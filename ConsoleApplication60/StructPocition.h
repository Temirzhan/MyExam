#pragma once
struct User_table
{
	int cod;
	char Name[200];
	int price;
	int pcs;
	char guarantee[10];
	int counter_sell; //сумма проданных

};
struct table
{
	int cod;
	char Name[200];
	int price_1pc;
	int price_wholesale;
	char guarantee[10];
};

struct Pocition
{
	char Name[100];
	table pocition[100] ;
};