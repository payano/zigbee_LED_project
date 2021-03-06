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
    mBrightnessValue[i] = 255;
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
    switch(message.fromAddress){
    case HandlerPkg::HandlerName::Button1:
      // This is the RGB button
      switch(message.type){
      case MessagePkg::Register::Potentiometer:{
        mLedValue[Channel::RGB_R] = message.value;
        mLedValue[Channel::RGB_G] = message.value;
        mLedValue[Channel::RGB_B] = message.value;
        mHalHandler->setPWM(Channel::RGB_R, &mLedValue[Channel::RGB_R]);
        mHalHandler->setPWM(Channel::RGB_G, &mLedValue[Channel::RGB_G]);
        mHalHandler->setPWM(Channel::RGB_B, &mLedValue[Channel::RGB_B]);
      }
      break;
      case MessagePkg::Register::Pressed:{
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
      default:
        break;
      }
      break;
      case HandlerPkg::HandlerName::Button2:
        // This is the PANEL button
        switch(message.type){
        case MessagePkg::Register::Potentiometer:{
          mLedValue[Channel::PANEL] = message.value;
          mHalHandler->setPWM(Channel::PANEL, &message.value);
        }
        break;
        case MessagePkg::Register::Pressed:{
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
        default:
          break;
        }
        break;
        case HandlerPkg::HandlerName::Radio:
          switch(message.type){
          case MessagePkg::Register::Pressed: {
            switch(message.value){
            case 0: { // white is set to ON via radio
              mHalHandler->setPWM(Channel::PANEL, &mLedValue[Channel::PANEL]);
              break;
            }
            case 1: { // rgb is set to ON via radio

              {
                int setPWMVal = getBrightnessLevel(&mLedValue[Channel::RGB_R], &mBrightnessValue[Channel::RGB_R]);
                mHalHandler->setPWM(Channel::RGB_R, &setPWMVal);
              }
              {
                int setPWMVal = getBrightnessLevel(&mLedValue[Channel::RGB_G], &mBrightnessValue[Channel::RGB_G]);
                mHalHandler->setPWM(Channel::RGB_G, &setPWMVal);
              }
              {
                int setPWMVal = getBrightnessLevel(&mLedValue[Channel::RGB_B], &mBrightnessValue[Channel::RGB_G]);
                mHalHandler->setPWM(Channel::RGB_B, &setPWMVal);
              }
              break;
            }
            case 2: { // white is set to OFF via radio
              int value = 254;
              mHalHandler->setPWM(Channel::PANEL, &value);
              break;
            }
            case 3: { // rgb is set to OFF via radio
              int value = 254;
              mHalHandler->setPWM(Channel::RGB_R, &value);
              mHalHandler->setPWM(Channel::RGB_G, &value);
              mHalHandler->setPWM(Channel::RGB_B, &value);
              break;
            }
            }

            break;
          }
          case MessagePkg::Register::RGB_R_Value: {
            mLedValue[Channel::RGB_R] = LED_INVERT_VALUE - message.value;
            int setPWMVal = getBrightnessLevel(&mLedValue[Channel::RGB_R], &mBrightnessValue[Channel::RGB_R]);
            mHalHandler->setPWM(Channel::RGB_R, &setPWMVal);
            break;
          }
          case MessagePkg::Register::RGB_R_Brightness: {
            mBrightnessValue[Channel::RGB_R] = message.value;
            int setPWMVal = getBrightnessLevel(&mLedValue[Channel::RGB_R], &mBrightnessValue[Channel::RGB_R]);
            mHalHandler->setPWM(Channel::RGB_R, &setPWMVal);
            break;
          }
          case MessagePkg::Register::RGB_G_Value: {
            mLedValue[Channel::RGB_G] = LED_INVERT_VALUE - message.value;
            int setPWMVal = getBrightnessLevel(&mLedValue[Channel::RGB_G], &mBrightnessValue[Channel::RGB_G]);
            mHalHandler->setPWM(Channel::RGB_G, &setPWMVal);
            break;
          }
          case MessagePkg::Register::RGB_G_Brightness: {
            mBrightnessValue[Channel::RGB_G] = message.value;
            int setPWMVal = getBrightnessLevel(&mLedValue[Channel::RGB_G], &mBrightnessValue[Channel::RGB_G]);
            mHalHandler->setPWM(Channel::RGB_G, &setPWMVal);
            break;
          }
          case MessagePkg::Register::RGB_B_Value: {
            mLedValue[Channel::RGB_B] = LED_INVERT_VALUE - message.value;
            int setPWMVal = getBrightnessLevel(&mLedValue[Channel::RGB_B], &mBrightnessValue[Channel::RGB_B]);
            mHalHandler->setPWM(Channel::RGB_B, &setPWMVal);
            break;
          }
          case MessagePkg::Register::RGB_B_Brightness: {
            mBrightnessValue[Channel::RGB_B] = message.value;
            int setPWMVal = getBrightnessLevel(&mLedValue[Channel::RGB_B], &mBrightnessValue[Channel::RGB_B]);
            mHalHandler->setPWM(Channel::RGB_B, &setPWMVal);
            break;
          }
          case MessagePkg::Register::Led_Panel_Value: {
            mLedValue[Channel::PANEL] = LED_INVERT_VALUE - message.value;
            mHalHandler->setPWM(Channel::PANEL, &mLedValue[Channel::PANEL]);
            break;
          }
          default:
            break;
          }
          break;
        default:

          break;
    }
  }
}
void LedHandler::init(){
  // Make them bright and dim down to off
  for(int i = 0; i < 254; ++i){
    mHalHandler->setPWM(Channel::PANEL, &i);
    mHalHandler->setPWM(Channel::RGB_R, &i);
    mHalHandler->setPWM(Channel::RGB_G, &i);
    mHalHandler->setPWM(Channel::RGB_B, &i);
    HAL_Delay(10);
  }

}

void LedHandler::addRecipient(IHandler* recipient, HandlerName recipientName){
  mRecipients[recipientName] = recipient;
}

int LedHandler::getBrightnessLevel(int *ledValue, int *brightnessValue){
  auto result = (LED_INVERT_VALUE - *ledValue) * (*brightnessValue);
  if(result == 0){return LED_INVERT_VALUE - result;}
  result = result / (LED_INVERT_VALUE*1.0);
  return LED_INVERT_VALUE - ((int)result);

}


}
