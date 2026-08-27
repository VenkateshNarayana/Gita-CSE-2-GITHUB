/*2.Use calloc() to create an array of 5 integers and display initial values.
*/
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
	printf("\nDisplaying the initialized vlaues of the memory block: ");
	//if memory is allocated successfully then display the elements 
	for(int i=0;i<5;i++){
		printf("%d-",(ptr_cal_arr+i));  //address
		printf("%d, ",*(ptr_cal_arr+i)); //value in that address
	}
	//free the memory to prevent memory leak
	free(ptr_cal_arr);
}

