#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#define AC_RED "\x1b[31m"
#define AC_GREEN "\x1b[32m"
#define AC_NORMAL "\x1b[30m"
#define Max 3

void Menu();
void classSize();
void getRecord();
void displayRec();
void delStudRec();//file handling
void editStudRec();
float average(int a, int b, int c);
float rate(float ave);

struct student
{
    char fname[Max][20], lname[Max][20];
    int q1[Max];
    int q2[Max];
    int q3[Max];
    int stud_num[Max];
    float ave[Max];
    float rating[Max];
};

FILE *fp, *fp1;
struct student record;
int i, arrClass[Max];

int main ()
{
    system("COLOR F0");
    int menu;
    do
    {
         system("cls");
         printf ("\n\t\t\t\t\t    Student Record");
         printf ("\n\n\t\t\t\t   [C]reate Class Size");
         printf ("\n\t\t\t\t   [I]nput Student Name and Grades");
         printf ("\n\t\t\t\t   [V]iew Student Record");
         printf ("\n\t\t\t\t   [D]elete Student Record");
         printf ("\n\t\t\t\t   [M]odify Student Record");
         printf ("\n\t\t\t\t   [E]xit program ");
         menu = toupper(getch());

         switch(menu)
         {
            case 'C': /*loading2();*/ classSize(); break;
            case 'I': /*loading2();*/ getRecord(); break;
            case 'V': /*loading2();*/ displayRec(); break;
            case 'D': /*loading2();*/ delStudRec(); break;
            case 'M': /*loading2();*/ editStudRec(); break;
            case 'E': printf ("\n\nThank you for using the program %s%c%s\n\n", AC_RED, 3, AC_NORMAL); break;
            default: printf("\n\n%sError. Please enter a valid input.%s\n", AC_RED, AC_NORMAL); getch();
        }
    }while(menu != 'E');
}

void delStudRec()
{
    char name[20];
    displayRec();
    printf("\n\n\t\t\t\t\tDelete Student Record");
    printf("\n\t\t\tEnter student surname: ");
    fflush(stdin);
    gets(name);

    fp = fopen("student_record.txt", "rb+");
    if(fp == NULL)
    {
    printf("\n\n%sCannot open file or file does not exist.%s\n", AC_RED, AC_NORMAL); getch();
    exit(1);
    }
    fp1 = fopen("temp.txt", "wb+");
    if(fp1 == NULL)
    {
    printf("\n\n%sCannot open file or file does not exist.%s\n", AC_RED, AC_NORMAL); getch();
    exit(1);
    }

    while(fread(&record,sizeof(struct student),1,fp)==1)
    {
        if(strcmp(name,record.lname[i])!=0)
        {
            fwrite(&record,sizeof(struct student),1,fp1);
            remove("student_record.txt");
            rename("temp.txt","student_record.txt");
            printf("\n\t\t\t%sRecord deleted successfully.%s\n", AC_GREEN, AC_NORMAL);
        }
    }
    fclose(fp);
    fclose(fp1);



    system("pause");
}

void editStudRec()
{
    int choice, editRecord;
    displayRec();
    printf("\n\n\t\t\t\t\tEdit Student Name and Grades");
    printf("\n\t\t\tEnter student number: ");
    scanf("%i", &choice);

    if(choice < 1 || choice > Max)
    {
        printf("\n\t\t\t\t%sInvalid input. Student does not exist.%s", AC_RED, AC_NORMAL);
        editStudRec();
    }
    else
    {
        displayRec();
        printf("\n\t\t\tEdit Mode: 1%c Name 2%c Quiz 1 3%c Quiz 2 4%c Quiz 3\n", 16, 16, 16, 16);
        scanf("%i", &editRecord);
        fp = fopen("student_record.txt", "w");

        switch(editRecord)
        {
        case 1:
            displayRec();
            printf("\n\t\t\tEnter New First Name: ");
            scanf("%s", record.fname[choice]);
            printf("\n\t\t\tEnter New Last Name: ");
            scanf("%s", record.lname[choice]);
            printf("\n\t\t\t%sEntered successfully.%s\n", AC_GREEN, AC_NORMAL);
            system("pause");
            displayRec();
            break;
        case 2:
            displayRec();
            printf("\n\t\t\tEnter New Quiz 1: ");//1
            scanf("%d", &record.q1[choice]);

            record.ave[i] = average(record.q1[i], record.q2[i], record.q3[i]);
            record.rating[i] = rate(record.ave[i]);
            printf("\n\t\t\t%sEntered successfully.%s\n", AC_GREEN, AC_NORMAL);
            system("pause");
            displayRec();
            break;
        case 3:
            displayRec();
            printf("\n\t\t\tEnter New Quiz 2: ");//2
            scanf("%d", &record.q2[choice]);

            record.ave[i] = average(record.q1[i], record.q2[i], record.q3[i]);
            record.rating[i] = rate(record.ave[i]);
            printf("\n\t\t\t%sEntered successfully.%s\n", AC_GREEN, AC_NORMAL);
            system("pause");
            displayRec();
            break;
        case 4:
            displayRec();
            printf("\n\t\t\tEnter New Quiz 3: ");//3
            scanf("%d", &record.q3[choice]);

            record.ave[i] = average(record.q1[i], record.q2[i], record.q3[i]);
            record.rating[i] = rate(record.ave[i]);
            printf("\n\t\t\t%sEntered successfully.%s\n", AC_GREEN, AC_NORMAL);
            system("pause");
            displayRec();
            break;
        default: printf("\n\n%sError. Please enter a valid input.%s\n", AC_RED, AC_NORMAL); getch();
        }

        fwrite(&record,sizeof(struct student),1,fp);
        fclose(fp);
    }
}

