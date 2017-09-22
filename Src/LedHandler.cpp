/*
 * LedHandler.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: johan
 */

#include "LedHandler.h"

LedHandler::LedHandler() {
   // TODO Auto-generated constructor stub

}

LedHandler::~LedHandler() {
   // TODO Auto-generated destructor stub
}
void LedHandler::addMessage(std::unique_ptr<Message> message){

}

void LedHandler::run() {

}
void LedHandler::setInterrupted() {

}
bool LedHandler::getInterrupted() {
   return false;

}
void LedHandler::addRecipient(IHandler* recipient, HandlerName recipientName){
   mRecipients[recipientName] = recipient;
}
