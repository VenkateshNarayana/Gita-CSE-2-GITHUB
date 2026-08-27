/*Demonstrate realloc() by increasing an array size*/
#include<stdlib.h>
#include<stdio.h>
int main(){
	int* ptr_cal_arr;
	//use calloc to dynamically create an memory block of 5 elements
	ptr_cal_arr = (int*) calloc(5, sizeof(int));
	if(ptr_cal_arr==NULL){
		printf("Memory allocation failed...");
		return 1;
	}
	//initiliase values
	for(int i=0;i<5;i++){
		*(ptr_cal_arr + i) = i; //assigning values to memory blocks
	}
	//use re-alloc to get more memory block
	ptr_cal_arr = (int*) realloc(ptr_cal_arr, 10*sizeof(int)); //increase to 10 from 5.
	if(ptr_cal_arr==NULL){
		printf("Memory reallocation failed...");
		return 1;
	}
	//print the new memory block with(new size=10)
	printf("\nPrinting Reallocated memory: ");
	for(int i=0;i<10;i++){
		printf("%d ",*(ptr_cal_arr + i));
	}
	//free the memory to prevent memory leaks
	free(ptr_cal_arr);
}

