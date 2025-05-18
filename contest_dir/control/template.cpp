#include<bits/stdc++.h>
using namespace std;

// ALIASES
#define ll long long
#define ld long double
#define S(x) ((int)(x.size()))
#define allsort(x) sort(x.begin(),x.end())

// GEOMETRY
#define apo(a,b) (sqrtl(powl(a.x-b.x,2)+powl(a.y-b.y,2)))

// MATH
#define ldeq(a,b) (fabsl((a)-(b))<0.00000000007) // check long double rough equality 
#define mmod(a,b) ((((a)%(b))+(b))%(b))

// CONSTANTS
#define INF LLONG_MAX

#define pii pair < int , int >
#define pil pair < int , ll >
#define pli pair < ll , int >
#define pll pair < ll , ll >
// we want to check if a * b > LONG_MAX -> b > LONG_MAX / a 
#define is_oflow(a,b) ( (a!=0) && ( abs(b) > LONG_LONG_MAX / abs(a) ) )
// for the min_heap we should either use one-word declared data type (int, char, long, name of struct) or define it to be a single word
#define min_heap(x) priority_queue < x , vector < x > , greater < x > >
// sum from 1 to x
#define sum_f1tx(x) ( ( (x) * ( (x) + 1LL ) ) / 2LL )
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

void reset_color() {
    std::cout << "\033[0m";   // ANSI reset code
}

void red_color_set() {
    std::cout << "\033[31m";  // ANSI escape code for red text
}

// --------------- PARAMETERS -----------------
//#define M_PI (2*acos(0))
#define MAX_N 10001
#define MOD 1000000007 // 10^9 + 7
// Uncomment the next two lines when you want to use the sieve
// #undef MAXSIEVE
#define MAXSIEVE (1LL+1)


// ----------------- CUSTOM FUNCTION DECLARATIONS -----------------
bool is_not_prime[MAXSIEVE+1]; 
// vector < ll > primes;
vector < ll > sieve(ll N);

// >>>>>>>>>>>>>>>>>> SOLUTION BEGIN <<<<<<<<<<<<<<<<<<<<<

// READ THIS BEFORE EVERY CONTEST -> WINNING = NOT REPEATING THE SAME MISTAKES:
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

#define MULTITEST 0 // 0 for single tests, 1 for multi-test

void printvp(vector < pair < int , int > > v){

	for(int i=0;i<(int)v.size();i++){
		cout << v[i].first << "," << v[i].second << " ";
	}
	cout << endl;

}

template <typename T>
void printv(vector <T> v, char del){
	for(int i=0;i<(int)v.size();i++){
		cout << v[i] << del;
	}
	// cout << endl;
}

template <typename T>
void load_into(vector<T>& ret, int size) {
    ret.clear();
    ret.reserve(size); // Optional: prevents multiple reallocations
    for (int i = 0; i < size; i++) {
        T x;
        cin >> x;
        ret.push_back(x);
    }
}


