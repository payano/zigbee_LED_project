/*
 * LedHandler.h
 *
 *  Created on: Sep 22, 2017
 *      Author: johan
 */

#pragma once

#include "IHandler.h"

namespace HandlerPkg{

class LedHandler: public IHandler {
private:
  MessagePkg::MessageBox *mQueue;
  HandlerName mWhoami;
  HalHandler* mHalHandler;
  int mLedValue[HandlerPkg::Channel::CHANNEL_SIZE];
  //RGB_R, RGB_G, RGB_B, LED_PANEL
  IHandler* mRecipients[HandlerName::SIZE];

public:
  LedHandler(HandlerName whoami, HalHandler* halHandler);
  virtual ~LedHandler();
  void addMessage(MessagePkg::Message* message) override;
  void run() override;
  void init() override;
  void addRecipient(IHandler* recipient, HandlerName recipientName) override;
};

}
