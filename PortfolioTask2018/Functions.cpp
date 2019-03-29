#include "pch.h"
#include <cstdio>
#include <cctype>
#include <iostream>
#include "Initialise.h"
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
#include "consoleapi2.h"
using namespace std;

void ToUpper(std::string& string_data)
{
	std::transform(string_data.begin(), string_data.end(), string_data.begin(), [](char c) ->  char { return std::toupper(c); });
}

void clear() // CLEARS THE CONSOLE.
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

void loading() // LOADING GRAPHICS.
{
	clear();

	cout << R"(
		 _     ___    _    ____ ___ _   _  ____   ____    _  _____  _      
		| |   / _ \  / \  |  _ |_ _| \ | |/ ___| |  _ \  / \|_   _|/ \     
		| |  | | | |/ _ \ | | | | ||  \| | |  _  | | | |/ _ \ | | / _ \    
		| |__| |_| / ___ \| |_| | || |\  | |_| | | |_| / ___ \| |/ ___ \   
		|_____\___/_/   \_|____|___|_| \_|\____| |____/_/   \_|_/_/   \_\                   
 )" << endl;
	Sleep(200);
	clear();
	cout << R"(
		 _     ___    _    ____ ___ _   _  ____   ____    _  _____  _      __  
		| |   / _ \  / \  |  _ |_ _| \ | |/ ___| |  _ \  / \|_   _|/ \     \ \ 
		| |  | | | |/ _ \ | | | | ||  \| | |  _  | | | |/ _ \ | | / _ \     \ \
		| |__| |_| / ___ \| |_| | || |\  | |_| | | |_| / ___ \| |/ ___ \    / /
		|_____\___/_/   \_|____|___|_| \_|\____| |____/_/   \_|_/_/   \_\  /_/ 
                                                                                       
 )" << endl;
	Sleep(200);
	clear();
	cout << R"(
		 _     ___    _    ____ ___ _   _  ____   ____    _  _____  _      __   __  
		| |   / _ \  / \  |  _ |_ _| \ | |/ ___| |  _ \  / \|_   _|/ \     \ \  \ \ 
		| |  | | | |/ _ \ | | | | ||  \| | |  _  | | | |/ _ \ | | / _ \     \ \  \ \
		| |__| |_| / ___ \| |_| | || |\  | |_| | | |_| / ___ \| |/ ___ \    / /  / /
		|_____\___/_/   \_|____|___|_| \_|\____| |____/_/   \_|_/_/   \_\  /_/  /_/ 
                                                                                                                                                                
 )" << endl;
	Sleep(200);
	clear();
	cout << R"(                                                                                 
		 _     ___    _    ____ ___ _   _  ____   ____    _  _____  _      __   __   __  
		| |   / _ \  / \  |  _ |_ _| \ | |/ ___| |  _ \  / \|_   _|/ \     \ \  \ \  \ \ 
		| |  | | | |/ _ \ | | | | ||  \| | |  _  | | | |/ _ \ | | / _ \     \ \  \ \  \ \
		| |__| |_| / ___ \| |_| | || |\  | |_| | | |_| / ___ \| |/ ___ \    / /  / /  / /
		|_____\___/_/   \_|____|___|_| \_|\____| |____/_/   \_|_/_/   \_\  /_/  /_/  /_/                                                                               
                                                                                                                                                                
 )" << endl;
	Sleep(200);
	clear();
	cout << R"(                                                                          
		 _     ___    _    ____ ___ _   _  ____   ____    _  _____  _      __   __   __   __  
		| |   / _ \  / \  |  _ |_ _| \ | |/ ___| |  _ \  / \|_   _|/ \     \ \  \ \  \ \  \ \ 
		| |  | | | |/ _ \ | | | | ||  \| | |  _  | | | |/ _ \ | | / _ \     \ \  \ \  \ \  \ \
		| |__| |_| / ___ \| |_| | || |\  | |_| | | |_| / ___ \| |/ ___ \    / /  / /  / /  / /
		|_____\___/_/   \_|____|___|_| \_|\____| |____/_/   \_|_/_/   \_\  /_/  /_/  /_/  /_/ 
                                                                                                                                                          
 )" << endl;
	Sleep(200);
	clear();
	cout << R"(                                                                                                                 
		 _     ___    _    ____ ___ _   _  ____   ____    _  _____  _      __   __   __   __   __  
		| |   / _ \  / \  |  _ |_ _| \ | |/ ___| |  _ \  / \|_   _|/ \     \ \  \ \  \ \  \ \  \ \ 
		| |  | | | |/ _ \ | | | | ||  \| | |  _  | | | |/ _ \ | | / _ \     \ \  \ \  \ \  \ \  \ \
		| |__| |_| / ___ \| |_| | || |\  | |_| | | |_| / ___ \| |/ ___ \    / /  / /  / /  / /  / /
		|_____\___/_/   \_|____|___|_| \_|\____| |____/_/   \_|_/_/   \_\  /_/  /_/  /_/  /_/  /_/                       
                                                      
 )" << endl;
	Sleep(200);
	clear();

}

