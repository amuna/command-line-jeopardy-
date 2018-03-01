/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "players.h"



bool player_exists(player *players, char *name)
{
    bool exists;
    for(int i = 0; i<= sizeof(players); i++){
        if (players[i].name == name)
        {
            exists = true;
            break;
        }
        else {
            exists = false;
        }
    }
    return exists;
}

// Updates the score for the player
void update_score(player *players, int num_players, char *name, int score)
{
    for(int i = 1; i <= num_players; i++)
    {
        if (players[i].name == name)
        {
            players[i].score += score;
        }
    }
}
