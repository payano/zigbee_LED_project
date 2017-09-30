/*
 * IHandler.h
 *
 *  Created on: Sep 21, 2017
 *      Author: johan
 */
#pragma once
#include <memory>
//forward declaring message:
namespace MessagePkg{
  class Message;
}
class HalHandler;
enum HandlerName {
  Hal, // don't send messages to interrupt, it will not be read.
  Led,
  Radio,
  Button1,
  Button2,
  SIZE
};

class IHandler {
public:
   virtual ~IHandler(){};
   virtual void run() = 0;
   virtual void addMessage(MessagePkg::Message* message) = 0;
   virtual void addRecipient(IHandler* recipient, HandlerName recipientName) = 0;
};
