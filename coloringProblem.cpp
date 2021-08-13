#include <iostream>
#include <stdio.h>
#include "GraphColoring.h"
using std::cout;

// NP-Complete problem
// Muhtemel durumlar�n say�s� �stel art�� g�sterir
// O(n^v) (v: k��e) karma��kl���nda �al���r
// Brute force ile �stel zaman karma��kl��� yakalan�r
// Bipartite graf, s�nav takvimi, radyo frekans atanmas�, register allocation, harita renklendirme vs.

/* Yakla��mlar
1) Greedy: ��z�m bulunur ancak en uygun ��z�m olma zorunlulu�u yoktur
2) Backtracking: Bad state'lerin �o�unlu�unu tek iterasyonda reddeder (veya recursive fonksiyon �a�r�s�nda) 
3) Powell-Welsh algorithm: node'lar�n derecesine g�re s�ralanmas�na dayan�r (k��e say�s�na g�re)
*/

GraphColoring::GraphColoring(const vector<vector<int>>& graph, int _renkSayisi): graphMatrix(graph), renkSayisi(_renkSayisi)
{
	renkler.resize(graphMatrix.size());

}
void GraphColoring::operator()() {
	
		if (solve(0))
		{
			sonucuGoster();
		}
		else {
			cout << "Girilen parametrelere uygun ��z�m yok...";
		}
	}

// recursive �ekilde renkleri atayacak fonksiyon
bool GraphColoring::solve(size_t nodeIndex)
{
	//grafdaki t�m nodelar� g�ze al�p renkleri istenen �ekilde atayabildiysek backtracking ile renklendirme problemini ba�ar�yla sonu�land�rd�k
	if (nodeIndex == graphMatrix.size()) {
		return true;
	}
	//t�m renkleri dene
	for (int colorIndex = 1; colorIndex <= renkSayisi; colorIndex++)
	{
		//E�er ge�erliyse renk atama
		if (isColorValid(nodeIndex, colorIndex)) {
			renkler[nodeIndex] = colorIndex;


			//sonraki node'un rengini bulma
			if (solve(nodeIndex + 1))
			{
				return true;
			}
			return false;
		}

	}
}

//verilen k��ede do�ru renk olup olmad���n� kontrol eden fonksiyon
bool GraphColoring::isColorValid(size_t nodeIndex,size_t colorIndex)
{
	for (size_t i = 0; i < graphMatrix.size(); i++)
	{
		if (graphMatrix[nodeIndex][i] == 1 && colorIndex == renkler[i])
			return false;
	}

}


void GraphColoring::sonucuGoster() {
	for (size_t  i = 0; i < graphMatrix.size(); i++)
	{
		cout << "Node " << i + 1 <<":  " << renkler[i] << " renk indexine sahip" << "\n";
	}
}
