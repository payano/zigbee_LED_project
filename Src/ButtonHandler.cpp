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
                      mQueue(new MessagePkg::MessageBox(5)),
                      mWhoami(whoami),
                      mHalHandler(halHandler),
                      mPotentiometerValue(0)
                      {
   // TODO Auto-generated constructor stub

}

ButtonHandler::~ButtonHandler() {
   // TODO Auto-generated destructor stub
  delete mQueue;
}

void ButtonHandler::addMessage(MessagePkg::Message* message){
  mQueue->putMessage(message);
}

void ButtonHandler::run() {
/*
   while(mQueue.size() > 0){
     // Get element from queue
     MessagePkg::Message message = mQueue.front();
     message.fromAddress = mWhoami;
     message.toAddress = HandlerPkg::HandlerName::Led;

     switch(message.type){
     case MessagePkg::Pressed:
       // the button does not know the state of the LED.
       // or should it know the state?
       message.value = 1;
       break;

     case MessagePkg::Potentiometer:
       //convert from 4000.. ish to 0-255!
       break;

     default:
       break;
     }

     // send message to LED if value >= 0
     if(message.value >= 0){
       mRecipients[HandlerName::Led]->addMessage(&message);
     }

     // Remove element from queue
     mQueue.pop();
   }


   // do that here?
   mHalHandler->enableInterrupt(&mWhoami);

*/
}

void ButtonHandler::addRecipient(IHandler* recipient, HandlerName recipientName){
   mRecipients[recipientName] = recipient;
}
}
