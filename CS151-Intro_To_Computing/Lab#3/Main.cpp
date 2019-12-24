//Lab 2 : Tic Tac Toe
//Team: <Team Name>
//Members: <Names>
//Creation: <Date>
#include "Repository.h"
#include <fstream>
using namespace std;

void PlayGame()
{
	const char tokens[2] = {'O','X'};
	int player = 0;
	int values = 9;
	int position;
	int choices[9];

	initArray(choices);
	initialize();

	cout << "Player 1 (O) => User\nPlayer 2 (X) => Computer\n";
	cout << "Board Positions\n";
	cout << "1 2 3\n4 5 6\n7 8 9\n\n";

	while(hasMove() && !winner())
	{
		cout << "Player " << (player + 1);
		cout << "\n" << board() << "\n";

		if(player == 0)
		{
			cout << "Select position: ";
			cin >> position;

			while(!makeMove(position,tokens[0]))
			{
				cout << "The position is unavailable\nSelect another position: ";
				cin >> position;
			}
		}
		else
		{
			position = canWin();

			if(position == -1)
				position = randomChoice(choices,values);
			else
				position += 1;

			makeMove(position,tokens[1]);
		}

		removeChoice(choices,values,position);
		values -= 1;
		player = (player + 1) % 2;
	}

	if(winner())
	{
		cout << "\n" << board() << "\n";
		cout << "Player " << ((player + 1) % 2 + 1) << " won!\n";
	}
	else
	{
		cout << "Game ended in a draw.\n";
	}
}

int main()
{
	if(Tester())
	{
		srand(time(NULL));
		PlayGame();
	}

	return 0;
}
