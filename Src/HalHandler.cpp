/*
 * HalHandler.cpp
 *
 *  Created on: Sep 25, 2017
 *      Author: johan
 */

#include "HalHandler.h"
#include "Message.h"
#include "stm32f0xx_hal.h"


bool HalHandler::sInterrupted[HandlerName::SIZE] = {false};

HalHandler::HalHandler(HandlerName whoami, ADC_HandleTypeDef *hadc):
  mAdcBuffer(nullptr),
  mAdcBufferLen(0),
  mWhoami(whoami),
  hadc(hadc){
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
  // for the buttons the address is 0b10; aka 2;
  // 2 = Temperature sensor

  if(sInterrupted[HandlerName::Hal]){
    {
      // generate message
      Message message;
      message.address = 0b10;
      message.value = mAdcBuffer[0];
      mRecipients[HandlerName::Button1]->addMessage(&message);
    }
    {
      // generate message
      Message message;
      message.address = 0b10;
      message.value = mAdcBuffer[1];
      mRecipients[HandlerName::Button2]->addMessage(&message);
    }
    {
      // generate message to temp sensor
      // temp sensor has address 0x04;
      Message message;
      message.address = 0b100;
      message.value = mAdcBuffer[2];
      //mRecipients[HandlerName::Button1]->addMessage(&to_button1);
    }
  }

  //check if button 1 has been pressed:
  if(sInterrupted[HandlerName::Button1]){
    // generate message
    Message message;
    message.address = 0b1;
    message.value = 1;
    //to_button1.address
    mRecipients[HandlerName::Button1]->addMessage(&message);
  }

  //check if button 2 has been pressed:
  if(sInterrupted[HandlerName::Button2]){
    // generate message
    Message message;
    message.address = 0b1;
    message.value = 1;
    //to_button1.address
    mRecipients[HandlerName::Button2]->addMessage(&message);
  }

  //check radio interrupt:
  if(sInterrupted[HandlerName::Radio]){
    // generate message
    Message message;
    message.address = 0b1;
    message.value = 1;
    //to_button1.address
    mRecipients[HandlerName::Radio]->addMessage(&message);
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
  switch(recipient){
  Hal:
  // this is to be handled some how.
  HAL_ADC_Start_DMA(hadc, mAdcBuffer,3);
  break;
  Led:
  break;
  Radio:
  break;
  Button1:
  HAL_NVIC_EnableIRQ(EXTI0_1_IRQn);
  break;
  Button2:
  HAL_NVIC_EnableIRQ(EXTI2_3_IRQn);
  break;
  default:
    // temp sensor?
    // here it is anyway
    HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

    // do nothing
    break;
  }
}


void HalHandler::addRecipient(IHandler* recipient, HandlerName recipientName){
   mRecipients[recipientName] = recipient;
}
