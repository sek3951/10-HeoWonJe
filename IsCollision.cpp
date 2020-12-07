#include<cstdio>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<iostream>
#include "common.h"

using namespace std;

//(v2.0) 충돌했으면 true, 아니면 false
bool IsCollision(const int tree_x, const int dino_y)
{
	//트리의 X가 공룡의 몸체쪽에 있을때,
	//공룡의 높이가 충분하지 않다면 충돌로 처리
	GoToXY(0, 0);
	cout << "tree_x : " << tree_x << " dino_y : " << dino_y; //이런식으로 적절한 X, Y를 찾습니다.
	if (tree_x <= 8 && tree_x >= 4 &&
		dino_y > 8)
	{
		return true;
	}
	return false;
}