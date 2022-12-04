#include "app.h"

#include <Motor.h>
#include <Steering.h>
#include <Port.h>

#define L_MOTOR EV3_PORT_A
#define R_MOTOR EV3_PORT_B

using namespace ev3api;

class MotorController {
 public:
  Motor *l_motor,*r_motor;
  Steering *steer;

  MotorController() {
    l_motor = new Motor((ePortM)L_MOTOR,(bool)true,  LARGE_MOTOR );
    r_motor = new Motor((ePortM)R_MOTOR,(bool)true,  LARGE_MOTOR );
    steer = new Steering(*l_motor, *r_motor);
  }

  void forward() {
    steer->setPower(100, 0);  // power=100 turn=0:
    tslp_tsk(1000000);       // 1sec sleep
  }
  void left_turn() {
    steer->setPower(100, -100);                          // power=100 turn=100:
      tslp_tsk(450000);                                // 450msec sleep
  }
  void stop() { steer->setPower(0, 0); }
};

void main_task(intptr_t unused) {
  auto c = new MotorController();
  for (int i = 0; i < 4; i++) {
      c->forward();
      c->left_turn();
  }
  c->stop();
}