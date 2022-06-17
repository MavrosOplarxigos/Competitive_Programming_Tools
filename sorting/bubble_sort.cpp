#include "sortheader.h"

void my_sort(){

	bool swapcheck = true;
	int last = (int)(input.size()) - 1;

	do{

		swapcheck = false;
		int new_last = 1;

		for(int i=1; i<=last ; i++){

			if(input[i] < input[i-1]){
				swap(input[i],input[i-1]);
				swapcheck = true;
				new_last = i;
			}

		}

		// last--;
		last = new_last;

	}while(swapcheck);

	output.insert(output.begin(),input.begin(),input.end());

}