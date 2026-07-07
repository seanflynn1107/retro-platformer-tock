#include <stdio.h>
#include <libtock/tock.h>

#include <u8g2.h>
#include <u8g2-tock.h>
#include "display.h"
#include "game.h"
#include "input.h"


u8g2_t u8g2;
Player player;
Obstacle obstacles[MAX_OBSTACLES];
Platform platforms[MAX_PLATFORMS];
Coin coins[MAX_COINS];





int main(void){
  
  
  display_init();

  input_init();

  player_init(&player);

  int camera_x = 0;
  
  int camera_y = 450; 

  obstacle_init(obstacles);

  platform_init(platforms);

  coin_init(coins);


  while (1){
        
    if (jump_pressed()){
        jump(&player);
    }

    if (right_pressed()){
      player.world_x += 2;
    }

    if (left_pressed() && player.world_x > 20){
        player.world_x -= 2;
    }

    player.on_ground = false;


    apply_gravity(&player);
    
    collide_platform(&player, platforms);

    collide_ground(&player);

    camera_x = player.world_x - 20;
    camera_y = player.world_y - 50;
    
    if(camera_x < 0){
      camera_x = 0;
    }

    if(camera_y < 450){
      camera_y = 450;
    }

    for(int i=0; i<MAX_OBSTACLES; i++){
      if(collide_obstacle(&player, &obstacles[i])){
        printf("Game Over\n");
      }
    }
      draw_frame(&player, obstacles, platforms, coins, camera_x, camera_y);
  }

    return 0;
}



