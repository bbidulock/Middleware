/* $Id$ */

/* Copyright (c) 1994 The Geometry Center; University of Minnesota
   1300 South Second Street;  Minneapolis, MN  55454, USA;

This file is free software; you can redistribute it and/or modify it only
under the the terms of the GNU GENERAL PUBLIC LICENSE which should be
included along with thisw file.  This software may be obtained via anonymous
ftp from geom.umn.edu; email: software@geom.umn.edu. */

/* Author: Daeron Meyer */

#include "mibload.h"
#include "mibwidgets.h"

ACE_RCSID(mpeg_mib, mibDrawArea, "$Id$")

extern Display  *dpy;
extern GC        mib_gc;

/* Code for DrawingArea */
/*****************************************************************************/

mib_Widget *mib_create_DrawingArea(mib_Widget *parent, char *name, char * /* label */,
        int posx, int posy, int width, int height, int mib_fill)
{
  mib_Widget            *temp;
  mib_DrawingArea       *myres;
  Arg                    args[20];
  int                    n;

  /* create the new widget and add it to the tree */

  temp = mib_new_mib_Widget();
  if (mib_fill == WDEFAULT)
    mib_add_backward(temp, parent);
  else
    mib_add_mib_Widget(temp, parent);
  myres = (mib_DrawingArea *)ACE_OS::malloc(sizeof(mib_DrawingArea));

  /* initialize public resources */

  if (mib_fill == WDEFAULT)
  {
    temp->name = (char *)ACE_OS::malloc(strlen(name)+1);
    strcpy(temp->name,name);
  }
  temp->mib_class = (char *)ACE_OS::malloc(12);
  sprintf(temp->mib_class,"DrawingArea");
  temp->mib_class_num = MIB_DRAWINGAREA;
  temp->width = width;
  temp->height = height;
  temp->topOffset = posy;
  temp->leftOffset = posx;
  temp->bottomOffset = 0;
  temp->rightOffset = 0;
  temp->topAttachment = 1;
  temp->leftAttachment = 1;
  temp->bottomAttachment = 0;
  temp->rightAttachment = 0;

  temp->mib_allowresize = 1;

  /* initialize private resources */

  temp->myres = (void *)myres;
  myres->nothing = 0;

  /* create Xt widget */


  n = 0;
  if (mib_fill == WDEFAULT)
  {
    XtSetArg (args[n], XmNleftAttachment, XmATTACH_FORM); n++;
    XtSetArg (args[n], XmNleftOffset, posx);n++;
    XtSetArg (args[n], XmNtopAttachment, XmATTACH_FORM); n++;
    XtSetArg (args[n], XmNtopOffset, posy);n++;
    XtSetArg (args[n], XmNwidth, width); n++;
    XtSetArg (args[n], XmNheight, height); n++;
  }

  XtSetArg (args[n], XmNbackground, WhitePixel(dpy, DefaultScreen(dpy))); n++;
  XtSetArg (args[n], XmNrubberPositioning, False); n++;
  XtSetArg (args[n], XmNhighlightThickness, 0); n++;

  temp->me = XtCreateManagedWidget(name, xmDrawingAreaWidgetClass,
                temp->parent->me, args, n);
  if (mib_fill == WEDIT || mib_fill == WDEFAULT)
  {
    mib_apply_eventhandlers(temp->me, temp);
  }

  return temp;
}

void mib_delete_DrawingArea(mib_Widget *thisw)
{
  mib_DrawingArea *temp = (mib_DrawingArea *)thisw->myres;

  ACE_OS::free(temp);
}

void mib_save_DrawingArea(mib_Widget *thisw, FILE *fout)
{
}

int mib_load_DrawingArea(mib_Widget *thisw, mib_Buffer *fin)
{
  char          res[MI_MAXSTRLEN];
  char          val[MI_MAXSTRLEN];

  if (!mib_read_line(fin, res, val))
    return 0;

  if (ACE_OS::strcmp (res,"EndWidget"))
    return 0;

  return 1;
}
