#include "Node.h"

Node::Node()
{

}


Node::~Node()
{

}


int Node::getFrequency()
{
	return frequency;
}

Node::Node(char _data, int _frequency, TYPENODE _type)
{
	data = _data;
	frequency = _frequency;
	type = _type;
}

Node::Node(Node* left, Node* right, TYPENODE _type)
{
	pLeft = left;
	pRight = right;
	frequency = left->frequency + right->frequency;
	data = (char)0;
	type = _type;
}