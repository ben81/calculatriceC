#include "nbrdef.h"
#include "sous.h"



Xint soustractionnbr(Tptrnombre nbra,Tptrnombre nbrb,Tptrnombre result)
{
	register int carry=0, calcul=0;
	register int i=0;
	int lena,lenb, lentampon=0 ;
	unsigned char *na,*nb,*ntamp,*nresult;
	if ((nbra->valid <0) || (nbrb->valid <0))
	{
		result->valid =-1;
		return(-1);
	}
	lena=nbra->length;
	lenb=nbrb->length;
	na= nbra->nbr +lena-1; /* pointe sur les unites*/
	nb= nbrb->nbr +lenb-1; /* pointe sur les unites*/
	ntamp= tampon->nbr;
	nresult= result->nbr;
	if (lena<lenb ) { result->valid=-1;return (-1);}
	while (i<lenb)
	{
		/* somme et on pointe sur le rang superieur */
		calcul= *na-- - ( *nb-- +carry );
		if (calcul<0 ) { calcul +=10; carry=1;}else { carry=0;}
		*ntamp++ =calcul;
		lentampon++;
		i++;
	}
	while (i<lena)
	{
		/* somme et on pointe sur le rang superieur */
		calcul=*na-- - ( carry );
		if (calcul<0 ) { calcul +=10; carry=1;}else { carry=0;}
		*ntamp++ =calcul;
		lentampon++;
		i++;
	}
	if (carry ==1)
	{
		result->valid=-1;
		return(-1);
	}
	i=0;
	result->length=lentampon;
	result->valid=1;
	ntamp--;
	while (i<lentampon )
	{
		*nresult++ = *ntamp--;
		i++;
	}
	return(sizenbr(result));
}


Xint decremente(Tptrnombre nbra,unsigned int inc ,Tptrnombre result)
{
	register int i;
	register int carry=inc, calcul=0;
	register int lena,lentampon=0 ;
	register int modu;
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
		modu = carry % 10 ;
		carry = carry / 10 ;
		calcul=  *na-- - modu ;
		if (calcul<0 ) { carry++ ;calcul += 10;}
		*ntamp++ =calcul;
		lentampon++;
	}
	if (carry !=0)
	{
		result->valid=-1;
		return(-1);
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
	return(sizenbr(result));
}