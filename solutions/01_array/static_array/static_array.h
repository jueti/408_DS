#ifndef __STATIC_ARRAY_H
#define __STATIC_ARRAY_H

#define MAX_SIZE 10

typedef int ElemType;
typedef struct {
    ElemType data[MAX_SIZE];
    int length;
} StaticArray;

void Init(StaticArray* pL);
int Count(const StaticArray* pL);
bool Empty(const StaticArray* pL);
bool Full(const StaticArray* pL);
void Get(const StaticArray* pL, const int index, ElemType* result);
int Locate(const StaticArray* pL, const ElemType* elem);
bool Insert(StaticArray* pL, const int index, const ElemType elem);
bool Append(StaticArray* pL, const ElemType* elem);
void Delete(StaticArray* pL, const int index, ElemType* result);
void Destroy(StaticArray* pL);
void Print(StaticArray* pL);
#endif // __STATIC_ARRAY_H
