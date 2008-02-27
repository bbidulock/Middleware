// $Id$

#include "ace/Date_Time.h"
#include "ace/streams.h"

#include "MonitorControl/examples/MC_Test_Utilities.h"

void
MC_Test_Utilities::display_timestamp (
  const MonitorControl_Types::Data &data)
{
  ACE_Date_Time dt (data.timestamp_);
  cout << setfill ('0')
       << setw (2) << dt.month () << '-'
       << setw (2) << dt.day () << '-'
       << dt.year () << ' '
       << setw (2) << dt.hour () << ':'
       << setw (2) << dt.minute () << ':'
       << setw (2) << dt.second () << '.'
       << setw (6) << dt.microsec () << ":   ";
}

void
MC_Test_Utilities::display_num_threads (
  const MonitorControl_Types::Data &data)
{
  cout << "# of threads:         ";
  display_timestamp (data);
  cout << static_cast<size_t> (data.value_) << endl;
}

void
MC_Test_Utilities::display_mq_size (
  const MonitorControl_Types::Data &data)
{
  cout << "Message queue size: ";
  display_timestamp (data);
  cout << static_cast<size_t> (data.value_) << endl;
}

void
MC_Test_Utilities::display_memory_usage (
  const MonitorControl_Types::Data &data)
{
  cout << "% memory used:         ";
  display_timestamp (data);
  cout << setiosflags (ios::showpoint | ios::fixed)
       << setprecision (2) << data.value_ << endl;
}

void
MC_Test_Utilities::display_cpu_load (
  const MonitorControl_Types::Data &data)
{
  cout << "% CPU load:         ";
  display_timestamp (data);
  cout << setiosflags (ios::showpoint | ios::fixed)
       << setprecision (2) << data.value_ << endl;
}

void
MC_Test_Utilities::display_bytes_sent (
  const MonitorControl_Types::Data &data)
{
  cout << "total bytes sent:         ";
  display_timestamp (data);
  cout << static_cast<ACE_UINT64> (data.value_) << endl;
}


