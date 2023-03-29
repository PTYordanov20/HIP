#include "calculator.h"

void displayCalculate(Texture2D CalcBackground) {
	DrawTextureEx(CalcBackground, { 0, 0 }, 0, 1, WHITE);
}

void displayElements(Texture2D metals, Texture2D nonmetals) {
	Rectangle elementFrame1 = { (float)(metals.width / 9.1), 0, (float)(metals.width / 9.1), (float)(metals.height) };
	DrawTextureRec(metals, elementFrame1, { 79, 439 }, WHITE);
	Rectangle elementFrame2 = { 2 * (float)(metals.width / 9.1), 0, (float)(metals.width / 9.1), (float)(metals.height) };
	DrawTextureRec(metals, elementFrame2, { 215, 439 }, WHITE);
	Rectangle elementFrame3 = { 3 * (float)(metals.width / 9.1), 0, (float)(metals.width / 9.1), (float)(metals.height) };
	DrawTextureRec(metals, elementFrame3, { 79, 584 }, WHITE);
	Rectangle elementFrame4 = { 4 * (float)(metals.width / 9 -0.1), 0, (float)(metals.width / 9.1), (float)(metals.height) };
	DrawTextureRec(metals, elementFrame4, { 215.5, 584 }, WHITE);
	Rectangle elementFrame5 = { 5 * (float)(metals.width / 9), 0, (float)(metals.width / 9.1), (float)(metals.height) };
	DrawTextureRec(metals, elementFrame5, { 353, 584 }, WHITE);
	Rectangle elementFrame6 = { 6 * (float)(metals.width / 9.1 + 1), 0, (float)(metals.width / 9.1), (float)(metals.height) };
	DrawTextureRec(metals, elementFrame6, { 491, 584 }, WHITE);
	Rectangle elementFrame7 = { 7 * (float)(metals.width / 9.1 + 1.2), 0, (float)(metals.width / 9.1), (float)(metals.height) };
	DrawTextureRec(metals, elementFrame7, { 354, 743 }, WHITE);
	Rectangle elementFrame8 = { 8 * (float)(metals.width / 9.1 +1.3), 0, (float)(metals.width / 9.1), (float)(metals.height) };
	DrawTextureRec(metals, elementFrame8, { 490, 743 }, WHITE);
	Rectangle elementFrame9 = { 9 * (float)(metals.width / 9.1 + 1.1), 0, (float)(metals.width / 9.1), (float)(metals.height) };
	DrawTextureRec(metals, elementFrame9, { 629, 742 }, WHITE);


	Rectangle elementFrame11 = {(float)(nonmetals.width / 9.1 + 0.1), 0, (float)(nonmetals.width / 9.1), (float)(nonmetals.height)};
	DrawTextureRec(nonmetals, elementFrame11, { 1719, 438 }, WHITE);
	Rectangle elementFrame12 = { 2 * (float)(nonmetals.width / 9.1 +0.1), 0, (float)(nonmetals.width / 9.1), (float)(nonmetals.height) };
	DrawTextureRec(nonmetals, elementFrame12, { 1582, 438 }, WHITE);
	Rectangle elementFrame13 = { 3 * (float)(nonmetals.width / 9.1 + 1), 0, (float)(nonmetals.width / 9.1), (float)(nonmetals.height) };
	DrawTextureRec(nonmetals, elementFrame13, { 1718, 583 }, WHITE);
	Rectangle elementFrame14 = { 4 * (float)(nonmetals.width / 9 + 1), 0, (float)(nonmetals.width / 9.1), (float)(nonmetals.height) };
	DrawTextureRec(nonmetals, elementFrame14, { 1582, 583 }, WHITE);
	Rectangle elementFrame15 = { 5 * (float)(nonmetals.width / 9.1 + 1), 0, (float)(nonmetals.width / 9.1), (float)(nonmetals.height) };
	DrawTextureRec(nonmetals, elementFrame15, { 1444, 583 }, WHITE);
	Rectangle elementFrame16 = { 6 * (float)(nonmetals.width / 9.1 + 1.3), 0, (float)(nonmetals.width / 9.1), (float)(nonmetals.height) };
	DrawTextureRec(nonmetals, elementFrame16, { 1308, 584 }, WHITE);
	Rectangle elementFrame17 = { 7 * (float)(nonmetals.width / 9.1 + 1.3), 0, (float)(nonmetals.width / 9.1), (float)(nonmetals.height) };
	DrawTextureRec(nonmetals, elementFrame17, { 1445, 743 }, WHITE);
	Rectangle elementFrame18 = { 8 * (float)(nonmetals.width / 9.1 + 1.2), 0, (float)(nonmetals.width / 9.1), (float)(nonmetals.height) };
	DrawTextureRec(nonmetals, elementFrame18, { 1308, 743 }, WHITE);
	Rectangle elementFrame19 = { 9 * (float)(nonmetals.width / 9.1 + 1.1), 0, (float)(nonmetals.width / 9.1), (float)(nonmetals.height) };
	DrawTextureRec(nonmetals, elementFrame19, { 1172, 742 }, WHITE);

}
