#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "Initialize.h"
#include "VerticalWinner.h"
#include "HorizontalWinner.h"
#include "DiagonalWinner.h"
#include "Winner.h"
#include "HasMove.h"
#include "MakeMove.h"
#include "Board.h"

bool InitializeTest()
{
	initialize();
	for(int i = 0;i < 9;i += 1)
	{
		if(grid[i] != '-')
		{
			return false;
		}
	}

	return true;
}

bool VerticalWinnerTest()
{
	for(int i = 0;i < 3;i += 1)
	{
		for(int j = 0;j < 9;j += 1)
		{
			grid[j] = '-';
		}

		grid[i]= grid[3 + i] = grid[6 + i] = 'T';

		if(!verticalWinner())
		{
			return false;
		}
	}

	for(int i = 0;i < 3;i += 1)
	{
		for(int j = 0;j < 3;j += 1)
		{
			for(int k = 0;k < 3;k += 1)
			{
				for(int l = 0;l < 9;l += 1)
				{
					grid[l] = 'T';
				}

				grid[3 * i] = grid[3 * j + 1] = grid[3 * k + 2] = 'S';

				if(verticalWinner())
				{
					return false;
				}
			}
		}
	}

	return true;
}

bool HorizontalWinnerTest()
{
	for(int i = 0;i < 3;i += 1)
	{
		for(int j = 0;j < 9;j += 1)
		{
			grid[j] = '-';
		}

		grid[3 * i]= grid[3 * i + 1] = grid[3 * i + 2] = 'T';

		if(!horizontalWinner())
		{
			return false;
		}
	}

	for(int i = 0;i < 3;i += 1)
	{
		for(int j = 0;j < 3;j += 1)
		{
			for(int k = 0;k < 3;k += 1)
			{
				for(int l = 0;l < 9;l += 1)
				{
					grid[l] = 'T';
				}

				grid[i] = grid[j + 3] = grid[k + 6] = 'S';

				if(horizontalWinner())
				{
					return false;
				}
			}
		}
	}

	return true;
}

bool DiagonalWinnerTest()
{
	for(int i = 0, j = 0,k = 8;i < 2;i += 1)
	{
		for(int l = 0;l < 9;l += 1)
		{
			grid[l] = '-';
		}

		grid[j] = grid[4] = grid[k] = 'T';

		if(!diagonalWinner())
		{
			return false;
		}

		j += 2;
		k -= 2;
	}

	for(int i = 0;i < 9;i += 1)
	{
		grid[i] = 'T';
	}

	grid[4] = 'S';

	if(diagonalWinner())
		return false;

	return true;
}

bool WinnerTest()
{
	for(int i = 0,k = 0;i < 3;i += 1)
	{
		for(int j = 0;j < 9;j += 1)
		{
			grid[j] = '-';
		}

		if(k == 0)
		{
			grid[i]= grid[3 + i] = grid[6 + i] = 'T';
		}
		else
		{
			grid[3* i] = grid[3 * i + 1] = grid[3 * i + 2] = 'S';
		}

		if(i == 2 && k == 0)
		{
			i = -1;
			k = 1;
		}

		if(!winner())
		{
			return false;
		}
	}

	for(int i = 0, j = 0,k = 8;i < 2;i += 1)
	{
		for(int l = 0;l < 9;l += 1)
		{
			grid[l] = '-';
		}

		grid[j] = grid[4] = grid[k] = 'T';

		if(!winner())
		{
			return false;
		}

		j += 2;
		k -= 2;
	}

	for(int i = 0;i < 9;i += 1)
	{
		grid[i] = 'T';
	}

	grid[4] = 'S';
	grid[0] = 'G';
	grid[8] = 'V';

	if(winner())
	{
		return false;
	}

	return true;
}

bool HasMoveTest()
{
	for(int i = 0;i < 9;i += 1)
	{
		grid[i] = 'S';
	}

	if(hasMove())
		return false;

	grid[rand() % 9] = '-';

	if(!hasMove())
		return false;

	return true;
}

