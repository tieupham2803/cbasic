#ifndef QUENE_H
#define QUENE_H
#include <stdio.h>

typedef struct vo
{
	char Name[50];
    int mau;
    int tancong;
    int nhanhnhen;
    int phongthu;
    int point;
    struct vo *next;
}Monphai;

void Prin1();
int Read_file(Monphai **top,char *x);
void Prin(Monphai *top);
Monphai * AddQueue(char *s,int a,int b,int c,int d);
void Truepoint(int a);
void InsearNode(Monphai **top,Monphai *Node);

#endif