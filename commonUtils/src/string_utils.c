/*
 * strutils.c
 *
 *  Created on: 2015-1-11
 *      Author: tony
 */

#include "string_utils.h"


/**
 * 1. 检查指针的有效性，增加函数的健壮性
 * 2. const明确表示为只读，良好的编程习惯
 * 3. 末尾附上结束字符
 * 4. 应该返回字符串的开始字符
 */
char* strCpy(char * strDest, const char * strSrc) {

	assert((strDest != NULL) && (strSrc != NULL));
	char * address = strDest;  //保存开始地址
	while(*strSrc) {
		*strDest++ = *strSrc++;
	}

	*strDest = '\0'; //结束字符

	return address; //返回开始地址
}

char* strCpy2(char * strDest, const char * strSrc, int pos, int length) {

	assert((strDest != NULL) && (strSrc != NULL));
	char * address = strDest;  //保存开始地址

	if(length == 0) return address;
	int len = strlen(strSrc);
	if(pos >= len) return address;

	int i = 0, count = 0;
	for(i=0; i<pos; i++) {
		*strSrc++;
	}

	while(*strSrc) {
		*strDest++ = *strSrc++;
		count++;
		if(count >= length) break;
	}

	*strDest = '\0'; //结束字符

	return address; //返回开始地址
}

int strCmp(const char * str1, const char * str2) {

	assert((str1 != '\0') && (str2 != '\0')); //不再判断是否为NULL，因为如果其中一个字符数组为NULL，那么也说明两个字符数组不相等
	while(*str1 && *str2 && *str1==*str2) {
		*str1++;
		*str2++;
	}

	return *str1 - *str2;
}

int strLen(const char * str) {

	int len = 0;
	assert(str != NULL);  //字符串不能为NULL
	while(*str++) {
		len++;
	}
	return len;
}

char * strCat(char * strDest, const char * strSrc) {

	assert((strDest != NULL) && (strSrc != NULL));
	char * address = strDest;  //保存开始地址

	while(*strDest) {
		*strDest++;
	}

	while(*strSrc) {
		*strDest++ = *strSrc++;
	}

	*strDest = '\0'; //结束字符

	return address; //返回开始地址
}

