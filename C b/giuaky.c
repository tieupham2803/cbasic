#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float Nhap()
{
	float a;
	printf("Moi ban nhap diem chuan\n");
	scanf("%d",&a);
	return a;
}
int Read_file(char *filename)
{
	FILE *file;
	int i=0;
	int n,m;
	int id;
	int v1,v2,l;
	char *IP;
	file = fopen(filename,"r+");
	if(file == NULL)
	{
		printf("can not read file\n");
		return 0;
	}
	else
	{
		// fscanf(file,"%d\n",&m);
		// for(i=0;i<m;i++)
		// {
		// 	IP = new_string();
		// 	fscanf(file,"%d %s",&id,IP);
		// 	addVertex(g2,id,IP);
		// }
		// fscanf(file,"%d\n",&n);
		// for(i=0;i<n;i++)
		// {
		// 	fscanf(file,"%d %d %d\n",&v1,&v2,&l);
		// 	AddEdge_int(g1,v1,v2,l);
		// 	AddEdge_int(g1,v2,v1,l);
		// }
		// return 1;
		// fclose(file);
	}
}
main(){
	int i,j;
	float diemchuan;
	int size = 0,imenu;
	size = Read_file();
	while(1)
	{
		printf("==============MENU=================\n");
		printf("1  :Nhap Diem Chuan\n");
		printf("2  :In danh sach trung tuyen\n");
		printf("3  : Thi sinh diemm cao nhat\n");
		printf("4  :Tim diem chuan\n");
		printf("5  :Thoat\n");
		printf(" MOi ban chon chuc nang\n");
		scanf("%d",&imenu);
		while(getchar() != '\n');
		switch(imenu)
		{
			case 1:
			{
				diemchuan = Nhap();
				continue;
			}
			// case 2:
			// {
			// 	Prin();
			// 	continue;
			// }
			case 5:
			break;
		}
		break;
	}
// 	Save_file();
// 	for(i = 1;i <= size;i++)
// 		{
// 			free(ds2[i]);
// 		}
// 		free(ds1);
// }


