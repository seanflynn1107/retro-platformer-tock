#ifndef DISPLAY_H
#define DISPLAY_H
#include <stdint.h>
#include <stdio.h>
#include "game.h"

void display_init(void);
void obstacle_init(Obstacle obstacles[]);
void platform_init(Platform platforms[]);
void coin_init(Coin coins[]);
void draw_player(Player *player, int camera_x, int camera_y);
void draw_obstacle(Obstacle *obstacle, int camera_x, int camera_y);
void draw_platform(Platform *platform, int camera_x, int camera_y);
void draw_coin(Coin *coin, int camera_x, int camera_y);
void draw_frame(Player *player, Obstacle obstacles[], Platform platforms[], Coin coins[], int camera_x, int camera_y);





#endif
