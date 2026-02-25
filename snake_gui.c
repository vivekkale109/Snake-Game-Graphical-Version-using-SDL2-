#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define BLOCK 20

int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
int gameOver;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum Direction dir;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

/* ================= Setup ================= */
void setup() {
    gameOver = 0;       
    dir = STOP;
    x = WIDTH / (2 * BLOCK);
    y = HEIGHT / (2 * BLOCK);
    fruitX = rand() % (WIDTH / BLOCK);
    fruitY = rand() % (HEIGHT / BLOCK);
    score = 0;
    nTail = 0;
}

/* ================= Draw ================= */
void draw() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw Snake Head (Green)
    SDL_Rect rect = { x * BLOCK, y * BLOCK, BLOCK, BLOCK };
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rect);

    // Draw Tail (Dark Green)
    SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);
    for (int i = 0; i < nTail; i++) {
        SDL_Rect tailRect = { tailX[i] * BLOCK, tailY[i] * BLOCK, BLOCK, BLOCK };
        SDL_RenderFillRect(renderer, &tailRect);
    }

    // Draw Fruit (Red)
    SDL_Rect fruit = { fruitX * BLOCK, fruitY * BLOCK, BLOCK, BLOCK };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &fruit);

    SDL_RenderPresent(renderer);
}

/* ================= Logic ================= */
void logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case LEFT: x--; break;
        case RIGHT: x++; break;
        case UP: y--; break;
        case DOWN: y++; break;
        default: break;
    }

    if (x < 0 || x >= WIDTH / BLOCK || y < 0 || y >= HEIGHT / BLOCK)
        gameOver = 1;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = 1;

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % (WIDTH / BLOCK);
        fruitY = rand() % (HEIGHT / BLOCK);
        nTail++;
    }
}

/* ================= Main ================= */
int main(int argc, char *argv[]) {

    srand(time(0));

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Snake Game",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              WIDTH, HEIGHT,
                              SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    setup();

    SDL_Event e;

    while (!gameOver) {

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                gameOver = 1;

            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT: dir = LEFT; break;
                    case SDLK_RIGHT: dir = RIGHT; break;
                    case SDLK_UP: dir = UP; break;
                    case SDLK_DOWN: dir = DOWN; break;
                }
            }
        }

        logic();
        draw();
        SDL_Delay(100);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}