﻿#include "pch.h"
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

void Get(const StaticArray* pL, int index, ElemType* result)
{
    const int length = Count(pL);
    assert(index >= 0);
    assert(length >= index + 1);
    *result = (index >= 0 && length >= index + 1) ? pL->data[index] : -1 ;     /* raise -1 if out of range */
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
    const int length = Count(pL);
    assert(length > 0);
    assert(index >= 0);
    assert(index <= length);
    *result = -1;
    if (length > 0 && index >= 0 && index <= length) {
        *result = pL->data[index];
        int i = index;
        for (; i < length; i++)
            pL->data[i] = pL->data[i + 1];
        pL->data[length - 1] = 0;
        pL->length--;
    }
}

void Destroy(StaticArray* pL)
{
}

void Print(StaticArray* pL)
{
    const int length = Count(pL);
    char buff[1 << 10];
    memset(buff, '\0', sizeof(buff));
    setvbuf(stdout, buff, _IOFBF, sizeof(buff));
    int i = 0;
    ElemType j;
    printf("Print:\n");
    for (; i < length; i++) {
        Get(pL, i, &j);
        printf("\tL[%d]=%d\n", i, j);
    }
    if (Empty(pL)) printf("\tEmpty\n");
    fflush(stdout);
    setvbuf(stdout, '\0', _IONBF, 0);
}
