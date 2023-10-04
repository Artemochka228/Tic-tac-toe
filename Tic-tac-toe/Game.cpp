#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

char table[3][3];
bool step;


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

int main() {

	instruction();

	srand(time(NULL));
	if (rand() & 1) step = true;
	else step = false;

}