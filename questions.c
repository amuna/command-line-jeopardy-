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
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    
    //100pts question
    strcpy(questions[0].category, "programming");
    strcpy(questions[0].question, "A variable of this type doesn't contain the value directly.");
    strcpy(questions[0].answer, "non primitive");
    questions[0].value = 100;
    questions[0].answered = true;

    strcpy(questions[1].category, "algorithm");
    strcpy(questions[1].question, "The type of algorithm that takes the most optimal choice on each stage is");
    strcpy(questions[1].answer,  "greedy");
    questions[1].value = 100;
    questions[1].answered = false;

    strcpy(questions[2].category, "databases");
    strcpy(questions[2].question, "This object contains a unique value for each row of data and cannot contain null values.");
    strcpy(questions[2].answer, "primary key");
    questions[2].value = 100;
    questions[2].answered = false;

    strcpy(questions[3].category, "programming");
    strcpy(questions[3].question, "Programmers can define the datatype of the data structure and the operations that can be applied to the data structure.");
    strcpy(questions[3].answer, "object oriented programming");
    questions[3].value = 200;
    questions[3].answered = false;

    strcpy(questions[4].category, "algorithm");
    strcpy(questions[4].question,  "The type of algorithm breaks down a complex problem int simpler subproblems, each subproblem once and storing its solution");
    strcpy(questions[4].answer,  "dynamic programming");
    questions[4].value = 200;
    questions[4].answered = false;

    strcpy(questions[5].category, "databases");
    strcpy(questions[5].question, "This object is field in one table that unqiquely identifies a row of another table");
    strcpy(questions[5].answer, "foreign key");
    questions[5].value = 200;
    questions[5].answered = false;

    strcpy(questions[6].category, "programming");
    strcpy(questions[6].question, "This language is used for to display information on the word wide web.");
    strcpy(questions[6].answer, "html");
    questions[6].value = 400;
    questions[6].answered = false;

    strcpy(questions[7].category, "algorithm");
    strcpy(questions[7].question, "The type of tests all possible solutions as the answer to the problem");
    strcpy(questions[7].answer, "brute force");
    questions[7].value = 400;
    questions[7].answered = false;

    strcpy(questions[8].category, "databases");
    strcpy(questions[8].question, "This is a request for data from a database table or combination of tables.");
    strcpy(questions[8].answer, "query");
    questions[8].value = 400;
    questions[8].answered = false;

    strcpy(questions[9].category, "algorithm");
    strcpy(questions[9].question, "The type of algorithm that breaks down a problem into two or more sub-problems of the same related type until they become simple enough to be solved directly.");
    strcpy(questions[9].answer, "divide and conquer");
    questions[9].value = 800;
    questions[9].answered = false;

    strcpy(questions[10].category, "programming");
    strcpy(questions[10].question, "The computer science degree at UOIT was formely know as.");
    strcpy(questions[10].answer, "computing science");
    questions[10].value = 800;
    questions[10].answered = false;

    strcpy(questions[11].category, "databases");
    strcpy(questions[11].question, "This constraint is a restriction placed on a column enforcing that every row of data must contain a value.");
    strcpy(questions[11].answer, "not null");
    questions[11].value = 800;
    questions[11].answered = false;
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    int i = 0;
    printf("%s\t%s\t%s\n", categories[0],categories[1],categories[2]);
    while(i < NUM_QUESTIONS) {
        if (i%3 == 0 && i != 0) {
            printf("\n");
        }
        if(!questions[i].answered) {
            printf("%d\t\t", questions[i].value);
        } else {
            printf("*\t\t");
        }
    i++;
    }
    printf("\n");
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
    int i = 0;
    while(i<NUM_QUESTIONS) {
        if ((!strcmp(questions[i].category, category)) && questions[i].value == value) { 
            printf("%s\n", questions[i].question);
        } 
        i++;
    }
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    int i = 0;
    while(i<NUM_QUESTIONS) {
        if ((!strcmp(questions[i].category, category)) && questions[i].value == value) { 
            if(questions[i].answered == true) {
                return true;
            } 
        } 
        i++;
    }
    return false;
}

