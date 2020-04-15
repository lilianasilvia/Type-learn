#include "prototype_functions.h"  //include prototype functions and global variables

int generating_array(char generator[51],int level,int index_max_mistake)  //generating text lesson
{
    int contor = 0;
    int current_position = 0;
    int word_count = 1;
    int letter;

    printf("Your current level: %d\n\n",level);

    //generate the text
    srand(time(0));
    while(contor < 49)
    {
        if(contor < 43)
        {

            //generationg length of the word--> between 3 to 5 letters
            int word_len = (rand() % 3) + 3; //random btw. 3-5

            //generating word
            for(int i = contor; i < (current_position + word_len) ; i++)
            {
                if(level == 0)
                {
                    letter = rand() % 8;  //generating letter from alphabet constant array (0..7)
                }
                if(level == 1)
                {
                    letter = rand() % 15;  //generating letter from alphabet constant array (0..14)
                }
                if(level == 2)
                {
                    letter = rand() % 22;  //generating letter from alphabet constant array (0..21)
                }
                if(level == 3)
                {
                    letter = rand() % 27;  //generating letter from alphabet constant array (0..26)
                }

                generator[i] = alphabet[letter];
                contor++; //contor count the number of caracters in the array generator
            }

            if(index_max_mistake > 0 && index_max_mistake < 26)
            {
                generator[contor] = alphabet[index_max_mistake]; //add most mistaken letter
                contor++;
            }

            generator[contor] = ' '; //adding space after word
            word_count++;
            contor++;
            current_position = contor; //update cursor position
        }
        if(contor >= 43 && contor < 51)
        {
            for(int i = contor; i < 50; i++)
            {
                if(level == 0)
                {
                    letter = rand() % 8;  //generating letter from alphabet constant array (0..7)
                }
                if(level == 1)
                {
                    letter = rand() % 15;  //generating letter from alphabet constant array (0..14)
                }
                if(level == 2)
                {
                    letter = rand() % 22;  //generating letter from alphabet constant array (0..21)
                }
                if(level == 3)
                {
                    letter = rand() % 26;  //generating letter from alphabet constant array (0..25)
                }
                generator[i] = alphabet[letter];
                contor++;
            }
        }
    }
    if(index_max_mistake > 0 && index_max_mistake < 26)
    {
        generator[49] = alphabet[index_max_mistake]; //add most mistaken letter at the end of last word
    }

    generator[50] = '\0';

    //display generator array
    for(int i = 0; i < 50; i++)
    {
        printf("%c",generator[i]);
    }
    return word_count;
}

void user_initial_output() //user output: ---------
{

    for(int i = 0; i < 50; i++)
    {

        printf("-");
    }
    //move cursor to begining of line
    for(int i = 0; i < 50; i++)
        {
            printf("\b");
        }
}

char user_input() //reads user letter input and return it
{
    return getch();
}
char menu()
{
    char r;
    printf("Menu:\n");
    printf("Start a new exercise?->y\n");
    printf("Quit->q\n");
    printf("Reset user progress and start from 0 ->r\n"); //delete the user history file - back to beginner
    scanf(" %c", &r);

    return r;
}

