/*
 * ButtonHandler.h
 *
 *  Created on: Sep 21, 2017
 *      Author: johan
 */

#pragma once

#include "IHandler.h"
#include <memory>

class ButtonHandler: public IHandler {
public:
   ButtonHandler();
   virtual ~ButtonHandler();
   void addMessage(std::unique_ptr<Message> message) override;
   void run() override;
   void setInterrupted() override;
   bool getInterrupted() override;
};
