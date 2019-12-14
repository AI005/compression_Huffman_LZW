#pragma once
#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Ascii_Dictionary
{
public:
	vector<string> Table;
public:
	Ascii_Dictionary();
	~Ascii_Dictionary();
	void Init();
	int Find_Pos(string temp);
};
