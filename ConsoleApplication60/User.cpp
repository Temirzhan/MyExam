#include<stdlib.h>
#include<locale.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<iostream>
#include"UserKey.h"

FILE *pt;

void User_Login(int User_main, char *folder_user)
{
	UserLogin get_Login;   //������� ���������
	UserLogin *Login_Base=NULL; //���� �������

	short int point_userLogin = 0; //������� �� � ���� ����� � ������;
	short int point_userPassword = 0;

	int replay_login = 0;//������ ������� ����� ���������

	int account_login = 0; //����������� �������
	Login_Base = (UserLogin*)calloc(1, sizeof(UserLogin));

	if ((pt = fopen("Key\\key.txt", "rb")) != NULL)
	{
		while (fread((Login_Base + account_login), 1, sizeof(UserLogin), pt) != 0)
		{
			account_login++;
			Login_Base = (UserLogin*)realloc(Login_Base, sizeof(UserLogin)*(account_login + 1));
		}
	}
	fclose(pt);
	do
	{
		replay_login = 0;//������ ������� ����� ���������
		point_userLogin = 0;
		system("cls");
		printf("������� �����:");
		scanf("%s", get_Login.Login);
		printf("������� ������");
		scanf("%s", get_Login.pasword);

		for (int i = 0; i < account_login; i++)
		{
			if (strcmp((Login_Base + i)->Login, get_Login.Login) == 0)
			{
				point_userLogin = 1;
				if (strcmp((Login_Base + i)->pasword, get_Login.pasword) == 0)
				{
					point_userPassword = 1;
					break;
				}
			}
		}

		switch (User_main)
		{
		case 1:
		{
			system("cls");
			if (point_userLogin == 1)
			{
				printf("����� ����� ����������\n");
				system("pause");
				replay_login = 1;
			}
			else
			{
				if ((pt = fopen("Key\\key.txt", "ab+")) != NULL)
				{
					fwrite(&get_Login, 1, sizeof(UserLogin), pt);
				}
				fclose(pt);
				strcpy(folder_user, get_Login.Login);
				sprintf(folder_user, "User\\%s.txt", get_Login.Login);
				if ((pt = fopen(folder_user, "wb+")) != NULL)
				{
				}
				fclose(pt);
			}
		}
		break;
		case 2:
		{
			system("cls");
			if (point_userLogin == 1&&point_userPassword==1)
			{
				sprintf(folder_user, "User\\%s.txt", get_Login.Login);
			}
			else
			{
				printf("����� ��� ������ �� ������\n");
				system("pause");
				replay_login = 1;
			}
		}
		}
	} while (replay_login == 1);


}

