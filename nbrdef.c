#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "nbrdef.h"
#include <string.h>


/********************************************************
*							*
*							*
*							*
*							*
*							*
********************************************************/

unsigned int sizenb=600;
Tptrnombre tampon,tampon2,tampon3,tampon4,tampon5,tampon6,tampon7,tampon8,zero;
char formatstr[20]="%s", *strinp, *strbuf ;


/********************************************************
*							*
*	renvoie la taille de p	(nbr chiffre)		*
*	et supprime les 0 supperflux 			*
*							*
*							*
********************************************************/
Xint sizenbr(Tptrnombre p)
{
	register int i=0,len;
	unsigned char *np,*np2;
	if (p->valid<0 )
	{
		return (-1);
	}
	if (*p->nbr != 0)
	{ return (p->length);}
	np2=np=p->nbr;
	len=p->length;
	while ((*np++ == 0) && (i<len))
	{
		i++;
	}
	p->length-=i;
	np--;
	while ( i<len )
	{
		*np2++=*np++;
		i++;
	}
	return ( p->length);
}


/********************************************************
*							*
*	copie source dans desti				*
*	renvoie la taille de source(nbr chiffre)	*
*	et supprime les 0 supperflux 			*
*							*
*							*
*							*
********************************************************/


Xint copienbr(Tptrnombre source, Tptrnombre desti)
{
	register int i=0,len;
	unsigned char *np,*np2,*np3;;
	if (source->valid<0 )
	{
		desti->valid=-1;
		return (-1);
	}
	np2=np=source->nbr;
	np3=desti->nbr;
	len=source->length;
	while ((*np++ == 0) && (i<len))
	{
		i++;
	}
	source->length-=i;
	np--;
	while ( i<len )
	{
		*np3++= *np2++=*np++;
		i++;
	}
	desti->valid=1;
	return ( desti->length =source->length);

}
/********************************************************
*							*
*	alloue le nombre				*
*							*
*							*
*							*
********************************************************/


Tptrnombre makenbr(void)
{
	Tptrnombre p;
	p=malloc(sizeof(Tnombre));
	p->length=0;
	p->nbr=malloc(sizenb);
	p->valid=1;
	return p;
}

/********************************************************
*							*
*	dealloue le nombre				*
*							*
*							*
*							*
********************************************************/

Tptrnombre donenbr(Tptrnombre p)
{
	free(p->nbr);
	free(p);
	return (NULL);
}

/********************************************************
*							*
*							*
*							*
*							*
*							*
********************************************************/

void printnbr(Tptrnombre output)
{
	register int i,maxl;
	unsigned char *move;
	if (output->valid >=0)
	{
		move =output->nbr;
		maxl=output->length;
		if (maxl!=0 )
		{
			for (i=0;i< maxl; i++)
			{
				printf("%c",(*move++)+'0');
			}
		}
		else
		{
			printf("ZERO");
		}
		printf(" ");
	}
	else
	{
		printf("nombre indefini \n");
	}
}


/********************************************************
*							*
*							*
*							*
*							*
*							*
********************************************************/


Xint saisienbr(Tptrnombre input)
{
	register int n=0,i=0;
	register unsigned char *move,chiffre;
	char c;
	move =input->nbr;
	printf("entrer un nombre :\n");
	scanf(formatstr , strinp);
	while ((c=strinp[i])!='\0')
	{
		i++;
		if (isdigit(c)!=0)
		{
			chiffre= (c -'0');
			if ((chiffre!=0) ||(n!=0))
			{
				*move++=chiffre ;
				n++;
			}
		}
		else
		{
		  /*while ((c=getchar())!='\n');*/
			input->valid=-1;
			return (-1);
		}
	}
	input->length=n	;
	input->valid=1;
	return  n;
}





void makenbrdef(void)
{
	char tp[20],tp2[5];
	int n=sizenb+60;
	tampon=makenbr();
	tampon2=makenbr();
	tampon3=makenbr();
	tampon4=makenbr();
	tampon5=makenbr();
	tampon6=makenbr();
	tampon7=makenbr();
	tampon8=makenbr();
	zero=makenbr();
	/*itoa(sizenb,tp,10);*/
	tp[0]=0;
	tp2[0]=0;
	tp2[1]=0;	
	while (n!=0 )
	{
	  tp2[0]= (n % 10 )+ '0';
	  tp2[1]=0;
	  strcat(tp2,tp);
	  strcpy(tp,tp2);
	  n=n / 10;
	}
	strcat(formatstr,tp2);
	strinp=(char *) malloc(sizenb+10);
	strbuf=(char *) malloc(8192);
	*strbuf=0;
}

void donenbrdef(void)
{
	tampon8=donenbr(tampon8);
	tampon7=donenbr(tampon7);
	tampon6=donenbr(tampon6);
	tampon5=donenbr(tampon5);
	tampon4=donenbr(tampon4);
	tampon3=donenbr(tampon3);
	tampon2=donenbr(tampon2);
	tampon=donenbr(tampon);
	zero=donenbr(zero);
	free(strinp);	
}

void printline(void)
{
	printf("\n___________________________________________________________\n");
}