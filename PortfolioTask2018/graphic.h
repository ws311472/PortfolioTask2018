//FUNCTION DECLARATIONS & Macros

#define DriverData "thetrackdriverdata.txt" // INPUT STORAGE FOR THE DRIVER.
//Stores: Driver name, Driver password, Driver ID
#define TimeData "thetracktimedata.txt" // INPUT STORAGE FOR THE TRACK.
//Stores: Driver ID, Track ID, Date, Lap times, Laps
#define TrackData "thetracktrackdata.txt" // INPUT STORAGE FOR THE TIMES.
//Stores: Track ID, Track name, Track data
#ifdef _MSC_VER
#endif
#define ToUpper(string_data) transform(string_data.begin(), string_data.end(), string_data.begin()) // CONVERTS STRINGS TO UPPERCASE FOR RE-READING CONVINIENCE. 

// SEE Functions.cpp FOR FULL FUNCTION IMPLEMENTATION & DESCRIPTIONS.

using namespace std; 
 
void clear(); // CLEAR THE CONSOLE.

void loading(); // LOADING GRAPHICS.

void error(); // ERROR GRAPHICS.

const string currentDateTime(); // PRINTS CURRENT DATE/TIME TO THE SCREEN.

bool IsYes(string in); // PARAMETERS FOR YES INPUT.

bool IsNo(string in); // PARAMETERS FOR NO INPUT.

bool IsLoad(string in); // PARAMETERS FOR LOAD INPUT.

bool IsNew(string in); // PARAMETERS FOR NEW INPUT.

bool IsAdd(string in); // PARAMETERS FOR ADD INPUT.

bool IsUpdate(string in); // PARAMETERS FOR UPDATE INPUT.

string sInput(string prompt); // STRING INPUT/OUTPUT FORMAT.

double dInput(string prompt); // DOUBLE INPUT/OUTPUT FORMAT.

int iInput(string prompt); // INTEGER INPUT/OUTPUT FORMAT.

void privacy(); // PRIVACY STATEMENT DISPLAYED WHEN BOOTED UP

