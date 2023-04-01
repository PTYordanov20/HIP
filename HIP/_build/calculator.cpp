#include "main.h"

void displayCalculate(Texture2D CalcBackground) {
	DrawTextureEx(CalcBackground, { 0, 0 }, 0, 1, WHITE);
}

void displayElements(Texture2D metals, Texture2D nonmetals, Texture2D metalsButtonsHover, Texture2D nonmetalsButtonsHover) {
	string metalElementSign = "";

	for (int i = 1; i <= 9; i++)
	{
		float specialWidth = 0;
		Vector2 coordinates = { 0, 0 };
		switch (i) {
		case 1:	specialWidth = (metals.width / 9.1); coordinates = { 79, 439 }; metalElementSign = "Mg"; break;
			case 2:	specialWidth = (metals.width / 9.1); coordinates = { 215, 439 }; metalElementSign = "Na"; break;
			case 3: specialWidth = (metals.width / 9.1); coordinates = { 79, 584 }; metalElementSign = "Ca"; break;
			case 4: specialWidth = (metals.width / 9 - 0.1); coordinates = { 215.5, 584 }; metalElementSign = "K"; break;
			case 5: specialWidth = (metals.width / 9); coordinates = { 353, 584 }; metalElementSign = "Fe"; break;
			case 6: specialWidth = (metals.width / 9.1 + 1); coordinates = { 491, 584 }; metalElementSign = "Cu"; break;
			case 7: specialWidth = (metals.width / 9.1 + 1.2); coordinates = { 354, 743 }; metalElementSign = "Ag"; break;
			case 8: specialWidth = (metals.width / 9.1 + 1.3); coordinates = { 490, 743 }; metalElementSign = "Au"; break;
			case 9: specialWidth = (metals.width / 9.1 + 1.1); coordinates = { 629, 742 }; metalElementSign = "Al"; break;
			default: break;
		}
		Rectangle elementFrame = { i * specialWidth, 0, (float)(metals.width / 9.1), (float)(metals.height) };
		float x = coordinates.x;
		float y = coordinates.y;
		Rectangle elementButton1 = { x, y, 100, 100 };
		bool isHovering = CheckCollisionPointRec(GetMousePosition(), elementButton1);
		if (isHovering) {
			DrawTextureRec(metalsButtonsHover, elementFrame, { x, y }, WHITE);
		}
		else {
			DrawTextureRec(metals, elementFrame, { x, y }, WHITE);
		}

	}
	string nonmetalElementSign = "";
	for (int i = 1; i <= 9; i++)
	{
		float specialWidth = 0;
		Vector2 coordinates = { 0, 0 };
		switch (i) {
		case 1:	specialWidth = (nonmetals.width / 9.1 + 0.1); coordinates = { 1719, 438 }; nonmetalElementSign = "H2"; break;
		case 2:	specialWidth = (nonmetals.width / 9.1 + 0.1); coordinates = { 1582, 438 }; nonmetalElementSign = "N2"; break;
		case 3: specialWidth = (nonmetals.width / 9.1 + 1); coordinates = { 1718, 583 }; nonmetalElementSign = "O2"; break;
		case 4: specialWidth = (metals.width / 9 - 0.1); coordinates = { 1582, 583 }; nonmetalElementSign = "S"; break;
		case 5: specialWidth = (nonmetals.width / 9 + 1); coordinates = { 1444, 583 }; nonmetalElementSign = "Cl2"; break;
		case 6: specialWidth = (nonmetals.width / 9.1 + 1.3); coordinates = { 1308, 584 }; nonmetalElementSign = "P"; break;
		case 7: specialWidth = (nonmetals.width / 9.1 + 1.3); coordinates = { 1445, 743 }; nonmetalElementSign = "Br2"; break;
		case 8: specialWidth = (nonmetals.width / 9.1 + 1.2); coordinates = { 1308, 743 }; nonmetalElementSign = "I2"; break;
		case 9: specialWidth = (nonmetals.width / 9.1 + 1.1); coordinates = { 1172, 742 }; nonmetalElementSign = "C"; break;
		default: break;
		}
		Rectangle elementFrame = { i * specialWidth, 0, (float)(metals.width / 9.1), (float)(metals.height) };
		float x = coordinates.x;
		float y = coordinates.y;
		Rectangle elementButton1 = { x, y, 100, 100 };
		bool isHovering = CheckCollisionPointRec(GetMousePosition(), elementButton1);
		if (isHovering) {
			DrawTextureRec(nonmetalsButtonsHover, elementFrame, { x, y }, WHITE);
		}
		else {
			DrawTextureRec(nonmetals, elementFrame, { x, y }, WHITE);
		}

	}
	
}

