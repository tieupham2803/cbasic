/** bài toán yêu cầu nhập vào tên các học sinh, sắp xếp theo kiểu ABC, kiểu Việt Nam, và tìm kiếm
  * không yêu cầu tối ưu bộ nhớ 
  * có thể thêm vào danh sách (nếu thêm thì cấp thêm bộ nhớ)
  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*--------------------------------------------------------*/
void them( char a[][30], int *n)
{


     while (getchar()!='\n');
     do{
          if ((*n)>=1000) break;
          (*n)++;
          printf("Nhap ten: (an enter ket thuc) ");
          gets(a[(*n)]);
     } while (a[(*n)][0]!='\0');

     (*n)--;
}
/*--------------------------------------------------------*/
void sapxepABC(char a[][30], int n)
{
     int i,j;

     for (i=0; i<=n-1; i++)
     for (j=i+1; j<=n; j++)
     if (strcmp(a[i], a[j])>0){
          char tmp[30];
          strcpy(tmp, a[i]);
          strcpy(a[i], a[j]);
          strcpy(a[j], tmp);
     }
     for (i=0; i<=n; i++)
     printf("%-30s\n", a[i]);
}
/*--------------------------------------------------------*/
void daoten(char *s, char *s2)
{
     int i,j ,l;
     char tg[40];
     i=l=strlen(s)-1;
     while (s[i]!=' ') i--;
     j=0;
     while (++i<=l) tg[j++]=s[i];
     tg[j]='\0';
     strcat(tg, " ");
     strcat(tg, s);
     strcpy(s2, tg);
}
/*--------------------------------------------------------*/
void sapxepVN(char a[][30], int n)
{
     int i,j;
     char tmp[40];
     char tmp2[40];
     char tmp3[40];

     for (i=0; i<=n-1; i++)
     for (j=i+1; j<=n; j++){
          daoten(a[i], tmp);
          daoten(a[j], tmp2);
          if ( strcmp( tmp, tmp2 ) >0  ){
               strcpy(tmp3, a[i]);
               strcpy(a[i], a[j]);
               strcpy(a[j], tmp3);
          }
     }


     for (i=0; i<=n; i++)
     printf("%-30s\n", a[i]);
}
/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
void timkiem(char a[][30], int n)
{
     char name[30];
     int kt=0,i;
     while (getchar()!='\n');
     printf("Nhap ten muon tim kiem: ");
     gets(name);
     for (i=0; i<=n; i++)
     if (strcmp(name, a[i])==0){
          printf("%-30s\n", a[i]);
          kt=1;
     }
     if (!kt) printf("KHONG TIM THAY!\n");
}
/*--------------------------------------------------------*/
int main()
{
     char a[1000][30];
     int menu,n=-1;

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
               case 1:   them(a, &n);
                         break;
               case 2:   sapxepABC(a, n);
                         break;
               case 3:   sapxepVN(a, n);
                         break;
               case 4:   timkiem(a, n);
                         break;
               case 5:   return 0;
               default:  printf("WRONG CHOICE!\n");
          }
     }
     return 0;
}
