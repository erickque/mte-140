#include <string>
#include <iostream>
#include <map>
using namespace std;

#include "Queue.h"

map <char, string> char_to_morse;

void initialize_morse()
{
	char_to_morse['e'] = ".";
	char_to_morse['m'] = "--";
	char_to_morse['o'] = "---";
	char_to_morse['s'] = "...";
	char_to_morse['t'] = "-";
	char_to_morse['/'] = "";
}

// Given a series of characters in "q"
// Output series of . and - according to the morse code
string convert_morse_code(Queue q)
{
	string morse_code = "";
	while (!q.empty())
	{
		char c = q.dequeue();
		morse_code += char_to_morse[c] + " ";
	}

	return morse_code;
}

void main_morse()
{
	initialize_morse();

	string morse_code = " ";
	while (morse_code.length() > 0)
	{
		Queue q;

		cout << "Enter characters (/ to end): ";
		char c = ' ';
		while (c != '/')
		{
			cin >> c;
			q.enqueue(c);
		}

		morse_code = convert_morse_code(q);
		cout << "SENDING: " << morse_code << endl;
	}
}