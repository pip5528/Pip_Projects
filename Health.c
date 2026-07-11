#include <stdio.h>

int main() {

int a = 0;
printf("Do your worst!\n");
scanf("%d", &a); 



if (a >= 5 && a < 10) {
	printf("Wow, it's super effective!");
}
else if (a >= 10) {
	printf("DEAD!");
}
else {
	printf("Not very effective."); }

	return 0;
}


