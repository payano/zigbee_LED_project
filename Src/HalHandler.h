/*
 * InterruptHandler.h
 *
 *  Created on: Sep 25, 2017
 *      Author: johan
 */

#pragma once
#include "IHandler.h"
#include "stm32f0xx_hal.h"
#include "stm32f0xx_hal_adc.h"
#include <memory>

namespace HandlerPkg{
constexpr int INTERRUPT_LENGTH = 3;
constexpr int PWM_CHANNELS = 4;



class HalHandler: public IHandler {
private:
  const IRQn_Type button[2] = {EXTI0_1_IRQn, EXTI2_3_IRQn};
  const IRQn_Type radio = EXTI4_15_IRQn;
  const uint32_t PWM_CHANNEL[4] = {TIM_CHANNEL_1,TIM_CHANNEL_2,TIM_CHANNEL_3,TIM_CHANNEL_4};

  IHandler* mRecipients[HandlerName::SIZE];
  static bool sInterrupted[HandlerName::SIZE]; //static
  uint32_t* mAdcBuffer;
  uint32_t mAdcBufferLen;
  HandlerName mWhoami;
  ADC_HandleTypeDef *mHadc;
  TIM_HandleTypeDef *mTimer;
  TIM_OC_InitTypeDef* pwmConfig[PWM_CHANNELS];

public:
  HalHandler(HandlerName whoami, ADC_HandleTypeDef *hadc, TIM_HandleTypeDef *timer);
  virtual ~HalHandler();

  //static void putInterruptData(uint32_t InterruptIncData[3]);
  void addAdcBuffer(uint32_t* buffer, int len);

  void addMessage(MessagePkg::Message* message) override;
  void run() override;
  static void setInterrupted(HandlerName handler);
  virtual bool getInterrupted(const HandlerName *handler);
  virtual void enableInterrupt(const HandlerName *handler);
  virtual void disableInterrupt(const HandlerName *handler);
  virtual void setPWM(const Channel channel, int* value);
  virtual void getPWM(const Channel channel, int* value);
  virtual int potentiometerToButtonValue(const uint32_t* value);
  void addRecipient(IHandler* recipient, HandlerName recipientName) override;

};
}
