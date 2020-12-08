//[C/C++ game] very simple google dinosaur. (by. BlockDMask)
//2019.12.03 (v2.0)���� �߰�, �浹ó�� �߰�.
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
	
	while (true)		//(v2.0) ���� ����
	{
		//���� ���۽� �ʱ�ȭ
		/*bool is_jumping = false;
		bool is_bottom = true;
		int is_crowd = 0;*/
		Status dinosour;
		dinosour.StatusInit();
		int input = 0;
		

		Where them;
		them.WhereInit();
		srand(time(NULL));
		int bird_or_tree = rand() % 2;
		int score = 0;
		clock_t start, curr;	//���� ���� �ʱ�ȭ
		start = clock();		//���۽ð� �ʱ�ȭ

		while (true)	//�� �ǿ� ���� ����
		{
			//(v2.0) �浹üũ Ʈ���� x���� ������ y������ �Ǵ�
			if (!bird_or_tree) {
				if (IsBirdCollision(them.GetBirdX(), them.GetDinoY(), dinosour.GetIsCrowd()))
					break;
			}
			else {
				if (IsTreeCollision(them.GetTreeX(), them.GetDinoY()))
					break;
			}

			//zŰ�� ���Ȱ�, �ٴ��� �ƴҶ� ����
			
			if ((input = GetKeyDown())  && dinosour.GetIsBottom())
			{
				if (input == 'z') {
					dinosour.SetIsJumping(true);
					dinosour.SetIsBottom(false);
				}
				else if(input == 'x')
					dinosour.SetIsCrowd(CROWD_TIME);
			}

			

			//�������̶�� Y�� ����, ������ �������� Y�� ����.
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


			//Y�� ����ؼ� �����ϴ°� �������� �ٴ��� ����.
			if (them.GetDinoY() >= DINO_BOTTOM_Y)
			{
				them.SetDinoY(DINO_BOTTOM_Y);
				dinosour.SetIsBottom(true);
			}

			//Y�� ����ؼ� �����ϴ� �� ���� ���� �ð��� ����
			

			//������ �������� (x����) �������ϰ�
			//������ ��ġ�� ���� �����ΰ��� �ٽ� ������ ������ ��ȯ.

			//������ ������ ������ ������ ���� ��Ȳ.
			if (them.GetDinoY() <= 3)
			{
				dinosour.SetIsJumping(false);
			}
			//3�ʰ� ������ �ٽ� �Ͼ
			

			if (!bird_or_tree) {
				them.BirdXMinus(2);
				if (them.GetBirdX() <= 0) {
					them.SetBirdX(BIRD_BOTTOM_X);
					srand(time(NULL));
					bird_or_tree = rand() % 2;
				}
			}
			else {
				them.TreeXMinus(2);
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
				DrawBird(them.GetBirdX());		//���� Ȥ�� ���� �������� ����
			else
				DrawTree(them.GetTreeX());
			//(v2.0)
			curr = clock();			//����ð� �޾ƿ���
			if (((curr - start) / CLOCKS_PER_SEC) >= 1)	// 1�ʰ� �Ѿ�����
			{
				score++;	//���ھ� UP
				start = clock();	//���۽ð� �ʱ�ȭ
			}
			Sleep(60);
			system("cls");	//clear

			//(v2.0) ��������� 1�ʸ��� ���ִ°��� �ƴ϶� �׻� ������ָ鼭, 1�ʰ� �������� ++ ���ݴϴ�.
			GoToXY(22, 0);	//Ŀ���� ��� �������� �ű��. �ܼ�â�� cols=100�̴ϱ� 2*x�̹Ƿ� 22���� �־���
			cout << "Score : " << score;	//���� �������.
		}

		//(v2.0) ���� ���� �޴�
		/*if (leader_board[4] < score) {
			leader_board[4] = score;
			int i = 3;
			int tmp;
			sort(leader_board, leader_board + 5,cmp);
		}*/
		DrawGameOver(score);
	}
	return 0;
}