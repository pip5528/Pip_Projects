#include <stdio.h>

// This is a four-function calculator written with literal C functions. Enjoy!

int add(int a, int b) {
  int result = a + b;
  printf("%d", result);
  return result;
}

int sub(int a, int b) {
  int result = a - b;
  printf("%d", result);
  return result;
}

int mul(int a, int b) {
  int result = a * b;
  printf("%d", result);
  return result;
}

int div(int a, int b) {
  int result = a / b;
  printf("%d", result);
  return result;
}

int main(void) {



int a = 0;
int b = 0;
int result = 0;
char operator;

while (1) {
  calc:
  printf("Enter two integers to calculate:\n");
  scanf("%d, %c, %d", &a, &operator, &b);

  switch(operator) { 

  case '+':
    add(a, b);
    return result;
    goto calc;

  case '-':
    sub(a, b);
    return result;
    goto calc;

  case '*':
    mul(a, b);
    return result;
    goto calc;

  case '/':
    div(a, b);
    return result;
    goto calc;
}}


return 0;
}
