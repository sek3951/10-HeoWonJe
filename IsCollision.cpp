#include<cstdio>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<iostream>
#include "common.h"

using namespace std;

//(v2.0) �浹������ true, �ƴϸ� false
bool IsTreeCollision(const int tree_x, const int dino_y)
{
	//Ʈ���� X�� ������ ��ü�ʿ� ������,
	//������ ���̰� ������� �ʴٸ� �浹�� ó��
	GoToXY(0, 0);
	cout << "tree_x : " << tree_x << " dino_y : " << dino_y; //�̷������� ������ X, Y�� ã���ϴ�.
	if (tree_x <= 8 && tree_x >= 4 &&
		dino_y > 8)
	{
		return true;
	}
	return false;
}
bool IsBirdCollision(const int bird_x, const int dino_y, const int is_crowd)
{
	GoToXY(0, 0);
	cout << "bird_x : " << bird_x << " dino_y : " << dino_y;
	if (bird_x <= 10 && bird_x >= 6 &&
		!is_crowd)
	{
		return true;
	}
	return false;
}