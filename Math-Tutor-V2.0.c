#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#define AC_RED "\x1b[31m"
#define AC_GREEN "\x1b[32m"
#define AC_NORMAL "\x1b[30m"

int Menu();
int Returnmenu();
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
    printf("\n\n\n\n\t\t\t\t\t       Loading.... Please wait\n");
    printf("\n\t\t\t\t   ");

    for(int i = 1; i <= 50; i++)
    {
        printf("%s%c%s", AC_GREEN, 176, AC_NORMAL);
    }

    printf("\r");
    printf("\t\t\t\t   ");

    for(int i = 1; i <= 50; i++)
    {
        Sleep(20);
        printf("%s%c%s", AC_GREEN, 219, AC_NORMAL);
    }

    printf("\n\n\t\t\t\t\t    Successfully Loaded. Welcome!");
}

void loading2() //loading screen
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\tLoading");
    for(int i =0; i<= 7; i++)
    {
        Sleep(200);
        printf(".");
    }
}

int main()
{
    system("COLOR F0");
    loading(); //Loading Screen function
    delay(1000);
    Menu();
}

int Menu()
{
    int menu;
    do{
        system("cls");
        printf ("\n\t\t\t\t\t    MATH TUTOR V2.0\n");
        //change menu interface
        printf ("\n\n\t\t\t\t\t  Press [1] Addition");
        printf ("\n\t\t\t\t\t  Press [2] Subtraction");
        printf ("\n\t\t\t\t\t  Press [3] Multiplication");
        printf ("\n\t\t\t\t\t  Press [4] Division");
        printf ("\n\t\t\t\t\t  Press [5] Exit");
        printf("\n\n\t\t\t\t\t  Enter your choice: ");
        scanf("%i", &menu);

        switch(menu)
        {
            case 1: Addition(); break;
            case 2: Subtraction(); break;
            case 3: Multiplication(); break;
            case 4: Division(); break;
            case 5: printf ("\n\nThank you for using Math Tutor v1.0 %c\n\n", 3); break;
            default: printf("\n\n%sError. Please enter a valid input.%s\n", AC_RED, AC_NORMAL); system("pause");Menu();

        }
    }while(menu != 5);
return 0;
}


int Returnmenu()//To improve efficiency I separated this code so I can just call this when needed
{
        system("COLOR F0");
        char again;

        printf ("\n\n\t\t\t   Back to Main Menu? [Press Y if Yes and N if No]: \n\n");
        again = getch();
        if (again == 'y' || again == 'Y')
        {
           loading2();
           Menu();
        }
        else if (again == 'n' || again == 'N')
        {
           printf ("\n\nThank you for trying this program. \n\n"); return 0;//loop ends
        }
        else
        {
            system("COLOR 40");
            printf("\n\t\t\t   Invalid input. Please try again.\n\n\n");
            printf("\n%cOK", 16);
            getch();
            Returnmenu();
        }

}


