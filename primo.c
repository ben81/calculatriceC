#include "nbrdef.h"
#include "addi.h"
#include "sous.h"
#include "divi.h"
#include <stdio.h>


/********************************************************
*							*
*	teste si nbra divisible par 2 ,3,5,7,11,13	*
*	2, 5 --> teste les unites			*
*	3 --> somme des chiffre 			*
*	11 --> differe somme des chiffrede rang P & I	*
*	7 13 --> comme 11 mais sur une base 1000	*
*	renvoie le produit de ces diviseurs		*
********************************************************/



int divisible(Tptrnombre nbra)
{
	register int i,lena;
	register unsigned char n;
	register unsigned char  *na;
	int somme=0, somme11=0;
	register char d=0;
	long somme1001=0; /* 1001=7 *11* 13 */
	int retour=1;
	if (nbra->valid <0)
	{
		return (-1);
	}
	lena= nbra->length;
	if (lena==0)  return(0);
	na= nbra->nbr +lena-1; /* pointe sur les unites*/
	n=*na;
	switch (n)
	{
		case 2:
		case 4:
		case 6:
		case 8: {retour*=2;} /* divisible par 2*/
		break;
		case 0: {retour*=10;} /* divisible par 10*/
		break;
		case 5: {retour*=5;} /* divisible par 5*/
	}
	na= nbra->nbr;
	for (i=0;i<lena;i++)
	{
		n=*na++;
		somme +=n;  /* somme les chiffre */
		if (( i& 1 )==0)
		{somme11 +=n;} else {somme11-=n	;}
	}
	if ((somme11 % 11)==0) {retour*=11;} /* divisible par 11 */
	if ((somme % 3)==0) {retour*=3;} /* divisible par 3 */
	na= nbra->nbr +lena-1;
	for (i=0;i<lena;i++)
	{
		n=*na--;
		switch(d)
		{
		case 0: somme1001 += n; break;
		case 1: somme1001 += n*10 ; break;
		case 2: somme1001 += n*100; break;
		case 3: somme1001 -= n; break;
		case 4: somme1001 -= n*10; break;
		case 5: somme1001 -= n*100; d=-1;
		}
		d++;
	}
	if ((somme1001 % 7)==0)  {retour*=7;} /* divisible par 7*/
	if ((somme1001 % 13)==0) {retour*=13;} /* divisible par 13 */
	return (retour);
}


int booldivisible(Tptrnombre nbra)
{
	register int i,lena;
	register unsigned char n;
	register unsigned char  *na;
	int somme=0, somme11=0;
	register char d=0;
	long somme1001=0; /* 1001=7 *11* 13 */	
	if (nbra->valid <0)
	{
		return (0);
	}
	lena= nbra->length;
	if (lena==0)  return(0);
	na= nbra->nbr +lena-1; /* pointe sur les unites*/
	n=*na;
	switch (n)
	{
		case 2:
		case 4:
		case 6:
		case 8: 		
		case 0: 		
		case 5: return (1);
	}
	na= nbra->nbr;
	for (i=0;i<lena;i++)
	{
		n=*na++;
		somme +=n;  /* somme les chiffre */
		if (( i& 1 )==0)
		{somme11 +=n;} else {somme11-=n	;}
	}
	if ((somme11 % 11)==0) return(1); /* divisible par 11 */
	if ((somme % 3)==0) return(1); /* divisible par 3 */
	na= nbra->nbr +lena-1;
	for (i=0;i<lena;i++)
	{
		n=*na--;
		switch(d)
		{
		case 0: somme1001 += n; break;
		case 1: somme1001 += n*10 ; break;
		case 2: somme1001 += n*100; break;
		case 3: somme1001 -= n; break;
		case 4: somme1001 -= n*10; break;
		case 5: somme1001 -= n*100; d=-1;
		}
		d++;
	}
	if ((somme1001 % 7)==0)  return(1); /* divisible par 7*/
	if ((somme1001 % 13)==0) return(1); /* divisible par 13 */
	return (0);
}


int primo(Tptrnombre nbra)
{
	int sizer;
	if ( decremente(nbra,1, tampon2)==0 ) {return 0;} /*nbra=1 -> pas premier */
	switch (divisible(nbra))
	{
		case 2:  if ( decremente(nbra,2,  tampon2)==0 ) {return 1;} return 0 ;
		case 3:  if ( decremente(nbra,3,  tampon2)==0 ) {return 1;} return 0 ;
		case 5:	 if ( decremente(nbra,5,  tampon2)==0 ) {return 1;} return 0 ;
		case 7:  if ( decremente(nbra,7,  tampon2)==0 ) {return 1;} return 0 ;
		case 11: if ( decremente(nbra,11, tampon2)==0 ) {return 1;} return 0 ;
		case 13: if ( decremente(nbra,13, tampon2)==0 ) {return 1;} return 0 ;
		case 1: break;
		default: return 0; /*si divisible par 6,10,14,22,25,15,21,33,55,30,66,91,110,165,330 , ..*/
	}	
	sizer=incremente(zero,17,tampon5); /*tampon5=13+zero =13*/
	while (1)
	{
		divisionnbrspeed(nbra,tampon5,tampon7, tampon8);
		if (sizequotient<=sizer )
		{
			/*si tampon7<tampon5 ==> tampon5 >sqrt(nbra) ==> premier */
			if (soustractionnbr(tampon7, tampon5,tampon8) <0) {return (1);}
		}
		/*si le reste est nul (nbr chiffre==0) */
		if ( sizereste==0) { return (0);}
		do
		{
			sizer=incremente(tampon5,2,tampon5);
		}
		while (booldivisible(tampon5)==1);
	}
}

void decompose(Tptrnombre nbra)
{
	int sizer;
	unsigned char prim[6]={2,3,5,7,11,13};
	int i=0,j,n,dive;
	/* tampon5=nbra */
	if (copienbr(nbra, tampon5)<= 0) { return ;};
	n=divisible(nbra);
	for (j=0;j<6;j++)
	{
	i=0;
	dive=prim[j];
	if ((n% dive)==0)
	{
	divisionintspeed(tampon5,dive,tampon7,tampon8);
	if (sizereste==0)
		{
			printf("\ndivisible par %d  : ", dive);
			while 	(sizereste==0)
			{
				i++;
				copienbr(tampon7, tampon5 );
				divisionintspeed(tampon5,dive,tampon7,tampon8);
			}
			printf("%d fois ",i);
		}
	}
	}
	sizer=incremente(zero,17,tampon6);
	while (decremente(tampon5,1, tampon8)>0 )
	{
		i=0;
		divisionnbrspeed(tampon5,tampon6,tampon7,tampon8);
		if (sizereste==0)
		{
			printf("\ndivisible par ");
			printnbr(tampon6);
			printf(" : ");
			while 	(sizereste==0)
			{
				i++;
				copienbr(tampon7, tampon5 );
				divisionnbrspeed(tampon5,tampon6,tampon7,tampon8);
			}
			printf("%d fois ",i);
		}
		if (sizequotient<=sizer )
		{
			if( soustractionnbr(tampon6,tampon5,tampon8)<0 )
				{
				printf("\ndivisible par ");
				printnbr(tampon5);
				printf(" : 1 fois .");
				printline();
				return ; }
		}
		do
		{
		       sizer=incremente(tampon6,2,tampon6);
		}
		while (booldivisible(tampon6)==1);

	}
	printline();
}