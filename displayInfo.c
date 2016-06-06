#include "head.h"

void menuDisplayInfo();
void displayFormer();
void displaySell();
void displayMoney();
void displayExpirationData();

void displayInfo()
{
	int choice;
	menuDisplayInfo();
	printf("请输入你的选择: ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		displayFormer();   //显示原来的顺序
		system("pause");
		//system("cls");
		break;
	case 2:
		displaySell();
		//system("pause");
		system("cls");
		break;
	case 3:
		displayMoney();
		system("pause");
		//system("cls");
		break;
	case 4:
		displayExpirationData();
		system("pause");
		//system("cls");
		break;
	case 0:
		break;
	default:
		printf("输入有误!");
		break;
	}
}

void menuDisplayInfo()
{
	printf("\t\t  显示商品信息\n");
	printf("\t\t1、原来商品顺序显示\n");
	printf("\t\t2、销售额高到低显示\n");
	printf("\t\t3、毛利的高到低显示\n");
	printf("\t\t4、保质期近到远显示\n");
	printf("\t\t0、返回上级\n");
}

void displayFormer()
{
	goodsInfoLink *head, *q, *p;
	head = createGoodsInfoLink();
	q = head->next;
	for (p = q; p != NULL; p = p->next)
	{
		p->money = (p->sell) - (p->bid)*(p->outAmount);
		printf("编号\t品名\t生产厂家\t保质期\t\t进价\t\t售价\t\t进货量\n");
		printf("%s\t%s\t%s\t\t%s\t%f\t%f\t%d\n",
			p->number, p->name, p->manuFacturer, p->expirationData, p->bid, p->price, p->inAmount);
		printf("销售量\t销售额\t\t\t剩余数\t\t报销量\t\t毛利\n");
		printf("%d\t%f\t\t%d\t\t%d\t\t%f\n\n\n", p->outAmount, p->sell, p->residue, p->scrap, p->money);
	}
}

void displaySell()
{
	goodsInfoLink *p, *head, *q = NULL, *r = NULL, *temp;
	head = createGoodsInfoLink();
	p = head->next;  //p指向第一个数据节点
	temp = head;
	if (p != NULL)                                     //单链表有一个或者以上的数据节点
	{
		r = p->next;                      //r 保存 *p节点的直接后继节点的指针
		p->next = NULL;            //构造只含有一个数据节点的有序表
		p = r;
		while (p != NULL)
		{
			r = p->next;                //r 保存*p节点的直接后继节点的指针
			q = head;
			while (q->next != NULL && q->next->sell > p->sell)
				q = q->next;     //在有序表中查找插入*p的直接前驱节点*q的位置

			p->next = q->next;                   //将*p插入到*q之后
			q->next = p;
			p = r;                                //扫描原单链表余下的节点
		}
	}
	while (temp->next != NULL)
	{
		temp->next->money = (temp->next->sell) - (temp->next->bid)*(temp->next->outAmount);
		printf("编号\t品名\t生产厂家\t保质期\t\t进价\t\t售价\t\t进货量\n");
		printf("%s\t%s\t%s\t\t%s\t%f\t%f\t%d\n",
			temp->next->number, temp->next->name, temp->next->manuFacturer, temp->next->expirationData, temp->next->bid, temp->next->price, temp->next->inAmount);
		printf("销售量\t销售额\t\t\t剩余数\t\t报销量\t\t毛利\n");
		printf("%d\t%f\t\t%d\t\t%d\t\t%f\n\n\n", temp->next->outAmount, temp->next->sell, temp->next->residue, temp->next->scrap, temp->next->money);
		temp = temp->next;
	}
}

void displayMoney()
{
	goodsInfoLink *p, *head, *q = NULL, *r = NULL, *temp;
	head = createGoodsInfoLink();
	p = head->next;  //p指向第一个数据节点
	temp = head;
	if (p != NULL)                                     //单链表有一个或者以上的数据节点
	{
		r = p->next;                      //r 保存 *p节点的直接后继节点的指针
		p->next = NULL;            //构造只含有一个数据节点的有序表
		p = r;
		while (p != NULL)
		{
			r = p->next;                //r 保存*p节点的直接后继节点的指针
			q = head;
			while (q->next != NULL && q->next->money > p->money)
			{
				q = q->next;     //在有序表中查找插入*p的直接前驱节点*q的位置
			}

			p->next = q->next;                   //将*p插入到*q之后
			q->next = p;
			p = r;                                //扫描原单链表余下的节点
		}
	}
	while (temp->next != NULL)
	{
		temp->next->money = (temp->next->sell) - (temp->next->bid)*(temp->next->outAmount);
		printf("编号\t品名\t生产厂家\t保质期\t\t进价\t\t售价\t\t进货量\n");
		printf("%s\t%s\t%s\t\t%s\t%f\t%f\t%d\n",
			temp->next->number, temp->next->name, temp->next->manuFacturer, temp->next->expirationData, temp->next->bid, temp->next->price, temp->next->inAmount);
		printf("销售量\t销售额\t\t\t剩余数\t\t报销量\t\t毛利\n");
		printf("%d\t%f\t\t%d\t\t%d\t\t%f\n\n\n", temp->next->outAmount, temp->next->sell, temp->next->residue, temp->next->scrap, temp->next->money);
		temp = temp->next;
	}
}

void displayExpirationData()
{
	goodsInfoLink *p, *head, *q = NULL, *r = NULL, *temp;
	head = createGoodsInfoLink();
	p = head->next;  //p指向第一个数据节点
	temp = head;
	if (p != NULL)                                     //单链表有一个或者以上的数据节点
	{
		r = p->next;                      //r 保存 *p节点的直接后继节点的指针
		p->next = NULL;            //构造只含有一个数据节点的有序表
		p = r;
		while (p != NULL)
		{
			r = p->next;                //r 保存*p节点的直接后继节点的指针
			q = head;
			while (q->next != NULL && strcmp(q->next->expirationData, p->expirationData) < 0)//q->next->money > p->money
			{
				q = q->next;     //在有序表中查找插入*p的直接前驱节点*q的位置
			}

			p->next = q->next;                   //将*p插入到*q之后
			q->next = p;
			p = r;                                //扫描原单链表余下的节点
		}
	}
	while (temp->next != NULL)
	{
		temp->next->money = (temp->next->sell) - (temp->next->bid)*(temp->next->outAmount);
		printf("编号\t品名\t生产厂家\t保质期\t\t进价\t\t售价\t\t进货量\n");
		printf("%s\t%s\t%s\t\t%s\t%f\t%f\t%d\n",
			temp->next->number, temp->next->name, temp->next->manuFacturer, temp->next->expirationData, temp->next->bid, temp->next->price, temp->next->inAmount);
		printf("销售量\t销售额\t\t\t剩余数\t\t报销量\t\t毛利\n");
		printf("%d\t%f\t\t%d\t\t%d\t\t%f\n\n\n", temp->next->outAmount, temp->next->sell, temp->next->residue, temp->next->scrap, temp->next->money);
		temp = temp->next;
	}
}