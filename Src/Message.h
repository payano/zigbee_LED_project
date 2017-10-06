/*
 * Message.h
 *
 *  Created on: Sep 13, 2017
 *      Author: johan
 */

#pragma once
#include "Enums.h"
/**
 * Address list:
 * 16 bit int.
 * 0b0 =
 */
namespace MessagePkg {

struct Message {
  HandlerPkg::HandlerName fromAddress;
  HandlerPkg::HandlerName toAddress;
  Register type;
  int value;
  bool write = false;
};

class MessageBox{
private:
  Message *mMessages;
  int mTotalSize;
  int mUsed;

public:
  MessageBox(int size);
  virtual ~MessageBox();
  void putMessage(Message* message);
  void getMessage(Message* message);
  bool empty();
  bool full();
  int maxSize();
  int usedSize();

};
}
