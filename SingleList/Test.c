#include "SList.h"

void TestSList1()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);

	SListDestory(&plist);
}

void TestSList2()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListDestory(&plist);

}


void TestSList3()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 3);
	if (pos)
	{
		// 修改
		pos->data *= 10;
		printf("找到了\n");
	}
	else
	{
		printf("没有找到\n");
	}
	SListPrint(plist);

	pos = SListFind(plist, 2);
	if (pos)
	{
		SListInsert(&plist, pos, 20);
	}
	SListPrint(plist);

	pos = SListFind(plist, 1);
	if (pos)
	{
		SListInsert(&plist, pos, 10);
	}
	SListPrint(plist);

	SListDestory(&plist);
}

int main()
{
	//TestSList1();
	TestSList3();

	return 0;
}


//void swapi(int* px, int* py)
//{
//	int tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//
//void swapptr(int** ppx, int** ppy)
//{
//	int* tmp = *ppx;
//	*ppx = *ppy;
//	*ppy = tmp;
//}
//
//int main()
//{
//	int x = 0, y = 1;
//	swapi(&x, &y);
//
//	int* p1 = &x, *p2 = &y;
//	swapptr(&p1, &p2);
//
//	TestSList1();
//
//	return 0;
//}