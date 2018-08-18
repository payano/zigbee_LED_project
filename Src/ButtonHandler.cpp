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

     switch(message.fromAddress){
     case HandlerPkg::Hal:
       message.fromAddress = mWhoami;
       message.toAddress = HandlerPkg::HandlerName::Led;

       switch(message.type){
       case MessagePkg::Pressed:
         if(mHalHandler->getCountFinished()){
           mHalHandler->startCounter(32000);
           mHalHandler->enableInterrupt(&mWhoami);
         }else{
           mHalHandler->enableInterrupt(&mWhoami);
           break;
         }

         // Delay and check if the button is still pressed.
         HAL_Delay(DELAY_TIME);

         if(!mHalHandler->readGpio(&mWhoami)){
           // Button is not pressed anymore.
           mHalHandler->enableInterrupt(&mWhoami);
           break;
         }

         // Button has changed status, someone pressed it.
         mButtonStatus = !mButtonStatus;
         if(mButtonStatus){
           message.value = 1;
         }else{
           message.value = 0;
         }

         mRecipients[HandlerName::Led]->addMessage(&message);
         mHalHandler->enableInterrupt(&mWhoami);

         // Inform Home Assistant that a change has occurred.
         {
           MessagePkg::Message message;
           message.fromAddress = mWhoami;
           message.toAddress = HandlerPkg::HandlerName::Radio;
           message.value = mButtonStatus;
           message.type = MessagePkg::Register::Pressed;
           mRecipients[HandlerName::Radio]->addMessage(&message);
         }

         break;

       case MessagePkg::Potentiometer:
       {
         if(mButtonStatus == false){break;}

         if(message.value > (MAX_VALUE-MIN_POT_VAL)){
           message.value = (MAX_VALUE-MIN_POT_VAL);
         }

         int diff = mPotentiometerValue - message.value;
         if(diff < 0){diff *= -1;}


         if(diff > 2){
           // if button is "off", don't send potentiometer information
           mRecipients[HandlerName::Led]->addMessage(&message);
           mPotentiometerValue = message.value;

           // Inform Home Assistant that a change has occurred.
           {
             MessagePkg::Message radioMessage;
             radioMessage.fromAddress = mWhoami;
             radioMessage.toAddress = HandlerPkg::HandlerName::Radio;
             radioMessage.value = MAX_VALUE - message.value;
             radioMessage.type = MessagePkg::Register::Potentiometer;
             mRecipients[HandlerName::Radio]->addMessage(&radioMessage);
           }
         }
       }
       break;

       default:
         // this is not meant for LED.
         break;
       }
       break;
       case HandlerPkg::Radio:
         if(message.value == 1){
           mButtonStatus = true;
         }else{
           mButtonStatus = false;
         }
         break;
       default:
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
