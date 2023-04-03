#pragma once
#include "main.h"

using namespace std;

void displayCalculate(Texture2D CalcBackground);

void displayElements(Texture2D metals, Texture2D nonmetals, Texture2D metalsButtonsHover, Texture2D nonmetalsButtonsHover);

void displayCalculatorButtons(Texture2D calculatorButtons, Texture2D calculatorButtonsHover);

void displayEquationButtons(Texture2D equationButtons, Texture2D equationButtonsHover);

void displayTextBox();

void deleteEquation();

int gcd(int a, int b);

int lcm(int a, int b);