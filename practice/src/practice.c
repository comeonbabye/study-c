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

#include "Dialog.h"

int WINAPI main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdline, int nCmdshow) {

	popupDialog();

	return EXIT_SUCCESS;
}



