#ifndef __u_disks_device_proxy_h
#define __u_disks_device_proxy_h

#include <dbus-c++/dbus.h>
#include <vector>
#include <map>
#include <signal.h>
#include <iostream>
#include <vdr/plugin.h>

class UDisksDeviceProxy;

class UDisksManagerProxy
: public DBus::InterfaceProxy,
  public DBus::ObjectProxy
{
public:
	UDisksManagerProxy(DBus::Connection &connection);
	std::vector< DBus::Path > GetAllDevices();

private:
	void DeviceAddedCb(const DBus::SignalMessage &sig);
	void DeviceRemovedCb(const DBus::SignalMessage &sig);
	std::map< std::string, DBus::RefPtr< UDisksDeviceProxy > > _devices;
};

class UDisksDeviceProxy
: public DBus::InterfaceProxy,
  public DBus::ObjectProxy
{
public:
	UDisksDeviceProxy(DBus::Connection &connection, DBus::Path &udi);

private:
	void PropertyModifiedCb(const DBus::SignalMessage &sig);
	void ConditionCb(const DBus::SignalMessage &sig);
};

#endif//__u_disks_device_proxy_h