#include"head.h"

void Menu();

int main()
{
	int choice;
	while (1)
	{
		system("title С�ͱ�������ҵ");
		Menu();
		printf("���������ѡ��");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			createInfo("w");
			system("pause");
			system("cls");
			break;
		case 2:
			editInfo();
			system("pause");
			system("cls");
			break;
		case 3:
			statisticsInfo();
			system("pause");
			system("cls");
			break;
		case 4:
			queryInfo();
			system("pause");
			system("cls");
			break;
		case 5:
			displayInfo();
			system("pause");
			system("cls");
			break;
		case 0:
			exit(1);
		default:
			printf("����������\n");
			break;
		}
	}
}

void Menu()
{
	printf("\t\t  �̵����ϵͳ\t\n\n");
	printf("\t\t1��������Ʒ����\n");
	printf("\t\t2���༭��Ʒ��Ϣ\n");
	printf("\t\t3��ͳ���������\n");
	printf("\t\t4����ѯ��Ʒ��Ϣ\n");
	printf("\t\t5����ʾ��Ʒ��Ϣ\n");
	printf("\t\t0���˳�\n");
}