/* Single Linked List - It is a Linear data structure which stores the elements as nodes which is scattered in memory & connected
						using pointers.
   Anatomy of Node   -  A node consists of 2 parts(first part is data and second is reference variable(pointer) which can store 
   						the address of another node
						1.DATA field 
						2.NEXT pointer
  HOW do we create a node? - We will use user defined data type (struct) to create our nodes.
  	struct node{
	  int data;
	  struct node* next;
    }
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int          data; //this will store the data part
	struct node* next; //this is a pointer variable which will store the address of another node
};
struct node* head=NULL; //track the first node
struct node* tail=NULL; //track the last node

struct node* create_node(int); //param1 = input data for storing the data(information part1)
//insert operations - at head, at position, at tail
void insert_at_head(int);     //param1 = input data for storing the data(information part1)
void insert_at_tail(int);     //param1 = input data for storing the data(information part1)

//delete operations - at head, at position, at tail
void delete_at_head();        //it will remove the current head and move the head to next node
void delete_at_tail();        //it will remove the current tail and move the tail to previous node

//traverse operation - traverse from head to tail
void traverse_list();

int main(){
	
	//create the linked list using insert at head
	insert_at_head(10);
	traverse_list();
	insert_at_head(20);
	traverse_list();
	
	//create list using insert at tail
	insert_at_tail(30);
	traverse_list();
	insert_at_tail(50);
	traverse_list();
	
	//perform delete at head
	delete_at_head();
	traverse_list();
	
	//perform delete at tail
	delete_at_tail();
	traverse_list();
	
	return 0; //return main
	
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
void insert_at_head(int input_data){
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
	printf("\nInserted %d at head successfully",input_data);
}
void insert_at_tail(int input_data){
	//crate the new node
	struct node* new_node = create_node(input_data);
	if(new_node==NULL) return; //memory allocation failed dont proceed
	if(tail==NULL){
		tail = new_node;
		head = tail;    //because single node we will have our head and tail pointing to the same new node
	}else{
		tail->next = new_node; //point current tail to new node
		tail = new_node;       //move the tail to new node
	}
	printf("\nInserted %d at tail successfully",input_data);
}
void delete_at_head(){
	//step0 : check if the linked is empty or not
	if(head==NULL){
		printf("\nList is empty ...cannot perform delete operation");
		return;
	}
	
	//step1 : store the head in a temp
	struct node* temp = head;
	//step2 : move the head to next node
	head = head->next;
	//step3 : free the temp
	free(temp);
	printf("\nDeleted node at head successfully");
}
void delete_at_tail(){
	struct node* temp = NULL;
	//step0 : check if the linked is empty or not
	if(head==NULL){
		printf("\nList is empty ...cannot perform delete operation");
		return;
	}
	//check if there is only 1 node left
	if(head==tail){
		temp = tail; //store the head/tail in a temp
		tail = head = NULL; //delete the node
		free(temp);  //free the temp
	}else{
		//if head and tail are not same it means there is more than 1 node available 
		//step1 : move to one node before tail & store it in a temp
		temp = head;
		while(temp->next!=tail){
			temp=temp->next;
		}
		//node before tail
//		printf("\nNode before tail=%d",temp->data);
		
		//step2 : store the tail in another pointer old_tail
		struct node* old_tail = tail;
		
		//step3 : move the tail to one node before
		tail = temp;
		tail->next = NULL;//point the next to NULL since it has become the tail node
		
		//step4 : free the old tail
		free(old_tail);
	}
	printf("\nDeleted node at tail successfully");
}

void traverse_list(){
	struct node* temp;
	
	if (head==NULL){
		printf("\nMy Linked list(head=NULL,tail=NULL)[ empty list]");
		return;
	}
	temp = head; //store head in temp so that we can traverse till tail from head
	printf("\nMy Linked list(head=%d,tail=%d)[",head->data,tail->data);
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp = temp->next;
	}
	printf("null]");
}
