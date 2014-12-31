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

int main(void) {

	char buf[80];
	getcwd(buf, sizeof(buf)); //获得当前路径
	char* path = strcat(buf, "\\test.txt");

	//处理路径里面的斜杠
	int i, len = strlen(path);
	printf("长度:%d\n", len);
	for(i=0;i<len;i++) {
		if(path[i] == '\\') {
			path[i] = '/';
		}
	}

	printf(path);
	printf("\n");

	FILE *file;

	if((file = fopen(path, "rt")) == NULL) {
		printf("文件不存在");
		exit(1);
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

	return 1;
}

