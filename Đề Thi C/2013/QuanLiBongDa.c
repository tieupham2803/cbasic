#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10
typedef struct TNode 
{
	char MaDoi[11];
	int Diem;
	struct TNode *left;
	struct TNode *right;
} Tree;
//----------------------------------------------------------------------------
Tree *InsertTree(Tree *root,Tree *TreeNode);
Tree *MakeTree(Tree *root);
Tree *SearchNode(Tree *root,char s[11]);
void Inorder(Tree *root);
Tree *FindMin(Tree *root);
Tree *DeleteNode(Tree *root,char s[11]);
Tree *XuongHang(Tree *root,int n);
void GhiFile(Tree *root,FILE *f);
void WriteFile(Tree *root);
//---------------------------------------------------------------------------
Tree *InsertTree(Tree *root,Tree *TreeNode)
{
	if(root==NULL)	root=TreeNode;
	else 
	{
		if(strcmp(root->MaDoi,TreeNode->MaDoi)>0) root->left=InsertTree(root->left,TreeNode);
		else if(strcmp(root->MaDoi,TreeNode->MaDoi)<0) root->right=InsertTree(root->right,TreeNode);
		else if(strcmp(root->MaDoi,TreeNode->MaDoi)==0) root->Diem=root->Diem+TreeNode->Diem;
	}
	return root;
}
Tree *MakeTree(Tree *root)
{
	FILE *f=fopen("BongDa.txt","r");
	int Diem1;
	int Diem2;
	char Tempchar[11];
	Tree *Node1,*Node2;
	while(fscanf(f,"%s",&Tempchar)==1)
	{
		Node1=(Tree *)malloc(sizeof(Tree));
		Node2=(Tree *)malloc(sizeof(Tree));		
		Node1->Diem=Node2->Diem=0;
		strcpy(Node1->MaDoi,Tempchar);
		fscanf(f,"%s",&Node2->MaDoi);
		fscanf(f,"%d",&Diem1); fgetc(f);
		fscanf(f,"%d",&Diem2); fgetc(f);
		if(Diem1==Diem2)
		{
			Node1->Diem++;
			Node2->Diem++;
		}
		else if(Diem1 < Diem2) Node2->Diem+=3;
		else if(Diem1 > Diem2) Node1->Diem+=3;
		root=InsertTree(root,Node1);
		root=InsertTree(root,Node2);		
	}
	fclose(f);
	return root;
}
Tree *SearchNode(Tree *root,char s[11])
{
	if(root!=NULL)
	{
		if(strcmp(root->MaDoi,s)>0) root=SearchNode(root->left,s);
		else if(strcmp(root->MaDoi,s) < 0) root=SearchNode(root->right,s);
	}
	return root;
}
void Inorder(Tree *root)
{
	if(root!=NULL)
	{
		Inorder(root->left);
		printf("%-11s%-3d\n",root->MaDoi,root->Diem);
		Inorder(root->right);
	}
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
Tree *DeleteNode(Tree *root,char s[11])
{
	Tree *Node;
	Tree *temp;
	if(root==NULL) printf("Not found\n");
	else if(strcmp(s,root->MaDoi)<0) root->left=DeleteNode(root->left,s);
	else if(strcmp(s,root->MaDoi)>0) root->right=DeleteNode(root->right,s);
	else 
	if (root->left!=NULL && root->right!=NULL)
	{
		temp=FindMin(root->right);
		root->Diem=temp->Diem;
		strcpy(root->MaDoi,temp->MaDoi);
		root->right=DeleteNode(root->right,root->MaDoi);
	}
	else
	{
		temp=root;
		if(root->left==NULL)
			root=root->right;
		else if(root->right==NULL)
			root=root->left;
		free(temp);
	}
	return root;
}
Tree *XuongHang(Tree *root,int n)
{
	if(root!=NULL)
	{
		root->left=XuongHang(root->left,n);
		root->right=XuongHang(root->right,n);
		if(root->Diem < n) 
			root=DeleteNode(root,root->MaDoi);

	}
	return root;
}
void GhiFile(Tree *root,FILE *f)
{
	if(root!=NULL)
	{
		GhiFile(root->left,f);
		fprintf(f,"%s\t%d\n",root->MaDoi,root->Diem);
		GhiFile(root->right,f);
	}
}
void WriteFile(Tree *root)
{
	FILE *f=fopen("KetQua.txt","w");
	GhiFile(root,f);
	fclose(f);
}
void main()
{
	int k;
	char s[11];
	Tree *root=NULL;
	Tree *Node;
	int n;
	Node=(Tree *)malloc(sizeof(Tree));
	while(1)
	{
		printf("\n-------------------------------------------------------------------------\n");
		printf("1. Tao Cay\n2. Ket qua\n3. Tim Kiem\n4. Xuong hang\n5. Xuat file\n------>Please choose:");
		scanf("%d",&k);
		while(getchar()!='\n');
		if(k==1) root=MakeTree(root);
		else if(k==2)
			Inorder(root);
		else if(k==3)
		{
			printf("Nhap vao ma doi can tim kiem:"); gets(s);
			if(SearchNode(root,s)==NULL)
				printf("Khong tim thay ma doi!\n");
			else 
			{
				Node=SearchNode(root,s);
				printf("Diem so cua doi %s : %d\n",s,Node->Diem);
			}
		}
		else if(k==4)
		{
			printf("Nhap vao so diem:");
			scanf("%d",&n); while(getchar()!='\n');
			root=XuongHang(root,n);
			printf("Nhung Doi Bong Con Lai:\n");
			Inorder(root);
		}
		else if(k==5) WriteFile(root);
		else break;
	}
}
