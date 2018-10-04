#include "pch.h"
#include <windows.h> 
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>

#pragma comment(lib, "comctl32.lib")

using namespace std;

//Just because I prefer using elif (plus it's quicker)
#define elif else if 
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS 1
#endif

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

const std::string currentDateTime() //Function so that I can call the current time.
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	// Visit http://en.cppreference.com/w/cpp/chrono/c/strftime for more information about date/time format...
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}

void loading() //Loading graphics function
{
	cout << R"(
		 _     ___    _    ____ ___ _   _  ____   ____    _  _____  _      
		| |   / _ \  / \  |  _ |_ _| \ | |/ ___| |  _ \  / \|_   _|/ \     
		| |  | | | |/ _ \ | | | | ||  \| | |  _  | | | |/ _ \ | | / _ \    
		| |__| |_| / ___ \| |_| | || |\  | |_| | | |_| / ___ \| |/ ___ \   
		|_____\___/_/   \_|____|___|_| \_|\____| |____/_/   \_|_/_/   \_\                   
 )" << endl;
	Sleep(200);
	//system("CLS");
	clear();
	cout << R"(
		 _     ___    _    ____ ___ _   _  ____   ____    _  _____  _      __  
		| |   / _ \  / \  |  _ |_ _| \ | |/ ___| |  _ \  / \|_   _|/ \     \ \ 
		| |  | | | |/ _ \ | | | | ||  \| | |  _  | | | |/ _ \ | | / _ \     \ \
		| |__| |_| / ___ \| |_| | || |\  | |_| | | |_| / ___ \| |/ ___ \    / /
		|_____\___/_/   \_|____|___|_| \_|\____| |____/_/   \_|_/_/   \_\  /_/ 
                                                                                       
 )" << endl;
	Sleep(200);
	//system("CLS");
	clear();
	cout << R"(
		 _     ___    _    ____ ___ _   _  ____   ____    _  _____  _      __   __  
		| |   / _ \  / \  |  _ |_ _| \ | |/ ___| |  _ \  / \|_   _|/ \     \ \  \ \ 
		| |  | | | |/ _ \ | | | | ||  \| | |  _  | | | |/ _ \ | | / _ \     \ \  \ \
		| |__| |_| / ___ \| |_| | || |\  | |_| | | |_| / ___ \| |/ ___ \    / /  / /
		|_____\___/_/   \_|____|___|_| \_|\____| |____/_/   \_|_/_/   \_\  /_/  /_/ 
                                                                                                                                                                
 )" << endl;
	Sleep(200);
	//system("CLS");
	clear();
	cout << R"(                                                                                 
		 _     ___    _    ____ ___ _   _  ____   ____    _  _____  _      __   __   __  
		| |   / _ \  / \  |  _ |_ _| \ | |/ ___| |  _ \  / \|_   _|/ \     \ \  \ \  \ \ 
		| |  | | | |/ _ \ | | | | ||  \| | |  _  | | | |/ _ \ | | / _ \     \ \  \ \  \ \
		| |__| |_| / ___ \| |_| | || |\  | |_| | | |_| / ___ \| |/ ___ \    / /  / /  / /
		|_____\___/_/   \_|____|___|_| \_|\____| |____/_/   \_|_/_/   \_\  /_/  /_/  /_/                                                                               
                                                                                                                                                                
 )" << endl;
	Sleep(200);
	//system("CLS");
	clear();
	cout << R"(                                                                          
		 _     ___    _    ____ ___ _   _  ____   ____    _  _____  _      __   __   __   __  
		| |   / _ \  / \  |  _ |_ _| \ | |/ ___| |  _ \  / \|_   _|/ \     \ \  \ \  \ \  \ \ 
		| |  | | | |/ _ \ | | | | ||  \| | |  _  | | | |/ _ \ | | / _ \     \ \  \ \  \ \  \ \
		| |__| |_| / ___ \| |_| | || |\  | |_| | | |_| / ___ \| |/ ___ \    / /  / /  / /  / /
		|_____\___/_/   \_|____|___|_| \_|\____| |____/_/   \_|_/_/   \_\  /_/  /_/  /_/  /_/ 
                                                                                                                                                          
 )" << endl;
	Sleep(200);
	//system("CLS");
	clear();
	cout << R"(                                                                                                                                                
		 _     ___    _    ____ ___ _   _  ____   ____    _  _____  _      __   __   __   __   __  
		| |   / _ \  / \  |  _ |_ _| \ | |/ ___| |  _ \  / \|_   _|/ \     \ \  \ \  \ \  \ \  \ \ 
		| |  | | | |/ _ \ | | | | ||  \| | |  _  | | | |/ _ \ | | / _ \     \ \  \ \  \ \  \ \  \ \
		| |__| |_| / ___ \| |_| | || |\  | |_| | | |_| / ___ \| |/ ___ \    / /  / /  / /  / /  / /
		|_____\___/_/   \_|____|___|_| \_|\____| |____/_/   \_|_/_/   \_\  /_/  /_/  /_/  /_/  /_/                       
                                                      
 )" << endl;
	Sleep(200);
	//system("CLS");
	clear();

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

	string sMyFirstName = "", sMyLastName = "", sMyNameStore = "";
	string sLorN = "", sLoad = "l", sNew = "n";

	cout << " >>>>		LOAD Previous Data OR Enter NEW data? (l/n)" << endl;
	cout << "" << endl;
	cout << " >>>>		";
	cin >> sLorN;
	//cout << "" << endl;

	if (sLorN == sLoad) {

		//system("CLS");
		clear();

		//Jerusalem >> http://patorjk.com/software/taag/#p=display&h=3&v=1&f=Jerusalem&t=NEW 

		cout << R"(
         
		| |   / _ \  / \  |  _ \ 
		| |  | | | |/ _ \ | | | |
		| |__| |_| / ___ \| |_| |
		|_____\___/_/   \_|____/ 

 )" << endl;

		//if = L >>>>>> LOAD DATA: 
		cout << " >>>>		What is the FIRST name of the person you're looking for?" << endl;
		cout << "" << endl;
		cout << " >>>>		";
		cin >> sMyFirstName;
		cout << "" << endl;
		cout << " >>>>		What is the LAST name of the person you're looking for?" << endl;
		cout << "" << endl;
		cout << " >>>>		";
		cin >> sMyLastName;

		//system("CLS");
		clear();

		loading();

		ifstream input("thetrackuserdata.txt"); //put your program together with this file in the same folder.

		if (input.is_open()) {

			while (!input.eof()) {
				//string number;
				string data;
				getline(input, data); //read number
				//data = atoi(data.c_str()); //convert to integer
				cout << " \n " << endl;
				cout << ">>>>		" << data << endl; //print it out
			}
			//This section needs to read info from the previously saved files, that correspond to their names. 
		}
	} elif(sLorN == sNew)
	{
		//system("CLS");
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
		myfile << " \n"<< sMyNameStore ;
		myfile.close();

		loading();

		cout << "" << endl;
		cout << " >>>>		Hello ";
		cout << sMyNameStore << "!" << endl;

	} else {
		//Displays an error if anything but l or n is inputted to the Welcome page.
		//system("CLS");
		clear();

		cout << R"(                              
		 _____ ____  ____   ___  ____  
		| ____|  _ \|  _ \ / _ \|  _ \ 
		|  _| | |_) | |_) | | | | |_) |
		| |___|  _ <|  _ <| |_| |  _ < 
		|_____|_| \_|_| \_\\___/|_| \_\
                                   			                                    
 )" << endl;
		cout << " >>>>		User input not recognised..." << endl;

	}
	return 0;
}



