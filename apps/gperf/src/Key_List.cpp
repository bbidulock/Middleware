// $Id$

/* Copyright (C) 1989 Free Software Foundation, Inc.
   written by Douglas C. Schmidt (schmidt@ics.uci.edu)

This file is part of GNU GPERF.

GNU GPERF is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 1, or (at your option) any
later version.

GNU GPERF is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU GPERF; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111,
USA.  */

#include "Key_List.h"

ACE_RCSID(src, Key_List, "$Id$")

#if defined (ACE_HAS_GPERF)

#include "ace/Read_Buffer.h"
#include "Hash_Table.h"

// Default type for generated code.
char *const Key_List::default_array_type = "char *";

// in_word_set return type, by default.
char *const Key_List::default_return_type = "char *";

// How wide the printed field width must be to contain the maximum
// hash value.
int Key_List::field_width = 0;
int Key_List::determined_[Vectors::ALPHA_SIZE];

// Destructor dumps diagnostics during debugging.

Key_List::~Key_List (void)
{
  if (option[DEBUG])
    this->dump ();

  // Free up all the nodes in the list.
  while (this->head != 0)
    {
      List_Node *temp;

      // Make sure to delete the linked nodes, as well.
      for (List_Node *ptr = this->head->link;
           ptr != 0; 
           ptr = temp)
        {
          temp = ptr->link;
          delete ptr;
        }
           
      temp = this->head->next;
      delete this->head;
      this->head = temp;
    }
}

// Gathers the input stream into a buffer until one of two things occur:
//
// 1. We read a '%' followed by a '%'
// 2. We read a '%' followed by a '}'
//
// The first symbolizes the beginning of the keyword list proper, The
// second symbolizes the end of the C source code to be generated
// verbatim in the output file.
//
// I assume that the keys are separated from the optional preceding
// struct declaration by a consecutive % followed by either % or }
// starting in the first column. The code below uses an expandible
// buffer to scan off and return a pointer to all the code (if any)
// appearing before the delimiter.

char *
Key_List::special_input (char delimiter)
{
  int size = 80;
  char *buf;
  ACE_NEW_RETURN (buf,
                  char[size],
                  0);
  int c;

  for (int i = 0; (c = getchar ()) != EOF; i++)
    {
      if (c == '%')
        {
          c = getchar ();
          if (c == delimiter)
            {
              // Discard newline...
              while ((c = getchar ()) != '\n')
                continue; 

              if (i == 0)
                return "";
              else
                {
                  buf[delimiter == '%' && buf[i - 2] == ';' 
                     ? i - 2 
                     : i - 1] = '\0';
                  return buf;
                }
            }
          else
            buf[i++] = '%';
        }
      else if (i >= size) 
        {
          // Yikes, time to grow the buffer!

          char *temp;
          ACE_NEW_RETURN (temp,
                          char[size *= 2],
                          0);
          for (int j = 0; j < i; j++)
            temp[j] = buf[j];

          delete [] buf;
          buf = temp;
        }
      buf[i] = c;
    }

  return 0; 
}

// Stores any C/C++ source code that must be included verbatim into
// the generated code output.

char *
Key_List::save_include_src (void)
{
  int c = getchar ();

  if (c != '%')
    ungetc (c, stdin);
  else if ((c = getchar ()) != '{')
    ACE_ERROR_RETURN ((LM_ERROR,
                       "internal error, %c != '{' on line %l in file %N",
                       c),
                       0);
  else
    return special_input ('}');
  return "";
}

// Determines from the input file whether the user wants to build a
// table from a user-defined struct, or whether the user is content to
// simply use the default array of keys.

char *
Key_List::array_type (void)
{
  return special_input ('%');
}

// Sets up the Return_Type, the Struct_Tag type and the Array_Type
// based upon various user Options.

int
Key_List::output_types (void)
{
  if (option[TYPE])
    {
      array_type_ = array_type ();
      if (array_type_ == 0)
        // Something's wrong, but we'll catch it later on....
        return -1;
      else
        {
          // Yow, we've got a user-defined type...
          int struct_tag_length = ACE_OS::strcspn (array_type_,
                                                   "{\n\0");
          if (option[POINTER])      // And it must return a pointer...
            {
              ACE_NEW_RETURN (return_type,
                              char[struct_tag_length + 2],
                              -1);
              ACE_OS::strncpy (return_type,
                               array_type_,
                               struct_tag_length);
              return_type[struct_tag_length] = '*';
              return_type[struct_tag_length + 1] = '\0';
            }

          ACE_NEW_RETURN (struct_tag,
                          char[struct_tag_length + 2],
                          -1);
          ACE_OS::strncpy (struct_tag,
                           array_type_,
                           struct_tag_length);
          if (struct_tag[struct_tag_length] != ' ')
            {
              struct_tag[struct_tag_length] = ' ';
              struct_tag_length++;
            }
          struct_tag[struct_tag_length] = '\0';
        }
    }
  else if (option[POINTER])     // Return a char *.
    return_type = Key_List::default_array_type;
  return 0;
}

// Reads in all keys from standard input and creates a linked list
// pointed to by Head.  This list is then quickly checked for
// ``links,'' i.e., unhashable elements possessing identical key sets
// and lengths.

