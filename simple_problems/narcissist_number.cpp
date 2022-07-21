#include <bits/stdc++.h>
using namespace std;

// return x to the power of y
long long pow(long long x, long long y){
	if(!y) return 1;
	int half = pow(x,y/2);
	return (y%2) ? half*half*x : half*half;
}

int main(){

	long long x;
	long long len;
	cin >> x;

	long long t = x;
	while(t){
		t /= 10;
		len++;
	}

	int sum = 0;
	t = x;
	while(t){
		sum += pow(t%10,len);
		t /= 10;
	}

	string ans = (sum==x) ? "Narcissistic Number" : "Non-Narcissistic Number";
	cout << ans << enld;

}