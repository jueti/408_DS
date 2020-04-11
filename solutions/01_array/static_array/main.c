#include "pch.h"
#include "static_array.h"

StaticArray _array;

void test()
{
    Init(&_array);
    int i = 0;
    ElemType elem = i;
    printf("Append\n");
    while (Append(&_array, &elem)) {
        printf("\t%d\n", elem);
        elem = ++i;
    }
    Print(&_array);
    printf("Delete:\n");
    while (!Empty(&_array)) {
        Delete(&_array, 0, &elem);
        if (elem == -1) break;
        printf("\t%d\n", elem);
    }
    Print(&_array);
}


int main()
{
    test();
    //(void)getchar();
    return 0;
}
