//#include "Initialise.h"
#include "pch.h"
#include "Input.h"
#include "IsFunction.h"
#include "Menu.h"
#include "Graphic.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <windows.h> // WINDOWS-SPECIFIC. CONTAINS DECLARATIONS FOR ALL THE WINDOWS API FUNCTIONS AND MACROS (AND ALL THE DATA TYPES).

#define DriverData "thetrackdriverdata.txt" // INPUT STORAGE FOR THE DRIVER.

using namespace std;

void MenuAdd()
{
	//new
	std::string sMyFirstName = "", sMyLastName = "", sMyNameStore = "";

	clear();

	cout << R"(
		 _   _ _______        __
		| \ | | ____\ \      / /
		|  \| |  _|  \ \ /\ / / 
		| |\  | |___  \ V  V /  
		|_| \_|_____|  \_/\_/   
                        
 )" << endl;

	sMyFirstName = sInput("What is your FIRST name?");
	sMyLastName = sInput("What is your LAST name?");
	sMyNameStore = sMyFirstName + " " + sMyLastName;
	ofstream myfile;
	myfile.open(DriverData, ofstream::app); // IF THE SPECIFIED FILE DOES NOT EXIST, THE OPEN FUNCTION WILL CREATE IT AUTOMATICALLY.
	myfile << " \n" << sMyNameStore;
	myfile.close(); // WHEN YOU'VE FINISHED WORKING WITH THE FILE, YOU CLOSE IF USING THE MEMBER FUNCTION close().
	// YOU ALSO HAVE THE OPTION OF SPECIFYING A PATH FOR YOUR FILE IN THE OPEN FUNCTION, SINCE IS CAN BE IN A LOCATION OTHER THAN THAT OF YOUR PROJECT.

	loading();

	cout << "" << endl;
	cout << " >>>>		Hello " << sMyNameStore << "!" << endl;
	cout << "" << endl;

	double dTotalLength = 0.0; // THE MILES TRAVELLED ON THE TRACK (MILES x AMOUNT OF LAPS).
	double dMiles = 0.0; // HOW MANY MILES LONG THE TRACK IS.
	double dLap = 0; // NUMBER OF LAPS COMPLETED - HAS to be a double otherwise later on in the program, the conversion from double to int may result in a loss of data.
	string sTrack = ""; // TRACK NAME.
	string sTrackStore = ""; // TRACK'S NAME STORED. 
	double dOptimumTime = 0.0; // THE TRACK'S OPTIMUM TIME.


	sTrack = sInput("What is the name of the racetrack you drove on today?");
	sTrackStore = sTrack;
	cout << "" << endl;
	dMiles = dInput("How many miles long is " + sTrackStore + "?");

	dOptimumTime = dInput("What is the Target Lap Time for this course?");
	cout << "" << endl;
	dLap = dInput("How many laps did you achieve altogether?: ");
	clear();

	int iAttempt = 1; // iAttempt IS USED TO MAKE SURE WHILST THE WHILE LOOP IS RUNNING, IT DOESN'T ASK FOR ANY MORE TIMES THAN THE ACTUAL NUMBER OF LAPS THE PERSON COMPLETED.

	double dTime = 0; // dTime IS THE TIME THAT THE PERSON TOOK TO COMPLETE EACH LAP.

	vector<double> dLapMins; // THE VECTOR 'dLapMins' STORES THE TIMES FOR ALL OF THE LAPS.

	while (iAttempt <= dLap) {

		cout << "" << endl;
		dTime = dInput("What was your time for Lap number " + to_string(iAttempt) + "?"); // to_string CONVERTS THE INT TO A STRING OTHERWISE IT WON'T OUTPUT IT: "expression must have integral or unscoped enum type".
		dLapMins.push_back(dTime);
		iAttempt++;

	}

	iAttempt = 1;

	for (auto mins : dLapMins) {

		cout << "" << endl;
		cout << " >>>>		" << "Lap " << iAttempt++ << " = " << mins << " minutes." << endl;
		cout << "" << endl;
	}

	double dSmallest = INT32_MAX; // THIS IS USED IN A FOR LOOP LATER TO TRY AND FIND THE FASTEST LAPTIME.

	for (auto dTime : dLapMins) {
		cout << dTime << endl;
		if (dTime < dSmallest) {
			dSmallest = dTime;
		}
	}

	clear();

	double dSum = accumulate(dLapMins.begin(), dLapMins.end(), 0.0); // TOTAL TIME SPENT DRIVING ON THE TRACK, 'ACCUMULATING' FROM THE dLapMins VECTOR.

	// Gotta use a pointer here to find out which lap the fastest laptime was methinks :)

	cout << "" << endl;
	cout << " " << endl;
	cout << " >>>>		On " << sTrackStore << " you have travelled: ";
	dTotalLength = dMiles * dLap;
	cout << dTotalLength << " miles in a time of: " << dSum << " minutes." << endl;
	cout << "" << endl;
	cout << " >>>>		The Target Lap Time for " << sTrackStore << " was " << dOptimumTime << " minutes." << endl;
	cout << "" << endl;
	cout << " >>>>		Your quickest lap was: " << dSmallest << " minutes." << endl; // Make it so you can print out which lap it was as well
	cout << "" << endl;
	if (dSmallest < dOptimumTime) {
		cout << " >>>>		CONGRATS! You beat the Target Lap Time by " << dOptimumTime - dSmallest << " minute/s :)" << endl;
		cout << "" << endl;

		//cout << " >>>>		It took you " <<  << " laps to beat the Target Time." << endl;
	} else {
		cout << " >>>>		SORRY, You didn't beat the Target Lap Time by " << dSmallest - dOptimumTime << " minute/s :(" << endl;
		cout << "" << endl;
	}
	double dAvgtime = dSum / dLap; // CREATES THE AVERAGE TIME BY DIVIDING THE SUM OF TIME BY THE SUM OF THE DISTANCE TRAVELLED.
	cout << " >>>>		In an AVERAGE time of: " << dAvgtime << " minute/s per lap." << endl;
	// SPEED = DISTANCE/TIME.
	double dSpeed = (dTotalLength * 1609.34) / (dSum * 60); // THIS IS TO WORK OUT LENGTH FROM MILES TO METRES PER SECOND, AND TIME FROM MINUTES TO SECONDS.
	cout << "" << endl;
	cout << " >>>>		At an AVERAGE speed of: " << (dSpeed / 0.44704) << " mph." << endl; // THIS OUTPUTS THE SPEED IN METRES PER SECOND SO IS DIVIDED TO OUTPUT MILES PER HOUR (1MPH = 0.44704 M/S).
	cout << "" << endl;
	
	cout << " >>>>		NY" << string(static_cast<int>(dLap), 'O') << "M!" << endl; // JUST WRITES NYOOM - WITH HOWEVER MANY O'S ACCORDING TO HOW MANY LAPS THE PERSON HAS DONE. JUST A BIT OF FUN.


}

