#include <stdio.h>
#include <stdlib.h>

typedef struct {

    char *name;
    int age;


} baby;


int main() {
int *ptr = malloc(sizeof(baby));

baby b1 = {"Noah", 7};
printf("%s, age %d months\n", b1.name, b1.age);

baby b2 = {"Sarah", 2};
printf("%s, age %d months\n", b2.name, b2.age);

baby b3 = {"Ellie", 10};
printf("%s, age %d months\n", b3.name, b3.age);

free(ptr);
ptr = NULL;
return 0;

}
