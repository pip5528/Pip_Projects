#include <stdalign.h>
#include <stdio.h>

int main() {
    // Static assertion to ensure integer size is 4 bytes
    _Static_assert(sizeof(int) == 4, "int must be 4 bytes");
    
    printf("Hello, world!\n");
    return 0;
}
