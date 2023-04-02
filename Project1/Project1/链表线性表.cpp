#include<iostream>
using namespace std;
#define maxSize
#define MIN
//插入和删除
//1.元素插入顺序表
int insertElem(int sqList[], int& length, int p, int e)
{
	if (p<0 || p>length || length == maxSize)
	{
		return 0;
	}
	for (int i = length - 1; i >= p; i--)
	{
		sqList[i + 1] = sqList[i];
	}
	sqList[p] = e;
	length++;
	return 1;
}
//2.顺序表元素删除
int deleteElem(int sqList[], int& length, int p, int& e)
{
	if (p<0 || p>length - 1)
		return 0;
	e = sqList[p];
	for (int i = p ; i <= length - 1; i++)
	{
		sqList[i] = sqList[i + 1];
	}
	length--;
	return 1;
}

//建表
//1.顺序表
int A[maxSize];
int length;
int creat(int A[], int &length)
{
	cin >> length;
	if (length > maxSize)
		return 0;
	for (int i = 0; i < length; i++)
		cin >> A[i];
	return 1;
}
//2.链表
//(1)尾插法
void createLinkListR(LNode*& head)
{
	head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	LNode* p = NULL, * r = head;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		p = (LNode*)malloc(sizeof(LNode));
		p->next = NULL;
		cin >> p->data;
		p->next = r->next;
		r->next = p;
		r = p;
	}
}
//(2)头插法
void createLinkListH(LNode*& head)
{
	head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	LNode* p = NULL, * r = head;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		p = (LNode*)malloc(sizeof(LNode));
		p->next = NULL;
		cin >> p->data;
		p->next = head->next;
		head->next = p;
	}
}
//逆置
//1.顺序表
for (int i = left, j = right; i < j; i++; j--)
{
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
//2.链表 逆置p->next到q之间的节点
while (p->next != q)
{
	t = p->next;
	p->next = t->next;
	t->next = q->next;
	q->next = t;
}
//取最值
//顺序表
int max = a[0];
int maxIdx = 0;
for(int i = 0; i < n; i++)
{
	if (max < a[i])
	{
		max = a[i];
		maxIdx = i;
	}
}
//链表
LNode* p, * q;
int max = head->next->data;
q = p = head->next;
while(p != NULL)
{
	if (max < p->data)
	{
		max = p->data;
		q = p;
	}
	p = p->next;
}
//划分
//以数组内某一数值arr[k]为枢轴
void partition(int arr[], int n,int k)
{
	int temp;
	int i = 0, j = n - 1;
	temp = arr[0];
	arr[0] = arr[k];
	arr[k] = temp;
	temp = arr[i];
	while (i < j)
	{
		while (i < j && arr[j] >= temp)
			j--;
		if (i < j)
		{
			arr[i] = arr[j];
			i++;
		}
		while (i < j && arr[i] < temp)
			i++;
		if (i < j)
		{
			arr[j] = arr[i];
			j--;
		}
	}
	arr[i] = temp;
}
//单独添加枢轴
void partition(int arr[], int n, int comp)
{
	int temp;
	int i = 0, j = n - 1;
	temp = arr[i];
	while (i < j)
	{
		while (i < j && arr[j] >= comp)
			j--;
		if (i < j)
		{
			arr[i] = arr[j];
			i++;
		}
		while (i < j && arr[i] < comp)
			j++;
		if (i < j)
		{
			arr[j] = arr[i];
			j--;
		}
	}
	arr[i] = temp;
}
//归并
//顺序表
void mergearray(int a[], int m, int b[], int n, int c[])
{
	int i = 0, j = 0;
	int k;
	while (i < m && j < n)
	{
		if (a[i] < b[j])
			c[k++] = a[i++];//c[k] = a[i];k++;i++;
		else
			c[k++] = b[j++];
	}
	while (i < m)
		c[k++] = a[i++];
	while (j < m)
		c[k++] = b[j++];
}
//链表(默认两条原链表顺序从小到大排序）
//1.链表数值依次从小到大
void merge(LNode* A, LNode* B, LNode*& C)
{
	LNode* p = A->next;
	LNode* q = B->next;
	LNode* r;
	C = A;
	C->next = NULL;
	free(B);
	r = C;
	while (p != NULL && q != NULL)
	{
		if (p->data <= q->data)
		{
			r->next = p;
			p = p->next;
			r = r->next;
		}
		else
		{
			r->next = q;
			q = q->next;
			r = r->next;
		}
	}
	if(p != NULL)
		r->next = p;
	if(q != NULL)
		r->next = q;
}
//2.链表数值依次从小到大
void mergeR(LNode* A, LNode* B, LNode*& C)
{
	LNode* p = A->next;
	LNode* q = B->next;
	LNode* s;
	C = A;
	C->next = NULL;
	free(B);
	while (p != NULL && q != NULL)
	{
		if (p->data <= q->data)
		{
			s = p;
			p = p->next;
			s->next = C->next;
			C->next = s;
		}
		else
		{
			s = q;
			q = q->next;
			s->next = C->next;
			C->next = s;
		}
	} 
	while (p != NULL)
	{
		s = p;
		p = p->next;
		s->next = C->next;
		C->next = s;
	}
	while (q != NULL)
	{
		s = q;
		q = q->next;
		s->next = C->next;
		C->next = s;
	}
}