void MenuLoad()
{
	string sMyFirstName = "", sMyLastName = "", sMyNameStore = "", sOption = "";
	bool bTrue = true;

	clear(); // CLEARS SCREEN (FIND FUNCTION IN Functions.cpp).

		//Jerusalem >> http://patorjk.com/software/taag/#p=display&h=3&v=1&f=Jerusalem&t=NEW (FONT FOR FUTURE REFERENCE)

	cout << R"(
		 __    ___    _    ____
		| |   / _ \  / \  |  _ \ 
		| |  | | | |/ _ \ | | | |
		| |__| |_| / ___ \| |_| |
		|_____\___/_/   \_|____/ 

 )" << endl;

	// YOU ALSO NEED TO FIGURE OUT WHAT YOU'LL DO IF THE DATABASE IS EMPTY.

	sMyFirstName = sInput("What is the FIRST name of the person you're looking for?");
	while (bTrue == true) {
		sMyLastName = sInput("What is the LAST name of the person you're looking for?");
		loading();
		ifstream input(DriverData); // YOU CAN READ THE INFORMATION FROM A FILE USING AN IFSTREAM OR FSTREAM OBJECT. 

		if (input.is_open()) { // THE is_open() MEMBER FUNCTION CHECKS WHETHER THE FILE IS OPEN AND READY TO BE ACCESSED.

			while (!input.eof()) {
				string data;
				getline(input, data); // THE GETLINE FUNCTION READS CHARACTERS FROM AN INPUT STREAM AND PLACES THEM INTO A STRING.
				cout << " \n " << endl;
				cout << " >>>>		" << data << endl; // PRINTS IT ALL OUT AT THE MOMENT, NEEDS IT TO ONLY OUTPUT THE CORRESPONDING NAME.
			}
			cout << "" << endl;
			sOption = sInput("Is this the right person you were looking for? [YES/NO]");
			cout << "" << endl;

			// WILL EVENTUALLY OUPUT ALL (UN-EDITABLE) USER INFO HERE, THEN THE LOAD SECTION WILL BE FINISHEDDDDDD

			if (IsNo(sOption))
			{
				clear();
				error();
				cout << "" << endl;
				cout << " >>>>		It seems we can't find the person you're looking for...Try entering their details again." << endl;
				Sleep(4000);
				clear();
			}
		} else {
			error();
		}
	}
}

