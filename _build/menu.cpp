#include "menu.h"

bool checkMouseButton()
{
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Vector2 chooseOption(Vector2 mousePosition)
{
    Rectangle buttonCollision = { 0, 0, 0, 0 };
    Vector2 buttonPosition = { -1000, -1000 };

    float coordinatesY[2] = { 400, 500 };

    for (int i = 0; i < 2; i++)
    {
        buttonCollision = { 620, coordinatesY[i], 300, 90 };

        //  Checks if the mouse position is on one of the buttons
        if (CheckCollisionPointRec(mousePosition, buttonCollision))
        {
            // Checks if it's clicked
            if (checkMouseButton() == 1)
            {
                return buttonPosition = { 620, coordinatesY[i] };
            }
            else
            {
                return buttonPosition = { 620 , coordinatesY[i] };
            }
        }
    }
}

// Visualise text in game menu

void displayMenuText()
{
    // Visualise button text in game menu
    DrawText("Calculate", 725, 650, 60, WHITE);
    DrawText("Guide", 725, 750, 60, WHITE);
    DrawText("Quit", 725, 850, 60, RED);
}

void startApp() {
    //Initializing screen resolution
    InitWindow(1920, 1080, "Chemistry Calculator");

    ToggleFullscreen();

    Texture2D mainMenu = LoadTexture("./textures/mainMenu.png");


    Vector2 mousePosition = { -100, -100 };

    while (!WindowShouldClose())
    {
        BeginDrawing();

        // Tracks mouse cursor position
        mousePosition = GetMousePosition();

        ClearBackground(RAYWHITE);

        DrawTexture(mainMenu, 0, 0, WHITE);
        displayMenuText();

        EndDrawing();
    }

    CloseWindow();

    // Unloads textures
    UnloadTexture(mainMenu);
}