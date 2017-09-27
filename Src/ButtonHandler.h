/*
 * ButtonHandler.h
 *
 *  Created on: Sep 21, 2017
 *      Author: johan
 */

#pragma once

#include "IHandler.h"

class ButtonHandler: public IHandler {
private:
   IHandler* mRecipients[HandlerName::SIZE];
   HandlerName mWhoami;
public:
   ButtonHandler(HandlerName whoami);
   virtual ~ButtonHandler();
   void addMessage(Message* message) override;
   void run() override;
   void setInterrupted() override;
   bool getInterrupted() override;
   void addRecipient(IHandler* recipient, HandlerName recipientName) override;
};
