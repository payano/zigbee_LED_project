/*
 * ButtonHandler.cpp
 *
 *  Created on: Sep 21, 2017
 *      Author: johan
 */

#include "ButtonHandler.h"
#include "Message.h"
#include "HalHandler.h"
namespace HandlerPkg{
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
     // Get element from queue
   //  MessagePkg::Message message = mQueue.front();
   //  switch(message.address){
   //  case MessagePkg::Button1_Pressed:
   //  case MessagePkg::Button2_Pressed:
   //
   //    break;
   //
   //  case MessagePkg::Button1_Potentiometer:
   //  case MessagePkg::Button2_Potentiometer:
   //
   //    break;
   //
   //
   //  default:
   //    break;
   //  }
     // Remove element from queue
     mQueue.pop();
   }


   // do that here?
   mHalHandler->enableInterrupt(&mWhoami);

}

void ButtonHandler::addRecipient(IHandler* recipient, HandlerName recipientName){
   mRecipients[recipientName] = recipient;
}
}
