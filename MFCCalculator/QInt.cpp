
#include "stdafx.h"

#include "QInt.h"


void scanQInt(string number, QInt &qInt) {
	qInt = { 0, 0, 0, 0 };
	bool isPositive = true;

	//count bit
	int count = countBit_unsInt(number);
	if (count > 128) { return; }

	//get sign
	if (!isdigit(number[0])) {
		if (number[0] == '+') { isPositive = true; }
		else { isPositive = false; }
		number = number.substr(1, number.length() - 1);
	}
	else { isPositive = true; }

	//set bit
	int i = 0;
	while (count > 0) {//highest[3] bit save sign
		if (gotBitIs1(number)) {
			setBit1At(qInt.data[i / INT_BIT_SIZE], i % INT_BIT_SIZE);
		}
		number = str_unsigned_divideBy2(number);
		count--;
		i++;
	}

	//if number is negative...
	if (!isPositive) {
		int i = 0;
		while (i < QINT_BIT_SIZE) {
			if (getBitAt(qInt.data[i / INT_BIT_SIZE], i % INT_BIT_SIZE) == 1) {//fst bit is 1...
				i++;
				while (i < QINT_BIT_SIZE) {//toggle the rest of bit to ending
					toggleBit(qInt.data[i / INT_BIT_SIZE], i%INT_BIT_SIZE);
					i++;
				}
			}
			i++;
		}
	}
}

string getValue(QInt qInt) {
	string result = "0";
	string sub_result = "0";

	//check sign of this number
	bool isPositive = true;
	if (getBitAt(qInt.data[3], INT_BIT_SIZE - 1) == 1) {
		isPositive = false;
	}

	//if number is negative turn it into original form
	if (!isPositive) {
		int i = 0;
		while (i < QINT_BIT_SIZE) {
			if (getBitAt(qInt.data[i / INT_BIT_SIZE], i % INT_BIT_SIZE) == 1) {//fst bit is 1...
				i++;
				while (i < QINT_BIT_SIZE) {//toggle the rest of bit to ending
					toggleBit(qInt.data[i / INT_BIT_SIZE], i%INT_BIT_SIZE);
					i++;
				}
			}
			i++;
		}
	}

	//get value
	for (int i = 0; i < QINT_BIT_SIZE; i++)
	{
		if (getBitAt(qInt.data[i / INT_BIT_SIZE], i % INT_BIT_SIZE) == 1) {
			sub_result = pow_2_n(i);
			result = str_unsigned_addTwoString(result, sub_result);
		}
	}

	//check sign
	if (!isPositive) { result = "-" + result; }
	return result;
}

void printQInt(QInt qInt) {
	string result = "0";
	string sub_result = "0";

	//check sign of this number
	bool isPositive = true;
	if (getBitAt(qInt.data[3], INT_BIT_SIZE - 1) == 1) {
		isPositive = false;
	}

	//if number is negative turn it into original form
	if (!isPositive) {
		int i = 0;
		while (i < QINT_BIT_SIZE) {
			if (getBitAt(qInt.data[i / INT_BIT_SIZE], i % INT_BIT_SIZE) == 1) {//fst bit is 1...
				i++;
				while (i < QINT_BIT_SIZE) {//toggle the rest of bit to ending
					toggleBit(qInt.data[i / INT_BIT_SIZE], i%INT_BIT_SIZE);
					i++;
				}
			}
			i++;
		}
	}

	//get value
	for (int i = 0; i < QINT_BIT_SIZE - 1; i++)
	{
		if (getBitAt(qInt.data[i / INT_BIT_SIZE], i % INT_BIT_SIZE) == 1) {
			sub_result = pow_2_n(i);
			result = str_unsigned_addTwoString(result, sub_result);
		}
	}

	//check sign
	if (!isPositive) { result = "-" + result; }
	cout << "result is: " << result << endl;
}

///////////////////////////////////////////////////////////////////////////////
/////////////////////////        PHEP TOAN      ///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

QInt add2QInt(QInt num1, QInt num2) {
	QInt result;

	int i = 0;
	int remem = 0;
	while (i < QINT_BIT_SIZE) {
		int bit1 = getBitAt(num1.data[i / INT_BIT_SIZE], i%INT_BIT_SIZE);
		int bit2 = getBitAt(num2.data[i / INT_BIT_SIZE], i%INT_BIT_SIZE);
		if (bit1 == 1 && bit2 == 1) {
			if (remem == 1) { setBit1At(result.data[i / INT_BIT_SIZE], i % INT_BIT_SIZE); }
			else if (remem == 0) { remem = 1; }
		}
		else if (bit1 == 1 || bit2 == 1) {
			if (remem == 0) { setBit1At(result.data[i / INT_BIT_SIZE], i % INT_BIT_SIZE); }
		}
		else {
			if (remem == 1) {
				setBit1At(result.data[i / INT_BIT_SIZE], i % INT_BIT_SIZE);
				remem = 0;
			}
		}
		i++;
	}

	if ((getBitAt(num1.data[3], 31) == 1 && getBitAt(num2.data[3], 31) == 1 && getBitAt(result.data[3], 31) == 0)
		|| (getBitAt(num1.data[3], 31) == 0 && getBitAt(num2.data[3], 31) == 0 && getBitAt(result.data[3], 31) == 1))
	{
		//tran so return 0
		return { 0, 0, 0, 0 };
	}

	return result;
}

