#pragma once
#ifndef ChessBoard_H
#define ChessBoard_H
#endif
#include <string>
using namespace std;

class ChessBoard
{
	public:
		
		void DisplayBoard();
		bool CorrectFigureSelection(int x, int y, int playerNumber);
		bool AttemptToMove(int x, int y, int playerNumber, int a, int b);
		void CountFigures(int playerNumber, string playerName, string winner);
		void TurnToQueens(int playerNumber);
		//void ZeroMoves(int playerNumber);
};

