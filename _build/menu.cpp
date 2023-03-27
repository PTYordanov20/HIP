#include "menu.h"

/*void displayMenuText()
{
    // Visualise button text in game menu
    DrawText("Calculate", 725, 650, 60, WHITE);
    DrawText("Guide", 725, 750, 60, WHITE);
    DrawText("Quit", 725, 850, 60, RED);
}*/

void startApp() {
    //Initializing screen resolution
    InitWindow(1920, 1080, "Chemistry Calculator");

    ToggleFullscreen();

    Texture2D mainMenu = LoadTexture("./textures/mainMenu.png");
    Texture2D button1 = LoadTexture("./textures/mainMenuButton1.png");
    Texture2D button2 = LoadTexture("./textures/mainMenuButton2.png");
    Texture2D button3 = LoadTexture("./textures/mainMenuButton3.png");

    const int buttonX = 700;
    const int button1Y = 620;
    const int button2Y = 720;
    const int button3Y = 820;

    Rectangle buttonRect1 = { buttonX, button1Y, button1.width, button1.height };
    Rectangle buttonRect2 = { buttonX, button2Y, button2.width, button2.height };
    Rectangle buttonRect3 = { buttonX, button3Y, button3.width, button3.height };

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(mainMenu, 0, 0, WHITE);
        DrawTexture(button1, buttonX, button1Y, WHITE);
        DrawTexture(button2, buttonX, button2Y, WHITE);
        DrawTexture(button3, buttonX, button3Y, WHITE);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), buttonRect3)) {
            CloseWindow();
        }

        EndDrawing();
    }

    // Unloads textures
    UnloadTexture(mainMenu);
    UnloadTexture(button1);
    UnloadTexture(button2);
    UnloadTexture(button3);

    CloseWindow();
}