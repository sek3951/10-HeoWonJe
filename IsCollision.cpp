#include<cstdio>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<iostream>
#include "common.h"

using namespace std;

//(v2.0) �浹������ true, �ƴϸ� false
bool IsCollision(const int treeX, const int dinoY)
{
	//Ʈ���� X�� ������ ��ü�ʿ� ������,
	//������ ���̰� ������� �ʴٸ� �浹�� ó��
	GoToXY(0, 0);
	cout << "treeX : " << treeX << " dinoY : " << dinoY; //�̷������� ������ X, Y�� ã���ϴ�.
	if (treeX <= 8 && treeX >= 4 &&
		dinoY > 8)
	{
		return true;
	}
	return false;
}