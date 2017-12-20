/*
 * ButtonHandler.h
 *
 *  Created on: Sep 21, 2017
 *      Author: johan
 */

#pragma once

#include "IHandler.h"

namespace HandlerPkg{
constexpr int BOUNCE_THRESHOLD = 25;
constexpr int BOUNCE_FALSE_POSITIVE = 1;
constexpr int MIN_POT_VAL = 10;
constexpr int DELAY_TIME = 50;
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
