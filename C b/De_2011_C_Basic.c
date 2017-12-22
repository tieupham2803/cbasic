/*
Ho va Ten : Nguyen Van Quang
MSSV      : 20133099
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct dic 
{
	char Eng[20];
	char VN[20];
	struct dic *left;
	struct dic *right;
}Dictonary;

void Save_file(FILE *ptr,Dictonary **root);
void Outputfile(Dictonary ** root);
void Deleteall(Dictonary *root);
Dictonary * Nhapthem(char *a);
void Translate(Dictonary **root);
void PirnMaxMin(Dictonary **root);
void Prin1();
void InSearNuon(Dictonary **root,char *a);
void Prin(Dictonary *a);
void InSearNode(Dictonary **Node,char *a,char *b);
Dictonary *AddNode(char *a,char *b);
void Read_file(Dictonary **root);
int InSear(Dictonary **root,char *a);


main()
{
	Dictonary *root = NULL;
	int imenu;
	while(1)
	{
		printf("\n==============MENU==============\n");
		printf("  1:Tao cay \n");
		printf("  2:Ket qua theo thu tu tang dan \n");
		printf("  3:Tim kiem \n");
		printf("  4:Xuong hang va in \n");
		printf("  5:Xuat file \n");
		printf("  6:Thoat\n");
		printf("Moi ban chon chuc nang\n");
		scanf("%d",&imenu);
		while(getchar() != '\n');
		switch(imenu)
		{
			case 1 :
			{
				Read_file(&root);
				continue;
			}
			case 2 :
			{
				PirnMaxMin(&root);
				continue;
			}
			case 3 :
			{
				Translate(&root);
				continue;
			}
			case 4:
			{
				continue;
			}
			case 5 :
			{
				Outputfile(&root);
				continue;
			}
			default :
			{
				printf("Input wroong!...\n");
                printf("Please input again!\n");
			}
			case 6 :
			{
				Deleteall(root);
				break;
			}
		}
		break;
	}
}
//============================================================================
void Read_file(Dictonary **root)
{
	FILE *ptr;
	char Nuon[20], Mean[20];
	char filename[] = "Dictonary.txt";
	if((ptr = fopen(filename ,"r")) == NULL)
	{
		printf("Can not file\n");
	}
	else
	{
		while(fscanf(ptr,"%s",Nuon) == 1)
		{
			fgetc(ptr);
			fgets(Mean,20,ptr);
			Mean[strlen(Mean) - 1] = '\0';
			if(InSear(root,Nuon) == 0)
			{
				InSearNode(root,Nuon,Mean);
			}
		}
	}
	fclose(ptr);
}
//===================================================================================
int InSear(Dictonary **root,char *a)
{
	if((*root) == NULL)
	{	
		return 0;
	}
	else
	{
	if(strcmp((*root) -> Eng,a) > 0)
	{
		return (InSear(&(*root) -> left,a));
	}
	else if(strcmp((*root) -> Eng,a) < 0)
	{
		return (InSear(&(*root) -> right,a));
	}
	else if(strcmp((*root) -> Eng,a) == 0)
		{
			return 1;
		}
	}
}
//==========================================================================================
Dictonary *AddNode(char *a,char *b)
{
	Dictonary *Node;
	Node = (Dictonary*)malloc(sizeof(Dictonary));
	strcpy(Node -> Eng ,a);
	strcpy(Node -> VN ,b);
	Node -> left = NULL;
	Node -> right = NULL;
	return Node;
}
//=========================================================================================
void InSearNode(Dictonary **Node,char *a,char *b)
{
	if((*Node) == NULL)
	{
		(*Node) = AddNode(a,b);
	}
	else if(strcmp((*Node) -> Eng,a) < 0)
	{
		InSearNode(&(*Node) -> right,a,b);
	}
	else if(strcmp((*Node) -> Eng,a) > 0)
	{
		InSearNode(&(*Node) -> left,a,b);		
	}
}
//========================================================================================
void Prin1()
{
	printf("%s\t%s\n","English","Viet Nam");
}
//========================================================================================
void Prin(Dictonary *a)
{
	if(a != NULL)
	{
		printf("%s\t%s\n",a -> Eng,a ->VN);
		Prin(a ->left);
		Prin(a ->right);
	}
}
//=========================================================================================
void PirnMaxMin(Dictonary **root)
{
	Dictonary *a;
	a = (*root);
	if(a != NULL)
	{
		PirnMaxMin(&a -> left);
		printf("%s\t%s\n",a -> Eng,a -> VN);
		PirnMaxMin(&a -> right);
	}
}
//==================================================================================
void Translate(Dictonary **root)
{
	char a[10][20];
	char *Nuon;
	char s[250];
	printf("Moi ban nhap cau muon tra\n");
	fgets(s,250,stdin);
	s[strlen(s) - 1] = '\0';
	int i =0,j;
	Nuon = strtok(s," ");
	while(Nuon != NULL)
	{
		strcpy(a[i],Nuon);
		printf("%s\n",Nuon);
		Nuon = strtok(NULL," ");
		i++;
	}
	for(j = 0;j < i; j++)
	{
		InSearNuon(root,a[j]);
	}
}
//===============================================================================
void InSearNuon(Dictonary **root,char *a)
{
	if((*root) == NULL)
	{	
		printf("Thieu tu\n");
		(*root) = Nhapthem(a);
	}
	else if(strcmp((*root) -> Eng,a) > 0)
	{
		InSearNuon(&(*root) -> left,a);
	}
	else if(strcmp((*root) -> Eng,a) < 0)
	{
		InSearNuon(&(*root) -> right,a);
	}
	else if(strcmp((*root) -> Eng,a) == 0)
	{
		printf("\t%s",(*root) -> VN);
	}
}
//=======================================================================================
Dictonary * Nhapthem(char *a)
{
	char b[20];
	printf("MOi ban nhap nghia cua tu %s la :\n",a);
	fgets(b,20,stdin);
	b[strlen(b) - 1] = '\0';
	return AddNode(a,b);
}
//======================================================================================
void Save_file(FILE *ptr,Dictonary **root)
{
	if((*root))
	{
		fprintf(ptr,"%s%s",(*root)->Eng,"\t");
		fputs((*root) -> VN,ptr);
		fprintf(ptr, "%s","\n" );
		Save_file(ptr,&(*root)->left);
		Save_file(ptr,&(*root)->right);
	}
}
//=======================================================================================
void Outputfile(Dictonary ** root)
{
	FILE *ptr;
	char filename[] = "Ketqua.txt";
	if((ptr = fopen (filename , "w")) == NULL)
	{
		printf("Can not open file\n");
	}
	else
		Save_file(ptr,root);
}
//========================================================================================
void Deleteall(Dictonary *root)
{
	if(root)
	{
		Deleteall(root -> left);
		Deleteall(root -> right);
		free(root);
	}
}