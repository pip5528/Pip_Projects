#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{


srand(time(NULL));
for (int i = 1; i <= 5; ++i){
printf("Your random numbers: %d\n", rand() % 100 + 1);
}

return 0;
}

