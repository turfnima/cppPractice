#include<iostream>
#include<random>
#include<string>

//Xiaozhi Li
// 2017/11/5
//code for fun...
//my cousin was playing a game£º Onmyouji
// he asks if anyone can calculate the hit effect of a char.
//so the char casts a snow storm, apply on hit effects three times,
//each time,there is freeze, slow, and additional freeze from item.

//the freeze rate was 8 percent, slow rate was 16 percent, and additional freeze rate from item is 12 percent.
//if an enemy is slowed, the chance of him or her getting frozen raises 10% (multiply)
//his char has a 102% hit ratio, which means all the on hit effect will apply to this.

//so my cousin wants to know for 5 enemies getting hit, what are the chances of 1, 2 ,3,4 ,and 5 enemies getting frozen.
//I hate to calculate it with binomial distribution, so I wrote this code.
using namespace std;

class enemy {
public:
	bool frozen;
	bool slowed;

	//constructor
	enemy() {
		frozen = false;
		slowed = false;
	}

	//initialize
	void initialize() {
		frozen = false;
		slowed = false;
	}


	bool testFrozen(int frate, bool slowed) {

		return false;
	}


	bool testSlowed(int srate) {
		return false;
	}
	void printCondition() {
		cout << "slowed:" << slowed;
		cout << "  frozen: " << frozen << endl;
	}
	enemy& operator=(const enemy& b) {
		frozen = b.frozen;
		slowed = b.slowed;
	}
};

//functions:
bool freezeOrNot(enemy &e, int frate) ;
bool slowOrNot(enemy &e, int srate);
// ~functions


int main() {
	//first we set the freeze rate, slow rate, armor effect:
	int frate = 8;
	int srate = 16;
	int aeffect = 12;
	int hits = 3;

	double hitRatio = 1.02;

	//then we create an enemy
	cout << "slow rate:";
	cout << srate;
	cout << "	freeze rate: ";
	cout << frate;

	cout << "	armor effect: ";
	cout << aeffect;

	enemy ass[5];


	//then we do tests
	int tests = 1000000;
	double sum[6];
	
	for (int i = 0; i < 6; i++) sum[i] = 0;


	for (int i = 0; i < tests; i++) {
		//we initialize ass
		for(int i=0;i<5;i++) ass[i].initialize();
		

		//every 3 strikes
		for(int j=0; j<hits; j++){
			//calculate for each person
			for(int p=0;p<5;p++){

				//first apply freeze chance
			freezeOrNot(ass[p], frate);
				//then apply armor freeze chance
			freezeOrNot(ass[p], aeffect);
			// then apply slow
			slowOrNot(ass[p], srate);
			}
		}
		//calculate how many was frozen:
		int nums = 0;
		for (int i = 0; i < 5; i++) {
			if (ass[i].frozen) nums += 1;
		}
		sum[nums]++;
	}
	for(int i=0;i<6;i++){
		double k = sum[i] / tests * 100;
		cout <<endl<< i << "ÈË±»±ù¶³¸ÅÂÊ£º ";
		cout<< k;
		cout << "/100" << endl;
	}

	getchar();
	getchar();
	return 0;
}


bool freezeOrNot(enemy &e, int frate) {
	//if enemy is already frozen, return
	if (e.frozen) { return true; }
	else {
		//if enemy is slowed, apply additional frate namely 10%
		if (e.slowed) {
			int k = rand() % 101;
			if (k <= frate*1.1*1.02) {
				//cout << "slowed, freezed  "<<endl;
				e.frozen = true;
				return true;
			}
			else return false;
		}
		//if enemy is not slowed, apply normal freeze rate
		else {
			int k = rand() % 101;
			if (k <= frate*1.02) {
				//cout << "not slowed, freezed"<<endl;
				e.frozen = true;
				return true;
			}
			else return false;
		}

	}

	return false;
}

bool slowOrNot(enemy &e, int srate) {
	if (e.slowed) { return true; }
	else {
		int k = rand() % 101;
		if (k <= srate) {
			//cout << "slowed" << endl;
			e.slowed = true;
			return true;
		}
	}
	return false;
}