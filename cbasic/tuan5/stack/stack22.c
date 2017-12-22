
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_ {
   char name[31];
  char mssv[10];
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
          char name[31], mssv[10],diem[10], Tempchar[30];
            char vao[30],Nuon1[30];
    char *Nuon,temp[30],temp1[30];
          float score;

          while(fgets(Tempchar,40,f)){
          	node=(Node *)malloc(sizeof(Node));
  // printf("%s\n",Tempchar );
  Nuon = catxau(Tempchar,Nuon1,'-');
  // printf("%s---%s\n",Nuon,Nuon1);
  strcpy(node->mssv,Nuon1);
  // printf("%s\n",sinhvien[i].mssv );
  Nuon = catxau(Nuon,Nuon1,'-');
    // printf("%s---%s\n",Nuon,Nuon1);
      strcpy(node->name,Nuon1);
      node->score = atoi(Nuon);
       addQueue(top, node);
      // printf("%f\n", sinhvien[i].score);

 // printf("%s-%s-%f\n",node->mssv,node->name,node->score );
}
          // while (fscanf(f, "%s-%s-%s\n", mssv, name,diem)==1)
          // {
          //      node=(Node *)malloc(sizeof(Node));

          //      strcpy(node->mssv, mssv);
          //       strcpy(node->name, name);
          //       node->score = atoi(diem);
          //       printf("%s-%s-%f\n",node->mssv,node->name,node->score );
          //       // addQueue(top,node);

          //      // fscanf(f, "%s", Mau);
          //      // node->mau=atoi(Mau);
          //      // if (!kt(node->mau)) return 0;

          //      // fscanf(f, "%s", Tancong);
          //      // node->tancong=atoi(Tancong);
          //      // if (!kt(node->tancong)) return 0;

          //      // fscanf(f, "%s", Nhanhnhen);
          //      // node->nhanhnhen=atoi(Nhanhnhen);
          //      // if (!kt(node->nhanhnhen)) return 0;

          //      // fscanf(f, "%s", Phongthu);
          //      // node->phongthu=atoi(Phongthu);
          //      // if (!kt(node->phongthu)) return 0;

          //      // node->diem=0;
          //      // addQueue(top, node);
          //      count++;
          // }
          return count;
     }
}
// /*----------------------------------------------------------------------------------*/
void Display(Node *top)
{
     Node *node;
 

     for (node=top; node!=NULL; node=node->next)
     printf("%s-%s-%f\n",  node->mssv,
            node->name, node->score);
}
// /*----------------------------------------------------------------------------------*/
// void addSort(Node **top, Node *newNode)
// {
//      if (isEmpty(*top))
//           addHead(top, newNode);
//      else
//      {
//           Node *sau,*truoc;

//           sau=(*top);
//           truoc=(*top);
//           if (newNode->diem>sau->diem)
//           {
//                newNode->next=(*top);
//                *top=newNode;
//           } else
//           {
//                while ( (sau!=NULL) && (sau->diem>=newNode->diem) )
//                {
//                     truoc=sau;
//                     sau=sau->next;
//                }
//                truoc->next=newNode;
//                newNode->next=sau;
//           }
//      }
// }
// /*----------------------------------------------------------------------------------*/

// /*----------------------------------------------------------------------------------*/
// void DisplaySort(Node *top)
// {
//      Node *node;
//      int i=1;

//      for (node=top; node!=NULL; node=node->next)
//      printf("%-3d%-10s%-10d\n", i++, node->biethieu, node->diem);
// }
// /*----------------------------------------------------------------------------------*/
// void free_all(Node **top)
// {
//      Node *node;
//      while (isEmpty(*top))
//           node=deQueue(top);
//      free(node);
// }
/*----------------------------------------------------------------------------------*/

int main()
{
     int menu;
     Node *Temp;
     Node *queue1=NULL;
     Node *XepHang=NULL;
     int count1, count2;


               	count1 = getData(&queue1,"sinhvien.dat");
               	Display(queue1);
               	printf(" bat dau lay du lieu ra khoi stack\n");
               	 // if ( !isEmpty(*queue1) )
               	 // {
               	 // 	/* code */
               	 // Temp=deQueue(queue1);
               	 // Display(Temp);
               	 // }
               	FILE *f=fopen("sinhvien2.dat","wb");
             			// fprintf(f, "%-11s%-4d\n",root->name,root->score);

               	    	Node *node;
               	  while(isEmpty(queue1==NULL)){
      //          	  	Node *node;
				  // node=deQueue(&queue1);
				  // fprintf(f,"%s-%s-%f\n",node->mssv,node->name,node->score);
      //             printf("%s-%s-%f\n",node->name,node->mssv,node->score );
      //             free(node);
               	  	
				  node=deQueue(&queue1);
				  printf("%s\n",node->mssv );
				  fprintf(f,"%s-%s-%f\n",node->mssv,node->name,node->score);
				  free(node);
                  }
               	 
               		
       
     return 0;
}
