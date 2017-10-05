/*
 * ButtonHandler.h
 *
 *  Created on: Sep 21, 2017
 *      Author: johan
 */

#pragma once

#include "IHandler.h"

namespace HandlerPkg{

class ButtonHandler: public HandlerPkg::IHandler {
private:
  MessagePkg::MessageBox *mQueue;
  HandlerName mWhoami;
  HalHandler* mHalHandler;
  int mPotentiometerValue;
  IHandler* mRecipients[HandlerName::SIZE];

public:
   ButtonHandler(HandlerName whoami, HalHandler* halHandler);
   virtual ~ButtonHandler();
   void addMessage(MessagePkg::Message* message) override;
   void run() override;
   void addRecipient(IHandler* recipient, HandlerName recipientName) override;
};
}
