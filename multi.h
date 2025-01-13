
#ifndef MULTI
#define MULTI 1

void initmulti(void);
void donemulti(void);

Xint multinbrspeed(Tptrnombre nbra,Tptrnombre nbrb,Tptrnombre result);
Xint multinbr(Tptrnombre nbra,Tptrnombre nbrb,Tptrnombre result);

Xint multinbrchi(Tptrnombre nbra,unsigned char inc ,Tptrnombre result);
Xint multinbrint(Tptrnombre nbra,unsigned int mul ,Tptrnombre result);

Xint multidecade(Tptrnombre nbra,unsigned int decal ,Tptrnombre result);



Xint puissance(Tptrnombre nbra,unsigned int expo ,Tptrnombre result);
#endif