#include <stdio.h>
#include <string.h>

#define STN_USE_INTRIN
#define STN_USE_STRING
#define STN_USE_MEMORY
#include "stn.h"


#ifdef BUILD_WIN32
    #pragma comment(lib, "uuid.lib ")
    #pragma comment(lib, "ole32.lib")
    #pragma comment(lib, "oleaut32.lib")
    #pragma comment(lib, "oledlg.lib")

    #include <Windows.h>

    #include "ext/win32/VirtualBox/VirtualBox_i.c"
    #include "ext/win32/VirtualBox/VirtualBox.h"
#endif




int
main(int ArgumentCount, char **Arguments)
{
    /* Initialize the COM subsystem. */
    CoInitialize(NULL);



    return 0;
}