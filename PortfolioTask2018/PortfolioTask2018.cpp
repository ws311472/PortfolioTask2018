#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <windows.h> 
#include <CommCtrl.h>
#include <fstream>

#pragma comment(lib, "comctl32.lib")

using namespace std;

#define elif else if 
/*
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


*/

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

	string sMyFirstName = "", sMyLastName = "", sMyNameStore = "";
	string sLorN = "", sLoad = "l", sNew = "n";

	cout << " >>>>		LOAD Previous Data OR Enter NEW data? (l/n)" << endl;
	cout << "" << endl;
	cout << " >>>>		";
	cin >> sLorN;
	//cout << "" << endl;

	if (sLorN == sLoad) {

		//Jerusalem >> http://patorjk.com/software/taag/#p=display&h=3&v=1&f=Jerusalem&t=NEW 

		cout << R"(
		| |   / _ \  / \  |  _ \ 
		| |  | | | |/ _ \ | | | |
		| |__| |_| / ___ \| |_| |
		|_____\___/_/   \_|____/ 
 )" << endl;

		//if = L >>>>>> LOAD DATA: 
		cout << " >>>>		What is your FIRST name?" << endl;
		cout << "" << endl;
		cout << " >>>>		";
		cin >> sMyFirstName;
		cout << "" << endl;
		cout << " >>>>		What is your LAST name?" << endl;
		cout << "" << endl;
		cout << " >>>>		";
		cin >> sMyLastName;

		ifstream input("thetrackuserdata.txt"); //put your program together with this file in the same folder.

		if (input.is_open()) {

			while (!input.eof()) {
				//string number;
				string data;
				getline(input, data); //read number
				//data = atoi(data.c_str()); //convert to integer
				cout << "" << endl;
				cout << ">>>>		" << data << endl; //print it out
			}
			//This section needs to read info from the previously saved files, that correspond to their names. 
		}
	} elif(sLorN == sNew)
	{
		cout << R"(
		 _   _ _______        __
		| \ | | ____\ \      / /
		|  \| |  _|  \ \ /\ / / 
		| |\  | |___  \ V  V /  
		|_| \_|_____|  \_/\_/   
                        
 )" << endl;

		//if = N >>>>>> NEW DATA: 
		cout << " >>>>		What is your FIRST name?" << endl;
		//Saves user input and outputs it to a text file (thetrackuserdata.txt)
		/*
		thetrackuserdata.txt:
		Name
		PB
		*/
		cout << "" << endl;
		cout << " >>>>		";
		cin >> sMyFirstName;
		cout << "" << endl;
		cout << " >>>>		What is your LAST name?" << endl;
		cout << "" << endl;
		//Saves user input and outputs it to a text file (thetrackuserdata.txt)
		/*
		thetrackuserdata.txt:
		Name
		PB
		*/
		cout << " >>>>		";
		cin >> sMyLastName;
		sMyNameStore = sMyFirstName + " " + sMyLastName;
		ofstream myfile;
		myfile.open("thetrackuserdata.txt", std::ofstream::app);
		myfile << sMyNameStore << "\n";
		myfile.close();

	} else {
		cout << " >>>>		User input not recognised..." << endl;
	}
return 0;
		
		/*
		TO DO LIST:
		CREATE A SECTION THAT Saves user input about the track and outputs it to a text file (thetracktrackdata.txt)
		thetracktrackdata.txt:
		Name
		Distance
		Target Lap
		Best Lap time overall
		FOR THE LOAD OPTION
		HAVE A NAME AND PASSWORD OPTION? PASSWORD RECOVERY, ECT? OR JUST LOAD DATA FOR THE PERSON'S NAME AND THEN IF THEY WANT TO ADD NEW DATA FOR THAT PERSON THEY NEED A PASSWORD????????
		*/
}


