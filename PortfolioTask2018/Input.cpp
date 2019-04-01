#include "Input.h"
#include "Initialise.h"

using namespace std;

std::string sInput(std::string prompt) // THIS KEEPS THE FORMAT FOR THE STRING OUTPUT I WANT AND SAVES A LOT OF SPACE IN THE MAIN PROGRAM. 
{
	std::string result;
	cout << "" << std::endl;
	cout << " >>>>		" << prompt << std::endl;
	cout << "" << std::endl;
	cout << " >>>>		";
	getline(cin, result); // GETLINE ALLOWS THE USER TO INPUT MORE THAN ONE WORD AT A TIME. BEFORE, WITH JUST CIN, IT IGNORED ANY WORDS AFTER THE FIRST SPACE.
	cout << "" << endl;
	ToUpper(result);

	return result;
}

double dInput(string prompt) // THIS IS THE SAME FOR DOUBLES.
{
	string result;
	cout << "" << endl;
	cout << " >>>>		" << prompt << endl;
	cout << "" << endl;
	cout << " >>>>		";
	getline(cin, result); // READS THE INPUT AS A STRING THEN...
	double resultd = stod(result, 0); // PARSES STR INTERPRETING ITS CONTENT AS A FLOATING-POINT NUMBER, WHICH IS RETURNED AS A VALUE OF TYPE DOUBLE: STOD = STRING TO DOUBLE. 
	return resultd;
}

int iInput(string prompt) // THIS IS THE SAME FOR INTEGERS.
{
	string result;
	cout << "" << endl;
	cout << " >>>>		" << prompt << endl;
	cout << "" << endl;
	cout << " >>>>		";
	getline(cin, result);
	cout << "" << endl;
	int resulti = stoi(result, 0); // STOI = STRING TO INTEGER.
	return resulti;
}
