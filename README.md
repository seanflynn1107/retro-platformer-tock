# Retro Platformer for Tock OS

A side-scrolling platform game written in C for the Nordic nRF52840 Development Kit running Tock OS on a SH1106 OLED screen.
---

## Hardware

- Nordic nRF52840 DK
- SH1106 OLED Display
- U8g2 graphics library
- Tock OS
- libtock-c
- On-board push buttons // update in future with joystick
  
---

## Features

Current features include:

- Player movement
- Gravity
- Jumping physics
- Horizontal camera scrolling
- Platform collision detection
- Head collision detection
- Obstacles
- Coins
- World coordinate system
- Camera coordinate transformation
- Off-screen rendering optimization

---

## Software Architecture

The project is divided into several sections.

### main.c

Main game loop.

Responsible for:

- initializing hardware
- reading inputs
- updating physics
- collision detection
- camera movement
- rendering

---

### input.c

Interfaces with the Tock button driver.

Responsible for:

- Jump input
- Left movement
- Right movement

Future plans include replacing the buttons with an analog joystick.

---

### game.c

Contains the game engine.

Responsible for:

- gravity
- jumping
- collision detection
- platform landing
- obstacle collisions
- world physics

---

### display.c

Responsible for:

Drawing:

- player
- platforms
- obstacles
- coins
- world

Uses camera transformations to convert world coordinates into screen coordinates.

---

## Coordinate System

Objects exist in world space.

```
world_x
world_y
```

The display converts world coordinates into screen coordinates.

```
screen_x = world_x - camera_x

screen_y = world_y - camera_y
```

This allows the game world to be much larger than the OLED display.

---

## Controls

| Button | Action |
|---------|--------|
| BTN0 | Jump |
| BTN2 | Move Left |
| BTN3 | Move Right |

---

## Future Improvements

Planned additions include

- Animated sprites
- Better camera smoothing
- Enemy AI
- Collectible scoring system
- Multiple levels
- Moving platforms
- Slopes
- Health system
- Sound
- Save system
- Analog joystick control
- Motorsports dashboard graphics techniques reused for game engine

---

## Building

Requires

- Tock OS
- libtock-c
- arm-none-eabi toolchain
- U8g2 graphics library

Clone the repository into your libtock-c projects directory and build using:

```bash
make
```

Flash using

```bash
tockloader install
```

---

## Purpose

This project was created to strengthen embedded systems software skills by implementing a complete interactive application instead of a traditional sensor demo.

The project focuses on

- embedded graphics
- real-time programming
- collision detection
- game physics
- modular software architecture
- hardware abstraction
- efficient rendering on constrained hardware
