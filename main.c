#include "heap.h"

int main1()
{
	int data[10] = { 6, 2, 5, 9, 8, 7, 1, 10, 4, 3 };
	Heap hp;

	HeapInit(&hp, data, 10);

	HeapPush(&hp, 13);
	HeapPush(&hp, 11);

	HeapPop(&hp);

	HeapPrint(&hp);

	HeapDestory(&hp);




	system("pause");
	return 0;
}