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
void DrawBird(int bird_x)
{
	GoToXY(bird_x, Bird_BOTTOM_Y);
	cout << "       $$$";
	GoToXY(bird_x, Bird_BOTTOM_Y + 1);
	cout << "<<$ $$$$$";
	GoToXY(bird_x, Bird_BOTTOM_Y + 2);
	cout << "  $$$$$ ";
	GoToXY(bird_x, Bird_BOTTOM_Y + 3);
	cout << "    $$$$$";
	GoToXY(bird_x, Bird_BOTTOM_Y + 4);
	cout << "       $$$";

}
void DrawDino(int dino_y)
{
	GoToXY(0, dino_y);
	static bool legFlag = true;
	cout << "        $$$$$$$ \n";
	cout << "       $$ $$$$$$\n";
	cout << "       $$$$$$$$$\n";
	cout << "$      $$$      \n";
	cout << "$$     $$$$$$$  \n";
	cout << "$$$   $$$$$     \n";
	cout << " $$  $$$$$$$$$$ \n";
	cout << " $$$$$$$$$$$    \n";
	cout << "  $$$$$$$$$$    \n";
	cout << "    $$$$$$$$    \n";
	cout << "     $$$$$$     \n";
	if (legFlag)
	{
		cout << "     $    $$$    \n";
		cout << "     $$          ";
		legFlag = false;
	}
	else
	{
		cout << "     $$$  $     \n";
		cout << "          $$    ";
		legFlag = true;
	}
}
void DrawDinoCrowd()
{
	GoToXY(0, 16);
	static bool legFlag = true;
	cout << "                $$$$$$$ \n";
	cout << "$$      $$$$$  $$ $$$$$$\n";
	cout << "$$$$   $$$$$$$$$$$$$$$$$\n";
	cout << " $$$$$$$$$$$$$$$$$      \n";
	cout << "  $$$$$$$$$$$$  $$$$$$  \n";
	cout << "      $$$$$$$$          \n";
	cout << "       $$$$$$           \n";
	if (legFlag)
	{
		cout << "       $    $$$    \n";
		cout << "       $$          ";
		legFlag = false;
	}
	else
	{
		cout << "       $$$  $     \n";
		cout << "            $$    ";
		legFlag = true;
	}
}