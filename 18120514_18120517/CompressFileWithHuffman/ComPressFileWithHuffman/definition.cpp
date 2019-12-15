#include "declare.h"

Huffman::Huffman()
{

}

void Huffman::Init()
{
	for (int i = 0; i < MAX_NODE; i++) {
		huffTree[i].c = i;
		huffTree[i].freq = 0;
		huffTree[i].used = false;
		huffTree[i].nLeft = -1;
		huffTree[i].nRight = -1;
	}
	nNode = 0;
}
Huffman::~Huffman()
{

}

void Huffman::InitFrequences(string filename)
{
	ifstream infile(filename, ios::binary);
	unsigned char c = 'a';
	while (true) {
		infile.read(reinterpret_cast<char*>(&c), sizeof(char));
		if (infile.eof())
			break;
		huffTree[c].freq++;
	}
	infile.close();
}

void Huffman::PrintFrequences()
{
	cout << "Bang thong ke tan suat:\n";
	for (int i = 0; i < 256; i++) {
		if (huffTree[i].freq > 0) {
			cout << (char)i << " " << huffTree[i].freq << endl;
			nNode++;
		}
	}
}

bool Huffman::FindPairOfMin(int& i, int& j, int _nNode)
{
	i = -1;
	j = -1;

	// tim 2 phan tu co trong so nho nhat
	for (int k = 0; k < nNode; k++)
		if (huffTree[k].used == false && huffTree[k].freq > 0) { // Ghi chú: Tại sao cần kiểm tra 2 điều kiện này
			if (i == -1) {
				i = k;
			}
			else if (j == -1) {
				j = k;
			}
			else {
				if (huffTree[i].freq > huffTree[j].freq) {
					if (huffTree[k].freq < huffTree[i].freq) {
						i = k;
					}
				}
				else {
					if (huffTree[k].freq < huffTree[j].freq) {
						j = k;
					}
				}
			}
		}
	// sap xep lai 2 phan tu de co i: phan tu co trong so nho nhat, j: phan tu co trong so nho nhi 
	// co 2 truong hop can doi i,j:
	// huffTree[i].freq > huffTree[j].freq
	// huffTree[i].freq == huffTree[j].freq va (huffTree[i].c > huffTree[j].c)
	if (i != -1 && j != -1) {
		if ((huffTree[i].freq > huffTree[j].freq) || ((huffTree[i].freq > huffTree[j].freq) && (huffTree[i].c > huffTree[j].c))) {
			int t = i;
			i = j;
			j = t;
		}
		return true;
	}
	else {
		return false;
	}
}

int  Huffman::makeHuffmanTree()
{
	int nNode = 256;
	int i, j;
	bool Flag = false;
	while (true) {

		// Gọi đệ quy tìm min
		Flag = FindPairOfMin(i, j, nNode);
		if (!Flag) {
			break;
		}

		// tìm tần suât min left và rigt
		huffTree[nNode].c = (huffTree[i].c < huffTree[j].c) ? huffTree[i].c : huffTree[j].c;
		huffTree[nNode].freq = huffTree[i].freq + huffTree[j].freq;
		huffTree[nNode].nLeft = i;
		huffTree[nNode].nRight = j;

		// Đánh xuất đã sử dụng
		huffTree[i].used = true;
		huffTree[j].used = true;

		// Đánh dấu chưa sử dụng
		huffTree[nNode].used = false;
		nNode++;

	}
	return nNode - 1; // trả về số lượng lá còn lại
}

void Huffman::PrintHuffmanTree(int node, int tab)
{
	if (node == -1) {
		return;
	}
	for (int i = 0; i < tab; i++) {
		cout << "\t";
	}

	if (huffTree[node].nLeft == -1 && huffTree[node].nRight == -1) {
		cout << huffTree[node].c << endl;
	}
	else {
		cout << huffTree[node].c << "..\n";
		PrintHuffmanTree(huffTree[node].nLeft, tab + 1);
		PrintHuffmanTree(huffTree[node].nRight, tab + 1);
	}
}

