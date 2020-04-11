#include "pch.h"
#include "static_array.h"

StaticArray _array;
char buff[1 << 10];
void test()
{
    memset(buff, '\0', sizeof(buff));
    setvbuf(stdout, buff, _IOFBF, sizeof(buff));
    Init(&_array);
    ElemType i = 0;
    while (Append(&_array, &i))
        i++;
    Print(&_array);
    fflush(stdout);
}


int main()
{
    test();
    (void)getchar();
    return 0;
}
