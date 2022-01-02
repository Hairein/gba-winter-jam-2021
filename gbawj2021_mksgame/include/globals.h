#ifndef MKS_GLOBALS_H
#define MKS_GLOBALS_H

// ! To run, set BUTANO "BN_CFG_MEMORY_MAX_EWRAM_ALLOC_ITEMS" to 128 and make clean; make
// (valid sprite sizes: 8x8, 16x16, 32x32, 64x64, 16x8, 32x8, 32x16, 8x16, 8x32, 16x32, 32x64)

#define PLAYER_TURN_SPEED 1.0
#define PLAYER_FORWARD_SPEED 1.0
#define PLAYER_BACK_SPEED 0.75
#define PLAYER_PAN_SPEED 0.75

#define PLAYER_SHOT_INTERVAL 120
#define TURRET_SHOT_INTERVAL 120
#define TANK_SHOT_INTERVAL 120
#define HELICOPTER_SHOT_INTERVAL 120

#define DEFAULT_SPRITE_VECTOR_SIZE 16
#define SINGLE_FRAME_HOLD 1
#define SHORT_FRAME_HOLD 2
#define MAX_PLAYER_ROTOR_INDEX 4
#define MAX_POW_WAVE_INDEX 3
#define MAX_CRATER_INDEX 4
#define FLASH_COUNTER_MAX 30
#define EXPLOSION_SEQUENCE_MAX 16
#define HIT_SEQUENCE_MAX 10

#define SHOT_SEQUENCE_MAX 2
#define SHOT_LIFETIME 25
#define SHOT_VELOCITY 4.0

#define PLAYER_MAX_HEALTH 100
#define TURRET_MAX_HEALTH 75
#define TANK_MAX_HEALTH 50
#define HELICOPTER_MAX_HEALTH 25
#define POW_CAGE_MAX_HEALTH 75
#define PLAYER_SHOT_DAMAGE 25
#define ENEMY_SHOT_DAMAGE 25
#define PLAYER_SHOT_DAMAGE_RADIUS 16
#define ENEMY_SHOT_DAMAGE_RADIUS 12
#define POW_PICKUP_RADIUS 8

#define ENEMY_SENSOR_RANGE 105
#define ENEMY_IDLE_ROTATE 1.0

#define MAP_TILES_X 128
#define MAP_TILES_Y 128
#define MAP_TILES_SIZE (MAP_TILES_X * MAP_TILES_Y)
#define MAP_SIZE_X 1024
#define MAP_SIZE_Y 1024
#define MAP_HALFSIZE_X 512
#define MAP_HALFSIZE_Y 512

#define MAP_TILE_SIZE_X 8
#define MAP_TILE_SIZE_Y 8
#define MAP_TILE_HALFSIZE_X 4
#define MAP_TILE_HALFSIZE_Y 4

#define MAPTYPE_EMPTY 0
#define MAPTYPE_POW_CAGE 225
#define MAPTYPE_HOME_PLATE 241
#define MAPTYPE_BLOCKER 242
#define MAPTYPE_TURRET_180_STATIC 226
#define MAPTYPE_TURRET_270_STATIC 227
#define MAPTYPE_TURRET_0_STATIC 228
#define MAPTYPE_TURRET_90_STATIC 229
#define MAPTYPE_TANK_180_STATIC 230
#define MAPTYPE_TANK_270_STATIC 231
#define MAPTYPE_TANK_0_STATIC 232
#define MAPTYPE_TANK_90_STATIC 233
#define MAPTYPE_HELICOPTER_180_STATIC 234
#define MAPTYPE_HELICOPTER_270_STATIC 235
#define MAPTYPE_HELICOPTER_0_STATIC 236
#define MAPTYPE_HELICOPTER_90_STATIC 237
#define MAPTYPE_TANK_180_MOBILE 246
#define MAPTYPE_TANK_270_MOBILE 247
#define MAPTYPE_TANK_0_MOBILE 248
#define MAPTYPE_TANK_90_MOBILE 249
#define MAPTYPE_HELICOPTER_180_MOBILE 250
#define MAPTYPE_HELICOPTER_270_MOBILE 251
#define MAPTYPE_HELICOPTER_0_MOBILE 252
#define MAPTYPE_HELICOPTER_90_MOBILE 253

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

enum TacticsBehaviour
{
    TACTICS_BEHAVIOUR_NONE,
    TACTICS_BEHAVIOUR_HORIZONTAL_PATROL,
    TACTICS_BEHAVIOUR_VERTICAL_PATROL,
    TACTICS_BEHAVIOUR_STATIC,
    TACTICS_BEHAVIOUR_CHASE   
};

#endif