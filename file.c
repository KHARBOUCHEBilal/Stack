#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "pile.h"
void	writef(file *f)
{
	f -> it = 0;
	f -> iq = 0;
}

int	videf(file f)
{
	if((f.it) == (f.iq))
		return 1; //vide == 1 non vide == 0
	return 0;
}
int	valf(file f)
{
	if(!videf(f))
		return (f.TF[f.it+1]);
	printf("Valeur non defenie\n");
	exit(EXIT_FAILURE);
}
int	addf(int x,file *f)
{
	f -> iq++;
	if(f->iq < 50)
	{
		f -> TF[f->iq] = x;
		return 1;
	}
	printf("implementation insuffisante\n");
	exit(-1);
}
int	delf(file *f)
{
	return f->it++;
}
void	afff(file f)
{
	printf("+++++++++++++++++Voila Votre File : \n|");
	while(!videf(f))
	{
		printf("%5d|\t", valf(f));
		delf(&f);
	}
	printf("\n+++++++++++++++++++++++++++++++++++\n");
}
void	remplirf(file* f)
{
	int	x;
	printf("remplir la file\n");
	while(10)
	{
		printf("Donner un entier :(-1 pour stop) :\t");
		scanf("%d", &x);
		if(x >= 0)
			addf(x,f);
		else
			break;
	}
}
void	Defilerelt(int x,file *f)
{
	while(!videf(*f) && (valf(*f) != x))
		delf(f);
}
