/*
 * LedHandler.h
 *
 *  Created on: Sep 22, 2017
 *      Author: johan
 */

#pragma once

#include "IHandler.h"
#include <queue>

class LedHandler: public IHandler {
private:
   IHandler* mRecipients[HandlerName::SIZE];
   std::queue<MessagePkg::Message> mQueue;
   HandlerName mWhoami;
   HalHandler* mHalHandler;

public:
   LedHandler(HandlerName whoami, HalHandler* halHandler);
   virtual ~LedHandler();
   void addMessage(MessagePkg::Message* message) override;
   void run() override;
   void addRecipient(IHandler* recipient, HandlerName recipientName) override;
};

