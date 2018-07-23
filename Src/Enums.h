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
  RGB_B_Value,
  RGB_R_Brightness,
  RGB_G_Brightness,
  RGB_B_Brightness
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
  RGB_B = 0,
  PANEL,
  RGB_R,
  RGB_G,
  CHANNEL_SIZE
};
}
