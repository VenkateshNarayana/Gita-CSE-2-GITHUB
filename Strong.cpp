/* check if a number is armstrong or not
*/
#include<stdio.h>
int factorial(int);
int checkStrong(int);
int add2numbers(int a,int b);//function declare -1st step
int main(){
	int num;
	printf("Enter the number:");
	scanf("%d",&num);
	printf("%s",(checkStrong(num)?"IT IS STRONG":"NOT STRONG"));
	int a=20,b=10;
	printf("\nSum of 2 numbers =%d",add2numbers(a,b));//function call - 3rd step
	return 0;//for int main
}
//function definition - 2nd step
int add2numbers(int a, int b){
	int sum;
	sum = a+b;
	return sum;	
}
int checkStrong(int num){
	int fact;
	int temp=num;
	int sumFact=0;
	while(num!=0){
		int digit = num %10;
		num/=10;
		fact= factorial(digit);
		sumFact += fact; //sumFact = sumFact+fact
	}
	if(sumFact==temp){
		return 1;
	}else{
		return 0;
	}
}
int factorial(int num){
	int fact=1;
	for(int i=1;i<=num;i++){
		fact *=i; //fact = fact * i
	}
	return fact;
}
