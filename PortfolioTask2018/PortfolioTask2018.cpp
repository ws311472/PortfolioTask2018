// The Orb, Rush Hill Road.
#include "pch.h" // PRECOMPILED HEADER
#include "headers.h" // HEADER FILE CONTAINING ALL THE #INCLUDES FOR HEADERS NEEDED.
#include "graphic.h" //CONTAINS ALL OF MY FUNCTION DECLARATIONS.
//Functions.cpp CONTAINS ALL OF MY FUNCTION IMPLEMENTATIONS.

using namespace std;

int main()
{
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

	string sMyFirstName = "", sMyLastName = "", sMyNameStore = "", sOp = "";
	string sLorN = "", sPassword = "", sPassStore = "";
	bool bTrue = true;
	double x = 0, dsum = 0;

	sLorN = sInput("LOAD Previous Data OR Enter NEW data?");

	if (IsLoad(sLorN)) {

		clear(); // CLEARS SCREEN (FIND FUNCTION IN Functions.cpp)

		//Jerusalem >> http://patorjk.com/software/taag/#p=display&h=3&v=1&f=Jerusalem&t=NEW (FONT FOR FUTURE REFERENCE)

		cout << R"(
		 __    ___    _    ____
		| |   / _ \  / \  |  _ \ 
		| |  | | | |/ _ \ | | | |
		| |__| |_| / ___ \| |_| |
		|_____\___/_/   \_|____/ 

 )" << endl;

		sMyFirstName = sInput("What is the FIRST name of the person you're looking for?");
		while (bTrue == true) {
			sMyLastName = sInput("What is the LAST name of the person you're looking for?");
			loading();
			ifstream input(DriverData); //You can read information from a file using an ifstream or fstream object. 

			if (input.is_open()) { //The is_open() member function checks whether the file is open and ready to be accessed.

				while (!input.eof()) {
					string data;
					getline(input, data); //The getline function reads characters from an input stream and places them into a string.
					//data = atoi(data.c_str()); //convert to integer
					cout << " \n " << endl;
					cout << " >>>>		" << data << endl; //print it out

				//This section needs to read info from the previously saved files, that correspond to their names. 
				}

				cout << "" << endl;
				sOp = sInput(" >>>>		Is this the right person you were looking for? (y/n)");
				cout << "" << endl;

				if (IsYes(sOp)) {
					cout << " >>>>		In order to edit this person's details you will have to login." << endl;
					cout << "" << endl;
					cout << " >>>>		Please enter the password associated with this account." << endl;
					cout << "" << endl;
					cout << " >>>>		" << sMyNameStore << endl;
					cout << "" << endl;
					cout << " >>>>		Password: " << endl;
					//^^^Needs to call from a preset password file which is linked to the person's name that they typed in

				} else if (IsNo(sOp))
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

		//if = N >>>>>> NEW DATA: 
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

		double length = 0.0;
		double dNum = 0.0;
		double dLap = 0.0;
		string sTrack = "";
		string sTrackStore = "";
		double dOptimumTime = 0.0;


		sTrack = sInput("What is the name of the racetrack you drove on today?");
		sTrackStore = sTrack;
		cout << "" << endl;
		dNum = dInput("How many miles long is " + sTrackStore + "?");

		dOptimumTime = dInput("What is the Target Lap Time for this course?");
		cout << "" << endl;
		dLap = dInput("How many laps did you achieve altogether?: ");
		clear();
		//cout << "" << endl;

		int iAttempt = 1;
		double dTime = 0;

		vector<double> dLapMins;

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

		double dSmallest = 2000000000.7;
		double dLapNo = 0;

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
		bool done = false;

		for (int i = 0; i < dLapMins.size() && done == false; i++) {
			if (dTime < dOptimumTime) {
				++iLapRound;
				done = true;
			}


			clear();

			double dsum = accumulate(dLapMins.begin(), dLapMins.end(), 0.0);

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
			double avgtime = dsum / dLap;
			cout << " >>>>		In an AVERAGE time of: " << avgtime << " minute/s per lap." << endl;
			// SPEED = DISTANCE/TIME.
			double speed = (length * 1609.34) / (dsum * 60); // THIS IS TO WORK OUT LENGTH FROM MILES TO METRES PER SECOND, AND TIME FROM MINUTES TO SECONDS.
			cout << "" << endl;
			cout << " >>>>		At an AVERAGE speed of: " << (speed / 0.44704) << " mph." << endl; // THIS OUTPUTS THE SPEED IN METRES PER SECOND SO IS DIVIDED TO OUTPUT MILES PER HOUR (1MPH = 0.44704 M/S).
			cout << "" << endl;
			string(dLap, 'O');
			cout << " >>>>		NY" << string(dLap, 'O') << "M!" << endl; // JUST WRITES NYOOM, WITH HOWEVER MANY O'S ACCORDING TO HOW MANY LAPS THE PERSON HAS DONE. JUST A BIT OF FUN.

		}
	} else {

		// DISPLAYS AN ERROR IF ANYTHING BUT L/LOAD OR N/NEW IS INPUTTED TO THE WELCOME PAGE. 

		error();
		cout << "" << endl;
		cout << " >>>>		User input not recognised..." << endl;
	}
	return 0;
}








