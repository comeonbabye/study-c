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

// ��������
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

	int a, b, n;  // �����������ͱ���

	printf("Input two integers: ");  // �Կո�Ϊ�ָ�

	// ��'|'Ϊ�ָ���������������������ֱ�ֵ��a, b
	scanf("%d %d", &a, &b);
	// ��������ʽ���a��b�����ֵ��a, b, max(a,b)Ϊ�����б�
	n = max(a, b);

	printf("The max between %d and %d is %d.\n", a, b, n);
}

// ��������
int add() {
	int i, total = 0; // �����������ͱ���
	/* for�������ѭ��
	 i����ʼֵΪ 1��ÿѭ��һ�μ� 1��i>100 ʱ�˳�ѭ�� */
	for (i = 1; i <= 100; i++) {
		total += i; // �ӷ����㣬Ҳ����д�� total=total+i
	}
	printf("1+2+3+...+99+100=%d\n", total); // ��total��������ʽ���

	return total;
}


// ��������
int max(int num1, int num2) { // num1, num2Ϊ��ʽ����(�β�)
	if (num1 > num2) { // ���num1����num2
		return num1; // ����num1������max����
	} else { // ���num2����num1
		return num2; // ����num2������max����
	}
}
