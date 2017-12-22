#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//----------------------------------------------------------------------------------
typedef struct T
{
	char name[11];
	int ma;
	struct T *left;
	struct T *right;	
} Tree; 
struct  T A[100];
Tree *Insert(Tree *root,Tree *Node)
{
	if(root==NULL) root=Node;
	else 
	{
		if(root->ma<Node->ma) root->right=Insert(root->right,Node);
		else if(root->ma>Node->ma) root->left=Insert(root->left,Node);
		// else if(strcmp(root->name,Node->name)==0) root->ma+=Node->ma;
	}
	return root;
}
char *catxau(char *a,char *b,char c)    
{
    int i,j= 0,k = 0;
    for(i = 0;i < strlen(a) + 1;i++)
    {
        if(a[i]== c)
        {
            b[i] = '\0';
            j = i + 1; break;
        }
        b[i] = a[i];
        if(i == strlen(a))
        {
            b[i] = '\0';    
        }
    }
    for(i = 0;i < strlen(a) ;i++)
    {
        a[i] = a[i+j];
    }
    return a;
}
Tree *ReadFileMakeTree(Tree *root)
{
	// printf("111111111111\n");
	FILE *f=fopen("A.txt","r");
	// printf("33333333333333\n");
	Tree *Node1,*Node2;
	char Tempchar[50],TempChar[30],ma1[10];
		char *TC,*TC2;
		 char vao[30],Nuon1[30];
    char *Nuon,temp[30],temp1[30];
	int count=1;
	int Diem1,Diem2,ma,i;
	// printf("44444444444\n");
	// while(fscanf(f,"%d",&Diem1)==1)
	// {	
	// 	printf("2222222222222222\n");
	// 	// fgetc();
	// 	fgetc(f);
	// 	fscanf(f,"%s\n",Tempchar);
	// 		printf("%s-%d\n", Tempchar,Diem1);
	// 			// fgetc(f);
	// 	// Node1=(Tree *)malloc(sizeof(Tree));
	// 	// 	// Node2=(Tree *)malloc(sizeof(Tree));
	
	// 	// root=Insert(root,Node1);
	// }

	    while(fgets(Tempchar,50,f)){
          	Tempchar[strlen(Tempchar) - 1] = '\0';// loai bo ky tu xuong dong
          		// printf("%s\n",Tempchar );

          		 Node1=(Tree *)malloc(sizeof(Tree));
          		  Nuon = catxau(Tempchar,Nuon1,'\t');
          		  // for (i = 0; i < strlen(Nuon); ++i)
          		  // {
          		  // 	/* code */
          		  // 	printf("%c\n", Nuon[i]);
          		  // }
          		  if ((strcmp(Nuon1,"\0")==0)||(strcmp(Nuon1,"\n")==0))
          		  {
          		  	/* code */
          		  	break;
          		  }
          		  if ((strcmp(Nuon,"\0")==0)||(strcmp(Nuon,"\n")==0))
          		  {
          		  	/* code */
          		  printf("Nhap thong tin cho ma so %s\n",Nuon1 );
          		  scanf("%s",temp);
          		 	strcpy(Nuon,temp);
          		 	printf("%s\n",Nuon );
          		  }
          		  strcpy(Node1->name,Nuon);
          		   Node1->ma = atoi(Nuon1);
          		printf("nuon %s---nuon1%d\n",Node1->name,Node1->ma);
          		root=Insert(root,Node1);
}
	fclose(f);
	return root;
}

int ReadFile()
{
	// printf("111111111111\n");
	FILE *f1=fopen("B.txt","r");
	// printf("33333333333333\n");
	Tree *Node1,*Node2;
	char Tempchar[50],TempChar[30],ma1[10];
		char *TC,*TC2;
		 char vao[30],Nuon1[30];
    char *Nuon,temp[30],temp1[30];
	int count=1;
	int Diem1,Diem2,ma,i =0;

	    while(fgets(Tempchar,50,f1)){
          	Tempchar[strlen(Tempchar) - 1] = '\0';// loai bo ky tu xuong dong
          		// printf("%s\n",Tempchar );

          		  Nuon = catxau(Tempchar,Nuon1,'\t');
          	
          		  if ((strcmp(Nuon1,"\0")==0)||(strcmp(Nuon1,"\n")==0))
          		  {
          		  	/* code */
          		  	break;
          		  }
          		  if ((strcmp(Nuon,"\0")==0)||(strcmp(Nuon,"\n")==0))
          		  {
          		  	/* code */
          		  printf("Nhap thong tin cho ma so %s\n",Nuon1 );
          		  scanf("%s",temp);
          		 	strcpy(Nuon,temp);
          		 	// printf("%s\n",Nuon );
          		  }
          		  strcpy(A[i].name,Nuon);
          		   A[i].ma = atoi(Nuon1);
          		// printf("nuon %s---nuon1%d\n",->name,Node1->ma);
          		// root=Insert(root,Node1);
          		i=i+1;
}
	fclose(f1);
	return i;
}