void error() // FLASHING ERROR GRAPHICS.
{
	clear();

	int ierror = 0;

	while (ierror <= 4) {

		cout << R"(                              
		 _____ ____  ____   ___  ____  
		| ____|  _ \|  _ \ / _ \|  _ \ 
		|  _| | |_) | |_) | | | | |_) |
		| |___|  _ <|  _ <| |_| |  _ < 
		|_____|_| \_|_| \_\\___/|_| \_\
                                   			                                    
 )" << endl;

		Sleep(500);
		clear();
		cout << "";
		Sleep(100);
		ierror++;

	}
}
const string currentDateTime() // PRINTS THE CURRENT TIME TO THE SCREEN.
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}

bool IsYes(std::string in) // THIS IS FOR INCASE THE USER PUTS IN ANYTHING THAT COULD MEAN YES, OTHERWISE THE PROGRAM WOULD RETURN AN ERROR AND THAT WOULD BE INCONVINIENT.
{
	ToUpper(in);
	if (in == "Y" || in == "YES") {
		return true;
	}
	return false;
}
bool IsNo(std::string in) // THIS IS THE SAME FOR NO
{
	ToUpper(in);
	if (in == "N" || in == "NO") {
		return true;
	}
	return false;
}
bool IsLoad(std::string in) // AND THE SAME FOR LOAD
{
	ToUpper(in);
	if (in == "L" || in == "LOAD") {
		return true;
	}
	return false;
}
bool IsNew(std::string in) // AND THE SAME FOR NEW
{
	ToUpper(in);
	if (in == "N" || in == "NEW") {
		return true;
	}
	return false;
}
bool IsAdd(std::string in) // AND THE SAME FOR ADD
{
	ToUpper(in);
	if (in == "A" || in == "ADD") {
		return true;
	}
	return false;
}
bool IsUpdate(std::string in) // AND THE SAME FOR UPDATE
{
	ToUpper(in);
	if (in == "U" || in == "UP") {
		return true;
	}
	return false;
}

string sInput(string prompt) // THIS KEEPS THE FORMAT FOR THE STRING OUTPUT I WANT AND SAVES A LOT OF SPACE IN THE MAIN PROGRAM. 
{
	string result;
	cout << "" << endl;
	cout << " >>>>		" << prompt << endl;
	cout << "" << endl;
	cout << " >>>>		";
	getline(cin, result); // GETLINE ALLOWS THE USER TO INPUT MORE THAN ONE WORD AT A TIME. BEFORE, WITH JUST CIN, IT IGNORED ANY WORDS AFTER THE FIRST SPACE.
	cout << "" << endl;
	ToUpper(result);

	return result;
}

double dInput(string prompt) // THIS IS THE SAME FOR DOUBLES.
{
	string result;
	cout << "" << endl;
	cout << " >>>>		" << prompt << endl;
	cout << "" << endl;
	cout << " >>>>		";
	getline(cin, result); // READS THE INPUT AS A STRING THEN...
	double resultd = stod(result, 0); // PARSES STR INTERPRETING ITS CONTENT AS A FLOATING-POINT NUMBER, WHICH IS RETURNED AS A VALUE OF TYPE DOUBLE: STOD = STRING TO DOUBLE. 
	return resultd;
}

