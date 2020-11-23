#include <windows.h>
#include "main.h"
#include <stdio.h>
bool msg = false;
LRESULT CALLBACK
DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);


int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow) {
	MSG msg;

	DialogBox(hInstance,(LPCTSTR)IDD_DLGTEST,NULL,
	          (DLGPROC)DlgProc);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK
DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	HWND hwDispatch;
	char strText1[100] = "0", strText2[100] = "0", result[100];
	int res = 0;
	COPYDATASTRUCT cds;
	cds.dwData = 1;
	cds.lpData = result;
	cds.cbData = sizeof(result);
	hwDispatch=FindWindow(NULL, "Result");
	if( hwDispatch != NULL ) {
		SendMessage( hwDispatch,
		             WM_COPYDATA,
		             NULL,
		             (LPARAM) (LPVOID) &cds );
	} else {
		if(!msg)
		{
			MessageBox( NULL, "Can't send WM_COPYDATA", "MyApp", MB_OK );
			msg = true;
		}
	}

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
				case IDC_BTN1:
					GetDlgItemText(hDlg,IDC_EDIT1,strText1,100);
					GetDlgItemText(hDlg,IDC_EDIT2,strText2,100);
					res = atoi(strText1) + atoi(strText2);
					sprintf(result, "%d", res);
					SetDlgItemText(hDlg,IDC_RESULT, result);
					int n = SendMessage(hwDispatch, WM_COPYDATA, (WPARAM) (HWND) hDlg, (LPARAM)&cds);
					sprintf(result, "%d", n);
					MessageBox( NULL, (LPCSTR) result, "MyApp", MB_OK );
					break;
			}
			break;
		default:
			return FALSE;
	}
}


