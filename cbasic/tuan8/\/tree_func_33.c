#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"tree_lib_33.h"
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