int iInput(string prompt) // THIS IS THE SAME FOR INTEGERS.
{
	string result;
	cout << "" << endl;
	cout << " >>>>		" << prompt << endl;
	cout << "" << endl;
	cout << " >>>>		";
	getline(cin, result);
	cout << "" << endl;
	int resulti = stoi(result, 0); // STOI = STRING TO INTEGER.
	return resulti;
}

void press_any_key() // PRESS ENTER TO CONTINUE
{
	cout << "\n >>>>		Press Enter to Continue...";
	string temp;
	getline(std::cin, temp);
}

void privacy() // HAVE TO COMPLY WITH THOSE GDPR REGULATIONS....
{
	string yesno = "";
	bool breakout = true;

	// CHECK WHY THIS DOESN'T WORK BEFORE YOU BOTHER REMOVING IT 

	while (breakout = true) {
		cout << R"(

								 ____  ____  _____     ___    ______   __  ____ _____  _  _____ _____ __  __ _____ _   _ _____ 
								|  _ \|  _ \|_ _\ \   / / \  / ___\ \ / / / ___|_   _|/ \|_   _| ____|  \/  | ____| \ | |_   _|
								| |_) | |_) || | \ \ / / _ \| |    \ V /  \___ \ | | / _ \ | | |  _| | |\/| |  _| |  \| | | |  
								|  __/|  _ < | |  \ V / ___ | |___  | |    ___) || |/ ___ \| | | |___| |  | | |___| |\  | | |  
								|_|   |_| \_|___|  \_/_/   \_\____| |_|   |____/ |_/_/   \_|_| |_____|_|  |_|_____|_| \_| |_|  
                                                                                                                                         	
		THE TRACK Ltd and its related companies (referred to in this document as we, us or our) recognise that your privacy is very important and we are committed to protecting personal information we collect from you. 
		The General Data Protection Act 2018 (Privacy Act), European Union Privacy Principles and registered privacy codes govern the way in which we must mange your personal information. 
		This policy describes how we collect, use, disclose and otherwise manage personal information about you.


		1. Collection of Personal Information

		Types of information collected:

		We may collect and hold personal information about you, that is, information that can identify you, and is relevant to providing you with the services or products you are seeking. 
		This personal information may include details such as your name, age, gender, contact information,
		products and services you are interested in or require more information about. 
		If you purchase or request products and services from us we may also request your preferences for receiving further marketing or promotional material.

		The choice of how much information you provide to us is yours. 
		We seek this information either to process your request for information and provide that information to you, 
		to improve the quality of our products and services or to assist you to determine which products and services best meet your needs. 	


		2. Method of collection
	

		Personal information will generally be collected directly from you through the use of any of our standard forms, over the internet, via email, or through a telephone conversation with you. 
		We may also collect personal information about you from third parties acting on your behalf (for instance, agents).

		3. Security of your information

	
		We store your personal information in different ways, including in paper and electronic format. 
		We take reasonable steps to ensure the security of all information we collects from risks such as loss or unauthorised access, destruction, use, modification or disclosure of data. 
		For example, your personal information is maintained in a secure environment which can be accessed only by authorised personnel. 
		However, no data transmission over the internet or information stored on servers accessible through the internet can be guaranteed to be fully secure. These activities are undertaken at your risk. 

		4. Changes to this Privacy Statement

		This privacy policy may change from time to time particularly as new rules, regulations and industry codes are introduced.


		                -.            .      .-.
                     '       /      / ./
	            _  __,     .--'      / <
		      ~_-~ /     <         <   \_ .-~7
		    _. \   >      \.-'\     >`   ~ .-~
		    <  ><  /         ,  7   <      ~7		EU REGULATIONS 2018. 
		   /_/  ! \       .-L  \  _//   <'~
		   ~  .-~  !      ! /o& `' .     7
             _>_._ >  _.-' '-._.-._.--./
            '-~   ~._/                                                .'
              ,-.-'                                                .-~<
             <                                                  __/    > -'
              \                                               -~ ___--/
               7                                ..   .       /_//     \__
               !       _.-.     ..             <  ~v~       '            \
        .-~---'   .-.-~    ~\  <  \            /            |          __/
        )         >      o  <   >  \           \_.--._      |O        |    .__,--_
       /       .-'      <>   \  \   7       .  '            )        / d  . _>   /.
       7       > . - '        > _\  !   _,-' `.             \       /.._  .)    <
       ~--,.--'           ._ /.- ~` <   \ .   \              `     |<   \  `-.__/
                          7/ ~       \.,< .  ` `-~-.-~       |    /  \__//.--...<|
                                        __  . `              '-.__\\  - ' '--~|/



)" << endl;

		yesno = sInput("Are you happy to continue? [YES/NO]");

		if (IsYes(yesno)) {

			clear();
			break;

		} else if (IsNo(yesno)) {

			clear();
			cout << R"(

					 ____  ____  _____     ___    ______   __  ____ _____  _  _____ _____ __  __ _____ _   _ _____ 
					|  _ \|  _ \|_ _\ \   / / \  / ___\ \ / / / ___|_   _|/ \|_   _| ____|  \/  | ____| \ | |_   _|
					| |_) | |_) || | \ \ / / _ \| |    \ V /  \___ \ | | / _ \ | | |  _| | |\/| |  _| |  \| | | |  
					|  __/|  _ < | |  \ V / ___ | |___  | |    ___) || |/ ___ \| | | |___| |  | | |___| |\  | | |  
					|_|   |_| \_|___|  \_/_/   \_\____| |_|   |____/ |_/_/   \_|_| |_____|_|  |_|_____|_| \_| |_|  

)" << endl;
			cout << " >>>>		If you are not happy with our privacy policy or methods of data collection/storage," << endl;
			cout << " >>>>		Please contact us on: +44123456789" << endl;
			cout << " >>>>		or email: thetrack@fakeprivacypolicy.co.uk" << endl;

			press_any_key();
		}
	}

}

void MenuAdd()
{
	//new
	string sMyFirstName = "", sMyLastName = "", sMyNameStore = "";

	clear();

	cout << R"(
		 _   _ _______        __
		| \ | | ____\ \      / /
		|  \| |  _|  \ \ /\ / / 
		| |\  | |___  \ V  V /  
		|_| \_|_____|  \_/\_/   
                        
 )" << endl;

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

	double dTotalLength = 0.0; // THE MILES TRAVELLED ON THE TRACK (MILES x AMOUNT OF LAPS).
	double dMiles = 0.0; // HOW MANY MILES LONG THE TRACK IS.
	double dLap = 0; // NUMBER OF LAPS COMPLETED - HAS to be a double otherwise later on in the program, the conversion from double to int may result in a loss of data.
	string sTrack = ""; // TRACK NAME.
	string sTrackStore = ""; // TRACK'S NAME STORED. 
	double dOptimumTime = 0.0; // THE TRACK'S OPTIMUM TIME.


	sTrack = sInput("What is the name of the racetrack you drove on today?");
	sTrackStore = sTrack;
	cout << "" << endl;
	dMiles = dInput("How many miles long is " + sTrackStore + "?");

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

	double dSmallest = INT32_MAX; // THIS IS USED IN A FOR LOOP LATER TO TRY AND FIND THE FASTEST LAPTIME.

	for (auto dTime : dLapMins) {
		cout << dTime << endl;
		if (dTime < dSmallest) {
			dSmallest = dTime;
		}
	}

	clear();

	double dSum = accumulate(dLapMins.begin(), dLapMins.end(), 0.0); // TOTAL TIME SPENT DRIVING ON THE TRACK, 'ACCUMULATING' FROM THE dLapMins VECTOR.

	// Gotta use a pointer here to find out which lap the fastest laptime was methinks :)

	cout << "" << endl;
	cout << " " << endl;
	cout << " >>>>		On " << sTrackStore << " you have travelled: ";
	dTotalLength = dMiles * dLap;
	cout << dTotalLength << " miles in a time of: " << dSum << " minutes." << endl;
	cout << "" << endl;
	cout << " >>>>		The Target Lap Time for " << sTrackStore << " was " << dOptimumTime << " minutes." << endl;
	cout << "" << endl;
	cout << " >>>>		Your quickest lap was: " << dSmallest << " minutes." << endl; // Make it so you can print out which lap it was as well
	cout << "" << endl;
	if (dSmallest < dOptimumTime) {
		cout << " >>>>		CONGRATS! You beat the Target Lap Time by " << dOptimumTime - dSmallest << " minute/s :)" << endl;
		cout << "" << endl;

		//cout << " >>>>		It took you " <<  << " laps to beat the Target Time." << endl;
	} else {
		cout << " >>>>		SORRY, You didn't beat the Target Lap Time by " << dSmallest - dOptimumTime << " minute/s :(" << endl;
		cout << "" << endl;
	}
	double dAvgtime = dSum / dLap; // CREATES THE AVERAGE TIME BY DIVIDING THE SUM OF TIME BY THE SUM OF THE DISTANCE TRAVELLED.
	cout << " >>>>		In an AVERAGE time of: " << dAvgtime << " minute/s per lap." << endl;
	// SPEED = DISTANCE/TIME.
	double dSpeed = (dTotalLength * 1609.34) / (dSum * 60); // THIS IS TO WORK OUT LENGTH FROM MILES TO METRES PER SECOND, AND TIME FROM MINUTES TO SECONDS.
	cout << "" << endl;
	cout << " >>>>		At an AVERAGE speed of: " << (dSpeed / 0.44704) << " mph." << endl; // THIS OUTPUTS THE SPEED IN METRES PER SECOND SO IS DIVIDED TO OUTPUT MILES PER HOUR (1MPH = 0.44704 M/S).
	cout << "" << endl;
	string(dLap, 'O');
	cout << " >>>>		NY" << string(dLap, 'O') << "M!" << endl; // JUST WRITES NYOOM - WITH HOWEVER MANY O'S ACCORDING TO HOW MANY LAPS THE PERSON HAS DONE. JUST A BIT OF FUN.


}

void MenuLoad()
{
	string sMyFirstName = "", sMyLastName = "", sMyNameStore = "", sOption = "";
	bool bTrue = true;

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
			sOption = sInput("Is this the right person you were looking for? [YES/NO]");
			cout << "" << endl;

			// WILL EVENTUALLY OUPUT ALL (UN-EDITABLE) USER INFO HERE, THEN THE LOAD SECTION WILL BE FINISHEDDDDDD

			if (IsNo(sOption))
			{
				clear();
				error();
				cout << "" << endl;
				cout << " >>>>		It seems we can't find the person you're looking for...Try entering their details again." << endl;
				Sleep(4000);
				clear();
			}
		} else {
			error();
		}
	}
}

void MenuUpdate()
{
	string sMyFirstName = "", sMyLastName = "", sMyNameStore = "", sOption = "";
	bool bTrue = true;

	clear();

	cout << R"(
		 _   _ _______        __
		| \ | | ____\ \      / /
		|  \| |  _|  \ \ /\ / / 
		| |\  | |___  \ V  V /  
		|_| \_|_____|  \_/\_/   
                        
 )" << endl;
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
			sOption = sInput("Is this the right person you were looking for? [YES/NO]");
			cout << "" << endl;

			if (IsNo(sOption))
			{
				clear();
				error();
				cout << "" << endl;
				cout << " >>>>		It seems we can't find the person you're looking for...Try entering their details again." << endl;
				Sleep(4000);
				clear();
			}
		} else {
			error();
		}


		// DISPLAYS AN ERROR IF ANYTHING BUT L/LOAD OR N/NEW IS INPUTTED TO THE WELCOME PAGE. 

		error();
		cout << "" << endl;
		cout << " >>>>		User input not recognised..." << endl;
	}
}

void exit()
{
	clear();
	cout << R"(                                    
		  ____  ___   ___  ____  ______   _______ 
		 / ___|/ _ \ / _ \|  _ \| __ \ \ / | ____|
		| |  _| | | | | | | | | |  _ \\ V /|  _|  
		| |_| | |_| | |_| | |_| | |_) || | | |___ 
		 \____|\___/ \___/|____/|____/ |_| |_____|
                                          
)" << endl;
	Sleep(300);
	exit(1);
}