#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

struct typeInfo
{
	char typeName[20];	//货物类型名称
	int goodsSum;	//该货物类型下已有的货物总数
	int goodsNum;	//该货物类型下已有的货物名称数量
	struct goodsInfo
	{
		char goodsName[20];	//货物名称
		double price;	//货物价格
		int goodsCnt;	//货物数量
	}goods[100];
}type[100];

int typeNum = 0;	//货物类型总数
char password0[20] = "";


int display()	//显示货物类型列表
{
	int i, j;
	char flag, name[20];
	system("cls");
	printf("\n\n\t欢迎您来到货物类型显示页面：");
	if (typeNum == 0)
	{
		printf("\n\n\n\t\t当前系统无货物类型！");
		printf("\n\n\t\t按任意键返回......");
		getch();
		return 0;
	}
	printf("\n\n\t\t________________________________________________________________");
	printf("\n\n\t\t\t\t\t货物类型列表");
	printf("\n\t\t________________________________________________________________\n");
	printf("\t\t                             |\n");
	printf("\t\t        货物类型总数         |               %d\n", typeNum);
	printf("\t\t_____________________________|__________________________________\n");
	printf("\t\t                             |\n");
	printf("\t\t   各货物类型名称（ 货物总数) |\n");
	for (i = 0; i < typeNum; i++)
		printf("\t\t                             |           %s（%d）\n", type[i].typeName, type[i].goodsSum);
	printf("\t\t_____________________________|__________________________________\n");
	printf("\n\n\t\t如果您要查看某一个货物类型下的详细信息，请输入1，否则按任意键继续：");
	flag = getch();
	while (flag == '1')
	{
		printf("\n\n\t\t请输入您要查看的货物类型名称：");
		scanf("%s", name);
		for (i = 0; i < typeNum; i++)
			if (strcmp(type[i].typeName, name) == 0)
			{
				printf("\n\n\t\t________________________________________________________________");
				printf("\n\n\t\t\t\t\t货物类型显示列表");
				printf("\n\t\t________________________________________________________________\n");
				printf("\t\t                            |\n");
				printf("\t\t   货物名称(数量)(价格)     |\n");
				for (j = 0; j < type[i].goodsNum; j++)
					printf("\t\t                            |         %s ( %d )( %.2f元 )\n", type[i].goods[j].goodsName, type[i].goods[j].goodsCnt, type[i].goods[j].price);
				printf("\t\t____________________________|___________________________________\n");
				flag = '0';	//判断是否存在此种货物类型
				break;
			}
		if (flag != '0')
			printf("\n\t\t该货物类型不存在！\n");
		printf("\n\n\t\t如果继续查看其他货物类型下的详细信息，请输入1，否则按任意键继续：");
		flag = getch();
	}
	return 0;
}

void add()	//增加货物类型
{
	int i;
	char flag = '1';
	do {
		system("cls");
		printf("\n\n\t欢迎您来到增加货物类型页面：");
		printf("\n\n\t\t请输入货物类型： ");
		scanf("%s", type[typeNum].typeName);
		type[typeNum].goodsSum = 0;
		type[typeNum].goodsNum = 0;
		for (i = 0; ; i++)
		{
			printf("\n\n\t\t请输入货物名称： ");
			scanf("%s", type[typeNum].goods[i].goodsName);
			printf("\n\n\t\t请输入货物价格： ");
			scanf("%lf", &type[typeNum].goods[i].price);
			printf("\n\n\t\t请输入货物数量： ");
			scanf("%d", &type[typeNum].goods[i].goodsCnt);
			type[typeNum].goodsNum++;
			type[typeNum].goodsSum += type[typeNum].goods[i].goodsCnt;	//该货物类型下已有的货物总数累加
			printf("\n\n\t继续添加货物名称请输入1,不添加请按任意键:");
			flag = getch();
			if (flag != '1')
				break;
		}
		typeNum++;	//货物类型总数累加
		printf("\n\n\t继续添加货物类型请输入1,返回请按任意键:");
		flag = getch();
	} while (flag == '1');
}

