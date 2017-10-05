/*
 * RadioHandler.h
 *
 *  Created on: Sep 22, 2017
 *      Author: johan
 */

#pragma once

#include "IHandler.h"

namespace HandlerPkg{

class RadioHandler: public IHandler {
private:
   MessagePkg::MessageBox *mQueue;
   HandlerName mWhoami;
   HalHandler* mHalHandler;
   IHandler* mRecipients[HandlerName::SIZE];
public:
   RadioHandler(HandlerName whoami, HalHandler* halHandler);
   virtual ~RadioHandler();
   void addMessage(MessagePkg::Message* message) override;
   void run() override;
   void addRecipient(IHandler* recipient, HandlerName recipientName) override;
};

}
