/**---------------------------------------------------------------------------------
  * Nguyễn Trí Minh. MSSV: 20132599. K58.
  * Nhóm 3. Môn C Basic.
  * --------------------------------------------------------------------------------
  * Dùng cấu trúc gồm các trường: Tên sv, khóa, lớp, ngày sinh, giới tính.
  * Xây dựng chương trình gồm các menu:
    - Thêm.
    - Sắp xếp (theo khóa, lớp, theo　ABC, kiểu VN).
    - Tìm kiếm.
    - In danh sách theo khóa, lớp.
  * Khi vào chương trình kiểm tra xem có tệp D:\Quanlihocsinh\data.dat　ko,
  　　nếu có thì đọc từ tệp, nếu ko thì nhập mới.
  * Trc khi kết thúc ct, lưu danh sách vào file trên.
  * Dùng cấp phát động.
  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Print1 printf("%-30s%-12s%-13s%-8s%-8s\n", "Ho va ten", "Gioi tinh", "Ngay sinh", "Lop", "Khoa");

typedef struct {
     char name[30];
     char grade[5];
     char Class[5];
     char birthday[11];
     char sex[10];
} Sinhvien;
/*----------------------------------------------------------------------------------*/
int kt(char *s)
{
     int i;
     for (i=1; i<strlen(s)-1; i++)
     if (s[i]==' ') return 1;
     return 0;
}
/*----------------------------------------------------------------------------------*/
Sinhvien add_inf()
{
     Sinhvien data;

     while (1){
          printf("Nhap ten sinh vien: ");
          gets(data.name);
          if (!kt(data.name)) printf("TEN SAI!\n"); //kt ten co dau cach ko
          else break;
     }

     printf("Nhap khoa: "); gets(data.grade);
     printf("Nhap lop: "); gets(data.Class);
     printf("Nhap ngay sinh (DD/MM/YYY): "); gets(data.birthday);
     printf("Nhap gioi tinh: "); gets(data.sex);
     return data;
}
/*----------------------------------------------------------------------------------*/
void add(Sinhvien **a, int *n) //n la con tro tro den array_size
{
     int m, i;

     printf("Nhap so sinh vien muon them: "); scanf("%d", &m);

     if ((*n)==0) (*a)=(Sinhvien *)malloc(m*sizeof(Sinhvien));
     else (*a)=(Sinhvien *)realloc( *a, (*n+m)*sizeof(Sinhvien));

     while (getchar()!='\n');
     for (i=(*n); i<(*n)+m; i++)   (*a)[i]=add_inf();
     *n+=m;
}
/*----------------------------------------------------------------------------------*/
void Print2(Sinhvien a)
{
     printf("%-30s%-12s%-13s%-8s%-8s\n", a.name, a.sex, a.birthday, a.Class, a.grade);

}
/*----------------------------------------------------------------------------------*/
void Swap_sv(Sinhvien *a, Sinhvien *b)
{
     Sinhvien tmp;
     tmp=(*a);
     (*a)=(*b);
     (*b)=tmp;
}
/*----------------------------------------------------------------------------------*/
int SortABC(Sinhvien *a, int array_size)
{

     if (array_size==0){
          printf("EMPTY LIST!\n");
          return 1;
     }

     int i,j;
     for (i=0; i<array_size-1; i++)
     for (j=i+1; j<array_size; j++){
          if (strcmp(a[i].grade, a[j].grade)>0 ) Swap_sv(&a[i], &a[j]);
          if (strcmp(a[i].grade, a[j].grade)==0){
               if (strcmp(a[i].Class, a[j].Class)>0 ) Swap_sv(&a[i], &a[j]);
               if (strcmp(a[i].Class, a[j].Class)==0)
                    if (strcmp(a[i].name, a[j].name)>0) Swap_sv(&a[i], &a[j]);
          }
     }

     Print1;
     for (i=0; i<array_size; i++) Print2(a[i]);
     return 0;
}
/*----------------------------------------------------------------------------------*/
void daoten(char *s, char *s2)
{
     int i,j ,l;
     char tg[30];
     char *p;
     p=s+strlen(s)-1;
     while ((*p)!=' ') p--;
     p++;
     strcpy(tg, p);

     strcat(tg, " ");
     strcat(tg, s);
     strcpy(s2, tg);
}
/*----------------------------------------------------------------------------------*/
int SortVN(Sinhvien *a, int array_size)
{
     if (array_size==0){
          printf("EMPTY LIST!\n");
          return 1;
     }

     int i,j;
     char tmp[30];
     char tmp2[30];
     for (i=0; i<array_size-1; i++)
     for (j=i+1; j<array_size; j++){
          if (strcmp(a[i].grade, a[j].grade)>0 ) Swap_sv(&a[i], &a[j]);
          if (strcmp(a[i].grade, a[j].grade)==0){
               if (strcmp(a[i].Class, a[j].Class)>0 ) Swap_sv(&a[i], &a[j]);
               if (strcmp(a[i].Class, a[j].Class)==0){
                    daoten(a[i].name, tmp);
                    daoten(a[j].name, tmp2);
                    if (strcmp(tmp, tmp2)>0) Swap_sv(&a[i], &a[j]);
               }
          }
     }

     Print1;
     for (i=0; i<array_size; i++) Print2(a[i]);
     return 0;
}
/*----------------------------------------------------------------------------------*/
int Search(Sinhvien *a, int array_size)
{
     if (array_size==0){
          printf("EMPTY!\n");
          return 1;
     }

     char name[30];
     int kt=0,i,j;
     while (getchar()!='\n');
     printf("Nhap ten muon tim kiem: "); gets(name);

     for (i=0; i<array_size; i++)                       //kt xem co ten ko
     if (strcmp(name, a[i].name)==0){
          kt=1;
          break;
     }

     if (kt) {
          Print1;
          for (j=i; j<array_size; j++)
          if (strcmp(a[j].name, name)==0) Print2(a[j]);
     }else printf("KHONG TIM THAY!\n");
}
/*----------------------------------------------------------------------------------*/
void Display_all(Sinhvien *a, int array_size)
{
     int i;
     Print1;
     for (i=0; i<array_size; i++) Print2(a[i]);
}
/*----------------------------------------------------------------------------------*/
void Display_Class(Sinhvien *a, int array_size)
{
     int i, j, kt=0;
     char s[5];
     while (getchar()!='\n');
     printf("Nhap lop muon in: "); gets(s);
     for (i=0; i<array_size; i++)
     if (strcmp(a[i].Class, s)==0){
          kt=1;
          break;
     }

     if (kt==1){
          Print1;
          for (j=i; j<array_size; j++)
          if (strcmp(a[j].Class, s)==0) Print2(a[j]);
     } else printf("KHONG CO LOP %-s!\n", s);
}
/*----------------------------------------------------------------------------------*/
void Display_grade(Sinhvien *a, int array_size)
{
     int i, j, kt=0;
     char s[5];
     while (getchar()!='\n');
     printf("Nhap khoa muon in: "); gets(s);
     for (i=0; i<array_size; i++)
     if (strcmp(a[i].grade, s)==0){
          kt=1;
          break;
     }

     if (kt==1){
          Print1;
          for (j=i; j<array_size; j++)
          if (strcmp(a[j ].grade, s)==0) Print2(a[j]);
     } else printf("KHONG CO KHOA %-s!\n", s);
}
/*----------------------------------------------------------------------------------*/
int Display(Sinhvien *a, int array_size)
{
     int menu;
     while (1)
     {
          printf("--------------------------------------------------------\n");

          printf("%-s%-s%-s%-s","1. In tat ca danh sach\n",
                                "2. In theo lop\n",
                                "3. In theo khoa\n",
                                "4. Thoat\n");
          printf("Input choice: ");
          if (scanf("%d", &menu)!=1) {
               while (getchar()!='\n');
               printf("WRONG CHOIE!\n");
               continue;
          }


          switch (menu){
               case 1:   Display_all(a, array_size);
                         break;
               case 2:   Display_Class(a, array_size);
                         break;
               case 3:   Display_grade(a ,array_size);
                         break;
               case 4:   return 0;
               default:  printf("WRONG CHOICE!\n");
          }
     }
}
/*----------------------------------------------------------------------------------*/
void Save_data(Sinhvien *a, int array_size)
{
     FILE *f=fopen("D:\Quanlihocsinh\data.dat", "wb");
     fwrite(a, sizeof(Sinhvien), array_size, f);
     fclose(f);
}
/*----------------------------------------------------------------------------------*/
int main()
{
     Sinhvien *ds;
     int menu,array_size=0;
     FILE *f=fopen("D:\Quanlihocsinh\data.dat", "rb");

     if (f==NULL) add(&ds, &array_size);
     else{
          fseek(f, 0L, SEEK_END);
          array_size=ftell(f)/sizeof(Sinhvien);
          ds=(Sinhvien *)malloc(array_size*sizeof(Sinhvien));

          rewind(f);
          fread(ds, sizeof(Sinhvien), array_size, f);
          fclose(f);
     }


     while (1)
     {
          printf("--------------------------------------------------------\n");
          printf("                          MENU                          \n");
          printf("--------------------------------------------------------\n");
          printf("%-s%-s%-s%-s%-s%-s","1. Nhap danh sach\n",
                                      "2. Sap xep va in ra theo ABC\n",
                                      "3. Sap xep va in ra kieu Viet Nam\n",
                                      "4. Tim kiem\n",
                                      "5. In danh sach\n",
                                      "6. Thoat\n");
          printf("Input choice: ");

          if (scanf("%d", &menu)!=1) {
               while (getchar()!='\n');
               printf("WRONG CHOIE!\n");
               continue;
          }


          switch (menu){
               case 1:   add(&ds, &array_size);
                         break;
               case 2:   SortABC(ds,array_size);
                         break;
               case 3:   SortVN(ds,array_size);
                         break;
               case 4:   Search(ds,array_size);
                         break;
               case 5:   Display(ds, array_size);
                         break;
               case 6:   Save_data(ds, array_size);
                         free(ds);
                         return 0;
               default:  printf("WRONG CHOICE!\n");
          }
     }
     return 0;
}
