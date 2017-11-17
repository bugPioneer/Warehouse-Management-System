#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

struct typeInfo
{
	char typeName[20];	//������������
	int goodsSum;	//�û������������еĻ�������
	int goodsNum;	//�û������������еĻ�����������
	struct goodsInfo
	{
		char goodsName[20];	//��������
		double price;	//����۸�
		int goodsCnt;	//��������
	}goods[100];
}type[100];

int typeNum = 0;	//������������
char password0[20] = "";


int display()	//��ʾ���������б�
{
	int i, j;
	char flag, name[20];
	system("cls");
	printf("\n\n\t��ӭ����������������ʾҳ�棺");
	if (typeNum == 0)
	{
		printf("\n\n\n\t\t��ǰϵͳ�޻������ͣ�");
		printf("\n\n\t\t�����������......");
		getch();
		return 0;
	}
	printf("\n\n\t\t________________________________________________________________");
	printf("\n\n\t\t\t\t\t���������б�");
	printf("\n\t\t________________________________________________________________\n");
	printf("\t\t                             |\n");
	printf("\t\t        ������������         |               %d\n", typeNum);
	printf("\t\t_____________________________|__________________________________\n");
	printf("\t\t                             |\n");
	printf("\t\t   �������������ƣ� ��������) |\n");
	for (i = 0; i < typeNum; i++)
		printf("\t\t                             |           %s��%d��\n", type[i].typeName, type[i].goodsSum);
	printf("\t\t_____________________________|__________________________________\n");
	printf("\n\n\t\t�����Ҫ�鿴ĳһ�����������µ���ϸ��Ϣ��������1�����������������");
	flag = getch();
	while (flag == '1')
	{
		printf("\n\n\t\t��������Ҫ�鿴�Ļ����������ƣ�");
		scanf("%s", name);
		for (i = 0; i < typeNum; i++)
			if (strcmp(type[i].typeName, name) == 0)
			{
				printf("\n\n\t\t________________________________________________________________");
				printf("\n\n\t\t\t\t\t����������ʾ�б�");
				printf("\n\t\t________________________________________________________________\n");
				printf("\t\t                            |\n");
				printf("\t\t   ��������(����)(�۸�)     |\n");
				for (j = 0; j < type[i].goodsNum; j++)
					printf("\t\t                            |         %s ( %d )( %.2fԪ )\n", type[i].goods[j].goodsName, type[i].goods[j].goodsCnt, type[i].goods[j].price);
				printf("\t\t____________________________|___________________________________\n");
				flag = '0';	//�ж��Ƿ���ڴ��ֻ�������
				break;
			}
		if (flag != '0')
			printf("\n\t\t�û������Ͳ����ڣ�\n");
		printf("\n\n\t\t��������鿴�������������µ���ϸ��Ϣ��������1�����������������");
		flag = getch();
	}
	return 0;
}

void add()	//���ӻ�������
{
	int i;
	char flag = '1';
	do {
		system("cls");
		printf("\n\n\t��ӭ���������ӻ�������ҳ�棺");
		printf("\n\n\t\t������������ͣ� ");
		scanf("%s", type[typeNum].typeName);
		type[typeNum].goodsSum = 0;
		type[typeNum].goodsNum = 0;
		for (i = 0; ; i++)
		{
			printf("\n\n\t\t������������ƣ� ");
			scanf("%s", type[typeNum].goods[i].goodsName);
			printf("\n\n\t\t���������۸� ");
			scanf("%lf", &type[typeNum].goods[i].price);
			printf("\n\n\t\t��������������� ");
			scanf("%d", &type[typeNum].goods[i].goodsCnt);
			type[typeNum].goodsNum++;
			type[typeNum].goodsSum += type[typeNum].goods[i].goodsCnt;	//�û������������еĻ��������ۼ�
			printf("\n\n\t������ӻ�������������1,������밴�����:");
			flag = getch();
			if (flag != '1')
				break;
		}
		typeNum++;	//�������������ۼ�
		printf("\n\n\t������ӻ�������������1,�����밴�����:");
		flag = getch();
	} while (flag == '1');
}

