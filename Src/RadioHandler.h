/*
 * RadioHandler.h
 *
 *  Created on: Sep 22, 2017
 *      Author: johan
 */

#pragma once

#include "IHandler.h"
#include <memory>
class RadioHandler: public IHandler {
private:
   IHandler* mRecipients[HandlerName::SIZE];
public:
   RadioHandler();
   virtual ~RadioHandler();
   void addMessage(std::unique_ptr<Message> message) override;
   void run() override;
   void setInterrupted() override;
   bool getInterrupted() override;
   void addRecipient(IHandler* recipient, HandlerName recipientName) override;
};
