/* Application of LINKED LIST
   2.Building a Queue
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
//insert operations - at tail

void enqueue(int);     //param1 = input data for storing the data(information part1)

//delete operations - at head
void dequeue();        //it will remove the current head and move the head to next node

int is_empty();
void peek_front();
void peek_rear();

//traverse operation - traverse from head to tail
void traverse_list();   //traverse the list from head to tail
void free_list();       //free the linked list if it is not empty using free() function
int main(){
	//enqueue operations
	enqueue(10);
	enqueue(20);
	enqueue(30);
	
	traverse_list();
	
	//dequeue operations
	dequeue();
	traverse_list();
	
	
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
	new_node->next = NULL;        //fill null as this is a brand new node
	return new_node;
}
int is_empty(){
	return(head==NULL);
}
void peek_front(){
	if(is_empty()){
		printf("\nFront = NULL");
	}else{
		printf("\nFront = %d",head->data);
	}
}
void peek_rear(){
	if(is_empty()){
		printf("\nRear = NULL");
	}else{
		printf("\nRear = %d",tail->data);
	}
}
void enqueue(int input_data){
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
void dequeue(){
	//step0 : check if the linked is empty or not
	if(head==NULL){
		printf("\nQueue is empty ...cannot perform delete operation");
		return;
	}
	//step1 : store the head in a temp
	struct node* temp = head;
	int dq_item = head->data;
	//step2 : move the head to next node
	head = head->next;
	//step3 : free the temp
	free(temp);
	printf("\nRemoved %d from front successfully",dq_item);
}

void traverse_list(){
	struct node* temp;
	
	if (head==NULL){
		printf("\nMy Queue(front=NULL,rear=NULL)[ empty Q]");
		return;
	}
	temp = head; //store head in temp so that we can traverse till tail from head
	printf("\nMy Queue(front=%d,rear=%d)[",head->data,tail->data);
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
	printf("\nfreed all the node of the Queue successfully!!!");
}
