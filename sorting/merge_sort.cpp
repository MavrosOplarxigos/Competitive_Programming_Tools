#include "sortheader.h"

void merge_sort(int left, int right);

void my_sort(){

	merge_sort(0,(int)input.size() - 1);
	output.insert(output.begin(),input.begin(),input.end());

}

void merge_sort(int left, int right){

	if(left == right){
		return;
	}

	// divide
	int mid = (left + right) / 2; // left .. mid , mid + 1 .. right

	merge_sort(left,mid);
	merge_sort(mid+1,right);

	// merge
	vector < long long > mv;
	int i,j;

	i = left;
	j = mid+1;

	while( i <= mid || j <= right ){

		if( i > mid ){
			mv.push_back(input[j]);
			j++;
		}
		else if( j > right ){
			mv.push_back(input[i]);
			i++;
		}
		else{

			if(input[i] < input[j]){
				mv.push_back(input[i]);
				i++;
			}
			else{
				mv.push_back(input[j]);
				j++;
			}

		}

	}

	for(size_t k=0; k < (int)(mv.size()); k++){
		input[left+k] = mv[k];
	}

}