#include "Initialise.h"

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
