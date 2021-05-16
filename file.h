#define	N	50
typedef	struct	{
			int	TF[N];
			int	it;
			int	iq;
		}file;
void	writef(file *f);
int	videf(file f);
int	valf(file f);
int	addf(int x,file *f);
int	delf(file *f);
void	afff(file f);
void	remplirf(file *f);
void	Defilerelt(int ,file *);