int Addition()
{
    char again;
    do
    {
        int i = 0, max, num1, num2, result[100], answer[100], score = 0;
        srand(time(NULL));

        loading2();
        system ("cls");
        printf("\n\n\t\tADDITION\n\n");
        printf("\n   Please input a number that corresponds to how many addition problem/s you want: (1-100 only) ");
        scanf("%i", &max);

        for(i = 0; i< max; i++)
            {
                num1 = rand()%50;
                num2 = rand()%50;
                result[i] = num1 + num2; // Sum of num1 and num2.
                printf("\n   %i + %i = ?: ", num1, num2); //Display the random number to the user.
                scanf("%i",&answer[i]); // get the answer from the user.
            }

        printf("\n\n___________________________________________________________");

        for(i = 0; i< max; i++)
        {
            if(result[i] == answer[i]) //compare result to the user's answer.
            {
                printf("   \n\nCorrect!\n\n");
                score = score + 1; // Count and sum the total correct answer/s.
            }
            else
            {
                printf("   \n\nWrong! the correct answer is %i\n\n", result[i]); // Display the correct answer.
            }

            printf("  Total score: %i/%i", score, max);
        }
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
    char again;
    do
    {
        int i = 0, max, num1, num2, result[100], answer[100], score = 0;
        srand(time(NULL));
        loading2();
        system("cls");
        printf("\n\n\t\tSUBTRACTION\n\n");
        printf("\n   Please input a number that corresponds to how many subtraction problem/s you want: (1-100 only) ");
        scanf("%i", &max);

        for(i = 0; i< max; i++)
        {
            num1 = rand()%50;
            num2 = rand()%50;

            if (num1 < num2)//Condition for displaying the random numbers.
            {
               result[i] = num2 - num1;
               printf("\n   %i - %i = ?: ", num2, num1); //Display the random number to the user.
            }
            else
            {
               result[i] = num1 - num2; //Result of num1 and num2.
               printf("\n   %i - %i = ?: ", num1, num2); //Display the random number to the user.
            }

            scanf("%i", &answer[i]); //Obtain the answer from user.
        }

        printf("\n\n___________________________________________________________");

        for(i = 0; i< max; i++)
        {
             if(result[i] == answer[i]) //compare result to the user's answer.
            {
                printf("   \n\nCorrect!\n\n");
                score = score + 1; // Count and sum the total correct answer/s.
            }
            else
            {
                printf("   \n\nWrong! the correct answer is %i\n\n", result[i]); // Display the correct answer.
            }
            printf("  Total score: %i/%i", score, max);
        }
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
    char again;
    do
    {
        int i = 0, max, num1, num2, result[100], answer[100], score = 0;
        srand(time(NULL));
        loading2();
        system("cls");
        printf("\n\n\t\tMULTIPLICATION\n\n");
        printf("\n   Please input a number that corresponds to how many multiplication problem/s you want: (1-100 only) ");
        scanf("%i", &max);
        for(i = 0; i< max; i++)
            {
                num1 = rand()%15;
                num2 = rand()%15;
                result[i] = num1 * num2; //Result of num1 and num2.
                printf("\n   %i * %i = ?: ", num1, num2); //Display the random number to the user.
                scanf("%i",&answer[i]); // get the answer from the user.


            }

        printf("\n\n___________________________________________________________");

        for(i = 0; i< max; i++)
        {
           if(result[i] == answer[i]) //compare result to the user's answer.
                {
                    printf("   \n\nCorrect!\n\n");
                    score = score + 1; // Count and sum the total correct answer/s.
                }
            else
                {
                    printf("   \n\nWrong! the correct answer is %i\n\n", result[i]); // Display the correct answer.
                }
            printf("  Total score: %i/%i", score, max);
        }
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
    char again;
    do
    {
        int i = 0, p, max, num1, num2, answer[100], score = 0;
        float result[100];
        srand(time(NULL));
        loading2();
        system("cls");
        printf("\n\n\t\tDIVISION\n\n");
        printf("\n   Please input a number that corresponds to how many division problem/s you want: (1-100 only) ");
        scanf("%i", &max);

        for(i = 0; i< max; i++)
            {
                num1 = rand()%10;
                num2 = rand()%10;
                result[i] = num1 / num2;

                if(num2 > num1)
                {
                    p= num1 * num2;
                    result[i] = p / num2;
                    printf("\n   %i / %i = ?: ", p, num2); //Display the random number to the user.
                }
                else if (getchar()!='.')//if the result of the randomized number is decimal.
                {
                    p= num1 * num2;
                    result[i] = p / num2;
                    printf("\n   %i / %i = ?: ", p, num2); //Display the random number to the user.
                }
                else if (num2 == 0)
                {
                    printf("\n   Cannot be divided by 0");
                }
                else
                {
                    result[i] = num1 / num2; //Result of num1 and num2.
                    printf("\n   %i / %i = ?: ", num1, num2); //Display the random number to the user.
                }
                scanf("%i",&answer[i]); // get the answer from the user.
            }

            printf("\n\n___________________________________________________________");

        for(i = 0; i< max; i++)
            {
                if(result[i] == answer[i]) //compare result to the user's answer.
                    {
                        printf("   \n\nCorrect!\n\n");
                        score = score + 1; // Count and sum the total correct answer/s.
                    }
                else if (result[i] != answer[i])
                    {
                        printf("   \n\nWrong! the correct answer is %.f\n\n", result[i]); // Display the correct answer.
                    }
                printf("  Total score: %i/%i", score, max);
            }
        printf("\n\t\t\t   Do you want to try again? [Press Y if Yes and N if No]: ");
        again = getch();

    }while (again == 'y' || again == 'Y');//loop inside chosen program

    if (again == 'n' || again == 'N')
    {
        Returnmenu();
    }
    return 0;
}