int
Key_List::read_keys (void)
{
  this->include_src = this->save_include_src ();
  if (this->include_src == 0)
    return -1;
  else if (this->output_types () == -1)
    return -1;
  else
    {
      ACE_Read_Buffer input (stdin);

      char *buffer = input.read ('\n');

      if (buffer == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "No words in input file, did you forget to prepend %%%%"
                           " or use -t accidentally?\n"),
                          -1);
      // Read in all the keywords from the input file.
      else
        {
          List_Node *temp;
          const char *delimiter = option.delimiter ();
          ACE_NEW_RETURN (this->head,
                          List_Node (buffer,
                                     ACE_OS::strcspn (buffer,
                                                      delimiter)),
                          -1);
          for (temp = this->head;
               (buffer = input.read ('\n')) 
                 && ACE_OS::strcmp (buffer, "%%");
               temp = temp->next)
            {
              ACE_NEW_RETURN (temp->next,
                              List_Node (buffer,
                                         ACE_OS::strcspn (buffer,
                                                          delimiter)),
                              -1);
              this->total_keys++;
            }

          // See if any additional source code is included at end of
          // this file.
          if (buffer)
            additional_code = 1;

          this->list_len = this->total_keys;

          // Make large hash table for efficiency.
          Hash_Table table (this->list_len * Key_List::TABLE_MULTIPLE);
          List_Node *trail = 0;

          // Test whether there are any links and also set the maximum
          // length an identifier in the keyword list.

          for (temp = head;
               temp != 0;
               temp = temp->next)
            {
              List_Node *ptr = table.find (temp, option[NOLENGTH]);

              // Check for links.  We deal with these by building an
              // equivalence class of all duplicate values (i.e.,
              // links) so that only 1 keyword is representative of
              // the entire collection.  This *greatly* simplifies
              // processing during later stages of the program.

              if (ptr == 0)
                trail = temp;
              else
                {
                  total_duplicates++;
                  list_len--;
                  trail->next = temp->next;
                  temp->link = ptr->link;
                  ptr->link = temp;

                  // Complain if user hasn't enabled the duplicate
                  // option.
                  if (!option[DUP] || option[DEBUG])
                    ACE_ERROR ((LM_ERROR,
                                "Key link: \"%s\" = \"%s\", with key set \"%s\".\n",
                                temp->key,
                                ptr->key,
                                temp->keysig));
                }

              // Update minimum and maximum keyword length, if needed.
              if (max_key_len < temp->length)
                max_key_len = temp->length;
              if (min_key_len > temp->length)
                min_key_len = temp->length;
            }
        }

      // Exit program if links exists and option[DUP] not set, since
      // we can't continue.
      if (total_duplicates)
        {
          if (option[DUP])
            {
              if (!option[MUTE])
                ACE_ERROR_RETURN ((LM_ERROR,
                                   "%d input keysigs have identical hash values, examine output carefully...\n",
                                   total_duplicates),
                                   0);
            }
          else
            ACE_ERROR_RETURN ((LM_ERROR,
                               "%d input keysigs have identical hash values,\ntry different key positions or use option -D.\n",
                               total_duplicates),
                              -1);
        }
      if (option[ALLCHARS])
        option.keysig_size (max_key_len);
    }

  return 0;
}

// Recursively merges two sorted lists together to form one sorted
// list. The ordering criteria is by frequency of occurrence of
// elements in the key set or by the hash value.  This is a kludge,
// but permits nice sharing of almost identical code without incurring
// the overhead of a function call comparison.

List_Node *
Key_List::merge (List_Node *list1, List_Node *list2)
{
  if (!list1)
    return list2;
  else if (!list2)
    return list1;
  else if (occurrence_sort && list1->occurrence < list2->occurrence
           || hash_sort && list1->hash_value > list2->hash_value)
    {
      list2->next = merge (list2->next, list1);
      return list2;
    }
  else
    {
      list1->next = merge (list1->next, list2);
      return list1;
    }
}

// Applies the merge sort algorithm to recursively sort the key list
// by frequency of occurrence of elements in the key set.

List_Node *
Key_List::merge_sort (List_Node *a_head)
{
  if (!a_head || !a_head->next)
    return a_head;
  else
    {
      List_Node *middle = a_head;
      List_Node *temp   = a_head->next->next;

      while (temp)
        {
          temp   = temp->next;
          middle = middle->next;
          if (temp)
            temp = temp->next;
        }

      temp = middle->next;
      middle->next = 0;
      return merge (merge_sort (a_head), merge_sort (temp));
    }
}

// Returns the frequency of occurrence of elements in the key set.

inline int
Key_List::occurrence (List_Node *ptr)
{
  int value = 0;

  for (char *temp = ptr->keysig; *temp; temp++)
    value += Vectors::occurrences[*temp];

  return value;
}

// Sets the index location for all keysig characters that are now
// determined.

inline void
Key_List::determined (List_Node *ptr)
{
  for (char *temp = ptr->keysig; *temp; temp++)
    Key_List::determined_[*temp] = 1;
}

// Returns TRUE if PTR's key set is already completely determined.

inline int
Key_List::already_determined (List_Node *ptr)
{
  int is_determined = 1;

  for (char *temp = ptr->keysig; is_determined && *temp; temp++)
    is_determined = determined_[*temp];

  return is_determined;
}

// Reorders the table by first sorting the list so that frequently
// occuring keys appear first, and then the list is reorded so that
// keys whose values are already determined will be placed towards the
// front of the list.  This helps prune the search time by handling
// inevitable collisions early in the search process.  See Cichelli's
// paper from Jan 1980 JACM for details....

void
Key_List::reorder (void)
{
  List_Node *ptr;

  for (ptr = head; ptr; ptr = ptr->next)
    ptr->occurrence = occurrence (ptr);

  // Switch to sorting by occurrence.
  hash_sort = 0;
  occurrence_sort = 1;

  for (ptr = head = merge_sort (head); ptr->next; ptr = ptr->next)
    {
      determined (ptr);

      if (already_determined (ptr->next))
        continue;
      else
        {
          List_Node *trail_ptr = ptr->next;
          List_Node *run_ptr = trail_ptr->next;

          for (; run_ptr; run_ptr = trail_ptr->next)
            {

              if (already_determined (run_ptr))
                {
                  trail_ptr->next = run_ptr->next;
                  run_ptr->next = ptr->next;
                  ptr = ptr->next = run_ptr;
                }
              else
                trail_ptr = run_ptr;
            }
        }
    }
}

// Outputs the maximum and minimum hash values.  Since the list is
// already sorted by hash value all we need to do is find the final
// item!

void
Key_List::output_min_max (void)
{
  List_Node *temp;
  for (temp = head; temp->next; temp = temp->next)
    continue;

  min_hash_value = head->hash_value;
  max_hash_value = temp->hash_value;

  if (!option[ENUM])
    printf ("\n#define TOTAL_KEYWORDS %d\n#define MIN_WORD_LENGTH %d"
            "\n#define MAX_WORD_LENGTH %d\n#define MIN_HASH_VALUE %d"
            "\n#define MAX_HASH_VALUE %d\n#define HASH_VALUE_RANGE %d"
            "\n#define DUPLICATES %d\n\n",
            total_keys, min_key_len, max_key_len, min_hash_value,
            max_hash_value, max_hash_value - min_hash_value + 1,
            total_duplicates ? total_duplicates + 1 : 0);
  else if (option[GLOBAL])
    printf ("enum\n{\n"
            "  TOTAL_KEYWORDS = %d,\n"
            "  MIN_WORD_LENGTH = %d,\n"
            "  MAX_WORD_LENGTH = %d,\n"
            "  MIN_HASH_VALUE = %d,\n"
            "  MAX_HASH_VALUE = %d,\n"
            "  HASH_VALUE_RANGE = %d,\n"
            "  DUPLICATES = %d\n};\n\n",
            total_keys, min_key_len, max_key_len, min_hash_value,
            max_hash_value, max_hash_value - min_hash_value + 1,
            total_duplicates ? total_duplicates + 1 : 0);
}

