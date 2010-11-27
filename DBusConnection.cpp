/*
 * DBusConnection.c
 *
 *  Created on: 27.11.2010
 *      Author: kersten
 */

#include "DBusConnection.h"

cDBusConnection::cDBusConnection()
{

}

cDBusConnection::~cDBusConnection()
{

}

DBusConnection*
cDBusConnection::connectSystem()
{
  DBusError err;
  DBusConnection* conn = dbus_bus_get(DBUS_BUS_SYSTEM, &err);

  dbus_error_init(&err);

  if (dbus_error_is_set(&err))
    {
      dsyslog("Connection Error (%s)\n", err.message);
      dbus_error_free(&err);
    }

  return conn;
}

DBusConnection*
cDBusConnection::connectSession()
{
  DBusError err;
  DBusConnection* conn = dbus_bus_get(DBUS_BUS_SESSION, &err);

  dbus_error_init(&err);

  if (dbus_error_is_set(&err))
    {
      dsyslog("Connection Error (%s)\n", err.message);
      dbus_error_free(&err);
    }

  return conn;
}

void
cDBusConnection::disconnect(DBusConnection &conn)
{
  dbus_connection_flush(&conn);
}
