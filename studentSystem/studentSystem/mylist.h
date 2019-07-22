#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
	char name[20];
	int age;
	char sex[5];
	char tel[20];
};

struct Node
{
	student data;
	struct Node* next;
};

struct Node* createList()
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = nullptr;
	return headNode;
}

struct Node* createNode(struct student data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = nullptr;
	return newNode;
}
//插入节点
void insertNodeByHead(struct Node* headNode,struct student data)
{
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
//打印链表
void printList(struct Node* headNode)
{
	struct Node* pMove = headNode->next;
	printf("姓名\t年龄\t性别\t电话\n");
	while (pMove)
	{
		printf("%s\t%d\t%s\t%s\n", pMove->data.name, pMove->data.age, pMove->data.sex, pMove->data.tel);
		pMove = pMove->next;
	}
	printf("\n");
}
//指定位置删除
void deleteAppoinNode(struct Node* headNode, char* name)
{
	struct Node* posNode = headNode->next;
	struct Node* posFrontNode = headNode;
	if (posNode == NULL)
	{
		printf("数据为空,无法删除！\n");
		return;
	}
	while (strcmp(posNode->data.name,name))
	{
		posFrontNode = posNode;
		posNode = posFrontNode->next;
		if (posNode == NULL)
		{
			printf("未找到指定位置无法删除!\n");
			return;
		}
	}
	posFrontNode->next = posNode->next;

}
//指定位置修改
void updataAppoinNode(Node* posNode,student data)
{
	posNode->data = data;
}

//查找
struct Node* searchInfoByData(struct Node* headNode, char *name)
{
	struct Node* pMove = headNode->next;
	if (pMove == NULL)
		return NULL;
	while (strcmp(pMove->data.name, name))
	{
		pMove = pMove->next;
	}
	return pMove;
}

//文件写操作
void writrInfoToFile(struct Node* headNode, char *fileName)
{
	//1.打开
	FILE *fp;
	struct student data;
	fp = fopen(fileName, "w");
	struct Node* pMove = headNode->next;
	//2.写文件
	while (pMove){
		fprintf(fp,"%s\t%d\t%s\t%s\n", pMove->data.name, pMove->data.age, pMove->data.sex, pMove->data.tel);
		pMove = pMove->next;
	}
	//3.关闭文件
	fclose(fp);
}


//文件读操作
void readInfoFromFile(struct Node* headNode, char *fileName)
{
	//1.打开
	FILE *fp;
	struct student data;
	fp = fopen(fileName, "r");
	if (fp == NULL){
		fp= fopen(fileName, "w+");
	}
	//2.读文件
	while (fscanf(fp, "%s\t%d\t%s\t%s\n", data.name, data.age, data.sex, data.tel) != EOF){
		insertNodeByHead(headNode, data);
	}
		//3.关闭文件
	fclose(fp);
}