// Generates the output using a C switch.  This trades increased
// search time for decreased table space (potentially *much* less
// space for sparse tables). It the user has specified their own
// struct in the keyword file *and* they enable the POINTER option we
// have extra work to do.  The solution here is to maintain a local
// static array of user defined struct's, as with the
// Output_Lookup_Function.  Then we use for switch statements to
// perform either a strcmp or strncmp, returning 0 if the str fails to
// match, and otherwise returning a pointer to appropriate index
// location in the local static array.

void
Key_List::output_switch (int use_keyword_table)
{
  if (!option[GLOBAL] && use_keyword_table == 0)
    {
      if (option[LENTABLE] && option[DUP])
        output_keylength_table ();
      if (option[POINTER] && option[TYPE])
        output_keyword_table ();
    }

  char *comp_buffer;
  List_Node *curr = head;
  int pointer_and_type_enabled = option[POINTER] && option[TYPE];
  int total_switches = option.total_switches ();
  int switch_size = keyword_list_length () / total_switches;

  if (pointer_and_type_enabled)
    {
      // Keep track of the longest string we'll need!
      const char *s = "charmap[*str] == *resword->%s && !strncasecmp (str + 1, resword->%s + 1, len - 1)";
      comp_buffer =
        new char [strlen (s) + 2 * strlen (option.key_name ()) + 1];
      if (option[COMP])
        sprintf (comp_buffer, "%s == *resword->%s && !%s (str + 1, resword->%s + 1, len - 1)",
                 option[STRCASECMP] ? "charmap[*str]" : "*str", option.key_name (),
                 option[STRCASECMP] ? "strncasecmp" : "strncmp", option.key_name ());
      else
        sprintf (comp_buffer, "%s == *resword->%s && !%s (str + 1, resword->%s + 1)",
                 option[STRCASECMP] ? "charmap[*str]" : "*str", option.key_name (),
                 option[STRCASECMP] ? "strcasecmp" : "strcmp", option.key_name ());
    }
  else
    {
      if (option[COMP])
        comp_buffer = option[STRCASECMP]
          ? "charmap[*str] == *resword && !strncasecmp (str + 1, resword + 1, len - 1)"
          : "*str == *resword && !strncmp (str + 1, resword + 1, len - 1)";
      else
        comp_buffer = option[STRCASECMP]
          ? "charmap[*str] == *resword && !strncasecmp (str + 1, resword + 1, len - 1)"
          : "*str == *resword && !strcmp (str + 1, resword + 1)";
    }
  if (!option[OPTIMIZE])
    printf ("  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)\n    {\n");
  printf ("      unsigned int key = %s (str, len);\n\n", option.hash_name ());
  if (!option[OPTIMIZE])
    printf ("      if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE)\n");

  printf ("        {\n");

  // Properly deal with user's who request multiple switch statements.

  while (curr)
    {
      List_Node *temp = curr;
      int lowest_case_value = curr->hash_value;
      int number_of_cases   = 0;

      // Figure out a good cut point to end this switch.

      for (; temp && ++number_of_cases < switch_size; temp = temp->next)
        if (temp->next && temp->hash_value == temp->next->hash_value)
          while (temp->next && temp->hash_value == temp->next->hash_value)
            temp = temp->next;

      if (temp && total_switches != 1)
        printf ("          if (key <= %d)\n            {\n", temp->hash_value);
      else
        printf ("            {\n");

      // Output each keyword as part of a switch statement indexed by
      // hash value.

      if (option[POINTER] || option[DUP] || use_keyword_table)
        {
          int i = 0;

          printf ("              %s%s *resword; %s\n\n",
                  option[CONSTANT] ? "const " : "",
                  pointer_and_type_enabled ? struct_tag : "char",
                  option[LENTABLE] && !option[DUP] ? "unsigned int key_len;" : "");
          if (total_switches == 1)
            {
              printf ("              switch (key)\n                {\n");
              lowest_case_value = 0;
            }
          else
            printf ("              switch (key - %d)\n                {\n", lowest_case_value);

          for (temp = curr; temp && ++i <= number_of_cases; temp = temp->next)
            {
              printf ("                case %*d:\n",
                      Key_List::field_width, 
                      temp->hash_value - lowest_case_value);

              // Handle `static links,' i.e., those that occur during
              // the initial preprocessing.

              if (temp->link == 0)
                {
                  if (option[DEBUG])
                    printf ("                  /* hash value = %4d, keyword = \"%s\" */\n",
                            temp->hash_value,
                            temp->key);
                }
              else
                {
                  List_Node *links;

                  for (links = temp; links; links = links->link)
                    {
                      if (option[DEBUG])
                        printf ("                  /* hash value = %4d, keyword = \"%s\" */\n",
                                temp->hash_value,
                                links->key);
                      if (pointer_and_type_enabled)
                        printf ("                  resword = &wordlist[%d];\n", links->index);
                      else if (use_keyword_table)
                        printf ("                  resword = wordlist[%d];\n", links->index);
                      else
                        printf ("                  resword = \"%s\";\n", links->key);
                      printf ("                  if (%s) return resword;\n", comp_buffer);
                    }
                }

              // Handle unresolved duplicate hash values.  These are
              // guaranteed to be adjacent since we sorted the keyword
              // list by increasing hash values.
              if (temp->next && temp->hash_value == temp->next->hash_value)
                {

                  for ( ; temp->next && temp->hash_value == temp->next->hash_value;
                        temp = temp->next)
                    {
                      if (pointer_and_type_enabled)
                        printf ("                  resword = &wordlist[%d];\n", temp->index);
                      else if (use_keyword_table)
                        printf ("                  resword = wordlist[%d];", temp->index);
                      else
                        printf ("                  resword = \"%s\";\n", temp->key);
                      printf ("                  if (%s) return resword;\n", comp_buffer);
                    }
                  if (pointer_and_type_enabled)
                    printf ("                  resword = &wordlist[%d];\n", temp->index);
                  else if (use_keyword_table)
                    printf ("                  resword = wordlist[%d];", temp->index);
                  else
                    printf ("                  resword = \"%s\";\n", temp->key);
                  printf ("                  return %s ? resword : 0;\n", comp_buffer);
                }
              else if (temp->link)
                printf ("                  return 0;\n");
              else
                {
                  if (pointer_and_type_enabled)
                    printf ("                  resword = &wordlist[%d];", temp->index);
                  else if (use_keyword_table)
                    printf ("                  resword = wordlist[%d];", temp->index);
                  else
                    printf ("                  resword = \"%s\";", temp->key);
                  if (option[LENTABLE] && !option[DUP])
                    printf (" key_len = %d;", temp->length);
                  printf (" break;\n");
                }
            }
          printf ("                default: return 0;\n                }\n");
          if (option[OPTIMIZE])
            printf ("                return resword;\n");
          else
            {
              printf (option[LENTABLE] && !option[DUP]
                      ? "              if (len == key_len && %s)\n                return resword;\n"
                      : "              if (%s)\n                return resword;\n", comp_buffer);
              printf ("              return 0;\n");
            }
          printf ("            }\n");
          curr = temp;
        }
      else // Nothing special required here.
        {
          int i = 0;
          printf ("              char *s;\n\n              switch (key - %d)\n                {\n",
                  lowest_case_value);

          for (temp = curr; temp && ++i <= number_of_cases; temp = temp->next)
            if (option[LENTABLE])
              printf ("                case %*d: if (len == %d) s = \"%s\"; else return 0; break;\n",
                      Key_List::field_width,
                      temp->hash_value - lowest_case_value,
                      temp->length, 
                      temp->key);
            else
              printf ("                case %*d: s = \"%s\"; break;\n",
                      Key_List::field_width,
                      temp->hash_value - lowest_case_value,
                      temp->key);

          printf ("                default: return 0;\n                }\n              ");
          if (option[COMP])
            printf ("return %s == *s && !%s;\n            }\n",
                    option[STRCASECMP] ? "charmap[*str]" : "*str",
                    option[STRCASECMP] ? "strncasecmp (s + 1, str + 1, len - 1)" : "strcmp (s + 1, str + 1)");
          else
            printf ("return %s == *s && !%s;\n            }\n",
                    option[STRCASECMP] ? "charmap[*str]" : "*str",
                    option[STRCASECMP] ? "strcasecmp (s + 1, str + 1, len - 1)" : "strcmp (s + 1, str + 1)");
          curr = temp;
        }
    }
  printf ("        }\n    %s\n}\n", option[OPTIMIZE] ? "" : "}\n  return 0;");
}

