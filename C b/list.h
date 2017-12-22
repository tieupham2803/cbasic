#ifndef LIST_H
#define LIST_H
#include <stdio.h>

typedef struct vo
{
	char Name[30];
    float point;
    struct vo *next;
}Student;

void addHead(Student **top, Student *newNode);
void free_all(Student **top);
void DeleteNode(Student **top,int a);
void Taodsmoi(Student **top4,Student **top1);
void Addsort(Student *newNode,Student **top4);
int Searpoint(Student **top,int a);
void Prin1();
int Read_file(Student **top,char *x);
void Prin(Student *top);
Student * AddNode(char *s,float a);
void InsearNode(Student **top,Student *Node);

#endif