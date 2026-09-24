/* Application of Linked List
   3.Evaluation of Polynomial Expressions
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int          coeff; //this will store the coeffecient part
	int          exp;   //this will store the exponent part
	struct node* next; //this is a pointer variable which will store the address of another node
};
struct node* head=NULL; //track the first node
struct node* tail=NULL; //track the last node

struct node* create_node(int,int); //param1 = data for storing the coefficient (information part1),param2 = data for storing the exponent (information part1)
//insert operations - at tail
void insert_at_tail(int,int);     //param1 = data for storing the coefficient (information part1),param2 = data for storing the exponent (information part1)

//traverse operation - traverse from head to tail
void traverse_list();   //traverse the list from head to tail
void free_list();       //free the linked list if it is not empty using free() function
int main(){
	//create the polynomial = 7X^2 + 7X + 7
	insert_at_tail(7,2);
	insert_at_tail(7,1);
	insert_at_tail(7,0);
	traverse_list();
	
	free_list();
	return 0; //return main
	
}
struct node* create_node(int coeff,int exp){
	//create the node using malloc 
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	
	if(new_node==NULL){
		printf("memory allocation failed....");
		return NULL;
	}
	new_node->coeff = coeff ; //fill the coeff from input value
	new_node->exp   = exp ;   //fill the exponent from input value
	new_node->next  = NULL;   //fill null as this is a brand new term
	return new_node;
}

void insert_at_tail(int coeff,int exp){
	//crate the new node
	struct node* new_node = create_node(coeff,exp);
	if(new_node==NULL) return; //memory allocation failed dont proceed
	if(tail==NULL){
		tail = new_node;
		head = tail;    //because single node we will have our head and tail pointing to the same new node
	}else{
		tail->next = new_node; //point current tail to new node
		tail = new_node;       //move the tail to new node
	}
	printf("\nInserted term at tail successfully");
}

void traverse_list(){
	struct node* temp;
	
	if (head==NULL){
		printf("\nMy Polynomial[ empty list]");
		return;
	}
	temp = head; //store head in temp so that we can traverse till tail from head
	printf("\nMy Polynomial[");
	while(temp!=NULL){
		
		printf("%d X^%d",temp->coeff,temp->exp); //7 X^2
		if (temp->next!=NULL) printf(" + ");
		temp = temp->next;
	}
	printf("]");
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
