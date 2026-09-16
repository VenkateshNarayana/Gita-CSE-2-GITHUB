/*Deque(Double Ended Queue) - It is  LDS where data management is managed using flexible insertion and deletion(both ends)
  Operations - 1.add_first    - add the element in the front(right shifting)
  			   2.add_last     - add the element in the rear	
  			   3.remove_first - delete the element from the front(left shifting)
               3.remove_last  - delete the element from the rear
               3.peek_front   - get the first element of the Q
               4.peek_rear    - get the last element of the Q
               5.is_empty     - return 1 front==-1 else 0
               6.is_full      - return 1 when rear reaches MAX_SIZE -1 of the  Q
               7.traverse     - display the Q elements from front(head) to rear(tail). display the current size(rear+1 - front)
         
*/
#include<stdio.h>
#define MAX_SIZE 5
int front = -1; //this is for tracking insertion from front
int rear  = -1; //this is for tracking insertion from rear
//dequeue
int remove_first(int[]);      //param1=arrayname 
int remove_last(int[]);      //param1=arrayname 

//enqueue
void add_first(int[],int); //param1=arrayname ;param2=value
void add_last(int[],int); //param1=arrayname ;param2=value
//traverse
void traverse(int[]);    //param1=arrayname 

//overflow and underflow check
int is_full();           //return 1 when rear reaches MAX_SIZE -1 of the  Q  
int is_empty();          //return 1 when front>rear else 0

//peek operations
int peek_front(int[]);   //param1=arrayname ; return the first element of the Q
int peek_rear(int[]);    //param1=arrayname ; return the last element of the Q

int main(){
	int queue[MAX_SIZE]={0};//declare and initialize the Q with zero
	
	//enqueue
	add_first(queue,10);
	traverse(queue);
	add_first(queue,20);
	traverse(queue);
	add_first(queue,30);
	traverse(queue);
	add_last(queue,40);
	traverse(queue);
	add_last(queue,50);
	traverse(queue);
	
	add_last(queue,60); //will this be added to Q?NO-becuase the Q is FULL
	traverse(queue);
	//peek front and rear
	printf("\nWho is in the front? %d",peek_front(queue));
	printf("\nWho is in the back? %d",peek_rear(queue));

	//	dequeue - from first
	printf("%s",(remove_first(queue)==-1)?"....":"\nPerformed dequeue from front(head) sucessfully!!!");
	//traversal
	traverse(queue);
	printf("\nWho is in the front? %d",peek_front(queue));
	printf("\nWho is in the back? %d",peek_rear(queue));
	
	
	//dequeue - from last
	printf("%s",(remove_last(queue)==-1)?"....":"\nPerformed dequeued from rear(tail) sucessfully!!!");
	//traversal
	traverse(queue);
	printf("\nWho is in the front? %d",peek_front(queue));
	printf("\nWho is in the back? %d",peek_rear(queue));
	
	return 0;//for the main
}
int is_empty(){         //return 1 when front==-1 else 0
	return(front==-1); //return 1 else 0
}
int is_full(){           //return 1 when rear reaches MAX_SIZE -1 of the  Q	
	return(rear==MAX_SIZE-1); //return 1 else 0
}
void add_first(int q[],int value){
	//check for is overflow
	if(is_full()){
		printf("\nQ overflow...cannot perform enqueue of %d",value);
		return; //do not proceed further
	}
	//check if its initial condition
	if(front==-1){
		front = 0;
	}else{
		//right shifting from right to left
		for(int i=rear;i>=front;i--){
			q[i+1] = q[i];
		}	
	}
	//insert the value at index 0
	q[front]=value; //inserted value at index 0
	rear++;         //increment rear by 1
}
void add_last(int q[],int value){
	//check for is overflow
	if(is_full()){
		printf("\nQ overflow...cannot perform enqueue of %d",value);
		return; //do not proceed further
	}
	//check if its initial condition
	if(front==-1){
		front = 0;
	}
	q[++rear]=value; //inserted value at index 0
}

int remove_first(int q[]){
	//check for underflow
	if(is_empty()){
		printf("\nQ underflow...cannot perform dequeue!!");
		return -1;
	}
	int dq_item=q[front];//store front value 
	//left shifting from left to right
		for(int i=front;i<rear;i++){
			q[i] = q[i+1];
		}
		q[rear] = 0;//make the last element 0
	rear--; //decrement the rear index by 
	if(front==rear){
		//reset the Q
		front = -1;
		rear  = -1;
	}
	return dq_item;
}
int remove_last(int q[]){
	//check for underflow
	if(is_empty()){
		printf("\nQ underflow...cannot perform dequeue!!");
		return -1;
	}
	int dq_item=q[rear--];//store rear value
	if(front==rear){
		//reset the Q
		front = -1;
		rear  = -1;
	}
	return dq_item;
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

void traverse(int q[]){
	printf("Queue (CurrSize:%d): [",(rear+1-front));
	for(int i=front;i<=rear;i++){
		printf("%d ",q[i]);
	}
	printf("]\n");
}


