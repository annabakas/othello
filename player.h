#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "gameboard.h"
#define NAMELEN 20
typedef struct _player_t {
    char name[NAMELEN+1];
    char token;
} player_t;


extern void init_first_player(player_t *first);
extern void init_second_player(player_t *second);

#endif