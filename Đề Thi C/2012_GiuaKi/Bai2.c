#include <stdio.h>
#include <stdlib.h>
#include "LISH.H"
void Input(list *s)
{
	int n;
	while(1)
	{
		printf("Nhap vao gia tri:");
		scanf("%d",&n);
		if(n==-1) break;
		InsertToLast(s,n);
	}
}
void PrintList(list *s,list *s1,list *s2)
{
	int k;
	while(1)
	{
		printf("\n1.In danh sach 1\n2.In danh sach 2\n3.In danh sach 3\n4.THoat chuc nang\n");
		printf("--------->CHON:\n");
		scanf("%d",&k);
		if(k==1) PrintScreen(s);
		if(k==2) PrintScreen(s1);
		if(k==3) PrintScreen(s2);
		if(k==4) break;
	}
}
void swap(ListNode **a,ListNode **b)
{
	ListNode **c;
	(*c)->data=(*a)->data;
	(*a)->data=(*b)->data;
	(*b)->data=(*c)->data;
}
void main()
{
	ListNode *temp,*temp1,*c;
	list *s,*s1,*s2;
	s=(list *)malloc(sizeof(list));
	s1=(list *)malloc(sizeof(list));
	s2=(list *)malloc(sizeof(list));
	s->first=NULL;
	s1->first=NULL;
	s2->first=NULL;
	int k;
	while(1)
	{
		printf("\n-------------------MENU----------------\n1.Nhap danh sach 1\n2.Nhap danh sach 2\n3.Gop danh sach\n4.In danh sach\n5.Thoat chuong trinh\n");
		printf("---->CHON CHUC NANG:");
		scanf("%d",&k);
		while(getchar()!='\n');
		if(k==1) Input(s);
		if(k==2) Input(s1);
		if(k==4) PrintList(s,s1,s2);
		if(k==5) break;
		if(k==3)
		{
			temp=s->first;
			while(temp!=NULL)
			{
				InsertToLast(s2,temp->data);
				temp=temp->next;
			}
			temp=s1->first;
			while(temp!=NULL)
			{
				InsertToLast(s2,temp->data);
				temp=temp->next;
			}
			for(temp=s2->first;temp!=NULL;temp=temp->next)
				for(temp1=temp->next;temp1!=NULL;temp1=temp1->next)
				{
					if(temp->data>temp1->data)
					{
						c->data=temp->data;
						temp->data=temp1->data;
						temp1->data=c->data;
					}
				}
		
		}

	}

}