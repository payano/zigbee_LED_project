/*
 * HalHandler.cpp
 *
 *  Created on: Sep 25, 2017
 *      Author: johan
 */

#include "HalHandler.h"
#include "Message.h"

//#include "stm32f0xx_hal.h"

namespace HandlerPkg{
bool HalHandler::sInterrupted[HandlerName::SIZE] = {false};

HalHandler::HalHandler(HandlerName whoami, ADC_HandleTypeDef *hadc, TIM_HandleTypeDef *timer):
      mAdcBuffer(nullptr),
      mAdcBufferLen(0),
      mWhoami(whoami),
      mHadc(hadc),
      mTimer(timer){

  for(int i = 0; i < PWM_CHANNELS; ++i){
    pwmPulseValues[i] = 0; //set PWM pulse to zero, it is off by default.

    pwmConfig[i] = new TIM_OC_InitTypeDef;

    // initiation of PWM configuration
    pwmConfig[i]->OCMode = TIM_OCMODE_PWM1;
    pwmConfig[i]->Pulse = 00;
    pwmConfig[i]->OCPolarity = TIM_OCNPOLARITY_HIGH;
    pwmConfig[i]->OCFastMode = TIM_OCFAST_DISABLE;
  }

  // TODO Auto-generated constructor stub
}

HalHandler::~HalHandler() {
  // TODO Auto-generated destructor stub
  for(int i = 0; i < PWM_CHANNELS; ++i){
    delete pwmConfig[i];
  }
}

void HalHandler::addAdcBuffer(uint32_t* buffer, int len){
  //TODO untested:
  mAdcBuffer = buffer;
  mAdcBufferLen = len;
}

void HalHandler::addMessage(MessagePkg::Message* message){
  //do nothing Hal Handler can not receive messages...
}

void HalHandler::run() {

  using namespace HandlerPkg;
  using namespace MessagePkg;
  // TODO: untested:
  //Check ADC:
  // 0 = Button 1 (potentiometer)
  // 1 = Button 2 (potentiometer)
  // 2 = Temperature sensor

  if(sInterrupted[HandlerName::Hal]){
    {
      // generate message

      MessagePkg::Message message;
      message.toAddress = HandlerName::Button1;
      message.fromAddress = HandlerName::Hal;
      message.type = Register::Potentiometer;
      message.value = potentiometerToButtonValue(&mAdcBuffer[0]);
      mRecipients[HandlerName::Button1]->addMessage(&message);
    }
    {
      // generate message

      MessagePkg::Message message;
      message.toAddress = HandlerName::Button2;
      message.fromAddress = HandlerName::Hal;
      message.type = Register::Potentiometer;
      message.value = potentiometerToButtonValue(&mAdcBuffer[1]);
      mRecipients[HandlerName::Button2]->addMessage(&message);
    }
    {
      // generate message
      MessagePkg::Message message;
      message.toAddress = HandlerName::Hal;
      message.fromAddress = HandlerName::Hal;
      message.type = Register::Temperature_Value;
      message.value = mAdcBuffer[2];
      //mRecipients[HandlerName::Hal]->addMessage(&message);
    }
  }

  //check if button 1 has been pressed:
  if(sInterrupted[HandlerName::Button1]){
    // generate message
    MessagePkg::Message message;
    message.toAddress = HandlerName::Button1;
    message.fromAddress = HandlerName::Hal;
    message.type = Register::Pressed;
    message.value = 1;
    mRecipients[HandlerName::Button1]->addMessage(&message);
  }

  //check if button 2 has been pressed:
  if(sInterrupted[HandlerName::Button2]){
    // generate message
    MessagePkg::Message message;
    message.toAddress = HandlerName::Button2;
    message.fromAddress = HandlerName::Hal;
    message.type = Register::Pressed;
    message.value = 1;
    mRecipients[HandlerName::Button2]->addMessage(&message);
  }

  //check radio interrupt:
  if(sInterrupted[HandlerName::Radio]){
    // generate message
    MessagePkg::Message message;
    message.toAddress = HandlerName::Radio;
    message.fromAddress = HandlerName::Hal;
    message.type = Register::Interrupt;
    message.value = 1;
    mRecipients[HandlerName::Radio]->addMessage(&message);
  }

  // Clear all interrupts flags:
  for(int i = 0; i < HandlerName::SIZE;++i){
    sInterrupted[i] = false;
  }

  // Enable ADC
  enableInterrupt(&mWhoami);
}

void HalHandler::setInterrupted(HandlerName handler){
  //got an interrupt
  sInterrupted[handler] = true;
}

bool HalHandler::getInterrupted(const HandlerName *handler) {
  //do nothing
  return sInterrupted[*handler];

}
void HalHandler::enableInterrupt(const HandlerName *handler){
  // reset interrupt flag
  sInterrupted[*handler] = false;

  switch(*handler){
  case Hal:
    // this is to be handled some how.
    HAL_ADC_Start_DMA(mHadc, mAdcBuffer,mAdcBufferLen);
    break;
  case Led:
    //led has PWM, no interrupts.
    break;
  case Radio:
    HAL_NVIC_EnableIRQ(radio);
    break;
  case Button1:
    HAL_NVIC_EnableIRQ(button[0]);
    break;
  case Button2:
    HAL_NVIC_EnableIRQ(button[1]);
    break;
  default:
    // do nothing
    break;
  }
}

void HalHandler::disableInterrupt(const HandlerName *handler){
  sInterrupted[*handler] = false;

  switch(*handler){
  case Hal:
    // this is to be handled some how.
    HAL_ADC_Start_DMA(mHadc, mAdcBuffer,mAdcBufferLen);
    break;
  case Led:
    //led has PWM, no interrupts.
    break;
  case Radio:
    HAL_NVIC_DisableIRQ(radio);
    break;
  case Button1:
    HAL_NVIC_DisableIRQ(button[0]);
    break;
  case Button2:
    HAL_NVIC_DisableIRQ(button[1]);
    break;
  default:
    // temp sensor?
    // here it is anyway
    // do nothing
    break;
  }
}

void HalHandler::setPWM(const Channel channel, int *value){
  // Dont go over the period time!
  if(*value > 254){*value = 254;}
  pwmConfig[channel]->Pulse = *value;
  HAL_TIM_PWM_Stop_IT(mTimer, PWM_CHANNEL[channel]);
  HAL_TIM_PWM_ConfigChannel(mTimer, pwmConfig[channel], PWM_CHANNEL[channel]);
  HAL_TIM_PWM_Start_IT(mTimer, PWM_CHANNEL[channel]);

}

void HalHandler::getPWM(const Channel channel, int* value){
  *value = pwmConfig[channel]->Pulse;
}

int HalHandler::potentiometerToButtonValue(const uint32_t* value){
  // 255/4034 = ..
  constexpr float convertFactor = 0.063212692117005453644025780862667327714427367377293009419;
  // measure value. think it is between 0-4000
  // this will do the equation:  255
  //                            ---- =  0.063212692117005453644025780862667327714427367377293009419
  //                             4034
  int returnval = (int)(*value);
  returnval *= convertFactor;
  return returnval;

}
void HalHandler::addRecipient(IHandler* recipient, HandlerName recipientName){
  mRecipients[recipientName] = recipient;
}
}
