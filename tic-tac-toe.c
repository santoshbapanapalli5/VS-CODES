#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void drawboard()
{
    for (int i = 0; i < 3; i++)
    {
        printf("%c | %c | %c\n", board[i][0], board[i][1], board[i][2]);
        if (i != 2)
        {
            printf("--|---|---\n");
        }
    }
}
int checkwin()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return 1;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return 1;
    }

    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'x' && board[i][j] != 'o')
            {
                count++;
            }
        }
    }
    if (count == 0)
    {
        return 2;
    }
}

int main()
{

    int row, column, gamestatus, move;
    int player = 1;
    while (1)
    {
        drawboard();
        player = (player % 2) ? 1 : 2;
        printf("player %d move: ", player);
        scanf("%d", &move);
        if (move >= 1 && move <= 9)
        {
            row = (move - 1) / 3;
            column = (move - 1) % 3;
            if (board[row][column] != 'x' && board[row][column] != 'o')
            {
                if (player == 1)
                {
                    board[row][column] = 'x';
                    system("cls");
                }
                else
                {
                    board[row][column] = 'o';
                    system("cls");
                }
            }
            else
            {
                system("cls");
                printf("this place is already occupied\n");
                player--;
            }
            gamestatus = checkwin();
            if (gamestatus == 1)
            {
                drawboard();
                printf("player %d win", player);
                break;
            }
            if (gamestatus == 2)
            {
                drawboard();
                printf("draw");
                break;
            }
            player++;
        }
        else
        {
            system("cls");
            printf("enter a valid number\n");
        }
    }
    return 0;
}