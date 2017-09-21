/*
 * IHandler.h
 *
 *  Created on: Sep 21, 2017
 *      Author: johan
 */
#pragma once
#include <memory>
//forward declaring message:
class Message;

class IHandler {
public:
   virtual ~IHandler(){};
   virtual void run() = 0;
   virtual void setInterrupted() = 0;
   virtual bool getInterrupted() = 0;
   virtual void addMessage(std::unique_ptr<Message> message) = 0;
};
