#include "player.h"
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void init_first_player(player_t *first){
	char name[NAMELEN+1];

	printf("Enter name of Player 1: ");
	scanf("%s",name);
	strncpy(first -> name, name, NAMELEN);
	first -> token = 'X';
}

