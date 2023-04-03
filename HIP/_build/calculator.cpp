#include "main.h"

char equationText[25];
int textIndex = 0;

char equationCalculation[25];
int equationCalculationIndex = 0;

// number of times element is used and its valence
int calculationLogic[18][18] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
								 {2, 1, 2, 1, 2, 2, 1, 3, 3, 2, 1, 3, 6, 2, 5, 2, 2, 4} };

// save last clicked element to add to it if needed
int* lastClickedElement;

// check for certain buttons
bool wasArrowClicked = false;
bool wasPlusClicked = false;

// display currently selected elements
void displayCalculate(Texture2D CalcBackground) {
	DrawTextureEx(CalcBackground, { 0, 0 }, 0, 1, WHITE);
}

// add elements to the text box
void addElement(Vector2 coordinates) {

	if (wasArrowClicked == false) {
		if (textIndex >= 25) {
			return;
		}
		
		// metals
		if (coordinates.x == 79 && coordinates.y == 439 && equationText[textIndex - 2] != 'M') {
			equationText[textIndex++] = 'M';
			equationText[textIndex++] = 'g';

			equationCalculation[equationCalculationIndex++] = 'M';
			equationCalculation[equationCalculationIndex++] = 'g';

			calculationLogic[0][0]++;
			lastClickedElement = &calculationLogic[0][0];
		}
		else if (coordinates.x == 215 && coordinates.y == 439 && equationText[textIndex - 2] != 'N' && equationText[textIndex - 1] != 'a') {
			equationText[textIndex++] = 'N';
			equationText[textIndex++] = 'a';

			equationCalculation[equationCalculationIndex++] = 'N';
			equationCalculation[equationCalculationIndex++] = 'a';

			calculationLogic[0][1]++;
			lastClickedElement = &calculationLogic[0][1];
		}
		else if (coordinates.x == 79 && coordinates.y == 584 && equationText[textIndex - 2] != 'C' && equationText[textIndex - 1] != 'a') {
			equationText[textIndex++] = 'C';
			equationText[textIndex++] = 'a';

			equationCalculation[equationCalculationIndex++] = 'C';
			equationCalculation[equationCalculationIndex++] = 'a';

			calculationLogic[0][2]++;
			lastClickedElement = &calculationLogic[0][2];
		}
		else if (coordinates.x == 215.5 && coordinates.y == 584 && equationText[textIndex - 1] != 'K') {
			equationText[textIndex++] = 'K';

			equationCalculation[equationCalculationIndex++] = 'K';

			calculationLogic[0][3]++;
			lastClickedElement = &calculationLogic[0][3];
		}
		else if (coordinates.x == 353 && coordinates.y == 584 && equationText[textIndex - 2] != 'F' && equationText[textIndex - 1] != 'e') {
			equationText[textIndex++] = 'F';
			equationText[textIndex++] = 'e';

			equationCalculation[equationCalculationIndex++] = 'F';
			equationCalculation[equationCalculationIndex++] = 'e';

			calculationLogic[0][4]++;
			lastClickedElement = &calculationLogic[0][4];
		}
		else if (coordinates.x == 491 && coordinates.y == 584 && equationText[textIndex - 2] != 'C' && equationText[textIndex - 1] != 'u') {
			equationText[textIndex++] = 'C';
			equationText[textIndex++] = 'u';

			equationCalculation[equationCalculationIndex++] = 'C';
			equationCalculation[equationCalculationIndex++] = 'u';

			calculationLogic[0][5]++;
			lastClickedElement = &calculationLogic[0][5];
		}
		else if (coordinates.x == 354 && coordinates.y == 743 && equationText[textIndex - 2] != 'A' && equationText[textIndex - 1] != 'g') {
			equationText[textIndex++] = 'A';
			equationText[textIndex++] = 'g';

			equationCalculation[equationCalculationIndex++] = 'A';
			equationCalculation[equationCalculationIndex++] = 'g';

			calculationLogic[0][6]++;
			lastClickedElement = &calculationLogic[0][6];
		}
		else if (coordinates.x == 490 && coordinates.y == 743 && equationText[textIndex - 2] != 'A' && equationText[textIndex - 1] != 'u') {
			equationText[textIndex++] = 'A';
			equationText[textIndex++] = 'u';

			equationCalculation[equationCalculationIndex++] = 'A';
			equationCalculation[equationCalculationIndex++] = 'u';

			calculationLogic[0][7]++;
			lastClickedElement = &calculationLogic[0][7];
		}
		else if (coordinates.x == 629 && coordinates.y == 742 && equationText[textIndex - 2] != 'A' && equationText[textIndex - 1] != 'l') {
			equationText[textIndex++] = 'A';
			equationText[textIndex++] = 'l';

			equationCalculation[equationCalculationIndex++] = 'A';
			equationCalculation[equationCalculationIndex++] = 'l';

			calculationLogic[0][8]++;
			lastClickedElement = &calculationLogic[0][8];
		}
		
		// non metals
		if (coordinates.x == 1718 && coordinates.y == 583 && equationText[textIndex - 1] != 'O') {
			equationText[textIndex++] = 'O';

			equationCalculation[equationCalculationIndex++] = 'O';

			calculationLogic[0][9]++;
			lastClickedElement = &calculationLogic[0][9];
		}
		else if (coordinates.x == 1719 && coordinates.y == 438 && equationText[textIndex - 1] != 'H') {
			equationText[textIndex++] = 'H';

			equationCalculation[equationCalculationIndex++] = 'H';

			calculationLogic[0][10]++;
			lastClickedElement = &calculationLogic[0][10];
		}
		else if (coordinates.x == 1582 && coordinates.y == 438 && equationText[textIndex - 1] != 'N') {
			equationText[textIndex++] = 'N';

			equationCalculation[equationCalculationIndex++] = 'N';

			calculationLogic[0][11]++;
			lastClickedElement = &calculationLogic[0][11];
		}
		else if (coordinates.x == 1582 && coordinates.y == 583 && equationText[textIndex - 1] != 'S') {
			equationText[textIndex++] = 'S';

			equationCalculation[equationCalculationIndex++] = 'S';

			calculationLogic[0][12]++;
			lastClickedElement = &calculationLogic[0][12];
		}
		else if (coordinates.x == 1444 && coordinates.y == 583 && equationText[textIndex - 2] != 'C' && equationText[textIndex - 1] != 'l') {
			equationText[textIndex++] = 'C';
			equationText[textIndex++] = 'l';

			equationCalculation[equationCalculationIndex++] = 'C';
			equationCalculation[equationCalculationIndex++] = 'l';

			calculationLogic[0][13]++;
			lastClickedElement = &calculationLogic[0][13];
		}
		else if (coordinates.x == 1308 && coordinates.y == 584 && equationText[textIndex - 1] != 'P') {
			equationText[textIndex++] = 'P';

			equationCalculation[equationCalculationIndex++] = 'P';

			calculationLogic[0][14]++;
			lastClickedElement = &calculationLogic[0][14];
		}
		else if (coordinates.x == 1445 && coordinates.y == 743 && equationText[textIndex - 2] != 'B' && equationText[textIndex - 1] != 'r') {
			equationText[textIndex++] = 'B';
			equationText[textIndex++] = 'r';

			equationCalculation[equationCalculationIndex++] = 'B';
			equationCalculation[equationCalculationIndex++] = 'r';

			calculationLogic[0][15]++;
			lastClickedElement = &calculationLogic[0][15];
		}
		else if (coordinates.x == 1308 && coordinates.y == 743 && equationText[textIndex - 1] != 'I') {
			equationText[textIndex++] = 'I';

			equationCalculation[equationCalculationIndex++] = 'I';

			calculationLogic[0][16]++;
			lastClickedElement = &calculationLogic[0][16];
		}
		else if (coordinates.x == 1172 && coordinates.y == 742 && equationText[textIndex - 1] != 'C') {
			equationText[textIndex++] = 'C';

			equationCalculation[equationCalculationIndex++] = 'C';

			calculationLogic[0][17]++;
			lastClickedElement = &calculationLogic[0][18];
		}

		switch (equationText[textIndex - 1]) {
			case 'g':
			case 'a':
			case 'e':
			case 'u':
			case 'l':
			case 'r':
			case 'K':
			case 'O':
			case 'H':
			case 'N':
			case 'S':
			case 'P':
			case 'I':
			case 'C':
				if (coordinates.x == 789 && coordinates.y == 389) {
					equationText[textIndex++] = '1';
				}
				else if (coordinates.x == 906 && coordinates.y == 389) {
					equationText[textIndex++] = '2';
					*lastClickedElement++;
				}
				else if (coordinates.x == 1024 && coordinates.y == 389) {
					equationText[textIndex++] = '3';
					*lastClickedElement += 2;
				}
				else if (coordinates.x == 789 && coordinates.y == 469) {
					equationText[textIndex++] = '4';
					*lastClickedElement += 3;
				}
				else if (coordinates.x == 906 && coordinates.y == 469) {
					equationText[textIndex++] = '5';
					*lastClickedElement += 4;
				}
				else if (coordinates.x == 1025 && coordinates.y == 469) {
					equationText[textIndex++] = '6';
					*lastClickedElement += 5;
				}
				else if (coordinates.x == 789 && coordinates.y == 549) {
					equationText[textIndex++] = '7';
					*lastClickedElement += 6;
				}
				else if (coordinates.x == 906 && coordinates.y == 549) {
					equationText[textIndex++] = '8';
					*lastClickedElement += 7;
				}
				else if (coordinates.x == 1025 && coordinates.y == 549) {
					equationText[textIndex++] = '9';
					*lastClickedElement += 8;
				}
				else if (coordinates.x == 906 && coordinates.y == 629) {
					equationText[textIndex++] = '0';
				}
				if (textIndex != 0 && equationText[textIndex - 1] != '+' && equationText[textIndex - 1] != '>') {
					if (coordinates.x == 789 && coordinates.y == 629) {
						equationText[textIndex++] = '(';
					}
					else if (coordinates.x == 1024 && coordinates.y == 628) {
						equationText[textIndex++] = ')';
					}
				}

				break;
			default:
				break;
		}
		if (textIndex != 0 && equationText[textIndex - 1] != '+' && equationText[textIndex - 1] != '>') {
			if (coordinates.x == 911 && coordinates.y == 703) {
				equationText[textIndex++] = '+';
				wasPlusClicked = true;
			}
			else if (coordinates.x == 909 && coordinates.y == 785) {
				equationText[textIndex++] = '-';
				equationText[textIndex++] = '>';
				wasArrowClicked = true;
			}
		}

		// Backspace button
		if (textIndex != 0 && equationText[textIndex - 1] != '>') {
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
						equationCalculationIndex--;
						for (int i = textIndex; i > textIndex - 2; i--) {
							equationText[i] = '\0';
							equationCalculation[i] = '\0';
						}
						textIndex--;
						equationCalculationIndex--;
					}
					else {
						textIndex = 0;
					}

					break;
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
				case '0':
				case '(':
				case ')':
				case '+':
					if (--textIndex < 0) {
						textIndex = 0;
					}
					else {
						equationText[textIndex] = '\0';
					}

					break;
				default:
					if (--textIndex < 0) {
						textIndex = 0;
					}
					else {
						equationText[textIndex] = '\0';
						equationCalculation[--equationCalculationIndex] = '\0';
					}

					break;
				}
			}
		}
	}
}
void displayTextBox() {
	DrawText(equationText, 400, 183, 70, BLACK);
	int x = 400 + (equationCalculationIndex) * 70;
	int y = 183;
	Rectangle calculateArrow = {903, 803, 89, 59};
	bool isHovering = CheckCollisionPointRec(GetMousePosition(), calculateArrow);
	
	if (wasArrowClicked) {
		for (int i = 0; i < equationCalculationIndex; i++) {
			equationText[i + textIndex] = equationCalculation[i];
		}
		DrawText(equationText, 400, 183, 70, BLACK);
	}
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

// delete equation from textbox
void deleteEquation() {
	for (int i = 0; i < textIndex; i++) {
		equationText[i] = '\0';
	}
	for (int i = 0; i < equationCalculationIndex; i++) {
		equationCalculation[i] = '\0';
	}
	textIndex = 0;
	equationCalculationIndex = 0;

	cout << "kfdjdasklfjadskljfksdjf";
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