/*
 * Status.h
 *
 *  Created on: 27.11.2010
 *      Author: kersten
 */

#ifndef STATUS_H_
#define STATUS_H_

#include <vdr/status.h>

#include "DBusSendSignal.h"

class Status : public cStatus
{
public:
  Status();
  virtual
  ~Status();
protected:
  virtual void ChannelSwitch(const cDevice *Device, int ChannelNumber);
  DBusSendSignal *sig;
};

#endif /* STATUS_H_ */
