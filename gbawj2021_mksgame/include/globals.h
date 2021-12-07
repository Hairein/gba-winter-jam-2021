#ifndef MKS_GLOBALS_H
#define MKS_GLOBALS_H

// (valid sprite sizes: 8x8, 16x16, 32x32, 64x64, 16x8, 32x8, 32x16, 8x16, 8x32, 16x32, 32x64)

#define PLAYER_TURN_SPEED 1.0
#define PLAYER_FORWARD_SPEED 1.0
#define PLAYER_BACK_SPEED 0.75
#define PLAYER_PAN_SPEED 0.75

enum GameState 
{
    NONE, 
    INIT, 
    TITLE,
    SETTINGS,
    CREDITS,
    START_GAME,
    INGAME
};

#endif