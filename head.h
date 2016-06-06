#pragma warning (disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
typedef struct goodsInfoLink
{
	int residue;		//ʣ����
	int inAmount;		//������
	int outAmount;		//�ۻ���
	int scrap;          //������

	char name[50];		//��Ʒ����
	char number[20];	//��Ʒ���
	char manuFacturer[50];		//����
	char expirationData[20];	//��������

	float bid;			//����
	float sell;			//���۶�
	float price;		//�ۼ�
	float money;		//ë��
	struct goodsInfoLink *next;
}goodsInfoLink;


void createInfo(char way[3]);
void saveInfo(goodsInfoLink *head, char way[3]);  //����������Ϣ
void editInfo();
void statisticsInfo();
void queryInfo();
goodsInfoLink *createGoodsInfoLink();
void displayInfo();