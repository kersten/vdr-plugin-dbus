// -----------------------------------------------------------------------------
/**
   File: dbus.c
  
   System:         VDR
   Component Name: dbus plugin
   Status:         Version 0.0.1 Release 1
   Language: C++
  
   License: GNU Public License V2
  
   Author: Kersten Burkhardt
   E-Mail: kerstenk@gmail.com
  
   Description: Main plugin file
                XXX Wite some text here
  
   Extendable: No
  
   Platform Dependencies: Linux      (i.e.: Linux/Intel, IRIX/Mips, Solaris/SPARC)
  
   $Id$
*/  
// -----------------------------------------------------------------------------

#include <vdr/plugin.h>
#include <dbus-c++/dbus.h>
#include <signal.h>
#include <iostream>
#include "client.h"

static const char *VERSION = "0.0.1";
static const char *DESCRIPTION = "Enter description for 'dbus' plugin";
static const char *MAINMENUENTRY = "Dbus";

class cPluginDbus : public cPlugin
{
private:
	// Add any member variables or functions you may need here.
	//Bus::BusDispatcher dispatcher;
	//DeviceMap m_AvailableDevices;

	/*DBusConnection *m_connection;
	DBusError m_error;
	DBusMessage *msg;
	DBusMessageIter args;
	char* sigvalue;*/
public:
	cPluginDbus(void);
	virtual ~cPluginDbus();
	virtual const char *Version(void)
	{	return VERSION;}
	virtual const char *Description(void)
	{	return DESCRIPTION;}
	virtual void niam(int sig);
	virtual const char *CommandLineHelp(void);
	virtual bool ProcessArgs(int argc, char *argv[]);
	virtual bool Initialize(void);
	virtual bool Start(void);
	virtual void Stop(void);
	virtual void Housekeeping(void);
	virtual void MainThreadHook(void);
	virtual cString Active(void);
	virtual time_t WakeupTime(void);
	virtual const char *MainMenuEntry(void)
	{	return MAINMENUENTRY;}
	virtual cOsdObject *MainMenuAction(void);
	virtual cMenuSetupPage *SetupMenu(void);
	virtual bool SetupParse(const char *Name, const char *Value);
	virtual bool Service(const char *Id, void *Data = NULL);
	virtual const char **SVDRPHelpPages(void);
	virtual cString SVDRPCommand(const char *Command, const char *Option, int &ReplyCode);
};

cPluginDbus::cPluginDbus(void)
{
	// Initialize any member variables here.
	// DON'T DO ANYTHING ELSE THAT MAY HAVE SIDE EFFECTS, REQUIRE GLOBAL
	// VDR OBJECTS TO EXIST OR PRODUCE ANY OUTPUT!
}

cPluginDbus::~cPluginDbus()
{
	// Clean up after yourself!
}

const char *cPluginDbus::CommandLineHelp(void)
{
	// Return a string that describes all known command line options.
	return NULL;
}

bool cPluginDbus::ProcessArgs(int argc, char *argv[])
{
	// Implement command line argument processing here if applicable.
	return true;
}

bool cPluginDbus::Initialize(void)
{
	// Initialize any background activities the plugin shall perform.
	return true;
}

void cPluginDbus::niam(int sig)
{
	//dispatcher.leave();
}

bool cPluginDbus::Start(void)
{
    std::cout << "Plugin started" << std::endl;

    cPluginDbusClient::Initialize();
    
	// Start any background activities the plugin shall perform.
	/*dsyslog("Satrt initalizing dbus plugin for vdr");

	//signal(SIGTERM, niam);
	//signal(SIGINT, niam);

	DBus::default_dispatcher = &dispatcher;

	DBus::Connection conn = DBus::Connection::SystemBus();

	HalManagerProxy hal(conn);

	dispatcher.enter();
*/
	/*// loop listening for signals being emmitted
	while (true)
	{
		dsyslog("Read dbus!");
		// non blocking read of the next available message
		dbus_connection_read_write(m_connection, 0);
		msg = dbus_connection_pop_message(m_connection);

		// loop again if we haven't read a message
		if (NULL == msg)
		{
			sleep(1);
			continue;
		}

		// check if the message is a signal from the correct interface
		// and with the correct name
		if (dbus_message_is_signal(msg, "org.freedesktop.UDisks", "DeviceAdded"))
		{
			// read the parameters
			if (!dbus_message_iter_init(msg, &args))
				dsyslog("Message has no arguments!");
			else if (DBUS_TYPE_STRING != dbus_message_iter_get_arg_type(&args))
				dsyslog("Argument is not string!");
			else
			{
				dbus_message_iter_get_basic(&args, &sigvalue);
				dsyslog("Got Signal with value %s\n", sigvalue);
			}
		}

		// free the message
		dbus_message_unref(msg);
	}*/

    std::cout << "Plugin started successfully" << std::endl;
	return true;
}

void cPluginDbus::Stop(void)
{
	// Stop any background activities the plugin is performing.
}

void cPluginDbus::Housekeeping(void)
{
	// Perform any cleanup or other regular tasks.
}

void cPluginDbus::MainThreadHook(void)
{
	// Perform actions in the context of the main program thread.
	// WARNING: Use with great care - see PLUGINS.html!
}

cString cPluginDbus::Active(void)
{
	// Return a message string if shutdown should be postponed
	return NULL;
}

time_t cPluginDbus::WakeupTime(void)
{
	// Return custom wakeup time for shutdown script
	return 0;
}

cOsdObject *cPluginDbus::MainMenuAction(void)
{
	// Perform the action when selected from the main VDR menu.
	return NULL;
}

cMenuSetupPage *cPluginDbus::SetupMenu(void)
{
	// Return a setup menu in case the plugin supports one.
	return NULL;
}

bool cPluginDbus::SetupParse(const char *Name, const char *Value)
{
	// Parse your own setup parameters and store their values.
	return false;
}

bool cPluginDbus::Service(const char *Id, void *Data)
{
	// Handle custom service requests from other plugins
	return false;
}

const char **cPluginDbus::SVDRPHelpPages(void)
{
	// Return help text for SVDRP commands this plugin implements
	return NULL;
}

cString cPluginDbus::SVDRPCommand(const char *Command, const char *Option, int &ReplyCode)
{
	// Process SVDRP commands this plugin implements
	return NULL;
}

VDRPLUGINCREATOR(cPluginDbus); // Don't touch this!
