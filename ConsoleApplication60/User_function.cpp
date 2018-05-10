#include<stdlib.h>
#include<locale.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<iostream>
#include"StructPocition.h"

int replay_function;

void Sort_Base(Pocition *PocitionBase,const int counter_struct, const int counter_pocition,const int sort)
{
	table temp;
	for (int i = 0; i < counter_pocition - 1; i++)
	{
		for (int j =counter_pocition- 1; j > i; j--)
		{
			if (sort == 1)
			{
				if ((PocitionBase + counter_struct)->pocition[j].price_1pc < (PocitionBase + counter_struct)->pocition[j - 1].price_1pc)
				{
             temp=(PocitionBase + counter_struct)->pocition[j];
			 (PocitionBase + counter_struct)->pocition[j] = (PocitionBase + counter_struct)->pocition[j - 1];
			 (PocitionBase + counter_struct)->pocition[j - 1] = temp;
				}
			}

			if (sort == 2)
			{
				if ((PocitionBase + counter_struct)->pocition[j].price_1pc > (PocitionBase + counter_struct)->pocition[j - 1].price_1pc)
				{
					temp = (PocitionBase + counter_struct)->pocition[j];
					(PocitionBase + counter_struct)->pocition[j] = (PocitionBase + counter_struct)->pocition[j - 1];
					(PocitionBase + counter_struct)->pocition[j - 1] = temp;
				}
			}
		}
	}
}
char PrintPocition(Pocition *PocitionBase, User_table *User_base, int *user_pocition,const int sort)
{
	int counter_struct=0;
	int counter_pocition = 0;
	int pocition;

	do {

		system("cls");

		for (int i = 0; i < 72; i++)
		{
			printf("%d - %s\n", i, (PocitionBase + i));
		}

		printf("Введите категорию\n");

		scanf("%d", &counter_struct);
		while ((PocitionBase + counter_struct)->pocition[counter_pocition].cod != 0)
		{
			counter_pocition++;
		}
		if (sort == 1 || sort == 2)
		{
		
			Sort_Base(PocitionBase, counter_struct,counter_pocition, sort);
		}
			system("cls");
		printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("|Номер  id |Наименование Товара                                                                                  |Цена за 1 штуку|Цена оптовая|гарантия|\n");
		printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");

		for(int i=0;i<counter_pocition;i++)
		{
			printf("|%9d|%-110s|%15d|%15d|%-8s|\n",(PocitionBase + counter_struct)->pocition[i].cod, (PocitionBase + counter_struct)->pocition[i].Name,
				(PocitionBase + counter_struct)->pocition[i].price_1pc, (PocitionBase + counter_struct)->pocition[i].price_wholesale, (PocitionBase + counter_struct)->pocition[i].guarantee);
		}

		do {


		printf("введите номер позици которую нужно поместить в корзину\n");
		printf("Если не хотите добовлять ничего просто введите 0\n");
		scanf("%d", &pocition);

		if (pocition != 0)
		{
			for (int i = 0; i < counter_pocition; i++)
			{
				if (pocition == (PocitionBase + counter_struct)->pocition[i].cod)
				{
					(User_base + *user_pocition)->cod = (PocitionBase + counter_struct)->pocition[i].cod;
					strcpy((User_base + *user_pocition)->Name, (PocitionBase + counter_struct)->pocition[i].Name);
					strcpy((User_base + *user_pocition)->guarantee, (PocitionBase + counter_struct)->pocition[i].guarantee);
					printf("Введите колличество данного товара для покупки\n");
					scanf("%d", &(User_base + *user_pocition)->pcs);
					if ((User_base + *user_pocition)->pcs > 10)
					{
						(User_base + *user_pocition)->price = (PocitionBase + counter_struct)->pocition[i].price_wholesale;
						(User_base + *user_pocition)->counter_sell = (User_base + *user_pocition)->price*(User_base + *user_pocition)->pcs;
						*user_pocition = *user_pocition + 1;
						break;
					}
					else
					{
						(User_base + *user_pocition)->price = (PocitionBase + counter_struct)->pocition[i].price_1pc;
						(User_base + *user_pocition)->counter_sell = (User_base + *user_pocition)->price*(User_base + *user_pocition)->pcs;
						*user_pocition = *user_pocition + 1;
						break;
					}
				}
			}
		}
		printf("Хотите продолжить выберать товар из этой группы выберите\"1\"\n");
		printf("Хотите вообще сменить группу выберите\"2\"\n");
		printf("Хотите покинуть этот раздел введите 3\n");
		scanf("%d", &replay_function);
		counter_pocition = 0;
		} while (replay_function == 1);

	} while (replay_function==2);

	return 'y';
}

