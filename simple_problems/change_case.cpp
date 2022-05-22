#include <bits/stdc++.h>
using namespace std;

string to_lower(string x){

	for(int i=0;i<(int)x.size();i++){
		if( x[i] < 97 ){ // we expect only English characters
			x[i] += 32;
		}
	}

	return x;

}

string to_upper(string x){

	for(int i=0;i<(int)x.size();i++){
		if( x[i] >= 97 ){ // we expect only English characters
			x[i] -= 32;
		}
	}

	return x;

}

int main(int argc, char * argv[]){
	
	// ASCII match integer values to characters
	// 1 byte = 8 bits -> 256 = 2^8 -> 0 - 255

	// cout << (int)('A') << endl;
	// cout << (int)('Z') << endl;
	// cout << (int)('a') << endl;
	// cout << (int)('z') << endl;

	// change_case [-l,-u] string

	if(argc != 3){
		cout << "Use: change_case [-l,-u] string" << endl;
		return 0;
	}

	string x = "";
	for(int i=0;argv[2][i]!='\0';i++){
		x += argv[2][i];
	}

	if( strcmp(argv[1],"-l") == 0){
		cout << to_lower(x) << endl;
		return 0;
	}
	if( strcmp(argv[1],"-u") == 0){
		cout << to_upper(x) << endl;
		return 0;
	}

	cout << "wrong parameters given!"<< endl;
	cout << "Use: change_case [-l,-u] string" << endl;
	return 0;

}