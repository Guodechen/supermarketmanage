#include"head.h"

goodsInfoLink *createGoodsInfoLink();
void menuQueryInfo();
void sortByName();
void sortBymanuFacturer();
void sortBySell();
void sortByresidue();
void sortByExpirationData();

void queryInfo()
{
	int choice;
	menuQueryInfo();
	printf("请输入你的选择:");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		sortByName();
		system("pause");
		//system("cls");
		break;
	case 2:
		sortBymanuFacturer();
		system("pause");
		//system("cls");
		break;
	case 3:
		sortBySell();
		system("pause");
		//system("cls");
		break;
	case 4:
		sortByresidue();
		system("pause");
		//system("cls");
		break;
	case 5:
		sortByExpirationData();
		system("pause");
		//system("cls");
		break;
	case 0:
		break;
	default:
		printf("输入信息有误");
		break;
	}
}

void menuQueryInfo()
{
	printf("\t\t  查询商品信息\n");
	printf("\t\t1、根据商品名\n");
	printf("\t\t2、根据生产厂家\n");
	printf("\t\t3、根据销售额\n");
	printf("\t\t4、根据剩余数\n");
	printf("\t\t5、根据保质期\n");
	printf("\t\t0、返回上级\n");
}


void sortByName()
{
	goodsInfoLink *head, *q, *p;
	char name[20];
	head = createGoodsInfoLink();
	printf("请输入你想要查询的商品名称:");
	scanf("%s", name);
	q = head->next;
	for (p = q; p != NULL&&strcmp(p->name, name); p = p->next);
	if (p != NULL)
	{
		p->money = (p->sell) - (p->bid)*(p->outAmount);
		printf("您想要查找的商品为：\n");
		printf("编号\t品名\t生产厂家\t保质期\t\t进价\t\t售价\t\t进货量\n");
		printf("%s\t%s\t%s\t\t%s\t%f\t%f\t%d\n",
			p->number, p->name, p->manuFacturer, p->expirationData, p->bid, p->price, p->inAmount);
		printf("销售量\t销售额\t\t\t剩余数\t\t报销量\t\t毛利\n");
		printf("%d\t%f\t\t%d\t\t%d\t\t%f\n", p->outAmount, p->sell, p->residue, p->scrap, p->money);
	}
	else
	{
		printf("未找到相关信息！\n");
	}
}

void sortBymanuFacturer()
{
	goodsInfoLink *head, *q, *p;
	int flag = 1;
	char manuFacturer[20];
	head = createGoodsInfoLink();
	printf("请输入你想要查询的商品的生产厂家:");
	scanf("%s", manuFacturer);
	q = head->next;
	for (p = q; p != NULL; p = p->next)
	{
		if (strcmp(p->manuFacturer, manuFacturer) == 0)
		{
			flag = 0;
			p->money = (p->sell) - (p->bid)*(p->outAmount);
			printf("您想要查找的商品为：\n");
			printf("编号\t品名\t生产厂家\t保质期\t\t进价\t\t售价\t\t进货量\n");
			printf("%s\t%s\t%s\t\t%s\t%f\t%f\t%d\n",
				p->number, p->name, p->manuFacturer, p->expirationData, p->bid, p->price, p->inAmount);
			printf("销售量\t销售额\t\t\t剩余数\t\t报销量\t\t毛利\n");
			printf("%d\t%f\t\t%d\t\t%d\t\t%f\n", p->outAmount, p->sell, p->residue, p->scrap, p->money);
		}
	}
	if (flag)
	{
		printf("未找到相关信息!\n");
	}
}

