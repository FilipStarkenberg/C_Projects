#include "Recursion.h"

int main(){
    assert(sum(1) == 1);
    printf("\n");
    assert(sum(2) == 3);
    printf("\n");
    assert(sum(3) == 6);
    printf("\n");
    assert(sum(4) == 10);
    printf("\n");
    assert(sum(5) == 15);
    printf("\n");
    assert(sum(20) == 210);
    printf("\n");
    assert(sum(0) == 0);
    printf("\n");
    assert(sum(-1) == 0);
    return 0;
}
