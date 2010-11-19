#ifndef __DbusClient_h
#define __DbusClient_h

#include <vdr/thread.h>
#include <dbus-c++/dbus.h>
#include <signal.h>

#include "Server.h"
#include "UDisksManagerProxy.h"

class cPluginDbusClient: public cThread {
private:
	static cPluginDbusClient        *m_Instance;
	DBus::BusDispatcher dispatcher;

protected:
	void Stop(void);

	virtual void Action(void);

public:
	cPluginDbusClient(void);
	virtual ~cPluginDbusClient();

	static void Initialize(void);
	static void Destruct(void);
	static bool Active(void);
};

inline bool cPluginDbusClient::Active(void)
{
	return m_Instance != NULL;
}
#endif//__DbusClient_h
