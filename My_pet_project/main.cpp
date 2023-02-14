#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

struct Pet
{
	bool is_live = true;
	string name, why_died = "Steel alive";
	int age = -1, health = 100, food = 100, clean = 100;
};

void make_stat(Pet* pet) {
	cout << "name = ";
	cin >> pet->name;

	cout << "age = ";
	cin >> pet->age;

	pet->clean = 100;
	pet->food = 100;
	pet->health = 100;
}

void show_stat(Pet* pet) {
	if (pet->is_live) {
		cout << "  name: " << pet->name << "\n";
		cout << "   age: " << pet->age << "\n";
		cout << "health: " << pet->health << "\n";
		cout << "  food: " << pet->food << "\n";
		cout << " clean: " << pet->clean << "\n";
	}
	else cout << "This pet is die\nCause: " << pet->why_died;
}

void next_turn(Pet* pet) {
	if (pet->clean < 0) {
		pet->is_live = false;
		pet->why_died = "Flu";
	}
	else if (pet->food == 0) {
		pet->is_live = false;
		pet->why_died = "Starvation";
	}

	if (pet->is_live == true) {
		pet->clean -= 20;
		pet->food -= 25;
		pet->health = 100;
		pet->age++;
	}
}

void care(Pet* pet) {
	pet->clean = 100;
	pet->food = 100;
	pet->health -= 50;
	cout << "You taking care of " << pet->name << ".\n";
}

int main() {
	int turn = 0, amount_of_pet = 0;
	bool t = true;
	Pet* list[30];

	while (t) {
		cout << "trun " << turn << ".\n";
		int input;

		cout << "(1 = Care the pet, 2 = show stat, 3 = make new pet, 4 = exit): ";
		cin >> input;

		switch (input)
		{
		case 1:
			cout << "what pet? ";
			int which;
			cin >> which;

			if (which <= amount_of_pet && which > 0) care(list[which - 1]);
			break;

		case 2:
			cout << "what pet? ";
			cin >> which;

			if(which <= amount_of_pet && which > 0) show_stat(list[which - 1]);
			break;

		case 3:
			cout << "make new pet\n";
			list[amount_of_pet] = new Pet;
			make_stat(list[amount_of_pet]);
			amount_of_pet++;
			break;

		case 4:
			cout << "Exit.";
			t = false;
			break;
		}

		for (int i = 0; i < amount_of_pet; i++) {
			next_turn(list[i]);
		}

		Sleep(2000);
		system("cls");

		turn++;
	}

	for (int i = 0; i < amount_of_pet; i++)
		delete list[i];
}
