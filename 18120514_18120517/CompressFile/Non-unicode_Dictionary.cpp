#include "Non-unicode_Dictionary.h"


Ascii_Dictionary::Ascii_Dictionary()
{

}

Ascii_Dictionary::~Ascii_Dictionary()
{
	Table.clear();
}

void Ascii_Dictionary::Init()
{
	Table.resize(256);

	for (int i = 0; i < 256; i++)
		Table[i] = char(i);

}

int Ascii_Dictionary::Find_Pos(string temp)
{
	for (int i = 0; i < Table.size(); i++)
		if (Table[i].compare(temp) == 0)
			return i;
	return -1;
}




