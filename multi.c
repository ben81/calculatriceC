#include "nbrdef.h"
#include "multi.h"
#include "addi.h"
#include "stdio.h"


char dizaine [16*10];
char unite   [16*10];
Tptrnombre mcalcul[10];

Xint multinbrspeed(Tptrnombre nbra,Tptrnombre nbrb,Tptrnombre result)
{
	unsigned int i=0;
	register unsigned int lena;
	unsigned char n;
	unsigned char *na;
	char cl[10]={0,0,0,0,0,0,0,0,0,0};
	Tptrnombre swap;
	tampon3->length=0;
	tampon3->valid=1;
	/* on veut  taille de nbra  <= nbrb */
	if (sizenbr(nbra) > sizenbr(nbrb) )
	{
		/* si c'est pas le cas on inverse les 2 nombre */
		swap=nbra;
		nbra=nbrb;
		nbrb=swap;
	}
	copienbr(zero,mcalcul[0]);
	copienbr(nbrb,mcalcul[1]);
	cl[0]=1;
	cl[1]=1;
	lena= nbra->length;
	na=nbra->nbr+lena-1;
	for (i=0;i<lena ;i++)
	{
		n=*na--;
		/*  nbrb*n est calcul puis le resultat est sauve */
		if (cl[n]==0 )
		{
			multinbrchi(nbrb,n,mcalcul[n]);
			cl[n]=1;
		}
		multidecade(mcalcul[n],i ,tampon2) ;
		additionnbr(tampon3,tampon2,tampon3);
	}
	return(copienbr(tampon3,result)) ;
}


Xint multinbr(Tptrnombre nbra,Tptrnombre nbrb,Tptrnombre result)
{
	register unsigned int i=0;
	register unsigned int lena;
	unsigned char *na;
	Tptrnombre swap;
	tampon3->length=0;
	tampon3->valid=1;
	/* on veut  taille de nbra  <= nbrb */
	if (nbra->length > nbrb->length )
	{
		/* si c'est pas le cas on inverse les 2 nombre */
		swap=nbra;
		nbra=nbrb;
		nbrb=swap;
	}
	lena= nbra->length;
	na=nbra->nbr+lena-1;
	for (i=0;i<lena ;i++)
	{
		multinbrchi(nbrb,*na--,tampon2);
		multidecade( tampon2,i ,tampon2) ;
		additionnbr(tampon3,tampon2,tampon3);
	}
	return(copienbr(tampon3,result)) ;
}


Xint multinbrchi(Tptrnombre nbra,unsigned char inc ,Tptrnombre result)
{
	register unsigned int i=0;
	register unsigned int lena;
	unsigned char n;
	unsigned int calcul, carry=0 , lentampon ;
	unsigned char *na,*nresult,*ntamp;
	if ((nbra->valid <0) || (inc >9))
	{
		result->valid =-1;
		return(-1);
	}
	nresult= result->nbr;
	lena= nbra->length;
	na=nbra->nbr+lena-1;
	ntamp=tampon->nbr;
	while (i<lena)
	{
		/*
		calcul=((int) *na-- ) * inc + carry;
		carry = calcul  / 10;		*/
		n= ((*na--)  << 4 )+ inc  ; /* utilisation d une table de résultat précalculer */
		calcul = unite[n]+ carry;
		carry= dizaine[n];
		if ( calcul>9) { calcul -= 10 ; carry++ ;}
		*ntamp++=calcul ;
		i++;
	}
	if  ( carry !=0)
	{
		if ((++i) >= sizenb)
		{
			result->valid=-2;
			return(-2);
		}
		*ntamp++ = carry ;
	}
	lentampon=i;
	ntamp--;
	i=0;
	while (i<lentampon )
	{
		*nresult++ = *ntamp--;
		i++;
	}
	result->valid=1;
	result->length=lentampon;
	return (lentampon) ;
}



Xint multinbrint(Tptrnombre nbra,unsigned int mul ,Tptrnombre result)
{
	register unsigned int i=0;
	register unsigned int lena;
	unsigned int calcul, carry=0 , lentampon ;
	unsigned char *na,*nresult,*ntamp;
	if (nbra->valid <0)
	{
		result->valid =-1;
		return(-1);
	}
	nresult= result->nbr;
	lena= nbra->length;
	na=nbra->nbr+lena-1;
	ntamp=tampon->nbr;
	while (i<lena)
	{
		calcul=( *na-- ) * mul + carry;
		carry = calcul  / 10;
		*ntamp++=calcul % 10;
		i++;
	}
	while ( carry !=0)
	{
		if ((++i) >= sizenb)
		{
			result->valid=-2;
			return(-2);
		}
		*ntamp++ = carry % 10;
		carry = carry / 10;
	}
	lentampon=i;
	ntamp--;
	i=0;
	while (i<lentampon )
	{
		*nresult++ = *ntamp--;
		i++;
	}
	result->valid=1;
	result->length=lentampon;
	return (lentampon) ;

}




int multidecade(Tptrnombre nbra,unsigned int decal ,Tptrnombre result)
{
	register unsigned int i=0;
	register unsigned int lena ;
	unsigned char *na,*nresult;
	if (nbra->valid <0)
	{
		result->valid= -1;
		return (-1);
	}
	na=nbra->nbr;
	nresult=result->nbr;
	lena= nbra->length;
	if ((lena+decal )>sizenb )
		{
		result->valid= -1;
		return (-1);
		}
	while (i<lena)
	{
		*nresult++=*na++;
		i++;
	}
	i=0;

	while (i<decal )
	{
		*nresult++ =0;
		i++;
	}
	result->length=lena+decal ;
	result->valid=1;
	return (lena+decal);

}


void initmulti(void)
{
	char i,j ;
	for (i=0;i<10;i++)
	for (j=0;j<10;j++)
	{
		dizaine[(i<<4 )+ j]= (i*j ) /10 ;
		unite[(i<<4) + j]=(i*j) % 10;
	}
	for (i=0;i<10;i++)
	mcalcul[i]=makenbr();
}



void donemulti(void)
{
	char i;
	for (i=0;i<10;i++)
	mcalcul[i]=donenbr(mcalcul[i]);
}

/********************************************************
*							*
* result = nbra  ^ expo					*
*							*
*	2 ^11 = 2 ^(8 + 2 +1)				*
*	      = 2^8 +2 ^2 + 2^1				*
*		= 2^8 *1 + 2^4 *0 + 2 ^2 * 1 +2 ^1 * 1  * 
********************************************************/

Xint puissance(Tptrnombre nbra,unsigned int expo ,Tptrnombre result)
{
	unsigned  int n=expo;
	int sr;
    copienbr(nbra,tampon4);
	sr=incremente(zero,1,result);
	while (n!=0)
	{
		if ((n % 2)==1)
			sr=multinbrspeed(result, tampon4,result);
		n = n / 2 ;
		multinbrspeed(tampon4,tampon4,tampon4);
	}
	return( sr);
}