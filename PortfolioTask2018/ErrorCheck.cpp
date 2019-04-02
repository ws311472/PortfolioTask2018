#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "ErrorCheck.h"

using namespace std;

bool ErrorCheckNum(string sLine)
{
	bool bError = false;

	if (any_of(sLine.begin(), sLine.end(), isdigit))
	{
		cout << "\nError! That is not an acceptable input. Try again." << endl;
		bError = true;
	}

	return bError;
}

bool ErrorCheckChar(string sLine, int * iResult)
{
	if (any_of(sLine.begin(), sLine.end(), isalpha) || any_of(sLine.begin(), sLine.end(), isspace))
	{
		cout << "\nError! That is not an acceptable input. Try again." << endl;
		return true;
	}

	*iResult = stoi(sLine);

	return false;
}