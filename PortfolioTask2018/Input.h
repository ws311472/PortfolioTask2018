#pragma once
#ifndef Input_h_
#define Input_h_

#include <iostream>
#include <string>

std::string sInput(std::string prompt); // STRING INPUT/OUTPUT FORMAT.

double dInput(std::string prompt); // DOUBLE INPUT/OUTPUT FORMAT.

int iInput(std::string prompt); // INTEGER INPUT/OUTPUT FORMAT.

void ToUpper(std::string& string_data);

#endif // Input_h_