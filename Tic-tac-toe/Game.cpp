#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <map>
using namespace std;

char table[3][3];
bool step;
map<bool, char> symbs;


void instruction()
{
	cout << "***** Tic-tac-toe game ***** \n\n";
	cout << "Rules:\n";
	cout << "2 players play on a 3v3 field\n";
	cout << "The one who makes the winning combination wins\n";
	cout << "Example field:\n\n";

	int l = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "| " << l + 1 << " ";
			table[i][j] = char(49 + l++);
		}
		cout << "|";
		cout << endl;
	}
	_getch();
}

void choice(bool plr)
{
	cin >> symbs[plr];
	symbs[plr] == 'X' ? symbs[!plr] = 'O' : symbs[!plr];
}

bool input()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "| " << table[i][j] << " ";
		}
		cout << "|";
		cout << endl;
	}

	cout << endl;
	if (step) cout << "1-st player moves: ";
	else cout << "2-nd player moves: ";

	int n;
	cin >> n;
	if (n < 1 || n > 9) return false;

	int i, j;
	i = (n - 1) / 3;
	j = (n - 1) % 3;

	if (table[i][j] == 'O' || table[i][j] == 'X') return false;

	table[i][j] = symbs[step];
	step = !step;

	return true;

}

bool win();

int main() {

	instruction();

	srand(time(NULL));
	if (rand() & 1) step = true;
	else step = false;

	while (!win())
	{
		system("cls");
		if (!input())
		{
			cout << "Invalid input, please try again: ";
			_getch();
		}
	}

}