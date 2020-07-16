#include <windows.h>


//C runtime lib entry point
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,int nShowCmd) {
    MessageBox(0, "Sup dilligent", "Dilligence", MB_OK | MB_ICONINFORMATION);
    return(0);
}
