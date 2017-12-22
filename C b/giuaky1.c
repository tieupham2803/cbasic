/*
Ho va Ten : Nguyen Van Quang
MSSV      : 20133099
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *ds1;
float **ds2;
int Read_file();
void Prin();
int Nhap(int size);
void Save_file();

main(){
	int i,j;
	int size = 0,imenu;
	size = Read_file();
	while(1)
	{
		printf("==============MENU=================\n");
		printf("1  :Nhap them\n");
		printf("2  :In danh sach\n");
		printf("3  :In gia tri max min\n");
		printf("4  :Tim va in gia tri trung binh cac vecto\n");
		printf("5  :Thoat\n");
		printf(" MOi ban chon chuc nang\n");
		scanf("%d",&imenu);
		while(getchar() != '\n');
		switch(imenu)
		{
			case 1:
			{
				size = Nhap(size);
				continue;
			}
			case 2:
			{
				Prin();
				continue;
			}
			case 5:
			break;
		}
		break;
	}
	Save_file();
	for(i = 1;i <= size;i++)
		{
			free(ds2[i]);
		}
		free(ds1);
}

int Read_file()
{
	int i = 0,j,size;
	FILE *ptr;
	char filename[] = "data.txt";
	if((ptr = fopen(filename , "r")) == NULL)
	{
		printf("Can not file \n");
	}
	else
	{
		fscanf(ptr,"%d",&size);
		ds1 = (int *)malloc(sizeof(int) *size);
		ds1[0] = size;
		ds2 = (float**)malloc(sizeof(float*) * size);
		for(i = 1; i <= size;i++)
		{
				fscanf(ptr,"%d",&ds1[i]);
				ds2[i] = (float*)malloc(sizeof(float) * ds1[i]);
				for(j = 0;j < ds1[i];j++)
				{
					fscanf(ptr,"%f",&ds2[i][j]);
				}
		}
	}
	Prin();
	fclose(ptr);
	return size;
}

void Prin()
{
	int i,j;
	printf("%d\n",ds1[0]);
	for(i = 1;i <= ds1[0];i++)
	{
			printf("%-4d",ds1[i]);
			for(j = 0 ;j < ds1[i];j++)
			{
				printf("%-4f",ds2[i][j]);
			}
			printf("\n");
		}
}

int Nhap(int size)
{
	int i,j;
	int a,b;
	printf("Moi ban nhap them so vecto la \n");
	scanf("%d",&a);
	while(getchar() !='\n');
	if(size == 0)
	{
		ds1 = (int *)malloc(sizeof(int) * a);
		ds2 = (float**)malloc(sizeof(float*) * a);
	}
	else
	{
		ds1 = realloc(ds1,sizeof(int)*(size+a));
		ds2 = realloc(ds2,sizeof(float*) * (size+a));
	}
	printf("%d\n",size);
	for(i = (size +1);i <= (size +a);i++)
	{
		printf("Moi ban nhap so chieu la :");
		scanf("%d",&b);
		printf("\n");
		while(getchar() !='\n');
		ds1[i] = b;
		ds2[i] = (float*)malloc(sizeof(float) * ds1[i]);
		for(j = 0;j < b;j++)
		{
			printf("Chi so la \n");
			scanf("%f",&ds2[i][j]);
			while(getchar() !='\n');
		}
		printf("\n");
	}
	Prin();
	size = size +a;
	ds1[0] = size;
		printf("%d\n",size);
	return size;
}

void Save_file()
{
	int i,j;
	FILE *ptr;
	char filename[] = "data.txt";
	if((ptr = fopen(filename , "w")) == NULL)
	{
		printf("Can not file\n");
	}
	else
	{
		fprintf(ptr,"%-4d",ds1[0]);
		printf("%d\n",ds1[0]);
		fprintf(ptr,"%s","\n");
		for(i = 1;i <= ds1[0];i++)
		{
			fprintf(ptr,"%-4d",ds1[i]);
			for(j = 0;j < ds1[i];j++){
				fprintf(ptr,"%-4f",ds2[i][j]);
			}
			fprintf(ptr,"%s","\n");
		}
	}
	fclose(ptr);
}