#include "pch.h"
#include "static_array.h"

StaticArray _array;

void test()
{
    Init(&_array);
    ElemType i = 0;
    while (Append(&_array, &i))
        i++;
    Print(&_array);
}


int main()
{
    test();
    (void)getchar();
    return 0;
}
