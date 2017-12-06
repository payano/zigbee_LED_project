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
                      mPotentiometerValue(30),
                      mButtonStatus(false),
                      mBouncing(0),
                      mFalsePos(0)
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

  if(mBouncing > 0){
    --mBouncing;
    mFalsePos = 0;
  }

   while(!mQueue->empty()){
     // Get element from queue
     MessagePkg::Message message;
     mQueue->getMessage(&message);
     message.fromAddress = mWhoami;
     message.toAddress = HandlerPkg::HandlerName::Led;

     switch(message.type){
     case MessagePkg::Pressed:
       // the button does not know the state of the LED.
       // or should it know the state?

       // is it a false positive?
       if(mFalsePos++ != BOUNCE_FALSE_POSITIVE){
         break;
       }

       // is it a button bounce?
       if(mBouncing != 0){
         // bounce
         break;
       }
       mBouncing = BOUNCE_THRESHOLD;

       mButtonStatus = !mButtonStatus;
       if(mButtonStatus){
         message.value = 1;
       }else{
         message.value = 0;
       }
       mRecipients[HandlerName::Led]->addMessage(&message);
       break;

     case MessagePkg::Potentiometer:
     {
       int diff = mPotentiometerValue - message.value;
       if(diff < 0){diff *= -1;}
       if(message.value > (254-MIN_POT_VAL)){
         message.value = (254-MIN_POT_VAL);
       }

       if(mButtonStatus && diff > 2){
         // if button is "off", don't send potentiometer information
         mRecipients[HandlerName::Led]->addMessage(&message);
         mPotentiometerValue = message.value;
       }
     }
       break;

     default:
       // this is not meant for LED.
       break;
     }
   }

   // do that here?
   mHalHandler->enableInterrupt(&mWhoami);

}
void ButtonHandler::init(){
  // Do nothing
}

void ButtonHandler::addRecipient(IHandler* recipient, HandlerName recipientName){
   mRecipients[recipientName] = recipient;
}

}
