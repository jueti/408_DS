#include "pch.h"
#include "static_array.h"

void test()
{
    StaticArray _array;
    Init(&_array);
    int i = 0;
    ElemType elem = i;
    printf("Append:\n");
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
    Destroy(&_array);
}

void test_insert()
{
    StaticArray _array;
    Init(&_array);
    printf("Insert:\n");
    printf("\t%s\n", Insert(&_array, 1, (const ElemType*)1) ? "Success" : "Fail");
    Print(&_array);
}

int main()
{
    test();
    test_insert();
    (void)getchar();
    return 0;
}
