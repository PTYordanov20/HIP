#include "main.h"

char equationText[25];
int textIndex = 0;

void displayCalculate(Texture2D CalcBackground) {
	DrawTextureEx(CalcBackground, { 0, 0 }, 0, 1, WHITE);
}

// add elements to the text box
void addElement(Vector2 coordinates) {

	if (textIndex >= 25) {
		return;
	}

	if (coordinates.x == 79 && coordinates.y == 439) {
		equationText[textIndex++] = 'M';
		equationText[textIndex++] = 'g';
	}
	else if (coordinates.x == 215 && coordinates.y == 439) {
		equationText[textIndex++] = 'N';
		equationText[textIndex++] = 'a';
	}
	else if (coordinates.x == 79 && coordinates.y == 584) {
		equationText[textIndex++] = 'C';
		equationText[textIndex++] = 'a';
	}
	else if (coordinates.x == 215.5 && coordinates.y == 584) {
		equationText[textIndex++] = 'K';
	}
	else if (coordinates.x == 353 && coordinates.y == 584) {
		equationText[textIndex++] = 'F';
		equationText[textIndex++] = 'e';
	}
	else if (coordinates.x == 491 && coordinates.y == 584) {
		equationText[textIndex++] = 'C';
		equationText[textIndex++] = 'u';
	}
	else if (coordinates.x == 354 && coordinates.y == 743) {
		equationText[textIndex++] = 'A';
		equationText[textIndex++] = 'g';
	}
	else if (coordinates.x == 490 && coordinates.y == 743) {
		equationText[textIndex++] = 'A';
		equationText[textIndex++] = 'u';
	}
	else if (coordinates.x == 629 && coordinates.y == 742) {
		equationText[textIndex++] = 'A';
		equationText[textIndex++] = 'l';
	}
	else if (coordinates.x == 1718 && coordinates.y == 583) {
		equationText[textIndex++] = 'O';
	}
	else if (coordinates.x == 1719 && coordinates.y == 438) {
		equationText[textIndex++] = 'H';
	}
	else if (coordinates.x == 1582 && coordinates.y == 438) {
		equationText[textIndex++] = 'N';
	}
	else if (coordinates.x == 1582 && coordinates.y == 583) {
		equationText[textIndex++] = 'S';
	}
	else if (coordinates.x == 1444 && coordinates.y == 583) {
		equationText[textIndex++] = 'C';
		equationText[textIndex++] = 'l';
	}
	else if (coordinates.x == 1308 && coordinates.y == 584) {
		equationText[textIndex++] = 'P';
	}
	else if (coordinates.x == 1445 && coordinates.y == 743) {
		equationText[textIndex++] = 'B';
		equationText[textIndex++] = 'r';
	}
	else if (coordinates.x == 1308 && coordinates.y == 743) {
		equationText[textIndex++] = 'I';
	}
	else if (coordinates.x == 1172 && coordinates.y == 742) {
		equationText[textIndex++] = 'C';
	}
	else if (coordinates.x == 906 && coordinates.y == 389) {
		equationText[textIndex++] = '2';
	}
	else if (coordinates.x == 1024 && coordinates.y == 389) {
		equationText[textIndex++] = '3';
	}
	else if (coordinates.x == 789 && coordinates.y == 469) {
		equationText[textIndex++] = '4';
	}
	else if (coordinates.x == 906 && coordinates.y == 469) {
		equationText[textIndex++] = '5';
	}
	else if (coordinates.x == 1025 && coordinates.y == 469) {
		equationText[textIndex++] = '6';
	}
	else if (coordinates.x == 789 && coordinates.y == 549) {
		equationText[textIndex++] = '7';
	}
	else if (coordinates.x == 906 && coordinates.y == 549) {
		equationText[textIndex++] = '8';
	}
	else if (coordinates.x == 1025 && coordinates.y == 549) {
		equationText[textIndex++] = '9';
	}
	else if (coordinates.x == 906 && coordinates.y == 629) {
		equationText[textIndex++] = '0';
	}
	else if (coordinates.x == 789 && coordinates.y == 389) {
		equationText[textIndex++] = '1';
	}
	else if (textIndex != 0 && equationText[textIndex-1] != '+' && equationText[textIndex - 1] != '>') {
		if (coordinates.x == 789 && coordinates.y == 629) {
			equationText[textIndex++] = '(';
		}
		else if (coordinates.x == 1024 && coordinates.y == 628) {
			equationText[textIndex++] = ')';
		}
		else if (coordinates.x == 911 && coordinates.y == 703) {
			equationText[textIndex++] = '+';
		}
		else if (coordinates.x == 909 && coordinates.y == 785) {
			equationText[textIndex++] = '-';
			equationText[textIndex++] = '>';
		}
	}

	if (coordinates.x == 1591 && coordinates.y == 164) {	
		switch (equationText[textIndex - 1]) {
			case 'g':
			case 'a':
			case 'e':
			case 'u':
			case 'l':
			case 'r':
			case '>':
				if (textIndex - 2 >= 0) {
					textIndex--;
					for (int i = textIndex; i > textIndex - 2; i--) {
						equationText[i] = '\0';
					}
					textIndex--;
				}
				else {
					textIndex = 0;
				}

				break;
			default:
				if (--textIndex < 0) {
					textIndex = 0;
				}
				equationText[textIndex] = '\0';

				break;
		}
	}
	
}
void displayTextBox() {
	DrawText(equationText, 400, 183, 70, BLACK);
}

