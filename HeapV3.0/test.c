#include "Heap.h"
#include <time.h>

// 
//int main()
//{
//	//int a[] = { 15, 18, 19, 25, 28, 34, 65, 49, 27, 37 };
//	int a[] = { 65, 100, 70, 32, 50, 60 };
//	HP hp;
//	HeapInit(&hp);
//	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
//	{
//		HeapPush(&hp, a[i]);
//	}
//
//	//HeapPush(&hp, 10);
//	//HeapPrint(&hp);
//
//	//HeapPop(&hp);
//	//HeapPrint(&hp);
//
//	//HeapPop(&hp);
//	//HeapPrint(&hp);
//
//	while (!HeapEmpty(&hp))
//	{
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//
//	return 0;
//}

// 空间复杂度O(N)
//void HeapSort(int* a, int n)
//{
//	HP php;
//	HeapInit(&php);
//}

// O(N*logN)
void HeapSort(int* a, int n)
{
	// 建堆 -- 向上调整建堆 - O(N*logN)
	//for (int i = 1; i < n; ++i)
	//{
	//	AdjustUp(a, i);
	//}

	// 大思路：选择排序，依次选数，从后往前排
	// 升序 -- 大堆
	// 降序 -- 小堆
	// 建堆 -- 向下调整建堆 - O(N)
	for (int i = (n-1-1)/2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	// 选数
	int i = 1;
	while (i < n)
	{
		Swap(&a[0], &a[n - i]);
		AdjustDown(a, n - i, 0);
		++i;
	}
}

//int main()
//{
//	//int a[] = { 65, 100, 60, 32, 50, 70 };
//	int a[] = { 15, 1, 19, 25, 8, 34, 65, 4, 27, 7 };
//	HeapSort(a, sizeof(a) / sizeof(int));
//
//	for (size_t i = 0; i < sizeof(a) / sizeof(int); ++i)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//
//	return 0;
//}

void CreateDataFile(const char* filename, int N)
{
	FILE* fin = fopen(filename, "w");
	if (fin == NULL)
	{
		perror("fopen fail");
		return;
	}
	srand(time(0));

	for (int i = 0; i < N; ++i)
	{
		fprintf(fin, "%d\n", rand()%1000000);
	}

	fclose(fin);
}

void PrintTopK(const char* filename, int k)
{
	assert(filename);

	FILE* fout = fopen(filename, "r");
	if (fout == NULL)
	{
		perror("fopen fail");
		return;
	}

	int* minHeap = (int*)malloc(sizeof(int)*k);
	if (minHeap == NULL)
	{
		perror("malloc fail");
		return;
	}
	// 如何读取前K个数据
	for (int i = 0; i < k; ++i)
	{
		fscanf(fout, "%d", &minHeap[i]);
	}

	// 建k个数小堆
	for (int j = (k - 2) / 2; j >= 0; --j)
	{
		AdjustDown(minHeap, k, j);
	}

	// 继续读取后N-K
	int val = 0;
	while (fscanf(fout, "%d", &val) != EOF)
	{
		if (val > minHeap[0])
		{
			minHeap[0] = val;
			AdjustDown(minHeap, k, 0);
		}
	}

	for (int i = 0; i < k; ++i)
	{
		printf("%d ", minHeap[i]);
	}

	free(minHeap);
	fclose(fout);
}

int main()
{
	const char* filename = "Data.txt";
	int N = 10000;
	int K = 10;
	//CreateDataFile(filename, N);
	PrintTopK(filename, K);

	return 0;
}