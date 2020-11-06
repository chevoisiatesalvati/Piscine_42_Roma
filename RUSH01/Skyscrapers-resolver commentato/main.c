#include "solver.h"
#include <stdlib.h>

int main(int argc, char **argv)  //argc e' il numero degli argomenti passati dalla command line, argv sono gli argomenti. Il primo argomento e' sempre il nome del programma.
{
	int **board;  //questa dovrebbe essere la tabella
	int *views;   //la viste, quello che si vede da ogni lato della tabella, i singoli input che diamo dalla command line)

	if (argc != 2)  // qui verifica che gli argomenti siano solo 2 (main e gli argomenti passati che valgono come un array)
	{
		error();  // se gli argomenti sono diversi da 2, scrive Error (tramite la funzione apposita).
		return (0);
	}
	views = check_argv(argv[1]);  //diamo a views il numero degli input, applicando a argv [1] la funzione che li conta e divide, togliendo spazi e caratteri sbagliati)
	if (views == NULL)      // se views = 0 da Errore, perche' nessun input VALIDO e' stato trovato con la funzione precedente
		return (0);
	board = initialize_board(views);   // crea la tabella e alloca la memoria necessaria
	if (board == NULL || !solveur(board, 1, 1))  // se la tabella non e' valida o non risolvibile, da errore
	{
		error();
		return (0);
	}
	print_board(board);   //stampa la tabella
	free_board(board);   //libera la memoria allocata per la tabella
	free(views);   //libera la memoria allocata per gli input
	return (0);
}
