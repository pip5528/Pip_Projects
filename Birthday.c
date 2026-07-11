#include <stdio.h>

// A birthday function for the June birthdays

void birthday(char name[], int age) {

printf("Please enter a name:\n");
scanf("%s", name);
printf("Please enter an age:\n");
scanf("%d", &age);
printf("%s, %d\n", name, age);
}

int main(void) {

char name[100];
int age;

birthday(name, age);


return 0;
}
