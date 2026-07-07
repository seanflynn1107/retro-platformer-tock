#include "input.h"
#include <libtock/tock.h>


void input_init(void){
    int count;
    if (!libtock_button_exists()){
        return;
    }
    libtock_button_count(&count);
}

bool jump_pressed(void){
    int value = 0;
    libtock_button_read(JUMP_BUTTON, &value);
    return value;
}

bool right_pressed(void){
    int value = 0;
    libtock_button_read(RIGHT_BUTTON, &value);
    return value;
}

bool left_pressed(void){
    int value = 0;
    libtock_button_read(LEFT_BUTTON, &value);
    return value;
}