/*
 ============================================================================
 Name        : HelloWorld.c
 Author      : tony
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>    //stdio ����ָ ��standard input & output"����׼���������
#include <stdlib.h>

/*
 *
 * stdlib.h���涨�����������͡�һЩ���ͨ�ù��ߺ����� ��������size_t��wchar_t��div_t��ldiv_t��lldiv_t��
 * ������EXIT_FAILURE��EXIT_SUCCESS��RAND_MAX��MB_CUR_MAX�ȵȣ� ���õĺ�����malloc()��calloc()��realloc()��
 * free()��system()��atoi()��atol()��rand()��srand()��exit()�ȵȡ�
 */

int main(void) {  //main����

	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

	printf("hello tony.");

	return EXIT_SUCCESS;   //����ִ�гɹ�
}