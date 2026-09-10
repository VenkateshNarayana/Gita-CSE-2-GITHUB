/*Circular Queue - It is LDS where data management is managed using the FIFO (first in first out) principle
  Operations - 1.enqueue     - add the element in the rear circularly
               2.dequeue     - delete the element from the front circularly
               3.peek_front  - get the first element of the Q
               4.peek_rear   - get the last element of the Q
               5.is_empty    - return 1 when front == -1 else 0
               6.is_full     - return 1 when (rear + 1) % MAX_SIZE == front
               7.traverse    - display the Q elements from front to rear circularly with current size
*/
#include<stdio.h>
#define MAX_SIZE 5
int front = -1; // initialized to -1 to denote an empty circular queue
int rear = -1;  // initialized to -1 to denote an empty circular queue

int dequeue(int[]);      //param1=arrayname 
void enqueue(int[],int); //param1=arrayname ;param2=value
int is_full();           //return 1 when (rear + 1) % MAX_SIZE == front  
int is_empty();          //return 1 when front == -1 else 0
void traverse(int[]);    //param1=arrayname 
int peek_front(int[]);   //param1=arrayname ; return the first element of the Q
int peek_rear(int[]);    //param1=arrayname ; return the last element of the Q

int main(){
	int queue[MAX_SIZE]={0}; //declare and initialize the Q with zero
	
	//enqueue
	enqueue(queue,10);
	traverse(queue);
	enqueue(queue,20);
	traverse(queue);
	enqueue(queue,30);
	traverse(queue);
	enqueue(queue,40);
	traverse(queue);
	enqueue(queue,50);
	
	traverse(queue);
	enqueue(queue,60); //will this be added to Q? (Overflows because queue is full)
	
	traverse(queue);
	//peek front and rear
	printf("\nWho is in the front? %d",peek_front(queue));
	printf("\nWho is in the back? %d",peek_rear(queue));
	
	
	int dq_elt = dequeue(queue); //remove element from front
	printf("%s",(dq_elt== -1)? "" : "\nDequeued successfully\n");
	traverse(queue);
	
	printf("\nWho is in the front? %d",peek_front(queue));
	printf("\nWho is in the back? %d\n",peek_rear(queue));
	
	dq_elt = dequeue(queue); //remove element from front
	printf("%s",(dq_elt== -1)? "" : "\nDequeued successfully\n");
	traverse(queue);
	
	dq_elt = dequeue(queue); //remove element from front
	printf("%s",(dq_elt== -1)? "" : "\nDequeued successfully\n");
	traverse(queue);
	
	dq_elt = dequeue(queue); //remove element from front
	printf("%s",(dq_elt== -1)? "" : "\nDequeued successfully\n");
	traverse(queue);
	
	dq_elt = dequeue(queue); //remove element from front
	printf("%s",(dq_elt== -1)? "" : "\nDequeued successfully\n");
	traverse(queue);
	
	dq_elt = dequeue(queue); //remove element from front
	printf("%s",(dq_elt== -1)? "" : "\nDequeued successfully\n");
	traverse(queue);
	
	
	enqueue(queue,60); //yes we can add why? because it is circular queue no wastage
	traverse(queue);
	
	
	return 0; //for the main
}

int peek_front(int q[]){   //param1=arrayname ; return the first element of the Q
	if(is_empty()){
		return -1;
	}
	return q[front];
}

int peek_rear(int q[]){    //param1=arrayname ; return the last element of the Q
	if(is_empty()){
		return -1;
	}
	return q[rear];
}

int dequeue(int q[]){
	//check for underflow
	if(is_empty()){
		printf("\nQ underflow...cannot perform dequeue!!\n");
		return -1;
	}
	int dq_item = q[front];
	
	// If only one element was left, reset the queue to empty state
	if(front == rear){
		front = -1;
		rear = -1;
	} else {
		front = (front + 1) % MAX_SIZE; // move front circularly
	}
	return dq_item;
}

void traverse(int q[]){
	if(is_empty()){
		printf("Queue (CurrSize:0): []\n");
		return;
	}
	int size = (rear >= front) ? (rear - front + 1) : (MAX_SIZE - front + rear + 1);
	printf("Queue (CurrSize:%d): [", size);
	int i = front;
	while(1){
		printf("%d ", q[i]);
		if(i == rear) break;
		i = (i + 1) % MAX_SIZE;
	}
	printf("]\n");
}

int is_empty(){          //return 1 when front == -1 else 0
	return (front == -1);
}

int is_full(){           //return 1 when (rear + 1) % MAX_SIZE == front	
	return ((rear + 1) % MAX_SIZE == front);
}

void enqueue(int q[], int value){
	//check for overflow
	if(is_full()){
		printf("\nQ overflow...cannot perform enqueue of %d\n", value);
		return; //do not proceed further
	}
	// If queue is empty, set front to 0
	if(front == -1){
		front = 0;
		rear  = 0;
	} else {
		rear = (rear + 1) % MAX_SIZE; // move rear circularly
	}
	q[rear] = value; // inserted value at rear index
}
