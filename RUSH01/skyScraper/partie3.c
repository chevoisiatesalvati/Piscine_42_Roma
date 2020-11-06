#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "gratteCiel.h"


void purger()
{
  int c;
  while ((c = getc(stdin)) != '\n' && c != EOF);
}


void clean (char *chaine)
{
   char *p = strchr(chaine, '\n');
   if (p)
    *p = 0;
   else
    purger();
}

void saisie_avec_espaces(char * chaine, int n)
{
    fgets(chaine, n, stdin);
    clean(chaine);
}


/************************QUESTION 17************************/

 /*!
 * Fonction permutant les lignes i et j dans la grille si i et j correspondent à des indices
 * différents de lignes du quartier.

 */

void permute_lignes(Gratte_ciel * p,int i, int j)
{
	if( i != j || i != 0 || i != p->n +1 || j != 0 || j != p->n +1)
	{
		int k;
		int tmp;
		for(k=1 ; k <= p->n ; k++)
		{
			tmp = get_case(p,i,k); //on enrigstre la valeur de base dans tmp 
			set_case(p,i,k, get_case(p,j,k)); // on atribu la seconde valeur a la premier
			set_case(p,j,k,tmp); // et la premier valeur a la deuxieme
		}
	}

}

/************************QUESTION 18************************/


void permute_colonnes(Gratte_ciel * p,int i, int j)
{
	if( i != j || i != 0 || i != p->n +1 || j != 0 || j != p->n +1)
	{
		int k;
		int tmp;
		for(k=1 ; k <= p->n ; k++)
		{
			tmp = get_case(p,k,i); //on enrigstre la valeur de base dans tmp 
			set_case(p,k,i, get_case(p,k,j));// on atribu la seconde valeur a la premier
			set_case(p,k,j,tmp);// et la premier valeur a la deuxieme
		}
	}

}


/************************QUESTION 19************************/

 /*!
  * Fonction permutant les valeurs nb1 et nb2 dans le quartier si nb1 et nb2 correspondent à des
	valeurs différentes pour des immeubles (entre 1 et n inclus) et si le quartier est entièrement
	rempli.
  * \param p : pointeur sur gratte-ciel
  * \param nb1 : première valeur
  * \param nb2 : deuxième valeur
  */

void permute_nombres(Gratte_ciel * p, int nb1, int nb2) 
{
	int i=0;
	int j=0;
	for(i=1 ; i <= p->n ; i++)
	{
		for(j=1 ; j <= p->n ; j++)
		{
			if(get_case(p,i,j) == nb1)
				set_case(p,i,j,nb2);
			else if(get_case(p,i,j) == nb2)
				set_case(p,i,j,nb1);
		}
	}
}

/************************QUESTION 20************************/

 /*!
 * Fonction remplissant le quartier selon un schéma précis
 * (10 étages sur la diagonale et +10 étages pour le voisin de droite) 4*
 * \param p : pointeur sur gratte-ciel
 */

void remplir_quartier(Gratte_ciel * p)
{ 
	int i;
	int j;
	int k;
	for(i=1 ; i <= p->n ; i++ )
	{
		j=1;
		for(k=p->n-i+2 ; k<=p->n ; k++)
		{
			set_case(p,i,j,k);
			j++;
		}
		k=1;
		for(; j <= p->n ; j++)
		{
			set_case(p,i,j,k);
			k++;
		}	
	}
}

/************************QUESTION 21************************/

/*!
 
 * Fonction retournant un nombre entier aléatoire entre min et max inclus, -1 si min > max.
 
 * \param min : borne inférieure de l’intervalle
 * \param max : borne supérieure de l’intervalle

 */

int nombre_aleatoire(int min, int max) 
{
	if(min>max)
		return -1;	
	return (min + (rand()%(max-min+1)));
}

/************************QUESTION 22************************/

/*!
 * Fonction générant aléatoirement un quartier de manière qu’il n’y ait pas deux immeubles
 * de même taille sur une même ligne ou colonne. 
 * \param p : pointeur sur gratte-ciel
 */ 

