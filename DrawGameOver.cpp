#include<cstdio>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<iostream>
#include "common.h"

using namespace std;

//(v2.0) 충돌 했을때 게임오버 그려줌
void DrawGameOver(const int score, const int leader_board[])
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
	cout << "===== L E A D E R B O A R D =====";
	for (int i = 0; i < 5; i++) {
		GoToXY(x, y + 9 + i);
		cout << "RANK " << i + 1 << " : " << leader_board[i];
	}
	cout << "\n\n\n\n\n\n";
	system("pause");
}