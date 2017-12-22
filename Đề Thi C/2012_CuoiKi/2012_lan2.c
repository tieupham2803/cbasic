#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//----------------------------------------------------------------------------------
typedef struct A
{
	char name[31];
	float score;
	struct A *next;
} ListNode;
typedef struct 
{
	ListNode *first,*last;
} list;
ListNode *MakeNode(char s[31],int n)
{
	ListNode *Node;
	Node=(ListNode *)malloc(sizeof(ListNode));
	Node->score=n;
	strcpy(Node->name,s);
	Node->next=NULL;
	return Node;
}
void InsertToLast(list *s,ListNode *Node)
{
	if(s->first==NULL)
		s->first=s->last=Node;
	else
	{
		s->last->next=Node;
		s->last=s->last->next;
	}
}

void ReadFile(list *s,FILE *f)
{
	ListNode *Node;
	char Tempchar[31];
	while(fgets(Tempchar,31,f)!=NULL)
	{
		Node=(ListNode *)malloc(sizeof(ListNode));
		strcpy(Node->name,Tempchar);
		Node->name[strlen(Node->name)-1]='\0';
		if(fscanf(f,"%f",&Node->score)!=1)
		{
			printf("Nhap vao diem cua sinh vien %s:\n",Node->name);
			scanf("%f",&Node->score);
		}
		fgetc(f);
		InsertToLast(s,Node);
	}
}
int Search(list *s,float n)
{
	int count=0;
	ListNode *temp;
	temp=s->first;
	while(temp!=NULL)
	{
		if(temp->score >= n)
		{
			printf("%-20s%-5.1f\n",temp->name,temp->score);
			count++;
		}
		temp=temp->next;
	}
	return count;
}
void List_Excellent(list *s1,list *s2,list *s3)
{
	ListNode *temp=s1->first;
	while(temp!=NULL)
	{
		if(temp->score>=8.5)
			InsertToLast(s3,MakeNode(temp->name,temp->score));
		temp=temp->next;
	}
	ListNode *temp2=s2->first;
	while(temp2!=NULL)
	{
		if(temp2->score>=8.5)
			InsertToLast(s3,MakeNode(temp2->name,temp2->score));
		temp2=temp2->next;
	}	
}
void PrintScreen(list *s)
{
	ListNode *temp;
	temp=s->first;
	while(temp!=NULL)
	{
		printf("%-20s%-5.1f%p\n",temp->name,temp->score,temp);
		temp=temp->next;
	}
	printf("\n");
}
void Insert_Sort(list *s, ListNode *Node)// sap xep giam dan
{
	ListNode *temp=s->first;
	if(s->first==NULL)
		s->first=s->last=Node;
	else
	{
		while(temp!=NULL)
		{
			if(s->first->score >= Node->score)//<=
			{
				Node->next=s->first;
				s->first=Node;
				break;
			}
			if(s->last->score <= Node->score)//>=
			{
				s->last->next=Node;
				s->last=s->last->next;
				break;
			}
			if(temp->score <= Node->score && Node->score <= temp->next->score)// >= >=
			{
				Node->next=temp->next;
				temp->next=Node;
				break;
			}
			temp=temp->next;
		}
	}
}
void GopDanhSach(list *s1,list *s2,list *s3)
{
	ListNode *temp=s1->first;
	while(temp!=NULL)
	{
		Insert_Sort(s3,MakeNode(temp->name,temp->score));
		temp=temp->next;
	}
	ListNode *temp2=s2->first;
	while(temp2!=NULL)
	{
		Insert_Sort(s3,MakeNode(temp2->name,temp2->score));
		temp2=temp2->next;
	}	
}
void WriteFile(list *s,FILE *f)
{
	ListNode *temp;
	temp=s->first;
	while(temp!=NULL)
	{
		fprintf(f,"%-20s\n%-5.1f\n",temp->name,temp->score);
		temp=temp->next;
	}
}
ListNode *DeleteToHead(list *s)
{
	ListNode *Node;
	Node=s->first;
	s->first=s->first->next;
	return Node;
}
ListNode *DeleteToLast(list *s)
{
	ListNode *temp;
	ListNode *temp1;
	temp=s->first;
	while(temp->next!=NULL)
	{
		temp1=temp;		
		temp=temp->next;
	}
	temp1->next=NULL;
	return temp;
}
ListNode *Delete(list *s,int n)
{
	ListNode *temp=s->first;
	ListNode *temp1=temp;
	if(s->first->score==n) return DeleteToHead(s);
	while(temp!=NULL)
	{
		if(temp->score==n)
		{
			temp1->next=temp->next;
			return temp;
		}
		temp1=temp;	
		temp=temp->next;
	}
	if(s->last->score==n) return DeleteToLast(s);	
}
void DeleteNode(list *s,int n)
{
	ListNode *temp=s->first;
	while(temp!=NULL)
	{
		if(temp->score < n)
			Delete(s,temp->score);
		temp=temp->next;
	}
}
void main()
{
	int k;
	list *s1=(list *)malloc(sizeof(list));
	s1->first=s1->last=NULL;
	list *s2=(list *)malloc(sizeof(list));
	s2->first=s2->last=NULL;
	list *s3=(list *)malloc(sizeof(list));
	s3->first=s3->last=NULL;	
	list *excellent=(list *)malloc(sizeof(list));
	excellent->first=excellent->last=NULL;			
	float n;
	while(1)
	{
		printf("\n-----------------MENU-----------------------\n");
		printf("1. Doc File\n2. Tim Kiem\n3. Danh sach xuat sac\n4. Ghi file\n5. Gop danh sach\n6. Xoa sinh vien\n------->Please choose:");
		scanf("%d",&k); while(getchar()!='\n');
		if(k==1)
		{
			FILE *f1=fopen("6D.txt","r");
			FILE *f2=fopen("6E.txt","r");
			ReadFile(s1,f1);
			ReadFile(s2,f2);
			fclose(f1);
			fclose(f2);
		}
		else if(k==2)
		{
			int count1,count2;
			printf("Nhap vao so thuc x:"); scanf("%f",&n);		
			count1=Search(s1,n);
			count2=Search(s2,n);
			if(count1==0 && count2==0)
				printf("Khong co sinh vien nao co diem lon hon bang %.1f\n",n );
		}

		else if(k==3)
		{
			List_Excellent(s1,s2,excellent);
			PrintScreen(excellent);
		}
		else if(k==4)
		{
			FILE *f=fopen("excellent2.txt","w");
			WriteFile(excellent,f);
			fclose(f);
		}
		else if(k==5)
		{
			GopDanhSach(s1,s2,s3);
			PrintScreen(s3);
		}
		else if(k==6)
		{
			printf("Nhap vao diem de xoa :"); scanf("%f",&n);
			DeleteNode(s3,n);
			PrintScreen(s3);

		}
		else break;
	}
}
