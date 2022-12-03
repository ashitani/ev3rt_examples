#include "app.h"

int toggle0 = 0;
int toggle1 = 0;

void print_number(int num, int pos) {
  char txt[2];
  sprintf(txt, "%d", num);
  ev3_lcd_set_font(EV3_FONT_MEDIUM);
  ev3_lcd_draw_string(txt, 0, pos);
}

void main_task(intptr_t unused) {
  ev3_lcd_set_font(EV3_FONT_MEDIUM);
  ev3_lcd_draw_string("enter to exit", 0, 16);
  while (1) {
    tslp_tsk(500000);  // 500msec スリープ
    print_number(toggle0, 48);
    toggle0 = 1 - toggle0;
  }
}

// 1sec間隔で実行される
void sub_task(intptr_t unused) {
  print_number(toggle1, 80);
  toggle1 = 1 - toggle1;
}
