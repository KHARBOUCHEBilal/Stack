#define	N	50
typedef	struct	{
			int	TP[N];
			int	ip;
		}pile;
void	writep(pile *);
int	videp(pile );
int	valp(pile );
int	addp(int ,pile *);
void	delp(pile *);
void	affp(pile );
void	remplirp(pile *);
void	DepilerK(int ,pile *);
void	Depilerelt(int ,pile *);
int	App(int ,pile );
