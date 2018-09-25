/*
 * RadioHandler.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: johan
 */

#include "RadioHandler.h"
#include "Message.h"
#include "HalHandler.h"
#include "Mrf24j.h"
#include <string.h>

namespace HandlerPkg {
RadioHandler::RadioHandler(HandlerName whoami, HalHandler* halHandler, Mrf24j* mrf24j):
               mQueue(new MessagePkg::MessageBox(10)),
               mWhoami(whoami),
               mHalHandler(halHandler),
               mMrf24j(mrf24j){
   // TODO Auto-generated constructor stub

}

RadioHandler::~RadioHandler() {
   // TODO Auto-generated destructor stub
  delete mQueue;
}

void RadioHandler::addMessage(MessagePkg::Message* message){
  mQueue->putMessage(message);
}

void RadioHandler::run() {
  using namespace MessagePkg;

  //  mMrf24j->send16(0xffff, one, da_size);
  while(!mQueue->empty()){
    //talk to MRF24J to send radio messages.
    // Get element from queue
    MessagePkg::Message message;
    mQueue->getMessage(&message);


    switch(message.type){
    case MessagePkg::Register::Interrupt:{
      // Incoming message from radio.

      tx_info_t* txInfo = mMrf24j->get_txinfo();
      rx_info_t* radioMessage = mMrf24j->get_rxinfo();
//
      if(txInfo->tx_ok == 1){
          memset(radioMessage->rx_data,0,127);
          // Disabled interrupt in radiohandler
//          mHalHandler->enableInterrupt(&mWhoami);
        continue;
      }
      std::string rx = (char*)radioMessage->rx_data;
      rx.substr(0, radioMessage->frame_length);

      auto findChar = rx.find('/');
      rx = rx.substr(findChar+1); // remove "kitchen/"
      findChar = rx.find('/');
      auto destination = rx.substr(0,findChar).c_str();
      rx = rx.substr(findChar+1); // remove "rgb/" or "white/"

      findChar = rx.find('/');
      auto type = rx.substr(0,findChar).c_str();
      rx = rx.substr(findChar+1); // remove "kitchen/"

      findChar = rx.find(' ');
      rx = rx.substr(findChar+1); // remove "set"

      auto value = rx.c_str();

      std::string sendAck = "kitchen/";
      sendAck.append(destination);
      sendAck.append("/");
      sendAck.append(type);
      sendAck.append("/get ");
      sendAck.append(value);

      const char* sendMe = sendAck.c_str();

      if(sendAck.size() > 16){
        // 0x002 is Rpi.
        mMrf24j->send16(HOME_ASSISTANT, sendMe, sendAck.length());
      }

      // Send a message to LedHandler.

      if(strcmp(type, "light") == 0){
        if(strcmp(value,"ON") == 0){
          // if on is sent
          MessagePkg::Message message;
          MessagePkg::Message buttonMsg;

          message.toAddress = HandlerName::Led;
          message.fromAddress = mWhoami;
          message.type = Register::Pressed;

          buttonMsg.fromAddress = mWhoami;
          buttonMsg.type = Register::Pressed;
          buttonMsg.value = 1;

          if(strcmp(destination, "white") == 0){
            //white is PANEL
            message.value = 0; // On for white
            buttonMsg.toAddress = HandlerName::Button2;
            mRecipients[HandlerName::Button2]->addMessage(&buttonMsg);
          }else {
            message.value = 1; // On for rgb
            buttonMsg.toAddress = HandlerName::Button1;
            mRecipients[HandlerName::Button1]->addMessage(&buttonMsg);
          }
          mRecipients[HandlerName::Led]->addMessage(&message);
        } else {
          MessagePkg::Message message;
          MessagePkg::Message buttonMsg;

          message.toAddress = HandlerName::Led;
          message.fromAddress = HandlerName::Radio;
          message.type = Register::Pressed;

          buttonMsg.fromAddress = mWhoami;
          buttonMsg.type = Register::Pressed;
          buttonMsg.value = 0;

          // Perhaps make something more dynamic..
          if(strcmp(destination, "white") == 0){
            message.value = 2; // Off for white
            mRecipients[HandlerName::Button2]->addMessage(&buttonMsg);

          }else {
            message.value = 3; // Off for rgb
            mRecipients[HandlerName::Button1]->addMessage(&buttonMsg);

          }
          mRecipients[HandlerName::Led]->addMessage(&message);
        }
      }else if(strcmp(type, "brightness") == 0) {
        if(strcmp(destination, "rgb") == 0){
          // Generate messages for LEDHandler
          {
            MessagePkg::Message message;
            message.toAddress = HandlerName::Led;
            message.fromAddress = HandlerName::Radio;
            message.type = Register::RGB_R_Brightness;
            message.value = atoi(value);
            mRecipients[HandlerName::Led]->addMessage(&message);
          }

          {
            MessagePkg::Message message;
            message.toAddress = HandlerName::Led;
            message.fromAddress = HandlerName::Radio;
            message.type = Register::RGB_G_Brightness;
            message.value = atoi(value);
            mRecipients[HandlerName::Led]->addMessage(&message);
          }

          {
            MessagePkg::Message message;
            message.toAddress = HandlerName::Led;
            message.fromAddress = HandlerName::Radio;
            message.type = Register::RGB_B_Brightness;
            message.value = atoi(value);
            mRecipients[HandlerName::Led]->addMessage(&message);
          }
        }else{
          MessagePkg::Message message;
          message.toAddress = HandlerName::Led;
          message.fromAddress = HandlerName::Radio;
          message.type = Register::Led_Panel_Value;
          message.value = atoi(value);
          mRecipients[HandlerName::Led]->addMessage(&message);
        }


      }else if(strcmp(type,"rgb") == 0){
        // if rgb is sent
        std::string rgb_value{value};
        auto findChar = rgb_value.find(',');
        auto r_value = atoi(rgb_value.substr(0,findChar).c_str()); // remove "kitchen/"
        rgb_value = rgb_value.substr(findChar+1);
        findChar = rgb_value.find(',');
        auto g_value = atoi(rgb_value.substr(0,findChar).c_str()); // remove "kitchen/"
        rgb_value = rgb_value.substr(findChar+1);
        auto b_value = atoi(rgb_value.c_str()); // remove "kitchen/"

        // Generate messages for LEDHandler
        {
          MessagePkg::Message message;
          message.toAddress = HandlerName::Led;
          message.fromAddress = HandlerName::Radio;
          message.type = Register::RGB_R_Value;
          message.value = r_value;
          mRecipients[HandlerName::Led]->addMessage(&message);
        }

        {
          MessagePkg::Message message;
          message.toAddress = HandlerName::Led;
          message.fromAddress = HandlerName::Radio;
          message.type = Register::RGB_G_Value;
          message.value = g_value;
          mRecipients[HandlerName::Led]->addMessage(&message);
        }

        {
          MessagePkg::Message message;
          message.toAddress = HandlerName::Led;
          message.fromAddress = HandlerName::Radio;
          message.type = Register::RGB_B_Value;
          message.value = b_value;
          mRecipients[HandlerName::Led]->addMessage(&message);
        }
      }
      // Disabled interrupt in radiohandler
//      mHalHandler->enableInterrupt(&mWhoami);

    }
    break;
    case MessagePkg::Register::Pressed:
    {
      std::string radioMessage = "kitchen/";

      if(message.fromAddress == HandlerName::Button1){
        radioMessage.append("rgb");
      }else{
        radioMessage.append("white");
      }

      radioMessage.append("/light/get ");

      if(message.value == 1){
        radioMessage.append("ON");
      }else{
        radioMessage.append("OFF");
      }

      mMrf24j->send16(HOME_ASSISTANT, radioMessage.c_str(), radioMessage.length());
      HAL_Delay(10);
    }
      break;
    case MessagePkg::Register::Potentiometer:
    {
      std::string radioMessage = "kitchen/";

      if(message.fromAddress == HandlerName::Button1){
        radioMessage.append("rgb");
      }else{
        radioMessage.append("white");
      }

      {
      radioMessage.append("/brightness/get ");
      if(message.value == 0){message.value = 1;}
      itoa(radioMessage, message.value);
      mMrf24j->send16(HOME_ASSISTANT, radioMessage.c_str(), radioMessage.length());
      HAL_Delay(10);
      }

      if(message.fromAddress == HandlerName::Button1){
        // RGB needs to reset aswell
        std::string radioMessage = "kitchen/rgb/rgb/get ";
        itoa(radioMessage, message.value);
        radioMessage += ",";
        itoa(radioMessage, message.value);
        radioMessage += ",";
        itoa(radioMessage, message.value);

        mMrf24j->send16(HOME_ASSISTANT, radioMessage.c_str(), radioMessage.length());
        HAL_Delay(10);
      }

    }
      break;

    case MessagePkg::Register::Led_Panel_Value:
    case MessagePkg::Register::Temperature_Value:
    case MessagePkg::Register::RGB_R_Value:
    case MessagePkg::Register::RGB_G_Value:
    case MessagePkg::Register::RGB_B_Value:
    default:
      break;
    }
  }
  // Do something with the message

}

void RadioHandler::itoa(std::string& message, int& value){
  // can only take 0-999;
  int hundred = (value/100)%10;
  int tens = (value/10)%10;
  int ones = value%10;

  if(hundred > 0){ message += '0' + hundred; }
  if(tens > 0 || hundred > 0){ message += '0' + tens; }
  message += '0' + ones;
}
void RadioHandler::init(){

  // Start up the radio
  HAL_Delay(20);

  mMrf24j->reset();
  mMrf24j->init();

  // Network id
  mMrf24j->set_pan(0x0023);
  // This is _our_ address
  mMrf24j->address16_write(0x6001);
  // Implement here
  mMrf24j->set_interrupts();

  // Tell radio that lights is off.
  char rgb[] = "kitchen/rgb/light/get OFF";
  char white[] = "kitchen/white/light/get OFF";
  // RGB also needs to reset RGB colors
  char rgbcolor[] = "kitchen/rgb/rgb/get 127,127,127";

  mMrf24j->send16(HOME_ASSISTANT, rgb, sizeof(rgb)/sizeof(rgb[0]));
  HAL_Delay(10);
  mMrf24j->send16(HOME_ASSISTANT, rgbcolor, sizeof(rgbcolor)/sizeof(rgbcolor[0]));
  HAL_Delay(10);
  mMrf24j->send16(HOME_ASSISTANT, white, sizeof(white)/sizeof(white[0]));
  HAL_Delay(10);
}

void RadioHandler::addRecipient(IHandler* recipient, HandlerName recipientName){
   mRecipients[recipientName] = recipient;

}
}
