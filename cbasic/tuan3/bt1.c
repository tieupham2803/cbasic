#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data
{
	char sodienthoai[20];
	char ten[30];
	/* data */
}  
typedef struct  danhba
{
   struct data dulieu;
   struct danhba *next;
}node;
node *root,*last;

void insertLast( char ten[30],char sodienthoai[20])
{
   //tao mot link
	node *newnode;

   newnode = (node*) malloc(sizeof(node));
	
 
   strcpy(newnode->dulieu.sodienthoai,sodienthoai);
   strcpy(newnode->dulieu.ten,ten);
   //cur = root
   if (root==NULL)
   {
   	root=newnode;
   	/* code */
   }
   else{
   	last->next = newnode;
   }
   last = newnode;
}


//hien thi danh sach
void printList()
{
   node *ptr = root;
   printf("\n[ ");
	
   //bat dau tu phan dau danh sach
   while(ptr != NULL)
	{        
      printf("(%s,%s)  ",ptr->dulieu.ten,ptr->dulieu.sodienthoai);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

void insertFirst(int data, char s)
{
   //tao mot link
   struct node *link = (struct node*) malloc(sizeof(struct node));
	
 
   link->data = data;
   strcpy(link->name,s)
	
   //tro link nay toi first node cu
   link->next = head;
	
   //tro first toi first node moi
   head = link;
}

main() {

    char t[30],d[20];
  
    printf("\n->Nhap vao ten: ");
    scanf("%s",&t);
  
    printf("\n->Nhap vao sdt: ");
   scanf("%s",&d);
  insertLast(t,d)

   printf("Danh sach lien ket: "); 
	
   //in danh sach
   printList();
   }