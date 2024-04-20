#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include <windows.h>

#include "TADpilha.h"
#include "TADpilhasmultiplas.h"

void layout()
{
	textbackground(2);
	for(int i=0;i<150;i++)
	{
		for(int j=0;j<48;j++)
		{
			gotoxy(i,j);
			printf(" ");
		}
	}
	textbackground(0);
}
void quadrado2(int ci, int li,int cf,int lf)
{
	gotoxy(ci,li);
	textcolor(4);
        printf("%c",4);
    gotoxy(ci,lf);
    textcolor(0);
        printf("%c",6);
    gotoxy(cf,li);
    textcolor(0);
        printf("%c",5);
    gotoxy(cf,lf);
    textcolor(4);
        printf("%c",3);
        
    for(int i=ci+1;i<cf;i++)
    {
    	textcolor(4);
    	if(i%2==0)
    	{
	    	gotoxy(i,li);
	    	printf("%c",4);
	    	gotoxy(i,lf);
	    	printf("%c",4);	
    	}
    	else
    	{
    		gotoxy(i,li);
	    	printf("%c",3);
	    	gotoxy(i,lf);
	    	printf("%c",3);	
    	}
    	
    }
    for(int i=li+1;i<lf;i++)
    {
    	textcolor(0);
    	if(i%2==0)
    	{
	    	gotoxy(ci,i);
	    	printf("%c",5);
	    	gotoxy(cf,i);
	    	printf("%c",5);
    	}
    	else
    	{
    		gotoxy(ci,i);
	    	printf("%c",6);
	    	gotoxy(cf,i);
	    	printf("%c",6);	
    	}
    	
    }
    textcolor(15);
}
void quadrado(int ci,int li,int cf,int lf,int cor)
{
	textcolor(cor);
	gotoxy(ci,li);
        printf("%c",381);
    gotoxy(ci,lf);
        printf("%c",200);
    gotoxy(cf,li);
        printf("%c",187);
    gotoxy(cf,lf);
        printf("%c",188);
        
    for(int i=ci+1;i<cf;i++)
    {
    	gotoxy(i,li);
    	printf("%c",205);
    	gotoxy(i,lf);
    	printf("%c",205);
    }
    for(int i=li+1;i<lf;i++)
    {
    	gotoxy(ci,i);
    	printf("%c",186);
    	gotoxy(cf,i);
    	printf("%c",186);
    }
    textcolor(15);
}

char menu()
{
	system("cls");
	quadrado(1,1,80,25,4);
	quadrado(2,2,24,15,7);
	gotoxy(2,22);
	printf("Developed by CAUA");
	quadrado(25,2,78,24,4);
	gotoxy(4,3);
	printf("[A]- Cria Baralho");
	gotoxy(4,4);
	printf("[B]- Embaralhar");
	gotoxy(4,5);
	printf("[C]- Para JOGAR!!!");
	return toupper(getch());
}

