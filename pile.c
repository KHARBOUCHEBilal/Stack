#include <stdio.h>
#include <stdlib.h>

#include "pile.h"

void	writep(pile *p)
{	
	p->ip = 0;
}
int	videp(pile p)
{
	if(p.ip)
		return 0;// non vide reutun 0 vide == 1
	return 1;
}
int	valp(pile p)
{
	if(!videp(p))
		return (p.TP[p.ip]);
	printf("valeur non defenie\n");
	exit(EXIT_FAILURE);
}
int	addp(int x, pile *p)
{
	p->ip++;
	if(p->ip < N)
	{
		p->TP[p->ip] = x;
		return 1;
	}
	printf("Espace insuiffisante\n");
	exit(-1);
}
void	delp(pile *p)
{
	if(videp(*p))
	{
		printf("Suppression Imposible\n");
		exit(-1);
	}
	p->ip--;
}
void	affp(pile p)
{
	printf("+++++++++++++++++Voila Votre Stack :\n|");
	while(!videp(p))
	{
		printf("%5d|\t", valp(p));
		delp(&p);
	}
	printf("\n++++++++++++++++++++++++++++++++++++\n");
}
void	remplirp(pile *p)
{
	int	x;
	printf("******Remplir Pile******\n");
	while(1337)
	{
		printf("Donner la valeur de x (-1 for stop):\t");
		scanf("%d", &x);
		if(x >= 0)
			addp(x,p);
		else
			break;
	}
}
void	DepilerK(int k, pile *p)
{
	while(!videp(*p) && k>0)
	{
		delp(p);
		k--;
	}	
}
void	Depilerelt(int elt, pile *p)
{
	while(!videp(*p) && valp(*p) != elt)
		delp(p);
}
int	App(int x,pile p)
{
	if(videp(p))
	{
		printf("La pile est vide\n");
		return 0;
	}
	for(int i=p.ip;i>=0;i--)
	{
		if(p.TP[i] == x)
			return 1;
	}
	return 0;
}