int del()	//ɾ����������
{
	int i, j, k;
	int flag = 0;
	char remove[20];
	system("cls");
	printf("\n\n\t��ӭ������ɾ����������ҳ�棺");
	if (typeNum == 0)
	{
		printf("\n\n\n\t\t��ǰϵͳ���κο�ɾ����¼��������ӻ��");
		printf("\n\n\t\t�����������......");
		getch();
		return 0;
	}
	printf("\n\n\t\t��������Ҫɾ���Ļ������ͣ�");
	scanf("%s", remove);
	for (i = 0; i < typeNum; i++)
		if (strcmp(type[i].typeName, remove) == 0)
		{
			flag = 1;
			for (j = i; j < typeNum; j++)
				type[j] = type[j + 1];
			typeNum--;
			printf("\n\t\tɾ���ɹ���");
			printf("\n\t\t�������������һ���˵�......");
			getch();
		}
	if (flag == 0)
	{
		printf("\n\n\t\t�Բ�������Ҫɾ���Ļ������Ͳ����ڣ����ʵ�����ԣ�\n");
		printf("\n\t\t�����������......");
		getch();
	}
	return 0;
}

void input()	//�������
{
	int i, j, flag, inputNum;
	char inputGoods[20];
	system("cls");
	printf("\n\n\t��ӭ�������������ҳ�棺");
	printf("\n\n\t\t�������������Ļ������ƣ�");
	scanf("%s", inputGoods);
	for (i = 0; i < typeNum; i++)
		for (j = 0; j < type[i].goodsNum; j++)
			if (strcmp(inputGoods, type[i].goods[j].goodsName) == 0)
			{
				flag = 1;
				printf("\n\n\t\t�������������Ļ���������");
				scanf("%d", &inputNum);
				printf("\n\n\t\t�������ɹ���");
				type[i].goods[j].goodsCnt += inputNum;
				type[i].goodsSum += inputNum;
				break;
			}
	if (flag != 1)
		printf("\n\n\tû�д˻���뷵����Ӵ��ֻ��");
	printf("\n\n\t����������ز˵�......");
	getch();
}

void output()	//�������
{
	int i, j, k, outputNum, flag;
	char outputGoods[20];
	system("cls");
	printf("\n\n\t��ӭ�������������ҳ��");
	printf("\n\n\t\t������Ҫ����Ļ������ƣ�");
	scanf("%s", outputGoods);
	for (i = 0; i < typeNum; i++)
		for (j = 0; j < type[i].goodsNum; j++)
			if (strcmp(outputGoods, type[i].goods[j].goodsName) == 0)
			{
				flag = 1;
				printf("\n\n\t\t������Ҫ����Ļ���������");
				scanf("%d", &outputNum);
				if (outputNum > type[i].goods[j].goodsCnt)
				{
					printf("\n\n\t������Ҫ�Ļ����治�㣬��ɹ����");
					break;
				}
				type[i].goods[j].goodsCnt -= outputNum;
				type[i].goodsSum -= outputNum;
				printf("\n\n\t\t�������ɹ���");
				break;
			}
	if (flag != 1)
		printf("\n\n\t������Ҫ�Ļ��ﲻ���ڣ��뷵����ӻ��");
	printf("\n\n\t����������ز˵�......");
	getch();
}

int show()	//�����ʾ
{
	int i, j, m, len;
	system("cls");
	printf("\n\n\t��ӭ�����������ʾҳ��");
	if (typeNum == 0)
	{
		printf("\n\n\n\t\t��ǰ���κο�棡");
		printf("\n\n\t\t�����������......");
		getch();
		return 0;
	}
	printf("\n\n\t\t________________________________________________________");
	printf("\n\n\t\t\t\t��������Ϣ\n");
	printf("\t\t________________________________________________________\n");
	printf("\t\t                       |\n");
	printf("\t\t        ��������       |       ��������(��������)\n");
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
	printf("\n\n\t\t��������ص����˵�......");
	getch();
	return 0;
}

