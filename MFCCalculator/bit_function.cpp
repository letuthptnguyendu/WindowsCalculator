
#include "stdafx.h"

#include "bit_function.h"



unsigned int rotateBit(unsigned int &x, unsigned int moves)
{
	return (x >> moves) | (x << sizeof(int) * 8 - moves);
}

void setBit1At(unsigned int &x, int i) {
	x = x | (1 << i);
}

void toggleBit(unsigned int &x, int i) {
	x = x ^ (1 << i);
}

int getBitAt(unsigned int x, int i) {
	return (x >> i) & 1;
}


int charToNumber(char x) {
	return (int)x - CHAR_0;
}