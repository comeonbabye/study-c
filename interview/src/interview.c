/*
 ============================================================================
 Name        : interview.c
 Author      : tony
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int printN(int n);

int main(void) {

	printN(5);

	return EXIT_SUCCESS;
}

/**
 * 一道淘宝面试：不用条件和循环语句写一个函数： int print_num(int k){};
 * 要求函数功能为打印k的降序，直到0结束，即如果k=5，即打印： 5 4 3 2 1 0
 * 要求： 不能用 if , if else, switch, ?: , while, for , do while, goto 语句
 */
int printN(int n) {
	printf("%d ", n);
	n && printN(n - 1);

	return n;
}
