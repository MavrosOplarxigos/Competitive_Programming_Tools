#include <bits/stdc++.h>
using namespace std;

int main(){

	char c;
	cin >> c;

	string vow = "aeiouy";

	for(size_t i=0; i<vow.size(); i++){
		if(vow[i] == c){
			cout << "Vowel!" << endl;
			return 0;
		}
	}

	cout << "Consonant!" << endl;

}