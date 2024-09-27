#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "background.h"
#define MAX 7

int time();
void menu();
int addentry(int, int, float, float sumex[], float sumre[]);
float expenses(int,int);
float receivables(int, int);
void write_expenses(float record[],float totalex, int);
void write_receivables(float record[], float totalre, int);
void write_computation(float, float, float, float);
float computation(float,float,float);
void viewfile();
void back();

char monthname[20];
const char excat[7][100] = {"Building Maintenance","Utilities","Administrative Expenses","Equipment and Furniture","Groundskeeping and Landscaping","Technology Infrastructure","Other Expenses"};
const char recat[3][100] = {"CHED","Donations","Other Sources"};

int main()
{
    system ("color F0");
    bg();
    menu();
}

void menu()
{
    float budget;
    int choice, day, startingday = 0;
    day = time();
    float sumex[day],sumre[day];
    system("cls");
    bg();
    gotoxy(45,10);


    printf("Enter amount initial budget: ");
    scanf("%f", &budget);

    while(budget < 0){
            gotoxy(43,12);
            printf("%sInitial budget cannot be below 0%s", RED, NORMAL);
            getch();
            gotoxy(43,12);
            printf("                                     ");
            gotoxy(45,10);
            printf("Enter amount initial budget: ");
            gotoxy(73,10);
            printf("                         ");
            gotoxy(74,10);
            scanf("%f", &budget);
    };


    do
    {
        system("cls");
        bg();

        gotoxy(45,9);
        printf("MAIN MENU || Day: %i/%i", startingday+1,day);
        gotoxy(41,11);
        printf("Please enter the correct characters");
        gotoxy(47,14);
        printf("[1] Add Entry");
        gotoxy(47,16);
        printf("[2] View Entries");
        gotoxy(47,18);
        printf("[3] Exit");
        gotoxy(47,21);

        printf("Enter your choice: ");
        scanf("%i", &choice);


        switch(choice)
        {
            case 1: startingday = addentry(day, startingday, budget, sumex, sumre); break;
            case 2: viewfile(); getch(); break;
            case 3: system("cls"); printf("\n\t\t\t\t\t\tSee you next time %s%c%s\n\n\n",RED, 3, NORMAL); break;
            default: printf("\n\n\t\t\t\t\t      %sChose only from 0 to 4%s",RED, NORMAL); printf("\n\n\t\t\t\t             Press any key to continue..."); getch(); break;
        }
    }while(choice != 3);
}

void viewfile()
{
    system("cls");
    FILE *fOUT;
    char c;

    bg();
    fOUT = fopen(monthname, "r");
    printf("The content of the file is/are: \n");
    if(!fOUT)
    {
        printf("\n%s The file does not exist.%s \n",RED,NORMAL);
        printf("\nPress any key to continue...");
        getch();
        menu();
    }

    c = fgetc(fOUT);
    while(!feof(fOUT))
    {
        printf("%c", c);
        c = fgetc(fOUT);
    }

    fclose(fOUT);
}

int addentry(int limit, int startingday, float budget, float sumex[], float sumre[])
{
    system("cls");
    float totalex,totalre;
    char choice;

    for(int i = startingday; i < limit; i++)
    {
        system("cls");
        bg();
        gotoxy(55,8);
        printf("DAY %i", i + 1);
        sumex[i] = expenses(limit,i);
        sumre[i] = receivables(limit,i);

        gotoxy(30,27);
        printf("Would you like to proceed to the next day?");
        gotoxy(40,29);
        printf("[Y]es || [N]o");
        choice = getch();
        choice = toupper(choice);

        while(choice != 'Y' && choice != 'N')
        {
            gotoxy(30,27);
            printf("%sInvalid Choice. Please Try Again....Press [Y] or [N] only.%s",RED,NORMAL);
            choice = getch();
            choice = toupper(choice);
        }

        if(choice == 'N'){
            return i+1;
        }

    }

    for(int i = 0; i < limit; i++)
    {
        totalex = totalex + sumex[i];
        totalre = totalre + sumre[i];
    }

    computation(totalex,totalre, budget);

}

float receivables(int limit, int startingday)
{

    int i;
    float amountre[3],totalre;
    gotoxy(70,10);
    printf("RECEIVABLES");
    for(i = 0; i < 3; i++)
    {
        gotoxy(70, 12 + 2 * i);
        puts(recat[i]);
        gotoxy(70,13 + 2 * i);
        printf("Amount: ");
        gotoxy(79,13 + 2 * i);
        scanf("%f", &amountre[i]);


        while(amountre[i] < 0){
            gotoxy(30,27);
            printf("%sEntered amount is not valid...Press any key to continue.%s", RED, NORMAL);
            getch();
            gotoxy(30,27);
            printf("                                                       ");
            gotoxy(70,13 + 2 * i);
            printf("Amount: ");
            gotoxy(79,13 + 2 * i);
            printf("       ");
            gotoxy(79,13 + 2 * i);
            scanf("%f", &amountre[i]);
        }
    }

    totalre = amountre[0]+amountre[1]+amountre[2];
    write_receivables(amountre, totalre, startingday);
    return totalre;
}

