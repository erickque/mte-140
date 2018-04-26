#include <string>
#include <iostream>
using namespace std;

#include "Stack.h"

string reverse(string s)
{
	Stack char_stack;
	// Sequence of pushes
	for (int i = 0; i < s.length(); i++)
	{
		char_stack.push(s[i]);
	}

	// Sequence of pops
	string s_reversed = "";
	while (char_stack.empty() == false)
	{
		s_reversed += char_stack.pop();
	}

	return s_reversed;
}


void main_reverse()
{
	string s = " ";

	while (s != "x")
	{
		cout << "Enter word (x to exit): ";
		cin >> s;
		cout << s << " / " << reverse(s) << endl << endl;
	}
}