void quartier_aleatoire (Gratte_ciel * p)
{
	srand((unsigned)(time(NULL)));
	remplir_quartier(p);
	int nb=nombre_aleatoire(50, 100);
	int x=nombre_aleatoire(1,3);
	int i=nombre_aleatoire(1,p->n);
	int j=nombre_aleatoire(1,p->n);
	while(i==j) 
	{
		j=((nombre_aleatoire(1,p->n)));
	}
	int a;
	do
		{	
		for(a=50; a<nb; a++)
		{
			i=nombre_aleatoire(1,p->n);
			j=nombre_aleatoire(1,p->n);
			if(x == 1)
			{
				permute_lignes(p,i,j);
			}
			else if(x == 2)
			{
				permute_colonnes(p,i,j);
			}
			else
			{
				permute_nombres(p,i,j);
			}
		}
	}while(quartier_est_solution(p) == 0);
}

/************************QUESTION 23************************/

/*!
 * Fonction créant une instance du jeu Gratte-ciel. Le quartier est généré aléatoirement,
 * la bordure est mise à jour par raport au imeuble visible et le quartier est finalement effacé.
 * La fonction renvoie l’adresse du gratte-ciel ainsi créé.
 *
 * \param n : Nombre d’immeubles par ligne et par colonne du quartier
 */

Gratte_ciel * creer_gratte_ciel_aleatoire (int n) 
{ 
	Gratte_ciel *g = creer_gratte_ciel(n);
	quartier_aleatoire(g);
	calcul_bordure(g);

	int i;
	int j;

	for(i = 1 ; i <= g->n ; i++)
	{
		for(j = 1 ; j <= g->n ; j++)
		{
			set_case(g,i,j,0);
		}
	}

	return g;

}


/*!
 * Fonction permettant au joueur de saisir un emplacement d’immeuble et modifiant le quartier en
 * conséquence. Si le joueur veut arrêter, il saisit la chaîne "stop". La saisie est répétée
 * jusqu’à ce que la saisie corresponde à une saisie d’un immeuble sur une case.

 * Format : "B1 30" pour mettre un immeuble de 30 étages sur la case du quartier de la 2ème ligne
 et de la 1ère colonne
       
*/  

int mouvement(Gratte_ciel * p) 
{
	char mouv[5];
	printf("Saisir un emplacement : (De la forme suivante B1 30 , ou stop si vous ne souhaiter ne pas jouer) \n");
	saisie_avec_espaces(mouv,5);// fonction cree par le prof permetant de recuper une valeur pour l'atribuer a un mouvement


	
	if (strcmp(mouv,"stop") == 0)//fonction permetant de compareer deux chaine si elle retourne 0 c'est qu'elle sont egqux
	{
		return 0;
	}

	int ligne = (int) mouv[0] - 64 ;// on fait moin 64 pour avoir la letre en nombre

	int	colonne=(int)mouv[1];

		colonne=(colonne-48); //pour avoir la chaine de caractere numerique en decimale


	int	immeuble = (int) mouv[3];
		
		immeuble=(immeuble-48)/* *10 */;

	while(colonne < 1 || colonne > p->n || ligne < 1 || ligne > p->n || immeuble <1) /*|| set_case(p,ligne,colonne,immeuble) == 0*/
	{
		if (strcmp(mouv,"stop") == 0)
		{
			return 0;
		}

		printf(" VOTRE SAISIE EST INCORECTE MERCI DE REESAYER ! \n");

		printf("Saisir un emplacement : (De la forme suivante B1 30 , ou stop si vous ne souhaiter ne pas jouer) \n");
		saisie_avec_espaces(mouv,5);

		ligne = (int) mouv[0] - 64 ;

		colonne=(int)mouv[1];

		colonne=(colonne-48); 

		immeuble = (int) mouv[3];

		immeuble=(immeuble-48)/* *10 */;

	}


	set_case(p,ligne,colonne,immeuble);
	affichage_gratte_ciel(p);

	return 1;
}


/*!
 * Fonction permettant de jouer au jeu du gratte-ciel.
 *
 * \param n : Taille du quartier de la partie à créer
 */

void jouer(int n)
 {
 	Gratte_ciel *g = creer_gratte_ciel_aleatoire(n);

 	affichage_gratte_ciel(g);

 	while(get_nb_cases_libres(g) != 0)
 	{ 
 		if(mouvement(g) == 0)
 		{
 			printf("_______________---------------JEU STOPE PAR L'UTILISATEUR---------------_______________\n");
 			exit(1);
 		}

 		mouvement(g);
 	}

 	if(quartier_est_solution(g) == 1)
 	{
	 	printf("-------------------PARTIS GAGNE VOUS AVEZ RESOLU LE GRATE CIEL PASSER AU NIVEAU SUPPERIEUR----------------------\n");
 	}
 	else
 	{
 		printf("_____________--------------------GAME OVER--------------------_____________ \n");
 	}
 }
