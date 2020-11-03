#include "app.h"

void main_task(intptr_t unused) {
  ev3_lcd_set_font(EV3_FONT_MEDIUM);
  ev3_lcd_draw_string("Hello, EV3RT", 0, 32);
}
