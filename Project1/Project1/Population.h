#pragma once
#include "cMember.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>

class Population
{
public:
	Population();
	Population::Population(int Size);

	~Population();

	int fPopSize;
	int **fRefMatrix;
	int fRefMatrixSize;
	cMember fBestMemberRef;
	vector <cMember*> fPopulation;
	vector <bool> OrderFlag;


	void mDrawMembers() {
		srand(time(NULL));
		for each (cMember *m in fPopulation) {
			for (int i = 0; i < fRefMatrixSize; i++) {
				int val = 0;
				do {
					val = rand() % fRefMatrixSize;
				} while (OrderFlag[val] != true);
				
				//cout << val << " ";
				m->fOrder[i] = val;
				OrderFlag[val] = false;	
			}
			OrderFlag = setFlag(OrderFlag, true);
			mSumLength(*&m);
			//cout << m.fLengeth<<endl;
			//cout<<"iii: "<< OrderFlag[0] << endl;
		}
	}
		
	vector<bool> setFlag(vector<bool> v, bool value) {
		for (int i = 0; i < fRefMatrixSize; i++) {
			v[i] = value;
		}
		return v;
	}
	
	void mChoseBestMember() {
		for each (cMember *m in fPopulation) {
			if (m->fLengeth < fBestMemberRef.fLengeth)
				fBestMemberRef.fLengeth = m->fLengeth;
		}
	}

	void mSumLength(cMember *m) {
		for (int i = 0; i < m->fOrder.size() -1 ; i++) {
			m->fLengeth += *fRefMatrix[m->fOrder[i], m->fOrder[i + 1]];
			//cout << "length: " << *fRefMatrix[m.fOrder[i], m.fOrder[i + 1]] << endl;
		}
		//cout << m->fLengeth << endl;
	}

	void mPrintMembers() {
		for each (cMember * m in fPopulation){
			cout << m->fLengeth << endl;
		}
	}

	void mInitializeMembers() {
		
		
		for (int i = 0; i < fPopSize; i++) {
			fPopulation.push_back(new cMember(i, fRefMatrixSize));
			
		}
		for (int i = 0; i < fRefMatrixSize; i++) {
			OrderFlag.push_back(true);
		}
		//mDrawMembers();
		//mChoseBestMember();
		//mPrintMembers();
		//@TEST cout << fPopulation.size();
	}


};

