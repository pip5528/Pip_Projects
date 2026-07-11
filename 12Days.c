#include <stdio.h>

/*
What you see here is The Twelve Days of Christmas written in C just for the heck of it.
I figured I would actually make it count how far along it is rather than just mindlessly put getchar() and print statements for everything.
This saves a bit of manual repetition.
*/



int main (void) {


printf("On the first day of Christmas, my true love gave to me:\n");
getchar();

int i;
for (i = 12; i >= 1; --i) {
if (i == 1) {
printf("A partridge in a pair tree\n");
getchar();
}}
 

printf("On the second day of Christmas, my true love gave to me:\n");
getchar();
for (i = 12; i > 1; --i) {
if (i == 2) { 
  printf(" Two turtle doves and\n");
  getchar();
}}




printf("On the third day of Christmas, my true love gave to me:\n");
getchar();
for (i = 12; i > 1; --i) {
if (i == 3) {
  printf("Three French hens\n");
  getchar();
}}



printf("On the fourth day of Christmas, my true love gave to me:\n");
getchar();

for (i = 12; i > 1; --i) {
if (i == 4) {
  printf("Four calling birds\n");
  getchar();
}}

// Traditional Christmas song, program recital by Sam Wittsell

return 0;
}


