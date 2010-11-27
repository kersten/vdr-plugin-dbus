/*
 * Status.cpp
 *
 *  Created on: 27.11.2010
 *      Author: kersten
 */

#include "Status.h"

Status::Status()
{
  sig = new DBusSendSignal();

}

Status::~Status()
{
  delete sig;
}

void
Status::ChannelSwitch(const cDevice *Device, int ChannelNumber)
{
  char buffer [255];
  snprintf (buffer, (size_t)255, "%d", ChannelNumber);
  sig->send("org.vdr.Events", "/org/vdr/Events", "org.vdr.Events.Channel", "Switched", buffer);
  dsyslog("status: cStatusTest::ChannelSwitch  %d %d", Device->CardIndex(), ChannelNumber);
}

