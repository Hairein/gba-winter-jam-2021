#ifndef MKS_GLOBALS_H
#define MKS_GLOBALS_H

#define PLAYER_TURN_SPEED 1.0
#define PLAYER_FORWARD_SPEED 1.0
#define PLAYER_BACK_SPEED 0.75
#define PLAYER_PAN_SPEED 0.75

enum GameState 
{
    NONE, 
    START, 
    TITLE,
    SETTINGS,
    CREDITS,
    NEW_GAME,
    CONTINUE_GAME,
    INGAME
};

#endif