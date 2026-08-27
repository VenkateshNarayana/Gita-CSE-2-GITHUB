/* We have added this in GITHUB Repository so that live updates can be saved directly to github using local
*/
#include<stdio.h>
void printArray(int[],int);
int findLargestElement(int[],int);
int sumArray(int[],int);
void countEvenOdd(int[],int);

int main(){
	int arr3[5];//3rd way - compiler automatically calculates the size
	int size = sizeof(arr3)/sizeof(arr3[0]); //sizeof(int);
	//accept from user input values
	printf("Enter %d elements:\n",size);
	for(int i=0;i<size;i++){
		printf("Enter the data for %d element:",i+1);
		scanf("%d",&arr3[i]);
	}
	printf("\nSize of arr3 =%d \n",size);
	printArray(arr3,size); //function call
	
	printf("\nLargest Element=%d",findLargestElement(arr3,size));
	printf("\nSum of all Element=%d",sumArray(arr3,size));
	
	countEvenOdd(arr3,size);//function call to display count of even and odd
}
//funciton definition
int findLargestElement(int arr[],int size){
	int max = arr[0];//assume 1st element to be largest
	for(int i=1;i<size;i++){
		if(arr[i]>max){
			max = arr[i];//discard old value of max and take this as new max
		}
	}
	return max;
}
int sumArray(int arr[],int size){
	int sum=0;
	for(int i =0;i<size;i++){
		sum+=arr[i]; //sum
	}
	return sum;
}
void countEvenOdd(int arr[],int size){
	int evenCounter=0;
	int oddCounter=0;
	for(int i =0;i<size;i++){
		if(arr[i]%2==0){
			evenCounter++;//increment the even count
		}else{
			oddCounter++;//increment the odd count
		}
	}
	printf("\nEven count=%d,Odd count=%d",evenCounter,oddCounter);
}
void printArray(int arr[],int size){

	for(int i =0;i<size;i++){
		printf("%d ",arr[i]); //random access using index
	}
}
