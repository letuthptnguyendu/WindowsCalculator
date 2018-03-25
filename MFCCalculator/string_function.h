#pragma once

#include "define_const.h"
#include <climits>
using namespace std;


//divide a unsigned int string by 2
string str_unsigned_divideBy2(string uns_num);

//multiply a unsigned int string by 2
string str_unsigned_multiplyBy2(string uns_num);

//to ADD 2 UNSIGNED number => to caculate 2^K
string str_unsigned_addTwoString(string uns_num1, string uns_num2);

//use in countBit and decToBin
bool gotBitIs1(string src);
//count bit of unsigned int string
int countBit_unsInt(string uns_num);

//2^n of a unsigned int string
string pow_2_n(int n);