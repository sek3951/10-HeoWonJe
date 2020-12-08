#include<cstdio>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<iostream>
#include "common.h"

using namespace std;
vector<int>leader_board;
//(v2.0) 충돌 했을때 게임오버 그려줌
void DrawGameOver(const int score)
{
	system("cls");
	int x = 16;
	int y = 3;
	int max = 0;
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
	leader_board.push_back(score);
	sort(leader_board.begin(),leader_board.end(),cmp);

	if (leader_board.size() > 5)
		max = 5;
	else
		max = leader_board.size();
	for (int i = 0; i < max; i++) {
		GoToXY(x, y + 9 + i);
		cout << "RANK " << i + 1 << " : " << leader_board[i];
	}
	cout << "\n\n\n\n\n\n";
	system("pause");
}