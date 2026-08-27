#include<stdio.h>
void printArray(int[],int);
int main(){
	
	int arr1[5]; //1st way
	arr1[0]=10;
	arr1[1]=11;
	arr1[2]=12;
	arr1[3]=13;
	arr1[4]=14;
	printf("\nPrinting array using random access of individual elements:");

	printArray(arr1,5); //function call
	
	printf("\nPrinting array using for loop:");
	
	int arr2[5]={12,14,16,18,20};//2nd way

	printArray(arr2,5); //function call
		
	int arr3[]={10,20,30,40,50,60};//3rd way - compiler automatically calculates the size
	int size = sizeof(arr3)/sizeof(arr3[0]); //sizeof(int);
	printf("\nSize of arr3 =%d \n",size);
	printArray(arr3,size); //function call	
}
//funciton definition
void printArray(int arr[],int size){

	for(int i =0;i<size;i++){
		printf("%d ",arr[i]); //random access using index
	}
}
