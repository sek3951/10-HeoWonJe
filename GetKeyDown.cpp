#include<cstdio>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<iostream>
#include "common.h"

//키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
int GetKeyDown()
{
	if (_kbhit() != 0)
	{
		return _getch();
	}
	return 0;
}