#include <stdio.h>

typedef struct {

char* name;
int age;

} siblings;

int main ()
{


siblings s1 = {"Sam", 26};
siblings s2 = {"Megan", 23};
siblings s3 = {"Rose", 20};

printf("%s is aged %d\n", s1.name, s1.age);
printf("%s is aged %d\n", s2.name, s2.age);
printf("%s is aged %d\n", s3.name, s3.age);

return 0;
}
