#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

void VpisTabela(char tabela[][8], int n);
void IzpisTabela(char tabela[][8], int n, const char* imeIgralnoPolje);
void VpisLadjic(char tabela[][8], int n, const char* imeIgralnoPolje);
void ZadetekLadjice(char tabela[][8], int n, const char* imeIgralnoPolje);
void IzbrisLadjice(char tabela[][8], int n, char znak);
void ZamenjajIgralca();
bool KonecIgre(char tabela[][8], int n);

static int s_Igralec = 1;

int main()
{
	char tabelaIgralec1[8][8];
	char tabelaIgralec2[8][8];

	VpisTabela(tabelaIgralec1, 8);
	VpisTabela(tabelaIgralec2, 8);
	VpisLadjic(tabelaIgralec1, 8, "Igralec 1");
	VpisLadjic(tabelaIgralec2, 8, "Igralec 2");

	ZamenjajIgralca();

	while (!KonecIgre(tabelaIgralec1, 8) && !KonecIgre(tabelaIgralec2, 8))
	{
		if (s_Igralec == 1)
		{
			ZadetekLadjice(tabelaIgralec2, 8, "Igralec 2");
		}
		else
		{
			ZadetekLadjice(tabelaIgralec1, 8, "Igralec 1");
		}
	}

	if (s_Igralec == 1)
	{
		std::cout << "Zmagal je Igralec 1." << std::endl;
	}
	else
	{
		std::cout << "Zmagal je Igralec 2." << std::endl;
	}
}

void VpisTabela(char tabela[][8], int n)
{
	tabela[0][0] = ' ';

	char crka = 'A';
	char stevilo = '1';

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

void IzpisTabela(char tabela[][8], int n, const char* imeIgralnoPolje)
{
	system("cls");
	std::cout << "Igralno polje @ " << imeIgralnoPolje << std::endl << std::endl;

	// Casovna zahtevnost: O(n^2)
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

void VpisLadjic(char tabela[][8], int n, const char* imeIgralnoPolje)
{
	IzpisTabela(tabela, n, imeIgralnoPolje);

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

		// Casovna zahtevnost: O(n)
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

		// Casovna zahtevnost: O(n)
		for (int k = 0; k < 5; k++)
		{
			tabela[i][j] = 'L';
			j++;
		}
	}

	IzpisTabela(tabela, n, imeIgralnoPolje);

	std::cout << "Vnesi pozicijo bojne ladje ([stolpec][vrstica] ali [vrstica][stolpec])" << std::endl;
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

		// Casovna zahtevnost: O(n)
		for (int k = 0; k < 4; k++)
		{
			tabela[j][i] = 'B';
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

		// Casovna zahtevnost: O(n)
		for (int k = 0; k < 4; k++)
		{
			tabela[i][j] = 'B';
			j++;
		}
	}

	IzpisTabela(tabela, n, imeIgralnoPolje);

	std::cout << "Vnesi pozicijo podmornice ([stolpec][vrstica] ali [vrstica][stolpec])" << std::endl;
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

		// Casovna zahtevnost: O(n)
		for (int k = 0; k < 3; k++)
		{
			tabela[j][i] = 'P';
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

		// Casovna zahtevnost: O(n)
		for (int k = 0; k < 3; k++)
		{
			tabela[i][j] = 'P';
			j++;
		}
	}

	IzpisTabela(tabela, n, imeIgralnoPolje);

	std::cout << "Vnesi pozicijo rusilca ([stolpec][vrstica] ali [vrstica][stolpec])" << std::endl;
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

		// Casovna zahtevnost: O(n)
		for (int k = 0; k < 2; k++)
		{
			tabela[j][i] = 'R';
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

		// Casovna zahtevnost: O(n)
		for (int k = 0; k < 2; k++)
		{
			tabela[i][j] = 'R';
			j++;
		}
	}
	IzpisTabela(tabela, n, imeIgralnoPolje);
}

void ZadetekLadjice(char tabela[][8], int n, const char* imeIgralnoPolje)
{
	IzpisTabela(tabela, n, imeIgralnoPolje);

	char pozicija[3];

	std::cout << "Vnesi pozicijo tarce ([stolpec][vrstica] ali [vrstica][stolpec])" << std::endl;
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

		switch (tabela[j][i])
		{
		case 'L':
		case 'B':
		case 'P':
		case 'R':
			std::cout << "Zadetek" << std::endl;
			IzbrisLadjice(tabela, n, tabela[j][i]);
			break;
		default:
			ZamenjajIgralca();
			break;
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

		switch (tabela[i][j])
		{
		case 'L':
		case 'B':
		case 'P':
		case 'R':
			std::cout << "Zadetek" << std::endl;
			IzbrisLadjice(tabela, n, tabela[i][j]);
			break;
		default:
			ZamenjajIgralca();
			break;
		}
	}
	IzpisTabela(tabela, n, imeIgralnoPolje);
}

void IzbrisLadjice(char tabela[][8], int n, char znak)
{
	// Casovna zahtevnost: O(n^2)
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (tabela[i][j] == znak)
			{
				tabela[i][j] = 'x';
			}
		}
	}
}

void ZamenjajIgralca()
{
	s_Igralec *= -1;
}

bool KonecIgre(char tabela[][8], int n)
{
	// Casovna zahtevnost: O(n^2)
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			switch (tabela[i][j])
			{
			case 'L':
			case 'B':
			case 'P':
			case 'R':
				return false;
			}
		}
	}
	return true;
}