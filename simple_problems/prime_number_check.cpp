#include <bits/stdc++.h>
using namespace std;

int main(){

	long long x;
	cin >> x;

	// checking from 3 up until the square root of the number
	for(long long i=3; i*i <= x; i+=2){
		if( x%i == 0 ){
			cout << "Not prime!" << endl;
			return 0;
		}
	}
	
	// corner cases
	if( ( (x%2==0) && (x!=2) ) || (x == 1) ){
		cout << "Not prime!" << endl;
		return 0;
	}

	cout << "Prime!" << endl;

}
