//#include <stdio.h>
//
//int f(int n)
//{
//	return n == 1 ? 1 : f(n - 1) + n;
//}
//
//int main()
//{
//	printf("%d\n", f(10000));
//	
//	return 0;
//}

#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

// ���� -- ����� ���ھ�
// ���ݽṹ���鲻Ҫֱ�ӷ��ʽṹ���ݣ�һ��Ҫͨ�������ӿڷ���
void TestStack()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	printf("%d ", StackTop(&st));
	StackPop(&st);
	printf("%d ", StackTop(&st));
	StackPop(&st);

	StackPush(&st, 4);
	StackPush(&st, 5);

	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");
}

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);

	printf("%d ", QueueFront(&q));
	QueuePop(&q);
	printf("%d ", QueueFront(&q));
	QueuePop(&q);

	QueuePush(&q, 4);
	QueuePush(&q, 4);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");

	QueueDestroy(&q);
}

int main()
{
	//TestStack();
	TestQueue();

	return 0;
}