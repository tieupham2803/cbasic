#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
ListNode *MakeNode(char s[31],float n)
{
	ListNode *Node;
	Node=(ListNode *)malloc(sizeof(ListNode));
	Node->score=n;
	strcpy(Node->name,s);
	Node->next=NULL;
	return Node;
}
void Insert(list *s,ListNode *Node)
{
	if(s->first==NULL) s->first=s->last=Node;
	else
	{
		s->last->next=Node;
		s->last=s->last->next;
	}
}
void ReadFile(list *s,FILE *f)
{
	char Tempchar[31];
	ListNode *Node;
	/*while(!feof(f))
	{
		printf("son2\n");
		Node=(ListNode *)malloc(sizeof(ListNode));
		fgets(Node->name,31,f);
		Node->name[strlen(Node->name)-1]='\0';
		if(fscanf(f,"%f",&Node->score)==-1)
		{
			printf("Nhap vao diem cua %s:",Node->name );
			scanf("%f",&Node->score);
		}
		fgetc(f);
		Insert(s,Node);
	}*/
	while(fgets(Tempchar,31,f)!=NULL)
	{

		printf("son2\n");
		Node=(ListNode *)malloc(sizeof(ListNode));
		strcpy(Node->name,Tempchar);
		Node->name[strlen(Node->name)-1]='\0';
		if(fscanf(f,"%f",&Node->score)==-1)
		{
			printf("Nhap vao diem cua %s:",Node->name );
			scanf("%f",&Node->score);
		}
		fgetc(f);
		Insert(s,Node);
	}	
}
	void PrintScreen(list *s)
	{
		ListNode *Temp;
		Temp=s->first;
		while(Temp!=NULL)
		{
			printf("%-18s%-5.1f\n",Temp->name,Temp->score);
			Temp=Temp->next;
		}
	}

int Search(list *s,float n)
{
	ListNode *Temp;
	int count=0;
	Temp=s->first;
	while(Temp!=NULL)
	{
		if(n <=Temp->score)
		{
			printf("%-20s%-5.1f\n",Temp->name,Temp->score);
			count++;
		}
		Temp=Temp->next;
	}
	return count;
}
list *excellent_list(list *s1,list *s3)
{
	ListNode *Temp,*Node;
	Temp=s1->first;
	while(Temp!=NULL)
	{
		if(Temp->score >= 8.5) 
			Insert(s3,MakeNode(Temp->name,Temp->score));
		Temp=Temp->next;
	}
}
void WriteFile(list *s,FILE *f)
{
	ListNode *Temp;
	Temp=s->first;
	while(Temp!=NULL)
	{
		fprintf(f,"%-20s%-5.1f\n",Temp->name,Temp->score);
		Temp=Temp->next;
	}
}
void Tron(list *s1,list *s2)
{
	ListNode *Temp,*Node;
	Temp=s1->first;
	while(Temp!=NULL)
	{
		Insert(s2,MakeNode(Temp->name,Temp->score));
		Temp=Temp->next;
	}
}
void Swap(list *s)
{
	ListNode *temp,*temp1;
	temp=s->first;
	char tg[30];
	int k;
	for(temp=s->first;temp!=NULL;temp=temp->next)
		for(temp1=temp->next;temp1!=NULL;temp1=temp1->next)
		{
			if(temp->score < temp1->score)
			{
				strcpy(tg,temp->name);
				strcpy(temp->name,temp1->name);
				strcpy(temp1->name,tg);
				k=temp->score;
				temp->score=temp1->score;
				temp1->score=k;
			}
		}
}
void main()
{
	int k;
	float Search_float;
	list *s1,*s2,*s3,*excellent;
	s1=(list *)malloc(sizeof(list));
	s2=(list *)malloc(sizeof(list));
	s3=(list *)malloc(sizeof(list));
	excellent=(list *)malloc(sizeof(list));
	s1->first=s1->last=NULL;
	s2->first=s2->last=NULL;
	s3->first=s3->last=NULL;	
	excellent->first=excellent->last=NULL;	
	FILE *f1,*f2;
	while(1)
	{
		printf("\n-----------------MENU-----------------------\n");
		printf("1. Doc File \n2. Search \n3. DS Xuat Sac\n4. Ghi FIle\n5.Tron danh sach \n6.In man hinh\n------->Please choose");
		scanf("%d",&k); while(getchar()!='\n');
		if(k==1) 
		{
			f1=fopen("6D.txt","r"); f2=fopen("6E.txt","r");
			ReadFile(s1,f1);
			ReadFile(s2,f2);
			fclose(f1);
			fclose(f2);
		}
		else if(k==2)
		{
			int count=0;
			printf("Nhap vao diem can tim:"); scanf("%f",&Search_float);
			if(Search(s1,Search_float)==0) 
				count++;
			if(Search(s2,Search_float)==0)
				count++;
			if(count==2) printf("khong co cai can tim\n");
		}
		else if(k==3)
		{
			excellent_list(s1,excellent);
			excellent_list(s2,excellent);
			PrintScreen(excellent);
		}
		else if(k==4)
		{
			FILE *f=fopen("excellent.txt","w");
			WriteFile(excellent,f);
			fclose(f);
		}
		else if(k==5)
		{
			Tron(s1,s3);
			Tron(s2,s3);	
			Swap(s3);
			PrintScreen(s3);
		}
		else if(k==6) 
		{
			PrintScreen(s1);
			PrintScreen(s2);
		}
		else break;
	}
}
