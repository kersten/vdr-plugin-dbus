#include "UDisksManagerProxy.h"



UDisksManagerProxy::UDisksManagerProxy(DBus::Connection &connection)
: DBus::InterfaceProxy("org.freedesktop.UDisks"),
  DBus::ObjectProxy(connection, "/org/freedesktop/UDisks", "org.freedesktop.UDisks")
{
	connect_signal(UDisksManagerProxy, DeviceAdded, DeviceAddedCb);
	connect_signal(UDisksManagerProxy, DeviceRemoved, DeviceRemovedCb);

	std::vector< DBus::Path > devices = GetAllDevices();
    
	std::vector< DBus::Path >::iterator it;
	for (it = devices.begin(); it != devices.end(); ++it)
	{
		DBus::Path udi = *it;

		dsyslog("[vdr-dbus] UDisksManagerProxy :: found device %s", (char*) &udi);

		_devices[udi] = new UDisksDeviceProxy(connection, udi);
	}
}

std::vector< DBus::Path > UDisksManagerProxy::GetAllDevices()
{
	std::vector< DBus::Path > udis;
	DBus::CallMessage call;

	call.member("EnumerateDevices");

	DBus::Message reply = invoke_method(call);
	DBus::MessageIter it = reply.reader();

	it >> udis;
	return udis;
}

void UDisksManagerProxy::DeviceAddedCb(const DBus::SignalMessage &sig)
{
	DBus::MessageIter it = sig.reader();
	DBus::Path devname;

	it >> devname;

	DBus::Path udi(devname);

	_devices[devname] = new UDisksDeviceProxy(conn(), udi);
	dsyslog("[vdr-dbus] UDisksManagerProxy :: added device %s", (char*) &udi);
}

void UDisksManagerProxy::DeviceRemovedCb(const DBus::SignalMessage &sig)
{
	DBus::MessageIter it = sig.reader();
	DBus::Path devname;

	it >> devname;

	dsyslog("[vdr-dbus] UDisksManagerProxy :: removed device %s", (char*) &udi);

	_devices.erase(devname);
}

UDisksDeviceProxy::UDisksDeviceProxy(DBus::Connection &connection, DBus::Path &udi)
: DBus::InterfaceProxy("org.freedesktop.UDisks"),
  DBus::ObjectProxy(connection, "/org/freedesktop/UDisks", "org.freedesktop.UDisks")
{
	connect_signal(UDisksDeviceProxy, PropertyModified, PropertyModifiedCb);
	connect_signal(UDisksDeviceProxy, Condition, ConditionCb);
}

void UDisksDeviceProxy::PropertyModifiedCb(const DBus::SignalMessage &sig)
{
	typedef DBus::Struct< std::string, bool, bool > HalProperty;

	DBus::MessageIter it = sig.reader();
	int32_t number;

	it >> number;

	DBus::MessageIter arr = it.recurse();

	for (int i = 0; i < number; ++i, ++arr)
	{
		HalProperty hp;

		arr >> hp;

		std::cout << "modified property " << hp._1 << " in " << path() << std::endl;
	}
}

void UDisksDeviceProxy::ConditionCb(const DBus::SignalMessage &sig)
{
	DBus::MessageIter it = sig.reader();
	std::string condition;

	it >> condition;

	std::cout << "encountered condition " << condition << " in " << path() << std::endl;
}
