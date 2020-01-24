#include <iostream>
#include "ChessBoard.h"
#include "Player.h"
using namespace std;

int main()
{
	//Tworzy obiekt szachownicy
	ChessBoard cb;
	
	//Tworzy 2 obiekty graczy
	cout << "Wpisz imie pierwszego gracza" << endl;
	string name1;
	cin >> name1;
	cout << "Wpisz imie dgrugiego gracza" << endl;
	string name2;
	cin >> name2;

	Player player1(name1, 1,cb,'X');
	Player player2(name2, 2,cb,'O');

	system("cls");
	
	bool canPlayer1Move = false;

	//Petla gry
	while (true)
	{
		do
		{
			cb.DisplayBoard();
			canPlayer1Move = player1.Move();
		} while (canPlayer1Move==false);
		cb.CountFigures(2, name2, name1);
		cb.TurnToQueens(1);


		do
		{
			cb.DisplayBoard();
			canPlayer1Move = player2.Move();
		} while (canPlayer1Move == false);
		cb.CountFigures(1, name1, name2);
		cb.TurnToQueens(2);

	}
}


