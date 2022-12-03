#include "app.h"

void main_task(intptr_t unused) {
  ev3_lcd_set_font(EV3_FONT_MEDIUM);

  char c[2];
  while (1) {
      serial_rea_dat(SIO_PORT_BT, c, 1);

    if (c != NULL) {
      ev3_lcd_draw_string(c, 0, 16);
    }
  }
}
