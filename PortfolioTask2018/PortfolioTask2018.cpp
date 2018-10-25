// The Orb, Rush..?
#include "pch.h"
#include "headers.h" // Header file containing all the #includes for headers needed.
//CONTAINS ALL OF MY FUNCTION IMPLEMENTATIONS:

using namespace std;

//CountTrackula, Tracktor, TrackToTheFuture, TrackStreetBoys

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

	cout << "		" << currentDateTime() << endl;
	cout << "" << endl;

	string sMyFirstName = "", sMyLastName = "", sMyNameStore = "", sOp = "";
	string sLorN = "", sPassword = "", sPassStore = "";
	int iNum = 0;
	bool bTrue = true;
	float x = 0, fsum = 0;

	//string trackname[5] = { "Tracktor", "Track To The Future", "Track Street Boys", "Count Trackula" };

	sLorN = sInput("LOAD Previous Data OR Enter NEW data?");

	if (IsLoad(sLorN)) {

		clear();

		//Jerusalem >> http://patorjk.com/software/taag/#p=display&h=3&v=1&f=Jerusalem&t=NEW 

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

				} else if(IsNo(sOp))
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
	}
	else if(IsNew(sLorN))
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
		myfile.open(DriverData, ofstream::app); //If the specified file does not exist, the open function will create it automatically.
		myfile << " \n" << sMyNameStore;
		myfile.close(); // When you've finished working with a file, close it using the member function close().
		//You also have the option of specifying a path for your file in the open function, since it can be in a location other than that of your project.

		loading();

		cout << "" << endl;
		cout << " >>>>		Hello " << sMyNameStore << "!" << endl;
		cout << "" << endl;

		float length = 0;
		float iNum = 0;
		float iLap = 0;
		string sTrack = "";
		string sTrackStore = "";

		sTrack = sInput("What is the name of the racetrack you drove on today?");
		sTrackStore = sTrack;
		cout << "" << endl;
		cout << " >>>>		How many miles long is " << sTrackStore << "?: " << endl;
		cout << "" << endl;
		cout << " >>>>		";
		cin >> iNum;
		cout << "" << endl;
		cout << " >>>>		How many laps did you achieve altogether?: " << endl;
		cout << "" << endl;
		cout << " >>>>		";
		cin >> iLap;
		clear();
		cout << "" << endl;

		int iAttempt = 1;
		float fTime = 0;

		vector<float> fLapMins;

		while (iAttempt <= iLap) {

			cout << "" << endl;
			cout << " >>>>		What was your time for Lap number " << iAttempt << "?" << endl;
			cout << "" << endl;
			cout << " >>>>		";
			cin >> fTime;
			fLapMins.push_back(fTime);
			iAttempt++;

		}

		iAttempt = 1;

		for (auto mins : fLapMins) {

			cout << "" << endl;
			cout << " >>>>		" << "Lap " << iAttempt++ << " = " << mins << " minutes." << endl;
			cout << "" << endl;
		}

		float fSmallest = 2000000000.7;

		/* for (int i = 0; i < fLapMins.size(); i++)
			cout << fLapMins[i] << endl; */

		for (auto fTime : fLapMins) {
			cout << fTime << endl;
			if (fTime < fSmallest) {
				fSmallest = fTime;
			}
		}

		clear();

		float fsum = accumulate(fLapMins.begin(), fLapMins.end(), 0);

		cout << "" << endl;
		cout << " " << endl;
		cout << " >>>>		On " << sTrackStore << " you have travelled: ";
		length = iNum * iLap;
		cout << length << " miles, in a time of: " << fsum << " minutes." << endl;
		cout << "" << endl;
		cout << " >>>>		Your quickest lap was: " << fSmallest << " minutes." << endl;
		cout << "" << endl;
		float avgtime = fsum / iLap;
		cout << " >>>>		In an AVERAGE time of: " << avgtime << " minute/s per lap." << endl;
		float speed = (length * 1609.34) / (fsum * 60); // This is to work out length from miles to metres per second, and time from minutes to seconds.
		cout << "" << endl;
		cout << " >>>>		At an AVERAGE speed of: " << (speed / 0.44704) << " mph." << endl; // This outputs the speed in metres per second so is multiplied to output miles per hour
		cout << "" << endl;
		string(iLap, 'O');
		cout << " >>>>		NY" << string(iLap, 'O') << "M!" << endl;

	} else {

		//Displays an error if anything but load/l or new/n is inputted to the Welcome page.
		error();
		cout << "" << endl;
		cout << " >>>>		User input not recognised..." << endl;
	}
	return 0;
}








