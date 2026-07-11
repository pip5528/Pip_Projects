#include <stdio.h>

int main(void) {

FILE* file = fopen("Stuff.txt", "w");

char *crap = "Here's some random crap to write to a file!";

fprintf(file, crap, stdout);

if (file == NULL) {
  perror("Failed to open file");
}

else {
  printf("Success! %s", crap);
}


fclose(file);


return 0;

}
