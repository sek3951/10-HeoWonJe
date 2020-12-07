#include<cstdio>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<iostream>
#include "common.h"

using namespace std;

//(v2.0) 충돌 했을때 게임오버 그려줌
void DrawGameOver(const int score)
{
	system("cls");
	int x = 18;
	int y = 8;
	GoToXY(x, y);
	cout << "===========================";
	GoToXY(x, y + 1);
	cout << "======G A M E O V E R======";
	GoToXY(x, y + 2);
	cout << "===========================";
	GoToXY(x, y + 5);
	cout << "SCORE : " << score;

	cout << "\n\n\n\n\n\n\n\n\n";
	system("pause");
}