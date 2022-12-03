#include "app.h"

#include <stdbool.h>

#define L_MOTOR EV3_PORT_A
#define R_MOTOR EV3_PORT_B

void init() {
  ev3_lcd_set_font(EV3_FONT_MEDIUM);
  ev3_motor_config(L_MOTOR, LARGE_MOTOR);
  ev3_motor_config(R_MOTOR, LARGE_MOTOR);
}

void forward() {
  ev3_motor_steer(L_MOTOR, R_MOTOR, 100, 0);  // power=100 turn=0:
}
void backward() {
  ev3_motor_steer(L_MOTOR, R_MOTOR, -100, 0);  // power=-100 turn=0:
}
void left_turn() {
  ev3_motor_steer(L_MOTOR, R_MOTOR, 100, -100);  // power=100 turn=-100:
}
void right_turn() {
  ev3_motor_steer(L_MOTOR, R_MOTOR, 100, 100);  // power=100 turn=100:
}
void stop() {
  ev3_motor_stop(L_MOTOR, false);
  ev3_motor_stop(R_MOTOR, false);
}

void main_task(intptr_t unused) {
  init();

  char c[2];
  bool exit = false;

  while (!exit) {
    serial_rea_dat(SIO_PORT_BT, c, 1);

    if (c != NULL) {
      switch (c[0]) {
        case 'w':
          forward();
          break;
        case 'a':
          left_turn();
          break;
        case 's':
          stop();
          break;
        case 'd':
          right_turn();
          break;
        case 'x':
          backward();
          break;
        case 'q':
          exit = true;
          break;
      }
    }
  }

  stop();
}
