/*
 * ButtonHandler.h
 *
 *  Created on: Sep 21, 2017
 *      Author: johan
 */

#pragma once

#include "IHandler.h"
#include <queue>

namespace HandlerPkg{

class ButtonHandler: public HandlerPkg::IHandler {
private:
  IHandler* mRecipients[HandlerName::SIZE];
  MessagePkg::Message *mQueue;
  HandlerName mWhoami;
  HalHandler* mHalHandler;
  int mPotentiometerValue;

public:
   ButtonHandler(HandlerName whoami, HalHandler* halHandler);
   virtual ~ButtonHandler();
   void addMessage(MessagePkg::Message* message) override;
   void run() override;
   void addRecipient(IHandler* recipient, HandlerName recipientName) override;
};
}
