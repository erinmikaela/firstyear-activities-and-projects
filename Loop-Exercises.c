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
int Problem1();
int Problem2();
int Problem3();
int Problem4();
int Problem5();

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
    system("cls");
    printf("\n\t\t\t\t\t      LOOPING EXERCISES");
    //change menu interface
    printf("\n\n\t\t\t\t\t  1 %c Greatest Common Divisor", 16);
    printf("\n\t\t\t\t\t  2 %c Fibonacci Sequence", 16);
    printf("\n\t\t\t\t\t  3 %c Even Squares", 16);
    printf("\n\t\t\t\t\t  4 %c Counting the Largest Integer", 16);
    printf("\n\t\t\t\t\t  5 %c Leap Year", 16);
    printf("\n\t\t\t\t\t  6 %c Exit", 16);
    printf("\n\n\t\t\t\t\t  Enter your choice: ");
    scanf("%i", &menu);

    if (menu == 1)//Greatest Common Diviso
        {
            loading2();
            Problem1();
        }
    else if (menu == 2)//Fibonacci Sequence
        {
            loading2();
            Problem2();
        }
    else if (menu == 3)//Even Squares
        {
            loading2();
            Problem3();
        }
    else if (menu == 4)//Counting the Largest Integer
        {
            loading2();
            Problem4();
        }
    else if (menu == 5)//Leap Year
        {
            loading2();
            Problem5();
        }
    else if (menu == 6)//Exit
        {
            printf ("\n\nThank you for trying this program.");//loop ends
            return 0;
        }
    else
        {
            printf("\n\n%sError. Please enter a valid input.%s\n", AC_RED, AC_NORMAL);
            return 0;
        }
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
           printf ("\n\nThank you for trying this program. \n\n");//loop ends
        }
        else
        {
            system("COLOR 40");
            printf("\n\t\t\t   Invalid input. Please try again.\n\n\n");
            printf("\n%cOK", 16);
            getch();
            Returnmenu();
        }
        return 0;
}


int Problem1()
{
    char again, notint;
    do
    {
        system("cls");//clear screen
        printf("\n\n\t\tIdentifying the GCD of Two Numbers\n\n");
        int num1, num2, result;
        printf("Enter-two whole numbers: \n");
        scanf("%d %d", &num1, &num2);//obtaining two integer input
        scanf("%c", &notint);//scans for invalid inputs

        while (num2 > 0)
            {
                result = num1 % num2;
                num1 = num2;
                num2 = result;
            }

        if(num1 == 0 && num2 == 0)//nested if else that prevents invalid inputs
        {
            system("COLOR 40");
            printf("\nUnidentified\n\n");
            return 0;
        }
        else if(num1 < 0 || num2 < 0)
        {
            system("COLOR 40");
            printf("\nInvalid input. Enter whole numbers only.\n\n");
            return 0;
        }
        else if(notint == '.' || notint == '/')
        {
            system("COLOR 40");
            printf("\nInvalid input. Enter whole numbers only.\n\n");
            return 0;
        }

    printf ("\nGCD = %d \n\n", num1);
    printf("\n\t\t\t   Do you want to try again? [Press Y if Yes and N if No]: ");
    again = getch();
    }while(again == 'y' || again == 'Y');//loop

    if (again == 'n' || again == 'N')
    {
        Returnmenu();
    }
    return 0;
}


