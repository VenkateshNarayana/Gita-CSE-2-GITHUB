/* Implementing Infix to Postfix operation using INTEGER Stack
   Algorithm
    step1:  Read the infix expression from left to right
    step2:  if ‘(’ then push onto the stack. 
   		    or,
   		    if Operator then pop & append to postfix expression string  
			   while stack-top has >= precedence
			   next we push the current operator
    step3:  if Operand then append directly to output string
    step4:  if ‘)’ then pop to output string until ‘(’ is found; discard both parenthesis
    step5:  if we have reached end of infix expression then go to stack and pop all remaining 
	         operators to output string
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

int operator_precedence(char);
int main(){
	int stack[MAX_SIZE]={0}; //declare an array of size as MAX_SIZE and initilise it to 0.
	char infix_exp[] = "(2+3)*(4-1)"; //"(2+3*4)"; //infix expr "(2+3)*(4-1)"; //
	char postfix_exp[20] = ""; //output
	int pop_item;
	int i=0, k=0; //i to track infix characters and k will track the output postfix 
	printf("\nGiven Infix Expression : %s\n", infix_exp);
	
	//read the infix string from left to right
	while(infix_exp[i]!='\0'){//read from left to right until string terminator is reached (\0)
		/* Step 2: Opening parenthesis */
        if (infix_exp[i] == '(') {

            push(stack, infix_exp[i]);
            traverse(stack);
        }

        //Step 2: Operator 
        else if (infix_exp[i] == '+' ||
                 infix_exp[i] == '-' ||
                 infix_exp[i] == '*' ||
                 infix_exp[i] == '/' ||
                 infix_exp[i] == '%') {

             /* Pop operators having greater OR equal precedence.
             * But stop when '(' is found.*/
            while (!is_empty() &&
                   peek(stack) != '(' &&
                   operator_precedence(peek(stack))
                       >= operator_precedence(infix_exp[i])) {
				//pop and append to postfix the higher precedence operators
                pop_item = pop(stack);
                postfix_exp[k++] = pop_item;
            }

            /* Push current operator */
            push(stack, infix_exp[i]);
            traverse(stack);
        }

        // Step 4: Closing parenthesis
        else if (infix_exp[i] == ')') {
			//when closing parenthesis found then pop until open parenthesis and append operators to postfix
            while (!is_empty() && peek(stack) != '(') {
                pop_item = pop(stack);
                postfix_exp[k++] = pop_item;
            }

            // Remove '(' 
            if (!is_empty() && peek(stack) == '(') {
                pop(stack);
            }
        }

        // Step 3: Operand 
        else {
            postfix_exp[k++] = infix_exp[i];
        }
        i++;
    }

    /* Step 5: Pop remaining operators */
    while (!is_empty()) {

        pop_item = pop(stack);

        /*Ideally there should be no '(' here
         * if parentheses are balanced.*/
        if (pop_item != '(') {
            postfix_exp[k++] = pop_item;
        }
    }

    /* String termination */
    postfix_exp[k] = '\0';

    
    printf("\n\nPostfix Expression     : %s\n", postfix_exp);

    return 0;
}
int operator_precedence(char op){
	switch(op){
		case '*': 
		case '/': 
		case '%': return 2;
		case '+':  
		case '-': return 1;
		default : return 0;
	}
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
		printf("%c ",stack[i]);
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

