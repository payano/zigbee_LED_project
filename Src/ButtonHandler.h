/*
 * ButtonHandler.h
 *
 *  Created on: Sep 21, 2017
 *      Author: johan
 */

#pragma once

#include "IHandler.h"
#include <memory>

class ButtonHandler: public IHandler {
private:
   IHandler* mRecipients[HandlerName::SIZE];
public:
   ButtonHandler();
   virtual ~ButtonHandler();
   void addMessage(Message* message) override;
   void run() override;
   void setInterrupted() override;
   bool getInterrupted() override;
   void addRecipient(IHandler* recipient, HandlerName recipientName) override;
};
