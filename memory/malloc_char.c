#include <stdio.h>
#include <stdlib.h>
/* From here:
 * https://www.darkcoding.net/software/resident-and-virtual-memory-on-linux-a-short-example/
 *
 * Compile:
 * gcc -Wall -g malloc_char.c -o malloc_char.x
 */

void fill(unsigned char* addr, size_t amount) {
    unsigned long i;
    for (i = 0; i < amount/2; i++) {
        *(addr + i) = 42;
    }
}

int main(int argc, char **argv) {
    unsigned char *result;
    char input;
    size_t s = 1<<30;

    result = malloc(s);
    printf("Addr: %p\n", result);
    fill(result, s);

    scanf("%c", &input);
    return 0;
}
