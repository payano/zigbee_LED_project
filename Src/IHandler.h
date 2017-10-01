/*
 * IHandler.h
 *
 *  Created on: Sep 21, 2017
 *      Author: johan
 */
#pragma once
#include "Enums.h"
#include <memory>
//forward declaring message:
namespace MessagePkg{
  class Message;
}

namespace HandlerPkg{
class HalHandler;

class IHandler {
public:
   virtual ~IHandler(){};
   virtual void run() = 0;
   virtual void addMessage(MessagePkg::Message* message) = 0;
   virtual void addRecipient(IHandler* recipient, HandlerName recipientName) = 0;
};
}
