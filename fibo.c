#include "nbrdef.h"
#include "addi.h"



/*int fibofor(int n);
{
int ni=0,a=0,b=1,f=0;

 for (ni=0;ni<n;ni++)
	{
	f=a+b;
	b=a;
	a=f;
	}
return (f);
}*/

Xint fibonbr(int n,Tptrnombre result)
{
	int ni;
	copienbr(zero,tampon2);
	copienbr(zero,result);
	incremente(zero,1,tampon3);
	if (n<0 ) {result->valid=ERRFIBO;return (ERRFIBO); }
	for (ni=0;ni<n;ni++)
	{
		additionnbr(tampon2,tampon3,result);
		copienbr(tampon2,tampon3);
		copienbr(result,tampon2);
	}	
	return (sizenbr(result));	
}