#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define apo(a,b) sqrtl( powl(a.x-b.x,2) + powl(a.y-b.y,2) )
#define ldeq(a,b) ( fabsl( (a) - (b) ) < 0.00000000007 ) // check long double rough equality 
#define mmod(a,b) ( ( (a) >= 0) ? ( (a) % (b) ) : ( ( ( (b)-1 ) * ( (-(a)) % (b) ) ) % (b) ) )
#define ALL(x) x.begin(),x.end()
#define S(x) ((long long)(x.size()))
#define PB push_back
#define pii pair < int , int >
#define pil pair < int , ll >
#define pli pair < ll , int >
#define pll pair < ll , ll >
// we want to check if a * b > LONG_MAX -> b > LONG_MAX / a 
#define is_oflow(a,b) ( (a!=0) && ( abs(b) > LONG_LONG_MAX / abs(a) ) )
// for the min_heap we should either use one-word declared data type (int, char, long, name of struct) or define it to be a single word
#define min_heap(x) priority_queue < x , vector < x > , greater < x > >
// sum from 1 to x
#define sum_f1tx(x) ( ( (x) * ( (x) + 1 ) ) / 2 )
// sum from x to y 
#define sum_fxty(x,y) ( ( ( ( (y) - (x) ) + 1 ) * ( (x) + (y) ) ) / 2 )
// inline fast power iterative "ans" must be already declared variable
#define fast_pow(x,y,m,ans) { ll cx=(x); ll cy=(y); ll res=1; cx=cx%(m); while(cy>0){ if(cy&1){res*=cx;res%=(m);} cy>>=1; cx*=cx; cx%=(m); } ans=res; }
// discriminant // for quadratic ax^2 + bx + c // > 0 (2 solutions), = 0 (1 solution), < 0 (complex solutions)
#define discr(a,b,c) ( ( (b) * (b) ) - (4 * (a) * (c) ) )
#define ord_pair(x,y) ( (x) < (y) ? make_pair((x),(y)) : make_pair((y),(x)) )
#define endol '\n'

#ifndef ONLINE_JUDGE
	#define debug( x ) { cout << "\033[0;31m";  { x } cout << "\033[1;37m";  }
#else
	#define debug( x ) 
#endif

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
bool is_not_prime[MAXSIEVE+1]; 
vector < ll > primes;
vector < ll > sieve(ll N);

// >>>>>>>>>>>>>>>>>> SOLUTION BEGIN <<<<<<<<<<<<<<<<<<<<<

// READ THIS BEFORE EVERY CONTEST -> WINNING = NOT REPEATING THE SAME MISTAKES:
// - For the "LOVE OF GOD" do "NOT name functions" that you write with "NAMES THAT DIFFER FROM BUILT-IN FUNCTION NAMES OR OTHER FUNCTION NAMES BY JUST A SINGLE CHARACTER". How many times do I have to tell you?
// - Fast IO is already included in this template.
// - If you find a "solution for a problem that uses segment trees" first check if there is a solution using "PQs or whatever else DOESN'T REQUIRE RECURSION". If you can't, use "g++20" instead.
// - If you get stuck in a problem where we are searching for the minimal/maximal valid solution to something, approach with: If I binary search the answer "how much time complexity will it take to calculate if the candidate answer gives a valid solution". Then you simply multiply that complexity with the logarithm of the size of the set of possible solutions.
// - After solving problem A. For the love of "GOD". Simply open "COMPLETE PROBLEMSET" on the "CORRECT DIVISION".
// - When dealing with output for ordered "edge list" and you use "pairs" ensure the "pair of vertices is also ordered with ord_pair(x,y)"
// - "Trailing zeroes of N!" just count the "powers of 5 that appear in 1..N". Log_5 time needed.
// - To reveal the "extra prime factor powers" that a number X has compared to some number Y just do " X / __gcd(X,Y) "
// - For a number X there "can" be "Y<X" such that for a "certain prime factor Y has a higher power" (e.g. X=6=2*3 and Y=4=2*2)
// - For N>4 there is always a permutation with abs(p[i] - p[i+1]) > 1 for all 1 <= i < N.
// - For integer X != 1 and P prime -> X * P is not prime because more than 1 factors.
// - That you "didn't confuse underlines in the example case with overlines in the instruction" that are meaning element inversion most propably.
// - "NlogN" complexities should pass "as linear ones" do even if you use a DS like maps or pqueues "UNLESS YOU HAVE RECURSION - BE CAREFUL!".
// - For trees remember that from leaf to root it can take O(n):" n/2 path to root and n/2 leafs -> O(n^2) complexity" to calculate on all these paths.
// - Where you used int the type limit is no surpassed "(search for * and +)". Make sure you "don't multiply two integers" without "casting them to long long first".
// - Didn't mess up "index 0 with index 1".
// - Not trying to go backward and use "++ instead of --"
// - That you didn't have a case of "bitwise operations not nested" like "( a & b > 0 )". NEST THE OPERATORS THAT YOU DON'T KNOW FOR CERTAIN.
// - "Arrays with size >400K bytes should be global" (for variable sizes use vectors; little bit of speed loss >> WA because of stack memory being so small)
// - "Read the whole code one more time." Reading should take < 1 min so you won't loose much rating "(for after C)".
// - We "don't use rep no more" to ensure that we use "long longs in the cases where indexes take such large values". For example maybe we have a sorted array of the indexes of some coneptual array. 

void doit(){

	
	
}

// >>>>>>>>>>>>>>>>>> SOLUTION END <<<<<<<<<<<<<<<<<<<<<

int main(){

	ios::sync_with_stdio(false);
  	cin.tie(0);
  	sieve(MAXSIEVE);
	
	int t = 1;
	if( MULTITEST ){
		cin >> t;
	}

	while(t--){
		doit();
	}

}

// -------------------------- CUSTOM FUNCTION DEFINITIONS -------------------------
vector < long long > sieve(long long N){

	vector < long long > primes;

	if( N == 1){
		return primes;
	}

	is_not_prime[1] = is_not_prime[0] = 1;
	
	primes.push_back(2);
	if( N % 2 == 0 ){ is_not_prime[N] = 1; }
	for(long long i=3;i<=N;i+=2){
		if( i>3 ){ is_not_prime[i-1] = 1; }
		if(is_not_prime[i] == 0){
			primes.push_back(i);
			for(long long j=i*i;j<=N;j+=i){
				is_not_prime[j] = 1;
			}
		}
	}

	return primes;

}
