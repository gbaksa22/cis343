#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//fills an array of random length with random numbers
size_t fill_array(int** numbers) {
    srand(time(NULL));
    int r = rand() %1000;
    *numbers = (int*)malloc(r * sizeof(int));
    for(size_t t = 0; t<r; ++t) {
        (*numbers)[t] = rand() % 1000;
    }
    return r;
}

int main(int argc, char** argv) {
    int* numbers;
    size_t amount = fill_array(&numbers);
    for( size_t t=0; t<amount; ++t) {
        printf("%d\t", numbers[t]);
    }
    printf("\n");
    return 0;
}