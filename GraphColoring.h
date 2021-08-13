#pragma once
#include <iostream>
#include <vector>
using std::vector;

class GraphColoring {
	vector<vector<int>> graphMatrix;
	int renkSayisi;
	vector<int> renkler;

public:
	GraphColoring(const vector<vector<int>>& graph, int _renkSayisi);
	
		// problem ��z�m� 
		void operator()();
	
private:
	// renkleri recursive �ekilde atayacak fonksiyon
	bool solve(size_t nodeIndex);

	// renk atamas�n�n ge�erli olup olmad���n� kontrol edecek fonksiyon
	bool isColorValid(size_t nodeIndex, size_t colorIndex);
	void sonucuGoster();

};