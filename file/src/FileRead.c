/*
 * FileRead.c
 *
 *  Created on: 2014-12-30
 *      Author: tony
 */

#include "stdio.h"
#include <stdlib.h>  //exit����
#include <string.h>
#include <unistd.h>  //getcwd����

int main(void) {

	char buf[80];
	getcwd(buf, sizeof(buf)); //��õ�ǰ·��
	char* path = strcat(buf, "\\test.txt");

	//����·�������б��
	int i, len = strlen(path);
	printf("����:%d\n", len);
	for(i=0;i<len;i++) {
		if(path[i] == '\\') {
			path[i] = '/';
		}
	}

	printf(path);
	printf("\n");

	FILE *file;

	if((file = fopen(path, "rt")) == NULL) {
		printf("�ļ�������");
		exit(1);
	}

	char ch;

	ch = fgetc(file);

	while(ch != EOF) { //���û�ж�ȡ���ļ�ĩβ���������ȡ�ʹ�ӡ�ַ�
		printf("%c",ch);
		ch = fgetc(file);
	}

	printf("\n");

	if(fclose(file) == EOF) {
		printf("�ر��ļ�ʧ�ܣ�");
	} else {
		printf("�ر��ļ��ɹ���");
	}

	return 1;
}

