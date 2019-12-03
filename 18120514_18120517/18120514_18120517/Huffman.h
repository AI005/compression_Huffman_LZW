#pragma once
#include "Node.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include  <deque>
using namespace std;


void Sort(vector<Node*>& lstNode);
class Huffman
{
private:
	Node* Tree;
	string content; // content of file you need to encode
	map<char, int> frequencies; 
	map<char, vector<bool>> codeTable;
public:
	void ReadFile(string f_name);
	void getFrequencies();
	void MakeTree();
	void build_lookup_table();
	Huffman();
	~Huffman();
};

