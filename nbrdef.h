#ifndef NBRDEF
#define NBRDEF 1


typedef struct {
	int length;
	unsigned char *nbr;
	signed char valid;
}  Tnombre;

typedef Tnombre *Tptrnombre;
/* Xint : nbrchiffre>=0 : erreur<0*/
#define Xint int 

#define ERRDIV   -2
#define ERRFACTO  -3
#define ERRFIBO  -4

extern unsigned int sizenb;
extern Tptrnombre tampon,tampon2,tampon3,tampon4,tampon5,tampon6,tampon7,tampon8,zero;
extern char *strinp;


Xint sizenbr(Tptrnombre p);
Xint copienbr(Tptrnombre source, Tptrnombre desti);

Tptrnombre makenbr(void);
Tptrnombre donenbr(Tptrnombre p);

void printnbr(Tptrnombre output);
Xint saisienbr(Tptrnombre input);


void makenbrdef(void);
void donenbrdef(void);


void printline(void);
#endif
