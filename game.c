#include "game.h"
#include <stdint.h>
#include <stdio.h>
#include <libtock/tock.h>
#include <u8g2.h>
#include <u8g2-tock.h>

const int GROUND_Y = 500;

void player_init(Player *player){
    player->world_x = 20;
    player->world_y = GROUND_Y;
    player->previous_x = player->world_x;
    player->previous_y = player->world_y;
    player->vx = 0;
    player->vy = 0;
    player->on_ground = true;
}

void jump(Player *player){
    if(player->on_ground){
        player->vy = -8;
        player->on_ground = false;
    }
}

void apply_gravity(Player *player){
    player->previous_y = player->world_y;
    player->vy++;
    if(player->vy > 6){
        player->vy = 6;
    }
    player->world_y += player->vy;
}

void collide_ground(Player *player)
{
    if(player->world_y > GROUND_Y)
    {
        player->world_y = GROUND_Y;

        player->vy = 0;

        player->on_ground = true;
    }

}

// void collide_platform(Player *player, Platform platforms[]){
//     player->on_ground = false;
//     int playerLeft = player->world_x - 4;
//     int playerRight = player->world_x + 4;
//     int playerTop = player->world_y - 12;
//     int playerBottom = player->world_y + 12;
//     int previousTop = player->previous_y - 12;
//     int previousBottom = player->previous_y + 12;

//     for(int i=0;i<MAX_PLATFORMS;i++){
//         int left = platforms[i].world_x;
//         int right = left + platforms[i].width;
//         int top = platforms[i].world_y;
//         int bottom = top + platforms[i].height;

//         if(playerRight < left)
//             continue;

//         if(playerLeft > right)
//             continue;

//         if(player->vy > 0 && previousBottom <= top && playerBottom >= top){
//             player->world_y = top - 12;
//             player->vy = 0;
//             player->on_ground = true;
//         }

//         if(player->vy < 0 && previousTop >= bottom && playerTop <= bottom){
//             player->world_y = bottom + 12;
//             player->vy = 0;
//         }
//     }
// }

void collide_platform(Player *player, Platform platforms[])
{
    player->on_ground = false;

    int playerLeft = player->world_x - 4;
    int playerRight = player->world_x + 4;
    int playerTop = player->world_y - 12;
    int playerBottom = player->world_y + 12;

    int previousTop = player->previous_y - 12;
    int previousBottom = player->previous_y + 12;

    for(int i = 0; i < MAX_PLATFORMS; i++)
    {
        int left = platforms[i].world_x;
        int right = left + platforms[i].width;
        int top = platforms[i].world_y;
        int bottom = top + platforms[i].height;

        if(playerRight <= left || playerLeft >= right)
            continue;

        if(player->vy > 0 &&
           previousBottom <= top &&
           playerBottom >= top)
        {
            player->world_y = top - 12;
            player->vy = 0;
            player->on_ground = true;
        }

        else if(player->vy < 0 &&
                previousTop >= bottom &&
                playerTop <= bottom)
        {
            player->world_y = bottom + 12;
            player->vy = 0;
        }
    }
}

bool collide_obstacle(Player *player, Obstacle *obstacle){
    int playerLeft = player->world_x - 4;
    int playerRight = player->world_x + 4;
    int playerTop = player->world_y - 12;
    int playerBottom = player->world_y + 12;

    int obsLeft = obstacle->world_x;
    int obsRight = obsLeft + obstacle->width;
    int obsTop = obstacle->world_y;
    int obsBottom = obsTop + obstacle->height;

    return !(playerRight < obsLeft || playerLeft > obsRight || playerBottom < obsTop || playerTop > obsBottom);
}

bool collide_coin(Player *player, Coin *coin){
    if(coin->collected)
        return false;

    int playerLeft = player->world_x - 4;
    int playerRight = player->world_x + 4;
    int playerTop = player->world_y - 12;
    int playerBottom = player->world_y + 12;

    int coinLeft = coin->world_x - coin->radius;
    int coinRight = coin->world_x + coin->radius;
    int coinTop = coin->world_y - coin->radius;
    int coinBottom = coin->world_y + coin->radius;

    if(!(playerRight < coinLeft ||
         playerLeft > coinRight ||
         playerBottom < coinTop ||
         playerTop > coinBottom))
    {
        coin->collected = true;
        return true;
    }

    return false;
}