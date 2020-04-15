#include "prototype_functions.h"  //include libraries, prototype functions and global variables

int main()
{
    char generator_text[51]; //generate the exercise text
    int mistake_count[27]; //count the mistakes of each letter
    int index_max_mistakes = -1; //index in alphabet to point the letter mostly mistaken
    int time_type,speed_cpm,speed_wpm;  //time to finish the exercise
    int words; //numbers of words generated per exercise
    int performance; //percentage of mistakes made in current exercise
    char user_file_name[30] = "user_performance.txt";
    int user_level;
    int previous_exercises[2][NR_OF_EXERCISES]; //information about performance and level of the user
    int performance_sum = 0; //check if the user has upgraded to next level after he played
    char user_choice;


    do
    {
        //menu loop TODO
        user_choice = menu();

        if(user_choice == 'r')
        {
            reset_user_level(user_file_name);
            user_choice = menu();
        }
        if(user_choice == 'q')
        {
            return 0;
        }


        //read from file and fill the matrix previous_exercises with last 5 exercises made by user
        read_file_fill_matrix(user_file_name,previous_exercises);

        //debug printf matrix
        /*for(int i = 0; i < NR_OF_EXERCISES; i++)
        {
            printf("%d %d",previous_exercises[0][i],previous_exercises[1][i]);
            printf("\n");
        }*/


        //check the level if it must be increased or not
        user_level = decision_upgrade_level(previous_exercises);

        //generate text based on current level
        words = generating_array(generator_text,user_level,index_max_mistakes); //will contain the generated text and we count the number of words generated
        printf("\n");
        user_initial_output(); // output ------------

        //user play and start time type counting
        time_type = count_mistakes(generator_text,mistake_count); //count for each letter the number of mistakes and the typing time
        printf("\n");
        index_max_mistakes = index_maxim_mistakes(mistake_count); //index of the letter with maximum mistakes

        //display the character with the maximum errors-->this character will be generated next time the most in the generator text[]
        if(index_max_mistakes > 0)
        {
            if(alphabet[index_max_mistakes] != ' ')
            {
                printf("The most mistaken character is: %c\n", alphabet[index_max_mistakes]);
            }
            else
            {
                printf("The most mistaken character is: _\n");
            }
        }
        else
        {
            printf("No mistakes were made. Congratulation!");
        }

        //calculate the user performance
        speed_cpm = 50*60/time_type;
        speed_wpm = words*60/time_type;
        performance = 100 - (total_mistakes(mistake_count)/50.0*100);

        //display the performance of the current exercise
        printf("Typing speed: CPM = %d   WPM = %d\n",speed_cpm,speed_wpm);
        printf("Accuracy: %d %%\n",performance);

        //include in matrix on the last position the current performance of the user

        //shift rows upward
        for(int i =0; i < NR_OF_EXERCISES-1; i++)
            {
                previous_exercises[0][i] = previous_exercises[0][i+1];
                previous_exercises[1][i] = previous_exercises[1][i+1];
            }
        //insert current performance on the last row in matrix
        previous_exercises[0][NR_OF_EXERCISES-1] = performance;
        previous_exercises[1][NR_OF_EXERCISES-1] = user_level;


        //verify status level after the user has played
        //(the level will be increased only in the next loop ->this check is only to inform the user if he has upgraded to next level
        if(previous_exercises[1][0] == previous_exercises[1][1] && previous_exercises[1][1] == previous_exercises[1][2] && previous_exercises[1][2] == previous_exercises[1][3] && previous_exercises[1][3] == previous_exercises[1][4])
        {
            for(int i = 0; i < NR_OF_EXERCISES; i++)
            {
                performance_sum += previous_exercises[0][i];
            }
        }
        if(performance_sum/NR_OF_EXERCISES >= 98 && user_level < 3)
        {
            //just let the user know that he was upgraded, actually the level will be increased in the beginning of next loop
            printf("You have been upgraded to the next level --> %d. Congratulations!\n", user_level+1);
        }
        performance_sum = 0; //reset to 0


        //update performance file
        update_performance_file(speed_cpm,speed_wpm,performance,user_level,user_file_name);

    }while(user_choice != 'q');

    return 0;
}


