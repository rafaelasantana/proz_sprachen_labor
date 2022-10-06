#include <stdio.h>

// with * we mark that the variable is of type POINTER
// we use it to change variables even from outside its scope
void foo_pointer(int* i) {
    // de-referencing the pointer, because the operation is made in the variable (pointer is another data structure)
    (*i)++;
}

// will not change the variable given as a parameter (in the outer scope)
void foo(int i) {
    i++;
}

int main() {
    int x = 4;

    // if we call foo giving x as parameter, nothing will happen to x in this scope, and x will stay as 4
    foo(x);
    printf("\ngiving x as a parameter: %d", x);
    foo_pointer(&x);
    printf("\ngiving the address from x as a parameter and operating with the pointer, x will be incremented: %d", x);
    return 0;
}
