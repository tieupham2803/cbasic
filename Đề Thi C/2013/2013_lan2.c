#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//----------------------------------------------------------------------------------
typedef struct T
{
	char name[11];
	int score;
	struct T *left;
	struct T *right;	
} Tree; 
Tree *Insert(Tree *root,Tree *Node)
{
	if(root==NULL) root=Node;
	else 
	{
		if(strcmp(root->name,Node->name)<0) root->right=Insert(root->right,Node);
		else if(strcmp(root->name,Node->name)>0) root->left=Insert(root->left,Node);
		else if(strcmp(root->name,Node->name)==0) root->score+=Node->score;
	}
	return root;
}
Tree *ReadFileMakeTree(Tree *root)
{
	FILE *f=fopen("BongDa2.txt","r");
	Tree *Node1,*Node2;
	char TempChar[11];
	int count=1;
	int Diem1,Diem2;
	while(fscanf(f,"%s",&TempChar)==1)
	{
		Node1=(Tree *)malloc(sizeof(Tree));
		Node2=(Tree *)malloc(sizeof(Tree));
		Node1->score=Node2->score=0;
		strcpy(Node1->name,TempChar);
		fscanf(f,"%s",&Node2->name);
		fscanf(f,"%d",&Diem1); fgetc(f);
		fscanf(f,"%d",&Diem2); fgetc(f);
		if(Diem1==Diem2)
		{
			Node1->score++;
			Node2->score++;
		}
		else if(Diem1 < Diem2) Node2->score+=3;
		else if(Diem2 < Diem1) Node1->score+=3;
		root=Insert(root,Node1);
		root=Insert(root,Node2);
	}
	fclose(f);
	return root;
}
void PrintInorder(Tree *root)
{
	if(root!=NULL)
	{
		PrintInorder(root->left);
		printf("%-10s%-4d\n",root->name,root->score);
		PrintInorder(root->right);
	}
}
Tree *Search(Tree *root,char s[11])
{
	if(root!=NULL)
	{
		if(strcmp(root->name,s)<0) root=Search(root->right,s);
		else if(strcmp(root->name,s)>0) root=Search(root->left,s); 
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
				root->score=Temp->score;
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
		if(root->score < n)
		{
			printf("%-11s%-4d\n",root->name,root->score);
			root=Delete(root,root->name);
		}			
	}
	return root;
}
void WriteFile(Tree *root,FILE *f)
{
	if(root!=NULL)
	{
		WriteFile(root->left,f);
		fprintf(f, "%-11s%-4d\n",root->name,root->score);
		WriteFile(root->right,f);
	}
}
void main()
{
	int k;
	char s[11];
	int n;
	Tree *root=NULL;
	while(1)
	{
		printf("\n-----------------MENU-----------------------\n");
		printf("1. Doc file va tao cay \n2. In man hinh \n3. tim kiem \n4. xuong hang\n5. xuat file\n------->Please choose");
		scanf("%d",&k); while(getchar()!='\n');
		if(k==1) root=ReadFileMakeTree(root);
		else if(k==2) PrintInorder(root);
		else if(k==3)
		{
			printf("Nhap vao ma doi can tim kiem:" ); gets(s);
			if(Search(root,s)==NULL) printf("Khong co ten doi can tim!");
			else 
			{
				printf("%-11s%-4d\n",Search(root,s)->name,Search(root,s)->score);
			}
		}
		else if(k==4)
		{
			printf("Nhap vao so nguyen n:"); scanf("%d",&n); while(getchar()!='\n');
			root=DeleteNode(root,n);
		}
		else if(k==5)
		{
			FILE *f=fopen("KetQua2.txt","w");
			WriteFile(root,f);
			fclose(f);
		}
		else break;
	}
}
