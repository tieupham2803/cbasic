#include<stdio.h>
#include<string.h>
#define MAX 100
int main()
{
  int i,n,k,chose;
  char a[100],b[100],c;
 do
   {
     
	 printf("nhap vao chuoi a: ");
	
	 gets(a);
	 //fflust(stdin);
	 printf("du lieu da nhap: %s\n",a);
	 n=strlen(a);
	 k=1;
	
    if (k!=1) {printf("ban chua nhap du lieu!\n\n"); break;} 
	 else
	   {
	     strcpy(b,a);
	     for(i=0;i<n;i++)
	       if(b[i]==' ') {b[i]='\n'; break;}
	     printf("chuoi sau khi chinh sua:\n%s\n",b);
	   }
      
       
   }while(chose!=4);
 return 0;
}
