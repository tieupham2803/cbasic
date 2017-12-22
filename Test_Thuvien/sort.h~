#include<stdio.h>
#include<stdlib.h>
#define MAX 81
/*
Dinh nghia mot cau truc elementtype co dang
typedef struct elementtype {... key; ...;} elementtype;
trong do key la khoa tim kiem
*/
/*=========================================================================
            Cac ham phu (duoc khai bao trong chuong trinh chinh)
=========================================================================*/
int compare(elementtype El1, elementtype El2);
void giveElement(elementtype *El1, elementtype El2);
//Ham gan gia tri cho elementtype
/*=========================================================================
                        Cac ham ho tro cho sap xep
=========================================================================*/
//Ham ho tro cho ham HeapSort
//Ghi chu: mang khai bao de luu cac gia tri su dung de sap xep
//trong Heap Sort phai danh so bat dau tu 1 chu khong phai la 0!!!
void adjust(elementtype list[], int root, int n)
{
  int child; elementtype temp,rootkey;
  temp=list[root];
  giveElement(&rootkey,list[root]);
  child=2*(root+1)-1;
  while(child<=n-1)
  {
    if((child<n-1) && (compare(list[child],list[child+1])<0))
      child++; //tim xem con trai hay con phai lon hon
    if(compare(rootkey,list[child])>0) break;
    else
    {
      list[(child+1)/2-1]=list[child];
      child=(child+1)*2-1;
    }
  }
  list[(child+1)/2-1]=temp;
}
//Ham trao doi 2 gia tri elementtype
void swap(elementtype *El1, elementtype *El2)
{
  elementtype tmp;
  tmp=*El1; *El1=*El2; *El2=tmp;
}
/*=========================================================================
                               Cac ham sap xep
=========================================================================*/
//Sap xep chen
void insertionSort(elementtype list[], int n)
{
  int i,j; elementtype next;
  for(i=1; i<n; i++)
  {
    next=list[i];
    for(j=i-1; j>=0 && compare(next,list[j])<0; j--)
      list[j+1]=list[j];
    list[j+1]=next;
  }
}
//=========================================================================
//Sap xep lua chon
void selectionSort(elementtype list[], int n)
{
  int i,j,min; elementtype tmp;
  for(i=0; i<n-1; i++)
  {
    min=i;
    for(j=i+1; j<=n-1; j++)
      if(compare(list[j],list[min])<0) min=j;
    swap(&list[i],&list[min]);
  }
}
//=========================================================================
//Sap xep bong bong (UNDONE!!!)
void bubbleSort(elementtype list[], int n)
{
  int i,j; elementtype tmp;
  for(i=0; i<=n-1; i++)
    for(j=i; j<=n-1; j++)
      if(compare(list[j],list[i])<0) swap(&list[j],&list[i]);
}
//=========================================================================
//Sap xep vun dong
void heapSort(elementtype list[], int n)
{
  int i;
  for(i=n/2; i>=0; i--) adjust(list,i,n);
  for(i=n-1; i>=0; i--)
  {
    swap(&list[0],&list[i]);
    adjust(list,0,i);
  }
}
//=========================================================================
//Sap xep nhanh
void quickSort(elementtype list[], int left, int right)
{
  int i,j; elementtype pivot;
  if(left<right)
  {
    i=left; j=right+1; giveElement(&pivot,list[left]);
    do
    {
      do i++; while(compare(list[i],pivot)<0);
      do j--; while(compare(list[j],pivot)>0);
      if(i<j) swap(&list[i],&list[j]);
    }
    while(i<j);
    swap(&list[left],&list[j]);
    quickSort(list,left,j-1);
    quickSort(list,j+1,right);
  }
}