// Prints out a table of keyword lengths, for use with the comparison
// code in generated function ``in_word_set.''

void
Key_List::output_keylength_table (void)
{
  const int max_column = 15;
  int index = 0;
  int column = 0;
  char *indent = option[GLOBAL] ? "" : "  ";
  List_Node *temp;

  if (!option[DUP] && !option[SWITCH])
    {
      printf ("\n%sstatic %sunsigned %s lengthtable[] =\n%s%s{\n    ",
              indent, option[CONSTANT] ? "const " : "",
              max_key_len <= UCHAR_MAX ? "char" : (max_key_len <= USHRT_MAX ? "short" : "long"),
              indent, indent);

      for (temp = head; temp; temp = temp->next, index++)
        {

          if (index < temp->hash_value)
            for ( ; index < temp->hash_value; index++)
              printf ("%3d,%s", 0, ++column % (max_column - 1) ? "" : "\n    ");

          printf ("%3d,%s", temp->length, ++column % (max_column - 1 ) ? "" : "\n    ");
        }

      printf ("\n%s%s};\n", indent, indent);
    }
}

// Prints out the array containing the key words for the Gen_Perf hash
// function.

void
Key_List::output_keyword_table (void)
{
  char *l_brace = *head->rest ? "{" : "";
  char *r_brace = *head->rest ? "}," : "";
  char *indent = option[GLOBAL] ? "" : "  ";
  int index = 0;
  List_Node *temp;

  printf ("%sstatic %s%swordlist[] =\n%s%s{\n",
          indent,
          option[CONSTANT] ? "const " : "",
          struct_tag,
          indent,
          indent);

  // Skip over leading blank entries if there are no duplicates.

  if (0 < head->hash_value)
    printf ("      ");

  int column;

  for (column = 1; index < head->hash_value; column++)
    {
      printf ("%s\"\",%s %s", l_brace, r_brace, column % 9 ? "" : "\n      ");
      index++;
    }

  if (0 < head->hash_value && column % 10)
    printf ("\n");

  // Generate an array of reserved words at appropriate locations.

  for (temp = head ; temp; temp = temp->next, index++)
    {
      temp->index = index;

      if (!option[SWITCH] && (total_duplicates == 0 || !option[DUP]) && index < temp->hash_value)
        {
          int column;

          printf ("      ");

          for (column = 1; index < temp->hash_value; index++, column++)
            printf ("%s\"\",%s %s", l_brace, r_brace, column % 9 ? "" : "\n      ");

          if (column % 10)
            printf ("\n");
          else
            {
              printf ("%s\"%s\", %s%s", l_brace, temp->key, temp->rest, r_brace);
              if (option[DEBUG])
                printf (" /* hash value = %d, index = %d */",
                        temp->hash_value,
                        temp->index);
              putchar ('\n');
              continue;
            }
        }

      printf ("      %s\"%s\", %s%s", l_brace, temp->key, temp->rest, r_brace);
      if (option[DEBUG])
        printf (" /* hash value = %d, index = %d */",
                temp->hash_value,
                temp->index);
      putchar ('\n');

      // Deal with links specially.
      if (temp->link)
        for (List_Node *links = temp->link; links; links = links->link)
          {
            links->index = ++index;
            printf ("      %s\"%s\", %s%s", l_brace, links->key, links->rest, r_brace);
            if (option[DEBUG])
              printf (" /* hash value = %d, index = %d */",
                      links->hash_value,
                      links->index);
            putchar ('\n');
          }
    }
  printf ("%s%s};\n\n", indent, indent);
}

// Generates C code for the hash function that returns the proper
// encoding for each key word.

