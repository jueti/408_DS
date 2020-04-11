#include "pch.h"
#include "static_array.h"

StaticArray _array;
char buff[1 << 10];
// 1K    1:45
// 0.25M 1:26
// 1M    1:28
// 64M   1:26
void test()
{
    memset(buff, '\0', sizeof(buff));
    setvbuf(stdout, buff, _IOFBF, sizeof(buff));
    Init(&_array);
    ElemType i = 0;
    while (Append(&_array, &i))
        i++;
    PrintList(&_array);
    fflush(stdout);
}

void test_1() {
    Init(&_array);
    int i = 0;
    while (!Full(&_array))
        AppendList(&_array, i++);
    PrintList(&_array);
};

int main()
{
    test();
    //(void)getchar();
    return 0;
}
