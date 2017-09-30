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

constexpr int INTERRUPT_LENGTH = 3;

class HalHandler: public IHandler {
private:
  IHandler* mRecipients[HandlerName::SIZE];
  static bool sInterrupted[HandlerName::SIZE]; //static
  uint32_t* mAdcBuffer;
  uint32_t mAdcBufferLen;
  HandlerName mWhoami;
  ADC_HandleTypeDef *hadc;

  const IRQn_Type button[2] = {EXTI0_1_IRQn, EXTI2_3_IRQn};
  const IRQn_Type radio = EXTI4_15_IRQn;

public:
  HalHandler(HandlerName whoami, ADC_HandleTypeDef *hadc);
  virtual ~HalHandler();

  //static void putInterruptData(uint32_t InterruptIncData[3]);
  void addAdcBuffer(uint32_t* buffer, int len);

  void addMessage(Message* message) override;
  void run() override;
  void setInterrupted() override;
  static void setInterrupted(HandlerName handler);
  bool getInterrupted() override;
  virtual bool getInterrupted(const HandlerName *recipient);

  virtual void enableInterrupt(const HandlerName *recipient);
  virtual void disableInterrupt(const HandlerName *recipient);

  void addRecipient(IHandler* recipient, HandlerName recipientName) override;

};
