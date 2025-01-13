#include "nbrdef.h"
#include "sous.h"
#include "addi.h"
#include "multi.h"


Xint sizereste=0,sizequotient=0;

/*
  int divisionnbr(Tptrnombre nbra,Tptrnombre nbrb,Tptrnombre quotien,Tptrnombre reste)
{
	copienbr(zero,quotien);
	copienbr(nbra,reste);
	while (soustractionnbr(reste, nbrb ,tampon2)>=0 )
	{
	incremente(quotien,1,quotien );
	copienbr(tampon2,reste);
	}
	return(1);
}
*/


Xint divisionnbr(Tptrnombre nbra,Tptrnombre nbrb,Tptrnombre quotien,Tptrnombre reste)
{

	if (sizenbr(nbrb) <=0)
	{
		quotien->valid=ERRDIV;
		reste->valid=ERRDIV;
		return(ERRDIV);
	}
	copienbr(nbra,tampon2);
	copienbr(zero, tampon3);
	/* on soutrait tant que l'on peut */
	while (soustractionnbr(tampon2, nbrb ,tampon4)>=0 )
	{
		incremente(tampon3,1,tampon3 );
		copienbr(tampon4,tampon2);
	}
	sizereste=copienbr(tampon2,reste);
	sizequotient=copienbr(tampon3,quotien);
	return(sizequotient);
}


Xint divisionnbrspeed(Tptrnombre nbra,Tptrnombre nbrb,Tptrnombre quotien,Tptrnombre reste)
{
	unsigned char *na;
	int i=0,lena=nbra->length;
	copienbr(nbra,tampon2);
	if (sizenbr(nbrb) <=0)
	{
		quotien->valid=-1;
		reste->valid=-1;
		return(-1);
	}
	na = nbra->nbr;
	copienbr(zero,tampon2);
	copienbr(zero, tampon3);
	while (i<lena)
	{
		i++;
		multidecade(tampon2,1,tampon2); /* tampon2 = tampon2 *10 )*/
		incremente(tampon2,*na++,tampon2); /*  on recupere les chiffre de gauche a droite */
		multidecade(tampon3,1,tampon3); /* tampon3 = tampon3 *10 )*/
		/* on soutrait tant que l'on peut */
		while (soustractionnbr(tampon2, nbrb ,tampon4)>=0 )
		{
			incremente(tampon3,1,tampon3 );
			copienbr(tampon4,tampon2);
		}
	}
	sizereste=copienbr(tampon2,reste);
	sizequotient=copienbr(tampon3,quotien);
	return(sizequotient);
}



Xint divisionintspeed(Tptrnombre nbra,unsigned int dive,Tptrnombre quotien,Tptrnombre reste)
{
	unsigned char *na;
	int i=0,lena=nbra->length;
	copienbr(nbra,tampon2);
	if (dive <=0)
	{
		quotien->valid=-1;
		reste->valid=-1;
		return(-1);
	}
	na = nbra->nbr;
	copienbr(zero,tampon2);
	copienbr(zero,tampon3);
	while (i<lena)
	{
		i++;
		multidecade(tampon2,1,tampon2);
		incremente(tampon2,*na++,tampon2);
		multidecade(tampon3,1,tampon3);
		while (decremente(tampon2, dive ,tampon4)>=0 )
		{
			incremente(tampon3,1,tampon3 );
			copienbr(tampon4,tampon2);
		}
	}
	sizereste=copienbr(tampon2,reste);
	sizequotient=copienbr(tampon3,quotien);
	return(sizequotient);
}