QInt subs2QInt(QInt num1, QInt num2) {
	string snum2 = getValue(num2);
	if (snum2[0] == '-') {
		snum2 = snum2.substr(1, snum2.length() - 1);
	}
	else {
		snum2 = '-' + snum2;
	}

	scanQInt(snum2, num2);
	QInt result = add2QInt(num1, num2);

	if ((getBitAt(num1.data[3], 31) == 1 && getBitAt(num2.data[3], 31) == 1 && getBitAt(result.data[3], 31) == 0)
		|| (getBitAt(num1.data[3], 31) == 0 && getBitAt(num2.data[3], 31) == 0 && getBitAt(result.data[3], 31) == 1))
	{
		//tran so return 0
		return { 0, 0, 0, 0 };
	}

	return result;
}

QInt mult2QInt(QInt Q, QInt M) {
	QInt A;

	QInt st_ = Q;
	int Q_1 = 0;

	for (int i = 0; i < QINT_BIT_SIZE; i++) {
		int bitcuoiQ = Q.data[0] & 1;

		if ((bitcuoiQ == 1 && Q_1 == 1) || (bitcuoiQ == 0 && Q_1 == 0)) {
			QInt temp = { 1, 0, 0, 0 };

			int lastA = A.data[0] & 1;

			//take advantage shrQInt :))
			A = shrQInt(A, temp);
			Q = shrQInt(Q, temp);

			if (lastA == 1) {
				Q.data[3] = Q.data[3] | (1 << 31);
			}
			if (lastA == 0) {
				if (((Q.data[3] >> 31) & 1) == 1) {
					Q.data[3] = Q.data[3] ^ (1 << 31);
				}
			}
		}
		else {
			if (bitcuoiQ == 1 && Q_1 == 0) {
				A = subs2QInt(A, M);
			}
			else if (bitcuoiQ == 0 && Q_1 == 1) {
				A = add2QInt(A, M);
			}

			QInt temp = { 1, 0, 0, 0 };
			int lastA = A.data[0] & 1;

			//take advantage shrQInt :))
			A = shrQInt(A, temp);
			Q = shrQInt(Q, temp);

			if (lastA == 1) {
				Q.data[3] = Q.data[3] | (1 << 31);
			}
			if (lastA == 0) {
				if (((Q.data[3] >> 31) & 1) == 1) {
					Q.data[3] = Q.data[3] ^ (1 << 31);
				}
			}

			if (Q_1 == 0) Q_1 = 1;
			else Q_1 = 0;
		}
	}

	//overflow
	int temp1 = getBitAt(A.data[0], 0);
	for (int i = 1; i < QINT_BIT_SIZE; i++)
	{
		if (getBitAt(A.data[i / INT_BIT_SIZE], i % INT_BIT_SIZE) != temp1)
		{
			return { 0, 0, 0, 0 };//return 0;
		}
	}
	return Q;
}

QInt divid2QInt(QInt Q, QInt M) {
	int dem = 0;//"dem so dau am"
	QInt minus;
	scanQInt("-1", minus);

	//"chia khong dau"
	if (Q.data[3] >> 31 & 1 == 1) {

		Q = mult2QInt(Q, minus);
		dem++;
	}
	if (M.data[3] >> 31 & 1 == 1) {
		M = mult2QInt(M, minus);
		dem++;
	}

	QInt A = { 0, 0, 0, 0 };
	for (int i = 0; i < QINT_BIT_SIZE; i++) {
		int bitcuoiQ = (Q.data[3] >> 31) & 1;//bit cao nhat cung Q

		QInt one = { 1,0, 0, 0 };
		A = shlQInt(A, one);

		if (bitcuoiQ == 1) {
			A.data[0] = A.data[0] ^ 1;
		}

		Q = shlQInt(Q, one);


		A = A - M;

		if ((A.data[3] >> 31) & 1 == 1) {//A<0

			A = A + M;
		}
		else {
			int dauQ = Q.data[0] & 1;
			if (dauQ == 0) {
				Q.data[0] = Q.data[0] ^ 1;

			}
		}
	}

	if (dem % 2 == 1)
	{
		return mult2QInt(Q, minus);
	}
	return Q;
}


