#include"head.h"

void Menu();

int main()
{
	int choice;
	while (1)
	{
		system("title 小贤笨蛋的作业");
		Menu();
		printf("请输入你的选择：");
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
			printf("请重新输入\n");
			break;
		}
	}
}

void Menu()
{
	printf("\t\t  商店管理系统\t\n\n");
	printf("\t\t1、创建商品档案\n");
	printf("\t\t2、编辑商品信息\n");
	printf("\t\t3、统计销售情况\n");
	printf("\t\t4、查询商品信息\n");
	printf("\t\t5、显示商品信息\n");
	printf("\t\t0、退出\n");
}