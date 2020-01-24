#include "ChessBoard.h"
#include <iostream>

using namespace std;

	/*char BoardArr[9][9] = { {' ','1','2','3','4','5','6','7','8'},
							{'a','X','X','X','X','X','X','X',' '},
							{'b','O','O','O','O','O','O','O',' '},
							{'c',' ',' ',' ',' ',' ',' ',' ',' '},
							{'d',' ',' ',' ','X',' ',' ',' ',' '},
							{'e',' ',' ',' ',' ',' ',' ',' ',' '},
							{'f',' ',' ',' ',' ',' ',' ',' ',' '},
							{'g',' ','O',' ','X',' ','O',' ','O'},
							{'h','O',' ',' ',' ',' ',' ','O',' '} 
	};
	*/
	char BoardArr[9][9] = { {' ','1','2','3','4','5','6','7','8'},
							{'a',' ','X',' ','X',' ','X',' ','X'},
							{'b','X',' ','X',' ','X',' ','X',' '},
							{'c',' ','X',' ','X',' ','X',' ','X'},
							{'d',' ',' ',' ',' ',' ',' ',' ',' '},
							{'e',' ',' ',' ',' ',' ',' ',' ',' '},
							{'f','O',' ','O',' ','O',' ','O',' '},
							{'g',' ','O',' ','O',' ','O',' ','O'},
							{'h','O',' ','O',' ','O',' ','O',' '}
	};

	void ChessBoard::DisplayBoard()
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << BoardArr[i][j] << " ";
			}
			cout << endl;
		}
	}

	bool ChessBoard::CorrectFigureSelection(int x, int y, int playerNumber)
	{
		if (x < 0 || x>8 || y < 0 || y>8)
		{
			return false;
		}
		if (playerNumber==1)
		{
			if (BoardArr[x][y]=='X'|| BoardArr[x][y] == 'x')
			{
				return true;
			}

		}

		if (playerNumber==2)
		{
			if (BoardArr[x][y] == 'O' || BoardArr[x][y] == 'o')
			{
				return true;
			}
		}
		return false;
	}

	bool ChessBoard::AttemptToMove(int x, int y, int playerNumber, int a, int b)
	{

		if (a < 0 || a>8 || b < 0 || b>8)
		{
			return false;
		}

		if (BoardArr[a][b] != ' ')
		{
			return false;
		}

		if (playerNumber == 1)
		{
			if (BoardArr[x][y] == 'X')
			{
				//Ruch o jeden do przodu
				if (a == x + 1 && (b == y + 1 || b == y - 1))
				{
					BoardArr[x][y] = ' ';
					BoardArr[a][b] = 'X';
					return true;

				}
				//Bicie do przodu
				if (a == x + 2 &&  b == y - 2)
				{
					if (BoardArr[a - 1][y - 1] == 'O' || BoardArr[a - 1][y - 1] == 'o')
					{					
						BoardArr[x][y] = ' ';
						BoardArr[a][b] = 'X';
						BoardArr[a - 1][y - 1] = ' ';
						return true;
					}

				}
				else if (a == x + 2 && b == y + 2)
				{
					if (BoardArr[a - 1][y + 1] == 'O' || BoardArr[a - 1][y + 1] == 'o')
					{
						BoardArr[x][y] = ' ';
						BoardArr[a][b] = 'X';
						BoardArr[a - 1][y + 1] = ' ';
						return true;
					}
				}
				//Bicie do tylu
				if (a == x - 2 && (b == y + 2 || b == y - 2))
				{
					if (BoardArr[a + 1][b - 1] == 'O' || BoardArr[a + 1][b - 1] == 'o')
					{
						BoardArr[x][y] = ' ';
						BoardArr[a][b] = 'X';
						BoardArr[a + 1][b - 1] = ' ';
						return true;
					}
					if (BoardArr[a + 1][b + 1] == 'O' || BoardArr[a + 1][b + 1] == 'o')
					{
						BoardArr[x][y] = ' ';
						BoardArr[a][b] = 'X';
						BoardArr[a + 1][b + 1] = ' ';
						return true;
					}
				}
				return false; //-<
			}
			//Ruch Queen X
			if (BoardArr[x][y] == 'x')
			{

				//Ruch o jeden do przodu
				if (a == x + 1 && (b == y + 1 || b == y - 1))
				{
					BoardArr[x][y] = ' ';
					BoardArr[a][b] = 'x';
					return true;

				}
				//Ruch o jeden do tylu
				if (a == x - 1 && (b == y + 1 || b == y - 1))
				{
					BoardArr[x][y] = ' ';
					BoardArr[a][b] = 'x';
					return true;

				}


				//Bicie do przodu
				if (a == x + 2 && (b == y + 2 || b == y - 2))
				{
					if (BoardArr[a - 1][b - 1] == 'O' || BoardArr[a - 1][b - 1] == 'o')
					{
						BoardArr[x][y] = ' ';
						BoardArr[a][b] = 'x';
						BoardArr[a - 1][b - 1] = ' ';
						return true;
					}
					if (BoardArr[a - 1][b + 1] == 'O' || BoardArr[a - 1][b + 1] == 'o')
					{
						BoardArr[x][y] = ' ';
						BoardArr[a][b] = 'x';
						BoardArr[a - 1][b + 1] = ' ';
						return true;
					}
				}
				//Bicie do tylu
				if (a == x - 2 && (b == y + 2 || b == y - 2))
				{
					if (BoardArr[a + 1][b - 1] == 'O' || BoardArr[a + 1][b - 1] == 'o')
					{
						BoardArr[x][y] = ' ';
						BoardArr[a][b] = 'x';
						BoardArr[a + 1][b - 1] = ' ';
						return true;
					}
					if (BoardArr[a + 1][b + 1] == 'O' || BoardArr[a + 1][b + 1] == 'o')
					{
						BoardArr[x][y] = ' ';
						BoardArr[a][b] = 'x';
						BoardArr[a + 1][b + 1] = ' ';
						return true;
					}
				}

				return false;
			}
		}

		if (playerNumber == 2) //Player 2
		{

			if (BoardArr[x][y] == 'O')
			{
				//Ruch o jeden do przodu
				if (a == x - 1 && (b == y + 1 || b == y - 1))
				{
					BoardArr[x][y] = ' ';
					BoardArr[a][b] = 'O';
					return true;

				}
				//Bicie do przodu
				if (a == x - 2 && (b == y + 2 || b == y - 2))
				{
					if (BoardArr[a + 1][b + 1] == 'X' || BoardArr[a + 1][b + 1] == 'x')
					{
						BoardArr[x][y] = ' ';
						BoardArr[a][b] = 'O';
						BoardArr[a + 1][b + 1] = ' ';
						return true;
					}

					if (BoardArr[a + 1][b - 1] == 'X' || BoardArr[a + 1][b - 1] == 'x')
					{
						
						BoardArr[x][y] = ' ';
						BoardArr[a][b] = 'O';
						BoardArr[a + 1][b - 1] = ' ';
						return true;
					}

				}
				//Bicie do tylu
				if (a == x + 2 && (b == y + 2 || b == y - 2))
				{
					if (BoardArr[a - 1][b + 1] == 'X' || BoardArr[a - 1][b + 1] == 'x')
					{
						BoardArr[x][y] = ' ';
						BoardArr[a][b] = 'O';
						BoardArr[a - 1][b + 1] = ' ';
						return true;
					}

					if (BoardArr[a - 1][b - 1] == 'X' || BoardArr[a - 1][b - 1] == 'x')
					{
						BoardArr[x][y] = ' ';
						BoardArr[a][b] = 'O';
						BoardArr[a - 1][b - 1] = ' ';
						return true;
					}

				}
			}
	
			if (BoardArr[x][y] == 'o')
			{
				//Ruch o jeden do przodu
				if (a == x - 1 && (b == y + 1 || b == y - 1))
				{
					BoardArr[x][y] = ' ';
					BoardArr[a][b] = 'o';
					return true;

				}
				//Ruch o jeden do tylu
				if (a == x + 1 && (b == y + 1 || b == y - 1))
				{
					BoardArr[x][y] = ' ';
					BoardArr[a][b] = 'o';
					return true;

				}
				//Bicie do przodu
				if (a == x - 2 && (b == y + 2 || b == y - 2))
				{
					if (BoardArr[a + 1][b + 1] == 'X' || BoardArr[a + 1][b + 1] == 'x')
					{
						BoardArr[x][y] = ' ';
						BoardArr[a][b] = 'o';
						BoardArr[a + 1][b + 1] = ' ';
						return true;
					}

					if (BoardArr[a + 1][b - 1] == 'X' || BoardArr[a + 1][b - 1] == 'x')
					{
						BoardArr[x][y] = ' ';
						BoardArr[a][b] = 'o';
						BoardArr[a + 1][b - 1] = ' ';
						return true;
					}

				}
				//Bicie do tylu
				if (a == x + 2 && (b == y + 2 || b == y - 2))
				{
					if (BoardArr[a - 1][b + 1] == 'X' || BoardArr[a - 1][b + 1] == 'x')
					{
						BoardArr[x][y] = ' ';
						BoardArr[a][b] = 'o';
						BoardArr[a - 1][b + 1] = ' ';
						return true;
					}

					if (BoardArr[a - 1][b - 1] == 'X' || BoardArr[a - 1][b - 1] == 'x')
					{
						BoardArr[x][y] = ' ';
						BoardArr[a][b] = 'o';
						BoardArr[a - 1][b - 1] = ' ';
						return true;
					}

					return false;
				}
			}
			return false;
		}
	}

	void ChessBoard::CountFigures(int playerNumber, string playerName, string winner)
	{
		int counter = 0;
		char figure1, figure2;
		if (playerNumber==1)
		{
			figure1 = 'X';
			figure2 = 'x';
		}
		if (playerNumber==2)
		{
			figure1 = 'O';
			figure2 = 'o';
		}

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (BoardArr[i][j] == figure1 || BoardArr[i][j] == figure2)
				{
					counter++;
				}
			}
		}

		if (counter<2)
		{
			cout << "GRATULACJE !!!" << endl;
			cout << "Zwyciezyl gracz: " << winner << endl;
			system("pause");
			exit(0);
		}

	}

	void ChessBoard::TurnToQueens(int playerNumber)
	{
		if (playerNumber==1)
		{
			for (int i = 1; i <= 8; i++)
			{
				if (BoardArr[8][i] == 'X')
				{
					BoardArr[8][i] = 'x';
					return;
				}
			}
		}
		if (playerNumber==2)
		{
			for (int i = 1; i <= 8; i++)
			{
				if (BoardArr[1][i] == 'O')
				{
					BoardArr[1][i] = 'o';
					return;
				}
			}
		}
	}
	