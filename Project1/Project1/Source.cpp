#pragma once
#include "cMember.h"
#include "Population.h"
#include <iostream>
#include "cLoader.h"

using namespace std;

void TestMatrix(int s, int **matrix) {

	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

void TestOrder(vector<cMember*> *v) {

	for each (cMember* m in *v) {
		for each(int i in m->fOrder) {
			cout << i << " ";
		}
		cout << endl;
	}
}

void TestPopulation(vector<cMember*> *v){
	for (int i = 0; i < v->size(); i++) {
		cout << v->at(i)->fId;
	}
}


int main() {

	const int MembersAmount = 2;

	cLoader load;
	Population pop;
	

	//Wypełniamy Tablice referencji
	pop.fRefMatrix = load.mLoadMatrix();

	//Okreslanie wielkości macierzy oraz populacji
	pop.fPopSize = MembersAmount;
	pop.fRefMatrixSize = load.size;

	//@TEST OK TestMatrix(pop.fRefMatrixSize, pop.fRefMatrix);

	//Inicjacja Osobników
	pop.mInitializeMembers();
	pop.mDrawMembers();
//	pop.mChoseBestMember();
	///*@TEST OK*/ TestPopulation(&pop.fPopulation);
	/*@Test OK*/ TestOrder(&pop.fPopulation); 

	pop.mPrintMembers();

	
	//load.mLoadMatrix();
	system("pause");
}

