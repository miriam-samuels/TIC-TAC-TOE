#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void menu();
void startgame();
void draw();
int check();
void board();
void result();

char box[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
size_t turns = 0;
char mark;

COORD coord = {0, 0}; // set co-ordinates
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void menu()
{
    int c;
menu:
    gotoxy(15, 5);
    printf("-----------------MAIN MENU------------------");
    gotoxy(15, 7);
    printf("1. Play with X");
    gotoxy(15, 8);
    printf("2. Play with O");
    gotoxy(15, 9);
    printf("3. Exit");
    gotoxy(15, 12);
    printf("Enter your choice: ");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        startgame();
        break;
    case 2:
        startgame();
        break;
    case 3:
        exit(1);
        break;
    default:
        printf("invalid choice");
        getchar();
        goto menu;
    }
}

void board()
{
    system("cls");
    gotoxy(15, 10);
    printf("        |         |        ");
    gotoxy(15, 11);
    printf("    %c   |   %c     |   %c   ", box[1], box[2], box[3]);
    gotoxy(15, 12);
    printf("________|_________|________");
    gotoxy(15, 13);
    printf("        |         |        ");
    gotoxy(15, 14);
    printf("    %c   |   %c     |   %c   ", box[4], box[5], box[6]);
    gotoxy(15, 15);
    printf("________|_________|________");
    gotoxy(15, 16);
    printf("        |         |        ");
    gotoxy(15, 17);
    printf("    %c   |   %c     |   %c   ", box[7], box[8], box[9]);
    gotoxy(15, 18);
    printf("        |         |        \n");
    getchar();
}

void startgame()
{
    size_t c;
play:
    mark = (c % 2) == 1 ? 'X' : 'O';
    board();
    check();
    draw();
    gotoxy(10, 20);
    printf("Pick a number from 1-9 to choose cells to play on.\n");
    gotoxy(10, 21);
    switch (getc(stdin))
    {
    case '1':
        box[1] = mark;
        break;
    case '2':
        box[2] = mark;
        break;
    case '3':
        box[3] = mark;
        break;
    case '4':
        box[4] = mark;
        break;
    case '5':
        box[5] = mark;
        break;
    case '6':
        box[6] = mark;
        break;
    case '7':
        box[7] = mark;
        break;
    case '8':
        box[8] = mark;
        break;
    case '9':
        box[9] = mark;
        break;
    default:
        printf("invalid cell number");
        c++;
        turns--;
        goto play;
        break;
    }
    result();
    c++;
    turns++;
    if (turns <= 9)
    {
        goto play;
    }
}
void draw()
{
    if (turns > 9)
    {
        printf("The game is a draw");
        getchar();
    }
}
int check()
{

    if ((box[1] == box[2]) && (box[2] == box[3]))
    {
        return 1;
    }
    else if ((box[4] == box[5]) && (box[5] == box[6]))
    {
        return 1;
    }
    else if ((box[7] == box[8]) && (box[8] == box[9]))
    {
        return 1;
    }
    else if ((box[1] == box[5]) && (box[5] == box[9]))
    {
        return 1;
    }
    else if ((box[3] == box[5]) && (box[5] == box[7]))
    {
        return 1;
    }
    else if ((box[1] == box[4]) && (box[4] == box[7]))
    {
        return 1;
    }
    else if ((box[2] == box[5]) && (box[5] == box[8]))
    {
        return 1;
    }
    else if ((box[3] == box[6]) && (box[6] == box[9]))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    // return 1;
}
void result()
{
    if (check() == 1)
    {
        gotoxy(10, 20);
        printf("We have a winner, %c is our winner horray horray horray", mark );
        // getchar();
        // exit(1);

    }
}

int main()
{
    system("cls");
    menu();
    getchar();
}
