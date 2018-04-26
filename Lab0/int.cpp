/* Code uses geometric series with common ratio 2 to reveal the sizes
* and ranges of different int types and to demonstrate the integer
* overflow problem.
*/

#include <stdio.h>
#include <stdlib.h> // for using exit(EXIT_SUCCESS)instead of return 0
#include <iostream>

using namespace std;
#define N_TERMS 64 // number of term in the geometric sequence.
int main ()
{
	long seq_term, seq_sum;
	seq_term = seq_sum = 1;
	cout << "Term no. " << 1 << " = " << seq_term;
	cout << " and accumulated sum = " << seq_sum << "." << endl;
	for (int i = 1; i < N_TERMS; i++)
	{
		seq_term *= 2; // double itself
		seq_sum += seq_term; // add to tracking sum
		cout << "Term no." << i+1 << " = " << seq_term ;
		cout << " and accumulated sum = "<< seq_sum << ".\n";
	}
	system("pause"); // pause so we can view output
}

/*
N_TERMS for each type
int: 32
short: 16
long: 64
*/