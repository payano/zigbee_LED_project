#pragma once

namespace MessagePkg {
enum Register {
  Pressed = 0,
  Potentiometer,
  Interrupt,
  Led_Panel_Value,
  Temperature_Value,
  RGB_R_Value,
  RGB_G_Value,
  RGB_B_Value
};
}
namespace HandlerPkg{
enum HandlerName {
  Hal, // don't send messages to interrupt, it will not be read.
  Led,
  Radio,
  Button1,
  Button2,
  SIZE
};
// assuming that everything runs on the same channel.
enum Channel {
  RGB_R = 0,
  RGB_G,
  RGB_B,
  PANEL,
  CHANNEL_SIZE
};
}
