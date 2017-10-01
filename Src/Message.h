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
  unsigned int value;
  bool write = false;
};
}
