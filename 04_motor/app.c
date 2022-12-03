#include "app.h"

#define L_MOTOR EV3_PORT_A
#define R_MOTOR EV3_PORT_B

void init() {
  ev3_motor_config(L_MOTOR, LARGE_MOTOR);
  ev3_motor_config(R_MOTOR, LARGE_MOTOR);
}

void forward() {
  ev3_motor_steer(L_MOTOR, R_MOTOR, 100, 0);  // power=100 turn=0:
  tslp_tsk(1000000);                                // 1sec sleep
}

void left_turn() {
  ev3_motor_steer(L_MOTOR, R_MOTOR, 100, -100);  // power=100 turn=-100:
  tslp_tsk(450000);                                    // 300msec sleep
}

void stop() {
  ev3_motor_stop(L_MOTOR, true);
  ev3_motor_stop(R_MOTOR, true);
}

void main_task(intptr_t unused) {
  init();
  for (int i = 0; i < 4; i++) {
    forward();
    left_turn();
  }
  stop();
}
