#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
//#define nguon "NokiaDB.txt"
//#define dich "NokiaDB.dat"
typedef struct dienthoai {char ten[30]; char dl[7]; char kt[5]; char gia[15];} dienthoai;
dienthoai *dt; int n; FILE *p;
int nhap(char nguon[MAX])
{
  int i,irc; char doc[81]; FILE *fnguon;
  n=0;
  if((fnguon=fopen(nguon,"r"))==NULL) printf("Không mở được file %s dể đọc!\n",nguon);
  else
  {
    while(fgets(doc,81,fnguon)!=NULL) n++; rewind(fnguon);
    dt=(dienthoai*)malloc(n*sizeof(dienthoai));
    if(dt==NULL) {printf("Lỗi cấp phát bộ nhớ!\n"); return 0;}
    else
    {
      i=0;
      while(!feof(fnguon)) {fscanf(fnguon,"%s %s %s %s",(dt+i)->ten,(dt+i)->dl,(dt+i)->kt,(dt+i)->gia); i++;};
    }
    rewind(p);
    irc=fwrite(dt,sizeof(dienthoai),n,p); printf("Giá trị fwrite trả về: %d\n",irc);
    fclose(fnguon); return 1;
  }
}
void doc(FILE *file)
{
  int irc,i,dem=0; rewind(file);
  irc=fread(dt,sizeof(dienthoai),n,file); printf("Giá trị fread trả về: %d\n",irc);
  printf("Stt  Ten                                Dung luong     Kich thuoc man hinh      Gia tien\n");
  for(i=0;i<=n-1;i++) printf("%-5d%-35s%-15s%-25s%s\n",i+1,(dt+i)->ten,(dt+i)->dl,(dt+i)->kt,(dt+i)->gia);
}
void main()
{
  char nguon[MAX],dich[MAX];
  printf("Nhap ten file nguon: "); gets(nguon);
  printf("Nhap ten file dich: "); gets(dich);
  p=fopen(dich,"w+b");
  if(nhap(nguon)!=0) doc(p);
  free(dt); fclose(p);
}
