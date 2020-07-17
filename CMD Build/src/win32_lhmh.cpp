#include <windows.h>
#define internal static 
#define local_persist static 
#define global_variable static

global_variable bool running = true;

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
            running = false;
            OutputDebugStringA("WM_DESTROY\n");
                
        }break;

        //window instructed to close
        case WM_CLOSE:{
            running = false;
            OutputDebugStringA("WM_CLOSE\n");
                
        }break;

        //user has clicked to focus the window
        case WM_ACTIVATEAPP:{
            OutputDebugStringA("WM_ACTIVATEAPP\n");
                
        }break;
		
		//paint area of window with solid color
		case WM_PAINT: {
			OutputDebugStringA("WM_PAINT\n");

            PAINTSTRUCT paint;
            HDC deviceContext = BeginPaint(hwnd, &paint);
            
            PatBlt(deviceContext, paint.rcPaint.left, paint.rcPaint.top, paint.rcPaint.right - paint.rcPaint.left, paint.rcPaint.bottom - paint.rcPaint.top, BLACKNESS);
            EndPaint(hwnd, &paint);
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


    if(RegisterClass(&windowClass)){
        HWND windowHandle = CreateWindowEx(0, windowClass.lpszClassName, "LHMH", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, hInstance, 0);
        if(windowHandle){
            MSG message;
            while(running){
                BOOL msgResult = GetMessage(&message, 0, 0, 0);
                if(msgResult > 0){
                    TranslateMessage(&message);
                    DispatchMessage(&message);
                }else{
                    break;
                }
            }
        }else{
            OutputDebugStringA("WINDOW HANDLE FAILED LMAOO");
        }
    }

    return(0);
}

