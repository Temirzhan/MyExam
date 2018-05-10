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
char Replay;//Проверка повтора цикла
void main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int section; //выбор раздела
	char folder[100]; //Место нахождения папки Усера
	do {
		system("cls");
		printf("*************Добро Пожаловать******************\n");
		printf("------------------------------------------------\n");
		printf("Главное меню\n");
		printf("1-Админ\n");
		printf("2-Пользователь\n");
		printf("3-выйти\n");
		printf("Введите свой уровень доступа:");
		scanf("%d", &section);

		switch (section)
		{
		case 1:
		{ int key_admin;
		system("cls");
		printf("Подсказка\"Пароль 1234\"\n");
		printf("Введите пароль:");
		scanf("%d", &key_admin);
		if (key_admin == key)
			Replay =admin_01();
		else {
			printf("Пароль введен не верно\n");
			Replay = 'y';
		     }
		}
		break;

		case 2:
		{
			int User_main;
			printf("1-Зарегестрироваться\n");
			printf("2-Вход\n");
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
		printf("Вы совершили ошибку:\"не верно введен формат\"\n");
		printf("----------------------------------------------\n");
		printf("Хотите снова попробовать y-да\n");
		printf("Вы разачерованы и хотите выйти нажмите \"ENTER\"\n");
		scanf("%c", &Replay);
		}
		}
	} while (Replay == 'y');
}
