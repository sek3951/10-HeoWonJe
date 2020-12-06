#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "common.h"

char* NumToCard(int num){
	int number;
	char card_number[1];
	char* card_shape=(char*)malloc(2);
	memset(card_shape,0,8);

	number = num%13;
	sprintf(card_number, "%d", number);
	if(number == 1)
		card_number[0] = 'A';
	else if(number == 10)
		card_number[0] = 'J';
	else if(number == 11)
		card_number[0] = 'Q';
	else if(number == 12)
		card_number[0] = 'K';

	if(num < 14){
		card_shape[0] = 'S';

	}
	else if((num >= 14) && (num < 27)){
		card_shape[0] = 'D';
	}
	else if((num >= 27) && (num < 40)){
		card_shape[0] = 'H';
	}
	else{
		card_shape[0] = 'C';
	}

	strcat(card_shape, card_number);

	return card_shape;
}
