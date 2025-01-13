#include "nbrdef.h"
#include "addi.h"

/********************************************************
*							*
* result = nbra + nbrb					*
*							*
*							*
*							*
********************************************************/


Xint additionnbr(Tptrnombre nbra,Tptrnombre nbrb,Tptrnombre result)
{
	register char carry=0, calcul=0;
	register unsigned int i=0;
	Tptrnombre swap;
	unsigned char *na,*nb,*ntamp,*nresult;
	unsigned int lena,lenb, lentampon=0 ;
	if ((nbra->valid <0) ||(nbrb->valid <0))
	{
		result->valid =-1;
		return(-1);
	}
	/* if faut que taille de nbra  >= nbrb */
	if (nbra->length < nbrb->length )
	{
		/* si c'est pas le cas on inverse les 2 nombre */
		swap=nbra;
		nbra=nbrb;
		nbrb=swap;
	}
	lena= nbra->length;
	lenb= nbrb->length;
	na= nbra->nbr +lena-1; /* pointe sur les unites*/
	nb= nbrb->nbr +lenb-1; /* pointe sur les unites*/
	ntamp= tampon->nbr;
	nresult= result->nbr;
	while (i<lenb)
	{
		/* somme et on pointe sur le rang superieur */
		calcul=*na-- + *nb -- +carry;
		if (calcul>9 ) { calcul -=10; carry=1;}else { carry=0;}
		*ntamp++ =calcul; /* memorisation du resultat */
		lentampon++;
		i++;
	}
	while (i<lena)
	{
		/* somme et on pointe sur le rang superieur */
		calcul=*na-- +carry;
		if (calcul>9 ) { calcul -=10; carry=1;} else { carry=0;}
		*ntamp++ =calcul;
		lentampon++;
		i++;
	}
	if (carry==1)
	{
		if ((++lentampon) >= sizenb)
		{
			result->valid=-2;
			return(-2);
		}		
		*ntamp++ =1;

	}
	i=0;
	result->length=lentampon;
	result->valid=1;
	ntamp--;
	/* on copie le resultat dans le buffer de
	sortie & l'on met a endroit le nombre*/
	while (i<lentampon )
	{
		*nresult++ = *ntamp--;
		i++;
	}

	return(lentampon);
}



/********************************************************
*							*
* result = nbra + inc					*
*							*
*							*
*							*
********************************************************/


Xint incremente(Tptrnombre nbra,unsigned int inc ,Tptrnombre result)
{
	register unsigned int i;
	register int carry=inc, calcul=0;
	unsigned int lena,lentampon=0 ;
	unsigned char *na,*ntamp,*nresult;
	if (nbra->valid <0)
	{
		result->valid= -1;
		return (-1);
	}
	lena= nbra->length;
	na= nbra->nbr +lena-1; /* pointe sur les unites*/
	ntamp= tampon->nbr;
	nresult= result->nbr;
	while (lentampon<lena)
	{
		/* somme et on pointe sur le rang superieur */
		calcul=*na-- +carry;
		if (calcul>9 ) {   carry= calcul / 10 ;calcul = calcul % 10;} else { carry=0;}
		*ntamp++ =calcul;
		lentampon++;
	}
	while (carry!=0)
	{
		calcul = carry % 10;
		carry= carry / 10;
		if ( ( ++lentampon) >= sizenb)
		{
			result->valid=-2;
			return(-2);
		}
		*ntamp++ =calcul;

	}
	result->length=lentampon;
	result->valid=1;
	ntamp--;
	i=0;
	while (i<lentampon )
	{
		*nresult++ = *ntamp--;
		i++;
	}
	return(lentampon);
}