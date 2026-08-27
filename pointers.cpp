/*1. Write a program to print the value and address of a variable using a pointer.
2. Swap two numbers using pointers.
*/
#include<stdio.h> //preprocessor directives
//global declarations 
void swap(int,int);
void swap_by_ref(int*,int*);
int main(){ //main function
	int x; //basic datatype x of integer type
	int* ptrx;//pointer variable ptrx which can store address of what type(integer only)
	x = 10;
	printf("\n%d is value of x",x);
	ptrx = &x; //storing the address of x in ptrx
	printf("\n%p is address of x",&x);
	printf("\n%p is value of ptrx",ptrx);//print the address of the variable x
	
	//purpose of pointer
	printf("\n%d is the value of the address variable stored in pointer ptrx.",*ptrx); //dereference operator *
	*ptrx=20;//you can use pointer to access and manipulate the values of variable it store
	printf("\n%d is the value of x after manipulation using ptrx.",x); 
	
	//swap 2 numbers
	int y=40;
	printf("\nx=%d y=%d are the values before swap.",x,y); 
	swap(x,y);
	printf("\nx=%d y=%d are the values after swap.",x,y);
	swap_by_ref(&x,&y);//send the addresses as arguments(becuase its a pointer)
	printf("\nx=%d y=%d are the values after swap.",x,y);

	return 0;//this is for main
}
//funtion definitions
void swap_by_ref(int* x, int* y){
	int temp;
	temp = *y;
	*y = *x;
	*x = temp;
}
void swap(int x, int y){
	int temp;
	temp = y;
	y=x;
	x=temp;
	
}

