#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#include "gratteCiel.h"
/*-------------------------------------------------------- Fonctions partie 1 --------------------------------------------------------*/

/************************QUESTION 2************************/

/*!
 * Fonction allouant dynamiquement un gratte_ciel dont l’adresse est retournée.
 *
 * \param n : nombre d’immeubles par ligne et par colonne dans le quartier
 * 
 */
Gratte_ciel *
creer_gratte_ciel (int nb)
{

  Gratte_ciel *creer_grille_p = NULL;
  int i = 0;

  creer_grille_p = (Gratte_ciel *) malloc (sizeof (Gratte_ciel));	/* on alloue la mémoire pour la structure pour que la variable ne soit pas supprimée à la fin de la fonction */

  if (creer_grille_p == NULL)
    { 
	  /* test sur l'allocation */
      printf ("\nEchec de l'allocation\n\n");
      exit (1);
    }

  if (nb < 2 || nb > 8)
    {
      printf ("NULL\n");
      return creer_grille_p;
    }
  else
    {

      creer_grille_p->n = nb;	/* le paramètre n est affecté au champ n de la variable de type grille */

      creer_grille_p->grille = malloc (sizeof (int) * (nb + 2) * (nb + 2));	/* allocation dynamique d'une grille de taille n*n */

      creer_grille_p->nb_cases_libres = nb * nb;

      while (i < (nb + 2) * (nb + 2))
	{
	  creer_grille_p->grille[i] = 0;	/* chaque case du tableau est initialisée à 0 car la grille ne contient aucun nombre */
	  i++;
	}

      return creer_grille_p;

    }
}

/************************QUESTION 3************************/

/*!
 * Fonction désallouant dynamiquement la mémoire utilisée par le gratte-ciel passé en paramètre
 *
 * \param p : pointeur sur le gratte-ciel à désallouer
 */
void
detruire_gratte_ciel (Gratte_ciel * p)
{
  free (p->grille);
  free (p);
}

/************************QUESTION 4************************/

/*!
 * Fonction retournant 1 si i correspond à un indice valide pour la grille du gratte-ciel
 * passé en paramètre, et 0 sinon
 *
 * \param p : pointeur sur un gratte-ciel
 * \param i : indice à tester
 */
int
indice_grille_valide (Gratte_ciel * p, int i)
{
  if (i >= 0 && i < (p->n) + 2)
    return 1;

  return 0;
}

/************************QUESTION 5************************/

/*!
* Fonction retournant la valeur de la case (i,j) de la grille du gratte-ciel p.
* Si la case (i,j) n’existe pas, la fonction renvoie -1.
*
* \param p : pointeur sur un gratte-ciel
* \param i : entier correspondant au numéro de ligne
* \param j : entier correspondant au numéro de colonne
*/
int
get_case (Gratte_ciel * p, int i, int j)
{
  int test1 = 0;
  int test2 = 0;

  test1 = indice_grille_valide (p, i);
  test2 = indice_grille_valide (p, j);
  if (test1 == 1 && test2 == 1)
    {
      return p->grille[(i * (p->n + 2)) + j];	/* on descend à la ième ligne en avançant de i*p->n cases et on avance à la jème case */
    }
  else
    return -1;

}

/************************QUESTION 6************************/

/*!
*
* Fonction modifiant la valeur de la case (i,j) de la grille du gratte-ciel p
*
* \param p : pointeur sur un gratte-ciel
* \param i : entier correspondant au numéro de ligne
* \param j : entier correspondant au numéro de colonne
* \param valeur : valeur que l’on souhaite mettre dans la case (i,j)
*/
int
set_case (Gratte_ciel * p, int i, int j, int val)
{

  if (!(indice_grille_valide (p, i)) || !(indice_grille_valide (p, j))
      || !(val >= 0 && val <= p->n))
    return 0;
  p->grille[((((p->n) + 2) * i) + j)] = val;
  if (!(i == 0 || i == ((p->n) + 1)) && !(j == 0 || j == ((p->n) + 1)))
    {					//On compte le nombre de cases libres que si on a modifié une case(i,j) du quartier
      int cmpt = 0;		//On introduit une variable cmpt qui va compter le nombre de cases libres dans le quartier 
      for (i = 1; i <= p->n; i++)
	{
	  for (j = 1; j <= p->n; j++)
	    if (get_case (p, i, j) == 0)
	      cmpt++;		//On incrémente cmpt si elle rencontre une case libre 
	}
      p->nb_cases_libres = cmpt;
    }
  return 1;

}

/************************QUESTION 7************************/

/*!
* Fontion retournant le nombre de cases libres du gratte-ciel passé en paramètre
*
*\param p : pointeur sur le gratte-ciel
*/
int
get_nb_cases_libres (Gratte_ciel * p)
{

  return p->nb_cases_libres;

}
/************************QUESTION 8************************/

 /*!
  * Fonction affichant la grille sur le terminal
  *
  * \param p : pointeur sur le gratte-ciel que l’on souhaite afficher
  */
void
affichage_gratte_ciel (Gratte_ciel * p)
{
  int *tab = NULL;
  int c2, i, j;
  char star = '*';
  int *mem = NULL;
  int n = (p->n) + 2;
  tab = p->grille;
  mem = p->grille;



  while (tab < (p->grille) + ((n) * (n)))	//boucle principale
    {
      for (i = 0; i < (n); i++)	// boucle ligne-colonne
	{
	  for (c2 = 0; c2 < (n) + (n); c2++)	//boucle ligne
	    {
	      printf ("%c %c ", star, star);	//affiche les 20 étoiles
	    }

	  printf ("%c", star);	// affiche la 21eme étoile

	  printf ("\n");	// Saute une ligne


	  for (j = 0; j < 2; j++)	// on repete 2 fois (dans 1 carré il y a 2 ligne pour placer le pion au milieu)
	    {
	      if (j == 1)	// Milieu de la case
		{
		  for (c2 = 0; c2 < (n); c2++)	// boucle pour remplir les petites cases
		    {
		      if (mem != tab && (mem + (n) - 1) != tab
			  && tab != (mem + (n) * (n) - 1)
			  && tab != (mem + ((n) - 1) * (n)))
			{
			  printf ("%c   %d\t", star, *tab);	// remplace 0 par rien et fait une tabulation
			}
		      else
			{
			  printf ("%c\t", star);	// remplace 0 par rien et fait une tabulation
			}
		      tab++;
		    }

		  printf ("%c", star);
		  printf ("\n");

		}

	      for (c2 = 0; c2 < (n) + 1; c2++)	// boucle qui affiche les étoile colonne (vide)
		{
		  printf ("%c\t", star);
		}

	      printf ("\n");
	    }

	}

      for (c2 = 0; c2 < (n) + (n); c2++)	// Affiche la dernière ligne de  boucle
	{
	  printf ("%c %c ", star, star);
	}

      printf ("%c\n", star);

    }
}