int del()	//删除货物类型
{
	int i, j, k;
	int flag = 0;
	char remove[20];
	system("cls");
	printf("\n\n\t欢迎您来到删除货物类型页面：");
	if (typeNum == 0)
	{
		printf("\n\n\n\t\t当前系统无任何可删除记录，请先添加货物！");
		printf("\n\n\t\t按任意键返回......");
		getch();
		return 0;
	}
	printf("\n\n\t\t请输入您要删除的货物类型：");
	scanf("%s", remove);
	for (i = 0; i < typeNum; i++)
		if (strcmp(type[i].typeName, remove) == 0)
		{
			flag = 1;
			for (j = i; j < typeNum; j++)
				type[j] = type[j + 1];
			typeNum--;
			printf("\n\t\t删除成功！");
			printf("\n\t\t按任意键返回上一级菜单......");
			getch();
		}
	if (flag == 0)
	{
		printf("\n\n\t\t对不起，你所要删除的货物类型不存在，请核实后重试！\n");
		printf("\n\t\t按任意键继续......");
		getch();
	}
	return 0;
}

void input()	//货物入库
{
	int i, j, flag, inputNum;
	char inputGoods[20];
	system("cls");
	printf("\n\n\t欢迎您来到货物入库页面：");
	printf("\n\n\t\t请输入所需入库的货物名称：");
	scanf("%s", inputGoods);
	for (i = 0; i < typeNum; i++)
		for (j = 0; j < type[i].goodsNum; j++)
			if (strcmp(inputGoods, type[i].goods[j].goodsName) == 0)
			{
				flag = 1;
				printf("\n\n\t\t请输入所需入库的货物数量：");
				scanf("%d", &inputNum);
				printf("\n\n\t\t货物入库成功！");
				type[i].goods[j].goodsCnt += inputNum;
				type[i].goodsSum += inputNum;
				break;
			}
	if (flag != 1)
		printf("\n\n\t没有此货物，请返回添加此种货物！");
	printf("\n\n\t按任意键返回菜单......");
	getch();
}

void output()	//货物出库
{
	int i, j, k, outputNum, flag;
	char outputGoods[20];
	system("cls");
	printf("\n\n\t欢迎您来到货物入库页面");
	printf("\n\n\t\t请输入要出库的货物名称：");
	scanf("%s", outputGoods);
	for (i = 0; i < typeNum; i++)
		for (j = 0; j < type[i].goodsNum; j++)
			if (strcmp(outputGoods, type[i].goods[j].goodsName) == 0)
			{
				flag = 1;
				printf("\n\n\t\t请输入要出库的货物数量：");
				scanf("%d", &outputNum);
				if (outputNum > type[i].goods[j].goodsCnt)
				{
					printf("\n\n\t您所需要的货物库存不足，请采购货物！");
					break;
				}
				type[i].goods[j].goodsCnt -= outputNum;
				type[i].goodsSum -= outputNum;
				printf("\n\n\t\t货物出库成功！");
				break;
			}
	if (flag != 1)
		printf("\n\n\t您所需要的货物不存在，请返回添加货物！");
	printf("\n\n\t按任意键返回菜单......");
	getch();
}

int show()	//库存显示
{
	int i, j, m, len;
	system("cls");
	printf("\n\n\t欢迎您来到库存显示页面");
	if (typeNum == 0)
	{
		printf("\n\n\n\t\t当前无任何库存！");
		printf("\n\n\t\t按任意键返回......");
		getch();
		return 0;
	}
	printf("\n\n\t\t________________________________________________________");
	printf("\n\n\t\t\t\t货物库存信息\n");
	printf("\t\t________________________________________________________\n");
	printf("\t\t                       |\n");
	printf("\t\t        货物类型       |       货物名称(货物数量)\n");
	printf("\t\t_______________________|________________________________\n");
	for (i = 0; i < typeNum; i++)
	{
		len = 14 - strlen(type[i].typeName);
		printf("\t\t%10s", type[i].typeName);
		for (m = 0; m < len; m++)
			printf(" ");
		printf("|\n");
		for (j = 0; j < type[i].goodsNum; j++)
		{
			if (j < type[i].goodsNum - 1)
			{
				printf("\t\t                       |%14s  ( %d )\n", type[i].goods[j].goodsName, type[i].goods[j].goodsCnt);
				printf("\t\t                       |________________________________\n");
				printf("\t\t                       |\n");
			}
			if (j == type[i].goodsNum - 1)
			{
				printf("\t\t                       |%14s  ( %d )\n", type[i].goods[j].goodsName, type[i].goods[j].goodsCnt);
				printf("\t\t_______________________|________________________________\n");
			}
		}
	}
	printf("\n\n\t\t按任意键回到主菜单......");
	getch();
	return 0;
}

