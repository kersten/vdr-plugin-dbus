/*
 * DbusSendSignal.h
 *
 *  Created on: 27.11.2010
 *      Author: kersten
 */

#ifndef DBUSSENDSIGNAL_H_
#define DBUSSENDSIGNAL_H_

#include <dbus/dbus.h>
#include <vdr/tools.h>

class DBusSendSignal
{
public:
  DBusSendSignal();
  virtual
  ~DBusSendSignal();
  void
  send(char* name, char* path, char* interface, char* signalName,
      char* sigvalue);
};

#endif /* DBUSSENDSIGNAL_H_ */