void displayElements(Texture2D metals, Texture2D nonmetals, Texture2D metalsButtonsHover, Texture2D nonmetalsButtonsHover) {

	for (int i = 1; i <= 9; i++)
	{
		double specialWidth = 0;
		Vector2 coordinates = { 0, 0 };
		switch (i) {
		case 1:	specialWidth = (metals.width / 9.1); coordinates = { 79, 439 };break;
		case 2:	specialWidth = (metals.width / 9.1); coordinates = { 215, 439 }; break;
		case 3: specialWidth = (metals.width / 9.1); coordinates = { 79, 584 }; break;
		case 4: specialWidth = (metals.width / 9 - 0.1); coordinates = { 215.5, 584 }; break;
		case 5: specialWidth = (metals.width / 9); coordinates = { 353, 584 }; break;
		case 6: specialWidth = (metals.width / 9.1 + 1); coordinates = { 491, 584 }; break;
		case 7: specialWidth = (metals.width / 9.1 + 1.2); coordinates = { 354, 743 }; break;
		case 8: specialWidth = (metals.width / 9.1 + 1.3); coordinates = { 490, 743 }; break;
		case 9: specialWidth = (metals.width / 9.1 + 1.1); coordinates = { 629, 742 }; break;
		default: break;
		}
		Rectangle elementFrame = { i * specialWidth, 0, (float)(metals.width / 9.1), (float)(metals.height) };
		float x = coordinates.x;
		float y = coordinates.y;
		Rectangle elementButton1 = { x, y, 100, 100 };
		bool isHovering = CheckCollisionPointRec(GetMousePosition(), elementButton1);
		if (isHovering) {
			DrawTextureRec(metalsButtonsHover, elementFrame, { x, y }, WHITE);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				addElement(coordinates);
			}
		}
		else {
			DrawTextureRec(metals, elementFrame, { x, y }, WHITE);
		}

	}

	for (int i = 1; i <= 9; i++)
	{
		float specialWidth = 0;
		Vector2 coordinates = { 0, 0 };
		switch (i) {
			case 1:	specialWidth = (nonmetals.width / 9.1 + 0.1); coordinates = { 1719, 438 }; break;
			case 2:	specialWidth = (nonmetals.width / 9.1 + 0.1); coordinates = { 1582, 438 }; break;
			case 3: specialWidth = (nonmetals.width / 9.1 + 1); coordinates = { 1718, 583 }; break;
			case 4: specialWidth = (metals.width / 9 - 0.1); coordinates = { 1582, 583 }; break;
			case 5: specialWidth = (nonmetals.width / 9 + 1); coordinates = { 1444, 583 }; break;
			case 6: specialWidth = (nonmetals.width / 9.1 + 1.3); coordinates = { 1308, 584 }; break;
			case 7: specialWidth = (nonmetals.width / 9.1 + 1.3); coordinates = { 1445, 743 }; break;
			case 8: specialWidth = (nonmetals.width / 9.1 + 1.2); coordinates = { 1308, 743 }; break;
			case 9: specialWidth = (nonmetals.width / 9.1 + 1.1); coordinates = { 1172, 742 }; break;
			default: break;
		}
		Rectangle elementFrame = { i * specialWidth, 0, (float)(metals.width / 9.1), (float)(metals.height) };
		float x = coordinates.x;
		float y = coordinates.y;
		Rectangle elementButton1 = { x, y, 100, 100 };
		bool isHovering = CheckCollisionPointRec(GetMousePosition(), elementButton1);
		if (isHovering) {
			DrawTextureRec(nonmetalsButtonsHover, elementFrame, { x, y }, WHITE);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				addElement(coordinates);
			}
		}
		else {
			DrawTextureRec(nonmetals, elementFrame, { x, y }, WHITE);
		}

	}

}

