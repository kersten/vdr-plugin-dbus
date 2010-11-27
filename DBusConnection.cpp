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

DBusConnection
cDBusConnection::connectSystem()
{
  DBusConnection* conn = dbus_bus_get(DBUS_BUS_SESSION, &err);
  if (dbus_error_is_set(&err))
    {
      fprintf(stderr, "Connection Error (%s)\n", err.message);
      dbus_error_free(&err);
    }

  return conn;
}
