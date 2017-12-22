#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct
{
  char name[20];
  char password[20];
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
      printf("%-20s%s\n",tree->key.name,tree->key.password);
      printftree(tree->right);
    }
}

int checkAcc(keytype x){
	if (strlen(x.password)<6)
 			{
 				/* code */
 				return 0;
 			}
 			else return 1;

}
// int CountNodes(treetype *tree)
// {
// if(tree == NULL)
// return 0;
// else
// 	printf("asdas\n");
// return CountNodes((*tree)->left) + CountNodes((*tree)->right) + 1;
// }
// void createFile()
// {
//     node *current;
//     current = root;
//     FILE *fptr;
//     if((fptr = fopen("pass.txt", "wb")) == NULL)
//     {
//         printf("Can not create a new file!\n");
//         return;
//     }
//     else
//     {
//         fwrite(&linked_list_no_elements, sizeof(int), 1, fptr);
//         while(current != NULL)
//         {
//             fwrite(&(current->data), sizeof(current->data), 1, fptr);
//             current = current->next;
//         }
//         printf("Successfully created pass.txt!\n");
//     }
//     fclose(fptr);
// }
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
	char *Name1[30],*password[30];
	char name[31], mssv[10],diem[10], Tempchar[30]; 
          char vao[30],Nuon1[30];
          char *Nuon,temp[30],temp1[30];
	keytype s;
		// InsertNode(s2,&tree);
	// int point1,point2;
	// int goal1,goal2;
	char filename[] = "pass.txt";
	if((ptr = fopen(filename ,"r")) == NULL)
	{
		printf("Can not file\n");
	}
	else
	{
		// printf("ajskdjs\n");
		while((fscanf(ptr,"%s\t%s\n",Tempchar,Nuon1))==2)
		{
			// printf("%s\t%s\n",Tempchar,Nuon1);
			strcpy(s.name,Tempchar);
			strcpy(s.password,Nuon1);
			// printf("%s-%s\n", s.name,s.password);
			 InsertNode(s,root);
			// InsertNode()
		}
		//   //  while(1)
  //   // {
  //   	printf("aaa\n");
  //       // if((fscanf(ptr,"%s\t%s\n",&Tempchar,&Nuon1) )==0 ) break;
  //       // fscanf(ptr,"%s\t%s\n",&Tempchar,&Nuon1) ;
  //       printf("%d\n", fscanf(ptr,"%s\t%s\n",&Tempchar,&Nuon1) );

  //       printf("bb\n");
  //      printf("%s\n",Tempchar );
  //       // fscanf(ptr,"%s\t%s\n",&Tempchar,&Nuon1) ;
  // printf("%d\n", fscanf(ptr,"%s\t%s\n",&Tempchar,&Nuon1) );
  //       printf("bb\n");
  //      printf("%s\n",Tempchar );
  //       // fscanf(ptr,"%s\t%s\n",&Tempchar,&Nuon1) ;
  // printf("%d\n", fscanf(ptr,"%s\t%s\n",&Tempchar,&Nuon1) );
  //       printf("bb\n");
  //      printf("%s\n",Tempchar );
  //   // }

	// 	 while(fgets(Tempchar,40,ptr)){
 //        	// node=(Node *)malloc(sizeof(Node));
 //  printf("%s",Tempchar );
 //          Nuon = catxau(Tempchar,Nuon1,'\t');
 //          printf("%s=%s",Nuon1 ,Nuon );

 //  // printf("%s---%s\n",Nuon,Nuon1);
 //           // strcpy(node->mssv,Nuon1);
 //  // printf("%s\n",sinhvien[i].mssv );
 //           // Nuon = catxau(Nuon,Nuon1,'-');
 //    // printf("%s---%s\n",Nuon,Nuon1);
 //          // strcpy(node->name,Nuon1);
 //          // node->score = atoi(Nuon);
 //          // push(top, node);
 //      // printf("%f\n", sinhvien[i].score);

 // // printf("%s-%s-%f\n",node->mssv,node->name,node->score );
 //          }
	}
	fclose(ptr);
}
void Outputfile(treetype * root)
{
	FILE *ptr;
	char filename[] = "pass.txt";
	if((ptr = fopen (filename , "w")) == NULL)
	{
		printf("Can not open file\n");
	}
	else
		Infile(ptr,root);
}
//===================================================================================
void Infile(FILE *ptr,treetype *root)
{
	if((*root))
		{
			fprintf(ptr, "%s",(*root) -> key.name);
			fprintf(ptr, "%s","\t");
			fprintf(ptr, "%s",(*root) -> key.password);			
			fprintf(ptr, "%s","\n");
			Infile(ptr,&(*root) -> right);
			Infile(ptr,&(*root) -> left);
		}	
}

