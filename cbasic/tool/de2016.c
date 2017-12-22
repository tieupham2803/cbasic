
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_ {
   char name[31];
  char phone[10];
  float score;
     struct Node_ *next;
} Node;
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
/*----------------------------------------------------------------------------------*/
int isEmpty(Node *top)
{
     return (top==NULL);
}
/*----------------------------------------------------------------------------------*/
Node *deQueue(Node **top)
{
     Node *node;
     node=(*top);
     (*top)=(*top)->next;
     return node;
}
/*----------------------------------------------------------------------------------*/
void addHead(Node **top, Node *newNode)
{
     newNode->next=(*top);
     (*top)=newNode;
}
/*----------------------------------------------------------------------------------*/
void addQueue(Node **top, Node *newNode)
{
     Node *node;
     if ((*top)==NULL)
          addHead(top, newNode);
     else
     {
          for (node=(*top); node->next!=NULL; node=node->next);
          node->next=newNode;
     }
}
/*----------------------------------------------------------------------------------*/
// int kt(int a)
// {
//      if (a<=0)
//      {
//           printf("File du lieu khong hop le!\n");
//           return 0;
//      }
//      return 1;
// }
// /*----------------------------------------------------------------------------------*/
int getData(Node **top, char filename[])
{
     FILE *f;
     if ( (f=fopen(filename, "rb"))==NULL )
     {
          printf("FILE NOT FOUND!\n");
          return 0;
     }
     else
     {
          Node *node;
          int count=0;
          char name[31], phone[10],diem[10], Tempchar[30];
            char vao[30],Nuon1[30];
    char *Nuon,temp[30],temp1[30];
          float score;

          while(fgets(Tempchar,40,f)){
          	Tempchar[strlen(Tempchar) - 1] = '\0';// loai bo ky tu xuong dong
          	          	// printf("111%s",Tempchar );

          	node=(Node *)malloc(sizeof(Node));
  // printf("%s\n",Tempchar );
  Nuon = catxau(Tempchar,Nuon1,'\t');
  // pr\n");
  // printf("nuon %s---nuon1%s\n",Nuon,Nuon1);
  strcpy(node->phone,Nuon);
  // printf("%s\n",sinhvien[i].phone );
  // Nuon[strlen(Nuon) - 1] = '\0';

 // printf("nuon %s---nuon1%s\n",Nuon,Nuon1);
      strcpy(node->name,Nuon1);
      // node->score = atoi(Nuon);
       addQueue(top, node);
      // printf("%f\n", sinhvien[i].score);

 // printf("%s-%s-%f\n",node->phone,node->name,node->score );
}
         
          return count;
     }
}

// /*----------------------------------------------------------------------------------*/
void Display(Node *top)
{
     Node *node;
 

     for (node=top; node!=NULL; node=node->next)
     printf("%s\t%s\n",  node->name,       node->phone);
 // printf("xon1g\n");
}
// /*----------------------------------------------------------------------------------*/
int KiemTra(char *s)
{
	int i;
 // int co=0;
 for(i=0;i<strlen(s);i++)
    {
      
       if(s[i]==' ') return 1;
       
       
    }
 return 0;  
}
int KiemTraKyTuSo(char *s)
{
	int i,j	;
 int co=0;
 for( i=0;i<strlen(s);i++)
    {
       for(j=48;j<=57;j++)
       {
       if(s[i]==j) co=1;
       
       }
    }
 return co;  
}
void Nhap(Node **top){
	int chot;
	char  name[20],phone[15];
	// char name[20] = "asdasdasd";
	// char phone[20] = "12312312312";
		  Node *node1;
	  node1=(Node *)malloc(sizeof(Node));
      
    	while(1){
    	printf("Nhap vao ten khach hang khong co dau cach\n");
    	gets(name);
    	chot = KiemTra(name);
    	if (chot==0)
    	break;
    	else printf("ten khach hang khong duoc chua dau cach vui long nhap lai\n");
    	}
    	printf("Nhap vao so dien thoai\n");
    scanf("%s",phone); while(getchar()!='\n');
    // printf("1111111111\n");
           strcpy(node1->phone,phone);
                 // printf("2222222222222\n");
      strcpy(node1->name,name);


       // printf("33333333333\n");
       addQueue(top, node1);
       // Display(queue1);
}
int main()
{
     int menu,k,chot;
     Node *Temp;
     Node *queue1=NULL;
     char name[30],phone[15];
   
     int count1, count2;


               	// count1 = getData(&queue1,"danhsach.txt");
               	// Display(queue1);
      //          	printf(" bat dau lay du lieu ra khoi stack\n");
      //          	 // if ( !isEmpty(*queue1) )
      //          	 // {
      //          	 // 	/* code */
      //          	 // Temp=deQueue(queue1);
      //          	 // Display(Temp);
      //          	 // }
      //          	FILE *f=fopen("sinhvien2.dat","w+");
      //        			// fprintf(f, "%-11s%-4d\n",root->name,root->score);

      //          	    	Node *node;
      //          	  while(isEmpty(queue1==NULL)){
      // //          	  	Node *node;
				  // // node=deQueue(&queue1);
				  // // fprintf(f,"%s-%s-%f\n",node->phone,node->name,node->score);
      // //             printf("%s-%s-%f\n",node->name,node->phone,node->score );
      // //             free(node);
               	  	
				  // node=deQueue(&queue1);
				  // printf("%s\n",node->phone );
				  // fprintf(f,"%s-%s-%f\n",node->phone,node->name,node->score);
				  // free(node);
      //             }
               	 
               		
  while(1)
  {
    printf("\n-----------------MENU-----------------------\n");
    printf("1.Doc file \n2. Them nguoi mua vao hang doi \n3. Ban hang\n4. ghi thong tin\n5.thong ke \n6 Yeu cau dac biet\n ------->Please choose\n");
    scanf("%d",&k); while(getchar()!='\n');
    if(k==1)
    {
      // Makelist(s1);
      // PrintScreen(s1);

               	count1 = getData(&queue1,"danhsach.txt");
               	Display(queue1);
    }
    else if(k==2)
    {
    	Nhap(&queue1);
	Display(queue1);
    		//   	Node *node;
				  // node=deQueue(&queue1);
    	// printf("xong chuc nang2\n");
    }
    else if(k==3)
    {
    	  	Node *node;

				  node=deQueue(&queue1);

				      	  	                  printf("%s-%s-\n",node->name,node->phone);
				      	  	                   printf("12312\n");


  Display(queue1);
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
       
     return 0;
}
