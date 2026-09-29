/* Double Linked List - It is a Linear data structure which stores the elements as nodes which is scattered in memory & connected
						using pointers.
   Anatomy of Node   -  A node consists of 2 parts(first part is data and second is reference variable(pointer) which can store 
   						the address of another node
						1.DATA field 
						2.1NEXT pointer (store next node address)
						2.2PREV pointer (store previous node's address)
						
  HOW do we create a node? - We will use user defined data type (struct) to create our nodes.
  	struct node{
	  int data;
	  struct node* next;
	  struct node* prev;
    }
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int          data; //this will store the data part
	struct node* next; //this is a pointer variable which will store the address of next node
	struct node* prev; //this is a pointer variable which will store the address of next node
	
};
struct node* head=NULL; //track the first node
struct node* tail=NULL; //track the last node

struct node* create_node(int); //param1 = input data for storing the data(information part1)
//insert operations - at head, at position, at tail
void insert_at_head(int);         //param1 = input data for storing the data(information part1)
void insert_at_tail(int);         //param1 = input data for storing the data(information part1)
void insert_at_position(int,int); //param1 =  node value ; param2= input value

//delete operations - at head, at position, at tail
void delete_at_head();        //it will remove the current head and move the head to next node
void delete_at_tail();        //it will remove the current tail and move the tail to previous node

//traverse operation - traverse from head to tail
void traverse_head();   //traverse the list from head to tail (forward)
void traverse_tail();   //traverse the list from tail to head (reverse)
void free_list();       //free the linked list if it is not empty using free() function
int main(){
	
	//create the linked list using insert at head
	insert_at_head(10);
	traverse_head();
	insert_at_head(20);
	traverse_head();
	
	//create list using insert at tail
	insert_at_tail(30);
	traverse_tail();
	insert_at_tail(50);
	traverse_tail();
	traverse_head();
	
	//insert at postion
	insert_at_position(30,25); //insert before node 30 new node 25
	traverse_tail();
	traverse_head();
	
	
	//perform delete at head
	delete_at_head();
	traverse_head();
	traverse_tail();
	
	//perform delete at tail
	delete_at_tail();
	traverse_head();
	traverse_tail();
	
	free_list();
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
	new_node->next = NULL;        //store null in next as this is a brand new node
	new_node->prev = NULL;        //strore null in previou as this is a brand new node
	
	return new_node;
}
void insert_at_head(int input_data){
	//crate the new node
	struct node* new_node = create_node(input_data);
	if(new_node==NULL) return; //memory allocation failed dont proceed
	if(head==NULL){ //linked list is empty
		head = new_node;
		tail = head;    //because single node we will have our head and tail pointing to the same new node
	}else{//linked list is not empty
		new_node->next = head;      //point new node to current head
		head->prev     = new_node;  //point the old head's prev to new node 
 		head           = new_node;  //move the old head to new node
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
		new_node->prev = tail; //point new node's prev to old tail
		tail = new_node;       //move the old tail to new node( to make it new tail)
	}
	printf("\nInserted %d at tail successfully",input_data);
}
void insert_at_position(int node_value,int input_data){
	if(head==NULL){
		printf("\nList is empty..could not find the position(%d)",node_value);
	}else if(head->data==node_value){
		insert_at_head(input_data);
	}else{
		//step1: traverse and search for the node_value
		struct node* temp=head;
		while(temp!=NULL){
			if(temp->data == node_value) break;
			temp = temp->next;
		}
		if(temp==NULL){
			printf("\nCould not find position(%d) in the list",node_value);
		}else{
			//if node is found
			//create the new node
			struct node* new_node = create_node(input_data);
			if(new_node==NULL) return; //memory allocation failed dont proceed
			//step2: store address of temp in new node's next 
			new_node->next = temp;
			//step3: store address of temp's prev in new node's prev 
			new_node->prev = temp->prev;
			//step4: store temp->prev in prev_node and update temp->prev to new node
			struct node* prev_node = temp->prev;
			temp->prev = new_node;
			//step5: store the new node address in prev_node's next
			prev_node->next = new_node;
			printf("\nInserted %d at position(%d) successfully",input_data,node_value);
		}
	}
}
void delete_at_head(){
	//step0 : check if the linked is empty or not
	if(head==NULL){
		printf("\nList is empty ...cannot perform delete operation");
		return;
	}//check if there is only 1 node left
	int deleted_node = head->data;
	struct node* temp=NULL;
	if(head==tail){
		temp = head; //store the head/tail in a temp
		tail = head = NULL; //make the list empty
		free(temp);  //free the temp
	}else{
		//step1 : store the head in a temp
		struct node* temp = head;
		//step2 : move the head to next node
		head       = head->next;
		head->prev = NULL; // since this is my new head(the prev node is always NULL)
		
		//step3 : free the temp
		free(temp);
	}
	printf("\nDeleted node(%d) at head successfully",deleted_node);
}
void delete_at_tail(){
	struct node* temp = NULL;
	//step0 : check if the linked is empty or not
	if(head==NULL){
		printf("\nList is empty ...cannot perform delete operation");
		return;
	}
	int deleted_node = tail->data;
	//check if there is only 1 node left
	if(head==tail){
		temp = tail; //store the head/tail in a temp
		tail = head = NULL; //make the linked list empty
		free(temp);  //free the temp
	}else{
		//step2 : store the tail in temp
		struct node* temp = tail;
		//step3 : move the tail to previou node
		tail = tail->prev;
		tail->next = NULL;//point the next to NULL since it has become the tail node
		//step4 : free the old tail
		free(temp);
	}
	printf("\nDeleted node(%d) at tail successfully",deleted_node);
}

void traverse_head(){
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
	printf("null]\n");
}
void traverse_tail(){
	struct node* temp;
	
	if (tail==NULL){
		printf("\nMy Linked list(head=NULL,tail=NULL)[ empty list]");
		return;
	}
	temp = tail; //store head in temp so that we can traverse till tail from head
	printf("\nMy Linked list(tail=%d,head=%d)[",tail->data,head->data);
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp = temp->prev;
	}
	printf("null]\n");
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
