// The Orb, Rush Hill Road << Go-to programming tune of the day.

#include "pch.h" // PRECOMPILED HEADER
#include "headers.h" // HEADER FILE CONTAINING ALL THE #INCLUDES FOR HEADERS NEEDED.
#include "graphic.h" //CONTAINS ALL OF MY FUNCTION DECLARATIONS.
//Functions.cpp CONTAINS ALL OF MY FUNCTION IMPLEMENTATIONS.


// NEED TO DO SOME VALIDATION!>!>!>!>!>!>!>!>!>>!>!>!>!>!>!>!>!

using namespace std;

int main()
{
	privacy();

	cout << R"(
							    _.-="_-         _
                         _.-="   _-          | ||"""""""---._______     __..
             ___.===""""-.______-,,,,,,,,,,,,`-''----" """""       """""  __'
      __.--""     __        ,'                   o \           __        [__|
 __-""=======.--""  ""--.=================================.--""  ""--.=======:
]       [L] : /        \ : |========================|    : /        \ :  [G] :
V___________:|          |: |========================|    :|          |:   _-"
 V__________: \        / :_|=======================/_____: \        / :__-"
 -----------'  "-____-"  `-------------------------------'  "-____-"
																																							nyoom...
    __          ________ _      _____ ____  __  __ ______                       
    \ \        / /  ____| |    / ____/ __ \|  \/  |  ____|                      
     \ \  /\  / /| |__  | |   | |   | |  | | \  / | |__                         
      \ \/  \/ / |  __| | |   | |   | |  | | |\/| |  __|                        
       \  /\  /  | |____| |___| |___| |__| | |  | | |____                       
    ____\/_ \/__ |______|______\_____\____/|_|__|_|______|           _____ _  __
   |__   __/ __ \  |__   __| |  | |  ____| |__   __|  __ \     /\   / ____| |/ /
      | | | |  | |    | |  | |__| | |__       | |  | |__) |   /  \ | |    | ' / 
      | | | |  | |    | |  |  __  |  __|      | |  |  _  /   / /\ \| |    |  <  
      | | | |__| |    | |  | |  | | |____     | |  | | \ \  / ____ \ |____| . \ 
      |_|  \____/     |_|  |_|  |_|______|    |_|  |_|  \_\/_/    \_\_____|_|\_\
                                                                                
                                                                                

        )" << endl;

	cout << "		" << currentDateTime() << endl; // CURRENT DATETIME YY/MM/DD-HH:MM:SS
	cout << "" << endl;

	string sMyFirstName = "", sMyLastName = "", sMyNameStore = "", sOp = ""; // STRING VARIABLES FOR INPUTTING: THE DRIVERS FIRSTNAME & LAST NAME, STORAGE OF THE NAMES TO USE LATER ON IN THE PROGRAM AND sOp IS FOR WHEN THE USER NEEDS TO INPUT YES OR NO.
	string sLorN = "", sPassword = "", sPassStore = ""; // STRING VARIABLES FOR LOAD OR NEW OPTIONS AT THE PROGRAM'S 'WELCOME SCREEN', THE PASSWORD 
	bool bTrue = true;
	double x = 0, dsum = 0;

	sLorN = sInput("LOAD Previous Data OR Enter NEW data? [LOAD/NEW]");

	if (IsLoad(sLorN)) {

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
				sOp = sInput(" >>>>		Is this the right person you were looking for? [YES/NO]");
				cout << "" << endl;

				// WILL EVENTUALLY OUPUT ALL (UN-EDITABLE) USER INFO HERE, THEN THE LOAD SECTION WILL BE FINISHEDDDDDD

				if (IsNo(sOp))
				{
					clear();
					error();
					cout << "" << endl;
					cout << " >>>>		It seems we can't find the person you're looking for...Try entering their details again." << endl;
					Sleep(3000);
					clear();
				}
			} else {
				error();
			}
		}
	} else if (IsNew(sLorN))
	{
		clear();

		cout << R"(
		 _   _ _______        __
		| \ | | ____\ \      / /
		|  \| |  _|  \ \ /\ / / 
		| |\  | |___  \ V  V /  
		|_| \_|_____|  \_/\_/   
                        
 )" << endl;

		string addorupdate = "";

		addorupdate = sInput("Are you looking to add a new user or update the data of an existing user? [ADD/UPDATE]");

		if (IsAdd(addorupdate)) {

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

			double length = 0.0; // THE TOTAL AMOUNT OF MILES TRAVELLED ON THE TRACK (MILES x AMOUNT OF LAPS).
			double dNum = 0.0; // HOW MANY MILES LONG THE TRACK IS.
			double dLap = 0.0; // NUMBER OF LAPS COMPLETED.
			string sTrack = ""; // TRACK NAME.
			string sTrackStore = ""; // TRACK'S NAME STORED. 
			double dOptimumTime = 0.0; // THE TRACK'S OPTIMUM TIME.


			sTrack = sInput("What is the name of the racetrack you drove on today?");
			sTrackStore = sTrack;
			cout << "" << endl;
			dNum = dInput("How many miles long is " + sTrackStore + "?");

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

			double dSmallest = 2000000000.7; // THIS IS USED IN A FOR LOOP LATER TO TRY AND FIND THE FASTEST LAPTIME.

			/* AUTO DTIME IS BASICALLY THE SAME AS WRITING:

			for (int i = 0; i < dLapMins.size(); i++)
				cout << dLapMins[i] << endl;

			tHE AUTO KEYWORD ASKS THE COMPILER TO DEDUCE IT'S TYPE FROM ITS INITIALISER. :)
				*/

			for (auto dTime : dLapMins) {
				cout << dTime << endl;
				if (dTime < dSmallest) {
					dSmallest = dTime;
				}
			}

			int iLapRound = 1;
			bool done = false; // USED IN THE FOR LOOP BELOW SO THAT IF THE TRACK TIME IS FASTER THAN THE OPTIMUM TIME IT BREAKS OUT OF THE LOOP (done = true).

			for (int i = 0; i < dLapMins.size() && done == false; i++) {
				if (dTime < dOptimumTime) {
					++iLapRound;
					done = true;
				}
			}

			clear();

			double dsum = accumulate(dLapMins.begin(), dLapMins.end(), 0.0); // TOTAL TIME SPENT DRIVING ON THE TRACK, 'ACCUMULATING' FROM THE dLapMins VECTOR.

			cout << "" << endl;
			cout << " " << endl;
			cout << " >>>>		On " << sTrackStore << " you have travelled: ";
			length = dNum * dLap;
			cout << length << " miles in a time of: " << dsum << " minutes." << endl;
			cout << "" << endl;
			cout << " >>>>		The Target Lap Time for " << sTrackStore << " was " << dOptimumTime << " minutes." << endl;
			cout << "" << endl;
			cout << " >>>>		Your quickest lap was: " << dSmallest << " minutes." << endl; // Make it so you can print out which lap it was as well
			cout << "" << endl;
			if (dSmallest < dOptimumTime) {
				cout << " >>>>		CONGRATS! You beat the Target Lap Time by " << dOptimumTime - dSmallest << " minute/s :)" << endl;
				cout << "" << endl;
			} else {
				cout << " >>>>		SORRY, You didn't beat the Target Lap Time by " << dSmallest - dOptimumTime << " minute/s :(" << endl;
				cout << "" << endl;
			}
			double avgtime = dsum / dLap; // CREATES THE AVERAGE TIME BY DIVIDING THE SUM OF TIME BY THE SUM OF THE DISTANCE TRAVELLED.
			cout << " >>>>		In an AVERAGE time of: " << avgtime << " minute/s per lap." << endl;
			// SPEED = DISTANCE/TIME.
			double speed = (length * 1609.34) / (dsum * 60); // THIS IS TO WORK OUT LENGTH FROM MILES TO METRES PER SECOND, AND TIME FROM MINUTES TO SECONDS.
			cout << "" << endl;
			cout << " >>>>		At an AVERAGE speed of: " << (speed / 0.44704) << " mph." << endl; // THIS OUTPUTS THE SPEED IN METRES PER SECOND SO IS DIVIDED TO OUTPUT MILES PER HOUR (1MPH = 0.44704 M/S).
			cout << "" << endl;
			string(dLap, 'O');
			cout << " >>>>		NY" << string(dLap, 'O') << "M!" << endl; // JUST WRITES NYOOM - WITH HOWEVER MANY O'S ACCORDING TO HOW MANY LAPS THE PERSON HAS DONE. JUST A BIT OF FUN.
		} else if (IsUpdate(addorupdate)) {

			// GOTTA FIGURE OUT HOW TO ADD NEW INFO TO EXISITING INFO AND WHACK IT HERER

		}
	} else {

		// DISPLAYS AN ERROR IF ANYTHING BUT L/LOAD OR N/NEW IS INPUTTED TO THE WELCOME PAGE. 

		error();
		cout << "" << endl;
		cout << " >>>>		User input not recognised..." << endl;
	}
return 0;
}








