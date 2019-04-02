#pragma once
#ifndef Graphic_h_
#define Graphic_h_

#include <string>

void clear(); // CLEAR THE CONSOLE.

void loading(); // LOADING GRAPHICS.

void error(); // ERROR GRAPHICS.

const std::string currentDateTime(); // PRINTS CURRENT DATE/TIME TO THE SCREEN.

/*
Determine if the given string is an affirmative response.
Param in The string to check.
return true if affirmative, otherwise false.
*/

void privacy(); // PRIVACY STATEMENT DISPLAYED WHEN BOOTED UP

void press_any_key();

void press_any_key_to_exit();

#endif // Graphic_h_