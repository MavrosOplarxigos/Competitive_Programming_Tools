#include "sortheader.h"

// int apps[100001]; // 0 .. 100K

map < long long , int > apps; // 0 .. 10^18

void my_sort(){

	for(size_t i=0; i < input.size(); i++){
		apps[ input[i] ]++;
	}

	// for(int i=0; i <= 100000; i++){
	// 	while( apps[i]-- ){
	// 		output.push_back(i);
	// 	}
	// }

	map < long long , int > :: iterator it;
	for(it=apps.begin(); it != apps.end(); it++){
		while( it->second-- ){
			output.push_back(it->first);
		}
	}

}