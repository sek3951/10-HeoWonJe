#include <iostream>
#include <cstdio>
#include <string>
#include "common.h"

using namespace std;

void  UserName(int num){
	string user_name;
	cout << "What is your name? : ";
	cin >> user_name;
	cout << "Your name is : " << user_name << endl;
}