void password()	//设置密码 
{
	int flag;
	char password1[20], password2[20];
	do
	{
		system("cls");
		printf("\n\n\t欢迎您使用本系统！\n\n\t由于您是第一次使用，为了数据的安全请您设置密码(密码位数：5~10)！");
		printf("\n\n\t\t请输入密码：");
		scanf("%s", password1);
		printf("\n\n\t\t请再次输入密码：");
		scanf("%s", password2);
		if (strcmp(password1, password2) != 0)
		{
			flag = 0;
			printf("\n\n\t您两次输入的密码不相同，请重新输入！\n\n\t按任意键继续......");
			getch();
		}
		else
		{
			flag = 1;
			strcpy(password0, password2);
		}
	} while (flag == 0);
}

int login()	//登陆 
{
	int flag;
	int changeNum = 3;
	char password3[20];
	do
	{
		system("cls");
		printf("\n\n\t\t(^v^)欢迎您的使用！ 您的完美体验将是我们前进的方向(^v^)\n\n");
		printf("\t\t\t----------------> 登陆 <---------------\n\n");
		printf("\t\t\t\t请输入登录密码：");
		scanf("%s", password3);
		if (strcmp(password0, password3) == 0)
		{
			flag = 1;
			printf("\n\n\t\t\t\t登陆成功，按任意键继续......");
		}
		else
			printf("\n\n\t\t\t\t您输入的密码不正确!\n\t\t\t\t警告！您还有%d次的输入机会，否则将退出系统！\n\t\t\t\t请重型输入！", --changeNum);
		if (changeNum == 0)
		{
			printf("\n\n\t\t\t\t您输入错误密码的次数已超过3此！系统将在5秒后退出！");
			Sleep(5000);
			system("cls");
			printf("\n\n\n\t\t由于您输入错误的密码次数超过3次！\n\n\t\t现不能保证您是使用者本人！\n\n\t\t为了数据的安全现在系统已退出！\n\n");
			return 0;
		}
		getch();
	} while (flag != 1);
	return 1;
}

int writeData()	//保存数据 
{
	FILE *fp;
	if ((fp = fopen("data.txt", "w")) == NULL)
	{
		printf("\n\n\t\t文件不能打开！\n");
		return 0;
	}
	fwrite(type, sizeof(struct typeInfo), 100, fp);
	fwrite(&typeNum, sizeof(int), 1, fp);
	fwrite(password0, sizeof(char), 20, fp);
	fclose(fp);
	return 0;
}

int readData()	//读取数据 
{
	FILE *fp;
	if ((fp = fopen("data.txt", "r")) == NULL)
	{
		printf("\n\n\t\t文件不能打开！\n");
		return 0;
	}
	rewind(fp);
	fread(type, sizeof(struct typeInfo), 100, fp);
	fread(&typeNum, sizeof(int), 1, fp);
	fread(password0, sizeof(char), 20, fp);
	fclose(fp);
	return 0;
}

void menu()	//菜单 
{
	char choice;
	int flag = 1;
	readData();	//读取数据 
	if (strcmp(password0, "") == 0)
		password();
	else
		login();	//登陆
					//writeData();
	do {
		system("cls");
		printf("\n\n\t\t(^v^)欢迎您的使用！ 您的完美体验将是我们前进的方向(^v^)\n\n");
		printf("\t\t\t----------------> 菜单 <---------------\n\n");
		printf("\t\t\t            1. 货物类型列表\n\n");
		printf("\t\t\t            2. 增加货物类型\n\n");
		printf("\t\t\t            3. 删除货物类型\n\n");
		printf("\t\t\t            4. 货 物  入 库\n\n");
		printf("\t\t\t            5. 货 物  出 库\n\n");
		printf("\t\t\t            6. 库 存  显 示\n\n");
		printf("\t\t\t            7. 返回登陆界面\n\n");
		printf("\t\t\t            0. 退 出  系 统\n\n");
		printf("\t\t\t---------------------------------------\n\n");
		printf("\t\t请输入您的选择：");
		choice = getch();
		switch (choice)
		{
		case '1':display(); break;
		case '2':add(); break;
		case '3':del(); break;
		case '4':input(); break;
		case '5':output(); break;
		case '6':show(); break;
		case '7':flag = login(); break;
		case '0':flag = 0; break;
		default:
		{
			printf("\n\n\t您的输入不正确，请重新输入!");
			printf("\n\t按任意键继续......");
			getch();
		}
		}
		writeData();	//保存数据 
	} while (flag == 1);
	system("cls");
	printf("\n\n\t\t(^v^)感谢您的使用！ 欢迎您下次使用！(^v^)\n\n");
}

int main(void)
{
	system("color 3a");
	menu();
	return 0;
}
