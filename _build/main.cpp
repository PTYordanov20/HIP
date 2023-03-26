#include "raylib.h"
#include <iostream>
using namespace std;

static const int screenWidth = 1920;
static const int screenHeight = 1080;

int main()
{
    //Initializing screen resolution
    InitWindow(screenWidth, screenHeight, "Chemistry Calculator");

    ToggleFullscreen();

    Texture2D mainMenu = LoadTexture("./textures/mainMenu.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(mainMenu, 0, 0, WHITE);

        EndDrawing();
    }

    CloseWindow();
}