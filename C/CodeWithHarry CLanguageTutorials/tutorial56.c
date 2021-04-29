/* 
CREATE ROCK PAPER SCISSORS GAME
Player1: Picks one say rock
Player2 (computer): Randomly picks say scissors --> player 1 gets 1 point
Runs 3 times.

rock vs scissors - rock wins
paper vs scissors - scissors win
paper vs rock - paper wins

Write a C program to play this game 3 times with computer
Log the scores of player and computer
Display the name of winner at the end
Notes : You have to display the name of player during the game.
Hence take input.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int n)
{
    /*
    generates random number based on time
    srand takes an input know as seed and is defined in stdlib.h
    time(NULL) returns time in seconds.
    */
    srand(time(NULL));
    return rand() % n;
}

int greater(char char1, char char2)
{ /*
    For rock paper scissors
    Returns 1 if  c1>c2 and 0 otherwise
    if c1 == c2 returns -1
    */
    if (char1 == char2)
    {
        return -1;
    }
    else if ((char1 == 'r') && (char2 == 's'))
    {
        return 1;
    }
    else if ((char2 == 'r') && (char1 == 's'))
    {
        return 0;
    }
    else if ((char1 == 'p') && (char2 == 'r'))
    {
        return 1;
    }
    else if ((char2 == 'p') && (char1 == 'r'))
    {
        return 0;
    }
    else if ((char1 == 's') && (char2 == 'p'))
    {
        return 1;
    }
    else if ((char2 == 's') && (char1 == 'p'))
    {
        return 0;
    }
}

int main()
{
    int playerScore = 0, compScore = 0, temp;
    char playerChar, compChar;
    char dict[] = {'r', 'p', 's'};

    printf("Welcome to the Rock, Paper , Scissiors.\n");
    for (int i = 0; i < 3; i++)
    {
        //Take player 1's input
        printf("Player 1's Turn:\n");
        printf("Choose 1 for Rock, 2 for Paper and 3 for Scissors\n");
        scanf("%d", &temp);
        getchar();
        playerChar = dict[temp - 1];
        printf("You chose %c\n\n", playerChar);

        // Generate computer's input
        printf("Computer's Turn:\n");
        printf("Choose 1 for Rock, 2 for Paper and 3 for Scissors\n");
        temp = generateRandomNumber(3) + 1;
        compChar = dict[temp - 1];
        printf("CPU chose %c\n\n", compChar);

        // Compare the scores
        if (greater(compChar, playerChar) == 1)
        {
            compScore += 1;
            printf("CPU got it!\n");
        }
        else if (greater(compChar, playerChar) == -1)
        {
            compScore += 1;
            playerScore += 1;
            printf("Its a draw!\n");
        }
        else
        {
            playerScore += 1;
            printf("You got it!\n");

        }
        printf("You: %d\nCPU: %d\n\n",playerScore,compScore);
    }

    if (playerScore > compScore) 
    {
        printf("You win the game\n");
    }
    else if (playerScore < compScore) 
    {
        printf("CPU wins the game\n");
    }
    else 
    {
        printf("Its a Draw\n");
    }

    return 0;
}
