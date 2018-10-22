#include "pch.h"
#include "headers.h" // Header file containing all the #includes for headers needed.


using namespace std;

int main()
{
	cout << R"(
							    _.-="_-         _
                         _.-="   _-          | ||"""""""---._______     __..
             ___.===""""-.______-,,,,,,,,,,,,`-''----" """""       """""  __'
      __.--""     __        ,'                   o \           __        [__|
 __-""=======.--""  ""--.=================================.--""  ""--.=======:
]       [w] : /        \ : |========================|    : /        \ :  [w] :
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

	cout << " >>>>		LOAD Previous Data OR Enter NEW data?" << endl;
	cout << "" << endl;
	cout << " >>>>		";
	cin >> sLorN;

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

		while (bTrue == true) {
			cout << "" << endl;
			cout << " >>>>		What is the FIRST name of the person you're looking for?" << endl;
			cout << "" << endl;
			cout << " >>>>		";
			cin >> sMyFirstName;
			ToUpper(sMyFirstName);
			cout << "" << endl;
			cout << " >>>>		What is the LAST name of the person you're looking for?" << endl;
			cout << "" << endl;
			cout << " >>>>		";
			cin >> sMyLastName;
			ToUpper(sMyLastName);


			loading();

			ifstream input("thetrackuserdata.txt"); //You can read information from a file using an ifstream or fstream object. 

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
				cout << " >>>>		Is this the right person you were looking for? (y/n)" << endl;
				cout << "" << endl;
				cout << " >>>>		";
				cin >> sOp;
				ToUpper(sOp);
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

				} elif(IsNo(sOp))
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
	}   elif(IsNew(sLorN))
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
		cout << " >>>>		What is your FIRST name?" << endl;
		cout << "" << endl;
		cout << " >>>>		";
		cin >> sMyFirstName;
		ToUpper(sMyFirstName);
		cout << "" << endl;
		cout << " >>>>		What is your LAST name?" << endl;
		cout << "" << endl;
		//Saves user input and outputs it to a text file (thetrackuserdata.txt)
		/*
		thetrackuserdata.txt:
		Name
		*/
		cout << " >>>>		";
		cin >> sMyLastName;
		ToUpper(sMyLastName);
		sMyNameStore = sMyFirstName + " " + sMyLastName;
		ofstream myfile;
		myfile.open("C:Users\\User01\source\repos\TheTrackDataFile\thetrackuserdata.txt", std::ofstream::app); //If the specified file does not exist, the open function will create it automatically.
		myfile << " \n" << sMyNameStore;
		myfile.close(); // When you've finished working with a file, close it using the member function close().
		//You also have the option of specifying a path for your file in the open function, since it can be in a location other than that of your project.

		loading();

		cout << "" << endl;
		cout << " >>>>		Hello " << sMyNameStore << "!" << endl;
		cout << "" << endl;

		float fNumStore = 0;
		int iLap = 0;
		string sTrack = "";
		string sTrackStore = "";

		cout << " >>>>		What is the name of the racetrack you drove on today?" << endl;
		cout << " " << endl;
		cout << " >>>>		";
		cin >> sTrack;
		sTrackStore = sTrack;
		ToUpper(sTrackStore);
		// cout << " >>>>		";
		cout << " " << endl;
		cout << " >>>>		How many miles long is " << sTrackStore << "?: " << endl;
		cout << "" << endl;
		cout << " >>>>		";
		cin >> iNum;
		cout << "" << endl;
		cout << " >>>>		How many laps did you achieve alltogether?: " << endl;
		cout << "" << endl;
		cout << " >>>>		";
		cin >> iLap;
		clear();
		cout << "" << endl;
		cout << " >>>>		Altogether, on " << sTrackStore << " you have travelled: ";
		fNumStore = iNum * iLap;
		cout << fNumStore << " miles!" << endl;
		cout << "" << endl;

		int iAttempt = 1;
		float fTime = 0;
		std::vector<float> fLapMins;

		while (iAttempt <= iLap) {

			cout << "" << endl;
			cout << " >>>>		What was your time for Lap number " << iAttempt << "?" << endl;
			cout << "" << endl;
			cout << " >>>>		";
			cin >> fTime;
			fLapMins.push_back(fTime);
			iAttempt++;
		}
		for (auto mins : fLapMins) {

			clear();
			cout << "" << endl;
			cout << " >>>>		" << "Lap." << --iAttempt << " " << mins << " minutes." << endl;
		}
		for (x = 0; x < iLap; x++)
		{
			fsum = 0;

			fsum += fLapMins[x];
		}
		cout << "" << endl;
		cout << " >>>>		Your total time is: " << fsum << " minutes." << endl;

		cout << "" << endl;
		std::string(iLap, 'O');
		cout << " >>>>		NY" << std::string(iLap, 'O') << "M!" << endl;


	} else {

		//Displays an error if anything but l or n is inputted to the Welcome page.
		error();
		cout << "" << endl;
		cout << " >>>>		User input not recognised..." << endl;
	}
	return 0;
}





