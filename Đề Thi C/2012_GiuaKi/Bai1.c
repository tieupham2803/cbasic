#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10
typedef struct 
{
	int data;
	char name[31];
} KiemTra;
KiemTra Bus[max];
int n=0;
void ReadFile(FILE *f)
{
	int i=0;
	while(!feof(f))
	{
		fscanf(f,"%d",&Bus[i].data);
		fgetc(f);
		fgets(Bus[i].name,30,f);
		Bus[i].name[strlen(Bus[i].name)-1]='\0';
		n++;
		i++;
	}
}
void swap(KiemTra *a,KiemTra *b)
{
	KiemTra *c;
	c->data=a->data;
	a->data=b->data;
	b->data=c->data;
	strcpy(c->name,a->name);
	strcpy(a->name,b->name);
	strcpy(b->name,c->name);		
}
void Sort(KiemTra Bus[max])
{
	int i;
	int j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			if(Bus[i].data>Bus[j].data)
				swap(Bus+i,Bus+j);
		}
}
void PrintScreen(KiemTra Bus[max])
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%-4d%-31s\n",Bus[i].data,Bus[i].name);
	}
}
int Search(KiemTra Bus[max],int n,int data)
{
	int lower=0,mid,upper;
	upper=n-1;
	while(lower<=upper)
	{
		mid=(lower+upper)/2;
		if(Bus[mid].data> data) upper=mid-1;
		else if(Bus[mid].data<data) lower=mid+1;
		else /*if(Bus[mid].data==data) */return Bus[mid].data;
	}
	return -1;
}
int TimTheoTen(char s[40])
{	
	int i,count=0;
	for(i=0;i<n;i++)
	{
		if(strstr(Bus[i].name,s)!=NULL)
			{
				printf("%-4d%-31s\n",Bus[i].data,Bus[i].name);
				count++;
			}
	}
	return count;

}
void main()
{
	int count=0;
	int k;
	int i;
	int data;
	char s[40];
	FILE *f;
	f=fopen("2012_GiuaKi.txt","r");
	ReadFile(f);
	while(1)
	{
		printf("----------------MENU-------------------------\n");
		printf("1.Doc Thong Tin\n2.Sap Xep\n3.Tim theo so tuyen\n4.Tim theo ten tuyen\n5.Nang cao\n6.Thoat chuong trinh\n");
		printf("->>>  CHON CHUC NANG:   ");
		scanf("%d",&k);
		while(getchar()!='\n');
		if(k==1) ReadFile(f);
		if(k==2)
		{
			Sort(Bus);
			PrintScreen(Bus);
		}
		if(k==3)
		{
			printf("Nhap vao tuyen xe bus muon tim:");
			scanf("%d",&data);
			for(i=0;i<n;i++)
			{
				//printf("%d\n", Search(Bus,n,data) );
				if(Search(Bus,n,data)==Bus[i].data)
				{
					printf("%-4d%-31s\n",Bus[i].data,Bus[i].name);
					count++;
				}
			}
			if(count==0) printf("Khong co tuyen xe bus can tim\n");
			count=0;
		}
		if(k==4)
		{
			printf("Nhap vao ten tuyen can tim:");
			fgets(s,40,stdin);
			s[strlen(s)-1]='\0';
			if(TimTheoTen(s)==0) printf("\nKhong tim thay ten\n");

		}
		if(k==6) break;

	}
	
	//PrintScreen(Bus);
	fclose(f);
}