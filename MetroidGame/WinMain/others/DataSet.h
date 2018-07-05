#include<string>


//Control
#define LEFT_ARROW 1
#define RIGHT_ARROW 2
#define UP_ARROW 3
#define DOWN_ARROW 4
#define UNKEY 0
#define JUMP_BUTTON 5
#define SHOOT_BUTTON 6
#define GOD_MODE 100


//Character movement Sprite
#define FILE_IMAGE L"Metroid_sprite_motion_2.png"
#define SPRITE_FILE "sprite.txt"
#define COLLISION_FILE "leftofmap7.txt"
#define MONSTER_FILE "Monster1_2.txt"
#define RELATION_FILE "Relation2.txt"
#define DOOR_FILE "door2.txt"
#define FIELD_FILE "fieldCollision2.txt"
#define QUADTREE_FILE "QuadTree_leftofmap7.txt"
#define BRICK_FILE L"a2.png"
#define INTRO_FILE L"Intro.png"
#define MATRIX_FILE "halfofmap_left4.txt"

////Coordinates in sprite


//#define GROUND_SPIN_WIDTH 43
//#define GROUND_SPIN_HEIGHT 126

//Number of frame on sprite
#define RUN_COUNT 3
#define JUMP_COUNT 1
#define JUMP_SPIN_COUNT 4
#define GROUND_SPIN_COUNT 4
#define STAND_COUNT 1
#define STAND_GAURD_COUNT 1
#define MOVE_GAURD_COUNT 3
#define JUMP_GAURD_COUNT 1
#define MONSTER1_COUNT 1
#define MONSTER2_COUNT 2
#define MONSTER3_COUNT 1
#define MONSTER4_COUNT 1
#define BULLET_COUNT 1 
#define MOVE_SHOOT_COUNT 3
#define EXPLOSION_COUNT 2
#define DOOR_COUNT 1
#define KRAID_COUNT 2
#define KRAID_BULLET_COUNT 4
#define RIDLEY_COUNT 2
#define RIDLEY_BULLET_COUNT 4
#define SCENE_COUNT 1

#define RIGHT_MOVE_INDEX 0
#define LEFT_MOVE_INDEX 3

#define RIGHT_STAND_INDEX 6
#define LEFT_STAND_INDEX 7

#define RIGHT_JUMP_SPIN_INDEX 8
#define LEFT_JUMP_SPIN_INDEX 12

#define RIGHT_GROUND_SPIN_INDEX 16
#define LEFT_GROUND_SPIN_INDEX 20

#define RIGHT_JUMP_INDEX 24
#define LEFT_JUMP_INDEX 25

#define RIGHT_STAND_GAURD_INDEX 26
#define LEFT_STAND_GAURD_INDEX 27

#define RIGHT_MOVE_GAURD_INDEX 28
#define LEFT_MOVE_GAURD_INDEX 31

#define RIGHT_JUMP_GAURD_INDEX 34
#define LEFT_JUMP_GAURD_INDEX 35

#define BRICK 36
#define MONSTER1_UP_INDEX 37
#define MONSTER1_DOWN_INDEX 39
#define MONSTER1_LEFT_INDEX 40
#define MONSTER1_RIGHT_INDEX 38
#define MONSTER2_INDEX 41 
#define MONSTER3_INDEX 43
#define MONSTER4_INDEX 44
#define BULLET_INDEX 45


#define RIGHT_MOVE_SHOOT_INDEX 46
#define LEFT_MOVE_SHOOT_INDEX 49

#define EXPLOSION_INDEX 52

#define RIGHTDOOR_INDEX 54
#define LEFTDOOR_INDEX 55

#define LEFT_NORMAL_KRAID 56
#define RIGHT_NORMAL_KRAID 62

#define LEFT_AVERAGE_KRAID 58
#define RIGHT_AVERAGE_KRAID 64

#define LEFT_ADVANCE_KRAID 60
#define RIGHT_ADVANCE_KRAID 66

#define KRAID_NORMAL_BULLET 68
#define KRAID_AVERAGE_BULLET 72

#define RIGHT_RIDLEY_STAND 76
#define LEFT_RIDLEY_STAND 78

#define RIGHT_RIDLEY_FLY 80
#define LEFT_RIDLEY_FLY 82

#define RIDLEY_NORMAL_BULLET 84
#define RIDLEY_ADVANCE_BULLET 88

#define INTRO_INDEX 92
#define START_INDEX 93
#define CONTINUE_INDEX 94

// start room
#define BEGINNING_ROOM 0

// life
#define MONSTER1_LIFE 2
#define MONSTER2_LIFE 2
#define MONSTER4_LIFE 4
#define KRAID_LIFE 96
#define RIDLEY_LIFE 140
#define PLAYER_LIFE 100


//Fix Collision
#define FixWidth 6
#define FixHeight 2
#define FixX 3
#define FixY 5

#define JUMPSPIN 14