#include<stdlib.h>
#include<locale.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<iostream>
#include"CreatingPosition.h"

char ReplayAdmin;

char admin_01()
{
	int section;
	do {
		system("cls");
		printf("*************����� ���������� �����******************\n");
		printf("------------------------------------------------\n");
		printf("������� ���� ������:\n");
		printf("1-��������\n");
		printf("2-��������\n");
		printf("3-����������\n");
		printf("4-��������� �����\n");
		printf("5-������� �����������\n");
		scanf("%d", &section);
		switch (section)
		{
		case 1:
		{
			ReplayAdmin=CreatingPosition();
		}
		break;

		case 2:
		{
			ReplayAdmin=DeletePosition();
		}
		break;

		case 3:
		{
			ReplayAdmin=filing();
		}
		break;

		case 4:
		{
			return 'y';
		}
		break;

		case 5:
		{
			exit(0);
		}
		break;

		default:
		{system("cls");
		printf("�� ��������� ������:\"�� ����� ������ ������\"\n");
		printf("----------------------------------------------\n");
		printf("������ ����� ����������� \"y\"-��\n");
		printf("�� ������������ � ������ ����� ������� \"ENTER\"\n");
		scanf("%c", &ReplayAdmin);
		}
		}
	} while (ReplayAdmin == 'y');
	return 0;
}