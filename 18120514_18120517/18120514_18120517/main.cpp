#include "LZW.h"

using namespace std;



int main()
{
	LZW lzw;
	lzw.Compression("input.txt", "compressed.dat");
	lzw.Decompression("compressed.dat", "decompressed.txt");
	//setlocale(LC_ALL, "vi_VN.UTF-8");
	//_setmode(_fileno(stdout), _O_U8TEXT);
	//wcout << L'\u1EAD' << endl;
	
	

	

	system("pause");
}