template <typename F>
void print2dv(vector < vector < F > > & v){
	for(int i=0;i<(int)v.size();i++){
		for(int j=0;j<(int)v[i].size();j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

bool isv(char x){
	string v = "aeiou";
	for(int i=0;i<(int)v.size();i++){
		if( v[i] == x ){
			return 1;
		}
	}
	return 0;
}

void prints_psi(set < pair < string , int > > s ){
	set < pair < string , int > >::iterator it;
	for(it=s.begin();it!=s.end();it++){
		cout << (*it).first << " " << (*it).second << endl;
	}
}

bool sorted_v(vector < int > v){
	for(int i=0;i<(int)v.size()-1;i++){
		if( v[i] > v[i+1] ){
			return 0;
		}
	}
	return 1;
}

class point{
	public:
	ld x,y;
	point() : x(0), y(0) {}
	point(ld n1, ld n2) : x(n1), y(n2) {}
	friend istream& operator>>(istream &in, point &obj){
		in >> obj.x >> obj.y; return in;
	}
	friend ostream& operator<<(ostream &out, const point &obj){
		out << obj.x << " , " << obj.y; return out;
	}
};

ll pop_count(ll x){
	ll a = 0;
	while(x>0){
		a += (x%2) ? 1 : 0;
		x /= 2;
	}
	return a;
}

ll next_p2(ll x){
	ll a = 1;
	while(a<=x){
		a *= 2;
	}
	return a;
}

int is_in_cs(char x, string f){
	for(int i=0;i<(int)f.size();i++){
		if( x == f[i] ){
			return i+1;
		}
	}
	return 0;
}

string dec_to_small_base(int num, int base){
	if( base > 10 ){
		cout << "Base is too big!!!" << endl;
		return "";
	}
	string ans = "";
	ll p = 1;

	while(p<num){
		p *= base;
	}
	if( p > num ){
		p /= base;
	}

	while(p>0){
		int d = (num / p);
		num %= p;
		ans += (char)('0'+d);
		p/=base;
	}

	return ans;

}

// disjoint-set-union
#define MAX_SET_SIZE 1
int father_dsu[MAX_SET_SIZE];
int rank_dsu[MAX_SET_SIZE];

void init_dsu(int s);
int fore_father_dsu(int x);
void join_dsu(int x, int y);

// in a 2d matrix is x in the dimension limits 0 to n-1
bool v2d(int x, int dim_orio){
	return ( (x >= 0) && (x < dim_orio) );
}

string char2bin(ll x){
	ll p=1;
	string ans = "";
	while(p<=(1LL<<60LL)){
		if( (p & (ll)(x)) > 0LL ){
			ans += "1";
		}
		else{
			ans += "0";
		}
		p *= 2LL;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int charPstring(string x,char f){
	int c = 0;
	for(int i=0;i<(int)x.size();i++){
		c += (x[i]==f);
	}
	return c;
}

bool is_ar(vector < int > v){
	bool ar = true;
	int diff = v[1]-v[0];
	for(int i=2;i<(int)v.size()&&ar;i++){
		ar &= (diff==v[i]-v[i-1]) ? 1 : 0;
		diff = v[i] - v[i-1];
	}
	return ar;
}

vector < long long > primes;
bool is_prime(ll i){
	if( i < MAXSIEVE && is_not_prime[i] ){
		return false;
	}
	if( i >= MAXSIEVE ){
		bool prime = 1;
		int ci = 0;
		while(primes[ci]*primes[ci]<=i){
			if( i % primes[ci] == 0 ){
				prime = 0;
				break;
			}
			ci++;
		}
		if( !prime ){
			return false;
		}
	}
	return true;
}

inline bool is_cap(char x){
	return (x>='A'&&x<='Z');
}
inline bool is_low(char x){
	return (x>='a'&&x<='z');
}

inline string change_case(string f, bool low, bool upp){
	for(int i=0;i<S(f);i++){
		f[i] = (upp&&is_cap(f[i])) ? (f[i]-'A'+'a') : ((low&&is_low(f[i]))?(f[i]-'a'+'A'):f[i]);
	}
	return f;
}
inline string change_case(string f){ return change_case(f,1,1); }
inline string to_lower(string f){ return change_case(f,0,1); }
inline string to_upper(string f){ return change_case(f,1,0); }

void p2(vector < string > v){
	for(int i=0;i<(int)v.size();i++){
		cout << v[i] << endl;
	}
	cout << endl;
}

struct my_pair{
	int first;
	string second;
	bool operator<(const my_pair &other) const{
		return (first<other.first) || (first==other.first && second>other.second);
	}
	my_pair(int num, const string &stra) : first(num), second(stra) {}
};

int ham_str(string s, string t){int a=0,f=min(S(t),S(s));for(int i=0;i<f;i++){a+=(s[i]!=t[i]);}return a;}

int rh_para = 8; // paranoia degree for the rolling hash 1 - 10
ll rh_p[10] = { 43, 1337, 31, 37, 53, 59, 61, 67, 73, 79 };
ll rh_m[10] = { 1337, 99999997, 1000000007, 1000000009, 998244353, 1000003021, 1000000033, 1000000039, 1000000057, 1000000061 };
ll rh_val[10]; 
ll rh_tar[10];
inline void slide_rh(char d, char n, int s){ for(int k=0;k<rh_para;k++){ll fp;fast_pow(rh_p[k],(s-1),rh_m[k],fp);fp *= (ll)(d);fp%=rh_m[k];rh_val[k] = mmod(rh_val[k]-fp,rh_m[k]);rh_val[k] = mmod(rh_val[k]*rh_p[k],rh_m[k]);rh_val[k] = mmod(rh_val[k]+(ll)(n),rh_m[k]);}}
#define new_rh(x,s) {for(int h=0;h<rh_para;h++){rh_val[h]=0;for(int i=0;i<s;i++){rh_val[h]*=rh_p[h];rh_val[h]+=x[i];rh_val[h] %= rh_m[h];}}}
#define init_rh(x) {for(int h=0;h<rh_para;h++){rh_tar[h]=0;int s=(int)(x.size());for(int i=0;i<s;i++){rh_tar[h]*=rh_p[h];rh_tar[h]+=x[i];rh_tar[h]%=rh_m[h];}}}
#define check_rh(res) {res=1;for(int h=0;h<rh_para;h++){if(rh_val[h]!=rh_tar[h]){res=0;break;}}}
inline int count_rh(string x, string y){int counta = 0;init_rh(x);int sz=(int)(x.size());new_rh(y,sz);check_rh(counta);for(int i=0;i+sz<(int)y.size();i++){slide_rh(y[i],y[i+sz],sz);int b;check_rh(b);	counta += b;}return counta;}

vector < int > kmp_lps;
string kmp_p,kmp_t;
int kmp_ans = 0;
void kmp_clps(){
	kmp_lps = vector < int >(S(kmp_p),0);
	int len = 0, i=1;
	while(i<S(kmp_p)){
		if( kmp_p[i] == kmp_p[len] ){ len++;kmp_lps[i]=len;i++; }
		else{ if(len!=0){ len = kmp_lps[len-1]; } else{ kmp_lps[i] = 0; i++; } }
	}
}

void kmp_search(){
	kmp_clps();
	int i,j; i = j = kmp_ans = 0;
	while(i<S(kmp_t)){
		if( kmp_p[j] == kmp_t[i] ){
			i++;
			j++;
		}
		if( j == S(kmp_p) ){
			kmp_ans++; j = kmp_lps[j-1];
		}
		else if( i<S(kmp_t) && kmp_p[j] != kmp_t[i] ){
			if(j != 0){ j = kmp_lps[j-1]; }
			else{ i++; }
		}
	}
}

class LCA {
private:
    vector<vector<int>> up;
    vector<int> depth;
    int LOG;
    vector <vector<int>> adj;
    
    void dfs(int node, int parent) {
        up[node][0] = parent;
        for (int i = 1; i <= LOG; i++) {
	    if (up[node][i - 1] != -1) {
                up[node][i] = up[up[node][i - 1]][i - 1];
            } else {
                up[node][i] = -1;
            }
        }

        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                depth[neighbor] = depth[node] + 1;
                dfs(neighbor, node);
            }
        }
    }

public:
    // number of nodes, all undirected edges, root
    LCA(int n, const vector <pair<int, int>> &edges,int root) {
	   up.clear();
	   depth.clear();
	   adj.clear();
        LOG = ceil(log2(n+1));
        up.assign(n+1, vector<int>(LOG + 1, -1));
        depth.assign(n+1, 0);

	adj.clear();
	adj.insert(adj.begin(),n+1,vector<int>());

        for (const auto& edge : edges) {
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }
        dfs(root, -1);
    }

    int query(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int i = 0; i <= LOG; i++) {
            if ((diff >> i) & 1) {
                u = up[u][i];
            }
        }

        if (u == v) return u;

        for (int i = LOG; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }
};

vector < string > tokenize(string x,char del){
	vector < string > ans;
	string buff = "";
	for(int i=0;i<S(x);i++){
		if( x[i] == del ){
			ans.push_back(buff);
			buff = "";
		}
		else{
			buff += x[i];
		}
	}
	if( S(buff) ){ ans.push_back(buff); }
	return ans;
}

inline vector < vector < ll > > iden_mat(int x){
	vector < vector < ll > > a;
	a.insert(a.begin(),x,vector<ll>(x,0LL));
	for(int i=0;i<x;i++){
		a[i][i] = 1LL;
	}
	return a;
}

inline vector < vector < ll > > mult_mat(vector < vector < ll > > x, vector < vector < ll > > y){
	assert(S(x)!=0 && S(x[0]) == S(y) );
	vector < vector < ll > > a;
	a.insert(a.begin(),S(x),vector<ll>(S(x),0));
	for(int i=0;i<S(x);i++){
	for(int j=0;j<S(x);j++){
		
		for(int jx=0;jx<S(x[0]);jx++){
			a[i][j] += (x[i][jx] * y[jx][j]) % MOD;
			a[i][j] %= MOD;
		}

	}
	}
	return a;
}

inline vector < vector < ll > > fast_mat_exp(vector < vector < ll > > v, ll p){
	assert(S(v)!=0 && S(v)==S(v[0]));
	if( p < 0 ){ return vector<vector<ll>>(S(v),vector<ll>(S(v),0LL)); }
	if( p == 0 ){ return iden_mat(S(v)); }
	if( p == 1 ){ return v; }
	vector < vector < ll > > half = fast_mat_exp(v,p/2);
	half = mult_mat(half,half);
	if( p % 2LL ){ half = mult_mat(half,v); }
	return half;
}

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
vector < long long > sieve(long long N){

	/*if(N >= MAXSIEVE){
		cout << "MAXSIEVE ERROR: THE CHOSEN MAXSIEVE IS TOO SMALL" << endl;
		return vector<ll>();
	}*/

	vector < long long > primes;

	if( N == 1 ){
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

void init_dsu(int s){
	for(int i=0;i<s+1;i++){
		father_dsu[i] = i;
		rank_dsu[i] = 1;
	}
}

int fore_father_dsu(int x){
	while(father_dsu[x] != x){
		x = father_dsu[x];
	}
	return x;
}

void join_dsu(int x, int y){

	if( x == y ){ return; }

	int fx = fore_father_dsu(x);
	int fy = fore_father_dsu(y);

	if( fx == fy ){ return; }

	if( rank_dsu[fx] < rank_dsu[fy] ){
		father_dsu[fx] = fy;
		return;
	}
	
	father_dsu[fy] = fx;
	if( rank_dsu[fx] > rank_dsu[fy] ){
		return;
	}

	rank_dsu[fx]++;

}
