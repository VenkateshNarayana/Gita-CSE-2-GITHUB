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

struct node* create_node(int,int); //param1 = data for storing the coefficient (information part1),param2 = data for storing the exponent (information part1)
//insert operations - at tail
void insert_at_tail(struct node** head,struct node** tail, int,int);     //param1 = data for storing the coefficient (information part1),param2 = data for storing the exponent (information part1)
void polynomial_addition(struct node* p_head,struct node* p_tail,struct node* q_head,struct node* q_tail);

//traverse operation - traverse from head to tail
void traverse_list(struct node* head);   //traverse the list from head to tail
void free_list(struct node* head);       //free the linked list if it is not empty using free() function
int main(){
	struct node* p_head=NULL; //track the first node polynomial p
	struct node* p_tail=NULL; //track the last node polynomial p

	//create the polynomial = 7X^2 + 7X + 7
	insert_at_tail(&p_head,&p_tail,7,2);
	insert_at_tail(&p_head,&p_tail,7,1);
	insert_at_tail(&p_head,&p_tail,7,0);
	traverse_list(p_head);
	
	struct node* q_head=NULL; //track the first node polynomial q
	struct node* q_tail=NULL; //track the last node of polynomial q
	
	//create another polynomia q(x) = 5X^2 + 3X + 8
	insert_at_tail(&q_head,&q_tail,5,2);
	insert_at_tail(&q_head,&q_tail,3,1);
	insert_at_tail(&q_head,&q_tail,8,0);
	traverse_list(q_head);
	
	//perform the polynomial addition
	polynomial_addition(p_head,p_tail,q_head,q_tail);
	
	free_list(p_head);
	free_list(q_head);
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

void insert_at_tail(struct node** head,struct node** tail, int coeff,int exp){
	//create the new node
	struct node* new_node = create_node(coeff,exp);
	if(new_node==NULL) return; //memory allocation failed dont proceed
	if(*tail==NULL){
		*tail = new_node;
		*head = *tail; //because single node we will have our head and tail pointing to the same new node
	}else{
		
		(*tail)->next = new_node; //point current tail to new node
		*tail = new_node;          //move the tail to new node
	}
	printf("\nInserted term at tail successfully");
}
void polynomial_addition(struct node* p_head,struct node* p_tail,struct node* q_head,struct node* q_tail){
	struct node* res_head=NULL;
	struct node* res_tail=NULL;
	while(p_head!=NULL && q_head!=NULL){
		if(p_head->exp == q_head->exp){
			int coeff = p_head->coeff + q_head->coeff;
			int exp   = p_head->exp;
			insert_at_tail(&res_head,&res_tail,coeff,exp);
			p_head = p_head->next; //move the p_head to next node
			q_head = q_head->next; //move the q_head to next node 
		}else if(p_head->exp > q_head->exp){
			insert_at_tail(&res_head,&res_tail,p_head->coeff,p_head->exp);
			p_head = p_head->next; //move the p_head to next node
		}else{
			insert_at_tail(&res_head,&res_tail,q_head->coeff,q_head->exp);
			q_head = q_head->next; //move the q_head to next node
		}
	}
	//Any leftovers from p or q will be inserted into res
	while(p_head!=NULL){
		insert_at_tail(&res_head,&res_tail,p_head->coeff,p_head->exp);
		p_head = p_head->next; //move the p_head to next node
	}
	while(q_head!=NULL){
		insert_at_tail(&res_head,&res_tail,q_head->coeff,q_head->exp);
		q_head = q_head->next; //move the q_head to next node
	}
	//display the result polynomial
	traverse_list(res_head);
	free_list(res_head);
}

void traverse_list(struct node* head){
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
void free_list(struct node* head){
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
