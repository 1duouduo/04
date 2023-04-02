/*非空有序单链表，删除值域重复结点*/
#include <iostream>
using namespace std;

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode;
void del(LNode* L)
{
	LNode *p = L->next, *q;
	while (p->next != NULL)
	{
		if (p->data == p->next->data)
		{
			q = p->next;
			p->next = q->next;
			free(q);
		}
		else
			p = p->next;
	}
}
void createList(LNode*& head, int arr[], int n)
{
	head = (LNode*)malloc(sizeof(LNode));
	head-> next = NULL;
	LNode* r = head;
	for (int i = 0; i < n; i++)
	{
		LNode* p = (LNode*)malloc(sizeof(LNode));
		p->data = arr[i];
		p->next = NULL;
		r->next = p;
		r = p;
	}


}
void printList(LNode* L)
{
	LNode* p;
	p = L->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

}
int main()
{
	int a[] = { 1,2,2,3,3,4,4,5,5,6,6,7,7,8 };
	LNode* A;
	createList(A, a, 15);
	del(A);
	printList(A);
	return 0;
}