void displayCalculatorButtons(Texture2D calculatorButtons, Texture2D calculatorButtonsHover) {
	
	for (int i = 1; i <= 10; i++)
	{
		float specialWidth = 0;
		Vector2 coordinates = { 0, 0 };
		switch (i) {
		case 1:	specialWidth = (calculatorButtons.width / 10.1 + 1); coordinates = { 905, 389 }; break;
		case 2:	specialWidth = (calculatorButtons.width / 10.1 + 1.1); coordinates = { 1023, 389 }; break;
		case 3: specialWidth = (calculatorButtons.width / 10.1 + 0.9); coordinates = { 788, 469 }; break;
		case 4: specialWidth = (calculatorButtons.width / 10.1 + 1); coordinates = { 905, 469 }; break;
		case 5: specialWidth = (calculatorButtons.width / 10.1 + 1); coordinates = { 1024, 469 }; break;
		case 6: specialWidth = (calculatorButtons.width / 10.1 + 1); coordinates = { 788, 549 }; break;
		case 7: specialWidth = (calculatorButtons.width / 10.1 + 1); coordinates = { 905, 549 }; break;
		case 8: specialWidth = (calculatorButtons.width / 10.1 + 1); coordinates = { 1024, 549 }; break;
		case 9: specialWidth = (calculatorButtons.width / 10.1 + 1); coordinates = { 906, 629 }; break;
		case 10: specialWidth = (calculatorButtons.width / 10.1 + 0.9); coordinates = { 788, 389 }; break;
		default: break;
		}
		Rectangle elementFrame = { i * specialWidth, 0, (float)(calculatorButtons.width / 10.1), (float)(calculatorButtons.height) };
		float x = coordinates.x;
		float y = coordinates.y;
		Rectangle elementButton1 = { x, y, 89, 59 };
		bool isHovering = CheckCollisionPointRec(GetMousePosition(), elementButton1);

		if (isHovering) {
			DrawTextureRec(calculatorButtonsHover, elementFrame, { x, y }, WHITE);
		}
		else {
			DrawTextureRec(calculatorButtons, elementFrame, { x, y }, WHITE);
		}

	}
}

//void isElementClicked() {
//	string elementSign = "";
//
//}
//void displayTextBox(string text[26], int& cursorPosition, bool& textboxSelected) {
//	const int maxChars = 26;
//	int TEXTBOX_WIDTH = 1100;
//	int TEXTBOX_HEIGHT = 75;
//
//	Rectangle textBox = {400, 175, TEXTBOX_WIDTH, TEXTBOX_HEIGHT};
//
//	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
//		if (CheckCollisionPointRec(GetMousePosition(), textBox)) {
//			textboxSelected = true;
//		}
//		else {
//			textboxSelected = false;
//		}
//	}
//
//	if (textboxSelected) {
//		string key = ;
//
//		if ((cursorPosition < maxChars)) {
//			text[cursorPosition] = (char)key;
//			cursorPosition++;
//		}
//		else if ((key == KEY_BACKSPACE) && (cursorPosition > 0)) {
//			cursorPosition--;
//			text[cursorPosition] = '\0';
//		}
//	}
//
//	DrawRectangle(400, 175, TEXTBOX_WIDTH, TEXTBOX_HEIGHT, BLACK);
//	DrawRectangle(403, 178, TEXTBOX_WIDTH - 6, TEXTBOX_HEIGHT - 6, LIGHTGRAY);
//	DrawText(text, 410, 183, 60, BLACK);
//
//	if (textboxSelected)
//	{
//		DrawLine(408, 180, 408, 180 + TEXTBOX_HEIGHT - 12, BLACK);
//	}
//}