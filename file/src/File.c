/*
 * File.c
 *
 *  Created on: 2014-12-31
 *      Author: tony
 */

#include <stdio.h>
#include <stdlib.h>

#include "./module/common/h/Common.h"
#include "FileReadChar.h"
#include "FileWriteChar.h"
#include "FileExsits.h"


int main() {

	//测试公共方法，获取文件完整路径
	/*char buf[100];
	if(getPath("\\resource\\FileWriteChar\\test.txt", buf, sizeof(buf)) == 0) {
		//printf("路径太长，需要增加buf长度");
	} else {
		printf("\n获得路径:%s", buf);
	}
	free(buf);*/

	//测试读取文件内容，并打印到控制台
	//testFileReadChar();

	testFileWriteChar();

	/**
	 * 测试文件是否已经存在
	 */
	/*if(isFileExsits("\\resource\\FileWriteChar\\test.txt")) {
		printf("file exsits.");
	}*/

	return 1;
}
