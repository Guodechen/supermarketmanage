#include"head.h"

void createInfo(char way[3])
{
	goodsInfoLink *head,*q, *p;
	char code[20];
	int choice=1;
	printf("������\n��š�Ʒ�����������ҡ�������(0000/00/00)�����ۡ��ۼۡ���������������.(��#����)\n");
	head = (goodsInfoLink *)malloc(sizeof(goodsInfoLink));
	p = head;
	scanf("%s", code);
	while (1)
	{
		if (strcmp(code, "#") == 0)
			break;
		else
		{
			q = (goodsInfoLink *)malloc(sizeof(goodsInfoLink));
			strcpy(q->number, code);
			scanf("%s%s%s%f%f%d%d",
				q->name,q->manuFacturer,q->expirationData,&q->bid,&q->price,&q->inAmount,&q->outAmount);
			q->residue = (q->inAmount) - (q->outAmount);    //ʣ����	
			q->sell = (q->price)*(q->outAmount);			//���۶�
			q->scrap = 0;
			p->money = (p->sell) - (p->bid)*(p->outAmount);
			p->next = q;
			p = q;
		}
		scanf("%s", code);
	}
	q->next = NULL;
	printf("��Ϣ�������\n");
	getchar();
	printf("�Ƿ񱣴���Ϣ����1������ 2�������棩\n");
	scanf("%d", &choice);
	if (choice == 1)
		saveInfo(head,way);
	else
		printf("��Ϣû�б�����\n");
}

void saveInfo(goodsInfoLink *head, char way[3])
{
	FILE *fp;
	goodsInfoLink *p;
	if ((fp = fopen("goodsInfo.txt", way)) == NULL)
	{
		printf("�ļ���ʧ�ܣ���\n");
		exit(0);
	}
	for (p = head->next; p != NULL; p = p->next)
		fprintf(fp, "%s\t%s\t%s\t%s\t%f\t%f\t%d\t%d\t%f\t%d\t%d\t%f\n",
			p->number, p->name, p->manuFacturer, p->expirationData, p->bid, p->price, p->inAmount, p->outAmount, p->sell, p->residue,p->scrap,p->money);
	fclose(fp);
	printf("�ļ��ѱ��棡");
}