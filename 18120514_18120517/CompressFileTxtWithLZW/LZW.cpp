#include "LZW.h"

LZW::LZW()
{	
}

LZW::~LZW()
{
}

vector<int> LZW::string_Compressed(const wstring & input, Dictionary &dic)
{

	wstring p = L"", c = L"";
	p += input[0];

	vector<int> output_code;

	for (int i = 0; i < input.length(); i++) {
		if (i != input.length() - 1)
			c += input[i + 1];
		if (dic.Find_Pos(p + c) != -1) {
			p = p + c;
		}
		else {
			output_code.push_back(dic.Find_Pos(p));
	
			dic.Table.push_back(p + c);
			p = c;
		}
		c = L"";
	}

	output_code.push_back(dic.Find_Pos(p));

	return output_code;

}

void LZW::Compression(string inputFile, string outputFile)
{
	static const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());

	wifstream fin(inputFile, ios::binary);
	
	if (fin.fail())
	{
		cout << "Failed when openning files!" << endl;
		return;
	}

	fin.imbue(utf8_locale);
	
	ofstream fout(outputFile, ios::binary);

	Dictionary dic;
	dic.Init();

	wstring temp;
	vector <int> test;

	while (getline(fin, temp))
	{
		test = string_Compressed(temp, dic);
	
		for (int i = 0; i < test.size(); i++)
			fout.write((char*)&test[i], sizeof(test[i]));
	}

	
	fin.close();
	fout.close();
}

wstring LZW::string_Decompressed(const vector<int>& input, Dictionary & dic)
{
	wstring output_string;

	int old;
	old = input[0];
	int n;
	wstring s = dic.Table[old];
	wstring c = L"";

	c += s[0];
	output_string += s;

	for (int i = 1; i < input.size(); i++)
	{
		n = input[i];

		if (n >= dic.Table.size())
		{
			s = dic.Table[old];
			s = s + c;
		}
		else
			s = dic.Table[n];
		output_string += s;
		c = L"";
		c += s[0];

		dic.Table.push_back(dic.Table[old] + c);
		old = n;
	}

	return output_string;
}

void LZW::Decompression(string inputFile, string outputFile)
{
	static const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());

	ifstream fin(inputFile, ios::binary);

	if (fin.fail())
	{
		cout << "Failed when openning files!" << endl;
		return;
	}


	wofstream fout(outputFile, ios::binary);
	fout.imbue(utf8_locale);


	Dictionary dic;
	dic.Init();



	wstring test;
	vector <int> temp;
	int _temp;

	while (fin.read((char*)&_temp, sizeof(_temp)))
	{
		temp.push_back(_temp);
	}

		test = string_Decompressed(temp, dic);
		fout << test << endl;

		temp.clear();


	fin.close();
	fout.close();
}

vector<int> LZW::Ascii_string_Compressed(const string & input, Ascii_Dictionary & dic)
{
	string p = "", c = "";
	p += input[0];

	vector<int> output_code;

	for (int i = 0; i < input.length(); i++) {
		if (i != input.length() - 1)
			c += input[i + 1];
		if (dic.Find_Pos(p + c) != -1) {
			p = p + c;
		}
		else {
			output_code.push_back(dic.Find_Pos(p));

			dic.Table.push_back(p + c);
			p = c;
		}
		c = "";
	}

	output_code.push_back(dic.Find_Pos(p));

	return output_code;
}

void LZW::Ascii_Compression(string inputFile, string outputFile)
{
	ifstream fin(inputFile, ios::binary);

	if (fin.fail())
	{
		cout << "Failed when openning files!" << endl;
		return;
	}

	ofstream fout(outputFile, ios::binary);

	Ascii_Dictionary dic;
	dic.Init();

	string temp;
	vector <int> sub_output;

	while (getline(fin, temp))
	{
		sub_output = Ascii_string_Compressed(temp, dic);

		for (int i = 0; i < sub_output.size(); i++)
		{
			fout.write((char*)&sub_output[i], sizeof(sub_output[i]));
		}
	}


	fin.close();
	fout.close();
}

string LZW::Ascii_string_Decompressed(const vector<int>& input, Ascii_Dictionary & dic)
{
	string output_string = "";

	int old;
	old = input[0];
	int n;
	string s = dic.Table[old];
	string c = "";

	c += s[0];
	output_string += s;

	for (int i = 1; i < input.size(); i++)
	{
		n = input[i];

		if (n >= dic.Table.size())
		{
			s = dic.Table[old];
			s = s + c;
		}
		else
			s = dic.Table[n];
		output_string += s;
		c = "";
		c += s[0];

		dic.Table.push_back(dic.Table[old] + c);
		old = n;
	}

	return output_string;
}

void LZW::Ascii_Decompression(string inputFile, string outputFile)
{
	ifstream fin(inputFile, ios::binary);

	if (fin.fail())
	{
		cout << "Failed when openning files!" << endl;
		return;
	}

	ofstream fout(outputFile, ios::binary);


	Ascii_Dictionary dic;
	dic.Init();

	string sub_output;

	vector <int> temp;
	int _tempInput = 0;

	while (fin.read((char*)&_tempInput, sizeof(_tempInput)))
	{
		if (_tempInput < 0)
		{
			temp.push_back(256 + _tempInput);
		}
		else
		{
			temp.push_back(_tempInput);
		}
	}

	sub_output = Ascii_string_Decompressed(temp, dic);
	fout << sub_output;




	fin.close();
	fout.close();
}

