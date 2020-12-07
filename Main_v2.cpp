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
		clock_t start, curr;	//���� ���� �ʱ�ȭ
		start = clock();		//���۽ð� �ʱ�ȭ

		while (true)	//�� �ǿ� ���� ����
		{
			//(v2.0) �浹üũ Ʈ���� x���� ������ y������ �Ǵ�
			if (!bird_or_tree) {
				if (IsBirdCollision(bird_x, dino_y))
					break;
			}
			else {
				if (IsCollision(tree_x, dino_y))
					break;
			}

			//zŰ�� ���Ȱ�, �ٴ��� �ƴҶ� ����
			if (GetKeyDown() == 'z' && is_bottom)
			{
				is_jumping = true;
				is_bottom = false;
			}

			//�������̶�� Y�� ����, ������ �������� Y�� ����.
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


			//Y�� ����ؼ� �����ϴ°� �������� �ٴ��� ����.
			if (dino_y >= DINO_BOTTOM_Y)
			{
				dino_y = DINO_BOTTOM_Y;
				is_bottom = true;
			}

			//������ �������� (x����) �������ϰ�
			//������ ��ġ�� ���� �����ΰ��� �ٽ� ������ ������ ��ȯ.

			//������ ������ ������ ������ ���� ��Ȳ.
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
				DrawBird(bird_x);		//���� Ȥ�� ���� �������� ����
			else
				DrawTree(tree_x);
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
		DrawGameOver(score);
	}
	return 0;
}