void MenuUpdate()
{
	string sMyFirstName = "", sMyLastName = "", sMyNameStore = "", sOption = "";
	bool bTrue = true;

	clear();

	cout << R"(
		 _   _ _______        __
		| \ | | ____\ \      / /
		|  \| |  _|  \ \ /\ / / 
		| |\  | |___  \ V  V /  
		|_| \_|_____|  \_/\_/   
                        
 )" << endl;
	sMyFirstName = sInput("What is the FIRST name of the person you're looking for?");
	while (bTrue == true) {
		sMyLastName = sInput("What is the LAST name of the person you're looking for?");
		loading();
		ifstream input(DriverData); // YOU CAN READ THE INFORMATION FROM A FILE USING AN IFSTREAM OR FSTREAM OBJECT. 

		if (input.is_open()) { // THE is_open() MEMBER FUNCTION CHECKS WHETHER THE FILE IS OPEN AND READY TO BE ACCESSED.

			while (!input.eof()) {
				string data;
				getline(input, data); // THE GETLINE FUNCTION READS CHARACTERS FROM AN INPUT STREAM AND PLACES THEM INTO A STRING.
				cout << " \n " << endl;
				cout << " >>>>		" << data << endl; // PRINTS IT ALL OUT AT THE MOMENT, NEEDS IT TO ONLY OUTPUT THE CORRESPONDING NAME.
			}
			cout << "" << endl;
			sOption = sInput("Is this the right person you were looking for? [YES/NO]");
			cout << "" << endl;

			if (IsNo(sOption))
			{
				clear();
				error();
				cout << "" << endl;
				cout << " >>>>		It seems we can't find the person you're looking for...Try entering their details again." << endl;
				Sleep(4000);
				clear();
			}
		} else {
			error();
		}


		// DISPLAYS AN ERROR IF ANYTHING BUT L/LOAD OR N/NEW IS INPUTTED TO THE WELCOME PAGE. 

		error();
		cout << "" << endl;
		cout << " >>>>		User input not recognised..." << endl;
	}
}

void exit()
{
	clear();
	cout << R"(                                    
		  ____  ___   ___  ____  ______   _______ 
		 / ___|/ _ \ / _ \|  _ \| __ \ \ / | ____|
		| |  _| | | | | | | | | |  _ \\ V /|  _|  
		| |_| | |_| | |_| | |_| | |_) || | | |___ 
		 \____|\___/ \___/|____/|____/ |_| |_____|
                                          
)" << endl;
	Sleep(300);
	exit(1);
}