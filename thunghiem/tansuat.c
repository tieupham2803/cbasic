#include"tansuat.h"
void chuanhoa(char s[])
{
  char tmp[81];
  int i;
  for(i=0;i<strlen(s);i++)
    {
      if(isupper(s[i])) s[i]=tolower(s[i]);
      if(s[i]<'a'||s[i]>'z') {s[i]='\0'; break;}
    }
}
treetype dem(FILE *f,char name[],treetype root)
{
  elementtype el;
  if((f=fopen(name,"r"))==NULL)
    {printf("Khong the mo file %s.\n",name);
      exit(1);}
  while(!feof(f))
    {
      fscanf(f,"%s",el.name);el.dem=1;
      chuanhoa(el.name);
      if(strcmp(el.name,"")!=0) InsertNode(el,&root);
    }
  fclose(f);
  return root ;
}
void update(FILE *f,treetype tree)
{
  if(tree!=NULL)
    {
      update(f,tree->left);
      update(f,tree->right);
      fprintf(f,"%-20s %d\n",tree->element.name,tree->element.dem);
    }
}

int main()
{
  FILE *f,*f1;
  char name[81];
  treetype root=NULL;
  printf("Nhap ten file: ");
  scanf("%s",name);
  root=dem(f,name,root);
  printftree(root);
  if((f1=fopen("ketqua.txt","w"))==NULL)
    {
      printf("Loi mo file.\n");
      exit(1);
    }
  update(f1,root);
  freetree(root);
  return 0;
}
