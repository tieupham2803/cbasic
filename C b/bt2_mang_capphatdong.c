/** bài toán yêu cầu nhập vào tên các học sinh, sắp xếp theo kiểu ABC, kiểu Việt Nam, và tìm kiếm
  * yêu cầu tối ưu bộ nhớ: cấp phát động, chỉ cấp phát cho đủ số học sinh, chỉ cấp phát mỗi học sinh số byte vừa đủ lưu trữ tên
  * có thể thêm vào danh sách (nếu thêm thì cấp thêm bộ nhớ)
  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*--------------------------------------------------------*/
int kt(char *s)
{
     int i;
     for (i=1; i<strlen(s)-1; i++)
     if (s[i]==' ') return 1;
     return 0;
}
/*--------------------------------------------------------*/
void them(char ***A, int *n)
{
     int i, m ;
     char s[40];
     while (1)
     {
          printf("Nhap so hoc sinh can them: ");
          if (scanf("%d", &m)!=1){
               printf("WRONG INPUT!\n");
               while (getchar()!='\n');
          } else {
               while (getchar()!='\n');
               break;
          }
     }



     if (*n==0)   (*A)=(char **)malloc( (*n)*sizeof(char*));
     else         (*A)=realloc( (*A), (*n+m)*sizeof(char *));


     for (i=(*n); i<*n+m; i++){
          while (1){
               printf("Nhap ten hs: "); gets(s);
               if (!kt(s)) printf("TEN KHONG HOP LE!\n");
               else break;
          }
          (*A)[i]=(char *)malloc(strlen(s)*sizeof(char)+1);
          strcpy((*A)[i], s);
     }

     (*n)+=m;
}
/*--------------------------------------------------------*/
int sapxepABC(char **a, int n)
{

     if (n==0){
          printf("DANH SACH RONG!\n");
          return 1;
     }

     int i,j;
     for (i=0; i<n-1; i++)
     for (j=i+1; j<n; j++)
     if (strcmp(a[i], a[j])>0){
          char *p;
          p=a[i];    //thay vì đổi chỗ 2 giá trị của xâu, ta đổi chỗ con trỏ trỏ tới đầu xâu
          a[i]=a[j];
          a[j]=p;
     }
     for (i=0; i<n; i++)
     printf("%-30s\n", a[i]);

     return 0;
}
/*--------------------------------------------------------*/
void daoten(char *s, char *s2)
{
     int i,j ,l;
     char tg[40];
     char *p;
     p=s+strlen(s)-1;
     while ((*p)!=' ') p--;
     p++;
     strcpy(tg, p);

     strcat(tg, " ");
     strcat(tg, s);
     strcpy(s2, tg);
}
/*--------------------------------------------------------*/
int sapxepVN( char **a,int n)
{
     if (n==0){
          printf("DANH SACH RONG!\n");
          return 1;
     }

     int i,j;
     char tmp[40]; //không thể khai báo char *tmp vì trong hàm daoten() lệnh strcpy(s2, tg) sẽ sai do tmp=NULL chưa đc gán vào bộ nhớ nào
     char tmp2[40];

     for (i=0; i<n-1; i++)
     for (j=i+1; j<n; j++){
          daoten(a[i], tmp);
          daoten(a[j], tmp2);
          if ( strcmp(tmp,tmp2) >0  ){
               char *p;
               p=a[i];   //thay vì đổi chỗ 2 giá trị của xâu, ta đổi chỗ con trỏ trỏ tới đầu xâu
               a[i]=a[j];
               a[j]=p;
          }
     }

     for (i=0; i<n; i++)
     printf("%-30s\n", a[i]);

     return 0;
}
/*--------------------------------------------------------*/
void free_all(char **a, int n)
{
     int i;
     for (i=0; i<n; i++)
     free(a[i]);
     free(a);
}
/*--------------------------------------------------------*/
void timkiem( char **a, int n)
{
     if (n==0){
          printf("DANH SACH RONG!\n");
          return 1;
     }

     char name[30];
     int kt=0,i;
     while (getchar()!='\n');
     printf("Nhap ten muon tim kiem: ");
     gets(name);
     for (i=0; i<n; i++)
     if (strcmp(name, a[i])==0){
          printf("%-30s\n", a[i]);
          kt=1;
     }
     if (!kt) printf("KHONG TIM THAY!\n");
}
/*--------------------------------------------------------*/
int main()
{
     char **ds;
     int menu,n=0,i;

     while (1)
     {
          printf("--------------------------------------------\n");
          printf("                    MENU                    \n");
          printf("--------------------------------------------\n");
          printf("1. Nhap danh sach\n2. Sap xep va in ra theo ABC\n3. Sap xep va in ra kieu Viet Nam\n4. Tim kiem\n5. Thoat \n");
          printf("Input choice: ");

          if (scanf("%d", &menu)!=1) {
               while (getchar()!='\n');
               printf("WRONG CHOIE!\n");
               continue;
          }


          switch (menu){
               case 1:   them(&ds,&n);
                         break;
               case 2:   sapxepABC(ds,n);
                         break;
               case 3:   sapxepVN(ds,n);
                         break;
               case 4:   timkiem(ds,n);
                         break;
               case 5:   free_all(ds,n);
                         return 0;
               default:  printf("WRONG CHOICE!\n");
          }
     }
     return 0;
}
