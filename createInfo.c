#include"head.h"

void createInfo(char way[3])
{
	goodsInfoLink *head,*q, *p;
	char code[20];
	int choice=1;
	printf("请输入\n编号、品名、生产厂家、保质期(0000/00/00)、进价、售价、进货量、销售量.(以#结束)\n");
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
			q->residue = (q->inAmount) - (q->outAmount);    //剩余数	
			q->sell = (q->price)*(q->outAmount);			//销售额
			q->scrap = 0;
			p->money = (p->sell) - (p->bid)*(p->outAmount);
			p->next = q;
			p = q;
		}
		scanf("%s", code);
	}
	q->next = NULL;
	printf("信息输入结束\n");
	getchar();
	printf("是否保存信息？（1、保存 2、不保存）\n");
	scanf("%d", &choice);
	if (choice == 1)
		saveInfo(head,way);
	else
		printf("信息没有被保存\n");
}

void saveInfo(goodsInfoLink *head, char way[3])
{
	FILE *fp;
	goodsInfoLink *p;
	if ((fp = fopen("goodsInfo.txt", way)) == NULL)
	{
		printf("文件打开失败！！\n");
		exit(0);
	}
	for (p = head->next; p != NULL; p = p->next)
		fprintf(fp, "%s\t%s\t%s\t%s\t%f\t%f\t%d\t%d\t%f\t%d\t%d\t%f\n",
			p->number, p->name, p->manuFacturer, p->expirationData, p->bid, p->price, p->inAmount, p->outAmount, p->sell, p->residue,p->scrap,p->money);
	fclose(fp);
	printf("文件已保存！");
}