

#include "stdafx.h"

#include "bit_function.h"


string str_unsigned_divideBy2(string uns_num) {
	int remem = 0;
	string result;

	int length = uns_num.length();

	//toi uu
	if (length <= 9) {
		int result = stoi(uns_num) / 2;
		return to_string(result);
	}

	//initialize remember variable
	if (charToNumber(uns_num[0]) < 2) {
		remem = charToNumber(uns_num[0]);
		uns_num = uns_num.substr(1, length - 1);
		length--;
	}

	while (length > 0)
	{
		remem = remem * 10 + charToNumber(uns_num[0]);
		result += to_string(remem / 2);
		remem = remem % 2;
		uns_num = uns_num.substr(1, length - 1);
		length--;
	}

	return result;
}

string str_unsigned_multiplyBy2(string uns_num) {
	string result;
	int remem = 0;

	int length = uns_num.length();
	//toi uu
	if (length < 9) {
		int result = stoi(uns_num) * 2;
		return to_string(result);
	}

	while (length > 0)
	{
		remem = remem + charToNumber(uns_num[length - 1]) * 2;
		result = to_string(remem % 10) + result;
		remem = remem / 10;
		uns_num = uns_num.substr(0, length - 1);
		length--;
	}

	if (remem != 0) {
		result = to_string(remem) + result;
	}

	return result;
}

string str_unsigned_addTwoString(string uns_num1, string uns_num2) {
	string result;
	int remem = 0;

	int length1 = uns_num1.length();
	int length2 = uns_num2.length();
	int maxLength = (length1 > length2) ? length1 : length2;

	if (maxLength < 9) {
		int result = stoi(uns_num1) + stoi(uns_num2);
		return to_string(result);
	}

	while (maxLength > 0)
	{
		if (uns_num1 == "") {
			remem = remem + charToNumber(uns_num2[maxLength - 1]);
			result = to_string(remem % 10) + result;
			remem = remem / 10;
			uns_num2 = uns_num2.substr(0, maxLength - 1);
			maxLength--;
		}
		else if (uns_num2 == "") {
			remem = remem + charToNumber(uns_num1[maxLength - 1]);
			result = to_string(remem % 10) + result;
			remem = remem / 10;
			uns_num1 = uns_num1.substr(0, maxLength - 1);
			maxLength--;
		}
		else {
			remem = remem + charToNumber(uns_num1[length1 - 1]) + charToNumber(uns_num2[length2 - 1]);
			result = to_string(remem % 10) + result;
			remem = remem / 10;
			uns_num1 = uns_num1.substr(0, length1 - 1);
			uns_num2 = uns_num2.substr(0, length2 - 1);
			maxLength--;
			length1--;
			length2--;
		}
	}

	if (remem != 0) {
		result = to_string(remem) + result;
	}

	return result;
}


bool gotBitIs1(string src) {
	return (charToNumber(src[src.length() - 1]) % 2) == 1;
}

int countBit_unsInt(string uns_num) {
	int result = 0;
	while (uns_num != "0") {
		result++;
		uns_num = str_unsigned_divideBy2(uns_num);
	}

	return result;
}


string pow_2_n(int n) {
	if (n <= 30) {
		return to_string((int)(pow(2, n)));
	}
	else {
		string subResult = to_string((int)(pow(2, 30)));;
		for (int i = 31; i <= n; i++) {
			subResult = str_unsigned_multiplyBy2(subResult);
		}
		return subResult;
	}
}