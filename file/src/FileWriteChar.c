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
#include <time.h>


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

	clock_t start, finish;

	start = clock();

	////////////////////开始写文件////////////////////////////
	char* str = "hello tony.\n";
	int i, j, len = strlen(str);
	for(j=0; j<10000; j++) {
		for(i=0; i<len; i++) {
			fputc(str[i], fp);
			//fputs(str, fp);//经过这个简单的测试发现fputs比fputc慢了5倍的时间
			//fprintf(fp, "%s", str);// 经过这个简单的测试发现fprintf比fputc慢了8倍的时间
		}
	}

	finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;

	printf("写入文件耗时：%f", (duration));

	fclose(fp);

}


