#include <bits/stdc++.h>
using namespace std;

int main(){

	// map < τύπος κλειδίου , τύπος τιμής > όνομα;
	map < int , double > hm;

	// Εισαγωγή στοιχείου (insertion)
	// 1ος τρόπος: με χρήση της συνάρτησης insert
	hm.insert( pair < int , double > (1337,1.70) );
	hm.insert( make_pair(2020,1.80) );

	// 2os τρόπος: με χρήση του τελεστή []
	hm[1001] = 2.01;

	cout << hm.size() << endl; // 3
	cout << hm[1001] << endl; // 2.01
	// Διαγραφή στοιχείου (deletion)
	hm.erase(1001);
	hm.erase(15); // Τίποτε δεν θα γίνει
	cout << hm.size() << endl; // 2
	cout << hm[1001] << endl; // 0

	cout << hm[2020] << endl; // 1.8
	// Αλλαγή τιμής
	// 1os τρόπος: με χρήση του τελεστή []
	hm[2020] = 1.95;
	cout << hm[2020] << endl; // 1.95
	
	// με χρήση της insert? OXI!
	hm.insert( make_pair(2020,2.10) );
	cout << hm[2020] << endl; // 1.95

	// Αναζήτηση
	hm[1234] = 1.55;
	hm[5678] = 1.56;
	// 1ος τρόπος: με χρήση της count
	cout << hm.count(1234) << endl; // 1
	cout << hm.count(3000) << endl; // 0

	// 2ος τρόπος: με χρήση της find
	cout << ( hm.find(1234) == hm.end() ) << endl; // 0
	cout << ( hm.find(3000) == hm.end() ) << endl; // 1

	if( hm.find(1234) != hm.end() ){
		cout << "1234 exists!" << endl; // θα τυπωθεί
	}

	// 3o τρόπος: με χρήση [] μόνο αν defautl value σημαίνει δεν υπάρχει
	if( hm[5678] != 0 ){
		cout << "5678 exists!" << endl; // θα τυπωθεί
	}

	// Διάσχιση (iteration)
	map<int,double>::iterator it;
	for(it=hm.begin(); it!=hm.end();it++){
		cout << it->first << " " << it->second << endl;
	}

	/*
	 * 1001 0
	 * 1234 1.55
	 * 1337 1.7
	 * 2020 1.95
	 * 5678 1.56
	 */

}
