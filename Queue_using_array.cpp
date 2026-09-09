/*Queue - Principle used for data management is FIFO- first in first out
  Operations - 1.enqueue - insertion at the tail
  			   2.dequeue - deletion at the front
  			   3.peek_front - get the first element
  			   4.peek_rear  - get the last element
  			   5.is_full    - checks if rear has reached its max_size or not
  			   6.is_empty   - checks if Q is empty or not
  			   7.traverse   - display all the elements in the Q from head till tail,display the size also
  			   
*/
#include <stdio.h>
#define MAX_SIZE 5
int front = 0 ; //you can keep -1 also but i chose 0
int rear  = -1; //you have to initialize this to -1

void enqueue(int[],int); //param1= array name ;param2 = value
int  dequeue(int[]);     //param1= array name 
void traverse(int[]);    //param1= array name
int peek_front(int[]);   //param1= array name
int peek_rear(int[]);    //param1= array name
int is_full();           //return 1 if rear reaches MAX_SIZE-1 else 0 
int is_empty();          //return 1 if front>rear else 0 


int main(){
	int queue[MAX_SIZE]={0}; //declare with MAX_SIZE & initialize Q to zero.
	enqueue(queue,10); //first element inserted in rear
	enqueue(queue,20);
	enqueue(queue,30);
	enqueue(queue,40);
	enqueue(queue,50);
	enqueue(queue,60); //rear goes out of bound index - will this work?
	traverse(queue);
	printf("\nWho is in the front? %d",peek_front(queue));
	printf("\nWhat is in the tail? %d",peek_rear(queue));
	
//	int dq_elt = dequeue(queue); //remove element from front
	printf("%s",dequeue(queue)==-1?"":"\nDequeued successfully\n");
	
	traverse(queue);
	enqueue(queue,60); //the queue has already reached its max capacity so cannot add
	traverse(queue);
		
	
	return 0;
}
void enqueue(int q[],int value){ //param1= array name ;param2 = value
	if(is_full()){
		printf("Q is FULL...cannot enqueue %d!!!\n",value);
		return; //return so that value is not stored
	}
	q[++rear] = value; //insert at tail
}
int  dequeue(int q[]){    //param1= array name
	if(is_empty()){
		printf("Q is EMPTY...cannot perform dequeue!!!\n");
		return -1; //return -1 so that value is not stored
	}
	int dq_item = q[front++]; //first store the value at index 0 and then increment the front by 1
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
int is_full(){           //return 1 if rear reaches MAX_SIZE-1 else 0 
	return(rear==MAX_SIZE-1);//overflow
} 
int is_empty(){         //return 1 if front>rear else 0 
	return(front>rear); //underflow
}
