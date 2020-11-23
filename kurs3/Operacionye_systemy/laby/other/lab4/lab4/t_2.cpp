#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <winuser.h>

using namespace std;

LRESULT CALLBACK MyWndProc(HWND, UINT, WPARAM, LPARAM);
HDC hdc;
RECT rt;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    HWND hWnd;
    MSG msg;
    WNDCLASS wc;
    LPCWSTR lpszAppName = L"CTemplate1";
    COPYDATASTRUCT data;
    char str[80];

    wc.lpszClassName = lpszAppName;
    wc.hInstance = hInstance;
    wc.lpfnWndProc = (WNDPROC)MyWndProc;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = 0;
    wc.lpszMenuName = 0;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);

    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;

    if(!RegisterClass(&wc)) return 0;

    hWnd = CreateWindow(lpszAppName, lpszAppName, WS_OVERLAPPEDWINDOW, 100, 100, 400, 200, NULL, NULL, hInstance, NULL);

    ShowWindow(hWnd, SW_SHOWNORMAL);

    UpdateWindow(hWnd);

    while (GetMessage(&msg, nullptr, 0, 0))
    {
       // do
       // {
            cin >> str;
            data.cbData = strlen(str);
            data.lpData = str;
            SendMessageA(hWnd, WM_COPYDATA, NULL, (LPARAM)&data);
        //} while(strcmp(str, "start"));
            getdlg
    }



    return msg.wParam;
}

LRESULT CALLBACK
MyWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;

    switch (message)
    {
        case WM_DESTROY: PostQuitMessage(0); break;
        case WM_HOTKEY: ShowWindow(hWnd,SW_SHOWNORMAL); break;

        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);
            GetClientRect(hWnd, &rt);
            DrawTextA(hdc, "From Paint", strlen("From Paint"), &rt, DT_CENTER);
            EndPaint(hWnd, &ps);
            break;

        case WM_COPYDATA:
            GetClientRect(hWnd, &rt);
            hdc =GetDC(hWnd);
            DrawTextA(hdc, (char*)(((COPYDATASTRUCT*)lParam)->lpData), ((COPYDATASTRUCT*)lParam)->cbData, &rt, DT_LEFT);
            ReleaseDC(hWnd,hdc);
            break;

        default: return DefWindowProc(hWnd, message, wParam, lParam);
    }
}
/*
int main()
{
    HWND hWnd;
    COPYDATASTRUCT data;
    char str[80];
    hWnd = FindWindowA("CTemplate1", "CTemplate1");

    ShowWindow(hWnd, SW_SHOWNORMAL);
    do
    {
        cin >> str;
        data.cbData = strlen(str);
        data.lpData = str;
        SendMessageA(hWnd, WM_COPYDATA, (WPARAM)GetFocus(),
        (LPARAM)&data);
    } while(strcmp(str, "quit"));

    return 0;
}
/*
#include <windows.h>
#include <process.h>

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
     char* argv[]={ "notepad", NULL };
     _spawnvp(_P_NOWAIT, argv[0],argv);

     MessageBoxA(NULL, "Parent process is yet running.", "Message", MB_OK);

     HWND head;
     CreateDialogA(NULL, "Calculator", NULL, NULL);



     return 0;
}
*/
