#include "nbrdef.h"
#include "addi.h"
#include "multi.h"
#include "facto.h"

/*
{
int f=1;
 for(ni=1;ni<=n;ni++)
	{
	f=f*i;
	}
return (f);
}*/




Xint factonbr(int n,Tptrnombre result)
{
	int ni;
	if (n<0 ) {result->valid=ERRFACTO;return (ERRFACTO); }
	incremente(zero,1,result);
	for (ni=1;ni<=n;ni++)
	{
		multinbrint(result,ni,result); /* result =result *ni */
	}	
	return (sizenbr(result));	
}
