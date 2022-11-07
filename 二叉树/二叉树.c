#define _CRT_SECURE_NO_WARNINGS 1

#include "queue.h"
typedef char BTDate;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDate date;
}BTNode;

BTNode* BuyNode(BTDate x)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	if (newNode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newNode->date = x;
	newNode->left = newNode->right = NULL;
	return newNode;
}


BTNode* CreatBinaryTree()
{
	BTNode* nodeA = BuyNode('A');
	BTNode* nodeB = BuyNode('B');
	BTNode* nodeC = BuyNode('C');
	BTNode* nodeD = BuyNode('D');
	BTNode* nodeE = BuyNode('E');
	BTNode* nodeF = BuyNode('F');

	nodeA->left = nodeB;
	nodeA->right = nodeC;
	nodeB->left = nodeD;
	nodeC->left = nodeE;
	nodeC->right = nodeF;

	return nodeA;
}


//前序遍历
void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->date);
	PreOrder(root->left);
	PreOrder(root->right);
}

//中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		return ;
	}
	InOrder(root->left);
	printf("%c ", root->date);
	InOrder(root->right);
}


//后序遍历
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return ;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->date);
}




//二叉树大小
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

//方法二 计算二叉树的节点个数
void BinaryTreeSize2(BTNode* root, int* count)
{
	if (root == NULL)
	{
		return;
	}
	(*count)++;
	BinaryTreeSize2(root->left, count);
	BinaryTreeSize2(root->right, count);
}


//二叉树叶子节点的个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}


//求二叉树第K层节点的个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return  0;
	}
	if (k == 1)
	{
		return 1;
	}

	// root不等空，k也不等于1，说明root这颗树的第k节点在子树里面
	// 转换成求左右子树的第k-1等的节点数量
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
	
}

//求二叉树的高度
int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	int leftH = BinaryTreeDepth(root->left);
	int rightH = BinaryTreeDepth(root->right);
	
	return leftH > rightH ? leftH + 1 : rightH + 1;
}



//找二叉树中值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDate x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->date == x)
	{
		return root;
	}

	BTNode* leftRet = BinaryTreeFind(root->left, x);
	if (leftRet)
	{
		return leftRet;
	}

	BTNode* rightRet = BinaryTreeFind(root->right, x);
	if (rightRet)
	{
		return rightRet;
	}

	return NULL;
}

//层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Queue q;
	queueInit(&q);
	queuePush(&q, root);
	while (!queueEmpty(&q))
	{
		BTNode* temp = queueFront(&q);
		printf("%c ", temp->date);
		queuePop(&q);
		
		if (temp->left)
			queuePush(&q, temp->left);

		if (temp->right)
			queuePush(&q, temp->right);
		
	}
}

// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
		return true;

	Queue q;
	queueInit(&q);
	queuePush(&q, root);
	while (!queueEmpty(&q))
	{
		BTNode* temp = queueFront(&q);
		queuePop(&q);
		if (temp == NULL)
		{
			break;
		}
		else
		{
			queuePush(&q, temp->left);
			queuePush(&q, temp->right);
		}
	}
	// 遇到空了以后，检查队列中剩下的节点
	// 1、剩下全是空给，则是完全二叉树
	// 2、剩下存在非空，则不是完全二叉树
	while (!queueEmpty(&q))
	{
		BTNode* temp = queueFront(&q);
		
		if (temp != NULL)
		{
			queueDestory(&q);
			return false;
		}
			
		queuePop(&q);
	}

	queueDestory(&q);
	return true;
}

void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestory(root->left);
	BinaryTreeComplete(root->right);
	free(root);
}


int main()
{
	BTNode* root = CreatBinaryTree();
	//前序遍历
	PreOrder(root);
	printf("\n");
	//中序遍历
	InOrder(root);
	printf("\n");
	//后序遍历
	PostOrder(root);
	printf("\n");

	printf("%d ", BinaryTreeSize(root));
	printf("\n");

	int n1 = 0;
	BinaryTreeSize2(root, &n1);
	printf("%d\n", n1);
	//层序遍历
	BinaryTreeLevelOrder(root);

	return 0;
}