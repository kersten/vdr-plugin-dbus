#include <vdr/thread.h>
#include <dbus-c++/dbus.h>
#include <signal.h>

#include "Server.h"

class cPluginDbusServer: public cThread {
private:
	static cPluginDbusServer        *m_Instance;
	DBus::BusDispatcher dispatcher;

protected:
	void Stop(void);

	virtual void Action(void);

public:
	cPluginDbusServer(void);
	virtual ~cPluginDbusServer();

	static void Initialize(void);
	static void Destruct(void);
	static bool Active(void);
};

inline bool cPluginDbusServer::Active(void)
{
	return m_Instance != NULL;
}
