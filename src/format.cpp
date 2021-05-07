#include <string>

#include "format.h"

using std::string;
using std::to_string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS 
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
	int HH = seconds / 3600;
	int MM = ((seconds / 3600.0) - (HH)) * 60;
	int SS = ((((seconds / 3600.0) - (HH)) * 60) - MM) * 60;
	string hh = (to_string(HH) == "0") ? "00" : to_string(HH);
  	string mm = (to_string(MM) == "0") ? "00" : to_string(MM);
	string ss = (to_string(SS) == "0") ? "00" : to_string(SS);
  	return hh + ":" + mm + ":" + ss;
}