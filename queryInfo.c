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
	printf("���������ѡ��:");
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
		printf("������Ϣ����");
		break;
	}
}

void menuQueryInfo()
{
	printf("\t\t  ��ѯ��Ʒ��Ϣ\n");
	printf("\t\t1��������Ʒ��\n");
	printf("\t\t2��������������\n");
	printf("\t\t3���������۶�\n");
	printf("\t\t4������ʣ����\n");
	printf("\t\t5�����ݱ�����\n");
	printf("\t\t0�������ϼ�\n");
}


void sortByName()
{
	goodsInfoLink *head, *q, *p;
	char name[20];
	head = createGoodsInfoLink();
	printf("����������Ҫ��ѯ����Ʒ����:");
	scanf("%s", name);
	q = head->next;
	for (p = q; p != NULL&&strcmp(p->name, name); p = p->next);
	if (p != NULL)
	{
		p->money = (p->sell) - (p->bid)*(p->outAmount);
		printf("����Ҫ���ҵ���ƷΪ��\n");
		printf("���\tƷ��\t��������\t������\t\t����\t\t�ۼ�\t\t������\n");
		printf("%s\t%s\t%s\t\t%s\t%f\t%f\t%d\n",
			p->number, p->name, p->manuFacturer, p->expirationData, p->bid, p->price, p->inAmount);
		printf("������\t���۶�\t\t\tʣ����\t\t������\t\të��\n");
		printf("%d\t%f\t\t%d\t\t%d\t\t%f\n", p->outAmount, p->sell, p->residue, p->scrap, p->money);
	}
	else
	{
		printf("δ�ҵ������Ϣ��\n");
	}
}

void sortBymanuFacturer()
{
	goodsInfoLink *head, *q, *p;
	int flag = 1;
	char manuFacturer[20];
	head = createGoodsInfoLink();
	printf("����������Ҫ��ѯ����Ʒ����������:");
	scanf("%s", manuFacturer);
	q = head->next;
	for (p = q; p != NULL; p = p->next)
	{
		if (strcmp(p->manuFacturer, manuFacturer) == 0)
		{
			flag = 0;
			p->money = (p->sell) - (p->bid)*(p->outAmount);
			printf("����Ҫ���ҵ���ƷΪ��\n");
			printf("���\tƷ��\t��������\t������\t\t����\t\t�ۼ�\t\t������\n");
			printf("%s\t%s\t%s\t\t%s\t%f\t%f\t%d\n",
				p->number, p->name, p->manuFacturer, p->expirationData, p->bid, p->price, p->inAmount);
			printf("������\t���۶�\t\t\tʣ����\t\t������\t\të��\n");
			printf("%d\t%f\t\t%d\t\t%d\t\t%f\n", p->outAmount, p->sell, p->residue, p->scrap, p->money);
		}
	}
	if (flag)
	{
		printf("δ�ҵ������Ϣ!\n");
	}
}

void sortBySell()
{
	goodsInfoLink *head, *q, *p;
	int flag = 1;
	float sell;
	head = createGoodsInfoLink();
	printf("����������Ҫ��ѯ����Ʒ�����۶�:");
	scanf("%f", &sell);
	q = head->next;
	for (p = q; p != NULL; p = p->next)
	{
		if (p->sell == sell)
		{
			flag = 0;
			p->money = (p->sell) - (p->bid)*(p->outAmount);
			printf("����Ҫ���ҵ���ƷΪ��\n");
			printf("���\tƷ��\t��������\t������\t\t����\t\t�ۼ�\t\t������\n");
			printf("%s\t%s\t%s\t\t%s\t%f\t%f\t%d\n",
				p->number, p->name, p->manuFacturer, p->expirationData, p->bid, p->price, p->inAmount);
			printf("������\t���۶�\t\t\tʣ����\t\t������\t\të��\n");
			printf("%d\t%f\t\t%d\t\t%d\t\t%f\n", p->outAmount, p->sell, p->residue, p->scrap, p->money);
		}
	}
	if (flag)
	{
		printf("δ�ҵ������Ϣ!\n");
	}
}

void sortByresidue()     //����switchֻ���������Σ����ʹ��if-else
{
	goodsInfoLink *head, *q, *p;
	char choice[2];
	int residue;
	printf("��ѡ������(��> 20 �� < 5 �Կո����)");
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
				printf("����Ҫ���ҵ���ƷΪ��\n");
				printf("���\tƷ��\t��������\t������\t\t����\t\t�ۼ�\t\t������\n");
				printf("%s\t%s\t%s\t\t%s\t%f\t%f\t%d\n",
					p->number, p->name, p->manuFacturer, p->expirationData, p->bid, p->price, p->inAmount);
				printf("������\t���۶�\t\t\tʣ����\t\t������\t\të��\n");
				printf("%d\t%f\t\t%d\t\t%d\t\t%f\n", p->outAmount, p->sell, p->residue, p->scrap, p->money);
			}
		}
		if (flag)
		{
			printf("δ�ҵ������Ϣ!\n");
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
				printf("����Ҫ���ҵ���ƷΪ��\n");
				printf("���\tƷ��\t��������\t������\t\t����\t\t�ۼ�\t\t������\n");
				printf("%s\t%s\t%s\t\t%s\t%f\t%f\t%d\n",
					p->number, p->name, p->manuFacturer, p->expirationData, p->bid, p->price, p->inAmount);
				printf("������\t���۶�\t\t\tʣ����\t\t������\t\të��\n");
				printf("%d\t%f\t\t%d\t\t%d\t\t%f\n", p->outAmount, p->sell, p->residue, p->scrap, p->money);
			}
		}
		if (flag)
		{
			printf("δ�ҵ������Ϣ!\n");
		}
	}
}

void sortByExpirationData()
{
	goodsInfoLink *head, *q, *p;
	int flag = 1;
	char expirationData[20];
	head = createGoodsInfoLink();
	printf("����������Ҫ��ѯ����Ʒ�ı�����:");
	scanf("%s", expirationData);
	q = head->next;
	for (p = q; p != NULL; p = p->next)
	{
		if (strcmp(p->expirationData, expirationData) == 0)
		{
			flag = 0;
			p->money = (p->sell) - (p->bid)*(p->outAmount);
			printf("����Ҫ���ҵ���ƷΪ��\n");
			printf("���\tƷ��\t��������\t������\t\t����\t\t�ۼ�\t\t������\n");
			printf("%s\t%s\t%s\t\t%s\t%f\t%f\t%d\n",
				p->number, p->name, p->manuFacturer, p->expirationData, p->bid, p->price, p->inAmount);
			printf("������\t���۶�\t\t\tʣ����\t\t������\t\të��\n");
			printf("%d\t%f\t\t%d\t\t%d\t\t%f\n", p->outAmount, p->sell, p->residue, p->scrap, p->money);
		}
	}
	if (flag)
	{
		printf("δ�ҵ������Ϣ!\n");
	}
}