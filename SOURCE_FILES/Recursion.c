#include "Recursion.h"
int sum(int addThis){
    int id = addThis;
    if(addThis <= 0){
        return 0;
    }
    printf("Calling sum(%d)\n", addThis);
    if(addThis > 1){
        addThis += sum(addThis - 1);
    }
    printf("Sum(%d): returned: %d\n", id, addThis);
    return addThis;
}
