#ifndef Initialise_h_
#define Initialise_h_

//Stores: Driver name, Driver password, Driver ID
//#define TimeData "thetracktimedata.txt" // INPUT STORAGE FOR THE TRACK.
//Stores: Driver ID, Track ID, Date, Lap times, Laps
//#define TrackData "thetracktrackdata.txt" // INPUT STORAGE FOR THE TIMES.
//Stores: Track ID, Track name, Track data
#ifdef _MSC_VER
#endif
#include <iostream>
#include <chrono>
#include "pch.h"
#include <cstdio>
#include <cctype>
#include <iostream>
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
#include "Input.h"
#include "IsFunction.h"
#include "Menu.h"
#include "Graphic.h"

using namespace std;

#endif // Initialise_h_