#include "prototype_functions.h"  //include prototype functions and global variables

int decision_upgrade_level(int matrix[2][NR_OF_EXERCISES])
{
    int sum = 0;
    int average;
    int current_level;

    if(matrix[1][NR_OF_EXERCISES-1] == -1)  //if the file is not yet created and the matrix is not filled
    {
        current_level = 0;
    }

    else
    {
        current_level = matrix[1][NR_OF_EXERCISES-1]; //last level from matrix
    }

    //check if all level performance from the matrix are equal ( if we have 5 times the same level) -->only then the level can be increased
    if(matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix[1][2] && matrix[1][2] == matrix[1][3] && matrix[1][3] == matrix[1][4])
    {
        //calculate average performance of the last 5 exercises from matrix
        for(int i = 0; i < NR_OF_EXERCISES; i++)
        {
            sum += matrix[0][i];
        }
        average = sum/NR_OF_EXERCISES;

        //increase level if average >= 98% performance
        if(average >= 98 && current_level < 3)  //maxim level is 3
        {
            current_level++;
        }
    }

    return current_level;
}

void reset_user_level(char file_name[30])
{
    if(remove(file_name) == 0) //returns 0 if removed successfully
    {
        printf("User progress reset successfully\n");
    }
    else
    {
        printf("Error: Unable to reset the user progress\n");
    }
}
