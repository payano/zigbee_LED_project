/*
 * ButtonHandler.cpp
 *
 *  Created on: Sep 21, 2017
 *      Author: johan
 */

#include "ButtonHandler.h"
#include "Message.h"
#include "HalHandler.h"

ButtonHandler::ButtonHandler(HandlerName whoami, HalHandler* halHandler):
                      mWhoami(whoami),
                      mHalHandler(halHandler),
                      mPotentiometerValue(0){
   // TODO Auto-generated constructor stub

}

ButtonHandler::~ButtonHandler() {
   // TODO Auto-generated destructor stub
}

void ButtonHandler::addMessage(MessagePkg::Message* message){
	//mQueue.push(*message);
}

void ButtonHandler::run() {

  while(mQueue.size() > 0){
       //talk to MRF24J to send radio messages.
    MessagePkg::Message myMess = mQueue.front();
    // TODO: this is wrong!
       myMess.address = MessagePkg::Button1_Potentiometer;
       mQueue.pop();
    }

  mHalHandler->enableInterrupt(&mWhoami);

}

void ButtonHandler::addRecipient(IHandler* recipient, HandlerName recipientName){
   mRecipients[recipientName] = recipient;
}
