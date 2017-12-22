#include<stdio.h>
#include<string.h>
#define MAX 100
int main()
{
  int i,n,k,chose;
  char a[100],b[100],c;
 do
   {
     printf("*** MENU ***\n 1.Nhap lieu\n 2.xuong dong tu dau tien\n 3.xuong dong o moi tu\n 4.thoat\n"); 
     printf("moi ban nhap lua chon: "); scanf("%d",&chose);
     switch(chose)
       {
       case 1:
	 printf("nhap vao chuoi a: ");
	 getchar();
	 gets(a);
	 printf("du lieu da nhap: %s\n",a);
	 n=strlen(a);
	 k=1;
	 break;
       case 2:
	 if (k!=1) {printf("ban chua nhap du lieu!\n\n"); break;} 
	 else
	   {
	     strcpy(b,a);
	     for(i=0;i<n;i++)
	       if(b[i]==' ') {b[i]='\n';break;}
	     printf("chuoi sau khi chinh sua:\n%s\n",b);
	     break;
	   }
       case 3:
	 if (k!=1) {printf("ban chua nhap du lieu!\n\n"); break;} 
	 else
	   {
	     strcpy(b,a);
	     for(i=0;i<n;i++)
	       if(b[i]==' ') b[i]='\n';
	     printf("chuoi sau khi chinh sua:\n%s\n",b);
	     break;
	   }
       case 4: break;
       }
   }while(chose!=4);
 return 0;
}
