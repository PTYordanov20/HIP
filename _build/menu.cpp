#include "menu.h"

//Checks if the left mouse button is clicked
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

//Reads which of the three buttons is clicked
Vector2 chooseOption(Vector2 mousePosition)
{
    Rectangle buttonCollision = { 0, 0, 0, 0 };
    Vector2 buttonPosition = { -1000, -1000 };

    float coordinatesY[3] = { 620, 720, 820 };

    for (int i = 0; i < 3; i++)
    {
        buttonCollision = { 700, coordinatesY[i], 375, 105 };

        //  Checks if the mouse position is on one of the buttons
        if (CheckCollisionPointRec(mousePosition, buttonCollision))
        {
            // Checks if it's clicked
            if (checkMouseButton() == 1)
            {
                return buttonPosition = { 700, coordinatesY[i] };
            }
            else
            {
                return buttonPosition = { 700 , coordinatesY[i] };
            }
        }
    }
}
// Checks if the Calculate button is clicked
bool buttonCalculateClicked(Vector2 buttonPosition, Vector2 mousePosition)
{
    Rectangle buttonPlay = { 700, 620, 375, 105 };

    if (CheckCollisionPointRec(mousePosition, buttonPlay))
    {
        return checkMouseButton();
    }
}

// Closes game when "Quit" it's clicked
bool buttonQuitClicked(Vector2 buttonPosition, Vector2 mousePosition, Rectangle buttonQuit)
{
    if (CheckCollisionPointRec(mousePosition, buttonQuit))
    {
        return checkMouseButton();
    }
}

// Visualise app menu buttons
void displayButtons(Texture2D button1, Texture2D button2, Texture2D button3)
{
    Rectangle buttonFrame1 = { 0, 0, (float)(button1.width), (float)button1.height };
    Rectangle buttonFrame2 = { 0, 0, (float)(button2.width), (float)button2.height };
    Rectangle buttonFrame3 = { 0, 0, (float)(button3.width), (float)button3.height };

    DrawTextureRec(button1, buttonFrame1, { 700, 620 }, WHITE);
    DrawTextureRec(button2, buttonFrame2, { 700, 720 }, WHITE);
    DrawTextureRec(button3, buttonFrame3, { 700, 820 }, WHITE);
}

void displayMenu(Texture2D menu, Texture2D button1, Texture2D button2, Texture2D button3)
{
    // Visualise menu background
    DrawTextureEx(menu, { 0, 0 }, 0, 1, WHITE);

    // Visualise buttons
    displayButtons(button1, button2, button3);
}

void displayCalculate(Texture2D CalcBackground) {
    DrawTextureEx(CalcBackground, { 0, 0 }, 0, 1, WHITE);
}

void startApp() {
    //Initializing screen resolution
    InitWindow(1920, 1080, "Chemistry Calculator");

    ToggleFullscreen();

    Texture2D mainMenu = LoadTexture("./textures/mainMenu.png");
    Texture2D button1 = LoadTexture("./textures/mainMenuButton1.png");
    Texture2D button2 = LoadTexture("./textures/mainMenuButton2.png");
    Texture2D button3 = LoadTexture("./textures/mainMenuButton3.png");
    Texture2D CalcBackground = LoadTexture("./textures/calculatorBackground.png");

    Vector2 mousePosition = { -100, -100 };
    Vector2 menuButtonPosition = { 0, 0 };

    Rectangle buttonQuitCollision = { 700, 820, 375, 105 };
    Rectangle buttonFrames = { 0, 0, (float)(button1.width), (float)button1.height };
    // Checks if the players has clicked "Calcualte"
    bool Calculate = false;


    while (!WindowShouldClose())
    {
        // Tracks mouse cursor position
        mousePosition = GetMousePosition();
        menuButtonPosition = chooseOption(mousePosition);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        if (buttonCalculateClicked(menuButtonPosition, mousePosition) == 0 && Calculate == false)
        {
            displayMenu(mainMenu, button1, button2, button3);
        }
        else {
            displayCalculate(CalcBackground);
            Calculate = true; \
                buttonQuitCollision = { -100, -100, 0, 0 };
        }


        if (buttonQuitClicked(menuButtonPosition, mousePosition, buttonQuitCollision) == 1)
        {
            break;
        }

        EndDrawing();
    }

    // Unloads textures
    UnloadTexture(mainMenu);
    UnloadTexture(button1);
    UnloadTexture(button2);
    UnloadTexture(button3);
    UnloadTexture(CalcBackground);

    CloseWindow();
}