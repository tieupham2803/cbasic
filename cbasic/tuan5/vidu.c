#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
int main(){
	StackType stack;
	Initialize(&stack);
	push(10,&stack);
	int a = pop(&stack);
	printf("%d\n", a);
	return 1;
}
