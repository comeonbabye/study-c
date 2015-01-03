/*
 * WriteFile.c
 *
 *  Created on: 2014-12-31
 *      Author: tony
 */

#include <stdio.h>
#include <stdlib.h>  //exit声明
#include <string.h>
#include <unistd.h>  //getcwd声明


#include "FileWriteChar.h"
#include "FileExsits.h"

void testFileWriteChar() {

	FILE *fp;

	/////////////////////获取路径//////////////////////
	char buf[80];
	if(isFileExsits2("\\resource\\FileWriteChar\\test.txt", buf, sizeof(buf)) == 0) {

		printf("\n只写模式打开文件");
		fp = fopen(buf, "w");

	} else {
		printf("追加模式打开文件");
		fp = fopen(buf, "a");
	}


	////////////////////开始写文件////////////////////////////
	char* str = "hello tony.\n";
	int i, len = strlen(str);
	for(i=0; i<len; i++) {
		fputc(str[i], fp);
	}

	fclose(fp);

}


