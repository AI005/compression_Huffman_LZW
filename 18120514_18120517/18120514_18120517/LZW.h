#pragma once
#include "Dictionary.h"
#include <locale>
#include <codecvt>
#include <fstream>
#include <io.h>
#include <fcntl.h>
#include <unordered_map>

class LZW
{	
public:
	LZW();
	~LZW();
	vector <int> string_Compressed(const wstring &input);
	void Compression(string inputFile, string outputFile);

	void Decompression(string inputFile, string outputFile);
	
};