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
	bool result = (a == '-');
	result = result && (b == '-');
	result = result && (c == '-');
	result = result && (d == '-');
	result = result && (e == '-');
	result = result && (f == '-');
	result = result && (g == '-');
	result = result && (h == '-');
	result = result && (i == '-');

	return result;
}

bool VerticalWinnerTest()
{
	bool result;

	a = 'X'; b = 'X'; c = '-';
	d = 'O'; e = 'O'; f = 'X';
	g = '-'; h = 'X'; i = '-';

	result = verticalWinner();

	a = 'X'; b = 'X'; c = 'X';
	d = 'O'; e = 'O'; f = 'X';
	g = '-'; h = 'X'; i = 'X';

	result = (!result) && verticalWinner();

	a = 'X'; b = 'X'; c = '-';
	d = 'O'; e = 'X'; f = 'O';
	g = '-'; h = 'X'; i = '-';

	result = result && verticalWinner();

	a = 'X'; b = 'X'; c = '-';
	d = 'X'; e = 'O'; f = 'X';
	g = 'X'; h = 'X'; i = 'X';

	result = result && verticalWinner();

	return result;
}

bool HorizontalWinnerTest()
{
	bool result;

	a = 'X'; b = 'X'; c = '-';
	d = 'O'; e = 'O'; f = 'X';
	g = '-'; h = 'X'; i = '-';

	result = horizontalWinner();

	a = 'X'; b = 'X'; c = 'X';
	d = 'O'; e = 'O'; f = 'X';
	g = '-'; h = 'X'; i = '-';

	result = (!result) && horizontalWinner();

	a = 'X'; b = 'X'; c = '-';
	d = 'O'; e = 'O'; f = 'O';
	g = '-'; h = 'X'; i = '-';

	result = result && horizontalWinner();

	a = 'X'; b = 'X'; c = '-';
	d = 'O'; e = 'O'; f = 'X';
	g = 'X'; h = 'X'; i = 'X';

	result = result && horizontalWinner();

	return result;
}

bool DiagonalWinnerTest()
{
	bool result;

	a = 'X'; b = 'X'; c = '-';
	d = 'O'; e = 'O'; f = 'X';
	g = '-'; h = 'X'; i = '-';

	result = diagonalWinner();

	a = 'X'; b = 'X'; c = '-';
	d = 'O'; e = 'X'; f = '-';
	g = '-'; h = 'X'; i = 'X';

	result = (!result) && diagonalWinner();

	a = 'X'; b = 'X'; c = 'O';
	d = 'O'; e = 'O'; f = 'O';
	g = 'O'; h = 'X'; i = '-';

	result = result && diagonalWinner();

	return result;
}

bool WinnerTest()
{
	bool result;

	a = 'X'; b = 'X'; c = '-';
	d = 'O'; e = 'O'; f = 'X';
	g = '-'; h = 'X'; i = '-';

	result = winner();

	a = 'X'; b = 'X'; c = 'X';
	d = 'O'; e = 'O'; f = 'X';
	g = '-'; h = 'X'; i = 'X';

	result = (!result) && winner();

	a = 'X'; b = 'X'; c = '-';
	d = 'O'; e = 'X'; f = 'O';
	g = '-'; h = 'X'; i = '-';

	result = result && winner();

	a = 'X'; b = 'X'; c = '-';
	d = 'X'; e = 'O'; f = 'X';
	g = 'X'; h = 'X'; i = 'X';

	result = result && winner();

	a = 'X'; b = 'X'; c = 'X';
	d = 'O'; e = 'O'; f = 'X';
	g = '-'; h = 'X'; i = '-';

	result = result && winner();

	a = 'X'; b = 'X'; c = '-';
	d = 'O'; e = 'O'; f = 'O';
	g = '-'; h = 'X'; i = '-';

	result = result && winner();

	a = 'X'; b = 'X'; c = '-';
	d = 'O'; e = 'O'; f = 'X';
	g = 'X'; h = 'X'; i = 'X';

	result = result && winner();

	a = 'X'; b = 'X'; c = '-';
	d = 'O'; e = 'X'; f = '-';
	g = '-'; h = 'X'; i = 'X';

	result = result && winner();

	a = 'X'; b = 'X'; c = 'O';
	d = 'O'; e = 'O'; f = 'O';
	g = 'O'; h = 'X'; i = '-';

	result = result && winner();

	return result;
}

bool HasMoveTest()
{
	bool result;

	a = 'X'; b = 'X'; c = '-';
	d = 'O'; e = 'O'; f = 'X';
	g = '-'; h = 'X'; i = '-';

	result = hasMove();

	a = 'X'; b = 'X'; c = 'X';
	d = 'O'; e = 'O'; f = 'X';
	g = 'X'; h = 'X'; i = 'X';

	result = result && !hasMove();

	return result;
}

bool MakeMoveTest()
{
	bool result;

	a = 'X'; b = 'X'; c = '-';
	d = 'O'; e = 'O'; f = 'X';
	g = '-'; h = 'X'; i = '-';

	result = makeMove(2,'O');
	result = (!result) && makeMove(7,'O');

	return result;
}

bool BoardTest()
{
	bool result;
	std::string bd;

	a = 'X'; b = 'X'; c = '-';
	d = 'O'; e = 'O'; f = 'X';
	g = '-'; h = 'X'; i = '-';

	bd = "\nX X -\nO O X\n- X -\n";
	result = (bd == board());

	a = 'X'; b = '-'; c = '-';
	d = 'X'; e = 'O'; f = 'X';
	g = '-'; h = 'O'; i = 'O';

	bd = "\nX - -\nX O X\n- O O\n";
	result = result && (bd == board());

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


#endif 
