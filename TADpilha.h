#define MAXPILHA 52
struct tpcarta
{
	int naipe,valor,cor,virada;
};
struct tppilha
{
	tpcarta pilha[MAXPILHA];
	int topo;
	
};
void inicializar(tppilha &pill)
{
	pill.topo=-1;
}
void push (tppilha &pill,tpcarta ele)
{
	pill.pilha[++pill.topo]=ele;
}
tpcarta pop (tppilha &pill)
{
	return pill.pilha[pill.topo--];
}
tpcarta topo (tppilha pill)
{
	return pill.pilha[pill.topo];
}
int cheia (int topo)
{
	return topo==MAXPILHA-1;
}
int vazia(int topo)
{
	return topo==-1;
}
void exibe (tppilha pill)
{
	tpcarta receptor;
	while(!vazia(pill.topo))
	{
		receptor=pop(pill);
		printf("%c %d %d\n",receptor.naipe,receptor.valor,receptor.cor);
	}
}
