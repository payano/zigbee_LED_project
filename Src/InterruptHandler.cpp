/*
 * InterruptHandler.cpp
 *
 *  Created on: Sep 25, 2017
 *      Author: johan
 */

#include "InterruptHandler.h"
#include "Message.h"

bool InterruptHandler::sInterrupted[HandlerName::SIZE] = {false};

InterruptHandler::InterruptHandler():
  mAdcBuffer(nullptr),
  mAdcBufferLen(0){
  // TODO Auto-generated constructor stub
}

InterruptHandler::~InterruptHandler() {
  // TODO Auto-generated destructor stub
}

void InterruptHandler::addAdcBuffer(uint32_t* buffer, int len){
  //TODO untested:
  mAdcBuffer = buffer;
  mAdcBufferLen = len;
}

void InterruptHandler::addMessage(Message* message){
   //do nothing
}

void InterruptHandler::run() {

  // TODO: untested:
  //Check ADC:
  // 0 = Button 1 (potentiometer)
  // 1 = Button 2 (potentiometer)
  // 2 = Temperature sensor

  if(sInterrupted[HandlerName::Interrupt]){
    {
      // generate message
      Message message;
      mRecipients[HandlerName::Button1]->addMessage(&message);
    }
    {
      // generate message
      Message message;
      mRecipients[HandlerName::Button2]->addMessage(&message);
    }
    {
      // generate message to temp sensor
      Message message;
      //mRecipients[HandlerName::Button1]->addMessage(&to_button1);
    }
  }

  //check if button 1 has been pressed:
  if(sInterrupted[HandlerName::Button1]){
    // generate message
    Message to_button1;
    //to_button1.address
    mRecipients[HandlerName::Button1]->addMessage(&to_button1);
  }

  //check if button 2 has been pressed:
  if(sInterrupted[HandlerName::Button2]){
    // generate message
    Message to_button2;
    //to_button1.address
    mRecipients[HandlerName::Button2]->addMessage(&to_button2);
  }

  //check radio interrupt:
  if(sInterrupted[HandlerName::Radio]){
    // generate message
    Message to_radio;
    //to_button1.address
    mRecipients[HandlerName::Radio]->addMessage(&to_radio);
  }

  // Clear all interrupts flags:
  for(int i = 0; i < HandlerName::SIZE;++i){
    sInterrupted[i] = false;
  }
}

void InterruptHandler::setInterrupted() {
  //do nothing
}

void InterruptHandler::setInterrupted(HandlerName handler){
  //got an interrupt
  sInterrupted[handler] = true;
}

bool InterruptHandler::getInterrupted() {
  //do nothing
   return false;

}
void InterruptHandler::addRecipient(IHandler* recipient, HandlerName recipientName){
   mRecipients[recipientName] = recipient;
}
