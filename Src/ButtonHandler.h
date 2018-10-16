/*
 * ButtonHandler.h
 *
 *  Created on: Sep 21, 2017
 *      Author: johan
 */

#pragma once

#include "IHandler.h"

namespace HandlerPkg{
constexpr int MAX_VALUE =  255;
constexpr int MIN_POT_VAL = 8;
constexpr int DELAY_TIME = 10;
class ButtonHandler: public HandlerPkg::IHandler {
private:
  MessagePkg::MessageBox *mQueue;
  HandlerName mWhoami;
  HalHandler* mHalHandler;
  int mPotentiometerValue;
  bool mButtonStatus;
  IHandler* mRecipients[HandlerName::SIZE];

public:
   ButtonHandler(HandlerName whoami, HalHandler* halHandler);
   virtual ~ButtonHandler();
   void addMessage(MessagePkg::Message* message) override;
   void run() override;
   void init() override;
   void addRecipient(IHandler* recipient, HandlerName recipientName) override;
};
}
