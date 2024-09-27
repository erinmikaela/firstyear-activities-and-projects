/*
INSTRUCTIONS:

1. Upon opening the workspace, go to settings > compiler > linker settings > Other linker options, then type -lwinmm . Click OK.
2. Build and run the program.
Note: Make sure the main .c file and .wav file are in the same folder.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <mmstream.h>
#include "logo.h"

#define ROWS 20
#define COLS 20
#define MINES 10
#define LIVES 3
#define SCORE 0

#define BOMB 'X'
#define EMPTY ' '
#define TILE 219
#define MAX 3
#define TRUE 1
#define FALSE 0

#define GREEN "\x1b[32m"
#define GRAY "\x1b[38;5;145m"
#define FGREEN1 "\x1b[38;5;22m"
#define FGREEN2 "\x1b[38;5;107m"

void initialize_world();
void print_world();
void plant_mines();
void checkbomb();
void menu();
void playgame();
void gameover();
void getuseryandx();
void hideCursor();
void view();
void write();
void loading1();
void loading2();
int coordmaker(int lower, int upper);

char *numtocolor[7] =
{
    RED, GREEN, NORMAL, FGREEN1, FGREEN2, GRAY
};
char world[ROWS][COLS];
int bombx[MINES], bomby[MINES], userx, usery, bomb_flag, color[ROWS][COLS], lives, score;
int  loop1, loop2;
FILE *fp;



int main()
{
    srand(time(NULL));
    system("COLOR F0");
    hideCursor();
    loading1();
    Sleep(1000);
    menu();
        return 0;
}

void menu()
{
    char userInput;
    do
    {
        system("cls");
        hideCursor();
        logo();
        gotoxy(26,6);
        printf("%s\t\t\t  Minesweeper\n%s", BLUEBG, NORMAL);
        printf("\n\t\t\t\t\t      %c [P]lay game", 16);
        printf("\n\t\t\t\t\t      %c [V]iew Scoreboard", 16);
        printf("\n\t\t\t\t\t      %c [E]xit", 16);
        userInput = toupper(getch());
        switch(userInput)
        {
            case 'P': loading2();initialize_world(); playgame(); break;
            case 'V': loading2(); view(); getch(); break;
            case 'E': PlaySound(NULL,0,0); gotoxy(0,27);printf("%sThank you for playing%s",FGREENBG, NORMAL);

        }
    }while(userInput != 'E');
        return;
}

void playgame()
{
    system("COLOR F0");
    PlaySound(TEXT("A-Lonely-Cherry-Tree.wav"), NULL, SND_ASYNC | SND_LOOP);
    system("cls");
    print_world();
    printf("\n");

    do
    {
        getuseryandx();
        checkbomb();
        system("cls");
        print_world();
    }while(lives > 0);

    gameover();
        return;

}
void gameover()
{
    char name[10];
    gotoxy(80,10);
    printf("%sGAME OVER. %s", RED, NORMAL);
    gotoxy(80,12);
    printf("SCORE: %i", score);
    gotoxy(80,14);
    printf("ENTER NAME: ");
    scanf("%s", name);
    write(name);
    gotoxy(80,16);
    printf("Press any key to continue...");
    getch();
        return;
}


void getuseryandx()
{
    gotoxy(80,8);
    printf("Enter X: ");
    scanf("%i",&userx);
    gotoxy(80,10);
    printf("Enter Y: ");
    scanf("%i", &usery);
    if(usery > ROWS - 1 || userx > COLS - 1 || usery < 0 || userx < 0){
        gotoxy(1,25);
        printf("Coordinates are not in the range. Renter new coordinates within range.");
        getch();
        system("cls");
        print_world();
        getuseryandx();
    }else if(world[usery][userx] == EMPTY || world[usery][userx] == BOMB){
        gotoxy(1,25);
        printf("The coordinate has been previously entered...Press any key to continue");
        getch();
        system("cls");
        print_world();
        getuseryandx();
    }
        return;
}

void checkbomb()
{
    for(loop2 = 0; loop2 < MINES; loop2++)
    {
        if(usery == bomby[loop2] && userx == bombx[loop2]){
            world[usery][userx] = BOMB;
            bomb_flag = TRUE;
            --lives;
        }
    }
    if(bomb_flag == FALSE){
        world[usery][userx] = EMPTY;
        score += 10;
    }
    bomb_flag = 0;
        return;
}

void initialize_world()
{
    bomb_flag = FALSE;
    lives = LIVES;
    score = SCORE;
    for(loop1 = 0; loop1 < ROWS; loop1++)
    {
        for(loop2 = 0; loop2 < COLS; loop2++)
        {
            world[loop1][loop2] = TILE;
            color[loop1][loop2] = ((loop1 % 2 == 0 && loop2 % 2 == 0) || (loop1 % 2 == 1 && loop2 % 2 == 1) ? 3 : 4);
        }
    }
    plant_mines();
        return;
}

void print_world()
{

    printf("\n\n\n\t\t\t\t        ");

    for(loop1 = 0; loop1 < COLS; loop1++){
        if(loop1 < 10){
            printf("%i ", loop1);
        }else{
            printf("%c ", loop1 + 55);
        }
    }

    for(loop1 = 0; loop1 < ROWS; loop1++)
    {
        printf("\n\t\t\t\t    ");
        if(loop1 < 10){
            printf(" %i ", loop1);
        }else{
            printf(" %c ", loop1 + 55);
        }

        for(loop2 = 0; loop2 < COLS; loop2++)
        {
            printf("%s%c%c%s", numtocolor[color[loop1][loop2]],world[loop1][loop2],world[loop1][loop2], NORMAL);
        }
        switch(loop1)
        {
        case 0:
            {
                switch (lives)
                {
                case 0: printf("\tLives: %s%c %c %c%s", GRAY, 3, 3, 3, NORMAL); break;
                case 1: printf("\tLives: %s%c %s%c %c%s", RED, 3, GRAY, 3, 3, NORMAL); break;
                case 2: printf("\tLives: %s%c %c %s%c%s", RED, 3, 3, GRAY, 3, NORMAL); break;
                case 3: printf("\tLives: %s%c %c %c%s", RED, 3, 3, 3, NORMAL); break;

                }
                break;
            }
        case 1: printf("\tScore: %i", score);; break;
        }
    }
    gotoxy(80,20);
    printf("A = 10 B = 11 C = 12 D = 13 E = 14");
    gotoxy(80,22);
    printf("F = 15 G = 16 H = 17 I = 18 J = 19");
        return;
}


void plant_mines()
{
    for(loop1 = 0; loop1 < MINES; loop1++){
        bombx[loop1] = coordmaker(0,COLS - 1);
        bomby[loop1] = coordmaker(0,ROWS - 1);
    }
        return;
}

int coordmaker(int lower, int upper)
{
    return(rand()% (upper-lower+1)+lower);
}

void hideCursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
       return;
}
void write(char name[3])
{
    fp = fopen("minesweepers.txt", "a");
    fprintf(fp, "\tPlayer Name: %s\n", name);
    fprintf(fp, "\tScore: %i\n", score);
    fprintf(fp, "_______________________________________________\n");
    fclose(fp);
        return;
}

void view()
{

    char character;
    system("cls");
    logo();
    fp = fopen("minesweepers.txt", "r");
    gotoxy(0,23);
    printf("_______________________________________________");
    if(!fp)
    {
        printf("\n The file does not exist. \n");
        printf("\nPress any key to continue...");
        getch();
        main();
    }

    character = fgetc(fp);
    while(!feof(fp))
    {
        printf("%c", character);
        character = fgetc(fp);
    }

    fclose(fp);
    return;
}

void loading1()
{
    system("cls");
    printf("\n\n\n\n");
    printf("\n\n\n\n\t\t\t\t\t       Loading.... Please wait\n");
    printf("\n\t\t\t\t   ");


    for(int i = 1; i <= 50; i++)
    {
        printf("%s%c%s", GREEN, 176, NORMAL);
    }

    printf("\r");
    printf("\t\t\t\t   ");

    for(int i = 1; i <= 50; i++)
    {
        Sleep(30);
        printf("%s%c%s", GREEN, 219, NORMAL);
    }
    printf("\n\n\t\t\t\t\t    Successfully Loaded. Welcome %s%c%s",RED,3,NORMAL);
}

void loading2(){
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\tLoading");
    for(int i =0; i <= 6; i++){
        Sleep(300);
        printf(".");
    }
}
