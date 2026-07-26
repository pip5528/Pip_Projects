#include <stdio.h>


struct crap {
char junk[64];
int stuff;


};


int main(void) {

   struct crap crappy = {"This", 50};
   struct crap crappier = {"That", 100};

   for (int i = 0; i < 5; ++i) 
       
   
    printf ("%s, %d, %s, %d", crappy.junk, crappy.stuff, crappier.junk, crappier.stuff);
}
