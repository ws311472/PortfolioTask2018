#include "pch.h"
#include "Graphic.h"
#include "Input.h"
#include "IsFunction.h"
#include "Menu.h"

// DEFINITIONS FROM http://www.cplusplus.com/reference/ & https://en.cppreference.com/w/.


// Make sure all the variables follow the same format.
// NEED TO DO SOME (a lot) OF THE VALIDATION!>!>!>!>!>!>!>!>!>>!>!>!>!>!>!>!>!
// Include pointer etc. 
// Structures, Vectors please :)

using namespace std;

int main()
{
	privacy(); // PRIVACY/DATA STORAGE POLICY (FOUND IN: Functions.cpp)

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

	while (1) {
		string sOption = ""; // STRING VARIABLES FOR INPUTTING: THE DRIVERS FIRSTNAME & LAST NAME, STORAGE OF THE NAMES TO USE LATER ON IN THE PROGRAM AND sOption IS FOR WHEN THE USER NEEDS TO INPUT YES OR NO.
		int iMenuChoice = 0;

		cout << R"(
                         
		 __  __ _____ _   _ _   _ 
		|  \/  | ____| \ | | | | |
		| |\/| |  _| |  \| | | | |
		| |  | | |___| |\  | |_| |
		|_|  |_|_____|_| \_|\___/ 
                          

|  >>>>		1. LOAD																		
|																						
|  >>>>		2. ADD																		
|																						
|  >>>>		3. UPDATE																	
|								
|  >>>>		4. EXIT
|														
|  >>>>		LOAD Previous Data OR ADD New data OR UPDATE Existing Data OR EXIT [1, 2, 3 or 4]?		
|																						
|  >>>>		CHOICE = )";

		getline(cin, sOption);
		iMenuChoice = std::stoi(sOption);

		switch (iMenuChoice)
		{
		case 1:
			MenuLoad();
			break;
		case 2:
			MenuAdd();
			break;
		case 3:
			MenuUpdate();
			break;
		case 4:
			exit();
		break;
		default:
			error();
			break;
		}
	}
	return 0;
}









