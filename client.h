#include <vdr/thread.h>
#include <dbus-c++/dbus.h>
#include <signal.h>

#include "UDisksManagerProxy.h"

class cPluginDbusClient: public cThread {
private:
	static cPluginDbusClient        *m_Instance;
	DBus::BusDispatcher dispatcher;
	void niam(int sig);

protected:
	void Stop(void);

	virtual void Action(void);

	//static void Register(cServerComponent *Server);

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
	    //&& m_Instance->m_Clients.Count() > 0;
}
