/*
 * test.c
 *
 *  Created on: 2015-1-11
 *      Author: tony
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test.h"

void testStrCpy() {

	printf("===================start testStrCpy()===================\n");

	char strB[20] = "how are you.";
	char strA[10];
	strCpy(strA, strB);

	printf("strA:%s\n", strA);
	printf("length of strA: %d \n", strlen(strA));
}

void testStrCpy2() {

	printf("===================start testStrCpy2()===================\n");

	char strB[20] = "how are you.";
	char strA[10];
	strCpy2(strA, strB, 4, 3);

	printf("strA:%s\n", strA);
	printf("length of strA: %d \n", strlen(strA));
}

void testStrCmp() {
	printf("===================start testStrCmp()===================\n");

	char strB[20] = "how are you.";
	char strA[5];

	int ret = strCmp(strA, strB);
	if(ret == 0) {
		printf("strA:[%s] is equals strB:[%s]\n", strA, strB);
	} else {
		printf("strA:[%s] is not equals strB:[%s]? ret: %d \n", strA, strB, ret);
	}

	char strC[20] = "how are you.";
	char strD[13] = "how are you."; //长度要足够的长，不然后面就不知道是什么了，且长度必须加上结束字符'\0'

	ret = strCmp(strC, strD);
	if(ret == 0) {
		printf("strC:[%s] is equals strD:[%s]\n", strC, strD);
	} else {
		printf("strC:[%s] is not equals strD:[%s]? ret: %d \n", strC, strD, ret);
	}
}

void testStrLen() {
	printf("===================start testStrLen()===================\n");
	char strB[20] = "how are you, tony.";

	int len = strLen(strB);

	printf("the length of strB:[%s] is %d \n", strB, len);

}


void testStrCat() {
	printf("===================start testStrCat()===================\n");
	char strB[20] = "how are you.";
	char strA[10] = "hi tony, ";

	strCat(strA, strB);

	printf("the length of strA:[%s] is %d \n", strA, strLen(strA));
}

