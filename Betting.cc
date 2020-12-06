#include <iostream>
#include "common.h"
using namespace std;
void BeforeBetting(void)
{
	cout << "What is your choice?" << endl;
        cout << "1. Fold      2.Call      3.Raise" << endl;

}
void Betting(int *money,int *stake,int player, int choice)
{
	if(choice == 1)
		cout << "Player " << player << " die" << endl;
	else if(choice == 2){
		cout << "Player " << player << " choose Call"<< endl;
		*money = *money - *stake;
		cout << "Current stake is " << *stake << endl; 
	}
	else if(choice == 3){
		int raise_money;
		cout << "Player " << player << " choose Raise" << endl;
		cout << "How much you want to Raise?" << endl;
		cin >> raise_money;
		*stake = *stake + raise_money;
		cout << "Player " << player << " raise money " << raise_money << " more!" << endl;
		*money = *money - *stake;
		cout << "Current stake is " << *stake << endl;
	}
}
