#include <vdr/tools.h>
#include <string.h>
#include <errno.h>
#include <iostream>

#include "client.h"
#include "Server.h"

cPluginDbusClient         *cPluginDbusClient::m_Instance = NULL;

cPluginDbusClient::cPluginDbusClient(void):
		cThread("streamdev server")
{
	Start();
}

cPluginDbusClient::~cPluginDbusClient()
{
	Stop();
}

void cPluginDbusClient::Initialize(void)
{
    std::cout << "Initializing..." << std::endl;

	if (m_Instance == NULL) {
		/*if (StreamdevServerSetup.StartVTPServer)  Register(new cComponentVTP);
		if (StreamdevServerSetup.StartHTTPServer) Register(new cComponentHTTP);
		if (StreamdevServerSetup.StartIGMPServer) {
			if (strcmp(StreamdevServerSetup.IGMPBindIP, "0.0.0.0") == 0)
			    esyslog("streamdev-server: Not starting IGMP.
			        IGMP must be bound to a local IP");
			else
				Register(new cComponentIGMP);
		}*/
        std::cout << "Thread started" << std::endl;
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
	
	conn.request_name("org.vdr.Events");
	PluginDBusServer server(conn);

	dispatcher.enter();
}
