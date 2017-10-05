/*
 * RadioHandler.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: johan
 */

#include "RadioHandler.h"
#include "Message.h"
#include "HalHandler.h"

namespace HandlerPkg {
RadioHandler::RadioHandler(HandlerName whoami, HalHandler* halHandler):
               mQueue(new MessagePkg::MessageBox(10)),
               mWhoami(whoami),
               mHalHandler(halHandler){
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
//	while(mQueue.size() > 0){
//		//talk to MRF24J to send radio messages.
//
//	}

}

void RadioHandler::addRecipient(IHandler* recipient, HandlerName recipientName){
   mRecipients[recipientName] = recipient;

}
}
