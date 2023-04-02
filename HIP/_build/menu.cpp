#include "main.h"

//Checks if the left mouse button is clicked
bool checkMouseButton() {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        return 1;
    }
    else {
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
        buttonCollision = { 800, coordinatesY[i], 375, 85 };

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
    Rectangle buttonCalculate = { 800, 620, 375, 85 };

    if (CheckCollisionPointRec(mousePosition, buttonCalculate))
    {
        return checkMouseButton();
    }
}

bool buttonGuideClicked(Vector2 buttonPosition, Vector2 mousePosition)
{
    Rectangle buttonGuide = { 800, 720, 375, 85 };

    if (CheckCollisionPointRec(mousePosition, buttonGuide))
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
    Rectangle button1Rect = { 800, 620, button1.width, 85 };
    Rectangle button2Rect = { 800, 720, button2.width, 85 };
    Rectangle button3Rect = { 800, 820, button3.width, 85 };

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

void displayGuide(Texture2D guide)
{
    // Visualise menu background
    DrawTextureEx(guide, { 0, 0 }, 0, 1, WHITE);
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
    Texture2D guide = LoadTexture("./textures/Guide.png");

    Texture2D metals = LoadTexture("./textures/ElementsMetals.png");
    Texture2D nonmetals = LoadTexture("./textures/ElementsNonmetals.png");

    Texture2D equationButtons = LoadTexture("./textures/equationButtons.png");
    Texture2D equationButtonsHover = LoadTexture("./textures/equationButtonsHover.png");

    Texture2D calculatorButtons = LoadTexture("./textures/calculatorButtons.png");
    Texture2D calculatorButtonsHover = LoadTexture("./textures/calculatorButtonsHover.png");

    Vector2 mousePosition = { -100, -100 };
    Vector2 menuButtonPosition = { 0, 0 };
    Vector2 guideButtonPosition = { 0, 0 };

    Rectangle buttonQuitCollision = { 800, 820, 375, 85 };

    Rectangle buttonFrames = { 0, 0, (float)(button1.width), (float)button1.height };

    // Checks if the players has clicked "Calcualte"
    bool Calculate = false;
    bool Guide = false;
    bool isButtonHovering = false;
    isButtonHovering = CheckCollisionPointRec(mousePosition, buttonFrames);
    bool oneButtonClicked = true;

    //Checks if quit button was clicked
    bool wasQuitClicked = false;

    while (!WindowShouldClose() && wasQuitClicked == false)
    {
        // Tracks mouse cursor position
        mousePosition = GetMousePosition();
        menuButtonPosition = chooseOption(mousePosition);
        guideButtonPosition = chooseOption(mousePosition);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        if (buttonCalculateClicked(menuButtonPosition, mousePosition) == 0 && Calculate == false)
        {
            displayMenu(mainMenu, button1, button1Hover, button2, button2Hover, button3, button3Hover);
        }
        else {

            Calculate = true;
            Guide = false;

            DrawText(TextFormat("%0.f, %0.f", GetMousePosition().x, GetMousePosition().y), 0, 0, 20.f, WHITE);

            displayCalculate(CalcBackground);

            displayElements(metals, nonmetals, metalsButtonsHover, nonmetalsButtonsHover);

            displayCalculatorButtons(calculatorButtons, calculatorButtonsHover);

            displayEquationButtons(equationButtons, equationButtonsHover);

            displayTextBox();
            oneButtonClicked = false;
            buttonQuitCollision = { -100, -100, 0, 0 };

            if (IsKeyPressed(KEY_K)) {
                Calculate = false;
                oneButtonClicked = true;

                displayMenu(mainMenu, button1, button1Hover, button2, button2Hover, button3, button3Hover);

                buttonQuitCollision = { 800, 820, 375, 85 };
            }
        }

        if (oneButtonClicked) {
            
            if (buttonGuideClicked(guideButtonPosition, mousePosition) == 0 && Guide == false) {
                displayMenu(mainMenu, button1, button1Hover, button2, button2Hover, button3, button3Hover);
            }
            else {
                Guide = true;
                oneButtonClicked = true;

                displayGuide(guide);

                buttonQuitCollision = { -100, -100, 0, 0 };

                if (IsKeyPressed(KEY_K)) {
                    Guide = false;
                    oneButtonClicked = true;

                    displayMenu(mainMenu, button1, button1Hover, button2, button2Hover, button3, button3Hover);

                    buttonQuitCollision = { 800, 820, 375, 85 };
                }
            }
        }

        DrawText(TextFormat("%0.f, %0.f", GetMousePosition().x, GetMousePosition().y), 0, 0, 20.f, WHITE);

        if (buttonQuitClicked(menuButtonPosition, mousePosition, buttonQuitCollision) == 1)
        {
            wasQuitClicked = true;
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
    UnloadTexture(metalsButtonsHover);
    UnloadTexture(nonmetalsButtonsHover);
    UnloadTexture(guide);
    UnloadTexture(metals);
    UnloadTexture(nonmetals);
    UnloadTexture(calculatorButtons);
    UnloadTexture(calculatorButtonsHover);


    CloseWindow();
}