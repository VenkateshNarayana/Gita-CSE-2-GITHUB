/*Stack -  
A lds which follows LIFO - Last In First Out
Operations -  push, pop, peek, is_empty,is_full, traverse(?-only for debugging and viewing stack elements)
*/
#include<stdio.h>
#define MAX_SIZE 5
int top = -1; //current index of the array to keep track of the current size and position of the last element of the stack
void push(int[],int);  //param1 = array name;param2=value
void traverse(int[]);  //param1 = array name;
int pop(int[]);        //param1 = array name;
int peek(int[]);        //param1 = array name
int is_empty();         //return 1 if stack is empty else return 0
int is_full();          //return 1 if stack is full else return 0
int main(){
	int stack[MAX_SIZE]={0}; //declare an array of size as MAX_SIZE and initilise it to 0.
	//push operation
	push(stack,10);
	traverse(stack);
	push(stack,20);
	traverse(stack);
	push(stack,30);
	traverse(stack);
	
	int popped_item = pop(stack);
	printf("\npopped value=%d",popped_item);	
	traverse(stack);
    printf("\npeeked value=%d",peek(stack));
	
	popped_item = pop(stack);
	printf("\npopped value=%d",popped_item);	
	traverse(stack);
	
	popped_item = pop(stack);
	printf("\npopped value=%d",popped_item);	
	traverse(stack);
	
	popped_item = pop(stack);
	printf("\npopped value=%d",popped_item);	
	traverse(stack);

	return 0;//for main
}
int is_empty(){
	return (top<=-1);
}
int is_full(){
	return (top>=MAX_SIZE-1);
}
void traverse(int stack[]){
	
	if (is_empty()){
		printf("\nStack is empty....Cannot perform traverse operation!!!");
		return;
	}
	
	printf("\nStack Elements[");
	for(int i=0;i<=top;i++){
		printf("%d ",stack[i]);
	}
	printf("]");
}

int peek(int stack[]) {

	return stack[top];
	
}

int pop(int stack[]) {
	if (is_empty()){
		printf("\nStack Underflow....Cannot perform pop operation!!!");
		return -1;
	}
	int pop_item = stack[top--];
	return pop_item;
}
void push(int stack[],int value){ //param1 = array name;param2=value
	if (is_full()){
		printf("\nStack Overflow....Cannot perform push operation!!!");
		return;
	}
	stack[++top]=value; //this is going to insert value at index 0 
}