void displayRec()
{
    system("cls");
    fp = fopen("student_record.txt", "r");
    if(!fp)
    {
        fprintf(stderr,"\n\n%sCannot open file or file does not exist.%s\n", AC_RED, AC_NORMAL); getch();
    }

    while(fread(&record,sizeof(struct student),1,fp))
    {
        fflush(stdin);
        for(i=0; i<arrClass[Max]; i++)
        {
            printf("\n\nNo.   Name      \t\t\t\tQuiz 1   \tQuiz 2   \tQuiz 3   \tAverage   \tRating\n");
            printf("%d   %s %s", record.stud_num[i], record.fname[i], record.lname[i]);
            printf("\t\t\t\t%d \t\t%d \t\t%d \t\t%.2f \t\t%.2f \n", record.q1[i], record.q2[i], record.q3[i], record.ave[i], record.rating[i]);
        }
    }

    fclose(fp);
    printf("\n");
    system("pause");
}

void getRecord()
{

    for(i=0; i<arrClass[Max]; i++)
        {
            system("cls");
            fp = fopen("student_record.txt", "w");
            printf("\n\n\t\t\t\t\tInput Student Name and Grades");
            printf("\n\t\t\tStudent #%i ", i + 1);

            printf("\n\t\t\tFirst Name: ");
            scanf("%s", record.fname[i]);
            printf("\n\t\t\tLast Name: ");
            scanf("%s", record.lname[i]);
            printf("\n\t\t\tStudent Number: ");
            scanf("%i", &record.stud_num[i]);

            printf("\n\t\t\tQuiz 1: ");//1
            scanf("%d", &record.q1[i]);
            printf("\n\t\t\tQuiz 2: ");//2
            scanf("%d", &record.q2[i]);
            printf("\n\t\t\tQuiz 3: ");//3
            scanf("%d", &record.q3[i]);
            record.ave[i] = average(record.q1[i], record.q2[i], record.q3[i]);
            record.rating[i] = rate(record.ave[i]);
            fwrite(&record,sizeof(struct student),1,fp);
            fclose(fp);
        }

    if(!fp)
    {
        fprintf(stderr,"\n\n%sCannot open file or file does not exist.%s\n", AC_RED, AC_NORMAL); getch();
    }
    else
    {
        printf("\n\nStudent record stored successfully\n"); getch();
    }
}

void classSize()
{
    system("cls");
    printf("\n\n\t\t\t\t\tCreate Class Size");
    printf("\n\t\t\t\tEnter size: ");
    scanf("%i", &arrClass[Max]);

    if(arrClass[Max] <= 0)
    {
        printf("\n\t\t\t\t%sInvalid input. Choose within the maximum number only.%s", AC_RED, AC_NORMAL);
        getch();
        classSize();
    }
    else if(arrClass[Max] <= Max)
    {
        printf("\n\t\t\t\tClass Size: [%i]\n\n", arrClass[Max]);
        getch();
    }
    else
    {
        printf("\n\t\t\t\t%sInvalid input. Choose within the maximum number only.%s", AC_RED, AC_NORMAL);
        getch();
        classSize();
    }
    /*loading2();*/
}

float rate(float ave)
{
    if(ave >= 1 && ave <= 19.99)
        return 4.00;
    if(ave >= 20 && ave <=39.99)
        return 3.75;
    if(ave >= 40 && ave <= 57.99)
        return 3.50;
    if(ave >= 58 && ave <= 74.99)
        return 3.25;
    if(ave >=75 && ave <= 77.99)
        return 3.00;
    if(ave >=78 && ave <= 80.99)
        return 2.75;
    if(ave >=81 && ave <= 83.99)
        return 2.50;
    if(ave >= 84 && ave<= 86.99)
        return 2.25;
    if(ave >= 87 && ave <= 90.99)
        return 2.00;
    if(ave >= 91 && ave <= 94.99)
        return 1.75;
    if(ave >= 95 && ave <= 98.99)
        return 1.50;
    if(ave >= 99 && ave <99.99)
        return 1.25;
    else if (ave == 100)
        return 1.00;
    else
        return 5.00;

}

float average(int a, int b, int c)
{
    return(a+b+c)/3;

}
