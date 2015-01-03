/*
 ============================================================================
 Name        : pointer.c
 Author      : tony
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void point_one();
void point_two();

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

	point_one();

	point_two();

	return EXIT_SUCCESS;
}

/**
 *测试指针循环和复制
 */
void point_one() {

	int array[20] = {0};
	int *ptr = array, i;
	(*ptr) = 100;
	for(i=0; i<20; i++) {
		(*ptr)++;
		printf("\n %d = %d", i, *ptr);
		ptr++;
	}
}


/**
 * 指针本身地址会占用4个字节
 * 指针会存储指向值的首地址，然后开辟一块连续的内存区域来存储值sizeof(ptr *)，即sizeof(指针类型);
 *
 */
void point_two() {

	char a[20] = "You_are_a_girl";
	char *p = a;
	char **ptr = &p;
	printf("\n");
	printf("a=%s\n", a);
	printf("p=%d\n", (int)p);
	printf("*p=%c\n", *p);
	printf("ptr=%d\n", (int)ptr);
	printf("*ptr=%d\n", (int)*ptr);
	printf("**ptr=%c\n", **ptr);

	ptr++;

	printf("\n");

	//printf("ptr=%d\n", ptr);
	//printf("*ptr=%d\n", *ptr);
	printf("**ptr=%c\n", **ptr);
	//这个是在一个指针本身地址上加上size(char*)，也就是4(因为32系统下面一直指针地址占4个字节)，
	//所以指针本身地址加上四指向的地方未知，而不是指针指向值的地址，即指针会存储指向值的首地址

}
