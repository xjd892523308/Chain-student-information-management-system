/*
	1.界面
	2.数据结构的设计
	3.交互

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "mylist.h"

//菜单设计
void menu(){
	printf("--------------【学生信息管理系统】---------------\n");
	printf("\t\t0.退出系统\n");
	printf("\t\t1.录入信息\n");
	printf("\t\t2.浏览信息\n");
	printf("\t\t3.修改信息\n");
	printf("\t\t4.删除信息\n");
	printf("\t\t5.查找信息\n");
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
		printf("正常退出！\n");
		system("pause");
		exit(0);
		break;
	case 1:
		printf("-----------------【录入信息】--------------------\n");
		printf("请输入学生姓名，年龄，性别，电话：");
		fflush(stdin);
		scanf("%s%d%s%s", data.name, &data.age, data.sex, data.tel);
		insertNodeByHead(list, data);
		break;
	case 2:
		printf("-----------------【浏览信息】--------------------\n");
		printList(list);
		break;
	case 3:
		printf("-----------------【修改信息】--------------------\n");
		printf("请输入要修改的学生姓名：");
		scanf("%s", data.name);
		pMove = searchInfoByData(list, data.name);
		if (pMove == NULL){
			printf("未找到相关信息,无法修改!\n");
			system("pause");
		}
		else{
			printf("姓名\t年龄\t性别\t电话\n");
			printf("%s\t%d\t%s\t%s\n", pMove->data.name, pMove->data.age, pMove->data.sex, pMove->data.tel);
			printf("请修改后的学生姓名，年龄，性别，电话：");
			fflush(stdin);
			scanf("%s%d%s%s", data.name, &data.age, data.sex, data.tel);
			updataAppoinNode(pMove, data);
		}
		break;
	case 4:
		printf("-----------------【删除信息】--------------------\n");
		printf("请输入删除的学生姓名：");
		scanf("%s", data.name);
		deleteAppoinNode(list, data.name);
		break;
	case 5:
		printf("-----------------【查找信息】--------------------\n");
		printf("请输入要查找的学生姓名：");
		scanf("%s", data.name);
		pMove = searchInfoByData(list, data.name);
		if (pMove== NULL){
			printf("未找到相关信息,无法删除!\n");
			system("pause");
		}
		else{
			printf("姓名\t年龄\t性别\t电话\n");
			printf("%s\t%d\t%s\t%s\n", pMove->data.name, pMove->data.age, pMove->data.sex, pMove->data.tel);
		}
		break;
	default:
		printf("选择错误，重新输入");
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