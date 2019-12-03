#pragma once
enum TYPENODE{LEAF, BIND};
class Node
{
private:
	char data;
	int frequency;
	Node* pLeft;
	Node* pRight;
	TYPENODE type;
public:
	int getFrequency();
	Node(char _data, int _frequency, TYPENODE _type = LEAF);
	Node(Node* left, Node* right, TYPENODE _type = BIND);
	Node();
	~Node();
};

