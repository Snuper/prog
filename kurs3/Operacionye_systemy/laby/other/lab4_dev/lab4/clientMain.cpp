#include <windows.h>
#include "resource.h"
#include <stdio.h>

LRESULT CALLBACK
DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);


int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow) {
	MSG msg;

	DialogBox(hInstance,(LPCTSTR)IDD_DLG, NULL,
	          (DLGPROC)DlgProc);
		
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK
DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	PCOPYDATASTRUCT pMyCDS;
	char request[100];
	switch (message) {
		case WM_INITDIALOG:
			return TRUE;
		case WM_COMMAND:
			switch (LOWORD(wParam) ) {
				case IDOK:
					PostQuitMessage(0);
					return TRUE;
				case IDCANCEL:
					PostQuitMessage(0);
					return TRUE;
				case WM_COPYDATA:
					if(!(pMyCDS = (PCOPYDATASTRUCT) lParam))
      					MessageBox( NULL, "Can't send WM_COPYDATA", "MyApp", MB_OK );
					printf("OK");
					strncpy(request,(char*)pMyCDS->lpData,pMyCDS->cbData);
					SetDlgItemText(hDlg,IDC_RESULT,request);
					break;
			}
			break;
		default:
			return FALSE;
	}
}


