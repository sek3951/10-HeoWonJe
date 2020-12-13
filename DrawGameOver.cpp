#include<cstdio>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<iostream>
#include<queue>
#include "common.h"

using namespace std;

void DrawGameOver(const int score)
{
	system("cls");
	int x = 16;
	int y = 3;
	GoToXY(x, y);
	cout << "=================================";
	GoToXY(x, y + 1);
	cout << "======== G A M E O V E R ========";
	GoToXY(x, y + 2);
	cout << "=================================";
	GoToXY(x, y + 4);
	cout << "YOUR SCORE : " << score;
	GoToXY(x, y + 7);
}