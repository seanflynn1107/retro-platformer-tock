#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "game.h"
#include <../libtock-c/libtock/interface/button.h>

#define JUMP_BUTTON   0
#define LEFT_BUTTON   2
#define RIGHT_BUTTON  3

void input_init(void);

bool jump_pressed(void);
bool left_pressed(void);
bool right_pressed(void);

#endif