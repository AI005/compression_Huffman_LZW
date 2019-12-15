#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
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
	int     nBit;
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
	void Init();
	void InitFrequences(string filename); // thống kê tần số xuất hiện
	void PrintFrequences(); // xuất ra tần số các kí tự
	bool FindPairOfMin(int& i, int& j, int _nNode); // tìm cặp phần tử min
	int makeHuffmanTree(); // tạo cây huffman
	void PrintHuffmanTree(int node, int tab); // xuất cây huffman
	void TraversingHuffmanTree(int node, char TableBit[], int nTableBit); // duyệt cây huffman
	void generalBitCode(int nRoot); // phát sinh mã bit
	void PrintTableBitCode(); // in ra bảng mã bit
	void PrintByte(unsigned char out, int nValidBit); // Xuất byte
	void WriteStatisticalTable(fstream& fwrite); //ghi bảng thống kê
	void encode_a_char(fstream& fwrite, unsigned char c, unsigned char& out, unsigned char& posBit); // mã hóa 1 kí tự
	void encode(string FilenameInput, string FilenameOutput); // nén
	void LoadHuffmanTree(fstream& fpread); // xây dựng lại cây huffman từ file
	int CountChar(); // đếm số kí tự
	int getBit(unsigned char n, int i); // lấy bit
	void onBit(char unsigned& n, int i); //bật bit
	void Decompress(int nRoot, fstream& fpread); //giải nén

};