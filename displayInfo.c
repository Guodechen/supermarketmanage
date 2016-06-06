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
	printf("���������ѡ��: ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		displayFormer();   //��ʾԭ����˳��
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
		printf("��������!");
		break;
	}
}

void menuDisplayInfo()
{
	printf("\t\t  ��ʾ��Ʒ��Ϣ\n");
	printf("\t\t1��ԭ����Ʒ˳����ʾ\n");
	printf("\t\t2�����۶�ߵ�����ʾ\n");
	printf("\t\t3��ë���ĸߵ�����ʾ\n");
	printf("\t\t4�������ڽ���Զ��ʾ\n");
	printf("\t\t0�������ϼ�\n");
}

void displayFormer()
{
	goodsInfoLink *head, *q, *p;
	head = createGoodsInfoLink();
	q = head->next;
	for (p = q; p != NULL; p = p->next)
	{
		p->money = (p->sell) - (p->bid)*(p->outAmount);
		printf("���\tƷ��\t��������\t������\t\t����\t\t�ۼ�\t\t������\n");
		printf("%s\t%s\t%s\t\t%s\t%f\t%f\t%d\n",
			p->number, p->name, p->manuFacturer, p->expirationData, p->bid, p->price, p->inAmount);
		printf("������\t���۶�\t\t\tʣ����\t\t������\t\të��\n");
		printf("%d\t%f\t\t%d\t\t%d\t\t%f\n\n\n", p->outAmount, p->sell, p->residue, p->scrap, p->money);
	}
}

void displaySell()
{
	goodsInfoLink *p, *head, *q = NULL, *r = NULL, *temp;
	head = createGoodsInfoLink();
	p = head->next;  //pָ���һ�����ݽڵ�
	temp = head;
	if (p != NULL)                                     //��������һ���������ϵ����ݽڵ�
	{
		r = p->next;                      //r ���� *p�ڵ��ֱ�Ӻ�̽ڵ��ָ��
		p->next = NULL;            //����ֻ����һ�����ݽڵ�������
		p = r;
		while (p != NULL)
		{
			r = p->next;                //r ����*p�ڵ��ֱ�Ӻ�̽ڵ��ָ��
			q = head;
			while (q->next != NULL && q->next->sell > p->sell)
				q = q->next;     //��������в��Ҳ���*p��ֱ��ǰ���ڵ�*q��λ��

			p->next = q->next;                   //��*p���뵽*q֮��
			q->next = p;
			p = r;                                //ɨ��ԭ���������µĽڵ�
		}
	}
	while (temp->next != NULL)
	{
		temp->next->money = (temp->next->sell) - (temp->next->bid)*(temp->next->outAmount);
		printf("���\tƷ��\t��������\t������\t\t����\t\t�ۼ�\t\t������\n");
		printf("%s\t%s\t%s\t\t%s\t%f\t%f\t%d\n",
			temp->next->number, temp->next->name, temp->next->manuFacturer, temp->next->expirationData, temp->next->bid, temp->next->price, temp->next->inAmount);
		printf("������\t���۶�\t\t\tʣ����\t\t������\t\të��\n");
		printf("%d\t%f\t\t%d\t\t%d\t\t%f\n\n\n", temp->next->outAmount, temp->next->sell, temp->next->residue, temp->next->scrap, temp->next->money);
		temp = temp->next;
	}
}

void displayMoney()
{
	goodsInfoLink *p, *head, *q = NULL, *r = NULL, *temp;
	head = createGoodsInfoLink();
	p = head->next;  //pָ���һ�����ݽڵ�
	temp = head;
	if (p != NULL)                                     //��������һ���������ϵ����ݽڵ�
	{
		r = p->next;                      //r ���� *p�ڵ��ֱ�Ӻ�̽ڵ��ָ��
		p->next = NULL;            //����ֻ����һ�����ݽڵ�������
		p = r;
		while (p != NULL)
		{
			r = p->next;                //r ����*p�ڵ��ֱ�Ӻ�̽ڵ��ָ��
			q = head;
			while (q->next != NULL && q->next->money > p->money)
			{
				q = q->next;     //��������в��Ҳ���*p��ֱ��ǰ���ڵ�*q��λ��
			}

			p->next = q->next;                   //��*p���뵽*q֮��
			q->next = p;
			p = r;                                //ɨ��ԭ���������µĽڵ�
		}
	}
	while (temp->next != NULL)
	{
		temp->next->money = (temp->next->sell) - (temp->next->bid)*(temp->next->outAmount);
		printf("���\tƷ��\t��������\t������\t\t����\t\t�ۼ�\t\t������\n");
		printf("%s\t%s\t%s\t\t%s\t%f\t%f\t%d\n",
			temp->next->number, temp->next->name, temp->next->manuFacturer, temp->next->expirationData, temp->next->bid, temp->next->price, temp->next->inAmount);
		printf("������\t���۶�\t\t\tʣ����\t\t������\t\të��\n");
		printf("%d\t%f\t\t%d\t\t%d\t\t%f\n\n\n", temp->next->outAmount, temp->next->sell, temp->next->residue, temp->next->scrap, temp->next->money);
		temp = temp->next;
	}
}

void displayExpirationData()
{
	goodsInfoLink *p, *head, *q = NULL, *r = NULL, *temp;
	head = createGoodsInfoLink();
	p = head->next;  //pָ���һ�����ݽڵ�
	temp = head;
	if (p != NULL)                                     //��������һ���������ϵ����ݽڵ�
	{
		r = p->next;                      //r ���� *p�ڵ��ֱ�Ӻ�̽ڵ��ָ��
		p->next = NULL;            //����ֻ����һ�����ݽڵ�������
		p = r;
		while (p != NULL)
		{
			r = p->next;                //r ����*p�ڵ��ֱ�Ӻ�̽ڵ��ָ��
			q = head;
			while (q->next != NULL && strcmp(q->next->expirationData, p->expirationData) < 0)//q->next->money > p->money
			{
				q = q->next;     //��������в��Ҳ���*p��ֱ��ǰ���ڵ�*q��λ��
			}

			p->next = q->next;                   //��*p���뵽*q֮��
			q->next = p;
			p = r;                                //ɨ��ԭ���������µĽڵ�
		}
	}
	while (temp->next != NULL)
	{
		temp->next->money = (temp->next->sell) - (temp->next->bid)*(temp->next->outAmount);
		printf("���\tƷ��\t��������\t������\t\t����\t\t�ۼ�\t\t������\n");
		printf("%s\t%s\t%s\t\t%s\t%f\t%f\t%d\n",
			temp->next->number, temp->next->name, temp->next->manuFacturer, temp->next->expirationData, temp->next->bid, temp->next->price, temp->next->inAmount);
		printf("������\t���۶�\t\t\tʣ����\t\t������\t\të��\n");
		printf("%d\t%f\t\t%d\t\t%d\t\t%f\n\n\n", temp->next->outAmount, temp->next->sell, temp->next->residue, temp->next->scrap, temp->next->money);
		temp = temp->next;
	}
}