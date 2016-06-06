#include"head.h"


void statisticsInfo()
{
	FILE * fp;
	goodsInfoLink *head, *p, *q;
	float money;
	if ((fp = fopen("goodsInfo.txt", "r")) == NULL)
	{
		printf("�ļ��򿪴���!\n");
		exit(0);
	}

	head = (goodsInfoLink *)malloc(sizeof(goodsInfoLink));
	p = head;
	while (!feof(fp))
	{

		q = (goodsInfoLink *)malloc(sizeof(goodsInfoLink));
		fscanf(fp, "%s\t%s\t%s\t%s\t%f\t%f\t%d\t%d\t%f\t%d\t%d\t%f\n",
			q->number, q->name, q->manuFacturer, q->expirationData, &q->bid, &q->price, &q->inAmount, &q->outAmount, &q->sell, &q->residue, &q->scrap, &q->money);

		p->next = q;
		p = q;

	}
	p->next = NULL;
	q = head->next;
	printf("��Ʒ\t��Ʒ���\t���۶�\t\tʣ����\të��\n");
	for (p = q; p != NULL; p = p->next)
	{
		p->residue = (p->inAmount) - (p->outAmount) - (p->scrap);
		money = (p->sell) - (p->bid)*(p->outAmount);
		printf("%s\t%s\t\t%f\t%d\t%f\n", p->name, p->number, p->sell, p->residue, money);
	}
}