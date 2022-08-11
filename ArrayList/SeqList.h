#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//#ifndef __SEQLIST_H__
//#define __SEQLIST_H__
////...
//#endif

// Shunxubiao -- 二狗  铁柱  招弟

// 静态的顺序表 -- 不知道要存储多少数据？
//#define N 10000
//typedef int SLDataType;
//struct SeqList
//{
//	SLDataType a[N];
//	int size; // 存储数据的个数
//};

// 动态顺序表
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;      // 存储数据的个数
	int capacity;  // 存储空间的大小
}SL;

//void SeqListInit(SL sl);
void SLInit(SL* psl);
void SLDestory(SL* psl);
void SLPrint(const SL* psl);

// 头插头删 尾插尾删
void SLPushBack(SL* psl, SLDataType x);
void SLPushFront(SL* psl, SLDataType x);
void SLPopBack(SL* psl);
void SLPopFront(SL* psl);

// 没有找到就返回-1
int SLFind(SL* psl, SLDataType x);

// 顺序表在pos位置插入x
void SLInsert(SL* psl, size_t pos, SLDataType x);

// 顺序表删除pos位置的值
void SLErase(SL* psl, size_t pos);

void SLModify(SL* psl, size_t pos, SLDataType x);