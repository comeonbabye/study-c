/*
 ============================================================================
 Name        : math.c
 Author      : tony
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// 函数声明
int add();
int max(int, int);
void max4input();


int main(void) {

	//printf("maxValue=%d", max(100,200));
	//printf("\n");

	//add();
	//printf("\n");


	max4input();

	return EXIT_SUCCESS;
}


void max4input() {

	int a, b, n;  // 声明两个整型变量

	printf("Input two integers: ");  // 以空格为分隔

	// 以'|'为分隔符，将输入的两个整数分别赋值给a, b
	scanf("%d %d", &a, &b);
	// 以整数形式输出a、b和最大值，a, b, max(a,b)为参数列表
	n = max(a, b);

	printf("The max between %d and %d is %d.\n", a, b, n);
}

// 函数定义
int add() {
	int i, total = 0; // 声明两个整型变量
	/* for语句用来循环
	 i的起始值为 1，每循环一次加 1，i>100 时退出循环 */
	for (i = 1; i <= 100; i++) {
		total += i; // 加法运算，也可以写作 total=total+i
	}
	printf("1+2+3+...+99+100=%d\n", total); // 将total以整数形式输出

	return total;
}


// 函数定义
int max(int num1, int num2) { // num1, num2为形式参数(形参)
	if (num1 > num2) { // 如果num1大于num2
		return num1; // 返回num1并结束max函数
	} else { // 如果num2大于num1
		return num2; // 返回num2并结束max函数
	}
}
