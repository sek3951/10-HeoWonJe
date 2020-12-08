//[C/C++ game] very simple google dinosaur. (by. BlockDMask)
//2019.12.03 (v2.0)점수 추가, 충돌처리 추가.
#include<cstdio>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<iostream>
#include "common.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

using namespace std;

int main()
{
	SetConsoleView();
	LeaderBoard lb;

	while (true)		//(v2.0) 게임 루프
	{
		//게임 시작시 초기화
		Status dinosour;
		Where them;
		int input = 0,level = 0;
		
		dinosour.StatusInit();
		them.WhereInit();

		srand(time(NULL));
		int bird_or_tree = rand() % 2;
		int score = 0;
		clock_t start, curr;	//점수 변수 초기화
		start = clock();		//시작시간 초기화

		while (true)	//한 판에 대한 루프
		{
			//(v2.0) 충돌체크 트리의 x값과 공룡의 y값으로 판단
			if (!bird_or_tree) {
				if (IsBirdCollision(them.GetBirdX(), them.GetDinoY(), dinosour.GetIsCrowd())) {
					PlaySound(TEXT("collisionsound.wav"), 0, SND_FILENAME | SND_ASYNC);
					break;
				}	
			}
			else {
				if (IsTreeCollision(them.GetTreeX(), them.GetDinoY())) {
					PlaySound(TEXT("collisionsound.wav"), 0, SND_FILENAME | SND_ASYNC);
					break;
				}	
			}

			//z키가 눌렸고, 바닥이 아닐때 점프
			
			if ((input = GetKeyDown())  && dinosour.GetIsBottom())
			{
				if (input == 'z') {
					dinosour.SetIsJumping(true);
					dinosour.SetIsBottom(false);
					PlaySound(TEXT("jumpsound.wav"), 0, SND_FILENAME | SND_ASYNC);
				}
				else if(input == 'x')
					dinosour.SetIsCrowd(CROWD_TIME - level);
			}

			

			//점프중이라면 Y를 감소, 점프가 끝났으면 Y를 증가.
			if (dinosour.GetIsJumping())
			{
				them.DinoYMinus(GRAVITY);
			}
			else
			{
				them.DinoYPlus(GRAVITY);
			}

			if (dinosour.GetIsCrowd())
				dinosour.SetIsCrowd(dinosour.GetIsCrowd()-1);


			//Y가 계속해서 증가하는걸 막기위해 바닥을 지정.
			if (them.GetDinoY() >= DINO_BOTTOM_Y)
			{
				them.SetDinoY(DINO_BOTTOM_Y);
				dinosour.SetIsBottom(true);
			}

			//Y가 계속해서 감소하는 걸 막기 위해 시간을 지정
			

			//나무가 왼쪽으로 (x음수) 가도록하고
			//나무의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환.

			//점프의 맨위를 찍으면 점프가 끝난 상황.
			if (them.GetDinoY() <= 3)
			{
				dinosour.SetIsJumping(false);
			}
			//3초가 지나면 다시 일어남
			

			if (!bird_or_tree) {
				them.BirdXMinus(2+level);
				if (them.GetBirdX() <= 0) {
					them.SetBirdX(BIRD_BOTTOM_X);
					srand(time(NULL));
					bird_or_tree = rand() % 2;
				}
			}
			else {
				them.TreeXMinus(2+level);
				if (them.GetTreeX() <= 0) {
					them.SetTreeX(TREE_BOTTOM_X);
					srand(time(NULL));
					bird_or_tree = rand() % 2;
				}
			}
			if (dinosour.GetIsCrowd())
				DrawDinoCrowd();
			else
				DrawDino(them.GetDinoY());		
			

			if (!bird_or_tree)
				DrawBird(them.GetBirdX());		//나무 혹은 새가 랜덤으로 등장
			else
				DrawTree(them.GetTreeX());
			//(v2.0)
			curr = clock();			//현재시간 받아오기
			if (((curr - start) / CLOCKS_PER_SEC) >= 1)	// 1초가 넘었을떄
			{
				score++;	//스코어 UP
				start = clock();	//시작시간 초기화
			}
			Sleep(60);
			system("cls");	//clear
			level = score / 10;

			//(v2.0) 점수출력을 1초마다 해주는것이 아니라 항상 출력해주면서, 1초가 지났을때 ++ 해줍니다.
			GoToXY(22, 0);	//커서를 가운데 위쪽으로 옮긴다. 콘솔창이 cols=100이니까 2*x이므로 22정도 넣어줌
			cout << "Score : " << score;	//점수 출력해줌.

			GoToXY(35, 0);
			cout << "Stage : " << level + 1;
		}

		//(v2.0) 게임 오버 메뉴

		DrawGameOver(score);
		lb.LeaderBoardPush(score);
		lb.LeaderBoardSort();
		lb.ShowLeaderBoard();
	}
	return 0;
}