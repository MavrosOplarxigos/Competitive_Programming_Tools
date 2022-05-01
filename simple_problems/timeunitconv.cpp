/*
For Linux users one can use the units command to convert between mutliple types of units of measurement.
I just created this program for people who want to get an idea of how one can attack this problem.
*/
#include <bits/stdc++.h>
using namespace std;

// this function just prints the help message and tells the user how to run the program essentially
void tunitconv_help(){
	string message = "";
	message =  "Run: timeunitconv [input_time_unit] [value] [output_time_unit]\n";
	message += "\n";	
	message += "Unit codes:\n";
	message += "--------------------\n";
	message += "nanoseconds\tns\n";
	message += "microseconds\tμs or mics\n";
	message += "miliseconds\tms\n";
	message += "seconds\t\ts or sec\n";
	message += "minutes\t\tmin\n";
	message += "hours\t\thrs\n";
	message += "days\t\tdays\n";
	message += "weeks\t\tweeks\n";
	cout << message << endl;
}

// have a mapping for every unit to the basic unit (seconds)
// it doesn't matter which one we choose to be the basic unit
// as long as we map all the other units to that one.
map < string , long double > time_units = 
{
	{"ns", 		1.0 / 1000 / 1000 / 1000},
	{"μs", 		1.0 / 1000 / 1000 		},
	{"mics",	1.0 / 1000 / 1000		},
	{"ms",		1.0 / 1000				},
	{"s",		1.0						},
	{"sec",		1.0						},
	{"min",		1.0 * 60				},
	{"hrs",		1.0 * 60 * 60			},
	{"days",	1.0 * 60 * 60 * 24		},
	{"weeks",	1.0 * 60 * 60 * 24 * 7	}
};

/*
	Returns the value after conversion or -1 if unit types invalid.
*/
long double unitconv(string input, long double value, string output){

	long double in_val = time_units[input];
	long double out_val = time_units[output];

	if( (in_val == 0) || (out_val == 0) ){
		return -1;
	}

	return value * (in_val/out_val);

}

int main(int argc, char * argv[]){

	// display help and exit if invalid number of arguments
	if(argc != 4){
		tunitconv_help();
		return 0;
	}

	// code to parse the arguments
	string inunit,value,outunit;
	inunit = value = outunit = "";

	for(int i=0;argv[1][i]!='\0';i++){
		inunit += argv[1][i];
	}

	bool dot = false; // 123.123
	for(int i=0;argv[2][i]!='\0';i++){
		value += argv[2][i];
		// check that it is a double
		if( ! ( (argv[2][i] >= '0') && (argv[2][i] <= '9') ) ){
			// one dot is allowed
			if(argv[2][i] == '.'){
				if(dot){
					cout << "Invalid value given!" << endl;
					return 0;
				}
				else{
					dot = true;
				}
			}
			else{
				cout << "Invalid value given!" << endl;
				return 0;
			}

		}
	}

	for(int i=0;argv[3][i]!='\0';i++){
		outunit += argv[3][i];
	}

	// call the conversion function and output the result
	if(unitconv(inunit,stold(value),outunit) == -1){
		cout << "Invalid unit code given!" << endl;
		return 0;
	}

	cout.precision(16);
	cout << value << " " << inunit << " equal to " << unitconv(inunit,stold(value),outunit) << " " << outunit;
	return 0;

}
