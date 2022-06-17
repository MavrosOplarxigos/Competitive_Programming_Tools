#include <bits/stdc++.h>
using namespace std;

int main(){

	// if OK we output 0 otherwise 1

	if(cin.eof()){
		cout << 0;
		return 0;
	}

	long long last;
	cin >> last;

	while(!cin.eof()){
		long long next;
		cin >> next;
		if(next < last){ // check if it is increasing
			cout << 1;
			return 0;
		}
		last = next;
	}

	cout << 0;

}