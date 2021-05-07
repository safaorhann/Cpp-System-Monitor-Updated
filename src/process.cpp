#include <unistd.h>
#include <cctype>
#include <sstream>
#include <dirent.h>
#include <string>
#include <vector>
#include <fstream>
#include "linux_parser.h"
#include "process.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int id) : pid(id) {}

// TODO: Return this process's ID
int Process::Pid() { return pid; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() const { 
    string line;
	string str;
  	string utime, stime, cutime, cstime, starttime;
  	std::ifstream filestream(LinuxParser::kProcDirectory + to_string(pid) + LinuxParser::kStatFilename);
  	if (filestream.is_open()) {
        std::getline(filestream, line);
    	std::stringstream linestream(line);
    	int count = 0 ;
    	while (std::getline(linestream, str, ' ')) { count++; if (count == 13) break; }
      	linestream >> utime >> stime >> cutime >> cstime; //starttime
      	count = 0;
      	while(linestream >> str){count++; if(count == 4) break;}
      	linestream >> starttime;
      	float total = stof(utime) + stof(stime);
      	total = total + stof(cutime) + stof(cstime);
      	float seconds = LinuxParser::UpTime() - (stof(starttime) / (float)sysconf(_SC_CLK_TCK));
		    float cpu = 100 * ((total / sysconf(_SC_CLK_TCK)) / seconds);
        return cpu;
    }
}

// TODO: Return the command that generated this process
string Process::Command() { return LinuxParser::Command(pid); }

// TODO: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(pid); }

// TODO: Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(pid); }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(pid); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { 
    return (CpuUtilization() > a.CpuUtilization()) ? true : false;
}