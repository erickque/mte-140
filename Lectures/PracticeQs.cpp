#include <iostream>
#include "Queue.h"

using namespace std;

int sum_of_digits(int n);
bool reach_in_3(int x0, int y0, int x, int y, int moves);

int main()
{
	int a = 45; 
	int b = 129;

	cout << sum_of_digits(a) << endl;
	cout << sum_of_digits(b) << endl;

	cout << reach_in_3(0, 0, 2, 2, 0) << endl;
}

int sum_of_digits(int n)
{
	if (n < 10)
	{
		return n;
	}
	return (n%10) + sum_of_digits(n/10);
}

bool reach_in_3(int x0, int y0, int x, int y, int moves)
{
	if (x0 == x && y0 == y)
	{
		return true;
	}
	if (moves<3)
	{
		moves++;
		if (x0 < x)
		{
			return reach_in_3(x0+1,y0,x,y,moves);
		}
		if (y0 < y)
		{
			return reach_in_3(x0, y0+1, x, y, moves);
		}
		return false;
	}
	return false;
}

void reverse(Queue& queue)
{
	stack rstack;
	while (!queue.empty())
	{
		Item item = queue dequeue();
		restack.push(item);
	}
	while (!stack.empty())
		queue.enqueue(rstack.pop()); 
}





/*
Question 1
Given a decimal number, write a recursive function that will return the sum of its digits. 

Question 2
Write a recursive function that will check if a robot starting at (xo, yo) can reach (x,y)
within 3 moves or fewer. 
Can only move up and right. 
*/ 

/*
Implement a "min stack"
push O(1)
pop O(1)
peek O(1)
min O(1)

HINT: 7, 8, 5, 9 
pop();

2.
Implement a function that reverses: 
void reverseQueue(Queue q);
*/ 
