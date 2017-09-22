/*
 * RadioHandler.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: johan
 */

#include "RadioHandler.h"

RadioHandler::RadioHandler() {
   // TODO Auto-generated constructor stub

}

RadioHandler::~RadioHandler() {
   // TODO Auto-generated destructor stub
}

void RadioHandler::addMessage(std::unique_ptr<Message> message){

}

void RadioHandler::run() {

}
void RadioHandler::setInterrupted() {

}
bool RadioHandler::getInterrupted() {
   return false;

}
void RadioHandler::addRecipient(IHandler* recipient, HandlerName recipientName){
   mRecipients[recipientName] = recipient;

}
