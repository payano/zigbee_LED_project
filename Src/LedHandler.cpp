/*
 * LedHandler.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: johan
 */

#include "LedHandler.h"
#include "Message.h"
#include "HalHandler.h"

namespace HandlerPkg{

LedHandler::LedHandler(HandlerName whoami, HalHandler* halHandler):
                    mQueue(new MessagePkg::MessageBox(10)),
                    mWhoami(whoami),
                    mHalHandler(halHandler)
{
  // TODO Auto-generated constructor stub
  for(int i = 0; i < HandlerPkg::Channel::CHANNEL_SIZE; ++i){
    mLedValue[i] = 0;
  }
  //mLedValue[HandlerPkg::Channel::CHANNEL_SIZE] = {0};

}

LedHandler::~LedHandler() {
  // TODO Auto-generated destructor stub
  delete mQueue;
}
void LedHandler::addMessage(MessagePkg::Message* message){
  mQueue->putMessage(message);
}

void LedHandler::run() {
  while(!mQueue->empty()){
    // Get element from queue
    MessagePkg::Message message;
    mQueue->getMessage(&message);

    // If
    switch(message.fromAddress)
    {
    case HandlerPkg::HandlerName::Button1:
      // This is the RGB button
      if(message.type == MessagePkg::Register::Potentiometer){
        mLedValue[Channel::RGB_R] = message.value;
        mLedValue[Channel::RGB_G] = message.value;
        mLedValue[Channel::RGB_B] = message.value;
        mHalHandler->setPWM(Channel::RGB_R, &message.value);
        mHalHandler->setPWM(Channel::RGB_G, &message.value);
        mHalHandler->setPWM(Channel::RGB_B, &message.value);
      }
      else if(message.type == MessagePkg::Register::Pressed)
      {
        if(message.value == 1){
          // turn on RGB
          mHalHandler->setPWM(Channel::RGB_R, &mLedValue[Channel::RGB_R]);
          mHalHandler->setPWM(Channel::RGB_G, &mLedValue[Channel::RGB_G]);
          mHalHandler->setPWM(Channel::RGB_B, &mLedValue[Channel::RGB_B]);
        }else{
          // turn off RGB
          int value = 254;
          mHalHandler->setPWM(Channel::RGB_R, &value);
          mHalHandler->setPWM(Channel::RGB_G, &value);
          mHalHandler->setPWM(Channel::RGB_B, &value);
        }

      }
      break;
    case HandlerPkg::HandlerName::Button2:
      // This is the PANEL button
      if(message.type == MessagePkg::Register::Potentiometer)
      {
        mLedValue[Channel::PANEL] = message.value;
        mHalHandler->setPWM(Channel::PANEL, &message.value);
      }
      else if(message.type == MessagePkg::Register::Pressed)
      {
        if(message.value == 1)
        {
          // turn on PANEL
          mHalHandler->setPWM(Channel::PANEL, &mLedValue[Channel::PANEL]);
        }else
        {
          // turn off PANEL
          int value = 254;
          mHalHandler->setPWM(Channel::PANEL, &value);
        }
      }
      break;
    case HandlerPkg::HandlerName::Radio:
      break;
    default:

      break;
    }
  }
}
void LedHandler::addRecipient(IHandler* recipient, HandlerName recipientName){
  mRecipients[recipientName] = recipient;
}

}
