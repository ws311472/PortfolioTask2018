#pragma once
#include <cstdio>
#include <iostream>
//Just because I prefer using elif (plus it's quicker)
#define elif else if 
#ifdef _MSC_VER
#endif
#define ToUpper(string_data) transform(string_data.begin(), string_data.end(), string_data.begin(), ::toupper);
using namespace std; 

void gotoxy(int x, int y) //Writes over the existing material in the console. Only works if the one that is on the console next is larger than the one before it.
{
	COORD topLeft = { x, y };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(console, topLeft);
}

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

void loading() //Loading graphics function
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
	gotoxy(0, 0);
	cout << R"(
		 _     ___    _    ____ ___ _   _  ____   ____    _  _____  _      __  
		| |   / _ \  / \  |  _ |_ _| \ | |/ ___| |  _ \  / \|_   _|/ \     \ \ 
		| |  | | | |/ _ \ | | | | ||  \| | |  _  | | | |/ _ \ | | / _ \     \ \
		| |__| |_| / ___ \| |_| | || |\  | |_| | | |_| / ___ \| |/ ___ \    / /
		|_____\___/_/   \_|____|___|_| \_|\____| |____/_/   \_|_/_/   \_\  /_/ 
                                                                                       
 )" << endl;
	Sleep(200);
	gotoxy(0, 0);
	cout << R"(
		 _     ___    _    ____ ___ _   _  ____   ____    _  _____  _      __   __  
		| |   / _ \  / \  |  _ |_ _| \ | |/ ___| |  _ \  / \|_   _|/ \     \ \  \ \ 
		| |  | | | |/ _ \ | | | | ||  \| | |  _  | | | |/ _ \ | | / _ \     \ \  \ \
		| |__| |_| / ___ \| |_| | || |\  | |_| | | |_| / ___ \| |/ ___ \    / /  / /
		|_____\___/_/   \_|____|___|_| \_|\____| |____/_/   \_|_/_/   \_\  /_/  /_/ 
                                                                                                                                                                
 )" << endl;
	Sleep(200);
	gotoxy(0, 0);
	cout << R"(                                                                                 
		 _     ___    _    ____ ___ _   _  ____   ____    _  _____  _      __   __   __  
		| |   / _ \  / \  |  _ |_ _| \ | |/ ___| |  _ \  / \|_   _|/ \     \ \  \ \  \ \ 
		| |  | | | |/ _ \ | | | | ||  \| | |  _  | | | |/ _ \ | | / _ \     \ \  \ \  \ \
		| |__| |_| / ___ \| |_| | || |\  | |_| | | |_| / ___ \| |/ ___ \    / /  / /  / /
		|_____\___/_/   \_|____|___|_| \_|\____| |____/_/   \_|_/_/   \_\  /_/  /_/  /_/                                                                               
                                                                                                                                                                
 )" << endl;
	Sleep(200);
	gotoxy(0, 0);
	cout << R"(                                                                          
		 _     ___    _    ____ ___ _   _  ____   ____    _  _____  _      __   __   __   __  
		| |   / _ \  / \  |  _ |_ _| \ | |/ ___| |  _ \  / \|_   _|/ \     \ \  \ \  \ \  \ \ 
		| |  | | | |/ _ \ | | | | ||  \| | |  _  | | | |/ _ \ | | / _ \     \ \  \ \  \ \  \ \
		| |__| |_| / ___ \| |_| | || |\  | |_| | | |_| / ___ \| |/ ___ \    / /  / /  / /  / /
		|_____\___/_/   \_|____|___|_| \_|\____| |____/_/   \_|_/_/   \_\  /_/  /_/  /_/  /_/ 
                                                                                                                                                          
 )" << endl;
	Sleep(200);
	system("CLS");
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

void error()
{
	clear();

	int ierror = 0;

	while (ierror <= 4) {

		std::cout << R"(                              
		 _____ ____  ____   ___  ____  
		| ____|  _ \|  _ \ / _ \|  _ \ 
		|  _| | |_) | |_) | | | | |_) |
		| |___|  _ <|  _ <| |_| |  _ < 
		|_____|_| \_|_| \_\\___/|_| \_\
                                   			                                    
 )" << endl;

		Sleep(500);
		clear();
		std::cout << "";
		Sleep(100);
		ierror++;

	}
}
const string currentDateTime() //Function so that I can call the current time.
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
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
