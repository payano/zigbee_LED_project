/*
 * RadioHandler.h
 *
 *  Created on: Sep 22, 2017
 *      Author: johan
 */

#pragma once

#include "IHandler.h"

class Mrf24j;

namespace HandlerPkg{

constexpr int HOME_ASSISTANT = 0x02;

class RadioHandler: public IHandler {
private:
   MessagePkg::MessageBox *mQueue;
   HandlerName mWhoami;
   HalHandler* mHalHandler;
   IHandler* mRecipients[HandlerName::SIZE];
   Mrf24j* mMrf24j;
public:
   RadioHandler(HandlerName whoami, HalHandler* halHandler, Mrf24j* mrf24j);
   virtual ~RadioHandler();
   void addMessage(MessagePkg::Message* message) override;
   void run() override;
   void init() override;
   void addRecipient(IHandler* recipient, HandlerName recipientName) override;
   void itoa(std::string& message, int& value);
};

}
