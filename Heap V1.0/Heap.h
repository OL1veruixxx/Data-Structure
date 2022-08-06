#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HeapPrint(HP* php);

void HeapInit(HP* php);
void HeapDestroy(HP* php);
// 插入x继续保持堆形态
void HeapPush(HP* php, HPDataType x);
// 删除堆顶元素
void HeapPop(HP* php);
// 返回堆顶的元素
HPDataType HeapTop(HP* php);
bool HeapEmpty(HP* php);
int HeapSize(HP* php);



