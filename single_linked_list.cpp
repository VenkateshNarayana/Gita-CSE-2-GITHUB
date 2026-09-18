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

int main(){
	struct node node1, node2, node3, node4;
	node1.data = 10;
	node1.next = &node2; //store the address of next node - node2 and this will be my head
	
	node2.data = 20;
	node2.next = &node3; //store the address of next node - node3
	
	node3.data = 30;
	node3.next = &node4; //store the address of next node - node4
	
	node4.data = 40;
	node4.next = NULL; //store NULL because this is tail(last  node) 
	
	//traverse from head to tail
	printf("\nLinked list[");
	printf("%d->",node1.data);
	printf("%d->",node1.next->data);//node2 ka data hai isme
	printf("%d->",node1.next->next->data);//node3 ka data hai isme
	printf("%d->",node1.next->next->next->data);//node4 ka data hai isme
	printf("null]\n");
	
	struct node* temp;
	temp = &node1; //store head address
	printf("\nMy Linked list[");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("null]\n");
	
	
	return 0; //return main
	
}
