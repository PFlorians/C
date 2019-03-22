#ifndef DEBUGUTILITARY_H
#define DEBUGUTILITARY_H
#include <stdexcept>
#include <csetjmp>
#include <csignal>
using namespace std;
#define TRY do { jmp_buf __buff; switch(setjmp(__buff)){case 0:
#define CATCH(x) break; case x:
#define THROW(x) longjmp(__buff, x)
#define YRT } }while(0)

//debug utilitary classes = due
namespace duc
{
    class SignalHandlers
    {
        public:
            SignalHandlers();
            virtual ~SignalHandlers();
            void terminationSignal(int signal);
            void invalidMemoryAccessSignal(int signal);
            void interruptSignal(int signal);
            void invalidInstructionSignal(int signal); //code corruption errors
            void abortSignal(int signal);
            void arithmethicErrorSignal(int signal);
            void setBacktraceFname(char *name);
            char *getBacktraceFname();
        private:
            char *backtraceFname;
    };
}

#endif // DEBUGUTILITARY_H
