


#include "stdafx.h"

#include "base.h"

///////////////////////////////////////////////////////////////////////////////
/////////////////////////        CHUYEN CO SO   ///////////////////////////////
///////////////////////////////////////////////////////////////////////////////
string decToBin(QInt &dec) {
	string result;

	//bring bit of Qint to a string
	for (int i = 0; i < QINT_BIT_SIZE; i++) {
		result += to_string(getBitAt(dec.data[i/INT_BIT_SIZE], i%INT_BIT_SIZE));
	}

	//reverse string
	reverse(result.begin(), result.end());

	//scratch out the '0's
	while (result[0] == '0') {
		result = result.substr(1, result.length());
	}

	return result;
}

string changeHCharToBin(char hexCh) {//must return 4 digits
	const int hex = 16;
	const int bit_hex = 4;

	char hex_ch[hex] = { '0', '1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	string result = "";
	int temp = 0;

	//get value of hexCh
	for (int i = 0; i < hex; i++) {
		if (hex_ch[i] == hexCh) {
			temp = i;
			break;
		}
	}

	//get corresponding bit string of hexCh
	for (int i = 0; i < bit_hex; i++) {
		if (temp % 2 == 0) {
			result = '0' + result;
		}
		else result = '1' + result;
		temp /= 2;
	}

	return result;
}
string hexToBin(string hex) {
	string result;

	int length = hex.length();

	//for each character in hex string, turn it into 4 bit
	for (int i = 0; i < length; i++) {
		result += changeHCharToBin(hex[i]);
	}

	return result;
}


QInt binToDec(string bin) {
	QInt result;

	int dem = 0;
	int length = bin.length();

	//"set bi tu cuoi toi dau, set theo thu tu"
	for (int i = length - 1; i >= 0; i--) {
		if (bin[i] == '1') {
			setBit1At(result.data[dem / INT_BIT_SIZE], dem % INT_BIT_SIZE);
		}
		dem++;
	}

	return result;
}

QInt hexToDec(string hex) {
	string bin = hexToBin(hex);
	return binToDec(bin);
}


char changeToHexChar(string bin) {//must have 4 digits
	char hex_ch[16] = { '0', '1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	int temp = 0; //to save value of bin

	for (int i = 0; i < 4; i++) {
		if (bin[i] == '1') {
			temp += (int)pow(2, 4 - i - 1);
		}
	}

	return hex_ch[temp];
}
string binToHex(string bin) {
	int length_bin = bin.length();
	string subresult;
	string result;

	//fill bin string with '0' for conversion
	if (length_bin % 4 != 0) {
		while (length_bin % 4 != 0) {
			bin = '0' + bin;
			length_bin++;
		}
	}

	for (int i = 0; i < length_bin; i++) {
		//get 4 bit
		subresult += bin[i];
		if ((i + 1) % 4 == 0) {
			result += changeToHexChar(subresult);
			subresult = "";
		}
	}

	return result;
}

string decToHex(QInt dec) {
	string bin = decToBin(dec);
	return binToHex(bin);
}
