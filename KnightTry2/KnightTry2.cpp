#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

#define X 7
#define Y 5

int startPosX;
int startPosY;

int solveKTUtil(int x, int y, int movei, int sol[X][Y],
	int xMove[], int yMove[]);

bool isSafe(int x, int y, int sol[X][Y])
{
	return (x >= 0 && x < X && y >= 0 &&
		y < Y && sol[x][y] == -1);
}

void printSolution(int sol[X][Y])
{
	for (int x = 0; x < X; x++)
	{
		for (int y = 0; y < Y; y++)
			cout << setw(3) << sol[x][y] << " ";
		cout << endl;
	}
	cout << endl;
}

bool solveKT()
{
	int sol[X][Y];

	for (int x = 0; x < X; x++)
		for (int y = 0; y < Y; y++)
			sol[x][y] = -1;

	// Possible moves
	int xMove[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
	int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

	// Start Knight at given position
	sol[startPosX][startPosY] = 0;

	// Start from start position and explore all tours 
	if (solveKTUtil(startPosX, startPosY, 1, sol, xMove, yMove) == false)
	{
		cout << "Solution does not exist" << endl;
		return false;
	}
	else
		printSolution(sol);

	return true;
}

int solveKTUtil(int x, int y, int movei, int sol[X][Y],
	int xMove[X], int yMove[Y])
{
	int k, next_x, next_y;
	if (movei == X*Y)
		return true;

	/* Try all next moves from the current coordinate x, y */
	for (k = 0; k < 8; k++)
	{
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if (isSafe(next_x, next_y, sol))
		{
			sol[next_x][next_y] = movei;
			if (solveKTUtil(next_x, next_y, movei + 1, sol,
				xMove, yMove))
				return true;
			else
				sol[next_x][next_y] = -1;// backtracking 
		}
	}

	return false;
}

int main() {
	cout << "Where would you like the knight to start?" << endl << endl;
	cout << "Please enter the X position" << endl;
	cin >> startPosY;
	cout << "Please enter the Y position" << endl;
	cin >> startPosX;
	cout << endl;
	solveKT();
	system("pause");
	return 0;
}