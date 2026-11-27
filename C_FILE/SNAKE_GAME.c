#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 10

int main() {
    int snakeX = WIDTH / 2;
    int snakeY = HEIGHT / 2;
    int foodX = 5;
    int foodY = 3;
    int score = 0;
    char move;
    int gameOver = 0;

    while (!gameOver) {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        printf("Score: %d\n", score);

        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                    printf("#");
                } else if (i == snakeY && j == snakeX) {
                    printf("O");
                } else if (i == foodY && j == foodX) {
                    printf("F");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        printf("Enter move (W/A/S/D) or Q to quit: ");
        scanf(" %c", &move);

        switch (move) {
            case 'w': case 'W': snakeY--; break;
            case 's': case 'S': snakeY++; break;
            case 'a': case 'A': snakeX--; break;
            case 'd': case 'D': snakeX++; break;
            case 'q': case 'Q': gameOver = 1; break;
            default: break;
        }

        if (snakeX <= 0 || snakeX >= WIDTH - 1 || snakeY <= 0 || snakeY >= HEIGHT - 1) {
            gameOver = 1;
            printf("\nGame Over! You hit a wall.\n");
        }

        if (snakeX == foodX && snakeY == foodY) {
            score += 10;
            foodX = 1 + rand() % (WIDTH - 2);
            foodY = 1 + rand() % (HEIGHT - 2);
        }
    }

    printf("Final Score: %d\n", score);
    return 0;
}