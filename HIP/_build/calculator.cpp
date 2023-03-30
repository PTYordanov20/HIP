#include "calculator.h"

void displayCalculate(Texture2D CalcBackground) {
	DrawTextureEx(CalcBackground, { 0, 0 }, 0, 1, WHITE);
}

void displayElements(Texture2D metals, Texture2D nonmetals, Texture2D metalsButtonsHover, Texture2D nonmetalsButtonsHover) {

	for (int i = 1; i <= 9; i++)
	{
		float specialWidth = 0;
		Vector2 coordinates = { 0, 0 };
		switch (i) {
			case 1:	specialWidth = (metals.width / 9.1); coordinates = { 79, 439 }; break;
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
		}
		else {
			DrawTextureRec(nonmetals, elementFrame, { x, y }, WHITE);
		}

	}
	
}


