#include<bits/stdc++.h>
#define ll long long
#define rep(a,b) for(int i=a; i<=b; i++)
#define repv(a,b,i) for(int i=a; i<=b; i++)
#define ALL(x) x.begin(),x.end()
#define S(x) ((int)(x.size()))
#define PB push_back
using namespace std;

// 32767 maximum value from rand()

ll random(ll limit){

	ll val = rand();

	rep(1,10){
		val *= rand();
		val %= limit + 1; // 0 .. limit
		val += rand();
		val %= limit + 1;
	}

	return val;

}

int main(){

	ios::sync_with_stdio(false);
  	cin.tie(0);

  	srand( time(0) );

  	ll s,a,b;
  	bool u;

  	// size
  	cout << "Give the size of the array: ";
  	cout.flush();
  	cin >> s;

  	// a .. b
  	cout << "Give the lowest value: ";
  	cout.flush();
  	cin >> a;

  	cout << "Give the highest value: ";
  	cout.flush();
  	cin >> b;

  	// unique or not 1/0
  	cout << "Unique values or not (1/0): ";
  	cout.flush();
  	cin >> u;

  	ll diff = b - a;
  	// generate 0 .. diff
  	// a + (0 .. diff) -> a .. b

  	map < ll , bool > mp;
  	vector < ll > rand_arr;

  	rep(1,s){

  		ll next = a + random(diff);

  		// uniquness test
  		// randomized solution: Las Vegas
  		while( ( mp.find(next) != mp.end() ) && ( u ) ){
  			next = a + random(diff);
  		}

  		rand_arr.push_back(next);
  		if( u ){
  			mp[next] = true;
  		}

  	}

  	// output of the array
  	cout << S(rand_arr) << endl;
  	rep(0,s-1){
  		cout << rand_arr[i] << " ";
  	}
  	cout << endl;

}
