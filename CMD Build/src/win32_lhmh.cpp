#include <windows.h>

//handle to window, message, 
LRESULT CALLBACK mainWindowCallback( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

    LRESULT result = 0;
    switch(uMsg){

        //window size changed
        case WM_SIZE:{
            OutputDebugStringA("WM_SIZE\n");
        }break;

        //window deletes window
        case WM_DESTROY:{
            OutputDebugStringA("WM_DESTROY\n");
                
        }break;

        //window instructed to close
        case WM_CLOSE:{
            OutputDebugStringA("WM_CLOSE\n");
                
        }break;

        //user has clicked to focus the window
        case WM_ACTIVATEAPP:{
            OutputDebugStringA("WM_ACTIVATEAPP\n");
                
        }break;
        
        default:{
           // OutputDebugStringA("Default\n");

            result = DefWindowProc(hwnd, uMsg, wParam, lParam);//defualt window callback handler for actions we dont handle
        }break;

    }
    return result;

}

//C runtime lib entry point
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,int nShowCmd) {
    OutputDebugStringA("App start\n");
    WNDCLASS windowClass = {};
    windowClass.style = CS_OWNDC | CS_VREDRAW | CS_HREDRAW; //allocates a unique device context for each window in the class
    windowClass.lpfnWndProc =  mainWindowCallback;
    windowClass.hInstance = hInstance;
    //windowClass.hIcon = ;
    windowClass.lpszClassName = "LHMHWindowClass";
    return(0);
}

