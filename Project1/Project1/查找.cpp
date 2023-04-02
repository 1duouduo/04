#include <iostream>
using namespace std;
//˳�����
//˳���
int Search(int arr[], int n, int key)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == key)
			return 1;
	return -1;
}
//��ʽ��
LNode* Search(LNode* head, int key)
{
	LNode* p = head->next;
	while (p != NULL)
	{
		if (p->next == key)
			return p;
		p = p->next;
	}
	return NULL;
}
//�۰����(�����������飩
int BSearch(int arr[], int low, int high, int key)
{
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] == key)
			return mid;
		else if (arr[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
//�ֿ����(���ú���һ�������Ե�����,�ֿ飬�����۰����ȷ����Χ��������˳������ҵ�Ԫ�أ�
typedef struct
{
	int maeKey;
	int low, high;

}indexElem;
indexElem index[5];
int keys[15];
//����������
//����1.
BTNode* BSTSearch(BTNode* p, int key)
{
	while (p != NULL)
	{
		if (key == p->key)
			return p;
		else if (key < p->key)
			p = p->lChild;
		else
			p = p->rChild;
	}
	return NULL;
}
//2.
BTNode* BSTSearch(BTNode* p, int key)
{
	if (p == NULL)
		return NULL;
	else
	{
		if (p->key == key)
			return p;
		else if (key < p->key)
			return BSTSearch(p->lChild, key);
		else
			return BSTSearch(p->rChild, key);
	}
}
//����ؼ���
int BSTInsert(BTNode*& p, int key)
{
	if (p == NULL)
	{
		p = (BTNode*)malloc(sizeof(BTNode));
		p->lChild = p->rChild = NULL;
		p->key = key;
		return 1;

	}
	else
	{
		if (key == p->key)
			return 0;
		else if (key < p->key)
			return BSTInsert(p->lChild, key);
		else
			return BSTInsert(p->rChild, key);
	}
}
//ɾ���ؼ���
//����������������

int main()
{

}