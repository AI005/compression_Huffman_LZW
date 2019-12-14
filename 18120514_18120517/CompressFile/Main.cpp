#include "LZW.h"

using namespace std;

int main()
{
	LZW lzw;

	cout
		<< "1. Nen va giai nen dang file unicode"
		<< "\n2. Nen va giai nen dang file ascii"
		<< "\nLua chon: ";
	int choose;
	cin >> choose;

	cout << "Nhap ten file ma ban muon nen: ";
	string infile_Name;
	cin.ignore();
	getline(cin, infile_Name);

	switch (choose)
	{
	case 1:
		lzw.Compression(infile_Name, "compressed.txt");
		lzw.Decompression("compressed.txt", "decompressed.txt");
		break;
	case 2:
		lzw.Ascii_Compression(infile_Name, "compressed.txt");
		lzw.Ascii_Decompression("compressed.txt", "decompressed.txt");
		break;
	}
	
	cout
		<< "Da nen va giai nen xong!"
		<< "\nTim file nen o compressed.txt"
		<< "\nTim file giai nen o decompressed.txt";

	system("pause");
}