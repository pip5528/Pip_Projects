#include <stdio.h>
#include <string.h>


int main(void) {

char greeting1[32] = "Hello";
char greeting2[32] = "World";

strlcat(greeting1, greeting2, sizeof(greeting1));


printf("%s\n", greeting1);


return 0;  
}
