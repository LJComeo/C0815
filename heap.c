#include "heap.h"

void adjustDown(Heap * hp,int m)//���µ����㷨
{
	int cur = m;
	int n;
	while (cur * 2 + 1<hp->size)
	{
		if (cur * 2 + 2 >=hp->size)
		{
			n = cur * 2 + 1;
		}
		else
		{
			if (hp->data[cur * 2 + 1] > hp->data[cur * 2 + 2])
			{
				n = cur * 2 + 1;
			}
			else
			{
				n = cur * 2 + 2;
			}
		}
		if (hp->data[cur] < hp->data[n])
		{
			int tmp = hp->data[cur];
			hp->data[cur] = hp->data[n];
			hp->data[n] = tmp;

			cur = n;
		}
		else
		{
			break;
		}
	}
}

void HeapInit(Heap* hp, HPDataType* a, int n)//��һ�����飬��ɶ�
{
	hp->capacity = n * 2;
	hp->size = n;
	hp->data = (HPDataType *)calloc(hp->capacity, sizeof(HPDataType));

	int i;
	for (i = 0; i < n; i++)
	{
		hp->data[i] = a[i];
	}
	for (i = n / 2 - 1; i >= 0;i--)
	{
		adjustDown(hp, i);
	}
}
void HeapDestory(Heap * hp)
{
	if (hp->data)
	{
		free(hp->data);
	}
	hp->data = NULL;
	hp->size = 0;
	hp->capacity = 0;
	
}
void HeapPush(Heap * hp, HPDataType x)//���ϵ����㷨
{
	if (hp->size == hp->capacity)
	{
		hp->capacity *= 2;
		hp->data = (HPDataType *)realloc(hp->data, hp->capacity*sizeof(HPDataType));
	}
	int cur = hp->size;

	hp->data[hp->size] = x;
	hp->size++;
	while (cur>0)
	{
		if (hp->data[cur] > hp->data[(cur - 1) / 2])
		{
			int tmp = hp->data[cur];
			hp->data[cur] = hp->data[(cur - 1) / 2];
			hp->data[(cur - 1) / 2] = tmp;

			cur = (cur - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(Heap * hp)//������βԪ��
{
	if (hp->size ==  0)
	{
		return 0;
	}
	hp->size--;
	int tmp = hp->data[0];
	hp->data[0] = hp->data[hp->size];
	hp->data[hp->size] = tmp;

	adjustDown(hp, 0);
}
HPDataType HeapTop(Heap * hp)//������Ԫ��
{
	if (hp->size == 0)
	{
		return (HPDataType)0;
	}
	return hp->data[0];
}
int HeapSize(Heap * hp)//�ѵĴ�С
{
	return hp->size;
}
int HeapEmpty(Heap * hp)//�ж϶��Ƿ�Ϊ��
{
	return hp->size == 0;
}
int HeapPrint(Heap * hp)
{
	int i;
	int rn = 0;
	int bin = 2;
	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->data[i]);
		if (i == rn)
		{
			putchar('\n');
			rn += bin;
			bin = bin * 2;
		}
	}
}
int HeapPrintS(Heap * hp)
{
	int i;
	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->data[i]);
	}
}
void HeapSort(Heap*hp)
{
	int tmp = hp->size;
	while (hp->size > 1)
	{
		HeapPop(hp);
	}
	hp->size = tmp;
}