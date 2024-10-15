#include <stdio.h>
#include <stdlib.h>

void fill_array(float* arr, size_t size) {
    for(int i=0; i<size; ++i) {
        arr[i] = rand();
        //same as *(arr + i) = rand();
    }
}

void print_array(float* arr, size_t size){
    for(int i=0; i<size; ++i) {
        printf()
    }
}

int main(int argc, char** argv) {
    //static: address + size doesn't change
    float numbers_one[100];
    
    //static: the pointer itself is static
    //dynamic: address can change if we reallocate
    float* numbers_two = malloc(1000 * sizeof(*numbers_two));

    //sizeof() gets the bytes of static

    fill_array(numbers_one, 100);
    fill_array(numbers_two, 1000);
}