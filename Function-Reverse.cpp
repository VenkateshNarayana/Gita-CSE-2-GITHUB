/*
Function for reversing digit and check for palindrome
*/
#include<stdio.h>
int reverseNumber(int);
#include <conio.h>
int main(){
	char ch;
	int num;
	do{
		printf("\nEnter the number:");
		scanf("%d",&num);
		printf("\nReverse number =%d",reverseNumber(num));
		
		printf("\nDo you wish to continue?");
	    ch = getch();
	    printf("%c",ch);
	}while(ch=='y'||ch=='Y');
	
	return 0;
}
int reverseNumber(int num){
	int reverse=0;
	while(num>0){
		int digit = num%10;
		reverse = reverse*10 + digit;
		num /=10; 
	}
	return reverse;
}
