#include<stdlib.h>
#include<locale.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<iostream>
#include"StructPocition.h"


FILE *pt2;
char CreatingPosition()
{
	char NameofCCV[100];//���� ���� ����� ������

	int counter = 0;//������� ";"

	int counter_struct = 0;//����������� ��������
	int counter_pocition = 0;//����������� �������

	char checking_symbol[2];// �������� ������� � �����
	checking_symbol[1] = '\0';


	Pocition *NewPocition=NULL;
	NewPocition = (Pocition*)calloc(72, sizeof(Pocition));

	system("cls");

	printf("���� ��������\n");
	printf("�������� csv �����\n");
	printf("--------------------------\n");
	printf("���������� : ��� ��������� ����� ���������� ��������� ��� � ������ ����� \n");
	printf("--------------------------\n");
	printf("��������� ��� ������� ��� ����� \n");
	printf("��������:\"����.txt\"\n");
	scanf("%s", NameofCCV);

	if ((pt2 = fopen(NameofCCV, "r")) != NULL)
	{
		while ((checking_symbol[0] = getc(pt2)) != EOF)
		{
			if (checking_symbol[0] == ';')
			{
				counter++;
			}
			if (counter == 2)
			{
				while ((checking_symbol[0] = getc(pt2)) != ';')
				{
					strcat((NewPocition + counter_struct)->Name, checking_symbol);
				}
				while ((checking_symbol[0] = getc(pt2)) == ';' || counter == 5)
				{
					counter++;
				}
				while ((checking_symbol[0] = getc(pt2)) == ' ')
				{
					getc(pt2);
					while ((checking_symbol[0] = getc(pt2)) != ';')
					{
						(NewPocition + counter_struct)->pocition[counter_pocition].cod *= 10;
						(NewPocition + counter_struct)->pocition[counter_pocition].cod += atoi(checking_symbol);
					}
					while ((checking_symbol[0] = getc(pt2)) != ';')
					{
						strcat((NewPocition + counter_struct)->pocition[counter_pocition].Name, checking_symbol);
					}
					while ((checking_symbol[0] = getc(pt2)) != ';')
					{
						(NewPocition + counter_struct)->pocition[counter_pocition].price_1pc *= 10;
						(NewPocition + counter_struct)->pocition[counter_pocition].price_1pc += atoi(checking_symbol);
					}
					while ((checking_symbol[0] = getc(pt2)) != ';')
					{
						(NewPocition + counter_struct)->pocition[counter_pocition].price_wholesale *= 10;
						(NewPocition + counter_struct)->pocition[counter_pocition].price_wholesale += atoi(checking_symbol);
					}
					while (((checking_symbol[0] = getc(pt2)) != '\n'))
					{
							strcat((NewPocition + counter_struct)->pocition[counter_pocition].guarantee, checking_symbol);
					}
					counter_pocition++;
				}
				counter_pocition = 0;
				counter = 1;
				counter_struct++;
			}
		}
		fclose(pt2);
		if ((pt2 = fopen("Pocition\\Base.txt", "wb+")) != NULL)
		{
			fwrite(NewPocition, 72, sizeof(Pocition), pt2);
		}
		free(NewPocition);
		fclose(pt2);
		}
	return 'y';
	}

char DeletePosition()
{
	system("cls");
	int section;

	Pocition *NewPocition = NULL;
	NewPocition = (Pocition*)calloc(72, sizeof(Pocition));
	if ((pt2 = fopen("Pocition\\Base.txt", "rb+")) != NULL)
	{
		fread(NewPocition, 72, sizeof(Pocition), pt2);
	}

	fclose(pt2);

	printf("���� ��������\n");
	printf("-----------------\n");
	printf("1-������� 1 �������\n");
	printf("2-������� ���\n");
	printf("3-�����\n");
	scanf("%d", &section);

	switch (section)
	{
	case 1:
	{
		system("cls");
		int delete_01=0;
		printf("������� id ������� ������� ������ �������\n");
		scanf("%d", &delete_01);
		for (int i = 0; i < 72; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if ((NewPocition + i)->pocition[j].cod == delete_01)
				{
					strcpy((NewPocition + i)->Name, '\0');
					(NewPocition + i)->pocition[j].cod = 0;
					(NewPocition + i)->pocition[j].price_1pc = 0;
					(NewPocition + i)->pocition[j].price_wholesale = 0;
					strcpy((NewPocition + i)->pocition[j].guarantee, '\0');
					strcpy((NewPocition + i)->pocition[j].Name, '\0');
				}
			}
		}
	}
		break;
	case 2:
	{
		if ((pt2 = fopen("Pocition\\Base.txt", "wb+")) != NULL)
		{
		}
		free(NewPocition);
		fclose(pt2);
		return 'y';
	}
	break;
	case 3:
	{
		return 'y';
	}
	break;

	}
	if ((pt2 = fopen("Pocition\\Base.txt", "wb+")) != NULL)
	{
		fwrite(NewPocition, 72, sizeof(Pocition), pt2);
	}
	free(NewPocition);
	fclose(pt2);
	return'y';
}

char filing()
{
	system("cls");

	int counter_struct=0;
		int counter_pocition = 0;//����������� �������
		char symbol;

	Pocition *NewPocition = NULL;
	NewPocition = (Pocition*)calloc(72, sizeof(Pocition));

	if ((pt2 = fopen("Pocition\\Base.txt", "rb+")) != NULL)
	{
		fread(NewPocition, 72, sizeof(Pocition), pt2);
	}
	fclose(pt2);

	printf("���� ����������\n");
	printf("-----------------\n");
	printf("�������� �� ����� ������ ������ ��������� �����\n");

	for (int i = 0; i < 72; i++)
	{
		printf("%d - %s\n",i, (NewPocition + i));
	}
	printf("������� ���������\n");
	scanf("%d", &counter_struct);
	while ((NewPocition + counter_struct)->pocition[counter_pocition].cod!= 0)
	{
		counter_pocition= counter_pocition+1;
	}
	printf("%d ������� ����������, �������� %d ������", counter_pocition, 100 - counter_pocition);
	counter_pocition++;
	system("pause");
	for (counter_pocition; counter_pocition < 100; counter_pocition++)
	{
		system("cls");
		printf("���������� ����� �������\n");
		printf("������� id\n");
		scanf("%d",&(NewPocition + counter_struct)->pocition[counter_pocition].cod);
		printf("��������\n");
		scanf("%s", (NewPocition + counter_struct)->pocition[counter_pocition].Name);
		printf("���� ���������\n");
		scanf("%d", &(NewPocition + counter_struct)->pocition[counter_pocition].price_1pc);
		printf("���� �������\n");
		scanf("%d", (NewPocition + counter_struct)->pocition[counter_pocition].price_wholesale);
		printf("��������\n");
		scanf("%s", (NewPocition + counter_struct)->pocition[counter_pocition].guarantee);
		printf("���� ������ ����� ������� y\n");
		scanf("%c", symbol);
		if (symbol == 'y')
			break;
	}
	if ((pt2 = fopen("Pocition\\Base.txt", "wb+")) != NULL)
	{
		fwrite(NewPocition, 72, sizeof(Pocition), pt2);
	}
	free(NewPocition);
	fclose(pt2);
	return 'y';
}