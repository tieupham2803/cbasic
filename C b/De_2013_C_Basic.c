/*
Ho va Ten : Nguyen Van Quang
MSSV      : 20133099
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bd
{
	char Name[10];
	int point;
	struct bd *left;
	struct bd *right;
}Soccer;

void Free(Soccer *root);
void Infile(FILE *ptr,Soccer **root);
void Outputfile(Soccer ** root);
void Xuonghang(Soccer **root);
void SearInput(Soccer **root);
Soccer *Right_Min(Soccer **root);
int True(char *s);	
void Prin(Soccer *root);
void Prin1();
void InserNode(Soccer **root,char *a,int b);
void Read_file(Soccer **root);
void DeletePlay(Soccer **root,char *s);
void DeleteNode(Soccer **root,int a);
void Data(FILE **fin,int *point1,int *point2,char *Name1,char *Name2);
//void Diem(int a,int b,int *c,int *d);
int InSear(Soccer **root,char *a,int b);
Soccer * AddNode(char *a,int b);

main()
{
	Soccer *root = NULL;
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
				Prin(root);
				continue;
			}
			case 2 :
			{
				Prin(root);
				continue;
			}
			case 3 :
			{
				SearInput(&root);
				continue;
			}
			case 4:
			{
				Xuonghang(&root);
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
				Free(root);
				break;
			}
		}
		break;
	}
}
//================================================================================
void Read_file(Soccer **root)
{
	FILE *ptr;
	int count =1;
	char Name1[10],Name2[10];
	int point1,point2;
	int goal1,goal2;
	char filename[] = "Bongda.txt";
	if((ptr = fopen(filename ,"r")) == NULL)
	{
		printf("Can not file\n");
	}
	else
	{
		while(fscanf(ptr,"%s",Name1)==1)
		{
			point1 = point2 =0;
		fscanf(ptr,"%s%d%d",Name2,&goal1,&goal2);
		if(goal1 < goal2) point2 = point2 + 3;
		else if(goal1 > goal2) point1 = point1 + 3;
		else 
		{
			point1++;
			point2++;
		}
		if(InSear(root,Name1,point1) == 0)
		{
			InserNode(root,Name1,point1);
			count ++;
		}
		if(InSear(root,Name2,point2) == 0)
		{
			InserNode(root,Name2,point2);
			count ++;
			}
		}
	}
	fclose(ptr);
}
//==================================================================================
int InSear(Soccer **root,char *a,int b)
{
	if((*root) == NULL)
	{	
		return 0;
	}
	else
	{
	if(strcmp((*root) -> Name,a) > 0)
	{
		return (InSear(&(*root) -> left,a,b));
	}
	else if(strcmp((*root) -> Name,a) < 0)
	{
		return (InSear(&(*root) -> right,a,b));
	}
	else if(strcmp((*root) -> Name,a) == 0)
		{
			(*root) ->point = (*root) ->point + b;
			return (*root)->point;

		}
	}
}
//==================================================================================
Soccer * AddNode(char *a,int b)
{
	Soccer *Node;
	Node = (Soccer*)malloc(sizeof(Soccer));
	strcpy(Node -> Name,a);
	Node ->point = b;
	Node ->left = NULL;
	Node ->right = NULL;
	return Node;
}
//=========================================================================================
void InserNode(Soccer **Node,char *a,int b)
{
	if((*Node) == NULL)
	{
		(*Node) = AddNode(a,b);
	}
	else if(strcmp((*Node)->Name,a) < 0)
	{
		InserNode(&(*Node) -> right,a,b);
	}
	else if(strcmp((*Node)->Name,a) > 0)
	{
		InserNode(&(*Node) ->left,a,b);
	}
}

void Prin1()
{
	printf("%s\t%s\n","Name1","Point");
}
//========================================================================================
void Prin(Soccer *a)
{
	if(a != NULL)
	{
		printf("%s\t%d\n",a -> Name,a ->point);
		Prin(a ->left);
		Prin(a ->right);
	}
}
//===========================================================================================
void DeleteNode(Soccer **root,int a)
{
	if((*root) == NULL) return;
	else
	{
		DeleteNode(&(*root) -> right,a);
		DeleteNode(&(*root) -> left,a);
		if((*root) -> point == a)
		{
			printf("%s\n",(*root) ->Name);
			DeletePlay(root,(*root)->Name);
		}
	}
	Prin1();
	Prin((*root));
}
//=====================================================================================
void DeletePlay(Soccer **root,char *s)
{
	if((*root)==NULL) return;
	Soccer *tmp;
	if(strcmp((*root) -> Name,s) < 0) DeletePlay(&(*root)->right,s);
	else if(strcmp((*root) -> Name,s) > 0) DeletePlay(&(*root)->left,s);
	else
	{
		if((*root) -> right != NULL && (*root) -> left != NULL)
		{

			tmp = Right_Min(&(*root) ->right);
			strcpy((*root) -> Name,tmp ->Name);
			(*root) -> point = tmp -> point;
			DeletePlay(&(*root) ->right,(*root) -> Name);			
		}
		else
		{
			tmp = (*root);
			if((*root) -> left == NULL) (*root) = (*root)->right;
			else
			{
				(*root) = (*root) -> left;
			}
			free(tmp);
			}
		}
}
//===================================================================================
Soccer *Right_Min(Soccer **root)
{
	Soccer *a = (*root);	
	if((a) == NULL) return NULL;
	else 
	{
		if((a) -> left == NULL) return a;
		else
			return (Right_Min(&a->left));
	}
}
//====================================================================================
int True(char *s)
{
int i;	
	for(i = 0; i < strlen(s);i++)
	{
		if(i == ' ')
		{
				printf("Input wroong!...\n");
                printf("Please input again!\n");
                return 0;
		}
	}
		return 1;
}
//===================================================================================
void SearInput(Soccer **root)
{
	int c;
	char s[10];
	printf("Moi ban nhap doi bong muon tim \n");
	while(1)
	{
		fgets(s,10,stdin);
		s[strlen(s) - 1] = '\0';
		if(True(s) == 1)
		{
			break;
		}
	}
	if(InSear(root,s,0) != 0)
	{
		printf("%d\n", InSear(root,s,0));
	}
	else
		 printf("KHONG co doi bong tren\n");
}
//=======================================================================================
void Xuonghang(Soccer **root)
{
	int a;
	printf("Moi ban Point xuong hang \n");
	scanf("%d",&a);
	while(getchar() !='\n');
	DeleteNode(root,a);	
}
//==================================================================================
void Outputfile(Soccer ** root)
{
	FILE *ptr;
	char filename[] = "Ketqua.txt";
	if((ptr = fopen (filename , "w")) == NULL)
	{
		printf("Can not open file\n");
	}
	else
		Infile(ptr,root);
}
//===================================================================================
void Infile(FILE *ptr,Soccer **root)
{
	if((*root))
		{
			fprintf(ptr, "%s",(*root) -> Name);
			fprintf(ptr, "%s","\t");
			fprintf(ptr, "%d",(*root) -> point);			
			fprintf(ptr, "%s","\n");
			Infile(ptr,&(*root) -> right);
			Infile(ptr,&(*root) -> left);
		}	
}
//======================================================================================
void Free(Soccer *root)
{
	if(root)
	{
		Free(root -> left);
		Free(root -> right);
		free(root);
	}
}