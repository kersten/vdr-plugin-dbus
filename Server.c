#include "Server.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <iostream>

static const char *ECHO_SERVER_NAME = "org.vdr.Events";
static const char *ECHO_SERVER_PATH = "/org/vdr/Events";

PluginDBusServer::PluginDBusServer(DBus::Connection &connection)
: DBus::ObjectAdaptor(connection, ECHO_SERVER_PATH)
{
}

bool PluginDBusServer::shutdown(const int32_t& minutes)
{
	std::cout << "Shutdown in " << minutes << " Minutes..." << std::endl;
	return true;
}

bool PluginDBusServer::suspend()
{
	return true;
}

bool PluginDBusServer::reboot()
{
	return true;
}
