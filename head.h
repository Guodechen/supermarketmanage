#pragma warning (disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
typedef struct goodsInfoLink
{
	int residue;		//剩余数
	int inAmount;		//进货量
	int outAmount;		//售货量
	int scrap;          //报废量

	char name[50];		//商品名字
	char number[20];	//商品编号
	char manuFacturer[50];		//厂家
	char expirationData[20];	//生产日期

	float bid;			//进价
	float sell;			//销售额
	float price;		//售价
	float money;		//毛利
	struct goodsInfoLink *next;
}goodsInfoLink;


void createInfo(char way[3]);
void saveInfo(goodsInfoLink *head, char way[3]);  //用链表保存信息
void editInfo();
void statisticsInfo();
void queryInfo();
goodsInfoLink *createGoodsInfoLink();
void displayInfo();