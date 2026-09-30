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
void polynomial_multiply(struct node* p_head,struct node* p_tail,struct node* q_head,struct node* q_tail);

//traverse operation - traverse from head to tail
void traverse_list(struct node* head);   //traverse the list from head to tail
void free_list(struct node* head);       //free the linked list if it is not empty using free() function
int main(){
	struct node* p_head=NULL; //track the first node polynomial p
	struct node* p_tail=NULL; //track the last node polynomial p

	//create the polynomial = 5X^2 + 3X + 2
	insert_at_tail(&p_head,&p_tail,5,2);
	insert_at_tail(&p_head,&p_tail,3,1);
	insert_at_tail(&p_head,&p_tail,2,0);
	traverse_list(p_head);
	
	struct node* q_head=NULL; //track the first node polynomial q
	struct node* q_tail=NULL; //track the last node of polynomial q
	
	//create another polynomia q(x) = 2X + 5
	insert_at_tail(&q_head,&q_tail,2,1);
	insert_at_tail(&q_head,&q_tail,5,0);
	traverse_list(q_head);
	
	//perform the polynomial addition
//	polynomial_addition(p_head,p_tail,q_head,q_tail);
	polynomial_multiply(p_head,p_tail,q_head,q_tail);
	
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
		//if the new node has the same exponenet then add the coeffient to existing term(node)
		struct node* temp = *head;
		while(temp!=NULL){//traverse from head to NULL to find if it has any node with same exponent
			if(temp->exp==new_node->exp){
				//add the coefficient
				temp->coeff  = temp->coeff + new_node->coeff;
				break;
			}
			temp = temp->next; //move to next node(term)
		}
		if (temp==NULL){//when the exponent is not found then add to tail
			(*tail)->next = new_node; //point current tail to new node
			*tail = new_node;         //move the tail to new node
		}
	}
	printf("\nInserted term(%d,%d) at tail successfully",coeff,exp);
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
void polynomial_multiply(struct node* p_head,struct node* p_tail,struct node* q_head,struct node* q_tail){
	struct node* res_head=NULL;
	struct node* res_tail=NULL;
	struct node* temp1 = p_head;
	struct node* temp2 = q_head;
	
	while(temp1!=NULL){
		temp2 = q_head; //reset the temp2 to point to q(head)
		while(temp2!=NULL){
			//do the mulitplication of terms of p with all terms of q
			int coeff = temp1->coeff * temp2->coeff;
			int exp   = temp1->exp   + temp2->exp; //when base are same powers get added
			insert_at_tail(&res_head,&res_tail,coeff,exp);
			temp2=temp2->next; //move to next node of q
		}
		temp1= temp1->next;    //move to next node of p
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
