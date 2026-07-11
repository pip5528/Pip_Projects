#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {

int fd = open ("Stuff.txt", O_RDWR | O_CREAT, 0644);
char crap[] = "Random crap\n";



if (fd == -1) {
  printf("Failed to open crap\n");
  return -1;
}

write (fd, crap, sizeof(crap) -1);
printf("Crap successfully written: %s\n", crap);

close(fd);
return 0;
}