void sortBySell()
{
	goodsInfoLink *head, *q, *p;
	int flag = 1;
	float sell;
	head = createGoodsInfoLink();
	printf("请输入你想要查询的商品的销售额:");
	scanf("%f", &sell);
	q = head->next;
	for (p = q; p != NULL; p = p->next)
	{
		if (p->sell == sell)
		{
			flag = 0;
			p->money = (p->sell) - (p->bid)*(p->outAmount);
			printf("您想要查找的商品为：\n");
			printf("编号\t品名\t生产厂家\t保质期\t\t进价\t\t售价\t\t进货量\n");
			printf("%s\t%s\t%s\t\t%s\t%f\t%f\t%d\n",
				p->number, p->name, p->manuFacturer, p->expirationData, p->bid, p->price, p->inAmount);
			printf("销售量\t销售额\t\t\t剩余数\t\t报销量\t\t毛利\n");
			printf("%d\t%f\t\t%d\t\t%d\t\t%f\n", p->outAmount, p->sell, p->residue, p->scrap, p->money);
		}
	}
	if (flag)
	{
		printf("未找到相关信息!\n");
	}
}

void sortByresidue()     //由于switch只能用于整形，因此使用if-else
{
	goodsInfoLink *head, *q, *p;
	char choice[2];
	int residue;
	printf("请选择条件(如> 20 或 < 5 以空格隔开)");
	scanf("%s %d", choice, &residue);
	int flag = 1;
	head = createGoodsInfoLink();
	if (strcmp(choice, ">"))
	{
		q = head->next;
		for (p = q; p != NULL; p = p->next)
		{
			if (p->residue > residue)
			{
				flag = 0;
				p->money = (p->sell) - (p->bid)*(p->outAmount);
				printf("您想要查找的商品为：\n");
				printf("编号\t品名\t生产厂家\t保质期\t\t进价\t\t售价\t\t进货量\n");
				printf("%s\t%s\t%s\t\t%s\t%f\t%f\t%d\n",
					p->number, p->name, p->manuFacturer, p->expirationData, p->bid, p->price, p->inAmount);
				printf("销售量\t销售额\t\t\t剩余数\t\t报销量\t\t毛利\n");
				printf("%d\t%f\t\t%d\t\t%d\t\t%f\n", p->outAmount, p->sell, p->residue, p->scrap, p->money);
			}
		}
		if (flag)
		{
			printf("未找到相关信息!\n");
		}
	}
	else if (strcmp(choice, "<"))
	{
		q = head->next;
		for (p = q; p != NULL; p = p->next)
		{
			if (p->residue < residue)
			{
				flag = 0;
				p->money = (p->sell) - (p->bid)*(p->outAmount);
				printf("您想要查找的商品为：\n");
				printf("编号\t品名\t生产厂家\t保质期\t\t进价\t\t售价\t\t进货量\n");
				printf("%s\t%s\t%s\t\t%s\t%f\t%f\t%d\n",
					p->number, p->name, p->manuFacturer, p->expirationData, p->bid, p->price, p->inAmount);
				printf("销售量\t销售额\t\t\t剩余数\t\t报销量\t\t毛利\n");
				printf("%d\t%f\t\t%d\t\t%d\t\t%f\n", p->outAmount, p->sell, p->residue, p->scrap, p->money);
			}
		}
		if (flag)
		{
			printf("未找到相关信息!\n");
		}
	}
}

void sortByExpirationData()
{
	goodsInfoLink *head, *q, *p;
	int flag = 1;
	char expirationData[20];
	head = createGoodsInfoLink();
	printf("请输入你想要查询的商品的保质期:");
	scanf("%s", expirationData);
	q = head->next;
	for (p = q; p != NULL; p = p->next)
	{
		if (strcmp(p->expirationData, expirationData) == 0)
		{
			flag = 0;
			p->money = (p->sell) - (p->bid)*(p->outAmount);
			printf("您想要查找的商品为：\n");
			printf("编号\t品名\t生产厂家\t保质期\t\t进价\t\t售价\t\t进货量\n");
			printf("%s\t%s\t%s\t\t%s\t%f\t%f\t%d\n",
				p->number, p->name, p->manuFacturer, p->expirationData, p->bid, p->price, p->inAmount);
			printf("销售量\t销售额\t\t\t剩余数\t\t报销量\t\t毛利\n");
			printf("%d\t%f\t\t%d\t\t%d\t\t%f\n", p->outAmount, p->sell, p->residue, p->scrap, p->money);
		}
	}
	if (flag)
	{
		printf("未找到相关信息!\n");
	}
}