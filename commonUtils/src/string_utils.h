/*
 * strutils.h
 *
 *  Created on: 2015-1-11
 *      Author: tony
 */

#ifndef STRUTILS_H_
#define STRUTILS_H_

#include <assert.h>
#include <stdio.h>
#include <string.h>


/**
 * 将源字符数组拼接到目标字符串中
 * Input
 * 		strDest 目标字符串
 * 		stcStr  源字符串
 * Output
 * 		返回目标字符串指针
 */
char * strCat(char * strDest, const char * srcStr);

/**
 * 将源字符数组拷贝到目标字符串中
 * Input
 * 		strDest 目标字符串
 * 		stcStr  源字符串
 * Output
 * 		返回目标字符串指针
 */
char * strCpy(char * strDest, const char * srcStr);

/**
 * 将源字符串拷贝到目标字符串中
 * Input
 * 		strDest 目标字符串
 * 		stcStr  源字符串
 * 		pos		开始地址
 * 		length	长度
  * Output
 * 		返回目标字符串指针
 */
char * strCpy2(char * strDest, const char * srcStr, int pos, int length);





/**
 * 比较两字符串是否相等
 * Input
 * 		strDest 目标字符串
 * 		stcStr  源字符串
 * Output
 * 		相等则返回0，否则返回非0
 */
int strCmp(const char * str1, const char * str2);


/**
 * 返回字符串长度
 * Input
 * 		str 字符串
 * Output
 * 		返回字符串长度
 */
int strLen(const char * str);



#endif /* STRUTILS_H_ */