void  main()
{
	
	treetype p, tree = NULL;
	int i, n = 0,k=0;
	int imenu ,imenu2;
	char newpass;
	 char Chuoi[]="admin" ;
 		 keytype x;
 		 treetype tmp,tmp1,tmp2,tmp3;
 		 keytype s1;
 		//  for (i=0; i < 4; ++i)
 		//  {
 		//  	/* code */
 		//  while(1){
 		// printf("nhap vao tai khoan, password\n");
 		// scanf("%s",x.name);
 		// scanf("%s",x.password);
 		// if(checkAcc(x)==0){
 		// 	printf("Thong tin nhap vao khong phu hop voi yeu cau\n"); continue;
 		// }
 		// printf("%s---%s\n",x.name,x.password );
 		// InsertNode(x,&tree);
 		// break;
 		// }
 		// }
 		 Read_file(&tree);
 		 // printftree(tree);

 		// printf("nhap vao tai khoan, password\n");
 		// scanf("%s",x.name);
 		// scanf("%s",x.password);
 		// printf("%s---%s\n",x.name,x.password );
 		// InsertNode(x,&tree);
 		 // printf("aaaa\n");
 		 // i = CountNodes(&tree);
 		 // printf("bbbb\n");
 		 // printf("%d\n",i );
 		
 		while(k<3){

 		printf("Phien Dang Nhap, Hay nhap vao Tai khoan va mat khau\n");
 		printf("taikhoan:\n");
 		scanf("%s",s1.name);
 		printf("matkhau:\n");
 		scanf("%s",s1.password);
 		printf("%s---%s\n",s1.name,s1.password );
 		// printftree(tree);

 		tmp =Search(s1,tree);
 		if (tmp==NULL)
 		{
 			/* code */
 			printf("Tk hoac mk ko chinh xac\n");
 			
 			k=k+1;

 			printf("K+1 la %d\n",k );
 			
 			continue;
 		}
 		printf("sida\n");
 		if((strcmp(s1.name,Chuoi)==0)&&(strcmp(tmp->key.password,s1.password)==0)){
 			// tmp =Search(s1,tree);
 			// if (strcmp(tmp->key.password,s1.password)==0)
 			// {
 			// 	/* code */
 			// 	printf("Xin chao admin\n");
 			// }
 			printf("Xin chao admin\n");
 			while(1){
					 		printf("De them thanh vien moi chon 1:\n De doi mat khau cho thanh vien nhap 2:\n De In danh sach nguoi dung nhap 3\n De thoat nhap 4\n");
					 		scanf("%d",&imenu2);
							while(getchar() != '\n');
							switch(imenu2)
							{
								case 1:{
										 while(1){
										 		printf("nhap vao tai khoan, password\n");
										 		scanf("%s",x.name);
										 		scanf("%s",x.password);
										 		if(checkAcc(x)==0){
										 			printf("Thong tin nhap vao khong phu hop voi yeu cau\n"); continue;
										 		}
										 		printf("%s---%s\n",x.name,x.password );
										 		InsertNode(x,&tree);
										 		break;
										 		}
										 		continue;

								}
								case 2 :
								{	
									keytype s2;
										printf("Nhap vao ten tai khoan\n");
									scanf("%s",s2.name);
									printf("Nhap vao password moi\n");
									scanf("%s",s2.password);
									tmp3 =Search(s2,tree);
									if(tmp3 == NULL){
										printf("Tai khoan nay khong ton tai\n");
									}
									else{
									printf("1\n");
									DeleteNode(s2,&tree);
									// printftree(tree);
									printf("2\n");
									// strcpy(s2.password,newpass);
									// strcpy(s2.name,s1.name);
									printf("3\n");
									InsertNode(s2,&tree);
								    printftree(tree);
									printf("4\n");
									tmp3 =Search(s2,tree);
									printf("5\n");
									printf("%s\n",tmp3->key.password );
									
								} 
								continue;
								}
									case 3 :
								{
									printftree(tree);
									// break;
										continue;

									}
									case 4:{
										break;
									}

					 		}
					 		break;

 			}

 		}
 		else{
 			tmp1 =Search(s1,tree);
 			if ((strcmp(tmp1->key.name,s1.name)==0)&&strcmp(tmp1->key.password,s1.password)==0)
 			{
 				/* code */
 				printf("Dang nhap thanh cong !\n");
 				printf("Xin chao ban %s\n",tmp1->key.name );

 				while(1){
					 		printf("De doi mk vui long chon 1:\n De thoat chon 2:\n");
					 		scanf("%d",&imenu2);
							while(getchar() != '\n');
							switch(imenu2)
							{
								case 1 :
								{	
									keytype s2;
									printf("Nhap vao password moi\n");
									scanf("%s",s2.password);
									printf("1\n");
									DeleteNode(s1,&tree);
									// printftree(tree);
									printf("2\n");
									// strcpy(s2.password,newpass);
									strcpy(s2.name,s1.name);
									printf("3\n");
									InsertNode(s2,&tree);
								    printftree(tree);
									printf("4\n");
									tmp3 =Search(s2,tree);
									printf("5\n");
									printf("%s\n",tmp3->key.password );
									continue;
								}
									case 2 :
								{
									break;

									}

					 		}
					 		break;

 			}
 		}
 			else{
 				printf("Dang nhap that bai\nVui long nhap lai  tai khoan\n");
 				 			k=k+1;
 				 			printf("k khi nay la %d\n",k );
 				 			continue;

 			}
 		}
 	

Outputfile(&tree);

}//ket thuc dem so lan dang nhap while(k<3)
 		
}