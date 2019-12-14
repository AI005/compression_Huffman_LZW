#pragma once
#include <iostream>
using namespace std;
#include <string>

struct NODE
{
	unsigned char c;
	int freq;   // tần số xuất hiện
	bool used;  // Đánh dấu xem Node đã xử lí hay chưa
	int nLeft;  // số lượng nút con nằm bên trái
	int nRight; // số lượng nút con nằm bên phải
};

struct BITCODE 
{
	char* bits;
	int     soBit;
};

#define MAX_NODE        256*9
#define MAX_LENGTH_BIT  10
class Huffman
{
private:
	NODE huffTree[MAX_NODE];
	BITCODE TableBitCode[256];
	unsigned int nNode;
public:
	Huffman();
	~Huffman();
	void initFrequences(string filename); // thống kê tần số xuất hiện

}