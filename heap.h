#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdio.h>
#include <stdlib.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* data;
	int size;
	int capacity;
}Heap;
void HeapInit(Heap* hp, HPDataType* a, int n);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
int HeapPrint(Heap*hp);
void adjustDown(Heap * hp, int n);//向下调整算法
// 堆排序
void HeapSort(int* a, int n);
void TestHeap();

#endif //_HEAP_H_