#pragma once
#ifndef Player_H
#define Player_H
#endif

#include <iostream>
#include "ChessBoard.h"

using namespace std;

class Player
{
	public:

		char figure;
		string Name;
		int PlayerNumber;
		Player(string name, int number, ChessBoard chess, char fig);
		bool Move();

};

