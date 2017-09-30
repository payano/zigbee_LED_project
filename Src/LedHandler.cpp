/*
 * LedHandler.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: johan
 */

#include "LedHandler.h"
#include "Message.h"
#include "HalHandler.h"

LedHandler::LedHandler(HandlerName whoami, HalHandler* halHandler):
        mWhoami(whoami),
        mHalHandler(halHandler){
   // TODO Auto-generated constructor stub

}

LedHandler::~LedHandler() {
   // TODO Auto-generated destructor stub
}
void LedHandler::addMessage(MessagePkg::Message* message){
	mQueue.push(*message);
}

void LedHandler::run() {
	while(mQueue.size() > 0){
	  // Get element from queue
	  MessagePkg::Message message = mQueue.front();
	  switch(message.address){
	  case MessagePkg::Led_Panel_Value:
	    if(message.write){
	      //radio and button can write.
	      mHalHandler->setPWM(Channel::PANEL, &message.value);
	    }
	    // only radio is requesting this
	    // use the same message and send it.
	    mHalHandler->getPWM(Channel::PANEL, &message.value);
	    // send it to radio
	    mRecipients[HandlerName::Radio]->addMessage(&message);
	    break;
	  case MessagePkg::RGB_R_Value:
	    if(message.write){
	      mHalHandler->setPWM(Channel::RGB_R, &message.value);
	    }
	    // only radio is requesting this
	    mHalHandler->getPWM(Channel::RGB_R, &message.value);
	    mRecipients[HandlerName::Radio]->addMessage(&message);
	    break;
	  case MessagePkg::RGB_G_Value:
	    if(message.write){
	      mHalHandler->setPWM(Channel::RGB_G, &message.value);
	    }
	    // only radio is requesting this
	    mHalHandler->getPWM(Channel::RGB_G, &message.value);
	    mRecipients[HandlerName::Radio]->addMessage(&message);
	    break;
	  case MessagePkg::RGB_B_Value:
	    if(message.write){
	      mHalHandler->setPWM(Channel::RGB_B, &message.value);
	    }
       // only radio is requesting this
	    mHalHandler->getPWM(Channel::RGB_B, &message.value);
	    mRecipients[HandlerName::Radio]->addMessage(&message);
	    break;

	  default:
	    break;
	  }
	  // Remove element from queue
	  mQueue.pop();
	}

}

void LedHandler::addRecipient(IHandler* recipient, HandlerName recipientName){
   mRecipients[recipientName] = recipient;
}
