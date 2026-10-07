#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node* head;
struct node* tail;
struct node* create_new_node(int data);

//insert list
void insert_node_at_head(int data);
void insert_node_at_tail(int data);

//delete list
void delete_node_at_tail();
void delete_node_at_head();

//sorting and traversing list
void sort_list();
void traverse_list();

int main(){
	//insert node
	insert_node_at_head(10);
	insert_node_at_head(20);
	insert_node_at_head(30);
	traverse_list();
	insert_node_at_tail(50);
	traverse_list();
	
	insert_node_at_tail(60);
	traverse_list();
	
	//perform sorting
	sort_list();
	
	//delete node
	printf("\nDelete node at tail");
	delete_node_at_tail();
	traverse_list();
	
	printf("\nDelete node at head");
	delete_node_at_head();
	traverse_list();
	
	printf("\nDelete node at head");
	delete_node_at_head();
	traverse_list();
	
	printf("\nDelete node at head");
	delete_node_at_head();
	traverse_list();
	
	printf("\nDelete node at head");
	delete_node_at_head();
	traverse_list();
	
	printf("\nDelete node at head");
	delete_node_at_head();
	traverse_list();
	
	free(head);
	free(tail);
}
struct node* create_new_node(int data){
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	if(new_node==NULL) {
		printf("memory allocation failed...");
		return NULL;
	}
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}
void insert_node_at_head(int data){
	struct node* new_node = create_new_node(data);
	if(new_node==NULL)	return;
	if (head==NULL){
		//linked list is empty
		head = new_node;
		tail = head;
	}else{
		new_node->next = head;
		head = new_node;
	}
	printf("\nInserted node(%d) at head successfully!!",data);
}
void insert_node_at_tail(int data){
	struct node* new_node = create_new_node(data);
	if(new_node==NULL)	return;
	if (head==NULL){
		//linked list is empty
		head = new_node;
		tail = head;
	}else{
		//add the new node to the tail and make the new node as tail
		tail->next = new_node;
		tail = new_node;
	}
	printf("\nInserted node(%d) at tail successfully!!",data);
}
void delete_node_at_head(){
	struct node* temp=head;
	if (head==NULL){
		//linked list is empty
		printf("\nLinked list is empty!!!...cannot perform delete.");
	}else{
		//delete node from head and make the next node as new head
		int deleted_data = head->data;
		if (head==tail){
			free(head);
			head = tail = NULL;
		}else{
			head = temp->next;
			free(temp);
		}
		printf("\nDeleted node(%d) from head successfully!!",deleted_data);
	}
}
void delete_node_at_tail() {
    struct node* temp = NULL;
    struct node* old_tail = tail;

    if (head == NULL) {
        printf("Linked list is empty!!!...cannot perform delete.");
    }
    else {
    	int deleted_data = head->data;
        // Only one node
        if (head == tail) {
            free(head);
            head = tail = NULL;
        }
        else {
            // Move to the node before tail
            temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }

            // Make temp the new tail
            tail = temp;
            tail->next = NULL;

            // Free the old tail
            free(old_tail);
        }
        printf("\nDeleted node(%d) from head successfully!!",deleted_data);
    }
}
void sort_list(){
	struct node* temp = head;
	while(temp!=NULL){
		struct node* next_node = temp->next;
		if(next_node==NULL) break;
		//check if the data (curr_node < next_node) else swap ?check ascending
		if (temp->data > next_node->data){
			//swap to make it ascending
			int temp_data = next_node->data;
			next_node->data = temp->data;
			temp->data = temp_data;
			
			//after swapping set the temp node to head
			temp = head;
		}else{
			//move to next node
			temp = temp->next;
		}
		
	}
	printf("\nSorting completed...");
	traverse_list();
}
void traverse_list(){
	struct node* temp = head;
	if (head==NULL){
		printf("\nList (Head=NULL,Tail=NULL) [ empty list ]");
	}else{
		printf("\nList (Head=%d,Tail=%d)[",head->data,tail->data);
		while(temp!=NULL){
			printf("%d->",temp->data);
			temp = temp->next;	
		}
		printf("null]\n");
	}
}