void Huffman::TraversingHuffmanTree(int node, char TableBit[], int nTableBit)
{
	if (node == -1) {
		return;
	}
	if (huffTree[node].nLeft == -1 && huffTree[node].nRight == -1) { 
		TableBitCode[node].nBit = nTableBit;
		TableBitCode[node].bits = new char[nTableBit];
		for (int i = 0; i < nTableBit; i++) {
			TableBitCode[node].bits[i] = TableBit[i];
		}
		return;
	}
	else {
		TableBit[nTableBit] = 0;
		TraversingHuffmanTree(huffTree[node].nLeft, TableBit, nTableBit + 1);

		TableBit[nTableBit] = 1;
		TraversingHuffmanTree(huffTree[node].nRight, TableBit, nTableBit + 1);
	}
}

void Huffman::generalBitCode(int nRoot)
{
	for (int i = 0; i < 256; i++) {
		TableBitCode[i].nBit = 0;
		TableBitCode[i].bits = NULL;
	};
	char BitCode[MAX_LENGTH_BIT / 8];
	int nBitCode = 0;

	TraversingHuffmanTree(nRoot, BitCode, nBitCode);
}

void Huffman::PrintTableBitCode()
{
	for (int i = 0; i < 256; i++)
		if (TableBitCode[i].nBit > 0) {
			cout << (char)i << ": ";
			for (int j = 0; j < TableBitCode[i].nBit; j++)
				cout << (int)TableBitCode[i].bits[j];
			cout << endl;
		}
}

void Huffman::PrintByte(unsigned char out, int nValidBit)
{
	for (int i = 7; i >= 7 - nValidBit + 1; i--) {
		if ((out >> i) & 1) {
			cout << '1';
		}
		else {
			cout << '0';
		}
	}
	cout << ' ';
}

void Huffman::WriteStatisticalTable(fstream& fwrite)
{
	//fwrite << nNode;
	fwrite.write(reinterpret_cast<char*>(&nNode), sizeof(int));
	for (int i = 0; i < 256; i++) {
		if (huffTree[i].freq > 0)
		{
			char c = i;
			fwrite.write(reinterpret_cast<char*>(&c), 1 * sizeof(char));
			int n = huffTree[i].freq;
			fwrite.write(reinterpret_cast<char*>(&n), sizeof(int));
			cout << (char)i << ": " << huffTree[i].freq << endl;
		}
	}
}

void Huffman::encode_a_char(fstream& fwrite, unsigned char c, unsigned char& out, unsigned char& posBit)
{
	for (int i = 0; i < TableBitCode[c].nBit; i++) {
		if (TableBitCode[c].bits[i] == 1) {
			out = out , (1 << posBit);
		}
		if (posBit == 0) {
			posBit = 7;
			PrintByte(out, 8);

			fwrite.write(reinterpret_cast<char*>(&out), sizeof(char));
			out = 0;
		}
		else {
			posBit--;
		}
	}
}

