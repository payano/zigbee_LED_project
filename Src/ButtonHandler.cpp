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
                      mButtonStatus(false)
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

   while(!mQueue->empty()){
     // Get element from queue
     MessagePkg::Message message;
     mQueue->getMessage(&message);

     if(
         message.fromAddress == HandlerPkg::HandlerName::Radio &&
         message.type == MessagePkg::Register::Pressed){
       if(message.value == 1){
         mButtonStatus = true;
       }else{
         mButtonStatus = false;
       }
       continue;
     }


     message.fromAddress = mWhoami;
     message.toAddress = HandlerPkg::HandlerName::Led;

     switch(message.type){
     case MessagePkg::Pressed:
       // the button does not know the state of the LED.
       // or should it know the state?

       // Delay and check if the button is still pressed.
       HAL_Delay(DELAY_TIME);

       if(!mHalHandler->readGpio(&mWhoami)){
         // Button is not pressed anymore.
    	   mHalHandler->enableInterrupt(&mWhoami);
    	   break;
       }

       mButtonStatus = !mButtonStatus;
       if(mButtonStatus){
         message.value = 1;
       }else{
         message.value = 0;
       }
       mRecipients[HandlerName::Led]->addMessage(&message);

       // do that here?
       HAL_Delay(DELAY_TIME);
       mHalHandler->enableInterrupt(&mWhoami);
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

}
void ButtonHandler::init(){
  // Do nothing
}

void ButtonHandler::addRecipient(IHandler* recipient, HandlerName recipientName){
   mRecipients[recipientName] = recipient;
}

}
