#include<iostream>
#include "common.h"
using namespace std;
void DrawBird(int bird_x)
{
	GoToXY(bird_x, Bird_BOTTOM_Y);
	cout << "       $$$";
	GoToXY(bird_x, Bird_BOTTOM_Y + 1);
	cout << "<<$ $$$$$";
	GoToXY(bird_x, Bird_BOTTOM_Y + 2);
	cout << "  $$$$$ ";
	GoToXY(bird_x, Bird_BOTTOM_Y + 3);
	cout << "    $$$$$";
	GoToXY(bird_x, Bird_BOTTOM_Y + 4);
	cout << "       $$$";

}