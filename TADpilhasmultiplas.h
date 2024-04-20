#define MAXPILHAM 500
struct tppilham
{
	int topos[MAXPILHAM],bases[MAXPILHAM];
	tpcarta pilhas[MAXPILHAM];
};
void inicializarm(tppilham &pill,int qntd)
{
	int qntdele,i;
	qntdele=MAXPILHAM/qntd;
	for (i=0;i<qntd;i++)
	{
		pill.bases[i]=i*qntdele;
		pill.topos[i]=pill.bases[i]-1;
	}
}
void pushm(tppilham &pill,int qual,tpcarta ele)
{
	pill.pilhas[++pill.topos[qual]]=ele;
}
tpcarta popm(tppilham &pill,int qual)
{
	return pill.pilhas[pill.topos[qual]--];
}
tpcarta topom(tppilham pill,int qual)
{
	return pill.pilhas[pill.topos[qual]];
}
int cheiam(tppilham pill,int qual)
{
	return pill.topos[qual]==pill.bases[qual+1]-1;
}
int vaziam (tppilham pill,int qual)
{
	return pill.topos[qual]<pill.bases[qual];
}
void exibem(tppilham pill,int qual)
{
	tpcarta reg;
	while(!vaziam(pill,qual))
	{
		reg=popm(pill,qual);
		printf("|%d %c|",reg.valor,reg.naipe);
	}
}
