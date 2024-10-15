#include <stdio.h>
#include <stdlib.h>

void hello_name( char* name, size_t len) {
    printf("Hello, ");
    for(size_t i=0; i<len; ++i) {
        printf("%c", name[i]);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    char* name = "super duper long name right here";
    hello_name(name, len(name));
    return 0;
}