void PrintInorder(Tree *root)
{
	if(root!=NULL)
	{
		PrintInorder(root->left);
		printf("%-10s%-4d\n",root->name,root->ma);
		PrintInorder(root->right);

	}
}
Tree *Search(Tree *root,int s)
{
	if(root!=NULL)
	{
		// if(strcmp(root->name,s)<0) root=Search(root->right,s);
		// else if(strcmp(root->name,s)>0) root=Search(root->left,s); 
		if(root->ma<s) root=Search(root->right,s);
		else if(root->ma>s) root=Search(root->left,s); 
	}
	return root;
}
Tree *FindMin(Tree *root)
{
	if(root!=NULL)
	{
		while(root->left!=NULL)
			root=root->left;
	}
	return root;
}

Tree *Delete(Tree *root,char n[11])
{
	Tree *Temp;
	if(root==NULL) printf("Not found\n");
	else if(strcmp(root->name,n)<0) root->right=Delete(root->right,n);
	else if(strcmp(root->name,n)>0) root->left=Delete(root->left,n);
	else
		{
			if(root->left!=NULL && root->right!=NULL)
			{
				Temp=FindMin(root->right);
				root->ma=Temp->ma;
				strcmp(root->name,Temp->name);
				root->right=Delete(root->right,root->name);
			}
			else 
			{
				Temp=root;
				if(root->left==NULL) root=root->right;
				else if(root->right==NULL) root=root->left;
				free(Temp);
			}
		}
	return root;
}
Tree *DeleteNode(Tree *root,int n)
{
	if(root!=NULL)
	{

		root->left=DeleteNode(root->left,n);
		root->right=DeleteNode(root->right,n);
		if(root->ma < n)
		{
			printf("%-11s%-4d\n",root->name,root->ma);
			root=Delete(root,root->name);
		}			
	}
	return root;
}
// Tree *DeleteNode(Tree *root,int n)
// {
// 	if(root!=NULL)
// 	{

// 		root->left=DeleteNode(root->left,n);
// 		root->right=DeleteNode(root->right,n);
// 		if(root->ma = n)
// 		{
// 			printf("%-11s%-4d\n",root->name,root->ma);
// 			root=Delete(root,root->name);
// 		}			
// 	}
// 	return root;
// }
void WriteFile(Tree *root,FILE *f)
{
	if(root!=NULL)
	{
		WriteFile(root->left,f);
		fprintf(f, "%-11s%-4d\n",root->name,root->ma);
		WriteFile(root->right,f);
	}
}
void main()
{
	 
	int k,d=0,i;
	char s[11];
	int n;
	Tree *root=NULL;
	Tree *temp;
	while(1)
	{
		printf("\n-----------------MENU-----------------------\n");
		printf("1. Doc file va tao cay \n2. Doc file B \n3. tim kiem \n4. c\n5. xuat file\n------->Please choose");
		scanf("%d",&k); while(getchar()!='\n');
		if(k==1) root=ReadFileMakeTree(root);
		else if(k==2) PrintInorder(root);
		else if(k==3)
		{
		d = ReadFile();
		printf("%d\n",d );
		for ( i = 0; i < d; ++i)
		{
			/* code */
			printf("%d-%s\n",A[i].ma , A[i].name);
		}
		}
		else if(k==4)
		{	
				for ( i = 0; i < d; ++i)
		{
			/* code */
				temp = Search(root,A[i].ma );
				if (temp!=NULL)
				{
					/* code */
						printf("%s--%d\n", temp->name,temp->ma);
						root=DeleteNode(root,temp->ma);
						PrintInorder(root);

				}
			// printf("%d-%s\n",A[i].ma , A[i].name);
		}
			// temp = Search(root,303);
			// printf("%s\n", temp->name);
			// printf("Nhap vao so nguyen n:"); scanf("%d",&n); while(getchar()!='\n');
			// root=DeleteNode(root,n);
		}
		// else if(k==5)
		// {
		// 	// FILE *f=fopen("KetQua2.txt","w");
		// 	// WriteFile(root,f);
		// 	// fclose(f);
		// }
		else break;
	}
}
