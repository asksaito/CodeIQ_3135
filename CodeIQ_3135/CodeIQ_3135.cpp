// CodeIQ_3135.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>
using namespace std;

string getPeriodicTableNumber(const string& input1, const string& input2);
int convertOffset(const string input);

int main()
{
	// 標準入力よりインプット取得
	string inputStr;
	getline(cin, inputStr);

	char delimiter = ',';
	size_t delimiterOfs = inputStr.find_first_of(delimiter);
	string input1 = inputStr.substr(0, delimiterOfs);
	string input2 = inputStr.substr(delimiterOfs + sizeof(delimiter));
	

	// 周期表の番号を取得する
	string result = getPeriodicTableNumber(input1, input2);

	// 結果
	std::stringstream stringstream;
	stringstream << result;

	// 標準出力へ結果出力
	cout << stringstream.str() << endl;
	return 0;
}

string getPeriodicTableNumber(const string& input1, const string& input2) {
	string table[10][18] = { 
		{ "1","-","-" ,"-" ,"-" ,"-" ,"-" ,"-" ,"-" ,"-" ,"-" ,"-" ,"-" ,"-" ,"-" ,"-" ,"-","2" },
		{ "3","4","-" ,"-" ,"-" ,"-" ,"-" ,"-" ,"-" ,"-" ,"-" ,"-","5" ,"6" ,"7" ,"8" ,"9" ,"10" },
		{ "11","12","-","-","-","-","-","-","-","-","-","-","13","14","15","16","17","18" },
		{ "19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36"},
		{ "37","38","39","40","41","42","43","44","45","46","47","48","49","50","51","52","53","54"},
		{ "55","56","L","72","73","74","75","76","77","78","79","80","81","82","83","84","85","86"},
		{ "87","88","A","104","105","106","107","108","109","110","111","112","113","114","115","116","117","118"},
		{ "119","120","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-"},
		{ "57","58","59","60","61","62","63","64","65","66","67","68","69","70","71","-","-","-"},
		{ "89","90","91","92","93","94","95","96","97","98","99","100","101","102","103","-","-","-"}
	};

	int col = convertOffset(input1);
	int row = convertOffset(input2);

	return table[col][row];
}

int convertOffset(const string input) {
	if (input == "L") {
		return 8;
	}
	else if (input == "A") {
		return 9;
	}
	else {
		return std::strtol(input.c_str(), 0, 10) - 1;
	}
}


