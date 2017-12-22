#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// #include"tree_lib_33.h"
struct char_array{
  char str[MAX];
};
typedef struct char_array mang;
void make_null(tree *Root){
  *Root=NULL;
}
void insert_tree(tree *Root,data y){
  if (*Root == NULL){
     tree new = (tree) malloc(sizeof(bi_tree));
     strcpy(new->x.eng,y.eng);
     strcpy(new->x.viet,y.viet);
     (*Root)=new;
  } 
  else if (strcmp(y.eng,(*Root)->x.eng)<0) insert_tree(&(*Root)->left,y);
  else if (strcmp(y.eng,(*Root)->x.eng)>0) insert_tree(&(*Root)->right,y);
  else if (strcmp(y.eng,(*Root)->x.eng)==0){
    //printf("Da ton tai nguoi dung\n");
  }
}
tree search_tree(tree Root,char y[]){
  if (Root == NULL) return NULL; // not found
  else if (strcmp(y,Root->x.eng)==0) /* found y */ 
    return Root;
  else if (strcmp(y,Root->x.eng)<0)
    //continue searching in the right sub tree  
    return search_tree(Root->left,y); 
  else 
  // continue searching in the left sub tree 
    return search_tree(Root->right,y); 
}
void delete_min(tree *Root){
  // data k; 
  if ((*Root)->left == NULL){ 
    //strcpy(k.user,(*Root)->x.user);
    //strcpy(k.pass,(*Root)->x.pass);
    (*Root) = (*Root)->right; 
    // return k; 
  } 
  else return delete_min(&(*Root)->left);
}
void delete_node(tree *Root,char y[]){
  if (*Root!=NULL) 
    if (strcmp(y,(*Root)->x.eng)<0) delete_node(&(*Root)->left,y) ;
    else if (strcmp(y,(*Root)->x.eng)>0) delete_node(&(*Root)->right,y) ;
    else if 
      ((*Root)->left==NULL&&(*Root)->right==NULL) *Root=NULL; 
    else if ((*Root)->left == NULL)
      *Root = (*Root)->right; 
    else if ((*Root)->right==NULL) 
      *Root = (*Root)->left; 
    else delete_min(&(*Root)->right); 
}
void display_tree(tree Root){
  if(Root==NULL) return;
  display_tree(Root->left);
  printf("%s\t%s\n",Root->x.eng,Root->x.viet);
  display_tree(Root->right);
}

void read_file_to_tree(tree *Root,FILE *fptr){
  data temp;
  char c;
  while(!feof(fptr)){
    fscanf(fptr,"%s",temp.eng);
    c=fgetc(fptr);
    fgets(temp.viet,MAX,fptr);
    int i = strlen(temp.viet)-1;
    if ((i > 0) && (temp.viet[i] == '\n'))
      temp.viet[i] = '\0';
    //printf("%s %s",temp.eng,temp.viet);
    insert_tree(Root,temp);
  }
}
void insert_file(data y){
  FILE *fptr;
  char file[]="data.txt";
  if((fptr=fopen(file,"a"))==NULL){
    printf("Cannot open file %s\n",file);
    return;
  }
  fprintf(fptr,"%s\t%s\n",y.eng,y.viet);
  fclose(fptr);
}
void insert_data(tree *Root,char s[]){
  data y;
  strcpy(y.eng,s);
  printf("\nNhap vao nghia cua %s:",y.eng);
  gets(y.viet);
  insert_tree(Root,y);
  insert_file(y);
}
void dich_cau(tree *Root,mang s[],int i){
  int j=0;
  tree temp;
  for(j=0;j<i;j++){
    make_null(&temp);
    temp=search_tree(*Root,s[j].str);
    if(temp==NULL) insert_data(Root,s[j].str);
    else printf("%s ",temp->x.viet);
  }
}
int main(){
  FILE *fptr;
  tree Root;
  char file[]="data.txt";
  make_null(&Root);
  int a;
  do{
    printf("Option:\n1.Doc tu file data.txt vao trong cay nhi phan\n2.Hien thi toan bo du lieu\n3.Dich\n4.Thoat\nBan muon lam gi:");
    scanf("%d%*c",&a);
    switch(a){
    case 1:{
      if((fptr=fopen(file,"r"))==NULL){
	printf("Can't open %s\n",file);
	return 1;
      }
      read_file_to_tree(&Root,fptr);
      fclose(fptr);
    }
      break;
    case 2:{
      display_tree(Root);
    }
      break;
    case 3:{
      mang s[MAX];
      char tmp[MAX];
      char c;
      int i=0,j=0,end;
      printf("Nhap vao cau ma ban muon dich:");
      end=scanf("%s",tmp);
      /*DOc tung tu trong mot cau*/
      while(1){
	if(tmp[0]!=' '){
	  strcpy(s[i].str,tmp);
	  // printf("%s-%s-%d-%d\n",s[i].str,tmp,end,i);
	  //strlwr(s[i].str);
	  i++;
	}
	c=getchar();
	//printf("%c\n",tmp[strlen(tmp)-1]);
	if(c=='\0'||c=='\n') break;
	end=scanf("%s",tmp);
      }
      printf("i=%d\n",i);
      for(j=0;j<i;j++){
	printf("%s ",s[j].str);
      }
      printf("\t");
      dich_cau(&Root,s,i);
      printf("\n");
    }
      break;
    }
  }
  while(a!=4);
  
  return 0;
}
