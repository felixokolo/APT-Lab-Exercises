// Standard (system) header files
#include <iostream>
#include <cstdlib>

#include "ReversiBoard.h"
#include "ReversiConsoleView.h"

using namespace std;

// Main program
int main ()
{

	ReversiBoard a;
	ReversiConsoleView con(&a);
	int row = -1, col = -1;
	string players[] = {"BLACK - #", "WHITE - o"};
	state curPlayer = BLACK;
	int valid = 0;
	while(1)
	{
		valid = 0;
		con.print();
		do
		{
			cout << "Player " << players[(int)curPlayer] << endl;
			cout << "Enter a valid move in the form "
				 << "ROW COL or -1 -1 to quit\t";
			cin >> row;
			cin >> col;
			cout << endl;
			if (row == -1)
			{
				cout << "Game ended" << endl;
				return 0;
			}

			valid = a.setFieldState(curPlayer, {row, col});
		} while (valid == 0);
		curPlayer =  curPlayer == WHITE? BLACK : WHITE;
	}
	return 0;
}
