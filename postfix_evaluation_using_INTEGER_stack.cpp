/*Implementing Postfix Evaluation using INTEGER Stack
Algorithm
step1 : Scan the postfix expression left to right, one token at a time
step2 : if token is OPERAND then ,push into stack
step3 : a) if token is OPERATOR then ,pop the top 2 items from the stack (1st pop - op2 & 2nd pop - op1)
	    b) compute the operation result = op1 (operator) op2, and push the result back into stack
step4 : After the last token, the single value left on the stack is the final answer

*/

#include<stdio.h>
#define MAX_SIZE 10
int top = -1; //current index of the array to keep track of the current size and position of the last element of the stack
void push(int[],int);  //param1 = array name;param2=value
void traverse(int[]);  //param1 = array name;
int pop(int[]);        //param1 = array name;
int peek(int[]);       //param1 = array name
int is_empty();        //return 1 if stack is empty else return 0
int is_full();         //return 1 if stack is full else return 0

int main(){
	int stack[MAX_SIZE]={0}; //declare an array of size as MAX_SIZE and initilise it to 0.
	char postfix_exp[] = "234*+"; //"(2+3*4)"; //infix expr "(2+3)*(4-1)"; //
	int result; //output
	int pop_item;
	int i=0; //i to track postfix tokens 
	printf("\nGiven Postfix(RPN) Expression : %s\n", postfix_exp);
	
	//step1 : Scan the postfix expression left to right, one token at a time
	while(postfix_exp[i]!='\0'){//read from left to right until string terminator is reached (\0)
		//step2 : if token is OPERAND then ,push into stack
		if(	postfix_exp[i]!='+' && postfix_exp[i]!='-' && 
			postfix_exp[i]!='*' && postfix_exp[i]!='/' && 
			postfix_exp[i]!='%'){
				push(stack,(postfix_exp[i]-'0')); //subtract it from ascii value of '0' to store actual value
				traverse(stack);
		}
		//step3 : a) if token is OPERATOR then ,pop the top 2 items from the stack (1st pop - op2 & 2nd pop - op1)
	    //      b) compute the operation result = op1 (operator) op2, and push the result back into stack
		else{
			//pop1 
			int op1=0,op2=0;
			op2 = pop(stack); //operand 2
			//pop2
			op1 = pop(stack); //operand 1
			//now we perform the actual operation using operator
			switch(postfix_exp[i]){
				case '*': result = op1 * op2; break;
				case '/': result = op1 / op2; break;
				case '%': result = op1 % op2; break;
				case '+': result = op1 + op2; break; 
				case '-': result = op1 - op2; break;
				default : printf("\nInvalid operator %c",postfix_exp[i]);
			}
			//push the result back into stack
			push(stack,result); //dont do the ascii value subtraction here since result is already an integer value
			traverse(stack);
		}
        i++;
    }
	//step4 : After the last token, pop the stack which contains the final answer
	result = pop(stack);
    printf("\n\nPostfix Evaluation     : %d\n", result);

    return 0;
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

