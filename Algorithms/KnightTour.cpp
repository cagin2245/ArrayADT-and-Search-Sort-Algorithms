#include <iostream>
#include <iomanip>

#include"KnightTour.h"
using std::cout;
const std::array<int, 8> KnightTour::xMove = { 2,1,-1,-2,-2,-1,1,2 };
const std::array<int, 8> KnightTour::yMove = { 1,2,2,1,-1,-2,-2,-1 };

KnightTour::KnightTour() {

	cozumMatrisi.resize(TAHTA_BUYUKLUGU);

	for (auto& submatrix : cozumMatrisi)
		submatrix.resize(TAHTA_BUYUKLUGU);
	initBoard();

}

void KnightTour::KnightTourProblemiCozumu() {
	//At (0,0) noktas�ndan ba�l�yor
	cozumMatrisi[0][0] = 0;

	//��z�m yoksa
	if (!problemiCoz(1, 0, 0)) {
		cout << "Uygun bir ��z�m bulunamad�...";
		
	}
	//��z�m varsa
	cozumuGoster();

}
bool KnightTour::problemiCoz(int stepCount, int x, int y) {
	//E�er son ad�mda ise: Ba�ar�l� (At t�m kareleri gezdi)
	if (stepCount == TAHTA_BUYUKLUGU * TAHTA_BUYUKLUGU)
	{
		return true;
	}
	//At'�n yapabilece�i t�m hamleler
	for (size_t i = 0; i < xMove.size(); ++i)
	{
		int nextX = x + xMove[i];
		int nextY = y + yMove[i];

		if (isValidMove(nextX, nextY))
		{
			cozumMatrisi[nextX][nextY] = stepCount;
			if (problemiCoz(stepCount + 1, nextX, nextY)) {
				return true;
			}
			cozumMatrisi[nextX][nextY] = INT_MIN;
		}

	}
	//T�m hamleleri denedik ama hi�biri ge�erli de�il, o zaman backtrack uygular�z.
	return false;
}

void KnightTour::cozumuGoster() {
	for (int i = 0; i < TAHTA_BUYUKLUGU; ++i)
	{
		cout << std::left;
		for (int j = 0; j < TAHTA_BUYUKLUGU; ++j)
		{
			cout << std::setw(2) << cozumMatrisi[i][j] << std::setw(2) << ' ';
		}
		cout << "\n";
	}
}
void KnightTour::initBoard() {
	// INT_MIN de�eri at'�n ge�erli kareyi ziyaret etmedi�i anlam�na geliyor
	for (int i = 0; i < TAHTA_BUYUKLUGU; ++i)
		for (int j = 0; j < TAHTA_BUYUKLUGU; ++j)
			cozumMatrisi[i][j] = INT_MIN;
}
bool KnightTour::isValidMove(int x, int y)
{
	//At tahtan�n d���nda olmamal�
	if (x < 0 || x >= TAHTA_BUYUKLUGU)
		return false;
	if (y < 0 || y >= TAHTA_BUYUKLUGU)
		return false;
	//At daha �nce ziyaret etti�i bir kareye u�ramamal�
	if (cozumMatrisi[x][y] != INT_MIN)
		return false;

	//(x,y) karesi at i�in uygun
	return true;
}