QInt and2QInt(QInt num1, QInt num2) {
	QInt result;
	for (int i = 0; i < INT_BIT_SIZE; i++) {
		if (getBitAt(num1.data[i / INT_BIT_SIZE], i % INT_BIT_SIZE) == 1
			&& getBitAt(num2.data[i / INT_BIT_SIZE], i % INT_BIT_SIZE) == 1) {
			setBit1At(result.data[i / INT_BIT_SIZE], i);
		}
	}

	return result;
}

QInt or2QInt(QInt num1, QInt num2) {
	QInt result;
	for (int i = 0; i < QINT_BIT_SIZE; i++) {
		if (getBitAt(num1.data[i / INT_BIT_SIZE], i % INT_BIT_SIZE) == 1
			|| getBitAt(num2.data[i / INT_BIT_SIZE], i % INT_BIT_SIZE) == 1) {
			setBit1At(result.data[i / INT_BIT_SIZE], i);
		}
	}

	return result;
}

QInt xor2QInt(QInt num1, QInt num2) {
	QInt result;
	for (int i = 0; i < QINT_BIT_SIZE; i++) {
		if (
			(getBitAt(num2.data[i / INT_BIT_SIZE], i % INT_BIT_SIZE) == 0
				&& getBitAt(num1.data[i / INT_BIT_SIZE], i % INT_BIT_SIZE) == 1)

			||
			(getBitAt(num2.data[i / INT_BIT_SIZE], i % INT_BIT_SIZE) == 1
				&& getBitAt(num1.data[i / INT_BIT_SIZE], i % INT_BIT_SIZE) == 0)
			)
		{
			setBit1At(result.data[i / INT_BIT_SIZE], i);
		}
	}

	return result;
}

QInt notQInt(QInt num) {
	QInt result;

	for (int i = 0; i < QINT_BIT_SIZE; i++) {
		if (getBitAt(num.data[i / INT_BIT_SIZE], i % INT_BIT_SIZE) == 0) {
			setBit1At(result.data[i / INT_BIT_SIZE], i);
		}
	}

	return result;
}


QInt shlQInt(QInt num1, QInt num2) {
	QInt result;

	if (num2.data[1] != 0 || num2.data[2] != 0 || num2.data[3] != 0 || num2.data[0] > QINT_BIT_SIZE) {
		return result;//0
	}

	for (int i = QINT_BIT_SIZE - 1; i >= num2.data[0]; i--) {
		int j = i - num2.data[0];
		if (getBitAt(num1.data[j / INT_BIT_SIZE], j % INT_BIT_SIZE) == 1) {
			setBit1At(result.data[i / INT_BIT_SIZE], i);
		}
	}

	return result;
}

QInt shrQInt(QInt num1, QInt num2) {
	QInt result;

	bool isPositive = true;

	//sign
	if (getBitAt(num1.data[3], INT_BIT_SIZE - 1) == 1) {
		isPositive = false;
	}

	if (num2.data[1] != 0 || num2.data[2] != 0 || num2.data[3] != 0 || num2.data[0] > QINT_BIT_SIZE) {
		if (isPositive) { return result; }//0
		else {
			scanQInt("-1", result);
			return result;
		}
	}

	for (int i = 0; i < QINT_BIT_SIZE - num2.data[0]; i++) {
		int j = i + num2.data[0];
		if (((num1.data[j / INT_BIT_SIZE] >> (j % INT_BIT_SIZE)) & 1) == 1) {
			setBit1At(result.data[i / INT_BIT_SIZE], i);
		}
	}

	for (int i = QINT_BIT_SIZE - num2.data[0]; i < QINT_BIT_SIZE; i++) {//set the rest bit
		if (!isPositive) {
			setBit1At(result.data[i / INT_BIT_SIZE], i);
		}
	}

	return result;
}




QInt operator+(QInt &x, QInt &y) {
	return add2QInt(x, y);
}

QInt operator-(QInt &x, QInt &y) {
	return subs2QInt(x, y);
}

QInt operator*(QInt &x, QInt &y) {
	return mult2QInt(x, y);
}

QInt operator/(QInt &x, QInt &y) {
	return divid2QInt(x, y);
}

QInt operator&(QInt &x, QInt &y) {
	return and2QInt(x, y);
}
QInt operator|(QInt &x, QInt &y) {
	return or2QInt(x, y);
}
QInt operator^(QInt &x, QInt &y) {
	return xor2QInt(x, y);
}
QInt operator!(QInt &x) {
	return notQInt(x);
}
QInt operator>>(QInt &x, QInt &y) {
	return shrQInt(x, y);
}
QInt operator<<(QInt &x, QInt &y) {
	return shlQInt(x, y);
}