void
Key_List::output_hash_function (void)
{
  const int max_column = 10;
  int count = max_hash_value;

  // Calculate maximum number of digits required for MAX_HASH_VALUE.

  for (Key_List::field_width = 2;
       (count /= 10) > 0;
       Key_List::field_width++)
    continue;

  if (option[INLINE])
    printf ("inline\n");

  if (option[C])
    printf ("static ");
  printf ("unsigned int\n");
  if (option[CPLUSPLUS])
    printf ("%s::", option.class_name ());

  printf (option[ANSI]
          ? "%s (const char *str, unsigned int len)\n{\n  static %sunsigned %s asso_values[] =\n    {"
          : "%s (str, len)\n     char *str;\n     unsigned int len;\n{\n  static %sunsigned %s asso_values[] =\n    {",
          option.hash_name (), option[CONSTANT] ? "const " : "",
          max_hash_value <= UCHAR_MAX ? "char" : (max_hash_value <= USHRT_MAX ? "short" : "int"));

  for (count = 0; count < Vectors::ALPHA_SIZE; ++count)
    {
      if (!(count % max_column))
        printf ("\n    ");

      printf ("%*d,",
              Key_List::field_width,
              Vectors::occurrences[count] ? Vectors::asso_values[count] : max_hash_value + 1);
    }

  // Optimize special case of ``-k 1,$''
  if (option[DEFAULTCHARS])
    {
      if (option[STRCASECMP])
        printf ("\n    };\n  return %sasso_values[charmap[str[len - 1]]] + asso_values[charmap[str[0]]];\n}\n\n",
                option[NOLENGTH] ? "" : "len + ");
      else
        printf ("\n    };\n  return %sasso_values[str[len - 1]] + asso_values[str[0]];\n}\n\n",
                option[NOLENGTH] ? "" : "len + ");
    }
  else
    {
      int key_pos;

      option.reset ();

      // Get first (also highest) key position.
      key_pos = option.get ();

      // We can perform additional optimizations here.
      if (!option[ALLCHARS] && key_pos <= min_key_len)
        {
          printf ("\n    };\n  return %s", option[NOLENGTH] ? "" : "len + ");

          for (; key_pos != WORD_END; )
            {
              printf (option[STRCASECMP] ? "asso_values[charmap[str[%d]]]" : "asso_values[str[%d]]", key_pos - 1);
              if ((key_pos = option.get ()) != EOS)
                printf (" + ");
              else
                break;
            }

          printf ("%s;\n}\n\n", key_pos == WORD_END
                  ? (option[STRCASECMP] ? "asso_values[charmap[str[len - 1]]]" : "asso_values[str[len - 1]]")
                  : "");
        }

      // We've got to use the correct, but brute force, technique.
      else
        {
          printf ("\n    };\n  unsigned int hval = %s;\n\n  switch (%s)\n    {\n      default:\n",
                  option[NOLENGTH] ? "0" : "len", option[NOLENGTH] ? "len" : "hval");

          // User wants *all* characters considered in hash.
          if (option[ALLCHARS])
            {
              int i;

              // Break these options up for speed (gee, is this misplaced efficiency or what?!
              if (option[STRCASECMP])

                for (i = max_key_len; i > 0; i--)
                  printf ("      case %d:\n        hval += asso_values[charmap[str[%d]]];\n", i, i - 1);

              else

                for (i = max_key_len; i > 0; i--)
                  printf ("      case %d:\n        hval += asso_values[str[%d]];\n", i, i - 1);

              printf ("    }\n  return hval;\n}\n\n");
            }
          else                  // do the hard part...
            {
              count = key_pos + 1;

              do
                {

                  while (--count > key_pos)
                    printf ("      case %d:\n", count);

                  printf (option[STRCASECMP]
                          ? "      case %d:\n        hval += asso_values[charmap[str[%d]]];\n"
                          : "      case %d:\n        hval += asso_values[str[%d]];\n",
                          key_pos, key_pos - 1);
                }
              while ((key_pos = option.get ()) != EOS && key_pos != WORD_END);

              printf ("    }\n  return hval%s;\n}\n\n",
                      key_pos == WORD_END
                      ? (option[STRCASECMP] ? " + asso_values[charmap[str[len - 1]]]" : " + asso_values[str[len - 1]]")
                      : "");
            }
        }
    }
}

int
Key_List::count_duplicates (List_Node *link,
                            const char *type)
{
  int count = 0;

  // Count the number of "static" duplicates for this hash value.
  for (List_Node *ptr = link;
       ptr != 0;
       ptr = ptr->link)
    {
      count++;

      if (option[DEBUG])
        ACE_DEBUG ((LM_DEBUG,
                    "%s linked keyword = %s, index = %d, hash_value = %d\n",
                    type,
                    ptr->key,
                    ptr->index,
                    ptr->hash_value));
    }

  return count;
}

void
Key_List::update_lookup_array (int lookup_array[],
                               int i1,
                               int i2,
                               Duplicate_Entry *dup_ptr,
                               int value)
{
  lookup_array[i1] = -dup_ptr->index;
  lookup_array[i2] = -dup_ptr->count;
  lookup_array[dup_ptr->hash_value] = value;
}

// Generates the large, sparse table that maps hash values in the
// smaller, contiguous range of the keyword table.

