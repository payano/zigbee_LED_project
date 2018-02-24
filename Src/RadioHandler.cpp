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
  char one[] = "kitchen/white/light get ON";
  int da_size = sizeof(one) / sizeof(one[0]);
//  mMrf24j->send16(0xffff, one, da_size);
	while(!mQueue->empty()){
		//talk to MRF24J to send radio messages.
     // Get element from queue
     MessagePkg::Message message;
     mQueue->getMessage(&message);

     if(message.fromAddress == HandlerPkg::Hal && message.type == MessagePkg::Interrupt){
       // Incoming message from radio.
       rx_info_t* radioMessage = mMrf24j->get_rxinfo();
       std::string rx = (char*)radioMessage->rx_data;
       auto yop = rx.c_str();
       auto len = rx.size();

       mHalHandler->enableInterrupt(&mWhoami);

     }
     mMrf24j->interrupt_handler();

     // Do something with the message

	}

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
