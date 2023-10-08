#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <limits>
#include <map>
using namespace std;

char table[3][3];
bool currentPlayer;
char flag = char(45);
map<bool, char> players;



void printInstr()
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
			cout << "| " << l + 1 << ' ';
			table[i][j] = char(49 + l++);
		}
		cout << '|';
		cout << endl;
	}
	_getch();
	system("cls");
}

void chooseSymb()
{
	char symb = char(45);
	do
	{
		system("cls");
		cout << "Choose symb for ";
		currentPlayer ? cout << "1-st player: " : cout << "2-nd player: ";
		cin >> symb;
	} while (symb != 'O' && symb != 'X');
	
	players[currentPlayer] = symb;
	players[currentPlayer] == 'X' ? players[!currentPlayer] = 'O' : players[!currentPlayer] = 'X';
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

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

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

		if ((table[0][0] == table[1][1] && table[0][0] == table[2][2]))
		{
			flag = table[0][0];
			return true;
		}

		if ((table[0][2] == table[1][1] && table[0][2] == table[2][0]))
		{
			flag = table[0][2];
			return true;
		}
	}

	int cnt = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (table[i][j] != 'X' && table[i][j] != 'O') break;
			cnt++;
		}
	}
	if (cnt == 9) return true;
	return false;
}

int main() {

	printInstr();

	srand(time(NULL));
	if (rand() & 1) currentPlayer = true;
	else currentPlayer = false;

	chooseSymb();

	currentPlayer = true;

	while (!checkWinner())
	{
		system("cls");
		if (!makeMove())
		{
			cout << "Invalid input, please try again: ";
			_getch();
		}
	}
	if (flag == players[true]) cout << "1-st player wins" << endl;
	else if (flag == players[false]) cout << "2-nd player wins" << endl;
	else cout << "Draw" << endl;
}