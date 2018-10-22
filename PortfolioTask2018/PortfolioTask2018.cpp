#include "pch.h"
#include <iostream>
#include <windows.h> 
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <locale>
#include <fstream>
#include <chrono>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include "graphic.h" //Loading and Error graphics
//#include <stdio.h>

#pragma comment(lib, "comctl32.lib")

//Just because I prefer using elif (plus it's quicker)
#define elif else if 
#ifdef _MSC_VER
#endif
#define ToUpper(string_data) std::transform(string_data.begin(), string_data.end(), string_data.begin(), ::toupper);

using namespace std;

/*
ASSIGNMENT MUSTS:
INPUT:
>TRACK NAME
>TRACK DISTANCE
>TARGET LAP TIME
>RACE DRIVER
>NUMBER OF LAPS COMPLETED
>LAP TIMES

OUTPUT:
>TRACK NAME
>TARGET LAP TIME
>AVERAGE LAP TIME
>BEST LAP TIME
>TOTAL TIME DRIVEN
>TOTAL DISTANCE TRAVELLED
>WAS THE TARGET TIME BEATEN?
>TOTAL LAPS TAKEN TO BEAT THE TARGET TIME

OVER & ABOVE:
>LEADER BOARD
>SAVE AND LOAD OPTIONS
>DATES
>PB FOR DRIVER

TO DO LIST:
CREATE A SECTION THAT Saves user input about the track and outputs it to a text file (thetracktrackdata.txt)
thetracktrackdata.txt:
NamE
Distance
Target Lap
Best Lap time overall
FOR THE LOAD OPTION
HAVE A NAME AND PASSWORD OPTION? PASSWORD RECOVERY, ECT? OR JUST LOAD DATA FOR THE PERSON'S NAME AND THEN IF THEY WANT TO ADD NEW DATA FOR THAT PERSON THEY NEED A PASSWORD????????
OVER & ABOVE:
>LEADER BOARD
>SAVE AND LOAD OPTIONS
>DATES
>PB FOR DRIVER
*/

void clear() //Used to be able to clear the console.
{
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}

void gotoxy(int x, int y) //Writes over the existing material in the console. Only works if the one that is on the console next is larger than the one before it.
{
	COORD topLeft = { x, y };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(console, topLeft);
}

const string currentDateTime() //Function so that I can call the current time.
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	// Visit http://en.cppreference.com/w/cpp/chrono/c/strftime for more information about date/time format...
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}

bool IsYes(std::string in)
{
	ToUpper(in);
	if (in == "Y" || in == "YES") {
		return true;
	}
	return false;
}
bool IsNo(std::string in)
{
	ToUpper(in);
	if (in == "N" || in == "NO") {
		return true;
	}
	return false;
}
bool IsLoad(std::string in)
{
	ToUpper(in);
	if (in == "L" || in == "LOAD") {
		return true;
	}
	return false;
}
bool IsNew(std::string in)
{
	ToUpper(in);
	if (in == "N" || in == "NEW") {
		return true;
	}
	return false;
}


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

	std::cout << "		" << currentDateTime() << std::endl;
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
				//Insert yes/no options etc.
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
					Sleep(30000000000);
					clear();
					//bTrue = false;

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





