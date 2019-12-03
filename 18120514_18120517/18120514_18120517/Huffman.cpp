#include "Huffman.h"

void Sort(vector<Node*>& lstNode)
{
	int imin;
	for (int i = 0; i < lstNode.size() - 1; i++) {
		imin = i;
		for(int j = i+1; j < lstNode.size(); j++)
			if (lstNode[j]->getFrequency() < lstNode[imin]->getFrequency()) {
				imin = j;
			}

		if (imin != i) {
			//swap node
			Node* temp = lstNode[imin];
			lstNode[imin] = lstNode[i];
			lstNode[i] = temp;
		}
	}
}


Huffman::Huffman()
{
}


Huffman::~Huffman()
{
}


void Huffman::ReadFile(string f_name)
{
	ifstream infile(f_name);
	if (!infile) {
		cout << "cannot open file";
		system("pause");
		exit(0);
	}
	string str;
	while (!infile.eof()) {
		getline(infile, str);
		content.append(str);
	}
	infile.close();
}

void Huffman::getFrequencies()
{
	map<char, int>::iterator itr;
	for (auto& letter : content) {
		itr = frequencies.find(letter);
		if (itr == frequencies.end())    frequencies.insert(pair<char, int>(letter, 1));
		else                             frequencies[letter]++;
	}

	//PRINT ALL FREQUENCIES
	cout << endl << "ALL OF FREQUENCIES: \n\n";
	for (auto& a : frequencies) {
		cout << a.first << " :" << a.second << endl;
	}
}

void Huffman::MakeTree()
{
	vector<Node*> lstNode;
	//make all leaf
	for (auto& a : frequencies) {
		lstNode.push_back(new Node(a.first, a.second));
	}

	//creat  huffman tree
	Sort(lstNode);

	while (lstNode.size() > 1) {
		lstNode.push_back(new Node(lstNode.at(0), lstNode.at(1)));
		lstNode.erase(lstNode.begin(), lstNode.begin() + 2);
		Sort(lstNode);
	}

	Tree = lstNode.front();
}


void Huffman::build_lookup_table()
{
	deque < pair<Node*, vector<bool>>> q;
}