int
Key_List::output_lookup_array (void)
{
  if (total_duplicates > 0)
    {
      const int DEFAULT_VALUE = -1;

      Duplicate_Entry *duplicates;
      ACE_NEW_RETURN (duplicates,
                      Duplicate_Entry[total_duplicates],
                      -1);

      int *lookup_array;
      ACE_NEW_RETURN (lookup_array,
                      int[max_hash_value + 1],
                      -1);

      Duplicate_Entry *dup_ptr = duplicates;
      int *lookup_ptr = lookup_array + max_hash_value + 1;

      // Initialize the lookup array to the DEFAULT_VALUE (-1).
      while (lookup_ptr > lookup_array)
        *--lookup_ptr = DEFAULT_VALUE;

      // Iterate through the keylist and handle the static and dynamic
      // duplicate entries.
      for (List_Node *temp = head; temp; temp = temp->next)
        {
          int hash_value = temp->hash_value;
          // Store the keyword's index location into the
          // <lookup_array> at the <hash_value>.  If this is a
          // non-duplicate, then this value will point directly to the
          // keyword.
          lookup_array[hash_value] = temp->index;

          if (option[DEBUG])
            ACE_DEBUG ((LM_DEBUG,
                        "keyword = %s, index = %d, hash_value = %d, lookup_array[hash_value] = %d\n",
                        temp->key,
                        temp->index,
                        temp->hash_value,
                        lookup_array[temp->hash_value]));

          if (temp->link == 0 &&
              (temp->next == 0 || hash_value != temp->next->hash_value))
            // This isn't a duplicate.  Note that we know this because
            // we sorted the keys by their hash value.
            continue;
          else
            {
              // We'll handle the duplicates here.
              dup_ptr->hash_value = hash_value;
              dup_ptr->index = temp->index;
              dup_ptr->count = 1;

              // Count the number of "static" duplicates, i.e.,
              // keywords that had the same keysig when the keyfile
              // was first read.
              dup_ptr->count += this->count_duplicates (temp->link,
                                                        "static");

              // Count the number of "dynamic" duplicates, i.e.,
              // keywords that ended up with the same hash value as a
              // result of the <asso_values> contents.
              for (;
                   temp->next && hash_value == temp->next->hash_value;
                   temp = temp->next)
                dup_ptr->count += this->count_duplicates (temp->next,
                                                          "dynamic");
              dup_ptr++;
            }
        }

      // Compute the values in the lookup array.
      while (--dup_ptr >= duplicates)
        {
          if (option[DEBUG])
            ACE_DEBUG ((LM_DEBUG,
                        "dup_ptr[%d]: hash_value = %d, index = %d, count = %d\n",
                        dup_ptr - duplicates,
                        dup_ptr->hash_value,
                        dup_ptr->index,
                        dup_ptr->count));
          int i;

          // Look to the left first.
          for (i = dup_ptr->hash_value; i > 0; i--)
            if (lookup_array[i] == DEFAULT_VALUE && lookup_array[i - 1] == DEFAULT_VALUE)
              {
                this->update_lookup_array (lookup_array,
                                           i - 1,
                                           i,
                                           dup_ptr,
                                           -(max_hash_value + (dup_ptr->hash_value - i + 1)));
                break;
              }

          // If we didn't find it to the left look to the right
          // instead...
          if (i == 0)
            {
              for (i = dup_ptr->hash_value; i < max_hash_value; i++)
                if (lookup_array[i] == DEFAULT_VALUE && lookup_array[i + 1] == DEFAULT_VALUE)
                  {
                    this->update_lookup_array (lookup_array,
                                               i,
                                               i + 1,
                                               dup_ptr,
                                               max_hash_value + (i - dup_ptr->hash_value));
                    break;
                  }

              // If this happens, we can't use the output array scheme...
              if (i >= max_hash_value)
                {
                  option = SWITCH;
                  ACE_DEBUG ((LM_DEBUG,
                              "Automatically changing to -S1 switch option\n"));
                  // Since we've already generated the keyword table
                  // we need to use it!
                  this->output_switch (1); 
                  return 1; // 1 indicates that we've changed our mind...
                }
            }
        }

      int max = INT_MIN;
      lookup_ptr = lookup_array + max_hash_value + 1;

      while (lookup_ptr > lookup_array)
        {
          int val = abs (*--lookup_ptr);
          if (max < val)
            max = val;
        }

      char *indent = option[GLOBAL] ? "" : "  ";

      printf ("%sstatic %ssigned %s lookup[] =\n%s%s{\n      ", indent, option[CONSTANT] ? "const " : "",
              max <= SCHAR_MAX ? "char" : (max <= SHRT_MAX ? "short" : "int"),
              indent, indent);

      int count = max;

      // Calculate maximum number of digits required for
      // MAX_HASH_VALUE.

      for (Key_List::field_width = 2; (count /= 10) > 0; Key_List::field_width++)
        continue;

      const int max_column = 15;
      int column = 0;

      for (lookup_ptr = lookup_array;
           lookup_ptr < lookup_array + max_hash_value + 1;
           lookup_ptr++)
        printf ("%*d, %s",
                Key_List::field_width,
                *lookup_ptr,
                ++column % (max_column - 1) ? "" : "\n      ");

      printf ("\n%s%s};\n\n", indent, indent);

      delete [] duplicates;
      delete [] lookup_array;
    }
  return 0;
}

// Generates C code to perform the keyword lookup.

void
Key_List::output_lookup_function (void)
{
  if (!option[OPTIMIZE])
    printf ("  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)\n    {\n");
  printf ("      unsigned int key = %s (str, len);\n\n", option.hash_name ());
  if (!option[OPTIMIZE])
    printf ("      if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE)\n");
  printf ("        {\n");

  if (option[DUP] && total_duplicates > 0)
    {
      printf ("          int index = lookup[key];\n\n"
              "          if (index >= 0 && index < MAX_HASH_VALUE)\n");
      if (option[OPTIMIZE])
        printf ("            return %swordlist[index];\n", option[TYPE] && option[POINTER] ? "&" : "");
      else
        {
          printf ("            {\n"
                  "              %schar *s = wordlist[index]", option[CONSTANT] ? "const " : "");
          if (array_type_ != Key_List::default_array_type)
            printf (".%s", option.key_name ());

          printf (";\n\n              if (%s%s == *s && !%s)\n                return %s;\n            }\n",
                  option[LENTABLE] ? "len == lengthtable[key]\n              && " : "",
                  option[STRCASECMP] ? "charmap[*str]" : "*str",
                  option[COMP] ? (option[STRCASECMP] ? "strncasecmp (str + 1, s + 1, len - 1)" : "strncmp (str + 1, s + 1, len - 1)")
                  : (option[STRCASECMP] ? "strcasecmp (str + 1, s + 1)" : "strcmp (str + 1, s + 1)"),
                  option[TYPE] && option[POINTER] ? "&wordlist[index]" : "s");
          printf ("          else if (index < 0 && index >= -MAX_HASH_VALUE)\n"
                  "            return 0;\n");
        }
      printf ("          else\n            {\n"
              "              unsigned int offset = key + index + (index > 0 ? -MAX_HASH_VALUE : MAX_HASH_VALUE);\n"
              "              %s%s*base = &wordlist[-lookup[offset]];\n"
              "              %s%s*ptr = base + -lookup[offset + 1];\n\n"
              "              while (--ptr >= base)\n                ",
              option[CONSTANT] ? "const " : "", struct_tag,
              option[CONSTANT] ? "const " : "", struct_tag);
      if (array_type_ != Key_List::default_array_type)
        {
          if (option[COMP])
              printf ("if (%s == *ptr->%s && !%s (str + 1, ptr->%s + 1, len - 1",
                      option[STRCASECMP] ? "charmap[*str]" : "*str", option.key_name (),
                      option[STRCASECMP] ? "strncasecmp" : "strncmp", option.key_name ());
          else
              printf ("if (%s == *ptr->%s && !%s (str + 1, ptr->%s + 1",
                      option[STRCASECMP] ? "charmap[*str]" : "*str", option.key_name (),
                      option[STRCASECMP] ? "strcasecmp" : "strcmp", option.key_name ());
        }
      else
        printf (option[STRCASECMP] ? "if (charmap[*str] == **ptr && !%s" : "if (*str == **ptr && !%s",
                option[COMP]
                ? (option[STRCASECMP] ? "strncasecmp (str + 1, *ptr + 1, len - 1" : "strncmp (str + 1, *ptr + 1, len - 1")
                : (option[STRCASECMP] ? "strcasecmp (str + 1, *ptr + 1" : "strcmp (str + 1, *ptr + 1"));
      printf ("))\n                  return %sptr;"
              "\n            }\n        }\n    %s\n}\n", array_type_ ==
              Key_List::default_array_type ? "*" : "", option[OPTIMIZE] ? "" : "}\n  return 0;");
    }
  else
    {
      if (option[OPTIMIZE])
        printf ("          return %swordlist[key]", option[TYPE] && option[POINTER] ? "&" : "");
      else
        {
          printf ("          %schar *s = wordlist[key]", option[CONSTANT] ? "const " : "");

          if (array_type_ != Key_List::default_array_type)
            printf (".%s", option.key_name ());

          printf (";\n\n          if (%s%s == *s && !%s)\n            return %s",
                  option[LENTABLE] ? "len == lengthtable[key]\n              && " : "",
                  option[STRCASECMP] ? "charmap[*str]" : "*str",
                  option[COMP]
                  ? (option[STRCASECMP] ? "strncasecmp (str + 1, s + 1, len - 1)" : "strncmp (str + 1, s + 1, len - 1)")
                  : (option[STRCASECMP] ? "strcasecmp (str + 1, s + 1)" : "strcmp (str + 1, s + 1)"),
                  option[TYPE] && option[POINTER] ? "&wordlist[key]" : "s");
        }
      printf (";\n        }\n    %s\n}\n", option[OPTIMIZE] ? "" : "}\n  return 0;");
    }
}

