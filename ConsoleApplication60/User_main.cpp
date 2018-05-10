#include<stdlib.h>
#include<locale.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<iostream>
#include"StructPocition.h"
#include"User_Function.h"

FILE *pt3;
FILE *ptUser;
char ReplayUser;
char User_Main(char *folder_user)
{
	Pocition *PocitionBase = NULL;
	PocitionBase = (Pocition*)calloc(72, sizeof(Pocition));//БАза позиций

	int sort;

	if ((pt3 = fopen("Pocition\\Base.txt", "rb+")) != NULL)
	{
		fread(PocitionBase, 72, sizeof(Pocition), pt3);
	}
	int user_pocition = 0; //колличество позиций юзера
	int use_pocition_base = 0;//колличество order
	fclose(pt3);

	User_table *Base_User = NULL;
	Base_User = (User_table*)calloc(100, sizeof(User_table));
	if ((ptUser = fopen(folder_user, "rb+")) != NULL)
	{
		while (fread((Base_User + user_pocition), 1, sizeof(User_table), ptUser) != 0)
		{
			user_pocition++;
		}
	}
	fclose(ptUser);
	char User_Base_Folder[100];
	sprintf(User_Base_Folder, "UserBase\\%s", folder_user);


	User_table *Base_User_base = NULL;
	Base_User_base = (User_table*)calloc(1, sizeof(User_table));
	if ((ptUser = fopen(User_Base_Folder, "rb+")) != NULL)
	{
		while (fread((Base_User_base + use_pocition_base), 1, sizeof(User_table), ptUser) != 0)
		{
			use_pocition_base++;
			Base_User_base = (User_table*)realloc(Base_User_base, sizeof(User_table)*(use_pocition_base + 1));
		}
	}
	else 
	{
		fopen(User_Base_Folder, "wb+");
	}

	int section;
	fclose(ptUser);
	do {
		system("cls");
		printf("*************Добро Пожаловать User******************\n");
		printf("------------------------------------------------\n");
		printf("Главное меню Usera:\n");
		printf("1-распечатки прайс-листа\n");
		printf("2-сортировке элементов прайс-листа\n");
		printf("3-Оформление заказа\n");
		printf("4-Список товаров в корзине\n");
		printf("5-Список оформленных товаров\n");
		printf("6-Вернуться назад\n");
		printf("7-Закрыть предложение\n");
		scanf("%d", &section);
		switch (section)
		{
		case 1:
		{
			ReplayUser=	PrintPocition(PocitionBase, Base_User, &user_pocition,0);
		}
		break;

		case 2:
		{
			system("cls");
			printf("Выберите как вы хотите отсортировать\n");
			printf("1-цена по возрастанию\n");
			printf("2-цена по убыванию");
			scanf("%d", &sort);
			if (sort == 1 || sort == 2)
			{
				ReplayUser = PrintPocition(PocitionBase, Base_User, &user_pocition, sort);
			}
			else
			{
				printf("Упс вы что то сделали не то\n");
				system("pause");
				ReplayUser = 'y';
			}
		}
		break;

		case 3:
		{
			ReplayUser = User_Order(Base_User, &user_pocition, Base_User_base, &use_pocition_base);
		}
		break;

		case 4:
		{
			ReplayUser=User_Basket(Base_User, &user_pocition);
		}
		break;

		case 5:
		{
			User_Base_order(Base_User_base, &use_pocition_base);
		}
		break;

		

		case 6:
		{
			CloseBase(Base_User_base, &use_pocition_base, Base_User, &user_pocition, ptUser, User_Base_Folder, folder_user);
			return 'y';
		}
		break;

		case 7:
		{
			CloseBase(Base_User_base, &use_pocition_base, Base_User, &user_pocition, ptUser, User_Base_Folder, folder_user);
			exit(0);
		}
		break;

		default:
		{system("cls");
		printf("Вы совершили ошибку:\"не верно введен формат\"\n");
		printf("----------------------------------------------\n");
		printf("Хотите снова попробовать \"y\"-да\n");
		printf("Вы разачерованы и хотите выйти нажмите \"ENTER\"\n");
		scanf("%c", &ReplayUser);
		}
		}
	} while (ReplayUser == 'y');
	CloseBase(Base_User_base, &use_pocition_base, Base_User, &user_pocition, ptUser, User_Base_Folder, folder_user);
	return 'y';
}