#include<cstdio>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<iostream>
#include "common.h"

using namespace std;

//나무를 그리는 함수
void DrawTree(int tree_x)
{
	GoToXY(tree_x, TREE_BOTTOM_Y);
	cout << "$$$$";
	GoToXY(tree_x, TREE_BOTTOM_Y + 1);
	cout << " $$ ";
	GoToXY(tree_x, TREE_BOTTOM_Y + 2);
	cout << " $$ ";
	GoToXY(tree_x, TREE_BOTTOM_Y + 3);
	cout << " $$ ";
	GoToXY(tree_x, TREE_BOTTOM_Y + 4);
	cout << " $$ ";
}