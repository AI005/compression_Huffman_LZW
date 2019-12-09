#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Dictionary
{
public:
	vector<wstring> Table;
public:
	Dictionary();
	~Dictionary();
	void Init();
	int Find_Pos(wstring temp);
};