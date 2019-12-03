#include "Huffman.h"
int main()
{
	Huffman H;
	int select;
	cout
		<< "\nCHOOSE OPTION"
		<< "\n1. encode"
		<< "\n2. decode"
		<< "\n3. Exit"
		<< "\nSelect: ";    cin >> select;

	if (select == 3)    return 0;

	if (select == 1) 
	{
		cin.ignore(256, '\n');
		string filename;
		cout << "\ninput name's file: ";
		getline(cin, filename);
		H.ReadFile(filename);
		H.getFrequencies();
	}
	else if (select == 2)
	{

	}
	cout << endl;    system("pause");    return 0;
}