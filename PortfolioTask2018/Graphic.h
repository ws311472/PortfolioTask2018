#pragma once
#include "Initialise.h"

void ToUpper(const std::string& string_data);

void clear(); // CLEAR THE CONSOLE.

void loading(); // LOADING GRAPHICS.

void error(); // ERROR GRAPHICS.

const string currentDateTime(); // PRINTS CURRENT DATE/TIME TO THE SCREEN.

/**
* Determine if the given string is an affirmative response.
* @param in The string to check.
* @return true if affirmative, otherwise false.
*/

void privacy(); // PRIVACY STATEMENT DISPLAYED WHEN BOOTED UP

void press_any_key();