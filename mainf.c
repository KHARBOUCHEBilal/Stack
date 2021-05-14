#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "pile.h"
void	Invf(file* );
int	comparer(file , file );
void	defilerEnfiler(file* , file* );
void	permuterFile(file* , file* );
void	Tri(file ,file* );
void	Invf(file *f)
{
	pile	p;
	writep(&p);
	while(!videf(*f))
	{
		addp(valf(*f), &p);
		delf(f);
	}
	while(!videp(p))
	{
		addf(valp(p), f);
		delp(&p);
	}
}
int	comparer(file f1, file f2)
{
	if(videf(f1) || videf(f2))
	{
		printf("Comparison impossible\n");
		return -1;
	}
	if(valf(f1) >= valf(f2))
		return 1;
	return 0;
}
void	defilerEnfiler(file *f1, file *f2)
{
	if(!videf(*f1))
	{
		addf(valf(*f1), f2);
		delf(f1);
	}
	else	printf("premier file est vide\n");
}
void	permuterFile(file *f1, file *f2)
{
	file	f3;
	writef(&f3);
	while(!videf(*f1))
	{
		addf(valf(*f1), &f3);
		delf(f1);
	}
	while(!videf(*f2))
	{
		addf(valf(*f2), f1);
		delf(f2);
	}
	while(!videf(f3))
	{
		addf(valf(f3), f2);
		delf(&f3);
	}
}
void	Tri(file f1, file* f2)
{
	file	f3;
	writef(&f3);
	defilerEnfiler(&f1, f2);
	while(!videf(f1))
	{
		while(!videf(*f2) && comparer(f1, *f2))
			defilerEnfiler(f2, &f3);
		defilerEnfiler(&f1, &f3);
		while(!videf(*f2))
			defilerEnfiler(f2, &f3);
		permuterFile(f2, &f3);
	}
}
int     main(int argc, char* argv)
{
        file    *a;
        a = (file *)    malloc(sizeof(file));
        writef(a);
	file	f2;
	writef(&f2);
        int     x, i;
        while(42)
        {
                printf("***************This programme created by Brav0********************\n");
                printf("|1|: Remplir File  \t|2|: Afficher File \t|3|: Test Vide\n");
                printf("|4|: Add 1 Elt     \t|5|: Valeur File   \t|6|: Delete 1 Elt\n");
                printf("|7|: Defiler Jusqu'a Elt|8|: Inverser File\t|9|: Tri file\n");
		printf("******************************************************************\n");
                printf("Entrer nombre beqeen 1 and 8 others for quit :\t");
                scanf("%d", &i);
		printf("******************************************************************\n");
                switch(i)
                {
                        case 1: remplirf(a); 
				break;
                        case 2: afff(*a); 
				break;
                        case 3: if(videf(*a))	printf("File est vide\n");
                                else		printf("File not Vide\n");
                                break;
			case 4: printf("Donner une valeur :\t");
				scanf("%d", &x);
				addf(x, a);
				break;
                        case 5: printf("Valeur De La file est ##[%5d]## \n", valf(*a));
				break;
                        case 6: delf(a);
				break; 
                        case 7: scanf("%d", &x);
				Defilerelt(x, a);
				break;
			case 8: Invf(a); 
				break;
			case 9: Tri(*a, &f2);
				break;
                        default: free(a);
				 printf("Good By chabab\n");
				 exit(0);
                }
        }

}
