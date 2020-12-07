#include<cstdio>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<iostream>
#include "common.h"

using namespace std;

//공룡을 그리는 함수
void DrawDino(int dinoY)
{
	GoToXY(0, dinoY);
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