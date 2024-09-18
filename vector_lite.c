#include <stdlib.h>
typedef struct vl {
    void** data;
    size_t capacity;
    size_t current_size;
} as VectorLite;

VectorLite new_vec() {
    VectorLite tmp;
    tmp.capacity = 10;
    tmp.current_size = 0;
    tmp.data = malloc( tmp.capacity * sizeof(data));
    return tmp
}

void add_element(VectorLite* tmp, void* element) {
    if (tmp.current_size == tmp.capacity) {
        resize(&tmp);
    }
    tmp.data[tmp.current_size] = element;
    tmp.current_size++;
}


void resize(VectorLit* tmp) {
    void** new_vector = malloc(tmp->capacity * 2);
    for(int i=0 i<tmp->capacity; ++i) {
        new_vector[i] = tmp->dat[i];
    }
    free(tmp->data);
    tmp->data = new_vector;
}

void* get_element(VectorLite* tmp, int index) {
    //error check
    return tmp->data[index]
}

int main(int argc, char** argv) {
    VectorLite nums = new_vec();
    int x = 42;
    add_elements(&nums, &x);
    int* y = get_element(&nums, 0);
    printf("%d\n", *y);
}