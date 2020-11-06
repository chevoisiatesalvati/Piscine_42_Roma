#include "check.h"
#include <unistd.h>

int *check_argv(char *arg)  //prende come variabile il puntatore del parametro argv[1], che contiene gli input 
{
	int i;  //indice per scorrere i caratteri dell'input 
	int j;  //
	int *tab;  //creazione puntatore della tabella

	tab = malloc(16 * sizeof(int));   //allocazione della memoria per la tabella di 16 interi (16 caselle, 4x4) e cast di tab
	if (!tab)
		return (error_null());   // se la tabella non e' 16 da errore
	j = 0;
	i = 0;   //posizione del carattere da dove parte l'indice
	if (!arg)  //
		return (error_null());
	while (arg[i])
	{
		if ((!(i % 2 == 0 && arg[i] >= '1' && arg[i] <= '4')  //contrario di: SE i numeri pari dell'indice sono compresi tra 1 e 4 
			&& !(i % 2 == 1 && arg[i] == ' ')) || i > 31)  //E i numeri dispari dell'indice sono spazi o caratteri stampabili
			return (error_null());   //dai errore
		if (i % 2 == 0)  //se l' indice e' su un numero pari 
			tab[j++] = arg[i] - 48;
		i++;
	}
	if ((i > 0 && (arg[i - 1] < '1' || arg[i - 1] > '4')) || i != 31)
		return (error_null());
	return (tab);
}

int check_row(int *row)
{
	int i;
	int max;
	int count;

	i = 1;
	max = 0;
	count = 0;
	while (i < 5)
	{
		if (row[i] > max)
		{
			max = row[i];
			count++;
		}
		i++;
	}
	if (count != row[0])
		return (0);
	i--;
	max = 0;
	count = 0;
	while (i > 0)
	{
		if (row[i] > max)
		{
			max = row[i];
			count++;
		}
		i--;
	}
	if (count != row[5])
		return (0);
	return (1);
}

int check_col(int **board, int col)
{
	int *tab;
	int i;

	tab = malloc(6 * sizeof(int));
	i = 0;
	while (i < 6)
	{
		tab[i] = board[i][col];
		i++;
	}
	if (check_row(tab))
	{
		free(tab);
		return (1);
	}
	free(tab);
	return (0);
}

int is_safe(int **board, int val, int row, int col)
{
	int i;

	i = 1;
	while (i < 5)
	{
		if (board[i++][col] == val)
			return (0);
	}
	i = 1;
	while (i < 5)
	{
		if (board[row][i++] == val)
			return (0);
	}
	return (1);
}