int Problem2()
{
    char again, notint;
    do
    {
        system("cls");//clear screen
        int term1 = 0, term2 = 1, nextTerm = 0, x;//the first two terms are always 0 and 1
        printf("\n\n\t\tFibonacci Sequence\n\n");
        printf("Input Number: \n");
        scanf("%d", &x);
        scanf("%c", &notint);//scans for invalid inputs
        nextTerm = term1 + term2;

        if(x < 0)//nested if else that prevents invalid inputs
        {
            system("COLOR 40");
            printf("\nInvalid input. Enter postive whole numbers only.\n\n");
            return 0;
        }
        else if(x == 0)
        {
            system("COLOR 40");
            printf("\nInvalid input. Enter postive whole numbers only.\n\n");
            return 0;
        }
        else if(notint == '.' || notint == '/')
        {
            system("COLOR 40");
            printf("\nInvalid input. Enter whole numbers only.\n\n");
            return 0;
        }
        printf("\nFibonacci Sequence: %d, %d, ", term1, term2);

        while (nextTerm <= x)
            {
                printf("%d, ", nextTerm);
                term1 = term2;
                term2 = nextTerm;
                nextTerm = term1 + term2;
            }

    printf("\n\n\n\t\t\t   Do you want to try again? [Press Y if Yes and N if No]: ");
    again = getch();
    }while(again == 'y' || again == 'Y');//loop

    if (again == 'n' || again == 'N')
    {
        Returnmenu();
    }
    return 0;
}

int Problem3()
{
    char again, notint;
    do
    {
        system("COLOR F0");//resets bg back to normal when looping
        system("cls");//clear screen
        int a, x;
        printf("\n\n\t\tGenerating Even Squares\n\n");
        printf("Input a maximum square: ");
        scanf("%i", &x);
        scanf("%c", &notint);

        if(x <= 0)//nested if else that prevents invalid inputs
        {
            system("COLOR 40");
            printf("\nInvalid input. Enter positive integers only.\n\n");
        }
        else if(notint == '.' || notint == '/')
        {
            system("COLOR 40");
            printf("\nInvalid input. Enter positive integers only.\n\n");
            return 0;
        }

        for(a=2; a * a <= x; a += 2)
        {
            printf("\n%d", a*a);
        }

    printf("\n\n\n\t\t\t   Do you want to try again? [Press Y if Yes and N if No]: ");
    again = getch();
    }while(again == 'y' || again == 'Y');//loop

    if (again == 'n' || again == 'N')
    {
        Returnmenu();
    }
    return 0;
}


int Problem4()
{
    char again;
    do
    {
        system("cls");//clear screen
        int qty, i, largest, occr = 0;
        printf("\n\n\t\tIdentifying and Counting the Largest Integer\n\n");
        printf("Specify the quantity of integers: ");
        scanf("%d", &qty);
        int arr[qty];
        printf("\nEnter the %d elements: \n", qty);
        i = 0;

        while (i < qty)//it will continue to scan for input/s based on the given quantity of user
            {
                scanf("%d", &arr[i]);
                i++;
            }

        largest = arr[0];

        for (i = 1; i < qty; i++)
            {
                if (largest < arr[i])
                largest = arr[i];
            }

        i = 0;
        while (i < qty)
            {
                if (arr[i] == largest)
                {
                    occr++;
                }
                i++;
            }

    printf("\nThe largest value in the given integers is %d and it appeared %d time/s\n\n", largest, occr);
    printf("\n\t\t\t   Do you want to try again? [Press Y if Yes and N if No]: ");
    again = getch();
    }while(again == 'y' || again == 'Y');//loop

    if (again == 'n' || again == 'N')
    {
        Returnmenu();
    }
    return 0;
}

int Problem5()
{
   char again;
   do
   {
       system("cls");
       int year;
       printf("\n\n\tDetermining a Leap Year\n\n");
       printf("Enter a year: ");
       scanf("%d", &year);

       // leap year if perfectly divisible by 400
       if (year % 400 == 0)
       {
            printf("\n%d is a leap year.", year);
       }
       // not a leap year if divisible by 100
       // but not divisible by 400
       else if (year % 100 == 0)
        {
            printf("\n%d is not a leap year.", year);
        }
        // leap year if not divisible by 100
        // but divisible by 4
        else if (year % 4 == 0)
        {
            printf("\n%d is a leap year.", year);
        }
        // all other years are not leap years
        else
        {
            printf("\n%d is not a leap year.", year);
        }

    printf("\n\n\n\t\t\t   Do you want to try again? [Press Y if Yes and N if No]: ");
    again = getch();
   }while(again == 'y' || again == 'Y');

    if (again == 'n' || again == 'N')
    {
        Returnmenu();
    }
    return 0;
}
