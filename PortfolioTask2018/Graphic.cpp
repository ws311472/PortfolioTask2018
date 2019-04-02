#include "pch.h"
#include "windows.h"
#include <string>
#include <iostream>
#include <chrono>
#include "IsFunction.h"
#include "Input.h"

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

	std::cout << R"(
		 _     ___    _    ____ ___ _   _  ____   ____    _  _____  _      
		| |   / _ \  / \  |  _ |_ _| \ | |/ ___| |  _ \  / \|_   _|/ \     
		| |  | | | |/ _ \ | | | | ||  \| | |  _  | | | |/ _ \ | | / _ \    
		| |__| |_| / ___ \| |_| | || |\  | |_| | | |_| / ___ \| |/ ___ \   
		|_____\___/_/   \_|____|___|_| \_|\____| |____/_/   \_|_/_/   \_\                   
 )" << std::endl;
	Sleep(200);
	clear();
	std::cout << R"(
		 _     ___    _    ____ ___ _   _  ____   ____    _  _____  _      __  
		| |   / _ \  / \  |  _ |_ _| \ | |/ ___| |  _ \  / \|_   _|/ \     \ \ 
		| |  | | | |/ _ \ | | | | ||  \| | |  _  | | | |/ _ \ | | / _ \     \ \
		| |__| |_| / ___ \| |_| | || |\  | |_| | | |_| / ___ \| |/ ___ \    / /
		|_____\___/_/   \_|____|___|_| \_|\____| |____/_/   \_|_/_/   \_\  /_/ 
                                                                                       
 )" << std::endl;
	Sleep(200);
	clear();
	std::cout << R"(
		 _     ___    _    ____ ___ _   _  ____   ____    _  _____  _      __   __  
		| |   / _ \  / \  |  _ |_ _| \ | |/ ___| |  _ \  / \|_   _|/ \     \ \  \ \ 
		| |  | | | |/ _ \ | | | | ||  \| | |  _  | | | |/ _ \ | | / _ \     \ \  \ \
		| |__| |_| / ___ \| |_| | || |\  | |_| | | |_| / ___ \| |/ ___ \    / /  / /
		|_____\___/_/   \_|____|___|_| \_|\____| |____/_/   \_|_/_/   \_\  /_/  /_/ 
                                                                                                                                                                
 )" << std::endl;
	Sleep(200);
	clear();
	std::cout << R"(                                                                                 
		 _     ___    _    ____ ___ _   _  ____   ____    _  _____  _      __   __   __  
		| |   / _ \  / \  |  _ |_ _| \ | |/ ___| |  _ \  / \|_   _|/ \     \ \  \ \  \ \ 
		| |  | | | |/ _ \ | | | | ||  \| | |  _  | | | |/ _ \ | | / _ \     \ \  \ \  \ \
		| |__| |_| / ___ \| |_| | || |\  | |_| | | |_| / ___ \| |/ ___ \    / /  / /  / /
		|_____\___/_/   \_|____|___|_| \_|\____| |____/_/   \_|_/_/   \_\  /_/  /_/  /_/                                                                               
                                                                                                                                                                
 )" << std::endl;
	Sleep(200);
	clear();
	std::cout << R"(                                                                          
		 _     ___    _    ____ ___ _   _  ____   ____    _  _____  _      __   __   __   __  
		| |   / _ \  / \  |  _ |_ _| \ | |/ ___| |  _ \  / \|_   _|/ \     \ \  \ \  \ \  \ \ 
		| |  | | | |/ _ \ | | | | ||  \| | |  _  | | | |/ _ \ | | / _ \     \ \  \ \  \ \  \ \
		| |__| |_| / ___ \| |_| | || |\  | |_| | | |_| / ___ \| |/ ___ \    / /  / /  / /  / /
		|_____\___/_/   \_|____|___|_| \_|\____| |____/_/   \_|_/_/   \_\  /_/  /_/  /_/  /_/ 
                                                                                                                                                          
 )" << std::endl;
	Sleep(200);
	clear();
	std::cout << R"(                                                                                                                 
		 _     ___    _    ____ ___ _   _  ____   ____    _  _____  _      __   __   __   __   __  
		| |   / _ \  / \  |  _ |_ _| \ | |/ ___| |  _ \  / \|_   _|/ \     \ \  \ \  \ \  \ \  \ \ 
		| |  | | | |/ _ \ | | | | ||  \| | |  _  | | | |/ _ \ | | / _ \     \ \  \ \  \ \  \ \  \ \
		| |__| |_| / ___ \| |_| | || |\  | |_| | | |_| / ___ \| |/ ___ \    / /  / /  / /  / /  / /
		|_____\___/_/   \_|____|___|_| \_|\____| |____/_/   \_|_/_/   \_\  /_/  /_/  /_/  /_/  /_/                       
                                                      
 )" << std::endl;
	Sleep(200);
	clear();

}

void error() // FLASHING ERROR GRAPHICS.
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
                                   			                                    
 )" << std::endl;

		Sleep(500);
		clear();
		std::cout << "";
		Sleep(100);
		ierror++;

	}
}
const std::string currentDateTime() // PRINTS THE CURRENT TIME TO THE SCREEN.
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}

void press_any_key() // PRESS ENTER TO CONTINUE
{
	std::cout << "\n >>>>		Press Enter to Continue...";
	std::string temp;
	std::getline(std::cin, temp);
}

void privacy() // HAVE TO COMPLY WITH THOSE GDPR REGULATIONS....
{
	std::string yesno = " ";
	bool breakout = true;

	// CHECK WHY THIS DOESN'T WORK BEFORE YOU BOTHER REMOVING IT 

	while (breakout = true) {
		std::cout << R"(

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



)" << std::endl;

		yesno = sInput("Are you happy to continue? [YES/NO]");

		if (IsYes(yesno)) {

			clear();
			break;

		} else if (IsNo(yesno)) {

			clear();
			std::cout << R"(

					 ____  ____  _____     ___    ______   __  ____ _____  _  _____ _____ __  __ _____ _   _ _____ 
					|  _ \|  _ \|_ _\ \   / / \  / ___\ \ / / / ___|_   _|/ \|_   _| ____|  \/  | ____| \ | |_   _|
					| |_) | |_) || | \ \ / / _ \| |    \ V /  \___ \ | | / _ \ | | |  _| | |\/| |  _| |  \| | | |  
					|  __/|  _ < | |  \ V / ___ | |___  | |    ___) || |/ ___ \| | | |___| |  | | |___| |\  | | |  
					|_|   |_| \_|___|  \_/_/   \_\____| |_|   |____/ |_/_/   \_|_| |_____|_|  |_|_____|_| \_| |_|  

)" << std::endl;
			std::cout << " >>>>		If you are not happy with our privacy policy or methods of data collection/storage," << std::endl;
			std::cout << " >>>>		Please contact us on: +44123456789" << std::endl;
			std::cout << " >>>>		or email: thetrack@fakeprivacypolicy.co.uk" << std::endl;

			press_any_key();
		}
	}

}

