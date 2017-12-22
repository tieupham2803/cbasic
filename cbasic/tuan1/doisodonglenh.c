#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
  double dai, rong;
  if(argc!=3)
    {
      printf("Ban da nhap sai doi so,\n");
      return 1;
    }
  dai=atof(argv[1]);
  rong=atof(argv[2]);
  printf("Dien tich cua hinh chu nhat la: %.2f\n", dai*rong);
  printf("Chu vi cua hinh chu nhat la: %.2fd\n\n", (dai+rong)*2);
  return 0;
}
