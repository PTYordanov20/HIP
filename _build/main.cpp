#include "raylib.h"
#include <iostream>
using namespace std;

int main()
{
    InitWindow(860, 460, "Chemistry Calculator");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        
        ClearBackground(RAYWHITE);



        EndDrawing();
    }

    CloseWindow();
}