#include <bits/stdc++.h>
using namespace std;

// if you do not want a strictly increasing subsequence switch the if statements with the commented out statements
int fast_LIS(vector < int > a){

	// comment out next line if your array already uses 1-based indexing
	a.insert(a.begin(),1,0);
	
	int n = (int)( a.size() ) - 1;
	int dp[n+1];

	dp[1] = a[1];
	int mj = 1;

	for(int i=2;i<=n;i++){
		// if(dp[mj] <= a[i]) 
		if(dp[mj] < a[i]){
			mj++;
			dp[mj] = a[i];
		}
		else if(dp[1] > a[i]){
			dp[1] = a[i]; 
		}
		else{
			
			int left = 1;
			int right = mj;
			
			while(left < right){
				
				int mid = (left+right) / 2;

				if(dp[mid] <= a[i]){
					left = mid+1;
				}
				else if(dp[mid] > a[i]){
					right = mid;
				}

			}

			// if( dp[ right-1 ] <= a[i] ) 
			if( dp[ right-1 ] < a[i] ){ 
				dp[right] = a[i];
			}

		}

	}

	cout << mj << endl;

}
