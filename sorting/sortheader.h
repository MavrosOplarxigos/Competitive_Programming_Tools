#include <bits/stdc++.h>
using namespace std;

vector < long long > input;
vector < long long > output;

void my_sort();

int main(){

	while( !cin.eof() ){
		long long x;
		cin >> x;
		input.push_back(x);
	}

	my_sort();

	for(size_t i = 0; i < output.size(); i++){
		cout << output[i] << " ";
	}
	cout << endl;

}