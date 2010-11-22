#include <vdr/tools.h>
#include <string.h>
#include <errno.h>
#include <iostream>

#include "DbusClient.h"

cPluginDbusClient         *cPluginDbusClient::m_Instance = NULL;

cPluginDbusClient::cPluginDbusClient(void):
		cThread("dbus client")
{
	Start();
}

cPluginDbusClient::~cPluginDbusClient()
{
	Stop();
}

void cPluginDbusClient::Initialize(void)
{
	dsyslog("[vdr-dbus] cPluginDbusClient::Initialize");

	if (m_Instance == NULL) {
		dsyslog("[vdr-dbus] cPluginDbusClient thread started");
		m_Instance = new cPluginDbusClient;
	}
}

void cPluginDbusClient::Destruct(void)
{
	DELETENULL(m_Instance);
}

void cPluginDbusClient::Stop(void)
{
    dispatcher.leave();
	if (Running())
		Cancel(3);
}

void cPluginDbusClient::Action(void)
{
	DBus::default_dispatcher = &dispatcher;
	DBus::Connection conn = DBus::Connection::SystemBus();
	
	UDisksManagerProxy udisks(conn);

	dispatcher.enter();
}
