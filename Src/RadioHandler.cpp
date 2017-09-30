/*
 * RadioHandler.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: johan
 */

#include "RadioHandler.h"
#include "Message.h"
#include "HalHandler.h"

RadioHandler::RadioHandler(HandlerName whoami, HalHandler* halHandler):
               mWhoami(whoami),
               mHalHandler(halHandler){
   // TODO Auto-generated constructor stub

}

RadioHandler::~RadioHandler() {
   // TODO Auto-generated destructor stub
}

void RadioHandler::addMessage(Message* message){
	mQueue.push(*message);
}

void RadioHandler::run() {
	//Add message to LED
	Message sending;
	sending.address = 233;
	sending.value = 132;
	mRecipients[HandlerName::Led]->addMessage(&sending);

	while(mQueue.size() > 0){
		//talk to MRF24J to send radio messages.
		Message myMess = mQueue.front();
		myMess.address = 30;
		mQueue.pop();
	}

}
void RadioHandler::setInterrupted() {

}
bool RadioHandler::getInterrupted() {
   return false;

}
void RadioHandler::addRecipient(IHandler* recipient, HandlerName recipientName){
   mRecipients[recipientName] = recipient;

}
