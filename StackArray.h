#define Max 50
typedef int Eltype;
typedef Eltype StackType[Max];
int top;

void Initialize(StackType stack) {top=0;}

int empty(StackType stack) {return top==0;}

int full(StackType stack) {return top==Max;}

void push(Eltype el, StackType stack)
{
  if(full(stack)) printf("Stack tran!\n");
  else stack[top++]=el;
}

Eltype pop(StackType stack)
{
  if(empty(stack)) printf("Stack khong con de lay ra\n");
  else return stack[--top];
}
