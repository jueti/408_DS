#include "pch.h"
#include "static_array.h"

void Init(StaticArray* pL)
{
    assert(pL);
    memset(pL, '\0', MAX_SIZE * sizeof(ElemType));
    pL->length = 0;
}

int Count(const StaticArray* pL)
{
    assert(pL);
    return pL->length;
}

bool Empty(const StaticArray* pL)
{
    return Count(pL) ? false : true;
}

bool Full(const StaticArray* pL)
{
    return (Count(pL) == MAX_SIZE) ? true : false;
}

ElemType Get(const StaticArray* pL, int index)
{
    const int length = Count(pL);
    assert(index >= 0);
    assert(length >= index + 1);
    return (index >= 0 && length >= index + 1) ? pL->data[index] : -1 ;     /* raise -1 if out of range */
}

int Locate(const StaticArray* pL, const ElemType* elem)
{
    const int length = Count(pL);
    int i = 0;
    for (; i < length; i++)
        if (pL->data[i] == *elem)
            return i;
    return -1;                                                                           /* raise -1 if no such elem */
}

bool Insert(StaticArray* pL, const int index, const ElemType* elem)
{
    const int length = Count(pL);
    assert(index >= 0);
    assert(length >= index + 1);
    assert(length < MAX_SIZE);
    if (length == MAX_SIZE) return false;
    int i = length - 1;
    for (; i >= index; i--)
        pL->data[i + 1] = pL->data[i];
    pL->data[index] = *elem;
    pL->length++;
    return true;
}

bool Append(StaticArray* pL, const ElemType* elem)
{
    const int length = Count(pL);
    if (length == MAX_SIZE) return false;
    pL->data[length] = *elem;
    pL->length++;
    return true;
}

void Delete(StaticArray* pL, const int index, ElemType* result)
{
    
}

void Destroy(StaticArray* pL)
{
}

void Print(StaticArray* pL)
{
    const int length = Count(pL);
    int i = 0;
    for (; i < length; i++) {
        /*j = pL->data[i];*/
        printf("L[%d]=%d\n", i, Get(pL, i));
    }
}
