/* Applications of Linked List
1. Building a Stack using Linked List 
2. Building a Queue using Linked List
3. Evaluation polynomial expressions
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int          data; //this will store the data part
	struct node* next; //this is a pointer variable which will store the address of another node
};
struct node* head=NULL; //track the first node
struct node* tail=NULL; //track the last node

//creating  node
struct node* create_node(int); //param1 = input data for storing the data(information part1)
//push operations - using insert_at head
void push(int);     //param1 = input data for storing the data(information part1)

//pop operations - using delete_at_head
int pop();        //it will remove the current head and move the head to next node
void peek();       //it will show the data of head(top) 
int is_empty();    //return 1 if list is empty else 0

//traverse operation - traverse from head to tail
void traverse();   //traverse the list from head to tail
void free_list();  //free the linked list if it is not empty using free() function

int main(){
	//perform push operations in my stack
	push(10);     //inserting at top(head) value = 10
	traverse();
	push(20);     //inserting at top(head) value = 20
	traverse();
	push(30);     //inserting at top(head) value = 30
	traverse();
	
	peek();       //this should fetch current top(head->data)
	
	//pop operations 
	pop();       //this should remove the current top(head) and move to next node
	traverse();
	
	pop();       //this should remove the current top(head) and move to next node
	peek();      //this should fetch current top(head->data)
	
	pop();
	peek();      //this should fetch current top(head->data)
	
	pop();       //this is underflow condition
	traverse();
	
	free_list(); //clean up of the linked list
	return 0;	
}
struct node* create_node(int input_data){
	//create the node using malloc 
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	
	if(new_node==NULL){
		printf("memory allocation failed....");
		return NULL;
	}
	new_node->data = input_data ; //fill the data part with the input value provided in the param1
	new_node->next = NULL;        //fill null as this is a brand new node
	return new_node;
}
void push(int input_data){
	//crate the new node
	struct node* new_node = create_node(input_data);
	if(new_node==NULL) return; //memory allocation failed dont proceed
	if(head==NULL){
		head = new_node;
		tail = head;    //because single node we will have our head and tail pointing to the same new node
	}else{
		new_node->next = head; //point new node to current head
		head = new_node;       //move the head to new node
	}
	printf("\nPushed %d successfully in stack",input_data);
}
int pop(){
	//step0 : check if the linked is empty or not
	if(head==NULL){
		printf("\nStack is empty ...cannot perform pop operation");
		return -1;
	}
	//step1 : store the head in a temp
	struct node* temp = head;
	int pop_item = head->data; //store the top(head->data) in pop_item
	//step2 : move the head to next node
	head = head->next;
	//step3 : free the temp
	free(temp);
	printf("\nPopped %d successfully from stack",pop_item);
	return pop_item;
}
int is_empty(){
	return	(head==NULL); //if head is NULL its empty return 1 else 0
}
void peek(){
	if(is_empty()){
		printf("stack is empty");
	}else{
		printf("\nTop=%d",head->data); //show the head as top
	}
}
void traverse(){
	struct node* temp;
	
	if (head==NULL){
		printf("\nMy Stack(top=NULL)[ empty list]");
		return;
	}
	temp = head; //store head in temp so that we can traverse till tail from head
	printf("\nMy Stack(top=%d)[",head->data);
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp = temp->next;
	}
	printf("null]");
}
void free_list(){
	struct node* temp;
	if (head==NULL){
		return;
	}
	while(head!=NULL){
		temp = head;        //store head in temp so that we can free it after it moves to next node
		head = head->next;  //move head to next node
		free(temp);         //free the temp
	}
	printf("\nfreed all the node of the list successfully");
}
