#include <stdio.h>
#include <stdlib.h>

typedef struct {

float price;
char *item;

} Money;

int main (void)
{



Money m1 = {0};

m1.item = malloc (sizeof (Money));

printf ("Please enter an item:\n");
fgets (m1.item, sizeof(m1.item), stdin);
printf ("Please enter a price:\n");
scanf ("%f", &m1.price);

FILE* fptr = fopen ("Money.csv", "a+");
fprintf (fptr, "%s, %f\n", m1.item, m1.price);

if (fptr != NULL)
{
  printf ("Money successfully added to spreadsheet: %s, %f\n", m1.item, m1.price);
}

else
{
  perror ("Failed to allocate money to spreadsheet.\n");
  return -1;
}
  

fclose (fptr);

free (m1.item);

m1.item = NULL;

return 0;  
}
