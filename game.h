#ifndef GAME_H
#define GAME_H
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_OBSTACLES 10
#define MAX_PLATFORMS 10
#define MAX_COINS     10


typedef struct {
    int world_x;
    int world_y;

    int previous_x;
    int previous_y;

    int vx;
    int vy;

    bool on_ground;
} Player;

typedef struct {
    int world_x;
    int world_y;
    int width;
    int height;
} Obstacle;

typedef struct {
    int world_x;
    int world_y;
    int width;
    int height;
} Platform;

typedef struct {
    int world_x;
    int world_y;
    int radius;
    bool collected;
} Coin;


void player_init(Player *player);
void apply_gravity(Player *player);
bool collide_obstacle(Player *player, Obstacle *obstacle);
void collide_platform(Player *player, Platform platforms[]);
void collide_ground(Player *player);
bool collide_coin(Player *player, Coin *coin);
void jump(Player *player);

#endif