bool MakeMoveTest()
{
	bool result;

	grid[0] = 'X'; grid[1] = 'X'; grid[2] = '-';
	grid[3] = 'O'; grid[4] = 'O'; grid[5] = 'X';
	grid[6] = '-'; grid[7] = 'X'; grid[2] = '-';

	result = makeMove(2,'O');
	result = (!result) && makeMove(7,'O');

	return result;
}

bool BoardTest()
{
	bool result;
	std::string bd;

	grid[0] = 'X'; grid[1] = 'X'; grid[2] = '-';
	grid[3] = 'O'; grid[4] = 'O'; grid[5] = 'X';
	grid[6] = '-'; grid[7] = 'X'; grid[8] = '-';

	bd = "\nX X X\nO O X\n- X -\n";
	result = (bd == board());

	grid[0] = 'X'; grid[1] = '-'; grid[2] = '-';
	grid[3] = 'X'; grid[4] = 'O'; grid[5] = 'X';
	grid[6] = '-'; grid[7] = 'O'; grid[8] = 'O';

	bd = "\nX - -\nX O X\n- O O\n";
	result = (!result) && (bd == board());

	return result;
}

bool Tester()
{
	bool(*func[8])() = { &InitializeTest,&VerticalWinnerTest,&HorizontalWinnerTest,&DiagonalWinnerTest,
		&WinnerTest,&HasMoveTest,&MakeMoveTest,&BoardTest}, result = true;

	std::string functions[8] = { "Initialize","VerticalWinner","HorizontalWinner","DiagonalWinner",
		"Winner", "HasMove", "MakeMove", "Board"};
	for (int i = 0; i < 8; i += 1)
	{
		std::cout << functions[i] << " Test ";
		std::cout << ((func[i]()) ? ("has passed.\n") : ("has failed.\n"));
		if (!func[i]())
		{
			result = false;
		}
	}

	std::cout << "\n";
	return result;
}

void initArray(int arr[])
{
	for(int i = 0;i < 9;i += 1)
	{
		arr[i] = i + 1;
	}
}

int findChoice(int arr[],int size,int choice)
{
	for(int i = 0;i < size;i += 1)
	{
		if(arr[i] == choice)
			return i;
	}

	return -1;
}

bool removeChoice(int arr[],int size,int choice)
{
	int index = findChoice(arr,size,choice);

	if(index == -1)
	{
		return false;
	}
	else
	{
		for(int i = index;i < size - 1;i += 1)
		{
			arr[i] = arr[i+1];
		}
		return true;
	}
}

int randomChoice(int arr[],int size)
{
	if(size == 0)
	{
		return 0;
	}
	else
	{
		int index = rand() % size;
		return arr[index];
	}
}

int canWin()
{
	for(int i = 0;i < 3;i += 1)
	{
		if(grid[i] == grid[i + 3] && grid[i] != '-')
		{
			return i + 6;
		}
		else if(grid[i] == grid[i + 6] && grid[i] != '-')
		{
			return i + 3;
		}
		else if(grid[i + 3] == grid[i + 6] && grid[i + 3] != '-')
		{
			return i;
		}
		else if(grid[3 * i] == grid[3 * i + 1] && grid[3 * i] != '-')
		{
			return (3 * i + 2);
		}
		else if(grid[3 * i] == grid[3 * i + 2] && grid[3 * i] != '-')
		{
			return (3 * i + 1);
		}
		else if(grid[3 * i + 1] == grid[3 * i + 2] && grid[3 * i + 1] != '-')
		{
			return (3 * i);
		}
	}

	if(grid[0] == grid[4] && grid[0] != '-')
	{
		return 8;
	}
	else if(grid[0] == grid[8] && grid[0] != '-')
	{
		return 4;
	}
	else if(grid[4] == grid[8] && grid[4] != '-')
	{
		return 0;
	}
	else if(grid[2] == grid[4] && grid[2] != '-')
	{
		return 6;
	}
	else if(grid[2] == grid[6] && grid[2] != '-')
	{
		return 4;
	}
	else if(grid[4] == grid[6] && grid[4] != '-')
	{
		return 2;
	}

	return -1;
}
#endif 
