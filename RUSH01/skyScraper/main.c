#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#include "gratteCiel.h"


int main()
{
	printf ("				******************************************\n");	
	printf ("				*           				 *\n");	
	printf ("				* 		GRATTE CIEL		 *\n");	
	printf ("				*					 *\n");	
	printf ("				******************************************\n");	
																															
	printf("\n\n----------------------**************** BIENVENU DANS LE JEU *****************----------------------\n\n");
	int n;
	printf ("Entrez un nombre pour la taille de la grille (entre 2 et 8 compris): \n");
	scanf("%d",&n);
	jouer(n);
	return 0;
}

