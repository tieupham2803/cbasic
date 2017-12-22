typedef struct hoso
{
	int stt;
	char mssv[10];
	char ten[50];
}sv;


#include <stdio.h>
#include <stdlib.h>
FILE *f1;

int main()
{
  f1 = fopen("d1.dat", "wb");
	int key;
	do{
		printf("MENU\n");
		printf("1. nhap\n");
		printf("2. sao chep\n");
		printf("3. in\n");
		printf("4.thoat\n");

		printf("nhap lua chon: \n");
		scanf("%d", &key);

		switch (key)
		{
			case 1: nhap();   break;
			case 2: break;
			case 3: break;
			case 4: puts("Thoat chuong trinh...");
		}
	}while(key>0 && key<4);
	fclose(f1);
	return 0;
}

void nhap()
{
	int i, n;
	sv ds;
	printf("Nhap vao so phan tu: \n"); scanf("%d", &n);
	fwrite(&n, sizeof(int), 1, n);
	for (i = 0; i < n; i++)
	{
		printf("nhap vao thong tin nguoi thu %d\n", i+1);
		printf("Stt: "); scanf("%d",&ds.stt); getchar();
		printf("mssv: "); gets(ds.mssv);
		printf("ten: "); getchar(); gets(ds.ten);
		fwrite(&ds, sizeof(sv), 1, f1 );
	}
}

