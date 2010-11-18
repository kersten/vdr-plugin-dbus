#include <dbus-c++/dbus.h>
#include "events-server-glue.h"

class PluginDBusServer
: public org::vdr::Events_adaptor,
  public DBus::IntrospectableAdaptor,
  public DBus::ObjectAdaptor
{
public:

	PluginDBusServer(DBus::Connection &connection);

	bool shutdown(const int32_t& minutes);
	bool suspend();
	bool reboot();
};
