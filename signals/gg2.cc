#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

class Wibble {
    static Wibble *instance;
    public:
        Wibble() { instance = this; }
        ~Wibble() { instance = NULL; }

        static Wibble *getInstance() { return instance; }
        //void run();
};

class mgr{
    public:
        mgr() {};
        int ia;
        double da;
        static void signal_handler(int sign);
        void run();
        void build(mgr*);
    //private:
        static double test;
        static mgr* _ptr;
};

void mgr::build(mgr* ObjPtr){
    //_ptr = ObjPtr;
    da = 1.1;
}

// Define the function to be called when ctrl-c (SIGINT) signal is sent to process
void
mgr::signal_handler(int signum)
{
    //printf(" --> so you want me to die? (ia,da): (%d, %g)\n", ia, da);
    printf("Caught signal %d\n",signum);
    // Cleanup and close up stuff here

    // Terminate program
    exit(signum);
}

void 
mgr::run(){
    //signal(SIGTERM, signal_handler);
    ia = 0;
    while(1)
    {
        ia++;
        printf("Program processing stuff here; ia=%d\n", ia);
        sleep(1);
    }
}

double mgr::test = 0;
mgr* mgr::_ptr = NULL; // dummy value

int main()
{
    mgr m;
    printf(" sigint  : %d\n", SIGINT);           // ctrl+c
    printf(" sigterm : %d\n", SIGTERM);          // default of "kill" command
    printf(" sigkill : %d\n", SIGKILL);          // CAN NOT be handled
    // Register signal and signal handler
    
    void *sh;
    //*sh = &mgr::signal_handler;
    //signal(SIGTERM, mgr::signal_handler);
    //*(m._ptr) = 45.6;
    mgr::test = 45.6;
    mgr::_ptr = &m;
    printf(" ---> %p\n", &m);
    printf(" ---> %p\n", mgr::_ptr);
    printf(" ---> %p\n", m._ptr);

    mgr m2;
    printf(" ---> %p\n", m2._ptr);

    m.run();
    //Wibble w;

    return EXIT_SUCCESS;
}
