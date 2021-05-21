#include "Haffman.h"
#include <iostream>

using namespace std;

Haffman::Haffman()
{
	head = nullptr;
}

void Haffman::pushSort(Node * node)
{
	if (head == nullptr || node->count <= head->count)
	{
		node->next = head;
		head = node;
	}
	else
	{
		Node* tmp = head;
		while (tmp->next != nullptr && tmp->next->count < node->count)
		{
			tmp = tmp->next;
		}
		node->next = tmp->next;
		tmp->next = node;
	}
}

Haffman::Node * Haffman::popFront()
{
	if (head == nullptr)
		throw "Called popFront on empty list";
	Node* tmp = head;
	head = head->next;
	return tmp;
}

void Haffman::printList()
{
	Node* tmp = head;
	while (tmp != nullptr)
	{
		cout << "(" << tmp->symbol << ", " << tmp->count << ") ";
		tmp = tmp->next;
	}
	cout << endl;
}

void Haffman::createTree(int ch[256])
{
	for (int i = 0; i < 256; i++)
	{
		if (ch[i] > 0)
		{
			pushSort(new Node(i, ch[i]));
		}
	}
	
	printList();

	while (head->next != nullptr)
	{
		Node* first = popFront();
		Node* second = popFront();
		Node* newNode = new Node(0, first->count + second->count, nullptr, first, second);
		pushSort(newNode);
		printList();

	}

}

vector<pair<char, string>> Haffman::codeHaffman()
{
	nextCode(head, "");
	return code;

}

vector<pair<char, string>> Haffman::nextCode(Node* root, string kod)
{
	if (root->left != nullptr)
	{
		root->code = kod;
		nextCode(root->left, kod + "0");
		nextCode(root->right, kod + "1");
	}
	else
	{
		root->code = kod;
		code.push_back({ root->symbol, kod });
	}
	return code;
}

void Haffman::remove(Haffman::Node * root)
{
	if (root != nullptr)
	{
		remove(root->left);
		remove(root->right);
		delete root;
	}
}

Haffman::~Haffman()
{
	remove(head);
}
