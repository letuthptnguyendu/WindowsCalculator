#pragma once

#include "define_const.h"
#include "string_function.h"
#include "bit_function.h"

using namespace std;

struct QInt {
	unsigned int data[4] = { 0, 0, 0, 0 };
};

//input value to QInt
void scanQInt(string number, QInt &qInt);
//print the value of QInt
void printQInt(QInt qInt);
//return the value of QInt
string getValue(QInt qInt);

///////////////////////////////////////////////////////////////////////////////
/////////////////////////        OPERATOR      ///////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//set bit of signed and unsigned number to QInt
QInt add2QInt(QInt num1, QInt num2);
QInt subs2QInt(QInt num1, QInt num2);
QInt mult2QInt(QInt num1, QInt num2);
QInt divid2QInt(QInt num1, QInt num2);

//bit
QInt and2QInt(QInt num1, QInt num2);
QInt or2QInt(QInt num1, QInt num2);
QInt xor2QInt(QInt num1, QInt num2);
QInt notQInt(QInt num);
QInt shlQInt(QInt num1, QInt num2);
QInt shrQInt(QInt num1, QInt num2);

//operator
QInt operator+(QInt &x, QInt &y);
QInt operator-(QInt &x, QInt &y);
QInt operator*(QInt &x, QInt &y);
QInt operator/(QInt &x, QInt &y);

QInt operator&(QInt &x, QInt &y);
QInt operator|(QInt &x, QInt &y);
QInt operator^(QInt &x, QInt &y);
QInt operator!(QInt &x);
QInt operator>>(QInt &x, QInt &y);
QInt operator<<(QInt &x, QInt &y);