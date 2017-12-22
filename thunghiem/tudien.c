#include"BSTc.h"
void nap(FILE *f,treetype *tree)
{
  char c,i=0,dem=0;
  char tmp[20];
  keytype x;
  if((f=fopen("tudien.txt","r"))==NULL)
    {
      printf("Khong the mo file tudien.txt.\n");
      exit(1);
    }
  while(!feof(f))
    {
      fscanf(f,"%s",x.eng);
      c=fgetc(f);
      while((c=fgetc(f))!='\n'&&c!=EOF)
	{x.vn[i]=c;i++;}
      x.vn[i]='\0';
      i=0;
      InsertNode(x,tree);
      dem++;
    }
  printf("Nap thanh cong %d tu.\n",dem);
  int dem1 = Leaf(&tree);
  printf("So node la: %d",dem1);
  fclose(f);
}
void dich(treetype tree)
{
  char s[81];
  char c;
  int i,j=0,dem=0;
  treetype tmp;
  keytype s1;
  printf("Nhap 1 cau tieng anh.\n");
  while(getchar()!='\n');
  gets(s);
  for(i=0;i<strlen(s);i++)
    {
      if(isupper(s[i])) s[i]=tolower(s[i]);
    }
  for(i=0;i<strlen(s);i++)
    {
      s1.eng[j]=s[i];
      j++;
      if(s[i]==' '||(i==strlen(s)-1)) 
	{if(s[i]==' ') s1.eng[j-1]='\0';else s1.eng[j]='\0';j=0;
	  tmp=Search(s1,tree);
	  if(tmp==NULL)
	  {printf("Thieu tu %s\n",s1.eng);
	    printf("Ban co muon bo sung tu %s khong(y or n)?.\n",s1.eng);
	    do{scanf("%c",&c);
	      while(getchar()!='\n');
	      if(c=='y') {printf("%s: ",s1.eng);gets(s1.vn);InsertNode(s1,&tree);break;}
	      if(c=='n') break;
	      if(c!='y'&&c!='n') printf("Nhap sai, nhap lai: ");}while(c!='y'||c!='n');dem++;  
	  }
	}
    }
  if(dem==0){
    for(i=0;i<strlen(s);i++)
      {
	s1.eng[j]=s[i];
	j++;
	if(s[i]==' '||(i==strlen(s)-1)) 
	{if(s[i]==' ') s1.eng[j-1]='\0';else s1.eng[j]='\0';j=0;
	  tmp=Search(s1,tree);
	  if(tmp!=NULL) printf("%s ",tmp->key.vn);
	}
      }
  }
  printf("\n");
}
void update(treetype tree,FILE *f)
{
  if(tree!=NULL)
    {
      update(tree->left,f);
      update(tree->right,f);
      fprintf(f,"%s%c%s\n",tree->key.eng,'	',tree->key.vn);
    }
}


void menu()
{
  printf("1-Doc du lieu tu file.\n");
  printf("2-Tu dien.\n");
  printf("3-Dich.\n");
  printf("4-Update vao file.\n");
  printf("5-Thoat.\n");
}
int main()
{
  treetype tree=NULL;
  FILE *f;
  int chon;
  menu();
do
  {
    printf("Chon: ");
    scanf("%d",&chon);
    switch(chon)
      {
      case 1:nap(f,&tree);break;
      case 2:printftree(tree);break;
      case 3:dich(tree);break;
      case 4:f=fopen("tudien.txt","w");update(tree,f);close(f);printf("Update thanh cong.\n");break;
      case 5:break;
      }
  }while(chon!=5||(getchar()!='\n'));
  freetree(tree);
  return 0;
}
