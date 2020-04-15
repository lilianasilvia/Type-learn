#ifndef PROTOTYPE_FUNCTIONS_H_INCLUDED
#define PROTOTYPE_FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> //for changing the color of mistaken character
#include <conio.h>  //for using getch() function

#define NR_OF_EXERCISES 5 //exercises to calculate average performance

const char alphabet[28] = "eairnutclsodpmvfbgzhjkyxqw ";  //alphabet ordered from most used letters to less used ones - romanian language


//prototype functions from "new_lesson_generating"
void user_initial_output();
int generating_array(char generator[51],int level,int index_max_mistake); //generating text lesson
char user_input();
char menu();

//prototype functions from "user performance analysis"
int count_mistakes(char a[],int c[27]);
int index_maxim_mistakes(int mistakes[27]);
int total_mistakes(int mistakes[27]);
void update_performance_file(int cpm, int wpm, int perform, int level, char file_name[30]);
void read_file_fill_matrix(char file_name[30], int matrix[2][NR_OF_EXERCISES] );

//prototype functions from "decision_user_next_level"
int decision_upgrade_level(int matrix[2][NR_OF_EXERCISES]);
void reset_user_level(char file_name[30]);

#endif // PROTOTYPE_FUNCTIONS_H_INCLUDED