void gerarbaralho(tppilha &baralho)
{
	tpcarta aux;
	inicializar(baralho);
	int i,j;
	for(i=0;i<4;i++)
	{
		for (j=1;j<14;j++)
		{
			if(i==0||i==1)
			{
				aux.cor=4;
				aux.naipe=i+3;
				aux.valor=j;
				aux.virada=0;
			}
			else
			{
				aux.cor=0;
				aux.naipe=i+3;
				aux.valor=j;
				aux.virada=0;
			}
			push(baralho,aux);
		}
	}
	gotoxy(27,3);
	printf("Baralho gerado com sucesso\n");
	getche();
	
}
void embaralhar(tppilha &baralho)
{
	tppilham aux;
	inicializarm(aux,4);
	tpcarta reg;
	int random;
	for(int i=0;i<30;i++)
	{
		while(!vazia(baralho.topo))
		{
			random=rand()%3+1;
		
			if(!cheiam(aux,random))
			{
				reg=pop(baralho);
				pushm(aux,random,reg);
			}	
		}
		while(!cheia(baralho.topo))
		{
			random=rand()%3+1;
			
			if(!vaziam(aux,random))
			{
				reg=popm(aux,random);
				push(baralho,reg);
			}
		
		}
	}
	gotoxy(27,3);
	printf("Baralho esta embaralhado\n");
	getche();
}
void mostratopos(tppilham &montes)
{
	tpcarta reg;
	int i;
	for(i=1;i<13;i++)
	{
		reg=popm(montes,i);
		reg.virada=1;
		pushm(montes,i,reg);
	}
}
char verificavalor(int valor)
{
	if(valor==11)
	{
		return 'J';	
	}
	else
	if(valor==12)
	{
		return 'Q';
	}
	else
	if(valor==13)
	{
		return 'K';
	}
	if(valor==1)
	{
		return 'A';
	}
	else
	{
		return 'n';
	}
}
void exibemontes (tppilham montes)
{
	
	tpcarta reg;
	textbackground(2);
	textcolor(0);
	gotoxy(3,42);
	printf("[W]-Vira carta");
	gotoxy(3,43);
	printf("[M]-Movimento unico");
	gotoxy(3,44);
	printf("[N]-Movimento multiplo");
	gotoxy(3,45);
	printf("[R]-Volta o resto");
	gotoxy(7,2);
	printf("    [0]    ");
	gotoxy(23,2);
	printf("    [1]    ");
	gotoxy(77,2);
	printf("    [2]    ");
	gotoxy(92,2);
	printf("    [3]    ");
	gotoxy(107,2);
	printf("    [4]    ");
	gotoxy(122,2);
	printf("    [5]    ");
	gotoxy(142,14);
	printf("[12]");
	gotoxy(123,14);
	printf("[11]");
	gotoxy(104,14);
	printf("[10]");
	gotoxy(85,14);
	printf("[9]");
	gotoxy(66,14);
	printf("[8]");
	gotoxy(47,14);
	printf("[7]");
	gotoxy(28,14);
	printf("[6]");
	textbackground(15);
	textcolor(0);
	for(int k=4;k<10;k++)
	{
		gotoxy(7,k);
		printf("           ");
		gotoxy(23,k);
		printf("           ");
		gotoxy(77,k);
		printf("           ");
		gotoxy(92,k);
		printf("           ");
		gotoxy(107,k);
		printf("           ");	
		gotoxy(122,k);
		printf("           ");	
	}
	

	char i;
	if(!vaziam(montes,0))
	{
		gotoxy(10,6);
		printf("CARTA");
	}
	else
	{
		gotoxy(10,6);
		printf("VAZIO");
	}
	
	if(!vaziam(montes,1))
	{
		reg=popm(montes,1);
		textcolor(reg.cor);
		gotoxy(25,8);
		printf("%c",reg.naipe);
		gotoxy(31,5);
		printf("%c",reg.naipe);
		i=verificavalor(reg.valor);
		if(i!='n')
		{
			gotoxy(25,5);
			printf("%c",i);
			gotoxy(31,8);
			printf("%c",i);
		}
		else
		{
			gotoxy(25,5);
			printf("%d",reg.valor);
			gotoxy(31,8);
			printf("%d",reg.valor);	
		}
	}
	else
	{
		gotoxy(26,6);
		printf("VAZIO");
	}
	textcolor(0);
	if(!vaziam(montes,2))
	{
		reg=popm(montes,2);
		textcolor(reg.cor);
		i=verificavalor(reg.valor);
		if(i!='n')
		{
			gotoxy(79,5);
			printf("%c",i);
			gotoxy(85,8);
			printf("%c",i);
		}
		else
		{
			gotoxy(79,5);
			printf("%d",reg.valor);
			gotoxy(85,8);
			printf("%d",reg.valor);
		}
		gotoxy(79,8);
		printf("%c",reg.naipe);
		gotoxy(85,5);
		printf("%c",reg.naipe);
	
	}
	else
	{
		gotoxy(80,6);
		printf("VAZIO");
	}
	textcolor(0);
	if(!vaziam(montes,3))
	{
		reg=popm(montes,3);
		textcolor(reg.cor);
		i=verificavalor(reg.valor);
		if(i!='n')
		{
			gotoxy(94,5);
			printf("%c",i);
			gotoxy(100,8);
			printf("%c",i);
		}
		else
		{
			gotoxy(94,5);
			printf("%d",reg.valor);
			gotoxy(100,8);
			printf("%d",reg.valor);
		}
		gotoxy(94,8);
		printf("%c",reg.naipe);
		gotoxy(100,5);
		printf("%c",reg.naipe);
		
	}
	else
	{
		gotoxy(95,6);
		printf("VAZIO");
	}
	textcolor(0);
	if(!vaziam(montes,4))
	{
		reg=popm(montes,4);
		textcolor(reg.cor);
		i=verificavalor(reg.valor);
		if(i!='n')
		{
			gotoxy(109,5);
			printf("%c",i);
			gotoxy(115,8);
			printf("%c",i);
		}
		else
		{
			gotoxy(109,5);
			printf("%d",reg.valor);
			gotoxy(115,8);
			printf("%d",reg.valor);
		}
		gotoxy(109,8);
		printf("%c",reg.naipe);
		gotoxy(115,5);
		printf("%c",reg.naipe);	
	}
	else
	{
		gotoxy(110,6);
		printf("VAZIO");
	}
	textcolor(0);
	if(!vaziam(montes,5))
	{
		reg=popm(montes,5);
		textcolor(reg.cor);
		i=verificavalor(reg.valor);
		if(i!='n')
		{
			gotoxy(124,5);
			printf("%c",i);
			gotoxy(130,8);
			printf("%c",i);
		}
		else
		{
			gotoxy(124,5);
			printf("%d",reg.valor);
			gotoxy(130,8);
			printf("%d",reg.valor);
		}
		gotoxy(124,8);
		printf("%c",reg.naipe);
		gotoxy(130,5);
		printf("%c",reg.naipe);
	}
	else
	{
		gotoxy(125,6);
		printf("VAZIO");
	}
	textcolor(0);
	tppilha aux;
	int x,y,j;
	x=25;
	for(j=6;j<13;j++)
	{
		inicializar(aux);
		while(!vaziam(montes,j))
		{
			reg=popm(montes,j);
			push(aux,reg);
		}
		y=15;
		while(!vazia(aux.topo))
		{
			reg=pop(aux);
			gotoxy(x,y);

			if(reg.virada==1)
			{
				printf("          ");
				gotoxy(x,y+1);
				printf("          ");
				gotoxy(x,y+2);
				printf("          ");
				gotoxy(x,y+3);
				printf("          ");
				gotoxy(x,y+4);
				printf("          ");
				gotoxy(x,y+5);
				
				
				
				textbackground(15);
				textcolor(reg.cor);
				gotoxy(x,y+1);
				i=verificavalor(reg.valor);
				
					if(i!='n')
					{
						printf(" %c     %c ",i,reg.naipe);
						gotoxy(x,y+4);
						printf(" %c     %c ",i,reg.naipe);
					}
					else
					{
						printf(" %d     %c ",reg.valor,reg.naipe);
						gotoxy(x,y+4);
						printf(" %d     %c ",reg.valor,reg.naipe);
					}
				
				textbackground(4);
				gotoxy(x,y+5);
				printf("          ");
				gotoxy(x,y);
				printf("         ");
				gotoxy(x,y+1);
				printf(" ");
				gotoxy(x,y+2);
				printf(" ");
				gotoxy(x,y+3);
				printf(" ");
				gotoxy(x,y+4);
				printf(" ");
				gotoxy(x,y+5);
				printf(" ");
		
				
				gotoxy(x+9,y);
				printf(" ");
				gotoxy(x+9,y+1);
				printf(" ");
				gotoxy(x+9,y+2);
				printf(" ");
				gotoxy(x+9,y+3);
				printf(" ");
				gotoxy(x+9,y+4);
				printf(" ");
				gotoxy(x+9,y+5);
				printf(" ");
				textbackground(15);
			}
			else
			{
				
				gotoxy(x,y);
				textbackground(0);
				printf("          ");
				gotoxy(x,y+1);
				textbackground(3);
				printf("          ");
				
				textbackground(0);
				gotoxy(x,y+1);
				printf(" ");
				gotoxy(x+9,y+1);
				printf(" ");
				textbackground(15);
				
			}
			textcolor(15);
			y+=2;
		}
		x+=19;
	}
	textbackground(2);
	textcolor(15);
	
}
int verificaseganhou(tppilham montes)
{
	tpcarta reg,reg1,reg2,reg3;
	int i;
	reg=popm(montes,2);
	reg1=popm(montes,3);
	reg2=popm(montes,4);
	reg3=popm(montes,5);
	if(reg.valor==13&&reg1.valor==13&&reg2.valor==13&&reg3.valor==13)
	{
		i=0;
	}
	else
	i=-1;
	
	return i;
}

