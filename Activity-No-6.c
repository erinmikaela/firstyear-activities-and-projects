#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<string.h>
#include <conio.h>
#include <windows.h>

int Menu();
int Addition();
int Subtraction();
int Multiplication();
int Division();

void delay(unsigned int secs)//system delay
{
    clock_t interval = clock() + secs;
    while(interval > clock());
}

void loading() //loading screen
{
    system("cls");
    printf("\n\n\n\n");
    printf("\n\n\t\t\t\t\t    Loading.... Please wait\n\n");
    for(int i =1; i<= 120; i++)
    {
        Sleep(5);
        printf("%c", 219); //Displayed character during the loading.
    }
    printf("\n\n\t\t\t\t\t Successfully Loaded. Welcome!");
}

void loading2() //loading screen
{
    int i, j, a;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\tLoading");
    for(int i =0; i<= 7; i++)
    {
        for (j=0; j<100000000; j++)
            a = j;
        printf(".");
    }
}

int main() //main function
{
    loading(); //Loading Screen function
    delay(2000);
    Menu(); //Main Menu function
}

int Menu()
{
        int menu;
        system("cls");
        printf ("\n\t\t\t\t\t    MATH TUTOR V1.0\n");
        printf ("\n\t\t\t\t\t     %c MAIN MENU %c", 16, 17);
        printf ("\n\n\t\t\t\t\t  Press [1] Addition");
        printf ("\n\t\t\t\t\t  Press [2] Subtraction");
        printf ("\n\t\t\t\t\t  Press [3] Multiplication");
        printf ("\n\t\t\t\t\t  Press [4] Division");
        printf ("\n\t\t\t\t\t  Press [5] Exit");
        printf ("\n\n\t\t\t\t\t  Enter your choice: ");
        scanf ("%i", &menu);

        if (menu == 1) //Addition
        {
            Addition();
        }
        else if (menu == 2) //Subtraction
        {
            Subtraction();
        }
        else if (menu == 3) //Multiplication
        {
            Multiplication();
        }
        else if (menu == 4) //Division
        {
            Division();
        }
        else if (menu == 5)//Exit
        {
            printf ("\n\nThank you for using Math Tutor v1.0 %c\n\n", 3);//loop ends
            return 0;
        }
        else
        {
            printf("\n\nError. Please enter a valid input.");
            printf("\n%cOK", 16);
            getch();
            Menu();
        }
        return 0;
}

int Returnmenu()//To improve efficiency I separated this code so I can just call this when needed
{
        char again;

        printf ("\n\n\t\t\t   Back to Main Menu? [Press Y if Yes and N if No]: \n\n");
        again = getch();
        if (again == 'y' || again == 'Y')
        {
           Menu();
        }
        else if (again == 'n' || again == 'N')
        {
           printf ("\n\t\t\t   Thank you for using Math Tutor v1.0 %c\n\n\n", 3);//loop ends
        }
        else
        {
            printf("\n\t\t\t   Error. Please try again.\n\n\n");
            printf("\n%cOK", 16);
            getch();
            Returnmenu();
        }
        return 0;
}

int Addition()
{
        int a, max, num1, num2, result, answer, score = 0;
        srand(time(NULL));
        char again;
    do
    {
        loading2();
        system ("cls");
        printf("\n\n\t\tADDITION\n\n");
        printf("\n   Please input a number that corresponds to how many addition problem/s you want: ");
        scanf("%i", &max);

        for(a = 1; a<= max; a++)
            {
                num1 = rand()%50;
                num2 = rand()%50;
                result = num1 + num2; // Sum of num1 and num2.
                printf("\n   %i + %i = ?: ", num1, num2); //Display the random number to the user.
                scanf("%i",&answer); // get the answer from the user.
                if(result == answer) //compare result to the user's answer.
                {
                    printf("   Correct!\n\n");
                    score = score + 1; // Count and sum the total correct answer/s.
                }
                else
                {
                    printf("   Wrong! the correct answer is %i\n\n", result); // Display the correct answer.
                }
            }
        printf("  Your score is %i/%i", score, max);
        printf("\n\t\t\t   Do you want to try again? [Press Y if Yes and N if No]: ");
        again = getch();

    }while (again == 'y' || again == 'Y');//loop inside chosen program

    if (again == 'n' || again == 'N')
    {
        Returnmenu();
    }
    return 0;
}




