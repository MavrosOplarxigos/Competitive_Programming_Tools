#include <bits/stdc++.h>
using namespace std;

string my_to_string(long x);

string my_to_string(int x){
	return my_to_string((long)x);
}

string my_to_string(long x){

	string solution = "";

	while(x > 0){
		int last = x % 10;
		x /= 10;
		solution = (char)(last + '0') + solution;
	}

	return solution;

}

string my_to_string(double x, int acc){

	long left = (long)(x);
	string left_s = my_to_string(left);
	left_s += ".";

	double right = x - left;

	while(acc--){

		right *= 10;
		long d = (long)right;
		right -= d;
		left_s += (char)(d + '0');

	}

	return left_s;

}

int main(){

	// Converting from int, long and double to string

	// Method #1: Using to_string() function (for C++11 and after compilers)

	int x_int = 100;
	long x_long = (long)(100000000000000000);
	double x_double = 100.12345678912341234;

	string s_int, s_long, s_double;
	s_int = to_string(x_int);
	s_long = to_string(x_long);
	s_double = to_string(x_double);

	cout << "Results from to_string():" << endl;
	cout << s_int << endl;
	cout << s_long << endl;
	cout << s_double << endl << endl;

	// Method #2: Use our own functions

	s_int = my_to_string(x_int);
	s_long = my_to_string(x_long);
	s_double = my_to_string(x_double,15);

	cout << "Results from my_to_string():" << endl;
	cout << s_int << endl;
	cout << s_long << endl;
	cout << s_double << endl << endl;

}