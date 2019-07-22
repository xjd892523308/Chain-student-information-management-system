/*
	1.����
	2.���ݽṹ�����
	3.����

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "mylist.h"

//�˵����
void menu(){
	printf("--------------��ѧ����Ϣ����ϵͳ��---------------\n");
	printf("\t\t0.�˳�ϵͳ\n");
	printf("\t\t1.¼����Ϣ\n");
	printf("\t\t2.�����Ϣ\n");
	printf("\t\t3.�޸���Ϣ\n");
	printf("\t\t4.ɾ����Ϣ\n");
	printf("\t\t5.������Ϣ\n");
	printf("-------------------------------------------------\n");
}

struct Node* list = createList();

void keyDown(){
	struct student data;
	struct Node* pMove = nullptr;
	int choice = 0;
	scanf("%d",&choice);
	switch (choice)
	{
	case 0:
		printf("�����˳���\n");
		system("pause");
		exit(0);
		break;
	case 1:
		printf("-----------------��¼����Ϣ��--------------------\n");
		printf("������ѧ�����������䣬�Ա𣬵绰��");
		fflush(stdin);
		scanf("%s%d%s%s", data.name, &data.age, data.sex, data.tel);
		insertNodeByHead(list, data);
		break;
	case 2:
		printf("-----------------�������Ϣ��--------------------\n");
		printList(list);
		break;
	case 3:
		printf("-----------------���޸���Ϣ��--------------------\n");
		printf("������Ҫ�޸ĵ�ѧ��������");
		scanf("%s", data.name);
		pMove = searchInfoByData(list, data.name);
		if (pMove == NULL){
			printf("δ�ҵ������Ϣ,�޷��޸�!\n");
			system("pause");
		}
		else{
			printf("����\t����\t�Ա�\t�绰\n");
			printf("%s\t%d\t%s\t%s\n", pMove->data.name, pMove->data.age, pMove->data.sex, pMove->data.tel);
			printf("���޸ĺ��ѧ�����������䣬�Ա𣬵绰��");
			fflush(stdin);
			scanf("%s%d%s%s", data.name, &data.age, data.sex, data.tel);
			updataAppoinNode(pMove, data);
		}
		break;
	case 4:
		printf("-----------------��ɾ����Ϣ��--------------------\n");
		printf("������ɾ����ѧ��������");
		scanf("%s", data.name);
		deleteAppoinNode(list, data.name);
		break;
	case 5:
		printf("-----------------��������Ϣ��--------------------\n");
		printf("������Ҫ���ҵ�ѧ��������");
		scanf("%s", data.name);
		pMove = searchInfoByData(list, data.name);
		if (pMove== NULL){
			printf("δ�ҵ������Ϣ,�޷�ɾ��!\n");
			system("pause");
		}
		else{
			printf("����\t����\t�Ա�\t�绰\n");
			printf("%s\t%d\t%s\t%s\n", pMove->data.name, pMove->data.age, pMove->data.sex, pMove->data.tel);
		}
		break;
	default:
		printf("ѡ�������������");
		system("pause");
		break;
	}
	writrInfoToFile(list, "1.txt");
}

int main(){
	readInfoFromFile(list, "1.txt");
	while (1){
		menu();
		keyDown();
		system("pause");
		system("cls");
	}


	

	system("pause");
	return 0;
}