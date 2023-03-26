#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define apo(a,b) sqrtl( powl(a.x-b.x,2) + powl(a.y-b.y,2) )
#define ldeq(a,b) ( fabsl(a - b) < 0.00000000007 ) // check long double rough equality 
#define rep(a,b) for(int i=a; i<=b; i++)
#define repv(a,b,i) for(int i=a; i<=b; i++)
#define mmod(a,b) ( (a >= 0) ? (a%b) : ( ( (b-1) * ( (-a) % b ) ) % b )  )
#define ALL(x) x.begin(),x.end()
#define S(x) ((int)(x.size()))
#define PB push_back
#define sum_f1tx(x) ( ( x * (x+1) ) / 2 )
#define sum_fxty(x,y) ( ( ( ( y - x ) + 1 ) * ( x + y ) ) / 2 )
#define fast_pow(x,y,m,ans) { ll cx=x; ll cy=y; ll res=1; cx=cx%m; while(cy>0){ if(cy&1){res*=cx;res%=m;} cy>>=1; cx*=cx; cx%=m; } ans=res; }

// --------------- PARAMETERS -----------------
#define MULTITEST 1 // 0 for single tests, 1 for multi-test
//#define M_PI (2*acos(0))
#define MAX_N 10001
#define MOD 1000000007 // 10^9 + 7
#define MAXSIEVE 1
// Uncomment the next two lines when you want to use the sieve
//#undef MAXSIEVE
//#define MAXSIEVE (1000000000LL+1)
using namespace std;

// ----------------- CUSTOM FUNCTION DECLARATIONS -----------------
vector < ll > sieve(ll N);

// >>>>>>>>>>>>>>>>>> SOLUTION BEGIN <<<<<<<<<<<<<<<<<<<<<

// Check before submission these common mistakes:
// - Make sure that where you used int the limit is no surpassed (search for * and +).
// - Make sure you didn't mess up index 0 with index 1.
// - Make sure you are not trying to go backward and use ++ instead of --
// - Read the whole code one more time. Reading should take < 1 min so you won't loose much rating.

void doit(){

	
	
}

// >>>>>>>>>>>>>>>>>> SOLUTION END <<<<<<<<<<<<<<<<<<<<<

int main(){

	ios::sync_with_stdio(false);
  	cin.tie(0);
  	
	int t = 1;
	if( MULTITEST ){
		cin >> t;
	}

	while(t--){
		doit();
	}

}

// -------------------------- CUSTOM FUNCTION DEFINITIONS -------------------------
bool is_not_prime[MAXSIEVE]; 
vector < long long > sieve(long long N){

	vector < long long > primes;

	is_not_prime[1] = is_not_prime[0] = 1;
	
	primes.push_back(2);
	for(long long i=3;i<=N;i+=2){
		if(is_not_prime[i] == 0){
			primes.push_back(i);
			for(long long j=i*i;j<=N;j+=i){
				is_not_prime[j] = 1;
			}
		}
	}

	return primes;

}
