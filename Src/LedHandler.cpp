/*
 * LedHandler.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: johan
 */

#include "LedHandler.h"
#include "Message.h"
#include "HalHandler.h"

namespace HandlerPkg{

LedHandler::LedHandler(HandlerName whoami, HalHandler* halHandler):
        mQueue(new MessagePkg::MessageBox(10)),
        mWhoami(whoami),
        mHalHandler(halHandler)
        {
   // TODO Auto-generated constructor stub
  for(int i = 0; i < HandlerPkg::Channel::CHANNEL_SIZE; ++i){
    mLedValue[i] = 0;
  }
  //mLedValue[HandlerPkg::Channel::CHANNEL_SIZE] = {0};

}

LedHandler::~LedHandler() {
   // TODO Auto-generated destructor stub
  delete mQueue;
}
void LedHandler::addMessage(MessagePkg::Message* message){
  mQueue->putMessage(message);
}

void LedHandler::run() {
	while(!mQueue->empty()){
	  // Get element from queue
	  MessagePkg::Message message;
	  mQueue->getMessage(&message);

	  // If
	  switch(message.fromAddress)
	  {
	  case HandlerPkg::HandlerName::Button1:
	    // This is the RGB button
	    if(message.type == MessagePkg::Register::Potentiometer){
	      mHalHandler->setPWM(Channel::RGB_R, &message.value);
	      mHalHandler->setPWM(Channel::RGB_G, &message.value);
	      mHalHandler->setPWM(Channel::RGB_B, &message.value);
	    }
	    break;
	  case HandlerPkg::HandlerName::Button2:
	    mHalHandler->setPWM(Channel::PANEL, &message.value);
	    break;
	  case HandlerPkg::HandlerName::Radio:
	    break;
	  default:

	    break;
	  }


	  //switch(message.type){
	  //case MessagePkg::Led_Panel_Value:
	  //  if(message.write){
	  //    //radio and button can write.
	  //    mHalHandler->setPWM(Channel::PANEL, &message.value);
	  //  }
	  //  // only radio is requesting this
	  //  // use the same message and send it.
	  //  mHalHandler->getPWM(Channel::PANEL, &message.value);
	  //  // send it to radio
	  //  mRecipients[HandlerName::Radio]->addMessage(&message);
	  //  break;
	  //case MessagePkg::RGB_R_Value:
	  //  if(message.write){
	  //    mHalHandler->setPWM(Channel::RGB_R, &message.value);
	  //  }
	  //  // only radio is requesting this
	  //  mHalHandler->getPWM(Channel::RGB_R, &message.value);
	  //  mRecipients[HandlerName::Radio]->addMessage(&message);
	  //  break;
	  //case MessagePkg::RGB_G_Value:
	  //  if(message.write){
	  //    mHalHandler->setPWM(Channel::RGB_G, &message.value);
	  //  }
	  //  // only radio is requesting this
	  //  mHalHandler->getPWM(Channel::RGB_G, &message.value);
	  //  mRecipients[HandlerName::Radio]->addMessage(&message);
	  //  break;
	  //case MessagePkg::RGB_B_Value:
	  //  if(message.write){
	  //    mHalHandler->setPWM(Channel::RGB_B, &message.value);
	  //  }
     //  // only radio is requesting this
	  //  mHalHandler->getPWM(Channel::RGB_B, &message.value);
	  //  mRecipients[HandlerName::Radio]->addMessage(&message);
	  //  break;
     //
	  //default:
	  //  break;
	  //}
	}

}

void LedHandler::addRecipient(IHandler* recipient, HandlerName recipientName){
   mRecipients[recipientName] = recipient;
}
}
