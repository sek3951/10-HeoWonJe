//[C/C++ game] very simple google dinosaur. (by. BlockDMask)
//2019.12.03 (v2.0)점수 추가, 충돌처리 추가.
#include<cstdio>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<iostream>
#include "common.h"

using namespace std;

int main()
{
	SetConsoleView();

	while (true)		//(v2.0) 게임 루프
	{
		//게임 시작시 초기화
		bool is_jumping = false;
		bool is_bottom = true;
		bool is_crowd = false;
		const int gravity = 3;

		int dino_y = DINO_BOTTOM_Y;
		int tree_x = TREE_BOTTOM_X;
		int bird_x = BIRD_BOTTOM_X;
		srand(time(NULL));
		int bird_or_tree = rand() % 2;
		int score = 0;
		clock_t start, curr;	//점수 변수 초기화
		start = clock();		//시작시간 초기화

		while (true)	//한 판에 대한 루프
		{
			//(v2.0) 충돌체크 트리의 x값과 공룡의 y값으로 판단
			if (!bird_or_tree) {
				if (IsBirdCollision(bird_x, dino_y))
					break;
			}
			else {
				if (IsCollision(tree_x, dino_y))
					break;
			}

			//z키가 눌렸고, 바닥이 아닐때 점프
			if (GetKeyDown() == 'z' && is_bottom)
			{
				is_jumping = true;
				is_bottom = false;
			}

			//점프중이라면 Y를 감소, 점프가 끝났으면 Y를 증가.
			if (is_jumping)
			{
				dino_y -= gravity;
			}
			else
			{
				dino_y += gravity;
			}

			if (is_crowd) {
				
			}


			//Y가 계속해서 증가하는걸 막기위해 바닥을 지정.
			if (dino_y >= DINO_BOTTOM_Y)
			{
				dino_y = DINO_BOTTOM_Y;
				is_bottom = true;
			}

			//나무가 왼쪽으로 (x음수) 가도록하고
			//나무의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환.

			//점프의 맨위를 찍으면 점프가 끝난 상황.
			if (dino_y <= 3)
			{
				is_jumping = false;
			}
			if (!bird_or_tree) {
				bird_x -= 2;
				if (bird_x <= 0) {
					bird_x = TREE_BOTTOM_X;
					srand(time(NULL));
					bird_or_tree = rand() % 2;
				}
			}
			else {
				tree_x -= 2;
				if (tree_x <= 0) {
					tree_x = TREE_BOTTOM_X;
					srand(time(NULL));
					bird_or_tree = rand() % 2;
				}
			}
			DrawDino(dino_y);		
			if (!bird_or_tree)
				DrawBird(bird_x);		//나무 혹은 새가 랜덤으로 등장
			else
				DrawTree(tree_x);
			//(v2.0)
			curr = clock();			//현재시간 받아오기
			if (((curr - start) / CLOCKS_PER_SEC) >= 1)	// 1초가 넘었을떄
			{
				score++;	//스코어 UP
				start = clock();	//시작시간 초기화
			}
			Sleep(60);
			system("cls");	//clear

			//(v2.0) 점수출력을 1초마다 해주는것이 아니라 항상 출력해주면서, 1초가 지났을때 ++ 해줍니다.
			GoToXY(22, 0);	//커서를 가운데 위쪽으로 옮긴다. 콘솔창이 cols=100이니까 2*x이므로 22정도 넣어줌
			cout << "Score : " << score;	//점수 출력해줌.
		}

		//(v2.0) 게임 오버 메뉴
		DrawGameOver(score);
	}
	return 0;
}