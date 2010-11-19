#include <vdr/tools.h>
#include <string.h>
#include <errno.h>
#include <iostream>

#include "DbusServer.h"
#include "Server.h"

cPluginDbusServer *cPluginDbusServer::m_Instance = NULL;

cPluginDbusServer::cPluginDbusServer(void):
		cThread("streamdev server")
{
	Start();
}

cPluginDbusServer::~cPluginDbusServer()
{
	Stop();
}

void cPluginDbusServer::Initialize(void)
{
    std::cout << "Initializing..." << std::endl;

	if (m_Instance == NULL) {
        std::cout << "Thread started" << std::endl;
		m_Instance = new cPluginDbusServer;
	}
}

void cPluginDbusServer::Destruct(void)
{
	DELETENULL(m_Instance);
}

void cPluginDbusServer::Stop(void)
{
    dispatcher.leave();
	if (Running())
		Cancel(3);
}

void cPluginDbusServer::Action(void)
{
	DBus::default_dispatcher = &dispatcher;
	DBus::Connection conn = DBus::Connection::SessionBus();
	
	conn.request_name("org.vdr.Events");
	PluginDBusServer server(conn);

	dispatcher.enter();
}
