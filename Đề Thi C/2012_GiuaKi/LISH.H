#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
} ListNode;
typedef struct 
{
	ListNode *first,*last;
} list;
ListNode *CreatNode(int n)
{
	ListNode *temp;
	temp=(ListNode *)malloc(sizeof(ListNode));
	temp->data=n;
	temp->next=NULL;
	return temp;	
}
void MakeFirstLast(list *s,int n)
{
	if(s->first==NULL)
		s->first=s->last=CreatNode(n);
}
void InsertToHead(list *s,int n)
{
	ListNode *temp;
	if(s->first==NULL)
		s->first=s->last=CreatNode(n);
	else
	{
	temp=CreatNode(n);
	temp->next=s->first;
	s->first=temp;}
}
void InsertToLast(list *s,int n)
{
	ListNode *temp;
	if(s->first==NULL)
		s->first=s->last=CreatNode(n);
	else {
	temp=CreatNode(n);
	s->last->next=temp;
	s->last=s->last->next;}
}
void InsertToMiddle(list *s,ListNode *prev,int n)
{
	if(s->first==NULL)
		s->first=s->last=CreatNode(n);
	else {
	ListNode *temp;
	temp=CreatNode(n);
	temp->next=prev->next;
	prev->next=temp;}
}
void PrintScreen(list *s)
{
	ListNode *temp;
	temp=s->first;
	while(temp!=NULL)
	{
		printf("%-3d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void Swap(ListNode **a,ListNode **b)
{
	ListNode **c;
	(*c)->data=(*a)->data;
	(*a)->data=(*b)->data;
	(*b)->data=(*c)->data;
}
int SizeOfList(list *s)
{
	ListNode *temp;
	int count=0;
	temp=s->first;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}
