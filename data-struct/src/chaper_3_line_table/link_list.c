/*
 * link_list.c
 *
 *  Created on: 2015-1-12
 *      Author: tony
 */

#include "link_list.h"


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20  /* 存储空间初始分配量 */

typedef int Status;  /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType; /* ElemType类型根据实际情况而定，这里假设为int */

Status visitLinkListNode(ElemType c) {
	printf("%d ", c);
	return OK;
}

typedef struct Node {
	ElemType data;  //int 占4字节
	struct Node *next; //指针占4字节
} Node;

typedef struct Node *LinkList; /* 定义LinkList */


/**
 * 初始化LinkList
 * input
 * 		*l	已经存在的链表
 * output
 * 		如果分配失败则返回ERROR
 * 		如果分配成功则返回OK
 */
Status initLinkList(LinkList *l) {
	*l = (LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
	if(!(*l)) { /* 存储分配失败 */
		return ERROR;
	}
	(*l)->next = NULL;  /* 指针域为空 */
	return OK;
}

/**
 * 初始条件：LinkList已经存在
 * input
 * 		l	已经存在的链表
 * ouput
 * 		如果链表为空则返回TRUE
 *  	如果链表不为空则返回FALSE
 */
Status isLinkListEmpty(LinkList l) {
	if(l->next) { //第一个节点不存储数据
		return FALSE;
	} else {
		return TRUE;
	}
}

/**
 * 初始条件：LinkList已经存在
 * input
 * 		*l	已经存在的链表
 * output
 *		如果释放内存成功，则返回OK
 */
Status clearLinkList(LinkList *l) {
	LinkList p, q;
	p = (*l)->next;  /*  p指向第一个结点 */
	while(p) { /*  如果没到表尾 */
		q = p->next;  //获得下一个节点的应用
		free(p);  //是否当前节点内存
		p = q;  //把下一个节点当做当前节点，循环处理，知道遍历到链表末尾
	}

	(*l)->next = NULL; //最后把第一个节点的指针设置为NULL

	return OK;
}

/**
 * 初始条件：LinkList已经存在
 * input
 * 		l	已经存在的链表
 * output
 *		返回链表元素的数量
 */
int lengthOfLinkList(LinkList l) {
	int i = 0;
	LinkList p = l->next;
	while(p) {
		i++;
		p = p->next;
	}
	return i;
}

/**
 * 初始条件：LinkList已经存在
 * input
 * 		l	已经存在的链表
 * 		i	index
 * 		*e	存储元素
 * output
 *		如果对应的index存在，则返回TRUE，并且把该index的值赋值给*e
 *		如果对应的index不存在，则返回ERROR
 */
Status getElemOfLinkList(LinkList l, int i, ElemType *e) {
	int j;
	LinkList p;  /* 声明一结点p */
	p = l->next;  /* 让p指向链表L的第一个结点 */
	j = 1;  /*  j为计数器 */
	while(p && j<i) {   /* p不为空或者计数器j还没有等于i时，循环继续 */
		p = p->next;  /* 让p指向下一个结点 */
		++j;
	}
	if(!p || j > i) {
		return ERROR;   /*  第i个元素不存在 */
	}

	*e = p->data;  /*  取第i个元素的数据 */

	return OK;
}


/**
 * 初始条件：LinkList已经存在
 * input
 * 		l	已经存在的链表
 * 		e	比较的元素
 * output
 *		如果链表中存在该元素，则返回对应的index
 *		如果链表中不存在该元素，则返回0
 */
int indexOfElemInLinkList(LinkList l, ElemType e) {
	int i = 0;
	LinkList p = l->next;
	while(p) {
		i++;
		if(p->data == e) {  /* 找到这样的数据元素 */
			return i;
		}
		p = p->next;
	}

	return 0;
}


/**
 * 初始条件：LinkList已经存在
 * 将元素插入到指定的位置后面
 * input
 * 		*l	已经存在的链表
 * 		i	插入位置
 * 		e	插入元素值
 * output
 *		如果插入成功，则返回OK
 *		如果插入失败，则返回ERROR
 */
Status insertLinkList(LinkList *l, int i, ElemType e) {
	int j;
	LinkList p, s;
	p = *l;
	j = 1;
	while(p && j<i) {  /* 寻找第i个结点 */
		p = p->next;
		++j;
	}

	if(!p || j > i) {
		return ERROR;  /* 第i个元素不存在 */
	}

	s = (LinkList)malloc(sizeof(Node));  /*  生成新结点(C语言标准函数) */
	s->data = e;
	s->next = p->next;  /* 将p的后继结点赋值给s的后继  */
	p->next = s;  /* 将s赋值给p的后继 */

	return OK;

}

/**
 * 初始条件：LinkList已经存在
 * 删除指定位置的元素
 * input
 * 		*l	已经存在的链表
 * 		i	删除元素index
 * 		*e	返回删除的元素
 * output
 *		如果删除成功，则返回OK，并且把删除元素存储在*e中
 *		如果删除失败，则返回ERROR
 */
Status deleteLinkList(LinkList *l, int i, ElemType *e) {
	int j;
	LinkList p, q;
	p = *l;
	j = 1;
	while(p->next && j<i) {  /* 遍历寻找第i个元素 */
		p = p->next;
		++j;
	}

	if(!(p->next) || j > i) {
		return ERROR;  /* 第i个元素不存在 */
	}

	q = p->next;
	p->next = q->next;  /* 将q的后继赋值给p的后继 */
	*e = q->data;     /* 将q结点中的数据给e */
	free(q);   /* 让系统回收此结点，释放内存 */

	return OK;
}

/**
 * 打印LinkList
 */
Status printLinkList(LinkList l) {

	LinkList p = l->next;
	while(p) {
		visitLinkListNode(p->data);
		p = p->next;
	}

	printf("\n");

	return OK;
}

/**
 * 随机产生n个元素，建立带表头节点的单向链表(头插法)
 */
void createLinkListHead(LinkList *l, int n) {
	LinkList p;
	int i;
	srand(time(0));  /* 初始化随机数种子 */
	*l = (LinkList)malloc(sizeof(Node));
	(*l)->next = NULL;   /*  先建立一个带头结点的单链表 */
	for(i=0; i<n; i++) {
		p = (LinkList)malloc(sizeof(Node));  /*  生成新结点 */
		p->data = rand()%100 + 1;  /*  随机生成100以内的数字 */
		p->next = (*l)->next;
		(*l)->next = p;  /*  插入到表头 */
	}
}

/**
 * 随机产生n个元素，建立带表头节点的单向链表(尾插法)
 */
void createLinkListTail(LinkList *l, int n) {
	LinkList p, r;
	int i;
	srand(time(0));   /* 初始化随机数种子 */
	*l = (LinkList)malloc(sizeof(Node));  /* L为整个线性表 */
	r = *l;  /* r为指向尾部的结点 */
	for(i=0; i<n; i++) {
		p = (Node *)malloc(sizeof(Node));  /*  生成新结点 */
		p->data = rand() % 100 + 1;  /*  随机生成100以内的数字 */
		r->next = p;  /* 将表尾终端结点的指针指向新结点 */
		r = p;   /* 将当前的新结点定义为表尾终端结点 */
	}
	r->next = NULL;  /* 表示当前链表结束 */
}


void testLinkList() {
	printf("size of Node : %d \n", sizeof(Node));

	LinkList L;
	ElemType e;
	Status i;
	int j,k;
	i=initLinkList(&L);
	printf("初始化L后：lengthOfLinkList(L)=%d\n",lengthOfLinkList(L));
	for(j=1;j<=5;j++)
		i=insertLinkList(&L,1,j);
	printf("在L的表头依次插入1～5后：L.data=");
	printLinkList(L);

	printf("lengthOfLinkList(L)=%d \n",lengthOfLinkList(L));
	i=isLinkListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n",i);

	i=clearLinkList(&L);
	printf("清空L后：lengthOfLinkList(L)=%d\n",lengthOfLinkList(L));
	i=isLinkListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n",i);

	for(j=1;j<=10;j++)
		insertLinkList(&L,j,j);
	printf("在L的表尾依次插入1～10后：L.data=");
	printLinkList(L);
	printf("lengthOfLinkList(L)=%d \n",lengthOfLinkList(L));

	insertLinkList(&L,1,0);
	printf("在L的表头插入0后：L.data=");
	printLinkList(L);
	printf("lengthOfLinkList(L)=%d \n",lengthOfLinkList(L));

	getElemOfLinkList(L,5,&e);
	printf("第5个元素的值为：%d\n",e);
	for(j=3;j<=4;j++) {
		k=indexOfElemInLinkList(L,j);
		if(k) {
			printf("第%d个元素的值为%d\n",k,j);
		} else {
			printf("没有值为%d的元素\n",j);
		}
	}

	k=lengthOfLinkList(L); /* k为表长 */
	for(j=k+1;j>=k;j--) {
		i=deleteLinkList(&L,j,&e); /* 删除第j个数据 */
		if(i==ERROR) {
			printf("删除第%d个数据失败\n",j);
		} else {
			printf("删除第%d个的元素值为：%d\n",j,e);
		}
	}
	printf("依次输出L的元素：");
	printLinkList(L);


	j=5;
	deleteLinkList(&L,j,&e); /* 删除第5个数据 */
	printf("删除第%d个的元素值为：%d\n",j,e);
	printf("依次输出L的元素：");
	printLinkList(L);


	i=clearLinkList(&L);
	printf("\n清空L后：ListLength(L)=%d\n",lengthOfLinkList(L));
	createLinkListHead(&L,20);
	printf("整体创建L的元素(头插法)：");
	printLinkList(L);

	i=clearLinkList(&L);
	printf("\n删除L后：lengthOfLinkList(L)=%d\n",lengthOfLinkList(L));
	createLinkListTail(&L,20);
	printf("整体创建L的元素(尾插法)：");
	printLinkList(L);

}






