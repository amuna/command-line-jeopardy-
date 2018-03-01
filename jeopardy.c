/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(struct player *players, int num_players);

int game_state;


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];

    // EXAMPLE: player 1 is named Fred
    //strcpy(players[0].name, "Fred");
    //printf("%s\n", players[0].name);
    
    // Buffer for user input
    char buffer[BUFFER_LEN] = { 0 };
    char cat[BUFFER_LEN] = { 0 };
    int value;
    char playerTurn[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
    printf("Welcome to the game!\n");
	for(int i = 1; i < 5;i++){
		players[i].score = 0;
		
		printf("Player%d, enter your name: ", i);
		scanf("%s",(char*)&players[i].name);
	
	}
    
    // initialize each of the players in the array

    // Perform an infinite loop getting command input from users until game ends
    game_state = 1;
	
	
	
    while (game_state)
    {

        // Call functions from the questions and players source files
        display_categories();

        int r = rand() % 5;

        printf("%s, it is your turn\n", players[r].name);

        printf("Choose a category: ");
        scanf("%s", cat);
        printf("Catagory chosen: %s\n", cat);

        printf("Choose points:");
        scanf("%d", &value);
        printf("Value chosen:%d\n\n", value);

        while (already_answered(cat, value)) {
            printf("Not valid category/value. Please enter again\n");
            
            printf("Choose a category: ");
            scanf("%s", cat);
            printf("Catagory chosen: %s\n", cat);

            printf("Choose points:");
            scanf("%d", &value);
            printf("Value chosen:%d\n\n", value);
        }

        display_question(cat, value);
        
        printf("Write your answer:");
        scanf("%s", buffer);

        if(valid_answer(cat, value, buffer)) {
            update_score(players, 4, players[r].name, value);
        }
        
        // Execute the game until all questions are answered

        // Display the final results and exit
    }
    return EXIT_SUCCESS;
}

void tokenize(char *input, char **tokens) {
    char *str;

    if((str = strtok(input, "")) != NULL)
        if(strcmp(str, "who") != 0 && strcmp(str, "what") != 0)
            return;

    if((str = strtok(NULL, "")) != NULL)
        if(strcmp(str, "is") != 0)
            return;

    *tokens = strtok(NULL, "\n");
}

void show_results(player *players, int num_players) {
    int name = 0;
    int score = 0;
    int winner = 0;

    for(int i = 0; i < num_players; i++) {
        if((int) strlen(players[i].name) > name)
            name = strlen(players[i].name);

        if(players[i].score > score) {
            score = players[i].score;
            winner = i;
        }
    }

    printf("Scores: \n");
    for(int i = 0; i < num_players; i++)
        printf("%*s: %d\n", name + 1, players[i].name, players[i].score);

    printf("Winner: %s", players[winner].name);
}
