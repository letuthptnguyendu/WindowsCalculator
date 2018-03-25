
///////////////////////////////////////////////////////////////////////////////
/////////////////////////        CHUYEN CO SO   ///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "QInt.h"
#include "bit_function.h"
#include <iostream>

using namespace std;

//to binary
string decToBin(QInt &dec);
string hexToBin(string hex);

//to decimal
QInt binToDec(string bin);
QInt hexToDec(string hex);

//to hex
char   changeToHexChar(string bin);
string changeHCharToBin(char hexCh);
string binToHex(string bin);
string decToHex(QInt dec);