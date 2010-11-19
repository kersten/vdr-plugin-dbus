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

#include "DbusClient.h"
#include "DbusServer.h"

static const char *VERSION = "0.0.1-r1";
static const char *DESCRIPTION = "Enter description for 'dbus' plugin";
static const char *MAINMENUENTRY = "Dbus";

class cPluginDbus : public cPlugin
{
private:
	// Add any member variables or functions you may need here.
public:
	cPluginDbus(void);
	virtual ~cPluginDbus();
	virtual const char *Version(void)
	{	return VERSION;}
	virtual const char *Description(void)
	{	return DESCRIPTION;}
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
	cPluginDbusServer::Destruct();
	cPluginDbusClient::Destruct();
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

bool cPluginDbus::Start(void)
{
	/// Initalize dbus system
	cPluginDbusServer::Initialize();
	cPluginDbusClient::Initialize();
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
