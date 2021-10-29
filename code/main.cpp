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

#include "platform.h"

#ifdef BUILD_WIN32
    #include "win32/win32_jobbuilder.cpp"
#endif


STN_INTERNAL void
InitializePlatform(platform *Platform)
{
#ifdef BUILD_WIN32
    Platform->InitVirtualBox = Win32InitializeVirtualBox;
    Platform->ListVirtualMachines = Win32ListVirtualMachines;
#endif
}

int
main(int ArgumentCount, char **Arguments)
{
    /* Initialize the COM subsystem. */
    CoInitialize(NULL);

    platform Platform = {};
    InitializePlatform(&Platform);

    platform_vbox_client VBoxData = Platform.InitVirtualBox();
    Platform.ListVirtualMachines(VBoxData.VBox);


    return 0;
}