/*
 ============================================================================
 Name        : practice.c
 Author      : tony
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#define UNICODE
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int WINAPI main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdline, int nCmdshow) {

	MessageBox(NULL, TEXT("确认"), TEXT("对话框"), MB_OK);

	return EXIT_SUCCESS;
}



