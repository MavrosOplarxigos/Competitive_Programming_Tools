// Test your O(N^2) solution here: https://www.spoj.com/problems/ELIS/
// Test your O(NlogN) solution here: https://cses.fi/problemset/task/1145
#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;

	int a[n+1];
	int dp[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	// O(n^2) solution
	/*
	
	// dp[i] = the length of the longest increasing subsequence up until index i

	dp[1] = 1;		// first element is just itself (by default has no previous elements)
	int maxa = 1;	// variable to save the longest increasing subsequence length 

	// we simply iterate over all the elements from left to right
	// we begin from the second element since we already know the solution of the first one
	for(int i=2;i<=n;i++){

		// we set its solution to be 1 since it can be just itself and form an increasing subsequence
		dp[i] = 1;

		// we iterate through all the previous elements
		for(int j=1;j<i;j++){
			// condition for strictly increasing 
			if(a[j] < a[i]){
				dp[i] = max(dp[i],dp[j]+1);
				maxa = max(maxa,dp[i]);
			}
			// if we want not strictly increasing we change it to (a[j] <= a[i]) 
		}
	}

	cout<<maxa<<endl;
	*/

	// O(nlogn)
	// dp[i] = the smallest element that was so far the last element of a subsequence of lenght i
	
	// the fist element at the start is the smallest element that is the ending
	// of a subsequence of lenght 1
	dp[1] = a[1];

	// index to the maximum length we have reached
	int mj = 1;

	for(int i=2;i<=n;i++){

		// check if we are greater than the last element of the longest subsequence
		if(dp[mj] < a[i]){
			// if we are we increase the maximum length reached and we add this element as the last for that length
			mj++;
			dp[mj] = a[i];
		}
		// check if we are smaller than the smallest last element of the subsequence with length 1
		else if(dp[1] > a[i]){
			//  we just take its place 
			dp[1] = a[i]; 
		}
		else{
			
			// otherwise we binary search to find the immediate element which is greater than our current element
			int left = 1;		// leftmost element bound
			int right = mj;		// rightmost element bound
			
			while(left < right){
				
				// the middle element that we will compare with
				int mid = (left+right) / 2;

				// if it is smaller we use its immediate next as our left bound
				if(dp[mid] <= a[i]){
					left = mid+1;
				}
				// if it is greater we use it as our right bound
				else if(dp[mid] > a[i]){
					right = mid;
				}

			}

			// if we want it to be strictly increasing
			// in the event that the element before the immediate greater is smaller than our current element
			if( dp[ right-1 ] < a[i] ){ 
				// we change our immediate greater with the current element
				dp[right] = a[i];
			}

			// if we just want increasing (not strictly) we can change the condition to ( dp[ right-1 ] <= a[i] )

		}

	}

	cout << mj << endl;

}