void password()	//�������� 
{
	int flag;
	char password1[20], password2[20];
	do
	{
		system("cls");
		printf("\n\n\t��ӭ��ʹ�ñ�ϵͳ��\n\n\t�������ǵ�һ��ʹ�ã�Ϊ�����ݵİ�ȫ������������(����λ����5~10)��");
		printf("\n\n\t\t���������룺");
		scanf("%s", password1);
		printf("\n\n\t\t���ٴ��������룺");
		scanf("%s", password2);
		if (strcmp(password1, password2) != 0)
		{
			flag = 0;
			printf("\n\n\t��������������벻��ͬ�����������룡\n\n\t�����������......");
			getch();
		}
		else
		{
			flag = 1;
			strcpy(password0, password2);
		}
	} while (flag == 0);
}

int login()	//��½ 
{
	int flag;
	int changeNum = 3;
	char password3[20];
	do
	{
		system("cls");
		printf("\n\n\t\t(^v^)��ӭ����ʹ�ã� �����������齫������ǰ���ķ���(^v^)\n\n");
		printf("\t\t\t----------------> ��½ <---------------\n\n");
		printf("\t\t\t\t�������¼���룺");
		scanf("%s", password3);
		if (strcmp(password0, password3) == 0)
		{
			flag = 1;
			printf("\n\n\t\t\t\t��½�ɹ��������������......");
		}
		else
			printf("\n\n\t\t\t\t����������벻��ȷ!\n\t\t\t\t���棡������%d�ε�������ᣬ�����˳�ϵͳ��\n\t\t\t\t���������룡", --changeNum);
		if (changeNum == 0)
		{
			printf("\n\n\t\t\t\t�������������Ĵ����ѳ���3�ˣ�ϵͳ����5����˳���");
			Sleep(5000);
			system("cls");
			printf("\n\n\n\t\t�������������������������3�Σ�\n\n\t\t�ֲ��ܱ�֤����ʹ���߱��ˣ�\n\n\t\tΪ�����ݵİ�ȫ����ϵͳ���˳���\n\n");
			return 0;
		}
		getch();
	} while (flag != 1);
	return 1;
}

int writeData()	//�������� 
{
	FILE *fp;
	if ((fp = fopen("data.txt", "w")) == NULL)
	{
		printf("\n\n\t\t�ļ����ܴ򿪣�\n");
		return 0;
	}
	fwrite(type, sizeof(struct typeInfo), 100, fp);
	fwrite(&typeNum, sizeof(int), 1, fp);
	fwrite(password0, sizeof(char), 20, fp);
	fclose(fp);
	return 0;
}

int readData()	//��ȡ���� 
{
	FILE *fp;
	if ((fp = fopen("data.txt", "r")) == NULL)
	{
		printf("\n\n\t\t�ļ����ܴ򿪣�\n");
		return 0;
	}
	rewind(fp);
	fread(type, sizeof(struct typeInfo), 100, fp);
	fread(&typeNum, sizeof(int), 1, fp);
	fread(password0, sizeof(char), 20, fp);
	fclose(fp);
	return 0;
}

void menu()	//�˵� 
{
	char choice;
	int flag = 1;
	readData();	//��ȡ���� 
	if (strcmp(password0, "") == 0)
		password();
	else
		login();	//��½
					//writeData();
	do {
		system("cls");
		printf("\n\n\t\t(^v^)��ӭ����ʹ�ã� �����������齫������ǰ���ķ���(^v^)\n\n");
		printf("\t\t\t----------------> �˵� <---------------\n\n");
		printf("\t\t\t            1. ���������б�\n\n");
		printf("\t\t\t            2. ���ӻ�������\n\n");
		printf("\t\t\t            3. ɾ����������\n\n");
		printf("\t\t\t            4. �� ��  �� ��\n\n");
		printf("\t\t\t            5. �� ��  �� ��\n\n");
		printf("\t\t\t            6. �� ��  �� ʾ\n\n");
		printf("\t\t\t            7. ���ص�½����\n\n");
		printf("\t\t\t            0. �� ��  ϵ ͳ\n\n");
		printf("\t\t\t---------------------------------------\n\n");
		printf("\t\t����������ѡ��");
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
			printf("\n\n\t�������벻��ȷ������������!");
			printf("\n\t�����������......");
			getch();
		}
		}
		writeData();	//�������� 
	} while (flag == 1);
	system("cls");
	printf("\n\n\t\t(^v^)��л����ʹ�ã� ��ӭ���´�ʹ�ã�(^v^)\n\n");
}

int main(void)
{
	system("color 3a");
	menu();
	return 0;
}
