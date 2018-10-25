//FUNCTION DECLARATIONS & Macros

#define DriverData "thetrackdriverdata.txt"
//Stores: Driver name, Driver password, Driver ID
#define TimeData "thetracktimedata.txt"
//Stores: Driver ID, Track ID, Date, Lap times, Laps
#define TrackData "thetracktrackdata.txt"
//Stores: Track ID, Track name, Track data
#ifdef _MSC_VER
#endif
#define ToUpper(string_data) transform(string_data.begin(), string_data.end(), string_data.begin(), ::toupper)

using namespace std; 

void gotoxy(int x, int y);

void clear();

void loading();

void error();

const string currentDateTime(); 

bool IsYes(string in);

bool IsNo(string in);

bool IsLoad(string in);

bool IsNew(string in);

string sInput(string prompt);

float fInput(string prompt);

int iInput(string prompt);

