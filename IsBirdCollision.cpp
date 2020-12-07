#include<iostream>
#include "common.h"

using namespace std;
bool IsBirdCollision(const int birdX, const int dinoY)
{
	GoToXY(0, 0);
	cout << "birdX : " << birdX << " dinoY : " << dinoY;
	if (birdX <= 10 && birdX >= 6 &&
		dinoY <= 15)
	{
		return true;
	}
	return false;
}