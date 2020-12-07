#include<iostream>
#include "common.h"

using namespace std;
bool is_birdCollision(const int bird_x, const int dino_y)
{
	GoToXY(0, 0);
	cout << "bird_x : " << bird_x << " dino_y : " << dino_y;
	if (bird_x <= 10 && bird_x >= 6 &&
		dino_y <= 15)
	{
		return true;
	}
	return false;
}