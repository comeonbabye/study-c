/*
 * list.c
 *
 *  Created on: 2015-1-11
 *      Author: tony
 */

#include "list.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status; /* Status是函数的类型，其值是函数结果状态代码，如OK等 */
typedef int ElemType; /* ElemType类型根据时间情况而定，这里假设为int */

Status visit(ElemType c) {
	printf("%d ", c);
	return OK;
}


typedef struct {
	ElemType data[MAXSIZE]; /* 数组，存储数据元素 */
	int length;  /* 线性表当前长度 */
} SequenceList;  //用typedef定义一个别名，不用多些struct这个单词


/**
 * 初始化顺序线性表
 */
Status init(SequenceList *l) {
	l->length = 0;
	return OK;
}


/**
 * 初始条件：顺序线性表已经存在
 * 如果表为空则返回TRUE，否则返回FALSE
 */
Status isEmpty(SequenceList l) {
	if(l.length == 0) {
		return TRUE;
	} else {
		return FALSE;
	}
}

/**
 * 初始条件：顺序线性表已经存在
 * 将表长度置为空，以前的值不需清空，下次覆盖即可
 */
Status clear(SequenceList *l) {
	l->length = 0;
	return OK;
}

/**
 *这里直接返回类型为int的length，因为length不定长，所以不适合用typedef定义
 */
int length(SequenceList l) {
	return l.length;
}

/**
 * 初始条件：顺序线性表L已存在，1≤i≤ListLength(L)
 * 用e返回list中第i个结果，实际存储下标是i-1
 */
Status getElem(SequenceList l, int i, ElemType *e) {
	if(l.length == 0 || i<1 || i>l.length) {
		return ERROR;
	}

	*e = l.data[i - 1];
	return OK;
}

/**
 * 初始条件：顺序线性表L已存在
 * 若list中存在e这个元素，则返回对应的index，否则返回0
 */
int indexOfElem(SequenceList l, ElemType e) {
	int i;
	if(l.length == 0) {
		return 0;
	}

	for(i=0; i<l.length; i++) {
		if(l.data[i] == e) {
			break;
		}
	}

	if(i >= l.length) {
		return 0;
	}

	return i + 1;
}

/**
 * 初始条件：顺序线性表L已存在
 * 在L中第i个位置之前插入新的数据元素e，L的长度加1
 */
Status insert(SequenceList *l, int i, ElemType e) {
	int k;
	if(l->length == MAXSIZE) { /* 顺序线性表已经满 */
		return ERROR;
	}

	if(i<1 || i>l->length + 1) {/* 当i比第一位置小或者比最后一位置后一位置还要大时 */
		return ERROR;
	}

	if(i<=l->length) {/* 若插入数据位置不在表尾 */
		for(k=l->length - 1; k>= i-1; k--) { /* 将要插入位置之后的数据元素向后移动一位 */
			l->data[k+1] = l->data[k];
		}
	}
	l->data[i-1] = e;   /* 将新元素插入 */
	l->length++;

	return OK;
}


/**
 * 初始条件：顺序线性表L已存在
 * 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1
 */
Status delete(SequenceList *l, int i, ElemType *e) {
	int k;
	if(l->length == 0) {/* 线性表为空 */
		return ERROR;
	}

	if(i<1 || i>l->length) {/* 删除位置不正确 */
		return ERROR;
	}

	*e = l->data[i-1];

	if(i<l->length) {/* 如果删除不是最后位置 */
		for(k=i; k<l->length; k++) {/* 将删除位置后继元素前移 */
			l->data[k-1] = l->data[k];
		}
	}

	l->length--;

	return OK;
}

/**
 * 初始条件：顺序线性表L已存在
 * 打印list
 */
Status printList(SequenceList l) {
	int i;
	for(i=0; i<l.length; i++) {
		visit(l.data[i]);
	}

	printf("\n");

	return OK;

}

void unionList(SequenceList *la, SequenceList *lb) {
	int la_len, lb_len, i;
	ElemType e;
	la_len = length(*la);
	lb_len = length(*lb);

	for(i=1; i<lb_len; i++) {  /* 遍历lb，取出每一个元素，如果在la中不存在，则插入到la的最后 */
		getElem(*lb, i, &e);
		if(!indexOfElem(*la, e)) {
			if(insert(la, ++la_len, e) == ERROR) {
				printf("la中元素已满，无法插入");
				break;
			}
		}
	}
}


void testList() {

	SequenceList l;
	ElemType e;
	Status i;
	int j, k;
	i = init(&l);
	printf("初始化List后：l.length=%d\n", l.length);

	for(j=1; j<=5; j++) {
		i = insert(&l, 1, j);
	}
	printf("在List的表头依次插入1~~5后：l.data=");
	printList(l);
	printf("l.length=%d\n", l.length);


	i = clear(&l);
	printf("List是否空：i=%d(1：是 0:否) \n", i);

	for(j=1; j<=10; j++) {
		i = insert(&l, 1, j);
	}
	printf("在List的表头依次插入1~~5后：l.data=");
	printList(l);
	printf("l.length=%d\n", l.length);


	insert(&l, 1, 0);
	printf("在List的表头插入0后：l.data=");
	printList(l);
	printf("l.length=%d\n", l.length);

	getElem(l, 5, &e);
	printf("第5个元素的值为：%d\n", e);

	for(j=3; j<=4; j++) {
		k = indexOfElem(l, j);
		if(k) {
			printf("第%d个元素的值为%d\n", k, j);
		} else {
			printf("没有值为%d的元素\n", j);
		}
	}

	k = length(l); /* k为表长 */
	for(j=k+1; j>=k; j--) {
		i = delete(&l, j, &e);
		if(i == ERROR) {
			printf("删除第%d个数据失败！\n", j);
		} else {
			printf("删除第%d个的元素的值为：%d\n", j, e);
		}
	}
	printf("依次输出List的元素：");
	printList(l);

	j = 5;
	delete(&l, j, &e);
	printf("删除第%d个元素的值为：%d\n", j, e);

	printf("依次输出List的元素：");
	printList(l);

	SequenceList lb;
	i = init(&lb);
	for(j=6; j<=15; j++) {
		i = insert(&lb, 1, j);
	}

	printf("依次输出lb的元素：");
	printList(lb);

	unionList(&l, &lb);
	printf("依次输出合并了lb和l的元素：");
	printList(l);

}







