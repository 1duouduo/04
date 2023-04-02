#include<iostream>
using namespace std;
//二叉树深度遍历代码
// 1.递归
//先序遍历
void r(BTNode* p)
{
	if (p != NULL)
	{
		visit(p);
		r(p->lchild);
		//(2)
		r(p->rchild);
		//(3)
	}
}
//中序遍历
void r(BTNode* p)
{
	if (p != NULL)
	{
		r(p->lchild);
		visit(p);
		r(p->rchild);
	}
}
//后序遍历
void r(BTNode* p)
{
	if (p != NULL)
	{
		r(p->lchild);
		r(p->rchild);
		visit(p);
	}
}
//2.非递归
//先序遍历
void preorderNonrecursion(BNode* bt)
{
	if (bt != NULL)
	{
		BTNode* Stack[maxSize];
		int top = -1;
		BTNode* p = NULL;
		Stack[++top] = bt;
		while (top != -1)
		{
			p = Stack[top--];
			Visit(p);
			if (p->rChild != NULL)
				Stack[++top] = p->child;
			if (p->lchild != NULL)
				Stack[++top] = p->child;
		}
	}
}
//后序遍历
void postorderNonrecursion(BTNode* bt)
{
	if (bt != NULL)
	{
		BTNode* Stack1[maxSize];//辅助遍历栈
		int top1 = -1;
		BTNode* Stack2[maxSize];//逆序的栈
		int top2 = -1;
		BTNode* p = NULL;
		Stack1[++TOP1] = bt;
		while (top != -1)
		{
			p = Stack1[top--];
			Stack2[++top2] = p;
			if (p->lchild != NULL)
				Stack1[++top1] = p->lChild;
			if (p->rchild != NULL)
				Stack1[++top1] = p->rChild;
		}
		//逆后序：先遍历右子树，再遍历根，最后遍历左子树
		while (top2 != -1)
		{
			p = Stack2[top--];
			Visit(p);
		}
	}
}
//中序遍历
void inorderNonrecursion(BTNode* bt)
{
	if (bt != NULL;)
	{
		BTNode* Stack[maxSize];
		int top = -1;
		BTNode* p = NULL;
		p = bt;
		while (top != -1 || p != NULL)
		{
			while (p != NULL)
			{
				Stack[++top] = p;
				p = p->lChild;
			}
			if (top != -1)
			{
				p = Stack[top--];
				Visit(p);
				p = p->rChild;
			}
		}
	}
}
//二叉树层次遍历
void level(BTNode* bt)
{
	if (bt != NULL)
	{
		int front, rear;
		BTNode* que[maxSize];
		front = rear = 0;
		BTNode* p;
		rear = (rear + 1) % maxSize;
		que[rear] = bt;
		while (front != rear)
		{
			front = (front + 1) % maxSize;
			p = que[front];
			Visit(p);
			if (p->lChild != NULL)
			{
				rear = (rear + 1) % maxSize;
				que[rear] = p->lChild;
			}
			if (p->rChild != NULL)
			{
				rear = (rear + 1) % maxSize;
				que[rear] = p->rChild;
			}
		}
	}
}
//树的深度优先遍历
//先序遍历
void postOrder(TNode* p, TNode tree[])
{
	if (p != NULL)
	{
		Branch* q;
		q = p->first;
		while (q != NULL)
		{
			postOrder(&tree[q->cIdx], tree);
			q = q->next;
		}
		visit(p);
	}
}
//树的广度优先遍历
void level(TNode* tn, TNode tree[])
{
	int front, rear;
	TNode* que[maxSize];
	front = rear = 0;
	TNode* p;
	if (tn != NULL)
	{
		rear = (rear + 1) % maxSize;
		que[rear] = tn;
		while (front != rear)
		{
			front = (front + 1) % maxSize;
			p = que[front];
			visit(p);
			Branch* q = p->first;
			while (q != NULL)
			{
				rear = (rear + 1) % maxSize;
				que[rear] = &tree[q->cIdx];
				q = q->next;
			}
		}
	}
}
//中序线索二叉树
void inThread(TBTNode* p, TBTNode*& pre)
{
	if (p != NULL)
	{
		inThread(p->lChild, pre);
		if (p->lChild == NULL)
		{
			p->lChild = pre;
			p->lTag = 1;
		}
		if (pre != NULL && pre->rChild == NULL)
		{
			pre->rChild = p;
			pre->rTag = 1,
		}
		pre = p;
		inThread(p->rChild, pre);
	}
}
//前序线索二叉树
void preThread(TBTNode* p, TBTNode*& pre)
{
	if (p != NULL)
	{
		if (p->lChild == NULL)
		{
			p->lChild = pre;
			p->lTag = 1;
		}
		if (pre != NULL && pre->rChild == NULL)
		{
			pre->rChild == p;
			pre->rTag = 1;
		}
		pre = p;
		if(p->lTag == 0)
			preThread(p->lChild, pre);
		if(p->rTag == 0)
			preThread(p->rChild, pre);
	}
}
//遍历操作
void preOrder(TBTNode* tbt)
{
	if (tbt != NULL)
	{
		TBTNode* p = tbt;
		while (p != NULL)
		{
			while (p->lTag == 0)
			{
				visit(p);
				p = p->rChild;
			}
			visit(p);
			p = p->rChild;
		}
	}
}
//后续线索二叉树
void postThread(TBTNode* p, TBTNode*& pre)
{
	if (p != NULL)
	{
		postThread(p->lChild, pre);
		postThread(p->rChild, pre);
		if (p->lChild == NULL)
		{
			p->lChild = pre;
			p->lTag = 1;
		}
		if (pre != NULL && pre->rChild == NULL)
		{
			pre->rChild = p;
			pre->rTag = 1;
		}
		pre = p;
	}
}
//根据遍历序列确定二叉树
//已知前序和中序遍历序列
BTNode* CreateBT(char pre[], char in[], int L1, int R1, int L2, int R2)
{
	if (L1 > R1)
		return NULL;
	BTNode* s = (BTNode*)malloc(sizeof(BTNode));
	s->lChild = s->rChild = NULL;
	s->data = pre[L1];
	int i;
	for (i = L2; i <= R2; i++)
		if (in[i] == pre[L1])
			break;
	s->lChild = CreateBT(pre, in, L1 + 1, L1 + i - L2, L2, i - 1);
	s->rChild = CreateBT(pre, in, L1 + i - L2 + 1, R1, i + 1, R2);
	return s;
}
//已知后序和中序遍历序列
BTNode* CreteBT(char post[], char in[], int L1, int R1, int L2, int R2)
{
	if (L1 > R1)
		return NULL;
	BTNode* s = (BTNode*)malloc(sizeof(BTNode));
	s->lChild = s->rChild = NULL;
	s->data = post[R1];
	int i;
	for (i = L2; i <= R2; i++)
		if (in[i] == post[R1])
			break;
	s->lChild = CreateBT2(post, in, L1, L1 + i - L2 - 1, L2, i - 1);
	s->rChild = CreateBT2(post, in, L1 + i - L2, R1 - 1, i + 1, R2);
	return s;
}
//已知层次遍历和中序遍历序列
int search(char arr[], char key, int L, int R)
{
	int idx;
	for (idx = L; idx <= R; idx++)
		if (arr[idx] == key)
			return idx;
	return -1;
}
void getSubLevel(char subLevel[], char level[], char in[], int n, int L, int R)
{
	int k = 0;
	for (int i = 0; i < n; i++)
		if (search(in, level[i], L, R) != -1)
			subLevel[k++] = level[i];
}
BTNode* CreateBT(char level[], char in[], int n, int L, int R)
{
	if (L > R)
		return NULL;
	BTNode* s = (BTNode*)malloc(sizeof(BTNode));
	s->lChild = s->rChild = NULL; 
	s->data = level[0];
	int i = search(in, level[0], L, R);
	int LN = i - L;
	char LLevel[LN];
	int RN = R - i;
	char RLevel[RN];
	getSubLevel(LLevel, level, in, n, L, i - 1);
	getSubLevel(RLevel, level, in, n, i + 1, R);
	s->lChild = CreateBT3(LLevel, in, LN, L, i - 1);
	s->rChild = CreateBT3(RLevel, in, RN, i + 1, R);
	return s;
}
//用树计算求值
int calsub(float opand1, char op, float opand2, float& result)
{
	if (op == '+')
		result = opand1 + opand2;
	if (op == '-')
		result = opand1 - opand2;
	if (op == '*')
		result = opand1 * opand2;
	if (op == '/')
	{
		if (fabs(opand2) < MIN)
			return 0;
		else
			result = opand1 / opand2;
	}
	return 1;
}
float cal(BTNode* root)
{
	if (root->lChild == NULL && root->rChild == NULL)
		return root->data - '0';
	else
	{
		float opand1 = cal(root->lChild);
		float opand2 = cal(root->rChild);
		float result;
		calSub(opand1, root->data, opand2, result);
		return result;
	}
}
