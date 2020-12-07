#include<cstdio>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<iostream>
#include "common.h"

using namespace std;

//나무를 그리는 함수
void DrawTree(int treeX)
{
	GoToXY(treeX, TREE_BOTTOM_Y);
	cout << "$$$$";
	GoToXY(treeX, TREE_BOTTOM_Y + 1);
	cout << " $$ ";
	GoToXY(treeX, TREE_BOTTOM_Y + 2);
	cout << " $$ ";
	GoToXY(treeX, TREE_BOTTOM_Y + 3);
	cout << " $$ ";
	GoToXY(treeX, TREE_BOTTOM_Y + 4);
	cout << " $$ ";
}