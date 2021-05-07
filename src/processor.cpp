#include "processor.h"
#include <string>
#include "linux_parser.h"

using namespace std;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { 
  return LinuxParser::ActiveJiffies() * (1.f / LinuxParser::Jiffies());
 }