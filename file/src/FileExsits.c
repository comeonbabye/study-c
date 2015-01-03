/*
 * FileExsits.c
 *
 *  Created on: 2015-1-1
 *      Author: tony
 */

#include <stdio.h>
#include <io.h>

#include "./module/common/h/Common.h"
#include "FileExsits.h"

int isFileExsits(char * fileName) {

	/////////////////////获取路径//////////////////////
	char buf[80];

	return isFileExsits2(fileName, buf, sizeof(buf));

}

int isFileExsits2(char * fileName, char * buf, int bufLen) {

	/////////////////////获取路径//////////////////////
	if(getPath(fileName, buf, bufLen) == 0) {
		return 0;
	}

	/**
	 * 这里用access精确控制，0：是否存在， 2：是否可写入 ，4：是否可读取，6：是否可执行
	 * 如果用fopen，模式用w的话，如果文件不存在默认会创建文件
	 * 				模式用r的话，如果文件不可读那么返回回事NULL，但是文件可能存在。
	 */
	if(access(buf, F_OK) == 0) {
		printf("该文件存在：%s", buf);
		return 1;
	} else {
		printf("该文件不存在：%s", buf);
		return 0;
	}

}

