#include<stdio.h>
#include<stdlib.h>
#define max 30
typedef struct tx {int a; char x[max];} tx;
typedef struct node {tx d; struct node *l,*r;} node;
typedef struct node *tree;
void kt(tree *t) {(*t)==NULL;}
void them(tree *t,char s[])
{
  if((*t)==NULL)
  {
    *t=(node *)malloc(sizeof(node));
    (*t)->d.a=1;
    strcpy((*t)->d.x,s);
    (*t)->l=NULL; (*t)->r=NULL;
  }
  else
  {
    if(strcmp((*t)->d.x,s)==0) (*t)->d.a=(*t)->d.a+1;
    if(strcmp((*t)->d.x,s)==1) them(&((*t)->l),s);
    if(strcmp((*t)->d.x,s)==-1) them(&((*t)->r),s);
  }
}
void in(tree t)
{
  if(t!=NULL)
  {
    in(t->l);
    printf("%30s%4d",t->d.x,t->d.a);
    in(t->r);
  }
}
int main(int argc,char* argv[])
{
  int i,j,c=-1; char s[max],k[12]; FILE *f;
  tree t;
  kt(&t);
  while(c!=0)
  {
    printf("chon 1 in du lieu ra man hinh\n");
    printf("chon 2 tim tan xuan xuat hien cua mot tu\n");
    printf("chon 3 in bang thong ke\n");
    printf("*chon 0 de ket thu chuong trinh\n");
    scanf("%d",&c);
    if(c==1)
    {
      if((f=fopen(argv[1],"r"))==NULL)
        {printf("khong mo duoc file\n"); return;}
      else
        {while(fgets(s,30,f)!=NULL) printf("%s",s);}
      fclose(f);
    }
    if(c==2)
    {
      if((f=fopen(argv[1],"r"))==NULL)
        {printf("khong mo duoc file\n"); return 0;}
      else
      {
        j=0;
        printf("nhap tu muon tim kiem tan xuat\n"); scanf("%s",k);
        while(fscanf(f,"%s",s)==1)
          {if(strcmp(s,k)==0) j++; fgetc(f); them(&t,s);}
        if(j!=0) printf("tu %s xuat hien %d\n\n",k,j);
        else printf("tu %s khong xuat hien trong file\n\n",k);
      }
      fclose(f);
    }
    if(c==3) {in(t); printf("\n");}
  }
  return 0;
}
