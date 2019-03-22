#include "DebugUtilitary.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;
namespace duc
{
    SignalHandlers::SignalHandlers()
    {
        this->backtraceFname="mem_trace.dat";
    }
    SignalHandlers::~SignalHandlers()
    {

    }
    void SignalHandlers::setBacktraceFname(char *name)
    {
        this->backtraceFname = name;
    }
    char *SignalHandlers::getBacktraceFname()
    {
        return this->backtraceFname;
    }
    void SignalHandlers::invalidMemoryAccessSignal(int signal)
    {
        fprintf(stderr, "Memory error %d, initiating backtrace into file: %s\n", signal, this->getBacktraceFname());
    }
}
