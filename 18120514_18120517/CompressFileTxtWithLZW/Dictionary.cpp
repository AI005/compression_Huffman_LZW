#include "Dictionary.h"

Dictionary::Dictionary()
{

}

Dictionary::~Dictionary()
{
	Table.clear();
}

void Dictionary::Init()
{
	vector <wchar_t> temp = 
	{	L'\u00C0',
		L'\u00C1',
		L'\u00C2',
		L'\u00C3',
		L'\u00C8',
		L'\u00C9',
		L'\u00CA',
		L'\u00CC',
		L'\u00CD',
		L'\u00D2',
		L'\u00D3',
		L'\u00D4',
		L'\u00D5',
		L'\u00D9',
		L'\u00DA',
		L'\u00DD',
		L'\u00E0',
		L'\u00E1',
		L'\u00E2',
		L'\u00E3',
		L'\u00E8',
		L'\u00E9',
		L'\u00EA',
		L'\u00EC',
		L'\u00ED',
		L'\u00F2',
		L'\u00F3',
		L'\u00F4',
		L'\u00F5',
		L'\u00F9',
		L'\u00FA',
		L'\u00FD',
		L'\u0102',
		L'\u0103',
		L'\u0110',
		L'\u0111',
		L'\u0128',
		L'\u0129',
		L'\u0168',
		L'\u0169',
		L'\u01A0',
		L'\u01A1',
		L'\u01AF',
		L'\u01B0',
		L'\u1EA0',
		L'\u1EA1',
		L'\u1EA2',
		L'\u1EA3',
		L'\u1EA4',
		L'\u1EA5',
		L'\u1EA6',
		L'\u1EA7',
		L'\u1EA8',
		L'\u1EA9',
		L'\u1EAA',
		L'\u1EAB',
		L'\u1EAC',
		L'\u1EAD',
		L'\u1EAE',
		L'\u1EAF',
		L'\u1EB0',
		L'\u1EB1',
		L'\u1EB2',
		L'\u1EB3',
		L'\u1EB4',
		L'\u1EB5',
		L'\u1EB6',
		L'\u1EB7',
		L'\u1EB8',
		L'\u1EB9',
		L'\u1EBA',
		L'\u1EBB',
		L'\u1EBC',
		L'\u1EBD',
		L'\u1EBE',
		L'\u1EBF',
		L'\u1EC0',
		L'\u1EC1',
		L'\u1EC2',
		L'\u1EC3',
		L'\u1EC4',
		L'\u1EC5',
		L'\u1EC6',
		L'\u1EC7',
		L'\u1EC8',
		L'\u1EC9',
		L'\u1ECA',
		L'\u1ECB',
		L'\u1ECC',
		L'\u1ECD',
		L'\u1ECE',
		L'\u1ECF',
		L'\u1ED0',
		L'\u1ED1',
		L'\u1ED2',
		L'\u1ED3',
		L'\u1ED4',
		L'\u1ED5',
		L'\u1ED6',
		L'\u1ED7',
		L'\u1ED8',
		L'\u1ED9',
		L'\u1EDA',
		L'\u1EDB',
		L'\u1EDC',
		L'\u1EDD',
		L'\u1EDE',
		L'\u1EDF',
		L'\u1EE0',
		L'\u1EE1',
		L'\u1EE2',
		L'\u1EE3',
		L'\u1EE4',
		L'\u1EE5',
		L'\u1EE6',
		L'\u1EE7',
		L'\u1EE8',
		L'\u1EE9',
		L'\u1EEA',
		L'\u1EEB',
		L'\u1EEC',
		L'\u1EED',
		L'\u1EEE',
		L'\u1EEF',
		L'\u1EF0',
		L'\u1EF1',
		L'\u1EF2',
		L'\u1EF3',
		L'\u1EF4',
		L'\u1EF5',
		L'\u1EF6',
		L'\u1EF7',
		L'\u1EF8',
		L'\u1EF9'	};

		Table.resize(temp.size() + 256);

		for (int i = 0; i < 256; i++)
			Table[i] = wchar_t(i);
		for (int i = 256; i < temp.size() + 256; i++)
			Table[i] = temp[i - 256];
}

int Dictionary::Find_Pos(wstring temp)
{
	for (int i = 0; i < Table.size(); i++)
		if (Table[i].compare(temp) == 0)
			return i;
	return -1;
}




