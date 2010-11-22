#ifndef __server_h
#define __server_h

#include <vdr/plugin.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <dbus-c++/dbus.h>

#include "events-server-glue.h"

class PluginDBusServer
: public org::vdr::Event_adaptor,
  public DBus::IntrospectableAdaptor,
  public DBus::ObjectAdaptor
{
public:

	PluginDBusServer(DBus::Connection &connection);

	bool shutdown(const int32_t& minutes);
	bool suspend();
	bool reboot();
};
#endif//__server_h
