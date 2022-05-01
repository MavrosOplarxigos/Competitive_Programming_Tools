#include <bits/stdc++.h>
using namespace std;

int main(){

	// -------------- converting from c++ to c ------------------
	string cpps1 = "cppstring_1";
	string cpps2 = "cppstring2!";

	// using built-in function: c_str()
	// c_str() returns a const char pointer

	// we can use a const char pointer to get the result as well
	// but we can't do any changes to it
	const char * cs1 = cpps1.c_str();
	// output the first string character by character
	cout << "What did we get from the first string:\n";
	for(int i=0;;i++){
		cout << "'" << cs1[i] << "' ";
		if(cs1[i] == '\0'){
			break;
		}
	}
	cout << endl;
	// for example
	// cs1[0] = 'C'; <-- this causes a compilation error
	// since cs1 in const char

	// we can use a pointer and copy the string instead with strcpy
	char cs2[100];
	strcpy(cs2,cpps2.c_str());
	cs2[0] = 'C';

	// output the second string character by character
	cout << "What did we get from the second string:\n";
	for(int i=0;;i++){
		cout << "'" << cs2[i] << "' ";
		if(cs2[i] == '\0'){
			break;
		}
	}
	cout << endl;

	// ---------- converting from c to c++ ------------

	// simple definition
	char s3[] = "Str3###";

	// simply use a for loop until you find the ending character '\0'
	string cpp_string = "";
	for(int i=0;s3[i] != '\0';i++){
		cpp_string += s3[i];
	}

	// the third string character by character
	cout << "What did we get from the third string:\n";
	for(uint i=0;i<cpp_string.size();i++){
		cout << "'" << cpp_string[i] << "'";
	}
	cout << endl;

}
