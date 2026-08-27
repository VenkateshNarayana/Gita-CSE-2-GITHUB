/*1. Allocate memory for 5 integers using malloc() and display them.
*/
#include<stdlib.h>
#include<stdio.h>
int main(){
	int*	ptr_mal_arr; //pointer??
	ptr_mal_arr = (int*) malloc(5*sizeof(int)); //allocation of memory done using malloc for 5 integers
	//check if the memory was allocated by operating system to the program or not
	if(ptr_mal_arr==NULL){
		printf("Memory allocation failed...");
		return 0;
	}
	
	//if memory is allocated properly
	for (int i=0;i<5;i++){
		*(ptr_mal_arr+i) = 0; //intialize to 0
		printf("%d ",*(ptr_mal_arr+i)); //displaying the allocated memory blocks
	}
	//free the memory after use to prevent memory leaks
	free(ptr_mal_arr);
	return 0; //for main function
}
