/*
 * ButtonHandler.h
 *
 *  Created on: Sep 21, 2017
 *      Author: johan
 */

#pragma once

#include "IHandler.h"
#include <queue>

class ButtonHandler: public IHandler {
private:
   IHandler* mRecipients[HandlerName::SIZE];
   HandlerName mWhoami;
   HalHandler* mHalHandler;
   std::queue<MessagePkg::Message> mQueue;
   int mPotentiometerValue;

public:
   ButtonHandler(HandlerName whoami, HalHandler* halHandler);
   virtual ~ButtonHandler();
   void addMessage(MessagePkg::Message* message) override;
   void run() override;
   void addRecipient(IHandler* recipient, HandlerName recipientName) override;
};
