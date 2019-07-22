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
//����ڵ�
void insertNodeByHead(struct Node* headNode,struct student data)
{
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
//��ӡ����
void printList(struct Node* headNode)
{
	struct Node* pMove = headNode->next;
	printf("����\t����\t�Ա�\t�绰\n");
	while (pMove)
	{
		printf("%s\t%d\t%s\t%s\n", pMove->data.name, pMove->data.age, pMove->data.sex, pMove->data.tel);
		pMove = pMove->next;
	}
	printf("\n");
}
//ָ��λ��ɾ��
void deleteAppoinNode(struct Node* headNode, char* name)
{
	struct Node* posNode = headNode->next;
	struct Node* posFrontNode = headNode;
	if (posNode == NULL)
	{
		printf("����Ϊ��,�޷�ɾ����\n");
		return;
	}
	while (strcmp(posNode->data.name,name))
	{
		posFrontNode = posNode;
		posNode = posFrontNode->next;
		if (posNode == NULL)
		{
			printf("δ�ҵ�ָ��λ���޷�ɾ��!\n");
			return;
		}
	}
	posFrontNode->next = posNode->next;

}
//ָ��λ���޸�
void updataAppoinNode(Node* posNode,student data)
{
	posNode->data = data;
}

//����
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

//�ļ�д����
void writrInfoToFile(struct Node* headNode, char *fileName)
{
	//1.��
	FILE *fp;
	struct student data;
	fp = fopen(fileName, "w");
	struct Node* pMove = headNode->next;
	//2.д�ļ�
	while (pMove){
		fprintf(fp,"%s\t%d\t%s\t%s\n", pMove->data.name, pMove->data.age, pMove->data.sex, pMove->data.tel);
		pMove = pMove->next;
	}
	//3.�ر��ļ�
	fclose(fp);
}


//�ļ�������
void readInfoFromFile(struct Node* headNode, char *fileName)
{
	//1.��
	FILE *fp;
	struct student data;
	fp = fopen(fileName, "r");
	if (fp == NULL){
		fp= fopen(fileName, "w+");
	}
	//2.���ļ�
	while (fscanf(fp, "%s\t%d\t%s\t%s\n", data.name, data.age, data.sex, data.tel) != EOF){
		insertNodeByHead(headNode, data);
	}
		//3.�ر��ļ�
	fclose(fp);
}

