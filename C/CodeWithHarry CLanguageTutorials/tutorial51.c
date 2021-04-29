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

int outcome(int a, int b)
{
    //Returns the outcome of the round
    if (a == b)
        return 0;
    else if (a == 1 && b == 3)
        return 1;
    else if (a == 2 && b == 1)
        return 1;
    else if (a == 3 && b == 2)
        return 1;
    else
    {
        return -1;
    }
}

void printChoice(int m)
{
    //Prints the choice picked
    switch (m)
    {
    case 1:
        printf("Picked Rock\n");
        break;
    case 2:
        printf("Picked Paper\n");
        break;
    case 3:
        printf("Picked Scissor\n");
        break;
    default:
        printf("Entered Wrong Choice\n");
    }
}

int main()
{

    //printf("The random no b/w 0 to 5 is %d\n", generateRandomNumber(5));

    char name[20];
    printf("Enter Your Name:\n");
    gets(name);
    printf("Welcome %s to Rock Paper Scissors!\n", name);
    printf("Let's begin the game.\n\n", name);

    //char *choice;
    //choice = (char *)malloc(9 * sizeof(char));

    int n, c, player = 0, comp = 0;
    int i = 0;
    while (i < 3)
    {
        printf("Round %d\n", i + 1);
        printf("%s's turn\n", name);
        printf("1 - Rock, 2 - Paper, 3- Scissors\n");
        scanf("%d", &n);
        //getchar();

        printf("You ");
        printChoice(n); //print players choice

        c = generateRandomNumber(3);

        printf("Computer ");
        printChoice(c + 1); //print computers choice

        switch (outcome(n, c + 1))
        {
        //Prints who won the round based on outcome
        case 1:
            printf("You Won\n");
            player++;
            break;
        case 0:
            printf("Draw\n");
            break;
        case -1:
            printf("Computer Won\n");
            comp++;
            break;
        default:
            printf("Invalid Outcome\n");
        }
        printf("\n");
        i++;
    }

    printf("\n\nFINAL RESULT\n");
    if (player > comp)
        printf("%s Won The Game\n", name);
    else if (comp > player)
        printf("Computer Won The Game\n");
    else
    {
        printf("It's a Draw\n");
    }
    //free(choice);

    return 0;
}