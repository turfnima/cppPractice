//Turfnima
//17/8/10
//hash practice
//a quick hash map practice
//i had an error when include<hash_map>
//dunno yet what happened, will deal with it later.

//this is crucial for a classic "two sum" question, store numbers in a hash
//map so they can be accessed easily and fast, then compare if their sum equals to a
//specific target
//once one understands use of stl hash map or unordered map it will be fairly easy.

#include<unordered_map>
#include<string>
#include<iostream>

using namespace std;

int main() {
	//initialize some data
	unordered_map<int, string> firstTry;
	firstTry[188] = "some random data";
	firstTry[2000] = "harry porter";
	firstTry[1932] = "show me the money";

	if (firstTry.find(2000) != firstTry.end()) {
		cout << firstTry[2000] << endl;
		cout << "success! " << endl;
	}
	else cout << "error" << endl;


	getchar();
	getchar();
	return 0;
}