#include "prototype_functions.h"  //include c libraries ,prototype functions and global variables

int count_mistakes(char a[],int c[27]) //a[] is the current generated text from main()- "generator_text" array"
{
    //int c[26]; //creat an array to coout mistakes for each letter
    int index;
    char input;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    long int initial_sec,end_sec;
    int typing_time;

    //initialize with 0 the array
    for(int i = 0; i < 27; i++)
    {
        c[i] = 0;
    }

    for(int i = 0; i < 50; i++)
    {
        input = user_input();

        //typing time counting start just after first input character
        if(i == 0)
        {
            initial_sec = time(NULL);
        }

        if(a[i] != input) //compare user input with generated text current character
        {
            //wait until the user enters the correct character
            while(a[i] != (input=user_input()) );

            //find the row_index which must be increased in c[] array
            index = 0;
            while(a[i] != alphabet[index])
            {
                index++;
            }
            c[index]++;

            //change color of mistaken character
            if(a[i] != ' ')
            {
                SetConsoleTextAttribute(hConsole, 4);
                printf("%c",input);
                SetConsoleTextAttribute(hConsole, 7);
            }

            if(a[i] == ' ')
            {
                SetConsoleTextAttribute(hConsole, 71);
                printf("_");
                SetConsoleTextAttribute(hConsole, 7);
            }
        }
        else
        {
            printf("%c",input);
        }
    }
     end_sec = time(NULL);

     return typing_time = end_sec - initial_sec;

}
int index_maxim_mistakes(int mistakes[27])
{
    int maxim = 0;
    int index = 0;
    for(int i = 0; i < 27; i++)
    {
        if(mistakes[i] > maxim)
        {
            maxim = mistakes[i];
            index = i;
        }
    }
    if(maxim > 0)
    {
        return index;
    }
    else
    {
        return -1; //means no mistakes were made
    }

}
int total_mistakes(int mistakes[27])
{
    int total = 0;

    for(int i = 0; i < 27; i++)
    {
        total += mistakes[i];
    }
    return total;
}


void read_file_fill_matrix(char file_name[30], int matrix[2][NR_OF_EXERCISES] )
{

    FILE* f;
    f = fopen(file_name,"r");
    int data1,data2; //just read from file the first two information but not use them to fill the matrix with it

    //initialize matrix with -1 --> not 0 because it can be confused with values of performance or level which can be 0
    //matrix contains informations of performance and level of user
    for(int i = 0; i < NR_OF_EXERCISES; i++)
    {
        matrix[0][i] = -1;
        matrix[1][i] = -1;
    }

    //if the file exist and contains values --> fill the last 5 values of performance and level in the matrix;

    if(f != NULL) //if file exists
    {
        while(!feof(f))
        {

            //move every row upwards to let free place for the last read position from file(2nd row comes instead of 1st row, 3rd row comes instead of 2nd row etc..)
            for(int i =0; i < NR_OF_EXERCISES-1; i++)
            {
                matrix[0][i] = matrix[0][i+1];
                matrix[1][i] = matrix[1][i+1];
            }

            //read a line from file and fill the matrix on the last position always

            fscanf(f,"%d %d %d %d\n", &data1,&data2,&matrix[0][NR_OF_EXERCISES-1],&matrix[1][NR_OF_EXERCISES-1]);
        }
    }
    fclose(f);
}

void update_performance_file(int cpm, int wpm, int perform, int level, char file_name[30])
{
     FILE* f;

     //add in file current user results
     f = fopen(file_name,"a");
     fprintf(f,"%d %d %d %d\n",cpm,wpm,perform,level);
     fclose(f);
}



