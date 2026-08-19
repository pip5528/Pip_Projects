#include <stdio.h>

int main(void) {

    /* Convert Fahrenheit to Celsius */
    float fahr = 0;
    printf("Enter a temperature in Fahrenheit:\n");
    scanf("%f", &fahr);
    
    const float celsius = (fahr - 32.0) * 5.0/9.0f;
    printf("%f", celsius);


   return 0; 
}
