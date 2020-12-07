#include<iostream>
#include "common.h"
using namespace std;
void DrawBird(int birdX)
{
	GoToXY(birdX, Bird_BOTTOM_Y);
	cout << "       $$$";
	GoToXY(birdX, Bird_BOTTOM_Y + 1);
	cout << "<<$ $$$$$";
	GoToXY(birdX, Bird_BOTTOM_Y + 2);
	cout << "  $$$$$ ";
	GoToXY(birdX, Bird_BOTTOM_Y + 3);
	cout << "    $$$$$";
	GoToXY(birdX, Bird_BOTTOM_Y + 4);
	cout << "       $$$";

}