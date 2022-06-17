#define MAXSIEVE 1
// Uncomment the next two lines when you want to use the sieve
//#undef MAXSIEVE
//#define MAXSIEVE (1000000000LL+1)
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
