#define _CRT_SECURE_NO_WARNINGS 1

#include "queue.h"

void queueInit(Queue* q)
{
	assert(q);
	q->head = q->tail = NULL;
}

void queuePush(Queue* q, QDateType x)
{
	assert(q);
	queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
	newNode->date = x;
	newNode->next = NULL;
	if (q->head == NULL)
	{
		q->head = q->tail = newNode;
	}
	else
	{
		q->tail->next = newNode;
		q->tail = newNode;
	}
}

int queueFront(Queue* q)
{
	assert(q);
	assert(!queueEmpty(q));

	return q->head->date;

}

int queueBack(Queue* q)
{
	assert(q);
	assert(!queueEmpty(q));

	return q->tail->date;
}

void queuePop(Queue* q)
{
	assert(q);
	assert(!queueEmpty(q));
	queueNode* next = q->head->next;
	free(q->head);
	q->head = next;
	if (q->head == NULL)
	{
		//当删除完毕后 要记得将尾指针也置空 不然会造成野指针
		q->tail = q->head = NULL;
	}
}

bool queueEmpty(Queue* q)
{
	assert(q);
	return q->head == NULL;
}

int queueSize(Queue* q)
{
	assert(q);
	int count = 0;
	queueNode* cur = q->head;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

void queueDestory(Queue* q)
{
	assert(q);
	queueNode* cur = q->head;
	while (cur)
	{
		queueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->head = q->tail = NULL;
}