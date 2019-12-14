#pragma once
#include "Dictionary.h"
#include "Non-unicode_Dictionary.h"
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
	vector <int> string_Compressed(const wstring &input, Dictionary &dic);
	void Compression(string inputFile, string outputFile);

	wstring string_Decompressed(const vector <int> &input, Dictionary &dic);
	void Decompression(string inputFile, string outputFile);



	vector <int> Ascii_string_Compressed(const string &input, Ascii_Dictionary &dic);
	void Ascii_Compression(string inputFile, string outputFile);

	string Ascii_string_Decompressed(const vector <int> &input, Ascii_Dictionary &dic);
	void Ascii_Decompression(string inputFile, string outputFile);

};