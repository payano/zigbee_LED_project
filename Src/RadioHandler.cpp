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
  //  mMrf24j->send16(0xffff, one, da_size);
  auto cathme = "0";
  while(!mQueue->empty()){
    //talk to MRF24J to send radio messages.
    // Get element from queue
    MessagePkg::Message message;
    mQueue->getMessage(&message);

    switch(message.type){
    case MessagePkg::Register::Interrupt:{
      // Incoming message from radio.

//      mMrf24j->interrupt_handler();
      tx_info_t* olaf = mMrf24j->get_txinfo();
      rx_info_t* radioMessage = mMrf24j->get_rxinfo();
//
      if(olaf->tx_ok == 1){
          memset(radioMessage->rx_data,0,127);
//          memset(ola,0,127);
        //  memset(rx_info.rx_data,0,116);
          mHalHandler->enableInterrupt(&mWhoami);
        continue;
      }
      std::string rx = (char*)radioMessage->rx_data;
      rx.substr(0, radioMessage->frame_length);
      auto yop = rx.c_str();
      auto len = rx.size();

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
        mMrf24j->send16(0x002, sendMe, sendAck.length());
      }

//      auto val = mMrf24j->get_rxbuf();
//      for(unsigned int i = 0 ; i < 60 ; ++i){
//        val[i] = '\0';
//      }
      //  rx_buf[127]
//      memset(mMrf24j->get_rxinfo(),0,127);
      mHalHandler->enableInterrupt(&mWhoami);
//      HAL_Delay(50);
//      mHalHandler->enableInterrupt(&mWhoami);

//      mMrf24j->interrupt_handler();
    }
    break;
    case MessagePkg::Register::Pressed:
    case MessagePkg::Register::Potentiometer:
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


void RadioHandler::init(){

  HAL_Delay(20);

  mMrf24j->reset();
  mMrf24j->init();

  mMrf24j->set_pan(0x0023);
  // This is _our_ address
  mMrf24j->address16_write(0x6001);
  // Implement here
  mMrf24j->set_interrupts();
}

void RadioHandler::addRecipient(IHandler* recipient, HandlerName recipientName){
   mRecipients[recipientName] = recipient;

}
}
