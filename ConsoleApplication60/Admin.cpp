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
		printf("*************Добро Пожаловать Админ******************\n");
		printf("------------------------------------------------\n");
		printf("Главное меню админа:\n");
		printf("1-Создание\n");
		printf("2-Удадение\n");
		printf("3-Заполнение\n");
		printf("4-Вернуться назад\n");
		printf("5-Закрыть предложение\n");
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
		printf("Вы совершили ошибку:\"не верно введен формат\"\n");
		printf("----------------------------------------------\n");
		printf("Хотите снова попробовать \"y\"-да\n");
		printf("Вы разачерованы и хотите выйти нажмите \"ENTER\"\n");
		scanf("%c", &ReplayAdmin);
		}
		}
	} while (ReplayAdmin == 'y');
	return 0;
}