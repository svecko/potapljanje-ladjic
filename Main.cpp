#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

void VpisTabela(char tabela[][8], int n);
void VpisLadjic(char tabela[][8], int n);
void IzpisTabela(char tabela[][8], int n);

int main()
{
	char tabela[8][8];

	VpisTabela(tabela, 8);
	VpisLadjic(tabela, 8);
}

void VpisTabela(char tabela[][8], int n)
{
	char crka = 'A';
	char stevilo = '1';

	tabela[0][0] = ' ';

	for (int i = 1; i < n; i++)
	{
		tabela[0][i] = crka;
		tabela[i][0] = stevilo;
		crka++;
		stevilo++;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			tabela[i][j] = 'x';
		}
	}
}

void VpisLadjic(char tabela[][8], int n)
{
	IzpisTabela(tabela, n);

	char pozicija[3];
	std::cout << "Vnesi pozicijo letalonosilke ([stolpec][vrstica] ali [vrstica][stolpec])" << std::endl;
	gets_s(pozicija);

	if (pozicija[0] >= 'a' && pozicija[0] <= 'g')
	{
		int i, j;
		switch (pozicija[0])
		{
		case 'a':
			i = 1;
			break;
		case 'b':
			i = 2;
			break;
		case 'c':
			i = 3;
			break;
		case 'd':
			i = 4;
			break;
		case 'e':
			i = 5;
			break;
		case 'f':
			i = 6;
			break;
		case 'g':
			i = 7;
			break;
		}

		switch (pozicija[1])
		{
		case '1':
			j = 1;
			break;
		case '2':
			j = 2;
			break;
		case '3':
			j = 3;
			break;
		case '4':
			j = 4;
			break;
		case '5':
			j = 5;
			break;
		case '6':
			j = 6;
			break;
		case '7':
			j = 7;
			break;
		}

		for (int k = 0; k < 5; k++)
		{
			tabela[j][i] = 'L';
			j++;
		}
	}
	else if (pozicija[0] >= '1' && pozicija[0] <= '7')
	{
		int i, j;
		switch (pozicija[0])
		{
		case '1':
			i = 1;
			break;
		case '2':
			i = 2;
			break;
		case '3':
			i = 3;
			break;
		case '4':
			i = 4;
			break;
		case '5':
			i = 5;
			break;
		case '6':
			i = 6;
			break;
		case '7':
			i = 7;
			break;
		}

		switch (pozicija[1])
		{
		case 'a':
			j = 1;
			break;
		case 'b':
			j = 2;
			break;
		case 'c':
			j = 3;
			break;
		case 'd':
			j = 4;
			break;
		case 'e':
			j = 5;
			break;
		case 'f':
			j = 6;
			break;
		case 'g':
			j = 7;
			break;
		}

		for (int k = 0; k < 5; k++)
		{
			tabela[i][j] = 'L';
			j++;
		}
	}

	IzpisTabela(tabela, n);
}

void IzpisTabela(char tabela[][8], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << (char)tabela[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}