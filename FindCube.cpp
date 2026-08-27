/* program to cube the number */
#include<stdio.h>
int findCube(int);
void isSpecialNumber(int);
int main(){
	int num;
	printf("Enter the number:");
	scanf("%d",&num);
	printf("Cube=%d",findCube(num));
	isSpecialNumber(num);
	
	return 0;//for the main
}
int findCube(int num){
	return (num*num*num);
}
void isSpecialNumber(int num){
	//extract the digits
	int sumDigit = 0;
	int prdDigit = 1;
	int origNum = num;
	while(num!=0){
		int digit = num%10;
		sumDigit += digit; //sumDigit = sumDigit + digit
		prdDigit *= digit; //prdDigit = prdDigit + digit
		num/=10; //num = num /10
	}
	//outside the while value of num=0
	if((sumDigit+prdDigit)==origNum){
		printf("\nITS SPECIAL!!!");
	}else{
		printf("\nSORRY! NUMBER IS NOT SPECIAL");
	}
}
