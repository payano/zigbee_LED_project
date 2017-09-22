/*
 * ButtonHandler.cpp
 *
 *  Created on: Sep 21, 2017
 *      Author: johan
 */

#include "ButtonHandler.h"
#include "Message.h"

ButtonHandler::ButtonHandler() {
   // TODO Auto-generated constructor stub

}

ButtonHandler::~ButtonHandler() {
   // TODO Auto-generated destructor stub
}

void ButtonHandler::addMessage(Message* message){
	//mQueue.push(*message);
}

void ButtonHandler::run() {

}
void ButtonHandler::setInterrupted() {

}
bool ButtonHandler::getInterrupted() {
   return false;

}

void ButtonHandler::addRecipient(IHandler* recipient, HandlerName recipientName){
   mRecipients[recipientName] = recipient;
}
