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
  virtual void enableInterrupt(HandlerName recipient);
  void addRecipient(IHandler* recipient, HandlerName recipientName) override;

};
