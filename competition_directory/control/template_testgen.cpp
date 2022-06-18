#include<bits/stdc++.h>
#define ll long long
#define ld long double
//#define M_PI (2*acos(0))
#define MAX_N 10001
#define MOD 1000000007
#define apo(a,b) sqrtl( powl(a.x-b.x,2) + powl(a.y-b.y,2) )
#define ldeq(a,b) ( fabsl(a - b) < 0.00000000007 )
#define rep(a,b) for(int i=a; i<=b; i++)
#define repv(a,b,i) for(int i=a; i<=b; i++)
#define mmod(a,b) ( (a >= 0) ? ((a%b)%b) : ( ( ( a + ( ((abs(a)+b)/b) * b ) ) % b ) % b ) )
#define ALL(x) x.begin(),x.end()
#define S(x) ((int)(x.size()))
#define PB push_back
using namespace std;

long rand_long();			// random integer to 10^9
char rand_upcase();		// random uppercase letter
char rand_lowcase();	// random lowercase letter
string rand_s20();		// random string of 20 chars max
string rand_s100();		// random string of 100 chars max

int main(int argc, char * argv[]){
	
	srand(time(NULL));
	// initialize rand if seed is given
	if(argc > 1){
		int seed = atoll(argv[1]);
		srand(seed);
	}

// -------- COUT TEST HERE -----------



// -------- COUT TEST HERE ----------- 

}

// random integer between 0 .. 10^9
long rand_long(){
	long ans = 74747070LL;
	rep(1,10){
		int y = rand();
		ans *= y;
		ans += ( y + 1 );
		ans %= 1000000001;
	}
	return ans;
}

char rand_lowcase(){
	return 'a' + ( rand_long() % 26 );
}

char rand_upcase(){
	return 'A' + ( rand_long() % 26 );
}