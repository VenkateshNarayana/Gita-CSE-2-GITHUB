/*3. Access array elements using a pointer.
*/
#include<stdio.h> //preprocessor directives
//global declarations 

int main(){ //main function
	int arr[5]={21,22,23,24,25}; //derived datatype array 
	int* ptr_arr; //derived datatype - pointer is used to store address
	ptr_arr = &arr[0];//storing the base address
//	printf("\n%d is the address of 1st element ptr_arr", (ptr_arr+1));
	printf("\nAddresses of all the elements using pointer arithmetics");
	for(int i=0;i<5;i++){
		printf("\n%d is the address", (ptr_arr+i));	
	}
	
	printf("\nAddresses of all the elements using array name ");
	for(int i=0;i<5;i++){
		printf("\n%d is the address ", (arr+i));	
	}
	
	printf("\n%p is the address of 0th element(base address)",&arr[0]);
	printf("\n%d is the value stored in base address",*ptr_arr); //use the dereference operator to get the value
	//access the value of base address
	printf("\nValues of all the elements using pointer variable & arithmetics");
	for(int i=0;i<5;i++){
		printf("\n%d is the value stored in address", *(ptr_arr+i));	
	}
	
	printf("\nValues of all the elements using array name & pointer arithmetics");
	for(int i=0;i<5;i++){
		printf("\n%d is the value stored in address", *(arr+i));	
	}	
	return 0;
}
//function definitions
