#include "ev3api.h"
#include "target_test.h"

#define STACK_SIZE 4096 /* タスクのスタックサイズ */

#ifndef TOPPERS_MACRO_ONLY
extern void main_task(intptr_t exinf);
#endif
