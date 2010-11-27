/*
 * DBusConnection.h
 *
 *  Created on: 27.11.2010
 *      Author: kersten
 */

#ifndef DBUSCONNECTION_H_
#define DBUSCONNECTION_H_

#include <dbus/dbus.h>

#include <vdr/tools.h>

class cDBusConnection
{
public:
  cDBusConnection();
  virtual
  ~cDBusConnection();
  DBusConnection* connectSystem();
  DBusConnection* connectSession();
  void disconnect(DBusConnection &conn);
};

#endif /* DBUSCONNECTION_H_ */
