/*
 * Dialog.c
 *
 *  Created on: 2015-1-3
 *      Author: tony
 */

#include <windows.h>
#include <tchar.h>

#include "Dialog.h"


static const char *msg[] = {
    "整你没商量..",
    "整你没商量.."
    //可以写很多
};


void popupDialog() {

	MessageBox(NULL, TEXT("确认"), TEXT("对话框"), MB_OK);

	/*MessageBox(NULL, TEXT("你好"), "HeHeHeHe", MB_YESNOCANCEL);
	MessageBox(NULL, TEXT(msg[1]), "HeHeHeHe", MB_ABORTRETRYIGNORE);
	MessageBoxA(NULL, TEXT("你好"), TEXT("HeHeHeHe"), MB_ICONINFORMATION);*/

}


/*int WINAPI WinMain(
HINSTANCE hInstance,
HINSTANCE hPrevInstance,
LPSTR lpCmdline,
int nCmdshow
)
{
MessageBox(NULL,TEXT("确认"),TEXT("对话框"),MB_OK);
return 0;
}*/