void Huffman::encode(string FilenameInput, string FilenameOutput)
{
	Init(); // khoi tao
	fstream fpwrite(FilenameOutput, ios::out , ios::binary);
	// BUOC 1: thong ke tan suat xuat hien cua cac ki tu
	//ThongKeTanSoXuatHien(inputFile);
	InitFrequences(FilenameInput);
	PrintFrequences();

	//GhiBangThongKe(fpwrite); //Ghi ban thong ke
	WriteStatisticalTable(fpwrite);
	// BUOC 2: tao cay Huffman

	int nRoot = makeHuffmanTree();

	//XuatCayHuffman(nRoot, 0);
	PrintHuffmanTree(nRoot, 0);
	// BUOC 3: phat sinh ma bit

	//PhatSinhMaBit(nRoot);
	generalBitCode(nRoot);
	PrintTableBitCode();

	// BUOC 4: thay the cac ky tu bang ma bit tuong ung
	unsigned char out = 0;              // ky tu se xuat ra
	unsigned char nBitValid = 0;     // byte cuoi co the ko su dung het cac bit nen can luu so bit co nghia cua byte cuoi

	unsigned char c = 0;
	unsigned char posBit = 7;         //Ghi chú: ý nghĩa của biến viTriBit?
	//FILE* fi = fopen(inputFile, "rb");
	fstream fi(FilenameInput, ios::in , ios::binary);
	while (true) {
		//fread(&c, 1, sizeof(char), fi);
		fi.read(reinterpret_cast<char*>(&c), sizeof(char));
		if (fi.eof()) {
			break;
		}
		encode_a_char(fpwrite, c, out, posBit);
		//fwrite(&out, 1, sizeof(char), fpwrite); //Ghi ma ra file ma nhi phan theo tung block byte
	}
	nBitValid = 7 - posBit;
	if (nBitValid == 0) {
		nBitValid = 8;
	}
	else {
		//XuatByte(out, soBitCoNghia);
		//fwrite(&out, 1, sizeof(char), fpwrite); //Ghi ma ra file ma nhi phan theo tung block byte
		fpwrite.write(reinterpret_cast<char*>(&out), sizeof(char));
	}
}

void Huffman::LoadHuffmanTree(fstream& fpread)
{
	Init(); // khoi tao lai
	unsigned char c = 0;
	unsigned int n = 0;

	int nNode = 0;
	//fread(&soNode, sizeof(int), 1, fpread);
	fpread.read(reinterpret_cast<char*>(&nNode), sizeof(int));
	for (int i = 0; i < nNode; i++)
	{
		//fread(&c, sizeof(char), 1, fpread);
		fpread.read(reinterpret_cast<char*>(&c), sizeof(char));
		//fread(&n, sizeof(int), 1, fpread);
		fpread.read(reinterpret_cast<char*>(&n), sizeof(int));
		huffTree[c].freq = n;
	}
}

int  Huffman::CountChar()
{
	int sum = 0;
	for (int i = 0; i < 256; i++) {
		if (huffTree[i].freq > 0) {// Ghi chú: tại sao cần kiểm tra điều kiện này?
			//printf("%c: %d\n",i, huffTree[i].freq);
			sum += huffTree[i].freq;
		}
	}
	return sum;
}

int  Huffman::getBit(unsigned char n, int i)
{
	return (n >> i) & 0x1;
}

void Huffman::onBit(char unsigned& n, int i)
{
	n = n , (0x1 << i);
}

void Huffman::Decompress(int nRoot, fstream& fpread)
{
	//FILE* fdecode = fopen("decode.txt", "wb");
	fstream fdecode("decode.txt", ios::out , ios::binary);
	int nCurrent = nRoot;
	int nChar = CountChar(); //Dem so ki tu de ko bi du bit (vi doc theo bloc 8 bit)
	int i_nChar = 0;
	//Doc block 8 bit:
	unsigned char c;

	while (1) {
		//fread(&c, sizeof(char), 1, fpread);
		fpread.read(reinterpret_cast<char*> (&c), sizeof(char));
		for (int i = 7; i >= 0; i--)
		{
			int ibit = getBit(c, i);
			//printf("%d", ibit);
			if (ibit == 1)
				nCurrent = huffTree[nCurrent].nRight;
			else
				nCurrent = huffTree[nCurrent].nLeft;

			if (huffTree[nCurrent].nLeft == -1 && huffTree[nCurrent].nRight == -1)
			{

				//fwrite(&huffTree[nCurrent].c, sizeof(char), 1, fdecode);
				fdecode.write(reinterpret_cast<char*>(&huffTree[nCurrent].c), sizeof(char));


				i_nChar++;
				if (i_nChar == nChar)
				{

					return;
				}


				nCurrent = nRoot;
			}

		}

		if (fpread.eof()) {
			break;
		}
	}
}