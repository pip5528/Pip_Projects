#include <stdio.h>


int main(void) {

// A bit of cleanup here and there.


int stuff[10];


printf("Please enter 10 numbers.\n");


int sum = 0;
for (int i = 0; i < 10; i++) {
scanf("%d", &stuff[i]);
sum += stuff[i]; 
printf("Current total:  %d\n", sum);
}



return 0;
}
