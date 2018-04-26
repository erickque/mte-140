/*Pointer variables and passing pointer parameters*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// Declare functions that we will define later on (so we can use them in main()).
void bad_charSwap (char v1, char v2);
void good_charSwap (char *v1, char *v2);
void bad_charPtrSwap (char *p1, char *p2);
void good_charPtrSwap (char **p1, char **p2);

int main ()
{
	char c1,c2;
	char *cPtr1, *cPtr2;

	// At this point, cPtr1 and cPtr2 have arbitrary memory addresses.
	// They are considered "wild" or "bad". They should NOT be dereferenced
	// until they are assigned the address of an allocated storage block.
	// That is, one should not attempt to read from or write at the
	// addresses they contain.
	c1 = 'A';
	c2 = 'B';
	cPtr1 = &c1;
	cPtr2 = &c2;

	// At this point, cPtr1 and cPtr2 are assigned the addresses allocated
	// for c1 and c2, respectively. Hence, they can be dereferenced.
	cout << ">>> After the assignment statements:" << endl;
	cout << "c1 = " << c1 << ", c2 = " << c2 << endl;

	// Let’s now read the pointers.
	// We static_cast from char* to void* because cout tries to interpret char*
	// as a null-terminated array of characters. But what we want to output is
	// the address of the pointer. Don’t worry if you don’t get this - just know
	// that we are doing this to output the memory address of the variable.
	cout << "cPtr1 = " << static_cast<void*>(cPtr1) << " and references value "
	<< *cPtr1 << endl;
	cout << "cPtr2 = " << static_cast<void*>(cPtr2) << " and references value "
	<< *cPtr2 << endl << endl;

	/* -------------------Swapping char values -----------------*/
	cout << ">>> Swapping char values ..." << endl;

	bad_charSwap(c1, c2);
	cout << ">>> After calling bad_charSwap(c1,c2):" << endl;
	cout << "c1 = " << c1 << ", c2 = " << c2 << endl;
	cout << "cPtr1 = " << static_cast<void*>(cPtr1) << " and references value "
	<< *cPtr1 << endl;
	cout << "cPtr2 = " << static_cast<void*>(cPtr2) << " and references value "
	<< *cPtr2 << endl << endl;

	good_charSwap(&c1, &c2);
	cout << ">>> After calling good_charSwap(&c1,&c2):" << endl;
	cout << "c1 = " << c1 << ", c2 = " << c2 << endl;
	cout << "cPtr1 = " << static_cast<void*>(cPtr1) << " and references value "
	<< *cPtr1 << endl;
	cout << "cPtr2 = " << static_cast<void*>(cPtr2) << " and references value "
	<< *cPtr2 << endl << endl;

	good_charSwap(cPtr1, cPtr2);
	cout << ">>> After calling good_charSwap(cPtr1, cPtr2):" << endl;
	cout << "c1 = " << *cPtr1 << ", c2 = " << *cPtr2 << endl;
	cout << "cPtr1 = " << static_cast<void*>(cPtr1) << " and references value "
	<< *cPtr1 << endl;
	cout << "cPtr2 = " << static_cast<void*>(cPtr2) << " and references value "
	<< *cPtr2 << endl << endl;

	/* -------------------Swapping Pointers to char -----------------*/
	cout << ">>> Swapping pointers ..." << endl;

	bad_charPtrSwap(cPtr1, cPtr2);
	cout << ">>> After calling bad_charPtrSwap(cPtr1,cPtr2):" << endl;
	cout << "cPtr1 = " << static_cast<void*>(cPtr1) << " and references value "
	<< *cPtr1 << endl;
	cout << "cPtr2 = " << static_cast<void*>(cPtr2) << " and references value "
	<< *cPtr2 << endl << endl;
	
	good_charPtrSwap(&cPtr1, &cPtr2);
	cout <<">>> After calling good_charPtrSwap(&cPtr1,&cPtr2):" << endl;
	cout <<"cPtr1 = " << static_cast<void*>(cPtr1) << " and references value "
	<< *cPtr1 << endl;
	cout <<"cPtr2 = " << static_cast<void*>(cPtr2) << " and references value "
	<< *cPtr2 << endl << endl;
	system("pause");
}

void bad_charSwap(char v1, char v2)
{
	char temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
}

void good_charSwap(char *v1, char *v2)
{
	char temp;
	temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}

void bad_charPtrSwap(char *p1, char *p2)
{
	char *temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
}

void good_charPtrSwap(char **p1, char **p2)
{
	char *temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}