// Output the table and the functions that map upper case into lower case!

void
Key_List::output_strcasecmp (void)
{
  printf ("%s",
          "/* This array is designed for mapping upper and lower case letter\n"
          " * together for a case independent comparison.  The mappings are\n"
          " * based upon ascii character sequences.\n */"
          "static char charmap[] = {\n"
          "   '\\000', '\\001', '\\002', '\\003', '\\004', '\\005', '\\006', '\\007',\n"
          "   '\\010', '\\011', '\\012', '\\013', '\\014', '\\015', '\\016', '\\017',\n"
          "   '\\020', '\\021', '\\022', '\\023', '\\024', '\\025', '\\026', '\\027',\n"
          "   '\\030', '\\031', '\\032', '\\033', '\\034', '\\035', '\\036', '\\037',\n"
          "   '\\040', '\\041', '\\042', '\\043', '\\044', '\\045', '\\046', '\\047',\n"
          "   '\\050', '\\051', '\\052', '\\053', '\\054', '\\055', '\\056', '\\057',\n"
          "   '\\060', '\\061', '\\062', '\\063', '\\064', '\\065', '\\066', '\\067',\n"
          "   '\\070', '\\071', '\\072', '\\073', '\\074', '\\075', '\\076', '\\077',\n"
          "   '\\100', '\\141', '\\142', '\\143', '\\144', '\\145', '\\146', '\\147',\n"
          "   '\\150', '\\151', '\\152', '\\153', '\\154', '\\155', '\\156', '\\157',\n"
          "   '\\160', '\\161', '\\162', '\\163', '\\164', '\\165', '\\166', '\\167',\n"
          "   '\\170', '\\171', '\\172', '\\133', '\\134', '\\135', '\\136', '\\137',\n"
          "   '\\140', '\\141', '\\142', '\\143', '\\144', '\\145', '\\146', '\\147',\n"
          "   '\\150', '\\151', '\\152', '\\153', '\\154', '\\155', '\\156', '\\157',\n"
          "   '\\160', '\\161', '\\162', '\\163', '\\164', '\\165', '\\166', '\\167',\n"
          "   '\\170', '\\171', '\\172', '\\173', '\\174', '\\175', '\\176', '\\177',\n"
          "   '\\200', '\\201', '\\202', '\\203', '\\204', '\\205', '\\206', '\\207',\n"
          "   '\\210', '\\211', '\\212', '\\213', '\\214', '\\215', '\\216', '\\217',\n"
          "   '\\220', '\\221', '\\222', '\\223', '\\224', '\\225', '\\226', '\\227',\n"
          "   '\\230', '\\231', '\\232', '\\233', '\\234', '\\235', '\\236', '\\237',\n"
          "   '\\240', '\\241', '\\242', '\\243', '\\244', '\\245', '\\246', '\\247',\n"
          "   '\\250', '\\251', '\\252', '\\253', '\\254', '\\255', '\\256', '\\257',\n"
          "   '\\260', '\\261', '\\262', '\\263', '\\264', '\\265', '\\266', '\\267',\n"
          "   '\\270', '\\271', '\\272', '\\273', '\\274', '\\275', '\\276', '\\277',\n"
          "   '\\300', '\\341', '\\342', '\\343', '\\344', '\\345', '\\346', '\\347',\n"
          "   '\\350', '\\351', '\\352', '\\353', '\\354', '\\355', '\\356', '\\357',\n"
          "   '\\360', '\\361', '\\362', '\\363', '\\364', '\\365', '\\366', '\\367',\n"
          "   '\\370', '\\371', '\\372', '\\333', '\\334', '\\335', '\\336', '\\337',\n"
          "   '\\340', '\\341', '\\342', '\\343', '\\344', '\\345', '\\346', '\\347',\n"
          "   '\\350', '\\351', '\\352', '\\353', '\\354', '\\355', '\\356', '\\357',\n"
          "   '\\360', '\\361', '\\362', '\\363', '\\364', '\\365', '\\366', '\\367',\n"
          "   '\\370', '\\371', '\\372', '\\373', '\\374', '\\375', '\\376', '\\377',\n};\n\nstatic int\n");
  if (option[COMP])
    {
      printf ("%s", option[ANSI]
              ? "strncasecmp (char *s1, char *s2, int n)"
              : "strncasecmp (s1, s2, n)\n     char *s1, *s2;\n     int n;");
      printf ("\n{\n  char *cm = charmap;\n\n  while (--n >= 0 && cm[*s1] == cm[*s2++])\n"
              "    if (*s1++ == '\\0')\n      return 0;\n"
              "\n  return n < 0 ? 0 : cm[*s1] - cm[*--s2];\n}\n\n");
    }
  else
    {
      printf ("%s", option[ANSI]
              ? "strcasecmp (char *s1, char *s2)"
              : "strcasecmp (s1, s2)\n     char *s1, *s2;");
      printf ("\n{\n  char *cm = charmap;\n\n  while (cm[*s1] == cm[*s2++])\n"
              "    if (*s1++ == '\\0')\n      return 0;\n"
              "\n  return cm[*s1] - cm[*--s2];\n}\n\n");
    }
}

