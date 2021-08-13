#include "NQueensProblem.h"
#include <iostream>
using std::cout;using std::cin;

QueensProblem::QueensProblem(int _numOfQueens):numofQueens(_numOfQueens)
{
	satrancTahtasi.resize(numofQueens);
	for (auto& chessrow : satrancTahtasi)
	{
		chessrow.resize(numofQueens);
	}
}
	void QueensProblem::cozum() {
		if (setQueens(0)) {
			printQueens();

		}
		else {
			cout << "Bir ��z�m yok...\n";
		}

	}
	bool QueensProblem::setQueens(int colIndex)
	{
		if (colIndex == numofQueens)
		{
			return true;
		}
		for (int rowIndex = 0; rowIndex < numofQueens; ++rowIndex)
		{
			if (gecerliHamle(rowIndex, colIndex)) {
				satrancTahtasi[rowIndex][colIndex] = 1;


				if (setQueens(colIndex + 1)) {
					return true;
				}
			// Vezir ta��n� verilen s�tuna yerle�tiremediysek BACKTRACKING uygulan�r
			// Ne yapmal�y�z? �tere etmeye devam etmeli ve s�radaki sat�r i�in i�lemi tekrarlamal�y�z

				satrancTahtasi[rowIndex][colIndex] = 0; //Backtracking i�lemi
			}
			
		}
		//t�m sat�rlara bakt�k ancak bir sonuca ulaiamad�k
		//vezirleri yerle�tiremedik ��nk� ge�ersiz hamle
		//backtrack uygular�z -> �nceki vezirin yerini de�i�tirirsek ��z�me ula�abiliriz
		return false;
	}
	void QueensProblem::printQueens() const
	{
		for (size_t i = 0; i < satrancTahtasi.size(); i++)
		{
			for (size_t j = 0;j < satrancTahtasi.size(); j++)
			{
				if (satrancTahtasi[i][j] == 1)
				{
					cout << " * ";
				}
				else
				{
					cout << " - ";

				}
			}
			cout << '\n';
		}
	}
	bool QueensProblem::gecerliHamle(int rowIndex, int colIndex)
	{
		for (int i = 0; i < colIndex; i++) {
			if (satrancTahtasi[rowIndex][i] == 1)
				return false;
		}
		for (int i = rowIndex, j = colIndex; i >= 0 && j >= 0; i--, j--)
		{
			if (satrancTahtasi[i][j] == 1)
				return false;
		}
		for (int i = rowIndex, j = colIndex; i < numofQueens&& j >= 0; i++, j--)
		{
			if (satrancTahtasi[i][j] == 1)
			{
				return false;
			}
		}
		return true;
	}

	void QueensProblem::initProgram()

	{
		
		int x;
		cout << "Please enter the size of the chess table: ";
		cin >> x;
		QueensProblem problem{ x };
		problem.cozum();
		
	}
	
