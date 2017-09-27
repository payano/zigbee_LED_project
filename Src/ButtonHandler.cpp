/*
 * ButtonHandler.cpp
 *
 *  Created on: Sep 21, 2017
 *      Author: johan
 */

#include "ButtonHandler.h"
#include "Message.h"
#include "HalHandler.h"

ButtonHandler::ButtonHandler(HandlerName whoami):
                      mWhoami(whoami){
   // TODO Auto-generated constructor stub

}

ButtonHandler::~ButtonHandler() {
   // TODO Auto-generated destructor stub
}

void ButtonHandler::addMessage(Message* message){
	//mQueue.push(*message);
}

void ButtonHandler::run() {

  HalHandler* hal = static_cast<HalHandler*>(mRecipients[HandlerName::Hal]);
  hal->enableInterrupt(mWhoami);

}
void ButtonHandler::setInterrupted() {

}
bool ButtonHandler::getInterrupted() {
   return false;

}

void ButtonHandler::addRecipient(IHandler* recipient, HandlerName recipientName){
   mRecipients[recipientName] = recipient;
}
