char programName[] = "Boa 1.0";
#include "Definicje.h"

#include <windows.h>
#include <mmsystem.h>


#include "Bledy.h"

// deklaracje funkcji
bool CreateMainWindow(HINSTANCE hThisInstance);

// zmienne globalne

int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nFunsterStil)
{
    if(!CreateMainWindow(hThisInstance))
    {
        return 0;
    }
    return 0;
}

#include "MainWindow.h"
