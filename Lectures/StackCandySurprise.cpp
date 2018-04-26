#include <stdlib.h>  // rand
#include <string>
#include <iostream>

using namespace std;

class Candy {
public:
	Candy(string newflavour);
	~Candy();

	string get_flavour();
	Candy* get_next();
	void set_next(Candy* newnext);
	
private:
	// "value" of the "node"
	string flavour;
	Candy* next;
};

Candy::Candy(string newflavour) // : flavour(newflavour), next(nullptr) {}
{
	flavour = newflavour;
	next = nullptr;
}
Candy::~Candy() {}
string Candy::get_flavour() { return flavour; }
void Candy::set_next(Candy* newnext) { next = newnext; }
Candy* Candy::get_next() { return next; }


class CandySurprise
{
public:
	CandySurprise();
	~CandySurprise();

	void add_money(double coins);
	double get_money();

	// "Peek". Copy the candy into the "candy" variable, so we maintain the original candy in the machine.
	bool see_first_candy(Candy& candy);
	// "Pop". Return a pointer because we want to return the actual candy, not a copy of it.
	// Returns nullptr if failed.
	Candy* purchase_candy();

private:
	// Money that has been deposited
	double money_deposited;
	int num_candies;

	Candy* top;

	const double PEEK_COST = 0.50;
	const double PURCHASE_COST = 2;
};


CandySurprise::CandySurprise()
{
	num_candies = 0;
	top = nullptr;

	string flavours[3] = { "Snickers", "Oh Henry", "Twix" };
	// Load 10 candies into the machine in random order.
	for (int i = 0; i < 10; i++) {
		int rand_idx = rand() % 3;
		string this_flavour = flavours[rand_idx];
		Candy* candy = new Candy(this_flavour);
		// Essentially a push() command
		candy->set_next(top);
		top = candy;
	}
	num_candies = 10;
}

CandySurprise::~CandySurprise()
{
	while (top != nullptr) {
		Candy* next = top->get_next();
		delete top;
		top = next;
	}
}

void CandySurprise::add_money(double coins)
{
	money_deposited += coins;
}

double CandySurprise::get_money()
{
	return money_deposited;
}

bool CandySurprise::see_first_candy(Candy& candy)
{
	// Error cases
	if (money_deposited < PEEK_COST) {
		cout << "Not enough money to view first candy :(" << endl;
		return false;
	}
	if (top == nullptr) {
		cout << "No candies available. Call the candy person to refill." << endl;
		return false;
	}

	// Return the first candy for $0.50
	money_deposited -= PEEK_COST;
	candy = *top;
	return true;
}

Candy* CandySurprise::purchase_candy()
{
	// Error cases
	if (money_deposited < PURCHASE_COST) {
		cout << "Not enough money to buy a candy. Don't cheat me!" << endl;
		return nullptr;
	}
	if (num_candies == 0) {
		cout << "No candies available. Call the candy dude." << endl;
		return nullptr;
	}

	// Purchase candy. We don't delete the "top" candy here because we give
	// it over to the user. It is their responsibility to delete it (probably,
	// or hopefully, by eating it).
	money_deposited -= PURCHASE_COST;
	Candy* purchased_candy = top;
	top = top->get_next();
	purchased_candy->set_next(nullptr);
	num_candies--;

	return purchased_candy;
}



void main_candy()
{
	CandySurprise machine;

	char choice = ' ';
	while (choice != 'x')
	{
		cout << "What do you want to do? (p-peek | m-add 50 cents | b-buy candy | x-exit) ";
		cin >> choice;

		if (choice == 'm') {  // add money
			machine.add_money(0.50);
		}
		else if (choice == 'p') {  // peek at first candy
			Candy candy("");
			if (machine.see_first_candy(candy) == true)
				cout << candy.get_flavour() << endl;
		}
		else if (choice == 'b') {  // buy candy
			Candy* candy = machine.purchase_candy();
			if (candy != nullptr) {
				cout << "Mmmm..." << candy->get_flavour() << endl;
				// We ate it. So free the memory.
				delete candy;
			}
		}
		cout << "Total money deposited: " << machine.get_money() << endl;
	}
}