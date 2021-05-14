#include <stdio.h>
#include <stdlib.h>

#include "pile.h"
void	Inverp(pile* );
void	Ex31(pile ,pile* );

void	Inverp(pile *p)
{
	pile	p1, p2;
	writep(&p1);
	writep(&p2);
	while(!videp(*p))
	{
		addp(valp(*p), &p1);
		delp(p);
	}
	while(!videp(p1))
	{
		addp(valp(p1), &p2);
		delp(&p1);
	}
	while(!videp(p2))
	{
		addp(valp(p2), p);
		delp(&p2);
	}
}
void	Ex31(pile p1, pile* p2)
{
	pile	aux;
	writep(&aux);
	while(!videp(p1))
	{
		if(valp(p1)%2) //impaire
			addp(valp(p1), &aux);
		else
			addp(valp(p1), p2);
		delp(&p1);
	}
	while(!videp(aux))
	{
		addp(valp(aux), p2);
		delp(&aux);
	}
}
int	main(int argc, char* argv)
{
	pile	*c;
	c = (pile *)	malloc(sizeof(pile));
	writep(c);
	pile	p2;
	int	i, x;
	while(1337)
	{
		printf("********************This programme created by Brav0********************\n");
		printf("|1|: Remplir Stack      |2|: Afficher Stack      |3|: Test Vide\n");
		printf("|4|: Add 1 Element      |5|: Valeur Stack        |6|: Delete 1 Element\n");
		printf("|7|: Depilier K elements|8|: Delpiler Jusqu'a Elt|9|: Appartient x ? \n");
		printf("|10|:Inverser Pile\t|11|: Paire over impaire\n"); 
		printf("***********************************************************************\n");
		printf("Enter nomber btween 1 and 10 other 0 for quit :\t");
		scanf("%d", &i);
		switch(i)
		{
			case 1:remplirp(c);	
				break;
			case 2:affp(*c);
				break;
			case 3:if(videp(*c))	printf("Stack est vide\n");
				else		printf("Stack non vide\n");
				break;
			case 4:printf("Entrer un element pour le ajouter :\t");
				scanf("%d", &x);
				addp(x, c);
				break;
			case 5: printf("La Valeur de pile est :[**[%d]**] \n", valp(*c));
				break;
			case 6: delp(c);
				break;
			case 7: scanf("%d", &x);
				DepilerK(x, c);
				break;
			case 8: scanf("%d", &x);
				Depilerelt(x, c);
				break;
			case 9: printf("Donner une valeur pour chercher si il'est dans la pile ou non :\t");
				scanf("%d", &x);
				if(App(x,*c))	printf("/--> [%d] Appartient a Stack\n", x);
				else		printf("/--> [%d] N'appartient pas a Stack\n", x);
				break;
			case 10:Inverp(c);
				break;
			case 11:writep(&p2);
				Ex31(*c, &p2);
				affp(p2);
				break;
			default:free(c);
				printf("Good by chabab\n");
				exit(0);
		}
	}
}
