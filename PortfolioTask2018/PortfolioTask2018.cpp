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
> BEST LAP TIME
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
//    __          ________ _      _____ ____  __  __ ______                       
//    \ \        / /  ____| |    / ____/ __ \|  \/  |  ____|                      
//     \ \  /\  / /| |__  | |   | |   | |  | | \  / | |__                         
//      \ \/  \/ / |  __| | |   | |   | |  | | |\/| |  __|                        
//       \  /\  /  | |____| |___| |___| |__| | |  | | |____                       
//    ____\/_ \/__ |______|______\_____\____/|_|__|_|______|           _____ _  __
//   |__   __/ __ \  |__   __| |  | |  ____| |__   __|  __ \     /\   / ____| |/ /
//      | | | |  | |    | |  | |__| | |__       | |  | |__) |   /  \ | |    | ' / 
//      | | | |  | |    | |  |  __  |  __|      | |  |  _  /   / /\ \| |    |  <  
//      | | | |__| |    | |  | |  | | |____     | |  | | \ \  / ____ \ |____| . \ 
//      |_|  \____/     |_|  |_|  |_|______|    |_|  |_|  \_\/_/    \_\_____|_|\_\
//                                                                                
//                                                                                

        )" << endl;

	cout << " >>>>		LOAD Previous Data OR Enter NEW data?" << endl;

	string sMyname = "", sMynameStore = "";
	cout << "" << endl;
	cout << " >>>>		What is your name?" << endl;
	//Saves user input and outputs it to a text file (thetrackuserdata.txt)
	cout << " >>>>		";
	cin >>sMyname;
	sMynameStore = sMyname;
	ofstream myfile;
	myfile.open("thetrackuserdata.txt", std::ofstream::app);
	myfile << sMynameStore <<"\n";
	myfile.close();


	return 0;
}


