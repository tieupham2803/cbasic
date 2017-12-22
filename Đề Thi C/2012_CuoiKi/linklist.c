#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct A
{
	char name[31];
	char mssv[10];
	float score;
	struct A *next;
} ListNode;
typedef struct 
{
	ListNode *first,*last;
} list;
ListNode *MakeNode(char s[31],char mssv[10],float n)
{
	ListNode *Node;
	Node=(ListNode *)malloc(sizeof(ListNode));
	Node->score=n;
	strcpy(Node->name,s);
	strcpy(Node->mssv,mssv);
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

void PrintScreen(list *s)
{
	ListNode *Temp;
	Temp=s->first;
	while(Temp!=NULL)
	{
		printf("%10s-%-30s%-5.1f\n",Temp->mssv,Temp->name,Temp->score);
		Temp=Temp->next;
	}
}
int Search(list *s)
{	int count = 0;
	ListNode *Temp;
	Temp=s->first;
	 char a[40];
    printf("Moi ban nhap mssv \n");
    fgets(a,40,stdin);
    a[strlen(a) - 1] = '\0';
	while(Temp!=NULL)
	{
		if(strcmp(Temp ->mssv ,a) == 0)
		{
			printf("%10s-%-30s%-5.1f\n",Temp->mssv,Temp->name,Temp->score);
			  count=count+1;
			
		}
		Temp=Temp->next;
	}
	if (count==0)
	{
		/* code */
		printf("khong tim thay sinh vien\n");
	}
	return count;
}
void DeleteMssv(list *s)
	{
	int count = 0;
	ListNode *Temp;
	ListNode *Temp1;
	// ListNode *Save;
	Temp1=(ListNode *)malloc(sizeof(ListNode));
	Temp1->next =s->first;// tao first ao tranh truong hop delete head
	// Temp->next=s->first;
	s->first=Temp1;
	Temp=s->first;
	// printf("%s\n",Temp->next->name );

	 char a[40];
    printf("Moi ban nhap mssv can xoa\n");
    fgets(a,40,stdin);
    a[strlen(a) - 1] = '\0';
    printf("%s\n",a );

	while(Temp->next!=NULL)
	{	

		if(strcmp(Temp->next->mssv ,a) == 0)
		{
			printf("asdas\n");
			// printf("%10s-%-30s\n",Temp->next->mssv,Temp->next->name);
			  // count=count+1;
			ListNode *Save;
	Save=(ListNode *)malloc(sizeof(ListNode));
			 Save = Temp->next;
			Temp->next=Save->next;
			
			Temp = Temp->next;
			free(Save);
		}
	
	

}
	s->first= s->first->next;
		free(Temp1);
}	
void Makelist(list *s)
{
	char Tempchar[31];
	 char a[10];
	ListNode *Node;
    printf("Moi ban nhap mssv \n");
    gets(a);
    Node=(ListNode *)malloc(sizeof(ListNode));
    strcpy(Node->mssv,a);
    printf("Nhap vao diem\n");
	scanf("%f",&Node->score);
	while(getchar()!='\n');
	 printf("Moi ban nhap ten \n");
    // fgets(Tempchar,40,stdin);
	 gets(Tempchar);
        // Tempchar[strlen(Tempchar) - 1] = '\0';
     strcpy(Node->name,Tempchar);
	Insert(s,Node);
}

void main()
{
	int k;
	// float Search_float;
	list *s1,*s2,*s3,*excellent;
	s1=(list *)malloc(sizeof(list));
	// s2=(list *)malloc(sizeof(list));
	// s3=(list *)malloc(sizeof(list));
	// excellent=(list *)malloc(sizeof(list));
	// s1->first=s1->last=NULL;
	// s2->first=s2->last=NULL;
	// s3->first=s3->last=NULL;	
	// excellent->first=excellent->last=NULL;	
	// FILE *f1,*f2;
	while(1)
	{
		printf("\n-----------------MENU-----------------------\n");
		printf("1.Nhap Sinh Vien \n2. Search \n3. Xoa\n4. Ghi FIle\n5.Tron danh sach \n6.In man hinh\n------->Please choose");
		scanf("%d",&k); while(getchar()!='\n');
		if(k==1) 
		{
			Makelist(s1);
			PrintScreen(s1);
		}
		else if(k==2)
		{
			// int count=0;
			// printf("Nhap vao diem can tim:"); scanf("%f",&Search_float);
			// if(Search(s1,Search_float)==0) 
			// 	count++;
			// if(Search(s2,Search_float)==0)
			// 	count++;
			// if(count==2) printf("khong co cai can tim\n");
			// PrintScreen(s1);
			Search(s1);
		}
		else if(k==3)
		{
			// excellent_list(s1,excellent);
			// excellent_list(s2,excellent);
			// PrintScreen(excellent);
			// char xoa[10];
			// printf("nhap vao mssv can xoa\n");
			// scanf("%s",xoa);
			// printf("%s\n",xoa);
			DeleteMssv(s1);
			// PrintScreen(s1);
		}
		else if(k==4)
		{
		// 	FILE *f=fopen("excellent.txt","w");
		// 	WriteFile(excellent,f);
		// 	fclose(f);
		}
		else if(k==5)
		{
			// Tron(s1,s3);
			// Tron(s2,s3);	
			// Swap(s3);
			// PrintScreen(s3);
		}
		else if(k==6) 
		{
			// PrintScreen(s1);
			// PrintScreen(s2);
		}
		else break;
	}
}