FILE *pt5;
char User_Order(User_table *User_base, int *user_pocition, User_table *User_order, int *user_pocition_order)
{
	system("cls");
	char Order_Folder[100];
	char Order_Folder_NAme[100];
	int count_summ = 0;
	printf("Введите адрес папки куда сохранить ваш Ордер\n");
	printf("Формат вашего пути должен быть как в примере\n");
	printf("D:\\\\Новая папка\\\\имя файла\n");
	scanf("%s", Order_Folder);
	sprintf(Order_Folder_NAme, "%s.txt", Order_Folder);
	if ((pt5 = fopen(Order_Folder_NAme, "w+"))!=NULL)
	{
		fprintf(pt5,"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		fprintf(pt5, "|Номер  id |Наименование Товара                                                                                  |Цена за 1 штуку|Общее колличество| Общая цена|гарантия|\n");
		fprintf(pt5, "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		for (int i = 0; i<*user_pocition; i++)
		{
			fprintf(pt5,"|%10d|%-110s|%15d|%18d|%11d|%-8s|\n", (User_base+i)->cod, (User_base + i)->Name,
				(User_base + i)->price, (User_base + i)->pcs, (User_base + i)->counter_sell, (User_base + i)->guarantee);
			count_summ += (User_base + i)->counter_sell;
			*(User_order + *user_pocition_order) = *(User_base + i);
			*user_pocition_order++;
		}
		fprintf(pt5, "Общая сумма = %d\n", count_summ);
		
		fprintf(pt5, "Поставка на завтра в первой половине дня (до 12:00)");

	}
	fclose(pt5);
	User_base = NULL;
	*user_pocition = 0;
	system("pause");
	return 'y';
}

char User_Basket(User_table *User_base, int *user_pocition)
{
	system("cls");
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|Номер  id |Наименование Товара                                                                                  |Цена за 1 штуку|Общее колличество| Общая цена|гарантия|\n");
	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i<*user_pocition; i++)
	{
		printf("|%10d|%-110s|%15d|%18d|%11d|%-8s|\n", (User_base + i)->cod, (User_base + i)->Name,
			(User_base + i)->price, (User_base + i)->pcs, (User_base + i)->counter_sell, (User_base + i)->guarantee);

	}
	system("pause");
	return 'y';
}

char User_Base_order(User_table *User_base, int *user_pocition_order)
{
	system("cls");
	printf("История ваших заказов\n");
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|Номер  id |Наименование Товара                                                                                  |Цена за 1 штуку|Общее колличество| Общая цена|гарантия|\n");
	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i<*user_pocition_order; i++)
	{
		printf("|%10d|%-110s|%15d|%18d|%11d|%-8s|\n", (User_base + i)->cod, (User_base + i)->Name,
			(User_base + i)->price, (User_base + i)->pcs, (User_base + i)->counter_sell, (User_base + i)->guarantee);

	}
	system("pause");
	return 'y';
}

void CloseBase(User_table *Base_User_base, int *use_pocition_base, User_table *Base_User, int *user_pocition, FILE *ptUser,char * User_Base_Folder,char * folder_user)
{
	if ((ptUser = fopen(User_Base_Folder, "wb+")) != NULL)
	{
		fwrite((Base_User_base), *use_pocition_base, sizeof(User_table), ptUser);
	}
	fclose(ptUser);
	if ((ptUser = fopen(folder_user, "ab+")) != NULL)
	{
		fwrite(Base_User, *user_pocition, sizeof(User_table), ptUser);
	}
	fclose(ptUser);
}