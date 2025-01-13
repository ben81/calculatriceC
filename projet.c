#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "nbrdef.h"
#include "addi.h"
#include "sous.h"
#include "multi.h"
#include "divi.h"
#include "fibo.h"
#include "facto.h"
#include "primo.h"




/********************************************************
*							*
*							*
*							*
*							*
*							*
********************************************************/
Tptrnombre op1,op2,result,memoire[10], quotient ,reste,cal[10];
char sc[20];
int menuview=1;


void stop(void);
void chercher(void)
{
	int i=0,min,max,found=0;
	printf("\t*----------------------------------------------------------*\n");
	printf("\t*  ALGORITHME de recherche de nombre premier		   *\n");
	printf("\t*  1) n! +- 1						   *\n");
	printf("\t*  2) 2 ^n +- 1   					   *\n");
	printf("\t*  3) n * n - n + 41 					   *\n");
	printf("\t*  4) n * n - 79 * n + 1601			           *\n");
	printf("\t*  5) produit des n premiers Premier - 1		   *\n");
	printf("\t*  6) produit des n premiers Premier + 1		   *\n");
	printf("\t*----------------------------------------------------------*\n");
	scanf("%s4" , sc);
	switch (sc[0])
	{
		case '1':
		{
			printf ("valeur min:");
			scanf("%s15", sc);
			min=atoi(sc);
			printf ("valeur max:");
			scanf("%s15", sc);
			max=atoi(sc);
			printline();
			for (i=min;i<=max; i++ )
			{
				factonbr(i,cal[1]);
				decremente(cal[1],1,cal[2]);
				if (primo(cal[2]))
				{
					printf("pour n=%d et - 1 :",i);
					printnbr(cal[2]) ;
					printf ("est premier \n");
					found=1;
				}
				incremente(cal[1],1,cal[2]);
				if (primo(cal[2]))
				{
					printf("pour n=%d et + 1 :",i);
					printnbr(cal[2]) ;
					printf ("est premier \n");
					found=1;
				}
			}
			if (found ==0 ) 
				printf("aucune nombre premier trouver\n");
			printline();
		}
		break;
		case '2':
		{
			printf ("valeur min:");
			scanf("%s15", sc);
			min=atoi(sc);
			printf ("valeur max:");
			scanf("%s15", sc);
			max=atoi(sc);
			printline();
			incremente(zero,2,cal[1]);
			for (i=min;i<=max; i++ )
			{
				puissance(cal[1],i,cal[3]);
				decremente(cal[3],1,cal[2]);
				if (primo(cal[2]))
				{
					printf("pour n=%d et - 1 :",i);
					printnbr(cal[2]) ;
					printf ("est premier \n");
					found=1;
				}
				incremente(cal[3],1,cal[2]);
				if (primo(cal[2]))
				{
					printf("pour n=%d et + 1 :",i);
					printnbr(cal[2]) ;
					printf ("est premier \n");
					found=1;
				}
			}
			if (found ==0 ) 
				printf("aucune nombre premier trouver\n");
			printline();
		}
		break;			
		case '3':
		{
			printf ("valeur min:");
			scanf("%s15", sc);
			min=atoi(sc);
			printf ("valeur max:");
			scanf("%s15", sc);
			max=atoi(sc);
			printline();
			for (i=min;i<=max; i++ )
			{
				incremente(zero,i,cal[1]);
				multinbrspeed(cal[1],cal[1],cal[2]);
				soustractionnbr(cal[2],cal[1], cal[3]);
				incremente(cal[3],41,cal[4]);
				if (primo(cal[4]))
				{
					printf("pour n=%d :",i);
					printnbr(cal[4]) ;
					printf ("est premier \n");
					found=1;
				}

			}
			if (found ==0 ) 
				printf("aucune nombre premier trouver\n");
			printline();
		}
		break;
		case '4':
		{
			printf("valeur min:");
			scanf("%s15", sc);
			min=atoi(sc);
			printf("valeur max:");
			scanf("%s15", sc);
			max=atoi(sc);
			printline();
			for (i=min;i<=max; i++ )
			{
				incremente(zero,i,cal[1]);
				multinbrspeed(cal[1],cal[1],cal[2]);
				multinbrint(cal[1],79,cal[5]);
				soustractionnbr(cal[2],cal[5], cal[3]);
				incremente(cal[3],41,cal[4]);
				if (primo(cal[4]))
				{
					printf("pour n=%d :",i);
					printnbr(cal[4]) ;
					printf ("est premier \n");
					found=1;
				}

			}
			if (found ==0 ) 
				printf("aucune nombre premier trouver\n");
			printline();
		}
		break;
		case '5':
		{
			printf ("N ieme premier:");
			scanf("%s15", sc);
			max=atoi(sc);
			incremente(zero,3,cal[1]);
			incremente(zero,6,cal[2]);
			printline();
			for (i=2;i<=max;i++)
			{
				do
				{
				incremente(cal[1],2,cal[1]);
				}
				while (!primo(cal[1]));
			multinbrspeed(cal[1],cal[2],cal[2]);
			decremente(cal[2],1,cal[3]);
			if (primo(cal[3]))
				{
					printf("pour n=%d :",i);
					printnbr(cal[3]) ;
					printf ("est premier \n");
					found=1;
				}	
				
			}
			if (found ==0 ) 
				printf("aucune nombre premier trouver\n");
			printline();
		}
		break;
		case '6':
		{
			printf ("N ieme premier:");
			scanf("%s15", sc);
			max=atoi(sc);
			incremente(zero,3,cal[1]);
			incremente(zero,6,cal[2]);
			printline();
			for (i=2;i<=max;i++)
			{
				do
				{
				incremente(cal[1],2,cal[1]);
				}
				while (!primo(cal[1]));
			multinbrspeed(cal[1],cal[2],cal[2]);
			incremente(cal[2],1,cal[3]);
			if (primo(cal[3]))
				{
					printf("pour n=%d :",i);
					printnbr(cal[3]) ;
					printf ("est premier \n");
					found=1;
				}

			}
			if (found ==0 )
				printf("aucune nombre premier trouver\n");
			printline();
		}
		break;
		default:;

	}
}
int nbrchoix(char *str ,Tptrnombre test )
{
	int sortie=1, menu=menuview;
	while(sortie==1)
	{
		if (menu==1)
		{
			printf("veuiller indiquer la source pour %s:\n",str);
			printf("\t*----------------------------------------------------------*\n");
			printf("\t*  i[n] entre clavier avec copie optionnel dans memoire n  *\n");
			printf("\t*  l[n] deinier valeur avec copie optionnel dans memoire n *\n");
			printf("\t*  q[n] quotient avec copie optionnel dans memoire n       *\n");
			printf("\t*  r[n] rester avec copie optionnel dans memoire n         *\n");
			printf("\t*  m<n> lecture  dans memoire n                            *\n");
			printf("\t*----------------------------------------------------------*\n");
		}
		sortie=0;
		menu=0;
		scanf("%s4" , sc);
		switch (sc[0])
		{
			case 'i':
			case 'I':
			saisienbr(test);
			if (isdigit(sc[1]))
			copienbr(test,memoire[sc[1]-'0']);
			break;

			case 'm':
			case 'M':
			if (isdigit(sc[1])) copienbr(memoire[sc[1]-'0'],test);
			break;

			case 'l':
			case 'L':
			copienbr(result,test);
			if (isdigit(sc[1])) copienbr(test,memoire[sc[1]-'0']);
			break;

			case 'q':
			case 'Q':
			copienbr(quotient,test);
			if (isdigit(sc[1]))
			copienbr(test,memoire[sc[1]-'0']);
			break;

			case 'r':
			case 'R':
			copienbr(reste,test);
			if (isdigit(sc[1])) copienbr(test,memoire[sc[1]-'0']);
			break;

			default  :sortie=1;
			break ;
		}
	}
	return 0;
}


