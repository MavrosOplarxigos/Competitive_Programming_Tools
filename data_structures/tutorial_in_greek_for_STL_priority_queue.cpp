#include <bits/stdc++.h>
using namespace std;

int main(){

	// MAX HEAP
	// priority_queue < τύπος αντικειμένου > όνομα;
	priority_queue < int > q;

	// MIN HEAP
	// priority_queue < τύπος , vector < τύπος > , greater < τύπος >  > όνομα;
	priority_queue < int , vector < int > , greater < int >  > min_q_example;
	priority_queue < int > min_q_minus;

	// Εισαγωή στοιχείων
	int a[5] = { 1, 2, 4, 2, 8};
	for(int i=0;i<5;i++){
		q.push(a[i]);
		min_q_example.push(a[i]);
		// χρήση τελεστή - για την min_q_minus
		min_q_minus.push(-a[i]); // e.g. -8 < -2
	}

	while(!q.empty()){
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
	// 8 4 2 2 1

	while(!min_q_example.empty()){
		cout << min_q_example.top() << " ";
		min_q_example.pop();
	}
	cout << endl;
	// 1 2 2 4 8
	
	while(!min_q_minus.empty()){
		cout << min_q_minus.top() << " ";
		min_q_minus.pop();
	}
	cout << endl;
	// -1 -2 -2 -4 -8
	
}

