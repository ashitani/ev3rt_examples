
#ifdef __cplusplus
extern "C" {
#endif

#include "ev3api.h"

#define STACK_SIZE 4096 /* タスクのスタックサイズ */

#ifndef TOPPERS_MACRO_ONLY
extern void main_task(intptr_t exinf);
#endif

#ifdef __cplusplus
}
#endif