void displayCalculatorButtons(Texture2D calculatorButtons, Texture2D calculatorButtonsHover) {

	for (int i = 1; i <= 12; i++)
	{
		float specialWidth = 0;
		Vector2 coordinates = { 0, 0 };
		switch (i) {
		case 1:	specialWidth = (calculatorButtons.width / 12.1 + 1.1); coordinates = { 906, 389 }; break;
		case 2:	specialWidth = (calculatorButtons.width / 12.1 + 1.1); coordinates = { 1024, 389 }; break;
		case 3: specialWidth = (calculatorButtons.width / 12.1 + 0.9); coordinates = { 789, 469 }; break;
		case 4: specialWidth = (calculatorButtons.width / 12.1 + 0.9); coordinates = { 906, 469 }; break;
		case 5: specialWidth = (calculatorButtons.width / 12.1 + 1); coordinates = { 1025, 469 }; break;
		case 6: specialWidth = (calculatorButtons.width / 12.1 + 1); coordinates = { 789, 549 }; break;
		case 7: specialWidth = (calculatorButtons.width / 12.1 + 0.9); coordinates = { 906, 549 }; break;
		case 8: specialWidth = (calculatorButtons.width / 12.1 + 1); coordinates = { 1025, 549 }; break;
		case 9: specialWidth = (calculatorButtons.width / 12.1 + 0.9); coordinates = { 906, 629 }; break;
		case 10: specialWidth = (calculatorButtons.width / 12.1 + 0.9); coordinates = { 789, 629 }; break;
		case 11: specialWidth = (calculatorButtons.width / 12.1 + 0.8); coordinates = { 1024, 628 }; break;
		case 12: specialWidth = (calculatorButtons.width / 12.1 + 0.8); coordinates = { 789, 389 }; break;

		default: break;
		}
		Rectangle elementFrame = { i * specialWidth, 0, (float)(calculatorButtons.width / 12.1), (float)(calculatorButtons.height) };
		float x = coordinates.x;
		float y = coordinates.y;
		Rectangle elementButton1 = { x, y, 89, 59 };
		bool isHovering = CheckCollisionPointRec(GetMousePosition(), elementButton1);

		if (isHovering) {
			DrawTextureRec(calculatorButtonsHover, elementFrame, { x, y }, WHITE);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				addElement(coordinates);
			}
		}
		else {
			DrawTextureRec(calculatorButtons, elementFrame, { x, y }, WHITE);
		}

	}
}

void displayEquationButtons(Texture2D equationButtons, Texture2D equationButtonsHover) {
	Rectangle elementFrame1 = { 3 * (equationButtons.width / 3 + 0.9), 0, (float)(equationButtons.width / 3.1), (float)(equationButtons.height) };
	Rectangle elementFrame2 = { 1 * (equationButtons.width / 3.1 + 4), 0, (float)(equationButtons.width / 3.1), (float)(equationButtons.height) };
	Rectangle elementFrame3 = { 2 * (equationButtons.width / 3.1 + 3.8), 0, (float)(equationButtons.width / 3.1), (float)(equationButtons.height) };
	Rectangle elementButton1 = { 910, 721, 89, 59 };
	Rectangle elementButton2 = { 908, 803, 89, 59 };
	Rectangle elementButton3 = { 1589, 182, 89, 59 };
	bool isHovering = CheckCollisionPointRec(GetMousePosition(), elementButton1);
	if (isHovering) {
		DrawTextureRec(equationButtonsHover, elementFrame1, { 911, 703 }, WHITE);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			addElement({ 911,703 });
		}
	}
	else {
		DrawTextureRec(equationButtons, elementFrame1, { 911, 703 }, WHITE);
	}
	isHovering = false;
	isHovering = CheckCollisionPointRec(GetMousePosition(), elementButton2);
	if (isHovering) {
		DrawTextureRec(equationButtonsHover, elementFrame2, { 909, 785 }, WHITE);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			addElement({ 909,785 });
		}
	}
	else {
		DrawTextureRec(equationButtons, elementFrame2, { 909, 785 }, WHITE);
	}
	isHovering = false;
	isHovering = CheckCollisionPointRec(GetMousePosition(), elementButton3);
	if (isHovering) {
		DrawTextureRec(equationButtonsHover, elementFrame3, { 1591, 164 }, WHITE);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			addElement({ 1591,164 });
		}
	}
	else {
		DrawTextureRec(equationButtons, elementFrame3, { 1591, 164 }, WHITE);
	}
}