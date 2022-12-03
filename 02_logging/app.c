#include "app.h"

void main_task(intptr_t unused) {
  ev3_lcd_set_font(EV3_FONT_MEDIUM);
  int i = 0;
  char txt[255];

  while (1) {
    syslog(LOG_WARNING, "Hello, LOG %d", i);
    sprintf(txt, "Hello, LCD %d", i);
    ev3_lcd_draw_string(txt, 0, 32);
    i++;
    tslp_tsk(500000);  // 500msec sleep
  }
}
