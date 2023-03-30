#include "menu.h"

//Checks if the left mouse button is clicked
bool checkMouseButton(){
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        return 1;
    }
    else{
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
        buttonCollision = { 800, coordinatesY[i], 375, 105 };

        //  Checks if the mouse position is on one of the buttons
        if (CheckCollisionPointRec(mousePosition, buttonCollision))
        {
            // Checks if it's clicked
            if (checkMouseButton() == 1)
            {
                return buttonPosition = { 800, coordinatesY[i] };
            }
            else
            {
                return buttonPosition = { 800 , coordinatesY[i] };
            }
        }
    }
}
// Checks if the Calculate button is clicked
bool buttonCalculateClicked(Vector2 buttonPosition, Vector2 mousePosition)
{
    Rectangle buttonPlay = { 800, 620, 375, 105 };

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
void displayButtons(Texture2D button1, Texture2D button1Hover, Texture2D button2, Texture2D button2Hover, Texture2D button3, Texture2D button3Hover)
{
    // Define rectangles for each button
    Rectangle button1Rect = { 800, 620, button1.width, button1.height };
    Rectangle button2Rect = { 800, 720, button2.width, button2.height };
    Rectangle button3Rect = { 800, 820, button3.width, button3.height };

    // Check if mouse is hovering over button 1
    bool isButton1Hovering = CheckCollisionPointRec(GetMousePosition(), button1Rect);

    // Draw button 1 with normal or hover texture based on mouse hover
    if (isButton1Hovering) {
        DrawTexture(button1Hover, 800, 620, WHITE);
    }
    else {
        DrawTexture(button1, 800, 620, WHITE);
    }

    // Check if mouse is hovering over button 2
    bool isButton2Hovering = CheckCollisionPointRec(GetMousePosition(), button2Rect);

    // Draw button 2 with normal or hover texture based on mouse hover
    if (isButton2Hovering) {
        DrawTexture(button2Hover, 800, 720, WHITE);
    }
    else {
        DrawTexture(button2, 800, 720, WHITE);
    }

    // Check if mouse is hovering over button 3
    bool isButton3Hovering = CheckCollisionPointRec(GetMousePosition(), button3Rect);

    // Draw button 3 with normal or hover texture based on mouse hover
    if (isButton3Hovering) {
        DrawTexture(button3Hover, 800, 820, WHITE);
    }
    else {
        DrawTexture(button3, 800, 820, WHITE);
    }
}


void displayMenu(Texture2D menu, Texture2D button1, Texture2D button1Hover, Texture2D button2, Texture2D button2Hover, Texture2D button3, Texture2D button3Hover)
{
    // Visualise menu background
    DrawTextureEx(menu, { 0, 0 }, 0, 1, WHITE);
    // Visualise buttons
    displayButtons(button1, button1Hover, button2, button2Hover, button3, button3Hover);
}

void startApp() {
    //Initializing screen resolution
    InitWindow(1920, 1080, "Chemistry Calculator");

    ToggleFullscreen();

    Texture2D mainMenu = LoadTexture("./textures/mainMenu.png");
    Texture2D button1 = LoadTexture("./textures/mainMenuButton1.png");
    Texture2D button2 = LoadTexture("./textures/mainMenuButton2.png");
    Texture2D button3 = LoadTexture("./textures/mainMenuButton3.png");

    Texture2D button1Hover = LoadTexture("./textures/mainMenuButton1Hover.png");
    Texture2D button2Hover = LoadTexture("./textures/mainMenuButton2Hover.png");
    Texture2D button3Hover = LoadTexture("./textures/mainMenuButton3Hover.png");
    Texture2D metalsButtonsHover = LoadTexture("./textures/ElementsMetalsHovers.png");
    Texture2D nonmetalsButtonsHover = LoadTexture("./textures/ElementsNonmetalsHovers.png");
    Texture2D CalcBackground = LoadTexture("./textures/calculatorBackground.png");

    Texture2D metals = LoadTexture("./textures/ElementsMetals.png");
    Texture2D nonmetals = LoadTexture("./textures/ElementsNonmetals.png");

    Vector2 mousePosition = { -100, -100 };
    Vector2 menuButtonPosition = { 0, 0 };

    Rectangle buttonQuitCollision = { 800, 820, 375, 105 };
    Rectangle buttonFrames = { 0, 0, (float)(button1.width), (float)button1.height };
    // Checks if the players has clicked "Calcualte"
    bool Calculate = false;
    bool isButtonHovering = false;
    isButtonHovering = CheckCollisionPointRec(mousePosition, buttonFrames);

    while (!WindowShouldClose())
    {
        // Tracks mouse cursor position
        mousePosition = GetMousePosition();
        menuButtonPosition = chooseOption(mousePosition);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        if (buttonCalculateClicked(menuButtonPosition, mousePosition) == 0 && Calculate == false)
        {

            displayMenu(mainMenu, button1, button1Hover, button2, button2Hover, button3, button3Hover);
        }
        else {

            displayCalculate(CalcBackground);
            displayElements(metals, nonmetals, metalsButtonsHover, nonmetalsButtonsHover);
            Calculate = true;
            DrawText(TextFormat("%0.f, %0.f", GetMousePosition().x, GetMousePosition().y), 0, 0, 20.f, WHITE);


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
    UnloadTexture(button1Hover);
    UnloadTexture(button2Hover);
    UnloadTexture(button3Hover);
    UnloadTexture(CalcBackground);

    CloseWindow();
}