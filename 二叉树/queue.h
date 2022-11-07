#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


struct BinaryTreeNode;
typedef struct BinaryTreeNode* QDateType;
typedef struct queueNode
{
	QDateType date;
	struct queueNode* next;
}queueNode;

typedef struct Queue
{
	queueNode* head;
	queueNode* tail;

}Queue;


void queueInit(Queue* q);

void queuePush(Queue* q, QDateType x);

int queueFront(Queue* q);

int queueBack(Queue* q);

void queuePop(Queue* q);

bool queueEmpty(Queue* q);

int queueSize(Queue* q);

void queueDestory(Queue* q);
