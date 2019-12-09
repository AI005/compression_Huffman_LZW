#include "LZW.h"

LZW::LZW()
{	
}

LZW::~LZW()
{
}

vector<int> LZW::string_Compressed(const wstring & input)
{
	Dictionary dic;
	dic.Init();

	wstring p = L"", c = L"";
	p += input[0];

	vector<int> output_code;
//	cout << "String\tOutput_Code\tAddition\n";
	for (int i = 0; i < input.length(); i++) {
		if (i != input.length() - 1)
			c += input[i + 1];
		if (dic.Find_Pos(p + c) != -1) {
			p = p + c;
		}
		else {
//			cout << p << "\t" << table[p] << "\t\t"
//				<< p + c << "\t" << code << endl;
			output_code.push_back(dic.Find_Pos(p));
			dic.Table.push_back(p + c);
			p = c;
		}
		c = L"";
	}
//	cout << p << "\t" << table[p] << endl;
	output_code.push_back(dic.Find_Pos(p));
	return output_code;

}

void LZW::Compression(string inputFile, string outputFile)
{
	static const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());

	wifstream fin(inputFile);
	
	if (fin.fail())
	{
		cout << "Failed when openning files!" << endl;
		return;
	}

	fin.imbue(utf8_locale);
	
	wofstream fout(outputFile);
	fout.imbue(utf8_locale);

	wstring temp;
	vector <int> test;

	while (!fin.eof())
	{
		getline(fin, temp);
		test = string_Compressed(temp);

		for (int i = 0; i < test.size(); i++)
			fout << test[i] << " ";
	}


	fin.close();
	fout.close();
}

void LZW::Decompression(string inputFile, string outputFile)
{
	static const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());

	wifstream fin(inputFile);

	if (fin.fail())
	{
		cout << "Failed when openning files!" << endl;
		return;
	}

	fin.imbue(utf8_locale);

	wofstream fout(outputFile);
	fout.imbue(utf8_locale);

	vector <int> op;
	int temp;
	while (!fin.eof())
	{
		fin >> temp;
		op.push_back(temp);
	}


	Dictionary dic;
	dic.Init();

	int old = op[0], n;
	wstring s = dic.Table[old];
	wstring c = L"";
	c += s[0];
	fout << s;
	int count = dic.Table.size();
	for (int i = 0; i < op.size() - 1; i++) {
		n = op[i + 1];

		if (n > dic.Table.size()) {
			s = dic.Table[old];
			s = s + c;
		}
		else {
			s = dic.Table[n];
		}
		wcout << s;
		c = L"";
		c += s[0];
		dic.Table[count] = dic.Table[old] + c;
		count++;
		old = n;
	}


}


