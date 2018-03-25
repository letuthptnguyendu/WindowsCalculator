#pragma once

#include "define_const.h"

using namespace std;




unsigned int rotateBit(unsigned int &x, unsigned int moves);

void setBit1At(unsigned int &x, int i);//set bit 1 at position i

void toggleBit(unsigned int &x, int i);//toggle bit at position i

int getBitAt(unsigned int x, int i);

int charToNumber(char x);//get corresponding number of a character