/*
 * LedHandler.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: johan
 */

#include "LedHandler.h"
#include "Message.h"

LedHandler::LedHandler(HandlerName whoami):
        mWhoami(whoami){
   // TODO Auto-generated constructor stub

}

LedHandler::~LedHandler() {
   // TODO Auto-generated destructor stub
}
void LedHandler::addMessage(Message* message){
	mQueue.push(*message);
}

void LedHandler::run() {
	//Add message to LED
	{
	Message sending;
	sending.address = 23;
	sending.value = 12;
	mRecipients[HandlerName::Radio]->addMessage(&sending);
	}
	{
	Message sending;
	sending.address = 999;
	sending.value = 111;
	mRecipients[HandlerName::Radio]->addMessage(&sending);
	}

	while(mQueue.size() > 0){
		//Update LEDS
		Message myMess = mQueue.front();
		myMess.address = 30;
		mQueue.pop();
	}

}
void LedHandler::setInterrupted() {

}
bool LedHandler::getInterrupted() {
   return false;

}
void LedHandler::addRecipient(IHandler* recipient, HandlerName recipientName){
   mRecipients[recipientName] = recipient;
}
