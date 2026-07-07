#include "display.h"
#include <stdint.h>
#include <stdio.h>
#include <libtock/tock.h>
#include <u8g2.h>
#include <u8g2-tock.h>

extern u8g2_t u8g2;


void display_init(void){
    u8g2_tock_init(&u8g2);
}

void obstacle_init(Obstacle obstacles[]){
  for(int i=0; i < MAX_OBSTACLES; i++){
    obstacles[i].world_x = 150 + 100 * i;
    obstacles[i].world_y = 492;
    obstacles[i].width = 8;
    obstacles[i].height = 8;
  } 
}

void platform_init(Platform platforms[]){
  for(int i=0; i < MAX_PLATFORMS; i++){
    platforms[i].world_x = 120 + 40 * i;
    platforms[i].world_y = 480;
    platforms[i].width = 16;
    platforms[i].height = 8;
  }
}

void coin_init(Coin coins[]){
  for(int i=0; i < MAX_COINS; i++){
    coins[i].world_x = 100 + 45 * i;
    coins[i].world_y = 470;
    coins[i].radius = 2;
  }
}

void draw_player(Player *player, int camera_x, int camera_y){
    int screen_x = player->world_x - camera_x;
    int screen_y = player->world_y - camera_y - 12;
    
    u8g2_DrawCircle(&u8g2, screen_x, screen_y - 8, 4, U8G2_DRAW_ALL);
    u8g2_DrawVLine(&u8g2, screen_x, screen_y, 8);
    u8g2_DrawLine(&u8g2, screen_x, screen_y + 8, screen_x - 3, screen_y + 12);
    u8g2_DrawLine(&u8g2, screen_x, screen_y + 8, screen_x + 3, screen_y + 12);
}

void draw_obstacle(Obstacle *obstacle, int camera_x, int camera_y){
    int screen_x = obstacle->world_x - camera_x;
    if(screen_x + obstacle->width < 0){
        return;
    }
    if(screen_x > 127){
        return; 
    }
    int screen_y = obstacle->world_y - camera_y;
    if(screen_y + obstacle->height < 0){
        return;
    }

    if(screen_y > 63){
        return;
    }

    u8g2_DrawBox(&u8g2, screen_x, screen_y, obstacle->width, obstacle->height);
}

void draw_platform(Platform *platform, int camera_x, int camera_y){
    int screen_x = platform->world_x - camera_x;
    if(screen_x + platform->width < 0){
        return;
    }
    if(screen_x > 127){
        return; 
    }

    int screen_y = platform->world_y - camera_y;
    if(screen_y + platform->height < 0){
        return;
    }

    if(screen_y > 63){
        return;
    }
    u8g2_DrawBox(&u8g2, screen_x, screen_y, platform->width, platform->height);
}

void draw_coin(Coin *coin, int camera_x, int camera_y){
    int screen_x = coin->world_x - camera_x;
        if(screen_x + coin->radius < 0){
        return;
    }
    if(screen_x > 127){
        return; 
    }
    int screen_y = coin->world_y - camera_y;
    if(screen_y + coin->radius < 0){
        return;
    }

    if(screen_y > 63){
        return;
    }

    if(!coin->collected){
        u8g2_DrawDisc(&u8g2, screen_x, screen_y, coin->radius, U8G2_DRAW_ALL);
    }   
}

void draw_frame(Player *player, Obstacle obstacles[], Platform platforms[], Coin coins[], int camera_x, int camera_y) {
    u8g2_ClearBuffer(&u8g2);

    int ground_screen_y = 500 - camera_y;;
    u8g2_DrawHLine(&u8g2, 0, ground_screen_y, 128);

    draw_player(player, camera_x, camera_y);
    for(int i=0; i<MAX_OBSTACLES; i++)
    {
        draw_obstacle(&obstacles[i], camera_x, camera_y);
    }
    for(int j=0; j < MAX_PLATFORMS; j++){
        draw_platform(&platforms[j], camera_x, camera_y);
    }

    for(int k=0; k < MAX_COINS; k++){
        draw_coin(&coins[k], camera_x, camera_y);
    }

    u8g2_SendBuffer(&u8g2);
}