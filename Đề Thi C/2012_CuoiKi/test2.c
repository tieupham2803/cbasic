#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//----------------------------------------------------------------------------------
typedef struct T
{
  char email[30];
  char tel[30];
  char name[30];
  
  struct T *left;
  struct T *right;  
} Tree; 
Tree *Insert(Tree *root,Tree *Node)
{
  if(root==NULL) root=Node;
  else 
  {
    if(strcmp(root->email,Node->email)<0) root->right=Insert(root->right,Node);
    else if(strcmp(root->email,Node->email)>0) root->left=Insert(root->left,Node);
    // else if(strcmp(root->email,Node->email)==0) root->score+=Node->score;
  }
  return root;
}
Tree *ReadFileMakeTree(Tree *root)
{
  FILE *f=fopen("dulieu.txt","r");
  Tree *Node1,*Node2;
  char TempChar[11],Temp[30],Temp1[30],Temp2[30];
  int count=1;
  int Diem1,Diem2;
  Node1=(Tree *)malloc(sizeof(Tree));
   scanf("%s",Temp); while(getchar()!='\n');
   strcpy(Node1->email,Temp);
      scanf("%s",Temp1); while(getchar()!='\n');
   strcpy(Node1->name,Temp1);
     scanf("%s",Temp2); while(getchar()!='\n');
   strcpy(Node1->tel,Temp2);
    root=Insert(root,Node1);
  // while(fscanf(f,"%s",&TempChar)==1)
  // {
  //   Node1=(Tree *)malloc(sizeof(Tree));
  //   Node2=(Tree *)malloc(sizeof(Tree));
  //   Node1->score=Node2->score=0;
  //   strcpy(Node1->email,TempChar);
  //   fscanf(f,"%s",&Node2->email);
  //   fscanf(f,"%d",&Diem1); fgetc(f);
  //   fscanf(f,"%d",&Diem2); fgetc(f);
  //   if(Diem1==Diem2)
  //   {
  //     Node1->score++;
  //     Node2->score++;
  //   }
  //   else if(Diem1 < Diem2) Node2->score+=3;
  //   else if(Diem2 < Diem1) Node1->score+=3;
   
  //   // root=Insert(root,Node2);
  // }
  
  fclose(f);
  return root;
}
void PrintInorder(Tree *root)
{
  if(root!=NULL)
  {
    PrintInorder(root->left);
    printf("%-10s%-4s\n",root->email,root->name);
    PrintInorder(root->right);
  }
}
Tree *Search(Tree *root,char s[11])
{
  if(root!=NULL)
  {
    if(strcmp(root->email,s)<0) root=Search(root->right,s);
    else if(strcmp(root->email,s)>0) root=Search(root->left,s); 
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

// Tree *Delete(Tree *root,char n[11])
// {
//   Tree *Temp;
//   if(root==NULL) printf("Not found\n");
//   else if(strcmp(root->email,n)<0) root->right=Delete(root->right,n);
//   else if(strcmp(root->email,n)>0) root->left=Delete(root->left,n);
//   else
//     {
//       if(root->left!=NULL && root->right!=NULL)
//       {
//         Temp=FindMin(root->right);
//         root->score=Temp->score;
//         strcmp(root->email,Temp->email);
//         root->right=Delete(root->right,root->email);
//       }
//       else 
//       {
//         Temp=root;
//         if(root->left==NULL) root=root->right;
//         else if(root->right==NULL) root=root->left;
//         free(Temp);
//       }
//     }
//   return root;
// }
// Tree *DeleteNode(Tree *root,int n)
// {
//   if(root!=NULL)
//   {

//     root->left=DeleteNode(root->left,n);
//     root->right=DeleteNode(root->right,n);
//     if(root->score < n)
//     {
//       printf("%-11s%-4d\n",root->email,root->score);
//       root=Delete(root,root->email);
//     }     
//   }
//   return root;
// }
// void WriteFile(Tree *root,FILE *f)
// {
//   if(root!=NULL)
//   {
//     WriteFile(root->left,f);
//     fprintf(f, "%-11s%-4d\n",root->email,root->score);
//     WriteFile(root->right,f);
//   }
// }
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

    }
    else if(k==4)
    {
    }
    else if(k==5)
    {

    }
    else break;
  }
}