int Subtraction()
{
    int a, max, num1, num2, result, answer, score = 0;
    srand(time(NULL));
    char again;
    do
    {
        loading2();
        system("cls");
        printf("\n\n\t\tSUBTRACTION\n\n");
        printf("\n   Please input a number that corresponds to how many subtraction problem/s you want: ");
        scanf("%i", &max);
        for(a = 1; a<= max; a++)
        {
            num1 = rand()%50;
            num2 = rand()%50;

            if (num1 < num2)//Condition for displaying the random numbers.
            {
               result = num2 - num1;
               printf("\n   %i - %i = ?: ", num2, num1); //Display the random number to the user.
            }
            else
            {
               result = num1 - num2; //Result of num1 and num2.
               printf("\n   %i - %i = ?: ", num1, num2); //Display the random number to the user.
            }

            scanf("%i",&answer); //Obtain the answer from user.

        if(result == answer) //compare result to the user's answer.
        {
            printf("   Correct!\n\n");
            score = score + 1; // Count and sum the total correct answer/s.
        }
        else
        {
            printf("   Wrong! the correct answer is %i\n\n", result); // Display the correct answer.
        }
        }
    printf("  Your score is %i/%i\n", score, max);
    printf("\n\t\t\t   Do you want to try again? [Press Y if Yes and N if No]: ");
    again = getch();

    }while (again == 'y' || again == 'Y');//loop inside chosen program

    if (again == 'n' || again == 'N')
    {
        Returnmenu();
    }
    return 0;
}

int Multiplication()
{
    int a, max, num1, num2, result, answer, score = 0;
    srand(time(NULL));
    char again;
    do
    {

        loading2();
        system("cls");
        printf("\n\n\t\tMULTIPLICATION\n\n");
        printf("\n   Please input a number that corresponds to how many multiplication problem/s you want: ");
        scanf("%i", &max);
        for(a = 1; a<= max; a++)
            {
                num1 = rand()%15;
                num2 = rand()%15;
                result = num1 * num2; //Result of num1 and num2.
                printf("\n   %i * %i = ?: ", num1, num2); //Display the random number to the user.
                scanf("%i",&answer); // get the answer from the user.

                if(result == answer) //compare result to the user's answer.
                    {
                        printf("   Correct!\n\n");
                        score = score + 1; // Count and sum the total correct answer/s.
                    }
                else
                    {
                        printf("   Wrong! the correct answer is %i\n\n", result); // Display the correct answer.
                    }
            }
        printf("  Your score is %i/%i", score, max);
        printf("\n\t\t\t   Do you want to try again? [Press Y if Yes and N if No]: ");
        again = getch();

    }while (again == 'y' || again == 'Y');//loop inside chosen program

    if (again == 'n' || again == 'N')
    {
        Returnmenu();
    }
    return 0;
}


int Division()
{
    int a, p, max, num1, num2, answer, score = 0;
    float result;
    srand(time(NULL));
    char again;
    do
    {
        loading2();
        system("cls");
        printf("\n\n\t\tDIVISION\n\n");
        printf("\n   Please input a number that corresponds to how many division problem/s you want: ");
        scanf("%i", &max);
        for(a = 1; a<= max; a++)
            {
                num1 = rand()%10;
                num2 = rand()%10;
                result = num1 / num2;

                if(num2 > num1)
                {
                    p= num1 * num2;
                    result = p / num2;
                    printf("\n   %i / %i = ?: ", p, num2); //Display the random number to the user.
                }
                else if (getchar()!='.')//if the result of the randomized number is decimal.
                {
                    p= num1 * num2;
                    result = p / num2;
                    printf("\n   %i / %i = ?: ", p, num2); //Display the random number to the user.
                }
                else if (num2 == 0)
                {
                    printf("\n   Cannot be divided by 0");
                }
                else
                {
                    result = num1 / num2; //Result of num1 and num2.
                    printf("\n   %i / %i = ?: ", num1, num2); //Display the random number to the user.
                }
                scanf("%i",&answer); // get the answer from the user.

                if(result == answer) //compare result to the user's answer.
                    {
                        printf("   Correct!\n\n");
                        score = score + 1; // Count and sum the total correct answer/s.
                    }
                else if (result != answer)
                    {
                        printf("   Wrong! the correct answer is %.f\n\n", result); // Display the correct answer.
                    }
            }
        printf("  Your score is %i/%i", score, max);
        printf("\n\t\t\t   Do you want to try again? [Press Y if Yes and N if No]: ");
        again = getch();

    }while (again == 'y' || again == 'Y');//loop inside chosen program

    if (again == 'n' || again == 'N')
    {
        Returnmenu();
    }
    return 0;
}