void start (void)
{
	int i;
	makenbrdef();
	initmulti();
	/* alloue la memoire */
	op1= makenbr();
	op2= makenbr();
	result= makenbr();
	quotient= makenbr();
	reste= makenbr();
	for (i=0;i<10;i++)
	{
		memoire[i]=makenbr();
		cal[i]=makenbr();
	}
	/* execute stop() a la fin du programme */
	atexit(stop);
}

void stop(void)
{
	int i;
	printf("\n\n\t\tau revoir\n");
	/* dealloue la memoire */
	donenbr(op1);
	donenbr(op2);
	donenbr(result);
	donenbr(quotient);
	donenbr(reste);
	for (i=0;i<10;i++)
	{
		donenbr(memoire[i]);
		donenbr(cal[i]);
	}
	donenbrdef();
	donemulti();
}

int main(void)
{
	int i;
	system("cls");
	start();
	while (1)
	{
		if (menuview==1 )
		{
			printf("\n");
			printf("\t*----------------------------------------------------------*\n");
			printf("\t*            Bienvenue dans les nombres geants             *\n");
			printf("\t*----------------------------------------------------------*\n");
			printf("\t*                   Choisissez une operation               *\n");
			printf("\t*----------------------------------------------------------*\n");
			printf("\t* A) +  S) - M) *  D) / %%  P) puissance                    *\n");
			printf("\t* 1) fibonacci 2)factoriel 				   *\n");
			printf("\t* 3) nb premier 4) dec premier 5) rch premier	   	   *\n");
			printf("\t* Q) quitter V) memoire  I) info		           *\n");
			printf("\t*----------------------------------------------------------*\n");
		}
		scanf("%s4",sc);
		switch (sc[0])
		{
			case 'a':
			case 'A':	
			printf("addition\n");
			nbrchoix("ADD1",op1);
			nbrchoix("ADD2",op2);
			additionnbr(op1,op2,result);
			printf("resultat:");
			printnbr(result);
			printf("\n");
			break;

			case 's':
			case 'S':
			printf("soustraction\n");
			nbrchoix("SZUS1",op1);
			nbrchoix("SZUS2",op2);
			soustractionnbr(op1,op2,result);
			printf("resultat:");
			printnbr(result);
			printf("\n");
			break;

			case 'm':
			case 'M':
			printf("multiplication\n");
			nbrchoix("MUL1",op1);
			nbrchoix("MUL2",op2);
			multinbrspeed(op1,op2,result);
			printf("resultat:");
			printnbr(result);
			printf("\n");
			break;

			case 'p':
			case 'P':
			printf("puissance\n");
			nbrchoix("base",op1);
			printf("exposant:");
			scanf("%s5", sc);
			i=atoi(sc);
			puissance(op1,i, result);
			printf("resultat:");
			printnbr(result);
			printf("\n");
			break;

			case 'd':
			case 'D':
			printf("division\n");
			nbrchoix("DIV1",op1);
			nbrchoix("DIV2",op2);
			divisionnbrspeed(op1,op2,quotient, reste);
			printf("quotient:");
			printnbr(quotient);
			printf("\nreste:");
			printnbr(reste);
			printf("\n");
			copienbr(quotient , result);
			break;

			case '1':
			printf("fibonacchi de:");
			scanf("%s5", sc);
			i=atoi(sc);
			fibonbr(i,result);
			printnbr(result);
			printf("\n");
			break;

			case '2':
			printf("factoriel de:");
			scanf("%s5", sc);
			i=atoi(sc);
			factonbr(i,result);
			printnbr(result);
			printf("\n");
			break;

			case '3':
			nbrchoix("premier\n",op1);
			printnbr(op1);
			printf("\n");
			if ( primo(op1)) { printf(" est premier\n"); } else {printf(" n'est pas premier\n"); }
			break;



			case '4':
			printf("decomposition de:\n");
			nbrchoix("DECP",op1);
			printf("\n");
			printf("%d",divisible(op1));
			decompose(op1);
			break;

			case '5':
			chercher();
			break ;

			case 'i':
			case 'I':
			printf("Developpe par benoit FERRERO et johnathan RENAUD,\n");
			printf("ce programme effectue des operations de base avec les chiffres geants \n");
			printf("compiler le %s:%s \n",  __DATE__,__TIME__);
			break;

			case 'q':
			case 'Q':
			exit(1);

			case '@':
			if (sc[1]=='v') { menuview=1;}
			if (sc[1]=='V') { menuview=1;}
			if (sc[1]=='o') { menuview=0;}
			if (sc[1]=='O') { menuview=0;}
			break;

			case 'v':
			case 'V':
			printf("memoire de:");
			scanf("%d",&i);
			if ((i>=0 ) && (i<10 ))
			{
				printf("\nmemoire %d:", i );
				printnbr(memoire[i]);
				printf("\n");
			}
			break;
			default:
			printf ("choix incorrect \n");
			break;
		}
	}
}




