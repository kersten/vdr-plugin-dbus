/*
 * DBusConnection.h
 *
 *  Created on: 27.11.2010
 *      Author: kersten
 */

#ifndef DBUSCONNECTION_H_
#define DBUSCONNECTION_H_

#include <dbus/dbus.h>

class cDBusConnection
{
public:
  cDBusConnection();
  ~cDBusConnection();
  DBusConnection connectSystem();
};

#endif /* DBUSCONNECTION_H_ */
