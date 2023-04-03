#include "main.h"

// displayed equation
string equationText = "";

// number of times element is used and its valence
int valence[18] = { 2, 1, 2, 1, 3, 2, 1, 3, 3, 2, 1, 3, 2, 2, 5, 2, 2, 4 };

// string
string product[18] = { "Mg", "Na", "Ca", "K", "Fe", "Cu", "Ag", "Au", "Al", "O", "H", "N", "S", "Cl", "P", "Br", "I", "C" };

// check for certain buttons
bool wasArrowClicked = false;
bool wasPlusClicked = false;

// save both elements
int element1 = -1, element2 = -1;

// balance values
int postCounts[7] = { 1, 1, 1, 1, 1, 1, 1 };

// greatest common divisor
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

// lowest common multiple
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

// display currently selected elements
void displayCalculate(Texture2D CalcBackground) {
	DrawTextureEx(CalcBackground, { 0, 0 }, 0, 1, WHITE);
}

// add elements to the text box
void addElement(Vector2 coordinates) {

	if (wasArrowClicked == false) {
		int clicked = -1;
		int numClicked = -1;

		// metals
		if (coordinates.x == 79 && coordinates.y == 439) { // Mg
			clicked = 0;
		}
		else if (coordinates.x == 215 && coordinates.y == 439) { // Na
			clicked = 1;
		}
		else if (coordinates.x == 79 && coordinates.y == 584) { // Ca
			clicked = 2;
		}
		else if (coordinates.x == 215.5 && coordinates.y == 584 ) { // K
			clicked = 3;
		}
		else if (coordinates.x == 353 && coordinates.y == 584) { // Fe
			clicked = 4;
		}
		else if (coordinates.x == 491 && coordinates.y == 584) { // Cu
			clicked = 5;
		}
		else if (coordinates.x == 354 && coordinates.y == 743) { // Ag
			clicked = 6;
		}
		else if (coordinates.x == 490 && coordinates.y == 743) { // Au
			clicked = 7;
		}
		else if (coordinates.x == 629 && coordinates.y == 742) { // Al
			clicked = 8;
		}

		// non metals
		else if (coordinates.x == 1718 && coordinates.y == 583) { // O
			clicked = 9;
		}
		else if (coordinates.x == 1719 && coordinates.y == 438) { // H
			clicked = 10;
		}
		else if (coordinates.x == 1582 && coordinates.y == 438) { // N
			clicked = 11;
		}
		else if (coordinates.x == 1582 && coordinates.y == 583) { // S
			clicked = 12;
		}
		else if (coordinates.x == 1444 && coordinates.y == 583) { // Cl
			clicked = 13;
		}
		else if (coordinates.x == 1308 && coordinates.y == 584) { // P
			clicked = 14;
		}
		else if (coordinates.x == 1445 && coordinates.y == 743) { // Br
			clicked = 15;
		}
		else if (coordinates.x == 1308 && coordinates.y == 743) { // I
			clicked = 16;
		}
		else if (coordinates.x == 1172 && coordinates.y == 742) { // C
			clicked = 17;
		}

		if (clicked != -1)
		{
			if (wasPlusClicked)
				element2 = clicked;
			else
				element1 = clicked;
		}
		else { // numbers
			if (coordinates.x == 789 && coordinates.y == 389) {
				numClicked = 1;
			}
			else if (coordinates.x == 906 && coordinates.y == 389) {
				numClicked = 2;
			}
			else if (coordinates.x == 1024 && coordinates.y == 389) {
				numClicked = 3;
			}
			else if (coordinates.x == 789 && coordinates.y == 469) {
				numClicked = 4;
			}
			else if (coordinates.x == 906 && coordinates.y == 469) {
				numClicked = 5;
			}
			else if (coordinates.x == 1025 && coordinates.y == 469) {
				numClicked = 6;
			}
			else if (coordinates.x == 789 && coordinates.y == 549) {
				numClicked = 7;
			}
			else if (coordinates.x == 906 && coordinates.y == 549) {
				numClicked = 8;
			}
			else if (coordinates.x == 1025 && coordinates.y == 549) {
				numClicked = 9;
			}
			if (numClicked != -1)
				if (wasPlusClicked)
					postCounts[3] = numClicked;
				else
					postCounts[1] = numClicked;
		}

		// plus and arrow
		if (element1 != -1) {
			if (coordinates.x == 911 && coordinates.y == 703) {
				wasPlusClicked = true;
			}
		}
		if (element2 != -1) {
			if (coordinates.x == 909 && coordinates.y == 785) {
				wasArrowClicked = true;
			}
		}

		// backspace
		if (coordinates.x == 1591 && coordinates.y == 164) {
			if (wasArrowClicked)		wasArrowClicked = false;
			else if (postCounts[3] > 1)		postCounts[3] = 1;
			else if (element2 != -1)	element2 = -1;
			else if (wasPlusClicked)	wasPlusClicked = false;
			else if (postCounts[1] > 1)		postCounts[1] = 1;
			else if (element1 != -1)	element1 = -1;
		}

		// generate string
		if (wasArrowClicked) {
			postCounts[5] = lcm(valence[element1], valence[element2]) / valence[element1];
			postCounts[6] = lcm(valence[element1], valence[element2]) / valence[element2];
			
			// 
			int c2 = lcm(postCounts[3], postCounts[6]);
			int c3 = c2 / postCounts[6];
			int c4 = lcm(c3 * postCounts[5], postCounts[1]);
			postCounts[0] = c4 / postCounts[1];
			postCounts[4] = c4 / postCounts[5];
			c3 = postCounts[4];
			int c5 = c3 * postCounts[6];
			postCounts[2] = c5 / postCounts[3];

		}

		equationText = "";
		if (postCounts[0] != 1) {
			equationText += to_string(postCounts[0]);
		}
		if (element1 != -1) {
			equationText += product[element1];
		}
		if (postCounts[1] != 1) {
			equationText += to_string(postCounts[1]);
		}
		if (wasPlusClicked) {
			equationText += " + ";
		}
		if (postCounts[2] != 1) {
			equationText += to_string(postCounts[2]);
		}
		if (element2 != -1) {
			equationText += product[element2];
		}
		if (postCounts[3] != 1) {
			equationText += to_string(postCounts[3]);
		}

		if (wasArrowClicked) {

			equationText += " -> ";

			if (postCounts[4] != 1)
				equationText += to_string(postCounts[4]);

			equationText += product[element1];

			if (postCounts[5] != 1)
				equationText += to_string(postCounts[5]);

			equationText += product[element2];

			if (postCounts[6] != 1)
				equationText += to_string(postCounts[6]);
		}

	}
}
void displayTextBox() {
	DrawText(equationText.c_str(), 400, 183, 70, BLACK);
	
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
	for (int i = 0; i < 7; i++) {
		postCounts[i] = 1;
	}

	wasArrowClicked = false;
	wasPlusClicked = false;
	
	element1 = -1;
	element2 = -1;
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