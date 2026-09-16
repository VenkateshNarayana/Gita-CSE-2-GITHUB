/*DeQue(double ended queue) - Principle used for data management is FIFO- first in first out
  Operations - 1.add_first    - insertion at the front(head) using front index
  			   2.add_last     - insertion at the rear(tail) using rear index
			   3.remove_first - deletion at the front(head) using front index
  			   4.remove_last  - deletion at the rear(tail) using front index
			   5.peek_front - get the first element
  			   6.peek_rear  - get the last element
  			   7.is_full    - checks if rear has reached its max_size or not
  			   8.is_empty   - checks if Q is empty or not
  			   9.traverse   - display all the elements in the Q from head till tail,display the size also
  			   
*/
#include <stdio.h>
#define MAX_SIZE 5
int front = -1; //you have to initialize this to -1
int rear  = -1; //you have to initialize this to -1
//enque
void add_first(int[],int); //param1= array name ;param2 = value
void add_last(int[],int); //param1= array name ;param2 = value
//deque
int  remove_first(int[]);     //param1= array name 
int  remove_last(int[]);     //param1= array name 
//traversing
void traverse(int[]);    //param1= array name
//peek
int peek_front(int[]);   //param1= array name
int peek_rear(int[]);    //param1= array name
//check overflow and undeflow
int is_full();           //return 1 if rear reaches MAX_SIZE-1 else 0 
int is_empty();          //return 1 if front>rear else 0 


int main(){
	int queue[MAX_SIZE]={0}; //declare with MAX_SIZE & initialize Q to zero.
	//enque operations
	add_first(queue,10); //insert at front
	traverse(queue);
	add_first(queue,20); //insert at front
	traverse(queue);
	add_last(queue,30);  //insert at rear
	traverse(queue);
	add_last(queue,40);  //insert at rear
	traverse(queue);
	add_last(queue,50);  //insert at rear
	traverse(queue);
	add_last(queue,60); //rear goes out of bound index - will this work? NO-becuase Q Overflow
	traverse(queue);
	
	//peek operations
	printf("\nWho is in the front? %d",peek_front(queue));
	printf("\nWhat is in the tail? %d",peek_rear(queue));
	
	//perform dequeue
	int dq_elt = remove_first(queue); //remove element from head(front)
	printf("%s",dq_elt==-1?"":"\nDequeued from front successfully\n");
	traverse(queue);
	
	//peek operations
	printf("\nWho is in the front? %d",peek_front(queue));
	printf("\nWhat is in the tail? %d",peek_rear(queue));
	
	dq_elt = remove_last(queue); //remove element from tail(rear)
	printf("%s",dq_elt==-1?"":"\nDequeued from rear successfully\n");
	traverse(queue);
	
	//peek operations
	printf("\nWho is in the front? %d",peek_front(queue));
	printf("\nWhat is in the tail? %d",peek_rear(queue));
	
	
	return 0;
}
int is_full(){           //return 1 if rear reaches MAX_SIZE-1 else 0 
	return(rear==MAX_SIZE-1);//overflow
} 
int is_empty(){         //return 1 if front>rear else 0 
	return(front==-1); //underflow
}
void add_first(int q[],int value){ //param1= array name ;param2 = value
	if(is_full()){
		printf("Q is FULL...cannot enqueue %d!!!\n",value);
		return; //return so that value is not stored
	}
	//when q is empty front and rear will be at -1
	if(front==-1){
		front = 0;
	}
    //insert at front using right shifting
    for(int i=rear;i >=front; i--){
    	q[i+1] = q[i];//right shifting formula
	}
	q[front]=value; //always insert value at 0 index
	rear++ ;        //rear will also move by 1
}
void add_last(int q[],int value){ //param1= array name ;param2 = value
	if(is_full()){
		printf("Q is FULL...cannot enqueue %d!!!\n",value);
		return; //return so that value is not stored
	}
	//when q is empty front and rear will be at -1
	if(front==-1){
		front = 0;
	}
	q[++rear] = value; //insert at rear(tail)
}
int  remove_first(int q[]){    //param1= array name
	if(is_empty()){
		printf("Q is EMPTY...cannot perform dequeue!!!\n");
		return -1; //return -1 so that value is not stored
	}
	int dq_item = q[front]; //first store the value at index 0 
	//remove from front using left shifting
	for(int i=front;i<rear; i++){
    	q[i] = q[i+1];//left shifting formula
	}
	q[rear--]=0; //set the last index value to 0;
	if (front==rear){
		//reset the queue
		front = -1;
		rear  = -1;
	}
	return dq_item;
}
int  remove_last(int q[]){    //param1= array name
	if(is_empty()){
		printf("Q is EMPTY...cannot perform dequeue!!!\n");
		return -1; //return -1 so that value is not stored
	}
	int dq_item = q[front]; //first store the value at index 0 
	rear--; //decrement the rear index by 1;rear = rear - 1; --rear ; rear--;
	if (front==rear){
		//reset the queue
		front = -1;
		rear  = -1;
	}
	return dq_item;
}
void traverse(int q[]){    //param1= array name
	printf("Queue (Curr Size:%d): [",(rear+1 - front));
	for(int i=front;i<=rear;i++){
		printf("%d ",q[i]);
	}
	printf("]\n");
}
int peek_front(int q[]){   //param1= array name
	return q[front]; //return the first element
}
int peek_rear(int q[]){    //param1= array name
	return q[rear]; //return the last element
}

