// Tu Dien
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Tnode
{
	char Anh[15];
	char Viet[21];
	struct Tnode *left;
	struct Tnode *right;
} Tree;
Tree *InsertNode(Tree *root,Tree *Node)
{
	if(root==NULL) root=Node;
	else
	{
		if(strcmp(root->Anh,Node->Anh)>0) root->left=InsertNode(root->left,Node);
		else if(strcmp(root->Anh,Node->Anh)<0) root->right=InsertNode(root->right,Node);
	}
	return root;
}
Tree *ReadFile_MakeTree(Tree *root)
{
	FILE *f=fopen("data.txt","r");
	Tree *Node;
	char TempChar[15];
	while(fscanf(f,"%s",&TempChar)==1)
	{
		Node=(Tree *)malloc(sizeof(Tree));
		strcpy(Node->Anh,TempChar);
		fgetc(f);
		fgets(Node->Viet,21,f); 
		Node->Viet[strlen(Node->Viet)-1]='\0';
		root=InsertNode(root,Node);

	}
	return root;
}
void PrintInorder(Tree *root)
{
	if(root!=NULL)
	{
		PrintInorder(root->left);
		printf("%s\t%s\n",root->Anh,root->Viet);
		PrintInorder(root->right);
	}
}
Tree *SearchNode(Tree *root,char *s)
{
	if(root!=NULL)
	{
		if(strcmp(root->Anh,s)>0) root=SearchNode(root->left,s);
		else if(strcmp(root->Anh,s)<0) root=SearchNode(root->right,s);
	}
	return root;
}
Tree *MakeNode(char s[15])
{
	Tree *Node;
	Node=(Tree *)malloc(sizeof(Tree));
	strcpy(Node->Anh,s);
	printf("Nhap vao nghia tieng viet:"); gets(Node->Viet);
	Node->left=NULL;
	Node->right=NULL;
	return Node;
}void Translate(Tree *root,char s[100])
{
	char *kq;
	int length,i=0;
	Tree *Node;
	length=strlen(s);
	for(i=0;i<length;i++)
		if(s[i]<= 'Z' && s[i] >='A')
			s[i]=s[i]+32;		
	kq=strtok(s," ");
	while(kq!=NULL)
	{
		Node=SearchNode(root,kq);
		if(Node==NULL)
		{
			printf("%-10s%-20s\n",kq,": Thieu Tu");
			InsertNode(root,MakeNode(kq));
		}
		else 
			printf("%-20s%-20s\n",Node->Anh,Node->Viet);
		kq=strtok(NULL," ");
	}
}
/*void Translate(Tree *root,char s[100])
{
	int length,i,j=0;
	Tree *Node;
	char TempChar[20];
	length=strlen(s);
	for(i=0;i<length;i++)
		if(s[i]<='Z' && s[i]>='A')
			s[i]+=32;
	for(i=0;i<length;i++)
	{
		TempChar[j]=s[i];
		++j;
		if(s[i+1]==' ' || s[i+1]=='\0') 
		{
			TempChar[j+1]='\0';
			Node=SearchNode(root,TempChar);
			if(Node==NULL)
			{
				printf("%-10s:%-20s\n",TempChar,"Thieu Tu");
				InsertNode(root,MakeNode(TempChar));
			}
			else
				printf("%-20s%-20s\n",Node->Anh,Node->Viet);
			i++;
			j=0;
		}
	}
}*/
void WriteFile(Tree *root,FILE *f)
{
	if(root!=NULL)
	{
		WriteFile(root->left,f);
		fprintf(f,"%s\t%s\n",root->Anh,root->Viet);
		WriteFile(root->right,f);
	}
}
void main()
{
	int k;
	char s[100];
	Tree *root=NULL;
	while(1)
	{
		printf("\n-------------------------------------------------------------------------------------\n");
		printf("1. Read File and Make Tree\n2. Print Screen\n3. Translate\n4. Exit program\n------>Please choose:");
		scanf("%d",&k); while(getchar()!='\n');
		if(k==1) root=ReadFile_MakeTree(root);
		else if(k==4)
		{
			FILE *f=fopen("data.txt","w");
			WriteFile(root,f);
			fclose(f);
			break;
		}
		else if(k==2) PrintInorder(root);
		else if(k==3) 
		{
			printf("Nhap vao cau van:"); gets(s);
			Translate(root,s);
		}
	}
}