#include<stdlib.h>
#include<locale.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<iostream>
#include"admin.h"
#include"User.h"
#include"User_main.h"

#define key 1234
char Replay;//�������� ������� �����
void main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int section; //����� �������
	char folder[100]; //����� ���������� ����� �����
	do {
		system("cls");
		printf("*************����� ����������******************\n");
		printf("------------------------------------------------\n");
		printf("������� ����\n");
		printf("1-�����\n");
		printf("2-������������\n");
		printf("3-�����\n");
		printf("������� ���� ������� �������:");
		scanf("%d", &section);

		switch (section)
		{
		case 1:
		{ int key_admin;
		system("cls");
		printf("���������\"������ 1234\"\n");
		printf("������� ������:");
		scanf("%d", &key_admin);
		if (key_admin == key)
			Replay =admin_01();
		else {
			printf("������ ������ �� �����\n");
			Replay = 'y';
		     }
		}
		break;

		case 2:
		{
			int User_main;
			printf("1-������������������\n");
			printf("2-����\n");
			scanf("%d", &User_main);
			switch (User_main)
			{
			case 1:
			{
				User_Login(User_main, folder);
				User_Main(folder);
			}
			break;
			case 2:
			{
				User_Login(User_main, folder);
				User_Main(folder);
			}
			break;
			}
		}
		break;

		case 3:
		{
			exit(0);
		}
		break;

		default:
		{system("cls");
		printf("�� ��������� ������:\"�� ����� ������ ������\"\n");
		printf("----------------------------------------------\n");
		printf("������ ����� ����������� y-��\n");
		printf("�� ������������ � ������ ����� ������� \"ENTER\"\n");
		scanf("%c", &Replay);
		}
		}
	} while (Replay == 'y');
}
