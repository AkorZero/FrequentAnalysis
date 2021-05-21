#pragma once
#include <string>
#include <vector>

using namespace std;

class Haffman
{
	class Node
	{
		friend class Haffman;
		char symbol;
		int count;
		string code;
		Node* next;
		Node* left;
		Node* right;
	public:
		Node(char s, int cnt, Node *n = nullptr, Node* l = nullptr, Node* r = nullptr)
		{
			symbol = s;
			count = cnt;
			code = "";
			next = n;
			left = l;
			right = r;
		}
	};
	vector<pair<char, string>> code;
	Node* head;
	void remove(Node* root);
	vector<pair<char, string>> nextCode(Node* root, string kod);
public:
	Haffman();
	void pushSort(Node* node);
	Node* popFront();
	void printList();
	void createTree(int ch[256]);
	vector<pair<char, string>> codeHaffman();
	~Haffman();
};

