#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#include "gratteCiel.h"
/*-------------------------------------------------------- Fonctions partie 2 --------------------------------------------------------*/
 
 /************************QUESTION 9************************/

 /*!
 * Fonction retournant 1 si (i,j) est une case de la bordure (n’est pas une case inutilisée),
 * 0 sinon
 *
 * \param p : pointeur sur gratte-ciel
 * \param i : indice de ligne
 * \param j : indice de colonne
 */
 int est_case_bordure(Gratte_ciel * p, int i, int j) 
 {

	 if((j==0 && (i>=1 && i<=p->n)) || (i==0 && (j>=1 && j<=p->n)) || (j == (p->n)+1 && (i>=1 && i<=p->n)) || (i==(p->n)+1 && (j>=1 && j<=p->n)))
		return 1;
	else
		return 0;
 }
 
 /************************QUESTION 10************************/

 /*!
* Fonction retournant le nombre d’immeubles visibles depuis la case (i,j)
*
* si (i,j) n’est pas une case de la bordure ou si c’est une case inutilisée,
* la fonction retourne -1
*
* \param p : pointeur sur gratte-ciel
* \param i : indice de ligne
* \param j : indice de colonne
*/
int nb_immeubles_visibles(Gratte_ciel * p, int i, int j) 
{ 
	int cmpt=0;
	int max=0;

	if(est_case_bordure(p,i,j) == 0)
		return -1;
	else
		{

			//Condition pour la bordure de gauche !	

			if(j==0 && (i>=1 && i<=p->n))
			{	
				for(j=1; j <= p->n ; j++)
				{					
					if(p->grille[(((p->n)+2)*i)+j] > max)
					{
						max = p->grille[(((p->n)+2)*i)+j];
						cmpt++;
					}

				}
				
			}

			//Condition pour la bordure de droite !	

			if(j==p->n + 1 && (i>=1 && i<=p->n))
			{	
				for(j= p->n; j >= 1 ; j--)
				{					
					if(p->grille[(((p->n)+2)*i)+j] > max)
					{
						max = p->grille[(((p->n)+2)*i)+j];
						cmpt++;
					}

				}
			}

			//Condition pour la bordure du haut !

			if(i == 0 && (j>=1 && j<=p->n))
			{	
				for(i = 1 ; i <= p->n ; i++)
				{					
					if(p->grille[(((p->n)+2)*i)+j] > max)
					{
						max = p->grille[(((p->n)+2)*i)+j];
						cmpt++;
					}

				}
			}

			//Condition pour la bordure du bas !

			if(i == p->n + 1 && (j>=1 && j<=p->n))
			{	
				for(i = p->n ; i >=1 ; i--)
				{					
					if(p->grille[(((p->n)+2)*i)+j] > max)
					{
						max = p->grille[(((p->n)+2)*i)+j];
						cmpt++;
					}

				}
			}



		}
		return cmpt;
}

/************************QUESTION 11************************/

/*!
 * Fonction mettant à jour la bordure avec le nombre d’immeubles du quartier visibles
 * depuis chaque case.
 *
 * \param p : pointeur sur gratte-ciel 
 */

void calcul_bordure(Gratte_ciel *p)
{
	int i;
	int j;
	//Remplit la bordure de gauche
	j = 0;
	for(i=1 ; i <= p->n ; i++)
		p->grille[((p->n + 2)*i) + j] = nb_immeubles_visibles(p,i,j);
	//Remplit la bordure de droite
	j = p->n + 1;
	for(i= 1 ; i <= p->n ; i++)
		p->grille[((p->n + 2)*i) + j] = nb_immeubles_visibles(p,i,j) ;
	//Remplit la bordure du haut 
	i = 0;
	for(j=1 ; j <= p->n ; j++)
		p->grille[((p->n + 2)*i) + j] = nb_immeubles_visibles(p,i,j);
	//Remplit la bordure du bas 
	i = p->n + 1;
	for(j=1 ; j <= p->n ; j++)
		p->grille[((p->n + 2)*i) + j] = nb_immeubles_visibles(p,i,j);
}

	

/************************QUESTION 12************************/

/*!
 *  Fonction retournant 1 si les immeubles de la ligne ind sont tous de taille différente 
 *
 *  param p : pointeur sur gratte-ciel 
 *  param ind : indice de ligne 
 */


int valeurs_differentes_ligne (Gratte_ciel * p, int ind) 
{ 
	if(ind!=0 && ind!=(p->n)+1){
		int k=1;
		int j=1;

		for(k=1 ; k <= p->n ; k++)
		{
			for(j=k ; j <= p->n -1; j++ )
			{
				if(p->grille[((p->n+2)*ind)+k] == p->grille[((p->n+2)*ind)+j+1]  )
				{	
				return 0;
				}
			}
		}
		return 1;
	}
	return 0;	
}




/************************QUESTION 13************************/

/*!
 * Fonction retournant 1 si les immeubles de la colonne ind sont tous de taille différente
 * \param p : pointeur sur gratte-ciel
 * \param ind : indice de colonne
 */
 
int valeurs_differentes_colonne(Gratte_ciel * p, int ind) 
{
	if(ind!=0 && ind!=(p->n)+1){
		int k=1;
		int j=1;

		for(j=1 ; j <= p->n ; j++)
		{
			for(k=j ; k <= p->n-1 ; k++ )
			{
				if(p->grille[(((p->n+2)*(k+1))+ind)] == p->grille[((p->n+2)*j)+ind]  )
				{
					return 0;
				}
			}
		}
		return 1;
	}
	return 0;
}





/************************QUESTION 14************************/


/*!
 * Fonction retournant 1 s’il n’y a pas deux immeubles de même hauteur
 * dans une ligne ou une colonne du quartier
 *  \param p : pointeur sur gratte-ciel
 */

int valeurs_differentes_quartier (Gratte_ciel * p) 
{ 
	int i;

	for( i=1 ; i < p->n ; i++)
	{
		if(valeurs_differentes_ligne(p , i) == 0)
		{
			return 0;
		}
	}

	for( i=1 ; i < p->n ; i++)
	{
		if(valeurs_differentes_colonne(p , i) == 0)
		{
			return 0;
		}
	}

	return 1;
}

/************************QUESTION 15************************/


/*!
 * Fonction retournant 1 si les valeurs non-nulles de la bordure correspondent
 * au nombre d’immeubles que l’on aperçoit dans le quartier à partir de la bordure,
 * et 0 sinon.
 *
 * \param p : pointeur sur gratte-ciel

 */


int bordure_correcte(Gratte_ciel * p) 
{ 
	int i;
	int j;

	for(j = 0 ; j < p->n + 2 ; j++ )
	{
		for(i = 0 ; i < p->n + 2 ; i++)
		{
			if(est_case_bordure (p,i,j) == 1 && p->grille[((p->n + 2)*i) + j] != 0)
			{
				if(nb_immeubles_visibles(p,i,j) != get_case(p,i,j))
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

/************************QUESTION 16************************/

/*!
 * Fonction retournant 1 si le placement des immeubles dans le quartier correspond 3 
 * à une solution du jeu du gratte-ciel, et 0 sinon.
 *
 *  \param p : pointeur sur gratte-ciel
 */

int quartier_est_solution(Gratte_ciel * p) 
{
	if(get_nb_cases_libres(p) == 0 && bordure_correcte(p) == 1 && valeurs_differentes_quartier(p) == 1)
		return 1;
	return 0;
}
 