// Generates the hash function and the key word recognizer function
// based upon the user's Options.

int
Key_List::output (void)
{
  printf ("%s\n", include_src);

  // Get prototype for strncmp() and strcmp().
  if (!option[SKIPSTRINGH])
    printf ("#include <string.h>\n");

  // Output type declaration now, reference it later on....
  if (option[TYPE] && !option[NOTYPE])
    printf ("%s;\n",
            array_type_);

  output_min_max ();

  if (option[STRCASECMP])
    output_strcasecmp ();

  // Class definition if -M is *not* enabled.
  if ((option[CPLUSPLUS]) && (!option[SKIPCLASS]))
    printf ("class %s\n{\nprivate:\n"
            "  static unsigned int %s (const char *str, unsigned int len);\npublic:\n"
            "  static %s%s%s (const char *str, unsigned int len);\n};\n\n",
            option.class_name (),
            option.hash_name (),
            option[CONSTANT] ? "const " : "",
            return_type,
            option.function_name ());

  output_hash_function ();

  if (option[GLOBAL])
    if (option[SWITCH])
      {
        if (option[LENTABLE] && option[DUP])
          output_keylength_table ();
        if (option[POINTER] && option[TYPE])
          output_keyword_table ();
      }
    else
      {
        if (option[LENTABLE])
          output_keylength_table ();
        output_keyword_table ();
        if (output_lookup_array () == -1)
          ACE_ERROR_RETURN ((LM_DEBUG,
                             "%p\n",
                             "output_lookup_array"),
                            -1);
      }

  // Use the inline keyword to remove function overhead.
  if (option[INLINE])           
    printf ("inline\n");

  printf ("%s%s\n", option[CONSTANT] ? "const " : "", return_type);
  if (option[CPLUSPLUS])
    printf ("%s::", option.class_name ());

  printf (option[ANSI]
          ? "%s (const char *str, unsigned int len)\n{\n"
          : "%s (str, len)\n     char *str;\n     unsigned int len;\n{\n",
          option.function_name ());

  if (option[ENUM] && !option[GLOBAL])
    printf ("  enum\n    {\n"
            "      TOTAL_KEYWORDS = %d,\n"
            "      MIN_WORD_LENGTH = %d,\n"
            "      MAX_WORD_LENGTH = %d,\n"
            "      MIN_HASH_VALUE = %d,\n"
            "      MAX_HASH_VALUE = %d,\n"
            "      HASH_VALUE_RANGE = %d,\n"
            "      DUPLICATES = %d\n    };\n\n",
            total_keys, min_key_len, max_key_len, min_hash_value,
            max_hash_value, max_hash_value - min_hash_value + 1,
            total_duplicates ? total_duplicates + 1 : 0);
  // Use the switch in place of lookup table.
  if (option[SWITCH])
    output_switch ();
  // Use the lookup table, in place of switch.
  else
    {
      if (!option[GLOBAL])
        {
          if (option[LENTABLE])
            output_keylength_table ();
          output_keyword_table ();
        }
      if (!option[GLOBAL])
        {
          switch (output_lookup_array ())
            {
            case -1:
              ACE_ERROR_RETURN ((LM_DEBUG,
                                 "%p\n",
                                 "output_lookup_array"),
                                -1);
              /* NOTREACHED */
            case 0:
              output_lookup_function ();
              break;
              /* NOTREACHED */
            default:
              break;
              /* NOTREACHED */
            }
        }
    }

  if (additional_code)
    {
      for (;;)
        {
          int c = getchar ();

          if (c == EOF)
            break;
          else
            putchar (c);
        }
    }

  fflush (stdout);
  return 0;
}

// Sorts the keys by hash value.

void
Key_List::sort (void)
{
  // By default, we sort via hashing.
  hash_sort = 1;
  occurrence_sort = 0;

  this->head = merge_sort (this->head);
}

// Dumps the key list to stderr stream.

void
Key_List::dump (void)
{
  ACE_DEBUG ((LM_DEBUG,
              "\nDumping key list information:\ntotal non-static linked keywords = %d"
              "\ntotal keywords = %d\ntotal duplicates = %d\nmaximum key length = %d\n",
              list_len,
              total_keys,
              total_duplicates ? total_duplicates + 1 : 0,
              max_key_len));

  int keysig_width = option.max_keysig_size () > ACE_OS::strlen ("keysig") 
    ? option.max_keysig_size () 
    : ACE_OS::strlen ("keysig");

  int keyword_width = this->max_key_length () > ACE_OS::strlen ("keysig") 
    ? this->max_key_length () 
    : ACE_OS::strlen ("keysig");

  ACE_DEBUG ((LM_DEBUG,
              "\nList contents are:\n(hash value, key length, index, %*s, %*s, duplicates):\n",
              keysig_width,
              "keysig",
              keyword_width,
              "keyword"));

  for (List_Node *ptr = head; ptr; ptr = ptr->next)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "%11d,%11d,%6d, %*s, %*s",
                  ptr->hash_value,
                  ptr->length,
                  ptr->index,
                  keysig_width,
                  ptr->keysig,
                  keyword_width,
                  ptr->key));

      List_Node *dup = ptr->link;
      if (dup)
        {
          for (;
               dup != 0;
               dup = dup->link)
            ACE_DEBUG ((LM_DEBUG,
                        " %s",
                        dup->key));
        }
      ACE_DEBUG ((LM_DEBUG,
                  "\n"));
    }
  ACE_DEBUG ((LM_DEBUG,
              "End dumping list.\n\n"));
}

// Simple-minded constructor action here...

Key_List::Key_List (void)
  : head (0),
    total_duplicates (0),
    array_type_ (Key_List::default_array_type),
    return_type (Key_List::default_return_type),
    struct_tag (Key_List::default_array_type),
    max_key_len (INT_MIN),
    min_key_len (INT_MAX),
    additional_code (0),
    total_keys (1)
{
}

// Returns the length of entire key list.

int
Key_List::keyword_list_length (void)
{
  return list_len;
}

// Returns length of longest key read.

int
Key_List::max_key_length (void)
{
  return max_key_len;
}

#endif /* ACE_HAS_GPERF */
