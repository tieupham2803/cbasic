#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct
{
  char name[20];
  char masanpham[20];
	// int x;
}data;
typedef data keytype;
typedef struct node
{
  keytype key;
  struct node *left,*right;
}node;
typedef struct node *treetype;
treetype Search(keytype key,treetype root)
{
	// printf("12312\n");
  if(root==NULL) return NULL;
  else if(strcmp(root->key.name,key.name)==0){
  	// printf("fuch you\n");
  	 return root;
  }
  	     
  else if(strcmp(root->key.name,key.name)<0)
      return Search(key,root->right);
    else
      {
	return Search(key,root->left);
      }
}


void InsertNode(keytype key,treetype *root)
{
	// printf("sadas\n");
if (*root == NULL){
  *root=(node*)malloc(sizeof(node)); 
  (*root)->key = key;
  (*root)->left = NULL; 
  (*root)->right = NULL; 
 }
 else if (strcmp(key.name,(*root)->key.name)<0) InsertNode(key, &(*root)->left);
 else if (strcmp(key.name,(*root)->key.name)>0) InsertNode(key, &(*root)->right); 
}

keytype DeleteMin(treetype *root)
{
  keytype k;
  if((*root)->left==NULL)
    {
      k=(*root)->key;
      (*root)=(*root)->right;
      return k;
    }
  else return DeleteMin(&(*root)->left);
}

void DeleteNode(keytype x,treetype *root)
{
  if(*root!=NULL)
    if(strcmp(x.name,(*root)->key.name)<0) DeleteNode(x,&(*root)->left);
    else if(strcmp(x.name,(*root)->key.name)>0)
      DeleteNode(x,&(*root)->right);
    else if
      (((*root)->left==NULL)&&((*root)->right==NULL))
      *root=NULL;
    else if((*root)->left==NULL)
      *root=(*root)->right;
    else if((*root)->right==NULL)
      *root=(*root)->left;
    else (*root)->key = DeleteMin(&(*root)->right); 
}
void freetree(treetype tree)
{
	if (tree!=NULL)
	{
		freetree(tree->left);
		freetree(tree->right);
		free((void*) tree);
	}
}
void printftree(treetype tree)
{
  if(tree!=NULL)
    {
      printftree(tree->left);
      printf("%-20s%s\n",tree->key.name,tree->key.masanpham);
      printftree(tree->right);
    }
}

int checkAcc(keytype x){
	if (strlen(x.masanpham)<6)
 			{
 				/* code */
 				return 0;
 			}
 			else return 1;

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
void Read_file(treetype *root)
{
	FILE *ptr;
	int count =1;
	char *Name1[30],*masanpham[30];
	char name[31], mssv[10],diem[10], Tempchar[30]; 
	char *TC;
          char vao[30],Nuon1[30];
          char *Nuon,temp[30],temp1[30];
	keytype s;
		// InsertNode(s2,&tree);
	// int point1,point2;
	// int goal1,goal2;
	char filename[] = "A.txt";
	if((ptr = fopen(filename ,"r")) == NULL)
	{
		printf("Can not file\n");
	}
	else
	{
	

         keytype s;
          int count=0;
          char name[31], phone[10],diem[10], Tempchar[30];
            char vao[30],Nuon1[30];
    char *Nuon,temp[30],temp1[30];

          while(fgets(Tempchar,40,ptr)){
          	Tempchar[strlen(Tempchar) - 1] = '\0';// loai bo ky tu xuong dong
          		printf("%s\n",Tempchar );
}
	}
	fclose(ptr);
}
// void Outputfile(treetype * root)
// {
// 	FILE *ptr;
// 	char filename[] = "pass.txt";
// 	if((ptr = fopen (filename , "w")) == NULL)
// 	{
// 		printf("Can not open file\n");
// 	}
// 	else
// 		Infile(ptr,root);
// }
// //===================================================================================
// void Infile(FILE *ptr,treetype *root)
// {
// 	if((*root))
// 		{
// 			fprintf(ptr, "%s",(*root) -> key.name);
// 			fprintf(ptr, "%s","\t");
// 			fprintf(ptr, "%s",(*root) -> key.masanpham);			
// 			fprintf(ptr, "%s","\n");
// 			Infile(ptr,&(*root) -> right);
// 			Infile(ptr,&(*root) -> left);
// 		}	
// }

void  main()
{
	
	treetype p, tree = NULL;
	int i, n = 0,k;
	int imenu ,imenu2;
	char newpass;
	
 		 keytype x;
 		 treetype tmp,tmp1,tmp2,tmp3;
 		 keytype s1;
 		
 	
 		             		
  while(1)
  {
    printf("\n-----------------MENU-----------------------\n");
    printf("1.Doc file A \n2. Doc file B \n3. Ban hang\n4. ghi thong tin\n5.thong ke \n6 Yeu cau dac biet\n ------->Please choose\n");
    scanf("%d",&k); while(getchar()!='\n');
    if(k==1)
    {
    Read_file(&tree);
    }
    else if(k==2)
    {
    }
    else if(k==3)
    {
    	 
      // Deletephone(s1);
      // PrintScreen(s1);
    }
    else if(k==4)
    {
  // PrintScreen(s1);
    }
    else if(k==5)
    {
      // printf("cam on ban da su dung chuong trinh\n");
     break;
    }
    else if(k==6)
    {
     // FILE *f=fopen("sinhvien.dat","wb");
     // WriteFile(s1,f);
     //  fclose(f);
    }
      else if(k==7)
    {
      // PrintScreen(s1);
      // ReadFile();
        
    }
    else break;
  }
}