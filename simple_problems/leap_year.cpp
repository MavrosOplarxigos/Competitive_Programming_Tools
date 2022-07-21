#include <bits/stdc++.h>
using namespace std;

int main(){

	int year;
	cin >> year; 

	if( (year%4) || (  !(year%100) && (year%400) ) ){
		cout << "Common Year" << endl; return 0;
	}

	cout << "Leap Year" << endl;

}
