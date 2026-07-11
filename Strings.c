#include <stdio.h>
#include <string.h>


int main(void) {

char greeting1[] = "Hello";
char greeting2[] = "World";

strcat(greeting1, greeting2);

printf("%s\n", greeting1);


return 0;  
}
