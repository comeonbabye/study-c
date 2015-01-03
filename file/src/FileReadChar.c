/*
 * FileRead.c
 *
 *  Created on: 2014-12-30
 *      Author: tony
 */

#include "stdio.h"
#include <stdlib.h>  //exit声明
#include <string.h>
#include <unistd.h>  //getcwd声明
#include "FileReadChar.h"
#include "./module/common/h/Common.h"

void testFileReadChar() {

	char buf[80];
	if(getPath("\\resource\\FileReadChar\\test.txt", buf, sizeof(buf)) == 0) {
		return;
	}

	printf(buf);
	printf("\n");

	FILE *file;

	if((file = fopen(buf, "rt")) == NULL) {
		printf("文件不存在");
		return;
	}

	char ch;

	ch = fgetc(file);

	while(ch != EOF) { //如果没有读取到文件末尾，则继续读取和打印字符
		printf("%c",ch);
		ch = fgetc(file);
	}

	printf("\n");

	if(fclose(file) == EOF) {
		printf("关闭文件失败！");
	} else {
		printf("关闭文件成功！");
	}

}