float expenses(int limit, int startingday)
{

    int i;
    float amountex[7],totalex;
    gotoxy(20,10);
    printf("EXPENSES");
    for(i = 0; i < 7; i++)
    {

        gotoxy(20, 12 + 2 * i);
        puts(excat[i]);
        gotoxy(20,13 + 2 * i);
        printf("Amount: ");
        gotoxy(29,13 + 2 * i);
        scanf("%f", &amountex[i]);


        while(amountex[i] < 0){
            gotoxy(30,27);
            printf("%sEntered amount is not valid...Press any key to continue.%s", RED,NORMAL);
            getch();
            gotoxy(30,27);
            printf("                                                       ");
            gotoxy(20,13 + 2 * i);
            printf("Amount: ");
            gotoxy(29,13 + 2 * i);
            printf("       ");
            gotoxy(29,13 + 2 * i);
            scanf("%f", &amountex[i]);
        }
    }

    totalex = amountex[0] + amountex[1] + amountex[2] + amountex[3] + amountex[4] + amountex[5] + amountex[6];
    write_expenses(amountex,totalex,startingday);
    return totalex;
}

void write_expenses(float recordex[], float totalex, int startingday)
{
    FILE *fOUT;
    fOUT = fopen(monthname,"a");

    fprintf(fOUT,"\n\nDAY %i\n", startingday + 1);
    fprintf(fOUT,"\nExpenses\n\n");

    for(int i = 0; i < 7; i++)
    {
        fprintf(fOUT,"%s", excat[i]);
        fprintf(fOUT,"\nAmount: ");
        fprintf(fOUT,"P %.2f\n",recordex[i]);
    }

    fprintf(fOUT,"\nTOTAL EXPENSES FOR DAY %i: %.2f\n\n", startingday+1,totalex);
    fclose(fOUT);

    return;
}

void write_receivables(float recordre[], float totalre, int startingday)
{

    FILE *fOUT;
    fOUT = fopen(monthname,"a");

    fprintf(fOUT,"\nReceivables\n\n");

    for(int i = 0; i < 3; i++)
    {
        fprintf(fOUT,"%s", recat[i]);
        fprintf(fOUT,"\nAmount: ");
        fprintf(fOUT,"P %.2f\n",recordre[i]);
    }

    fprintf(fOUT, "\nTOTAL RECEIVABLES FOR DAY %i: P %.2f\n\n", startingday+1,totalre);
    for(int i = 0; i < 120; i++)
    {
        fprintf(fOUT,"%c",205);
    }
    fclose(fOUT);
    return;
}

void write_computation(float totalex, float totalre, float newbudget, float budget)
{

    FILE *fOUT;
    fOUT = fopen(monthname,"a");

    fprintf(fOUT,"\nTOTAL TRANSACTION FOR ");
    for (int i = 0; i < strlen(monthname)-4; i++)
    {
        fprintf(fOUT,"%c",monthname[i] = toupper(monthname[i]));
    }


        fprintf(fOUT,"\n\nINITIAL BUDGET: %.2f", budget);
        fprintf(fOUT,"\n\nSUM OF ALL EXPENSES: %.2f", totalex);
        fprintf(fOUT,"\nSUM OF ALL RECEIVABLES: %.2f", totalre);
        fprintf(fOUT,"\nNEW BALANCE: %.2f\n", newbudget);

    for(int i = 0; i < 120; i++)
    {
        fprintf(fOUT,"%c",205);
    }
    fclose(fOUT);
    return;
}

int time()
{
    system("cls");
    bg();
    int month;
    gotoxy(45,15);
    printf("[1]January");
    gotoxy(45,16);
    printf("[2]February");
    gotoxy(45,17);
    printf("[3]March");
    gotoxy(45,18);
    printf("[4]April");
    gotoxy(45,19);
    printf("[5]May");
    gotoxy(45,20);
    printf("[6]June");
    gotoxy(60,15);
    printf("[7]July");
    gotoxy(60,16);
    printf("[8]August");
    gotoxy(60,17);
    printf("[9]September");
    gotoxy(60,18);
    printf("[10]October");
    gotoxy(60,19);
    printf("[11]November");
    gotoxy(60,20);
    printf("[12]December");

    gotoxy(50,10);
    printf("Enter month: ");
    scanf("%i", &month);

    switch(month)
    {
        case 1: month = 30; strcpy(monthname, "January.txt"); break;
        case 2: month = 5; strcpy(monthname, "February.txt");break;
        case 3: month = 31; strcpy(monthname, "March.txt");break;
        case 4: month = 30; strcpy(monthname, "April.txt");break;
        case 5: month = 31; strcpy(monthname, "May.txt");break;
        case 6: month = 30; strcpy(monthname, "June.txt");break;
        case 7: month = 31; strcpy(monthname, "July.txt");break;
        case 8: month = 31; strcpy(monthname, "August.txt");break;
        case 9: month = 30; strcpy(monthname, "September.txt");break;
        case 10: month = 31; strcpy(monthname, "October.txt");break;
        case 11: month = 30; strcpy(monthname, "November.txt");break;
        case 12: month = 31; strcpy(monthname, "December.txt");break;
        default: gotoxy(49,12); printf("%sPlease enter month%s",RED, NORMAL); getch(); time(); break;
    }


    return month;

}

float computation(float totalex,float totalre,float budget)
{
    float newbudget;

    newbudget = (totalre + budget) - totalex;
    write_computation(totalex, totalre, newbudget, budget);
}
