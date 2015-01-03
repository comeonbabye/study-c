/*
 * Common.c
 *
 *  Created on: 2015-1-1
 *      Author: tony
 */

#include "stdio.h"
#include <stdlib.h>  //exit声明
#include <string.h>
#include <unistd.h>  //getcwd声明

#include "../h/Common.h"


/**
 * 获取文件完整路径，传递相对路径，最后根据工程目录得到绝对路径
 * fileName:文件名称
 * buf:指针对象，专递数组首地址
 * bufLen:数组长度
 *
 * return 0:路径太长， 非0：buf首地址
 *
 */
char* getPath(char* fileName, char* buf, int bufLen) {

	/////////////////////获取路径//////////////////////
	getcwd(buf, bufLen); //把当前目录存入buf中，最大存入bufLen字符，超过了将会报错。

	int i=0, size = strlen(buf) + strlen(fileName), dirLen=strlen(buf);
	if(size < bufLen) { //如果能够存储，则拷贝到buf中

		for(i=0;i<dirLen;i++) {
			if(buf[i] == '\\') {
				buf[i] = '/';
			}
		}

		for(i=strlen(buf);i<size;i++) {
			if(fileName[i-dirLen] == '\\') {
				buf[i] = '/';
			} else {
				buf[i] = fileName[i-dirLen];
			}
		}

		buf[size] = '\0';
	} else {
		printf("路径太长，需要增加buf长度");
		return 0; //返回0，表示声明的内存不够存储地址整个长度
	}

	return buf;
}
