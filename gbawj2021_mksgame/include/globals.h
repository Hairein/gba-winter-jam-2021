#ifndef MKS_GLOBALS_H
#define MKS_GLOBALS_H

// (valid sprite sizes: 8x8, 16x16, 32x32, 64x64, 16x8, 32x8, 32x16, 8x16, 8x32, 16x32, 32x64)

#define PLAYER_TURN_SPEED 1.0
#define PLAYER_FORWARD_SPEED 1.0
#define PLAYER_BACK_SPEED 0.75
#define PLAYER_PAN_SPEED 0.75

#define DEFAULT_SPRITE_VECTOR_SIZE 16
#define SHORT_FRAME_HOLD 2
#define MAX_PLAYER_ROTOR_INDEX 4
#define MAX_POW_WAVE_INDEX 3
#define MAX_CRATER_INDEX 4
#define FLASH_COUNTER_AMX 30

#define POW_LIFETIME_MAX (60*5)

#define INPUT_A 0x0001
#define INPUT_B 0x0002
#define INPUT_SELECT 0x0004
#define INPUT_START 0x0008
#define INPUT_RIGHT 0x0010
#define INPUT_LEFT 0x0020
#define INPUT_UP 0x0040
#define INPUT_DOWN 0x0080
#define INPUT_R 0x0100
#define INPUT_L 0x0200 

enum GameState 
{
    GAMESTATE_NONE, 
    GAMESTATE_INIT, 
    GAMESTATE_TITLE,
    GAMESTATE_SETTINGS,
    GAMESTATE_CREDITS,
    GAMESTATE_START_GAME,
    GAMESTATE_INGAME
};

enum PitchState
{
    PITCHSTATE_FORWARD_FULL,
    PITCHSTATE_FORWARD_HALF,
    PITCHSTATE_CENTER,
    PITCHSTATE_BACKWARD_HALF,
    PITCHSTATE_BACKWARD_FULL
};

enum RollState
{
    ROLLSTATE_LEFT_FULL,
    ROLLSTATE_LEFT_HALF,
    ROLLSTATE_CENTER,
    ROLLSTATE_RIGHT_HALF,
    ROLLSTATE_RIGHT_FULL
};

#endif