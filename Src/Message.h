/*
 * Message.h
 *
 *  Created on: Sep 13, 2017
 *      Author: johan
 */

#pragma once

/**
 * Address list:
 * 16 bit int.
 * 0b0 =
 */
namespace MessagePkg {
enum Register {
  Button1_Pressed = 0,
  Button1_Potentiometer,
  Button2_Pressed,
  Button2_Potentiometer,
  Led_Panel_Value,
  Temperature_Value,
  RGB_R_Value,
  RGB_G_Value,
  RGB_B_Value,
  Radio_Interrupt
};

struct Message {
  Register address;
  unsigned int value;
  bool write = false;
};
}