tpcarta posicao (tppilham montes,int num1,int num3)
{
	tpcarta reg;
	for(int i=0;i<num3&&(!vaziam(montes,num1));i++)
	{
		reg=popm(montes,num1);
	}
	return reg;
}

void jogar (tppilha baralho)
{
	system("cls");
	textbackground(0);
	tppilham montes;
	tppilha meio;
	tpcarta reg,aux1,aux2;
	int i,num1,num2,num3;
	char op;
	inicializarm(montes,13);
	//0-RESTO,1-VIRADAS,2-PAUS,3-OUROS,4-ESPADAS,5-COPAS,6-MONTE1,7-MONTE2,8-MONTE3,9-MONTE4
	//10-MONTE5,11-MONTE6,12-MONTE7
	
		for(i=0;i<7;i++)
		{
			reg=pop(baralho);
			pushm(montes,12,reg);
		}
		for(i=7;i<13;i++)
		{
			reg=pop(baralho);
			pushm(montes,11,reg);	
		}
		for(i=13;i<18;i++)
		{
			reg=pop(baralho);
			pushm(montes,10,reg);
		}
		for(i=18;i<22;i++)
		{
			reg=pop(baralho);
			pushm(montes,9,reg);
		}
		for(i=22;i<25;i++)
		{
			reg=pop(baralho);
			pushm(montes,8,reg);
		}
		for(i=25;i<27;i++)
		{
			reg=pop(baralho);
			pushm(montes,7,reg);
		}
		for(i=27;i<28;i++)
		{
			reg=pop(baralho);
			pushm(montes,6,reg);
		}
		for(i=28;i<52;i++)
		{
			reg=pop(baralho);
			pushm(montes,0,reg);
		}
	do
	{
			textbackground(0);
			system("cls");
			layout();
			mostratopos(montes);
			exibemontes(montes);
			gotoxy(3,46);
			printf("                                            ");
			gotoxy(3,46);
			printf("Digite a opcao");
			fflush(stdin);
			gotoxy(3,47);
			op=toupper(getche());
			gotoxy(3,47);
			printf(" ");
		switch(op)
		{
			case 'R':
				{
					if(vaziam(montes,0))
					{
						if(!vaziam(montes,1))
						{
							while(!vaziam(montes,1))
							{
								reg=popm(montes,1);
								pushm(montes,0,reg);
							}
							gotoxy(3,46);
							printf("Monte resto recarregado");
						}
						else
						{
							gotoxy(3,46);
							printf("Nao possui cartas para retornar ao monte");
						}
					}
					else
					{
						gotoxy(3,46);
						printf("O monte de resto nao esta vazio");	
					}
					break;
				}
			case 'M':
				{
				gotoxy(3,46);	
				printf("Digite o monte que deseja mover, e para qual deseja mover\n");
				fflush(stdin);
				gotoxy(3,47);
				scanf("%d",&num1);// leio o monte endereco velho
						gotoxy(6,47);
						scanf("%d",&num2); // leio o monte endereco novo
						if(num2!=0&&num2!=1)//se nao quiser mover para o monte de resto nem das viradas
						{
							if(num1!=num2)//se o valor dos montes forem diferentes
							{
								if(!vaziam(montes,num1))//se o monte endereco velho nao for vazio
								{
									aux1=topom(montes,num1);//recebo o topo do monte velho
									aux2=topom(montes,num2);//recebo o topo do monte novo
									if(num2!=2&&num2!=3&&num2!=4&&num2!=5)//se o monte endereco novo nao é dos naipes
									{
										if(!vaziam(montes,num2))//se o monte 2 nao estiver vazio
										{
											if(aux1.cor!=aux2.cor&&aux1.valor==aux2.valor-1)//se o monte 2 nao esta vazio, verifica se a topo do monte 1 tem cor  diferente e o topo do monte 1 é 1 valor a menos que o monte 2
											{
												reg=popm(montes,num1);//retiro do monte 1 e jogo pro 2
												pushm(montes,num2,reg);
												gotoxy(3,46);
												printf("                                                                                      ");
												gotoxy(3,46);
												printf("Voce moveu uma carta <3");
											}
											else// se nao for cor diferente ou o valor nao for == -1
											{
												gotoxy(3,46);
												printf("                                                                                            ");
												gotoxy(3,46);
												printf("Nao e possivel mover");
											}
										}
										else//se o monte para qual desejo mover esteja vazio
											if(aux1.valor==13)//se o valor da carta do monte 1 for um rei(13)
											{
												reg=popm(montes,num1);
												pushm(montes,num2,reg);
												gotoxy(3,46);
												printf("                                                                                                 ");
												gotoxy(3,46);
												printf("Voce moveu um rei para um monte vazio");
											}
									}
									else//se o monte endereço for dos naipes
										{
											if(aux1.naipe==3)
											{
												if(vaziam(montes,2))//verifico se o monte do naipe esta vazio 
												{
													
													if(aux1.valor==1)//se estiver vazio, verifico se o valor que quer inserir é as
													{
														reg=popm(montes,num1);
														pushm(montes,2,reg);
													}
													else
													{
														gotoxy(3,46);
														printf("                                                                                                 ");
														gotoxy(3,46);
														printf("Voce so pode mover um as para esse monte");	
													}
													
												}
												else//se nao estiver vazio
												{
													aux2=topom(montes,2);
													if(aux1.valor==aux2.valor+1)//verifico se o valor que quer inserir -1 é igual ao valor do monte
													{
														reg=popm(montes,num1);
														pushm(montes,2,reg);
													}
													else
													{
														gotoxy(3,46);
														printf("                                                                                                 ");
														gotoxy(3,46);
														printf("Nao e possivel mover");
													}
												}
											}
											else
											{
												if(aux1.naipe==4)
												{
													if(vaziam(montes,3))//verifico se o monte do naipe esta vazio 
													{
														
														if(aux1.valor==1)//se estiver vazio, verifico se o valor que quer inserir é as
														{
															reg=popm(montes,num1);
															pushm(montes,3,reg);
														}
														else
														{
															gotoxy(3,46);
															printf("                                                                                                 ");
															gotoxy(3,46);
															printf("Voce so pode mover um as para esse monte");
														}
														
													}
													else//se nao estiver vazio
													{
														aux2=topom(montes,3);
														if(aux1.valor==aux2.valor+1)//verifico se o valor que quer inserir -1 é igual ao valor do monte
														{
															reg=popm(montes,num1);
															pushm(montes,3,reg);
														}
														else
														{
															gotoxy(3,46);
															printf("                                                                                                 ");
															gotoxy(3,46);
															printf("Nao e possivel mover");
														}
													}
												}
												else
												{
													if(aux1.naipe==5)
													{
														if(vaziam(montes,4))//verifico se o monte do naipe esta vazio 
														{
															
															if(aux1.valor==1)//se estiver vazio, verifico se o valor que quer inserir é as
															{
																reg=popm(montes,num1);
																pushm(montes,4,reg);
															}
															else
															{
																gotoxy(3,46);
																printf("                                                                                                 ");
																gotoxy(3,46);
																printf("Voce so pode mover um as para esse monte");
															}
															
														}
														else//se nao estiver vazio
														{
															aux2=topom(montes,4);
															if(aux1.valor==aux2.valor+1)//verifico se o valor que quer inserir -1 é igual ao valor do monte
															{
																reg=popm(montes,num1);
																pushm(montes,4,reg);
															}
															else
															{
																gotoxy(3,46);
													     		printf("                                                                                                 ");
																gotoxy(3,46);
																printf("Nao e possivel mover");
															}
														}
													}
													else
													{
														if(vaziam(montes,5))//verifico se o monte do naipe esta vazio 
														{
															
															if(aux1.valor==1)//se estiver vazio, verifico se o valor que quer inserir é as
															{
																reg=popm(montes,num1);
																pushm(montes,5,reg);
															}
															else
															{
																gotoxy(3,46);
																printf("                                                                                                 ");
																gotoxy(3,46);
																printf("Voce so pode mover um as para esse monte");
															}
															
														}
														else//se nao estiver vazio
														{
															aux2=topom(montes,5);
															if(aux1.valor==aux2.valor+1)//verifico se o valor que quer inserir -1 é igual ao valor do monte
															{
																reg=popm(montes,num1);
																pushm(montes,5,reg);
															}
															else
															{
																gotoxy(3,46);
																printf("                                                                                                 ");
																gotoxy(3,46);
																printf("Nao e possivel mover");
															}
														}
													}
												}
											}
											
											
										}	
								}
								else
								{
									gotoxy(3,46);
									printf("                                                                     ");
									gotoxy(3,46);
									printf("O primeiro monte selecionado esta vazio\n");
								}
								
							}
							else
							{
								gotoxy(3,46);
								printf("                                                                   ");
								gotoxy(3,46);
								printf("Voce nao pode mover para o mesmo monte");
							}	
						}
						else
						{
								gotoxy(3,46);
								printf("                                                                   ");
								gotoxy(3,46);
								printf("Voce nao pode mover para esse monte");
						}
						break;	
				}
			case 'N':
				{
					
					gotoxy(3,46);	
					printf("Digite o monte que deseja mover                         ");
					fflush(stdin);
					gotoxy(3,47);
					scanf("%d",&num1);// leio o monte endereco velho
					gotoxy(3,46);
					printf("Digite a posicao desse monte que deseja mover                         ");
					gotoxy(6,47);
					scanf("%d",&num3);
					gotoxy(3,46);
					printf("Digite para qual monte deseja mover                               ");
					gotoxy(9,47);
					scanf("%d",&num2); // leio o monte endereco novo
					
					if(!vaziam(montes,num1))//se nao estiver vazio
					{
						if(num1>5&&num1<13)//se for um monte do 6 ao 12
						{
							if(num3>0&&num3<21)//se for uma posicao valida
							{
								if(num2>5&&num2<13)//se for um monte do 6 ao 12
								{
									if(vaziam(montes,num2))//se estiver vazio só pode mover rei
									{
										aux1=posicao(montes,num1,num3);
										if(aux1.virada==1)
										{
											if(aux1.valor==13)
											{
												inicializar(meio);
												for(i=0;i<num3;i++)
												{
													aux2=popm(montes,num1);
													push(meio,aux2);
												}
												for(;!vazia(meio.topo);)
												{
													aux2=pop(meio);
													pushm(montes,num2,aux2);
												}
												gotoxy(3,46);
												printf("                                      ");
												gotoxy(3,46);
												printf("Voce moveu");
											}
											else
											{	gotoxy(3,46);
												printf("                                      ");
												gotoxy(3,46);
												printf("Voce so pode mover um rei para esse monte");
											}
										}
										else
										{
											gotoxy(3,46);
												printf("                                      ");
												gotoxy(3,46);
											printf("A carta nao esta virada");
										}
									
									}
									else//se o monte nao for vazio
									{
										aux2=topom(montes,num2);
										aux1=posicao(montes,num1,num3);
										if(aux1.virada==1)
										{
											if(aux1.valor==aux2.valor-1&&aux1.cor!=aux2.cor)//se a posicao qu
											{
												inicializar(meio);
												for(i=0;i<num3;i++)
												{
													reg=popm(montes,num1);
													push(meio,reg);
												}
												for(;!vazia(meio.topo);)
												{
													reg=pop(meio);
													pushm(montes,num2,reg);
												}
												gotoxy(3,46);
												printf("                                      ");
												gotoxy(3,46);
												printf("Voce moveu");
											}
											else
											{
												gotoxy(3,46);
												printf("                                      ");
												gotoxy(3,46);
												printf("Nao e possivel mover");
											}
										}
										else
										{
											gotoxy(3,46);
												printf("                                      ");
												gotoxy(3,46);
											printf("A carta nao esta virada");
										}										
										
									}
								}
								else
								{
									gotoxy(3,46);
												printf("                                      ");
												gotoxy(3,46);
									printf("Monte invalido");
								}
								
							}
							else
							{
								gotoxy(3,46);
												printf("                                      ");
												gotoxy(3,46);
								printf("Posicao invalida");
							}
							
						}
						else
						{
							gotoxy(3,46);
												printf("                                      ");
												gotoxy(3,46);
							printf("Voce nao pode mover multiplas cartas desse monte");
						}
						
					}
					else
					{
						gotoxy(3,46);
												printf("                                      ");
												gotoxy(3,46);
						printf("O monte esta vazio");
					}
					break;
				}
			case 'W':
				{
					if(!vaziam(montes,0))//se o monte de resto nao estivar vazio
					{
						reg=popm(montes,0);
						pushm(montes,1,reg);
						gotoxy(3,46);
						printf("                                                                                   ");
						gotoxy(3,46);
						printf("Voce virou uma carta");
					}
					else
					{
						gotoxy(3,46);
						printf("                                                                                   ");
						gotoxy(3,46);
						printf("O monte esta vazio");
					}
					break;	
				}
				
		}
		
	}while(op!=27&&verificaseganhou(montes)!=0);
	int k , j , x , y;
	if(verificaseganhou(montes)==0||op==27)
	{
		layout();
		exibemontes(montes);
		if(verificaseganhou(montes)!=0)
		{
			for(k=2;k<=5;k++)
			{
				for(j=0;j<=13;j++)
				{
					if(k==2||k==3)
					{
						aux1.cor=4;
						aux1.naipe=k+1;
						aux1.valor=j;
						aux1.virada=0;
					}
					else
					{
						aux1.cor=0;
						aux1.naipe=k+1;
						aux1.valor=j;
						aux1.virada=0;
					}
					pushm(montes,k,aux1);
				}
			}
		}	
		for(k=0;k<13;k++)
		{
			
	
			for(j=2;j<6;j++)
			{
				reg=popm(montes,j);
				i=verificavalor(reg.valor);
				if(j==2)
				{
					x=77;
					y=4;
				}
				else if(j==3)
				{
					x=92;
					y=4;
				}
				else
				if(j==4)
				{
					x=107;
					y=4;
				}
				else
				{
					x=122;
					y=4;
				}
			
				for(int w=0;w<30;w++)
				{
					textbackground(15);
					textcolor(reg.cor);
					gotoxy(x,y+1);
					i=verificavalor(reg.valor);
					
						if(i!='n')
						{
							printf(" %c     %c ",i,reg.naipe);
							gotoxy(x,y+4);
							printf(" %c     %c ",reg.naipe,i);
						}
						else
						{
							printf(" %d     %c ",reg.valor,reg.naipe);
							gotoxy(x,y+4);
							printf(" %d     %c ",reg.naipe,reg.valor);
						}
					
				
					Sleep(15);
					x--;
					y++;
				}
					textbackground(4);
					gotoxy(x,y+5);
					printf("          ");
					gotoxy(x,y);
					printf("         ");
					gotoxy(x,y+1);
					printf(" ");
					gotoxy(x,y+2);
					printf(" ");
					gotoxy(x,y+3);
					printf(" ");
					gotoxy(x,y+4);
					printf(" ");
					gotoxy(x,y+5);
					printf(" ");
			
					
					gotoxy(x+9,y);
					printf(" ");
					gotoxy(x+9,y+1);
					printf(" ");
					gotoxy(x+9,y+2);
					printf(" ");
					gotoxy(x+9,y+3);
					printf(" ");
					gotoxy(x+9,y+4);
					printf(" ");
					gotoxy(x+9,y+5);
					printf(" ");
				
			}
		}
		quadrado(50,15,110,35,4);
			textbackground(15);
		for(int i=51;i<110;i++)
		{
			for(int j=16;j<35;j++)
			{
				gotoxy(i,j);
				printf(" ");
			}
		}
		quadrado2(51,16,109,34);
		gotoxy(73,23);
		textcolor(0);
		printf("VOCE GANHOU");
		gotoxy(61,24);
		printf("DIGITE QUALQUER TECLA PARA VOLTAR AO MENU");
		getch();
		textcolor(15);
		textbackground(0);
	}

}
void exec()
{
	char op;
	tppilha baralho;
	inicializar(baralho);
	do
	{
		op=menu();
		switch(op)
		{
			case'A':
				gerarbaralho(baralho);
				break;
			case'B':
				embaralhar(baralho);
				break;
			case'C':
				jogar(baralho);
				break;
		}	
	}while(op!=27);
}

int main()
{
	srand(time(NULL));
	exec();
}
