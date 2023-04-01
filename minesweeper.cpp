#include<bits/stdc++.h>
using namespace std;

#define BEGINNER 0
#define INTERMEDIATE 1
#define ADVANCED 2
#define MAXSIDE 25
#define MAXMINES 99
#define MOVESIZE 526 // (25 * 25 - 99)

int SIDE ; 
int MINES ; 

bool isValid(int row, int col)
{

	return (row >= 0) && (row < SIDE) &&
		(col >= 0) && (col < SIDE);
}

bool isMine (int row, int col, char board[][MAXSIDE])
{
	if (board[row][col] == '*')
		return (true);
	else
		return (false);
}

{
	printf("Enter your move, (row, column) -> ");
	scanf("%d %d", x, y);
	return;
}

void printBoard(char myBoard[][MAXSIDE])
{
	int i, j;

	printf (" ");

	for (i=0; i<SIDE; i++)
		printf ("%d ", i);

	printf ("\n\n");

	for (i=0; i<SIDE; i++)
	{
		printf ("%d ", i);

		for (j=0; j<SIDE; j++)
			printf ("%c ", myBoard[i][j]);
		printf ("\n");
	}
	return;
}

int countAdjacentMines(int row, int col, int mines[][2],
					char realBoard[][MAXSIDE])
{

	int i;
	int count = 0;
  
		if (isValid (row-1, col) == true)
		{
			if (isMine (row-1, col, realBoard) == true)
			count++;
		}
		if (isValid (row+1, col) == true)
		{
			if (isMine (row+1, col, realBoard) == true)
			count++;
		}
		if (isValid (row, col+1) == true)
		{
			if (isMine (row, col+1, realBoard) == true)
			count++;
		}
		if (isValid (row, col-1) == true)
		{
			if (isMine (row, col-1, realBoard) == true)
			count++;
		}
		if (isValid (row-1, col+1) == true)
		{
			if (isMine (row-1, col+1, realBoard) == true)
			count++;
		}
		if (isValid (row-1, col-1) == true)
		{
			if (isMine (row-1, col-1, realBoard) == true)
			count++;
		}
		if (isValid (row+1, col+1) == true)
		{
			if (isMine (row+1, col+1, realBoard) == true)
			count++;
		}
		if (isValid (row+1, col-1) == true)
		{
			if (isMine (row+1, col-1, realBoard) == true)
			count++;
		}

	return (count);
}

bool playMinesweeperUtil(char myBoard[][MAXSIDE], char realBoard[][MAXSIDE],
			int mines[][2], int row, int col, int *movesLeft)
{

	if (myBoard[row][col] != '-')
		return (false);

	int i, j;

	if (realBoard[row][col] == '*')
	{
		myBoard[row][col]='*';

		for (i=0; i<MINES; i++)
			myBoard[mines[i][0]][mines[i][1]]='*';

		printBoard (myBoard);
		printf ("\nYou lost!\n");
		return (true) ;
	}

	else
	{
		int count = countAdjacentMines(row, col, mines, realBoard);
		(*movesLeft)--;

		myBoard[row][col] = count + '0';

		if (!count)
		{

			if (isValid (row-1, col) == true)
			{
				if (isMine (row-1, col, realBoard) == false)
				playMinesweeperUtil(myBoard, realBoard, mines, row-1, col, movesLeft);
			}
			if (isValid (row+1, col) == true)
			{
				if (isMine (row+1, col, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row+1, col, movesLeft);
			}
			if (isValid (row, col+1) == true)
			{
				if (isMine (row, col+1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row, col+1, movesLeft);
			}
			if (isValid (row, col-1) == true)
			{
				if (isMine (row, col-1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row, col-1, movesLeft);
			}
			if (isValid (row-1, col+1) == true)
			{
				if (isMine (row-1, col+1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row-1, col+1, movesLeft);
			}
			if (isValid (row-1, col-1) == true)
			{
				if (isMine (row-1, col-1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row-1, col-1, movesLeft);
			}
			if (isValid (row+1, col+1) == true)
			{
				if (isMine (row+1, col+1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row+1, col+1, movesLeft);
			}
			if (isValid (row+1, col-1) == true)
			{
				if (isMine (row+1, col-1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row+1, col-1, movesLeft);
			}
		}

		return (false);
	}
}
void placeMines(int mines[][2], char realBoard[][MAXSIDE])
{
	bool mark[MAXSIDE*MAXSIDE];

	memset (mark, false, sizeof (mark));

	for (int i=0; i<MINES; )
	{
		int random = rand() % (SIDE*SIDE);
		int x = random / SIDE;
		int y = random % SIDE;
		if (mark[random] == false)
		{
			mines[i][0]= x;
			mines[i][1] = y;

			realBoard[mines[i][0]][mines[i][1]] = '*';
			mark[random] = true;
			i++;
		}
	}

	return;
}
void initialise(char realBoard[][MAXSIDE], char myBoard[][MAXSIDE])
{
	srand(time (NULL));
	for (int i=0; i<SIDE; i++)
	{
		for (int j=0; j<SIDE; j++)
		{
			myBoard[i][j] = realBoard[i][j] = '-';
		}
	}

	return;
}
void replaceMine (int row, int col, char board[][MAXSIDE])
{
	for (int i=0; i<SIDE; i++)
	{
		for (int j=0; j<SIDE; j++)
			{
				if (board[i][j] != '*')
				{
					board[i][j] = '*';
					board[row][col] = '-';
					return;
				}
			}
	}
	return;
}
void playMinesweeper ()
{
	bool gameOver = false;

	char realBoard[MAXSIDE][MAXSIDE], myBoard[MAXSIDE][MAXSIDE];

	int movesLeft = SIDE * SIDE - MINES, x, y;
	int mines[MAXMINES][2]; 

	initialise (realBoard, myBoard);
  
	placeMines (mines, realBoard);

	int currentMoveIndex = 0;
	while (gameOver == false)
	{
		printf ("Current status of the board: \n");
		printBoard (myBoard);
		makeMove (&x, &y);

		if (currentMoveIndex == 0)
		{
      
			if (isMine (x, y, realBoard) == true)
				replaceMine (x, y, realBoard);
		}

		currentMoveIndex ++;

		gameOver = playMinesweeperUtil (myBoard, realBoard, mines, x, y, &movesLeft);

		if ((gameOver == false) && (movesLeft == 0))
		{
			printf ("\nYou won!\n");
			gameOver = true;
		}
	}
	return;
}

void chooseDifficultyLevel ()
{

	int level;

	printf ("Enter the Difficulty Level\n");
	printf ("Press 0 for Easy (9 x 9 Cells and 10 mines)\n");
	printf ("Press 1 for Medium (16 x 16 Cells and 40 mines)\n");
	printf ("Press 2 for Hard (24 x 24 Cells and 99 mines)\n");

	scanf ("%d", &level);

	if (level == BEGINNER)
	{
		SIDE = 9;
		MINES = 10;
	}

	if (level == INTERMEDIATE)
	{
		SIDE = 16;
		MINES = 40;
	}

	if (level == ADVANCED)
	{
		SIDE = 24;
		MINES = 99;
	}

	return;
}

int main()
{
	chooseDifficultyLevel ();

	playMinesweeper ();

	return (0);
}
