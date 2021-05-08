#include<bits/stdc++.h>
#define S(x) (long long)(x.size())
#define int long long
using namespace std;

// 10^9 max N
bool is_not_prime[1000000000+1];
vector < int > primes;

void sieve(int N){

	// INITALIZATION
	primes.clear();
	is_not_prime[1] = is_not_prime[0] = 1;

	// a clock to just count the time needed
	clock_t lt;
	lt = clock();

	// LOOPS TO CALCULATE THE NUMBERS
	
	// the most naive way
	// we just go through all the numbers and for each check if all the previous numbers from 2 to i-1 do not divide i
	
	/*
	for(int i=2;i<=N;i++){
	
		// inner loop to check if i is prime
		for(int j=2;j<i;j++){
			// if modulo equals to 0 then j divides i
			if(i % j == 0){
				is_not_prime[i] = 1;
				break;
			}
		}

		if(is_not_prime[i] == 0){
			primes.push_back(i);
		}

	}
	*/

	// level 1 sieve
	// we use the sieve of eratosthenes without any optimization
	
	/*
	for(int i=2;i<=N;i++){
	
		// if the number is prime then we start erasing all the subsequent numbers that it divides
		if(is_not_prime[i] == 0){
		
			primes.push_back(i);
			
			// we start from the number that is immediatly after i and is divided by i -> 2 * i
			for(int j=2*i;j<=N;j+=i){
				is_not_prime[j] = 1;
			}
			
		}
		
	}
	*/

	// level 2 sieve
	// we notice the even numbers can be just skipped
	
	/*
	primes.push_back(2);
	for(int i=3;i<=N;i+=2){
	
		if(is_not_prime[i] == 0){
		
			primes.push_back(i);
			
			for(int j=2*i;j<=N;j+=i){
				is_not_prime[j] = 1;
			}
			
		}
		
	}
	*/

	// level 3 sieve
	// we notice that we don't need to start erasing from 2 * i but instead we can start from i*i
	// that is because we already erased all the numbers divided by primes smaller than i
	
	primes.push_back(2);
	for(int i=3;i<=N;i+=2){
		if(is_not_prime[i] == 0){
			primes.push_back(i);
			for(int j=i*i;j<=N;j+=i){
				is_not_prime[j] = 1;
			}
		}
	}
	

	// stop the clock line
	lt = clock() - lt;

	// output lines
	cout<<"Time the sieve loop needed for primes until N = "<<N<<"( 10 ^ "<<log10(N)<<" ) is: "<<( ((double)lt) / CLOCKS_PER_SEC )<<endl;
	cout<<"There are "<<S(primes)<<" primes up until this number"<<endl<<endl;

	// Use these lines to check your result
	/*cout<<"The first 20 primes : ";
	for(int i=0;i<20;i++){
		cout<<primes[i]<<" ";
	}
	cout<<endl;*/


}

#undef int
int main(){

	ios::sync_with_stdio(false);
  	cin.tie(0);

  				// N 		primes until N:
  	sieve(10); 		// 10^1		4
  	sieve(100); 		// 10^2		25
  	sieve(1000); 		// 10^3		168
  	sieve(10000); 		// 10^4		1229
  	sieve(100000); 		// 10^5		9592
  	sieve(1000000); 	// 10^6		78498
  	sieve(10000000); 	// 10^7		664579
  	sieve(100000000); 	// 10^8		5761455
  	sieve(1000000000); 	// 10^9		50847534

}
