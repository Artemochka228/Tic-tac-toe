#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <map>
using namespace std;

char table[3][3];
bool currentPlayer;
char flag;
map<bool, char> players;



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

void choice()
{
	cin >> players[currentPlayer];
	players[currentPlayer] == 'X' ? players[!currentPlayer] = 'O' : players[!currentPlayer];
}

bool makeMove()
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
	if (currentPlayer) cout << "1-st player moves: ";
	else cout << "2-nd player moves: ";

	int n;
	cin >> n;
	if (n < 1 || n > 9) return false;

	int i, j;
	i = (n - 1) / 3;
	j = (n - 1) % 3;

	if (table[i][j] == 'O' || table[i][j] == 'X') return false;

	table[i][j] = players[currentPlayer];
	currentPlayer = !currentPlayer;

	return true;

}

bool checkWinner()
{
	for (int i = 0; i < 3; i++)
	{
		if (table[i][0] == table[i][1] && table[i][0] == table[i][2])
		{
			flag = table[i][0];
			return true;
		}

		if (table[0][i] == table[1][i] && table[0][i] == table[2][i])
		{
			flag = table[0][i];
			return true;
		}

		if ((table[0][0] == table[1][1] && table[0][0] == table[2][2]) || (table[0][2] == table[1][1] && table[0][2] == table[2][0]))
		{
			flag = table[0][0];
			return true;
		}
	}
	return false;
}

int main() {

	instruction();

	srand(time(NULL));
	if (rand() & 1) currentPlayer = true;
	else currentPlayer = false;

	choice();

	while (!checkWinner())
	{
		system("cls");
		if (!makeMove())
		{
			cout << "Invalid input, please try again: ";
			_getch();
		}
	}
	flag == 'X' ? cout << "1-st player wins" : cout << "2-nd player wins" << endl;
}