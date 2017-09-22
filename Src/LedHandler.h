/*
 * LedHandler.h
 *
 *  Created on: Sep 22, 2017
 *      Author: johan
 */

#pragma once

#include "IHandler.h"
#include <memory>

class LedHandler: public IHandler {
private:
   IHandler* mRecipients[HandlerName::SIZE];
public:
   LedHandler();
   virtual ~LedHandler();
   void addMessage(std::unique_ptr<Message> message) override;
   void run() override;
   void setInterrupted() override;
   bool getInterrupted() override;
   void addRecipient(IHandler* recipient, HandlerName recipientName) override;
};

