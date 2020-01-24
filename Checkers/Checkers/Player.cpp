#include <iostream>
#include "Player.h"

using namespace std;


	string Name;
	int PlayerNumber;
	ChessBoard chessboard;
	char figure;


Player::Player(string name, int number, ChessBoard chess, char fig)
{
	Name = name;
	PlayerNumber = number;
	chessboard = chess;
	figure = fig;
}

bool Player::Move()
{

	int  y=0, b=0, x=0, a=0;
	char xChar, aChar;

	cout << endl;
	cout << "Ruch gracza: " << Name << ". Wybierz swojego pionka: " << figure << " (np: c 2)." << endl;
		if (!(cin>>xChar))
	{
		cin.clear();
		cin.ignore();
		system("cls");
		cout << "Wpisz litere a-h" << endl;
		return false;
	}

	switch (xChar)
	{
	case 'a':
	case 'A':
		x = 1;
		break;
	case 'b':
	case 'B':
		x = 2;
		break;
	case 'c':
	case 'C':
		x = 3;
		break;
	case 'd':
	case 'D':
		x = 4;
		break;
	case 'e':
	case 'E':
		x = 5;
		break;
	case 'f':
	case 'F':
		x = 6;
		break;
	case 'g':
	case 'G':
		x = 7;
		break;
	case 'h':
	case 'H':
		x = 8;
		break;
	default:
		x = 9;
		break;
	}

	//cin >> x;

	if (!(cin >> y))
	{
		cin.clear();
		cin.ignore();
		system("cls");
		cout << "Wpisz liczbe 1-8" << endl;
		return false;
	}
	//cin >> y;

	if (chessboard.CorrectFigureSelection(x,y,PlayerNumber)==false)
	{
		system("cls");
		cout << "Wybrano niewlasciwe pole" << endl;
		return false;
	}

	cout << "Wybierz gdzie go przesunac (np: d 3)." << endl;
	//cin >> a;
			if (!(cin >> aChar))
	{
		cin.clear();
		cin.ignore();
		system("cls");
		cout << "Wpisz porawne wartosci!" << endl;
		return false;
	}


	switch (aChar)
	{
	case 'a':
	case 'A':
		a = 1;
		break;
	case 'b':
	case 'B':
		a = 2;
		break;
	case 'c':
	case 'C':
		a = 3;
		break;
	case 'd':
	case 'D':
		a = 4;
		break;
	case 'e':
	case 'E':
		a = 5;
		break;
	case 'f':
	case 'F':
		a = 6;
		break;
	case 'g':
	case 'G':
		a = 7;
		break;
	case 'h':
	case 'H':
		a = 8;
		break;
	default:
		a = 9;
		break;
	}


	if (!(cin >> b))
	{
		cin.clear();
		cin.ignore();
		system("cls");
		cout << "Wpisz poprawne wartosci!" << endl;
		return false;
	}
	//cin >> b;

	if (chessboard.AttemptToMove(x,y,PlayerNumber,a,b)==false)
	{
		system("cls");
		cout << "Pole jest zajete lub niezgodnosc z zasadami gry" << endl;
		return false;
	}
	else
	{
		system("cls");
		cout << "Przesunieto pionek: " << xChar << "," << y << " -> " << aChar << "," << b << endl;
	}
	return true;

}
