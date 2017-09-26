/*
 * HalHandler.cpp
 *
 *  Created on: Sep 25, 2017
 *      Author: johan
 */

#include "HalHandler.h"

#include "Message.h"

bool HalHandler::sInterrupted[HandlerName::SIZE] = {false};

HalHandler::HalHandler():
  mAdcBuffer(nullptr),
  mAdcBufferLen(0){
  // TODO Auto-generated constructor stub
}

HalHandler::~HalHandler() {
  // TODO Auto-generated destructor stub
}

void HalHandler::addAdcBuffer(uint32_t* buffer, int len){
  //TODO untested:
  mAdcBuffer = buffer;
  mAdcBufferLen = len;
}

void HalHandler::addMessage(Message* message){
   //do nothing
}

void HalHandler::run() {

  // TODO: untested:
  //Check ADC:
  // 0 = Button 1 (potentiometer)
  // 1 = Button 2 (potentiometer)
  // 2 = Temperature sensor

  if(sInterrupted[HandlerName::Hal]){
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

void HalHandler::setInterrupted() {
  //do nothing
}

void HalHandler::setInterrupted(HandlerName handler){
  //got an interrupt
  sInterrupted[handler] = true;
}

bool HalHandler::getInterrupted() {
  //do nothing
   return false;

}
void HalHandler::enableInterrupt(HandlerName recipient){
  //enable interrupts.
}

void HalHandler::addRecipient(IHandler* recipient, HandlerName recipientName){
   mRecipients[recipientName] = recipient;
}
