#include "Server.h"

static const char *ECHO_SERVER_NAME = "org.vdr.Events";
static const char *ECHO_SERVER_PATH = "/org/vdr/Events";

PluginDBusServer::PluginDBusServer(DBus::Connection &connection)
: DBus::ObjectAdaptor(connection, ECHO_SERVER_PATH)
{
	dsyslog("[vdr-dbus] PluginDBusServer::initalized");
}

bool PluginDBusServer::shutdown(const int32_t& minutes)
{
	dsyslog("[vdr-dbus] PluginDBusServer::shutdown in %i minutes", minutes);
	return true;
}

bool PluginDBusServer::suspend()
{
	dsyslog("[vdr-dbus] PluginDBusServer::suspend");
	return true;
}

bool PluginDBusServer::reboot()
{
	dsyslog("[vdr-dbus] PluginDBusServer::reboot");
	return true;
}
