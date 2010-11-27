/*
 * DbusSendSignal.cpp
 *
 *  Created on: 27.11.2010
 *      Author: kersten
 */

#include "DBusSendSignal.h"

DBusSendSignal::DBusSendSignal()
{
  // TODO Auto-generated constructor stub

}

DBusSendSignal::~DBusSendSignal()
{
  // TODO Auto-generated destructor stub
}

void
DBusSendSignal::send(char* name, char* path, char* interface, char* signalName,
    char* sigvalue)
{
  DBusMessage* msg;
  DBusMessageIter args;
  DBusConnection* conn;
  DBusError err;
  int ret;
  dbus_uint32_t serial = 0;

  isyslog("Sending signal with value %s", sigvalue);

  // initialise the error value
  dbus_error_init(&err);

  // connect to the DBUS system bus, and check for errors
  conn = dbus_bus_get(DBUS_BUS_SYSTEM, &err);
  if (dbus_error_is_set(&err))
    {
      isyslog("Connection Error (%s)", err.message);
      dbus_error_free(&err);
    }
  if (NULL == conn)
    {
      isyslog("Connection Null");
      exit(1);
    }

  // register our name on the bus, and check for errors
  ret
      = dbus_bus_request_name(conn, name, DBUS_NAME_FLAG_REPLACE_EXISTING, &err);
  if (dbus_error_is_set(&err))
    {
      isyslog("Name Error (%s)", err.message);
      dbus_error_free(&err);
    }
  if (DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER != ret)
    {
      isyslog("Some DBUS error");
      //exit(1);
    }

  // create a signal & check for errors
  msg = dbus_message_new_signal(path, // object name of the signal
      interface, // interface name of the signal
      signalName); // name of the signal
  if (NULL == msg)
    {
      isyslog("Message Null");
      exit(1);
    }

  // append arguments onto signal
  dbus_message_iter_init_append(msg, &args);
  if (!dbus_message_iter_append_basic(&args, DBUS_TYPE_STRING, &sigvalue))
    {
      isyslog("Out Of Memory!");
      exit(1);
    }

  // send the message and flush the connection
  if (!dbus_connection_send(conn, msg, &serial))
    {
      isyslog("Out Of Memory!");
      exit(1);
    }
  dbus_connection_flush(conn);

  isyslog("Signal Sent");

  // free the message and close the connection
  dbus_message_unref(msg);
  dbus_connection_close(conn);
}
