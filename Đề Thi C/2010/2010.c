#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//----------------------------------------------------------------------------------
typedef struct node
{
	char biethieu[20];
	int mau;
	int tancong;
	int nhanhnhen;
	int phongthu;
	int score;
	struct node *next;
} ListNode;
typedef struct 
{
	ListNode *first,*last;
} list;
void Insert(list *s,ListNode *Node)
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
	char tempchar[20];
	while(fscanf(f,"%s",&tempchar)==1)
	{
		Node=(ListNode *)malloc(sizeof(ListNode));
		strcpy(Node->biethieu,tempchar);
		fscanf(f,"%d",&Node->mau);
		fscanf(f,"%d",&Node->tancong);
		fscanf(f,"%d",&Node->nhanhnhen);
		fscanf(f,"%d",&Node->phongthu);
		if(Node->mau <0 || Node->tancong < 0 || Node->nhanhnhen <0 || Node->phongthu <0)
		{
			printf("Du lieu sai!\n");
			return;
		}
		Node->score=0;
		Insert(s,Node);			
	}
}
int Sizeoflist(list *s)
{
	int count=0;
	ListNode *temp=s->first;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}
void ThiDau(list *s1,list *s2)
{
	ListNode *temp1=s1->first;
	ListNode *temp2=s2->first;
	int trandau=1;
	int count1=0;
	int count2=0;

	int matmau;
	while(temp1!=NULL && temp2!=NULL)
	{
		printf("TRAN %d:\n",trandau);
		printf("%s(%d, %d, %d, %d)  ",temp1->biethieu,temp1->mau,temp1->tancong,temp1->nhanhnhen,temp1->phongthu);
		printf("  vs  %s(%d, %d, %d, %d)\n",temp2->biethieu,temp2->mau,temp2->tancong,temp2->nhanhnhen,temp2->phongthu);
		while(temp1->mau >0 && temp2->mau >0)
		{	
			if(temp1->nhanhnhen>temp2->nhanhnhen)
			{
				matmau = temp1->tancong - temp2->phongthu;
				if(matmau<=0) matmau=0;
				printf("%s(%d) tan cong %s(%d) mat %d mau \n",temp1->biethieu,temp1->mau,temp2->biethieu,temp2->mau,matmau);
				temp2->mau=temp2->mau-matmau;
				count1++;
				if(temp2->mau <= 0 && count1==1)
				{
					printf("%s bi KNOCKOUT.\n",temp2->biethieu);
					temp1->score+=3;
				}
				else temp1->score++;
				if(temp2->mau <=0 && count1!=1)
					printf("%s bi loai.\n",temp2->biethieu);
				else if(temp2->mau >=0)
				{
					matmau= temp2->tancong- temp1->phongthu;
					printf("%s(%d) tan cong %s(%d) mat %d mau \n",temp2->biethieu,temp2->mau,temp1->biethieu,temp1->mau,matmau);
					count2++;	
					temp1->mau = temp1->mau - matmau;
					if(temp1->mau <= 0 && count1==1)
					{
						printf("%s bi KNOCKOUT.\n",temp1->biethieu);
						temp2->score+=3;
					}
					else temp2->score++;
					if(temp1->mau <=0 && count1!=1)
						printf("%s bi loai.\n",temp1->biethieu);								
				}
			}
			else
			{
				matmau = temp2->tancong - temp1->phongthu;
				if(matmau<=0) matmau=0;
				printf("%s(%d) tan cong %s(%d) mat %d mau \n",temp2->biethieu,temp2->mau,temp1->biethieu,temp1->mau,matmau);
				count2++;
				temp1->mau = temp1->mau - matmau;
				if(temp1->mau <= 0 && count2==1)
				{
					printf("%s bi KNOCKOUT.\n",temp1->biethieu);
					temp2->score+=3;
				}
				else temp2->score++;	
				if(temp1->mau <=0 && count2!=1)
					printf("%s bi loai.\n",temp1->biethieu);
				else if(temp1->mau >=0)
				{
					matmau= temp1->tancong- temp2->phongthu;
					printf("%s(%d) tan cong %s(%d) mat %d mau \n",temp1->biethieu,temp1->mau,temp2->biethieu,temp2->mau,matmau);
					count1++;	
					temp2->mau = temp2->mau - matmau;
					if(temp2->mau <= 0 && count2==1)
					{
						printf("%s bi KNOCKOUT.\n",temp2->biethieu);
						temp1->score+=3;
					}
					else temp1->score++;
					if(temp2->mau <=0 && count2!=1)
						printf("%s bi loai.\n",temp2->biethieu);								
				}

			}
		}
		trandau++;
		if(temp1->mau <= 0) temp1=temp1->next;
		if(temp2->mau <= 0) temp2=temp2->next;
		count1=count2=0;
	}
	if(temp1==NULL) printf("MON PHAI 2 CHIEN THANG\n");
	else printf("MON PHAI 1 CHIEN THANG\n");
}
void Insert_Sort(list *s,ListNode *Node)
{
	ListNode *temp=s->first;
	if(s->first==NULL)
		s->first=s->last=Node;
	else
	{
		while(temp!=NULL)
		{
			if(s->first->score <= Node->score)
			{
				Node->next=s->first;
				s->first=Node;
				break;
			}
			if(s->last->score >= Node->score)
			{
				s->last->next=Node;
				s->last=s->last->next;
				break;
			}
			if(temp->score >= Node->score && Node->score >= temp->next->score)
			{
				Node->next=temp->next;
				temp->next=Node;
				break;
			}
			temp=temp->next;
		}
	}
}
ListNode *MakeNode(char s[20],int a,int b,int c,int d,int e)
{
	ListNode *Node=(ListNode *)malloc(sizeof(ListNode));
	strcpy(Node->biethieu,s);
	Node->mau=a;
	Node->tancong=b;
	Node->nhanhnhen=c;
	Node->phongthu=d;
	Node->score=e;
	Node->next=NULL;
	return Node;			
}
void Xephang(list *s1,list *s2,list *sort)
{
	ListNode *temp,*temp2;
	temp=s1->first;
	while(temp!=NULL)
	{
		Insert_Sort(sort,MakeNode(temp->biethieu,temp->mau,temp->tancong,temp->nhanhnhen,temp->phongthu,temp->score));
		temp=temp->next;
	}
	temp2=s2->first;
	while(temp2!=NULL)
	{
		Insert_Sort(sort,MakeNode(temp2->biethieu,temp2->mau,temp2->tancong,temp2->nhanhnhen,temp2->phongthu,temp2->score));
		temp2=temp2->next;
	}	

}
void PrintXepHang(list *s)
{
	ListNode *temp=s->first;
	while(temp!=NULL)
	{
		printf("%-20s%-5d\n",temp->biethieu,temp->score);
		temp=temp->next;
	}
}
void PrintScreen(list *s)
{
	ListNode *temp=s->first;
	while(temp!=NULL)
	{
		printf("%-20s%-5d%-5d%-5d%-5d\n",temp->biethieu,temp->mau,temp->tancong,temp->nhanhnhen,temp->phongthu);
		temp=temp->next;
	}
}
void main()
{
	int k;
	list *s1,*s2;
	s1=(list *)malloc(sizeof(list));
	s1->first=s1->last=NULL;
	s2=(list *)malloc(sizeof(list));
	s2->first=s2->last=NULL;
	list *sort=(list *)malloc(sizeof(list));
	sort->first=sort->last=NULL;	
	while(1)
	{
		printf("\n-----------------MENU-----------------------\n");
		printf("1. ReadFile \n2. ThiDau \n3. Xephang \n4. Thoat chuong trinh \n------->Please choose:");
		scanf("%d",&k); while(getchar()!='\n');
		if(k==1)
		{
			FILE *f1=fopen("monphai1.txt","r");
			FILE *f2=fopen("monphai2.txt","r");
			ReadFile(s1,f1);
			ReadFile(s2,f2);
			if(Sizeoflist(s1)!=Sizeoflist(s2))
				printf("Luc luong khong can bang. sua lai du lieu\n");
			printf("MON PHAI 1:\n");
			PrintScreen(s1);
			printf("MON PHAI 2:\n");
			PrintScreen(s2);			
			fclose(f1);
			fclose(f2);		
		}
		else if(k==2) ThiDau(s1,s2);
		else if(k==3) 
		{
			Xephang(s1,s2,sort);
			PrintXepHang(sort);
		}
		else break;
	}
}