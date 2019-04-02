#include "pch.h" // PRECOMPILED HEADER
#include "Initialise.h" //CONTAINS ALL OF MY FUNCTION DECLARATIONS.
#include <windows.h> // WINDOWS-SPECIFIC. CONTAINS DECLARATIONS FOR ALL THE WINDOWS API FUNCTIONS AND MACROS (AND ALL THE DATA TYPES).
#include <cstdlib> // C STANDARD GENERAL UTILITIES LIBRARY. THIS HEADER DEFINES SEVERAL GENERAL PURPOSE FUNCTIONS E.G. INTEGER ARITHMETICS, SEARCHING, SORTING, CONVERTING ETC. 
#include <locale> // "SET OF POLYMORPHIC FACETS THAT ENCAPSULATE CULTURAL DIFFERENCES" - STRING AND STREAM CONVERSIONS. IN THIS PROGRAM: TOUPPER.
#include <stdlib.h>
#include <fstream> // INPUT/OUPUT STREAM CLASS TO OPERATE ON FILES.
#include <conio.h>
#include <chrono> // THE ELEMENTS IN THIS HEADER DEAL WITH TIME. MAINLY IN THREE CONCEPTS:
// DURATIONS: THEY MEASURE TIME SPAN E.G. 1 MINUTE, 2 HOURS, 10 MILLISECONDS ETC. 
// TIME POINTS: A REFERENCE TO A SPECIFIC POINT IN TIME, E.G. SOMEONE'S BIRTHDAY. IN THIS LIBRARY, OBJECTS OF THE TIME_POINT CLASS TEMPLATE EXPRESS THIS USING A DURATION RELATIVE TO AN EPOCH (UNIX: JANUARY 1ST 1970).
// CLOCKS: A FRAMEWORK THAT RELATES A TIME POINT TO REAL PHYSICAL TIME. THE LIBRARY PROVIDES THREE CLOCKS THAT PROVIDE MEANS TO EXPRESS THE CURRENT TIME AS A TIME_POINT.
#include <algorithm> // DEFINES A COLLECTION OF FUNCTIONS ESPECIALLY DESIGNED TO BE USED ON RANGES OF ELEMENTS. (A RANGE IS ANY SEQUENCE OF OBJECTS THAT CAN BE ACCESSED THROUGH ITERATORS OR POINTERS, SUCH AS AN ARRAY ETC.)
#include <vector> // HEADER THAT DEFINES THE HEADER CONTAINER CLASS.
#include <numeric> // THIS HEADER DESCRIBES A SET OF ALGORITHMS TO PERFORM CERTAIN OPERATIONS ON A SEQUENCE OF NUMERIC VALUES (FOR THIS PROGRAM, SPECFICIALLY 'accumulate').
#include <iostream> // HEADER THAT DEFINES THE STANDARD INPUT/OUTPUT STREAM OBJECTS. (cin/cout ETC.)
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

//		cin >> iMenuChoice;
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









