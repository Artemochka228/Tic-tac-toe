#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

char table[3][3];
bool step;


void instruction();

int main() {

	instruction();

	srand(time(NULL));
	if (rand() & 1) step = true;
	else step = false;

}