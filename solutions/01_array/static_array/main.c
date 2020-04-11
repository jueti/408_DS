#include "pch.h"
#include "static_array.h"

void test_append_and_delete()
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

void test_insert_success()
{
    StaticArray _array;
    Init(&_array);
    printf("Insert: (success)\n");
    printf("\t%s\n", Insert(&_array, 0, 1) ? "Success" : "Fail");
    Print(&_array);
}

void test_insert_fail()
{
    StaticArray _array;
    Init(&_array);
    printf("Insert: (fail, only work in Release mode)\n");
    printf("\t%s\n", Insert(&_array, 1, 1) ? "Success" : "Fail");
    Print(&_array);
}

void test()
{
    test_append_and_delete();
    test_insert_success();
    test_insert_fail();
    printf("Finish!\n");
}

int main()
{
    test();
    (void)getchar();
    return 0;
}
