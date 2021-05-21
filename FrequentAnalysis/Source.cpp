#include <iostream>
#include <fstream>
#include "Haffman.h"

using namespace std;

int main()
{
	int freq[256] = { 0 };
	ifstream inFile("input.txt");
	if (!inFile.is_open())
	{
		cout << "File not found" << endl;
		system("pause");
		return 0;
	}

	char symbol;

	while (inFile.get(symbol))
	{
		freq[symbol]++;
	}

	for (int i = 0; i < 256; i++)
	{
		if (freq[i] > 0)
		{
			cout << char(i) << " --- " << freq[i] << " --- " << i << endl;
		}
	}

	Haffman treeHaffman;
	treeHaffman.createTree(freq);
	vector<pair<char, string>> t = treeHaffman.codeHaffman();

	for (pair<char, string> it : t)
	{
		cout << it.first << " --- " << it.second << endl;
	}

	int o_len = 0;

	for (int i = 0; i < 256; i++)
	{
		if (freq[i] > 0)
			o_len += freq[i] * 8;
	}

	cout << "Original: " << o_len << endl;

	

	system("pause");
	return 0;
}