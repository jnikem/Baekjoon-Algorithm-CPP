#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
int N;
char order[17];

typedef int element;
typedef struct {
	element *data;		
	int capacity;		
	int top;
} StackType;

void init_stack(StackType *s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element *)malloc(s->capacity * sizeof(element));
	
}

int is_empty(StackType *s)
{
	return (s->top == -1);
}

int is_full(StackType *s)
{
	return (s->top == (s->capacity - 1));
}
void push(StackType *s, element item)
{
	if (is_full(s)) {
		s->capacity *= 2;
		s->data =
			(element *)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}

element pop(StackType *s)
{
	if (is_empty(s)) {
		return -1;
	}
	else return s->data[(s->top)--];
}

element peek(StackType *s)
{
	if (is_empty(s)) {
		return -1;
	}
	else return s->data[(s->top)];
}

int main(void)
{
	StackType s;
	init_stack(&s);

    scanf("%d",&N);
	for(int i = 0; i<N; i++){
        scanf("%s",order);
        
        if (strcmp(order,"push") == 0){
            int X;
            scanf("%d",&X);
            push(&s,X);
        }
        else if (strcmp(order,"pop") == 0){
            printf("%d\n",pop(&s));
        }
        else if (strcmp(order,"size") == 0){
            printf("%d\n",(s.top) + 1);
        }
        else if (strcmp(order,"empty") == 0){
            printf("%d\n",is_empty(&s));
        }
        else if (strcmp(order,"top") == 0){
            printf("%d\n",peek(&s));
        }
	
}
    free(s.data);
	return 0;
}