/*Array operations 
-Insert - insert_at_end,insert_at_index 
-Delete - delete_at_end,delete_at_index
-Modify - modify_at_index
-Traverse - linear traversal
Adding to GITHUB so that all code is synched up there
*/
#include<stdio.h>
#define MAX 5
int curr_index = 0;
void insert_at_begin(int[],int);//param1 - array; param2-value to input
void insert_at_end(int[],int);//param1 - array; param2-value to input
void insert_at_index(int[],int,int);//param1 - array; param2-(index) ;param3- value

void display_array(int[]);//param1 - array; - traversal of array

void delete_at_index(int[],int);//param1 - array;param2-index 
void delete_at_end(int[]);//param1 - array; deleting from end always O(1)
void delete_at_begin(int[]);//param1 - array;

int get_array_index_from_user();
int get_array_value_from_user();
void show_menu(); //show options to perform array operations with last option to exit
int main(){
	int my_arr[MAX];
	int choice=0;
	int value,index;
	do{
	//show menu
		show_menu();
		scanf("%d",&choice);
		
		switch(choice){
			case 1: value = get_array_value_from_user();
					insert_at_begin(my_arr,value);
					break;
			case 2: value = get_array_value_from_user();
			        index = get_array_index_from_user();
					insert_at_index(my_arr,index, value);
					break;
			case 3: value = get_array_value_from_user();
					insert_at_end(my_arr, value);
					break;
			case 4: 
					delete_at_begin(my_arr);
					break;
			case 5: 
			        index = get_array_index_from_user();
					delete_at_index(my_arr,index);
					break;
			case 6: 
					delete_at_end(my_arr);
					break;	
			case 7: display_array(my_arr);
					break;
			case 8: break;
			default: printf("\nInvalid choice please enter value between 1 to 8...");
		}
	}while(choice!=8);
	printf("\nThank You! Exited the application successfully!!!");
}
int get_array_index_from_user(){
	int user_input;
	printf("\nEnter the index :");
	scanf("%d",&user_input);
	return user_input;
}
int get_array_value_from_user(){
	int user_input;
	printf("\nEnter the value :");
	scanf("%d",&user_input);
	return user_input;
}
void show_menu(){
	printf("\n****************************ARRAY OPERATIONS - TRAVERSE , INSERT, DELETE*****************************");
	printf("\nOption 1. INSERT AT BEGIN   		\tOption 4. DELETE AT BEGIN");
	printf("\nOption 2. INSERT AT INDEX   		\tOption 5. DELETE AT INDEX");
	printf("\nOption 3. INSERT AT END     		\tOption 6. DELETE AT END");
	printf("\nOption 7. TRAVERSE(DISPLAY ARRAY) \tOption 8. Exit");
	printf("\n\nEnter your choice[option 1-8]: ");
}
void delete_at_end(int arr[]){
	if(curr_index<=0){
		printf("Array is empty...cannot perform delete...");
		return;
	}
	arr[curr_index]=0; //make the last element as zero
	curr_index--; //decrement the curr_index so that current size is reduced
	printf("\nDeleted element successfully");
}
void delete_at_begin(int arr[]){
	delete_at_index(arr,0);
	
}
void delete_at_index(int arr[],int index_value){
	if(curr_index<=0){
		printf("\nArray is Empty...cannot perform delete...");
		return;
	}
	if(index_value<0 || index_value >curr_index){
		printf("\nInvalid index(Out of bound)....");
		return;
	}
	
	for(int i=index_value;i<curr_index-1;i++){
		//perform left shifting
		arr[i] = arr[i+1];
	}
	//fill the last element with zero
	arr[curr_index-1]=0;
	curr_index--; //decrement the element count by 1
	printf("\nDeleted element successfully");
}
void insert_at_begin(int arr[],int new_value){
	insert_at_index(arr,0,new_value);
}
void insert_at_index(int arr[],int index_value, int value){
	if(curr_index>=MAX){
		printf("\nArray is full...cannot perform insert...");
		return;
	}
	if(index_value<0 || index_value >curr_index){
		printf("\nInvalid index(Out of bound)....");
		return;
	}
	for(int i=curr_index-1;i>=index_value;i--){
		arr[i+1]=arr[i]; //right shift all elements
	}
	arr[index_value]=value ;//finally insert the value at the index
	curr_index++;//increment the current index by 1 
	if(index_value==0){
		printf("\nInserted %d at begining successfully",value);
	}else{
		printf("\nInserted @%d index value %d successfully",index_value,value);
	}
}
void insert_at_end(int arr[],int value){
	if(curr_index==MAX){
		printf("\nArray is full...cannot perform insert...");
		return;
	}
	arr[curr_index++] = value;//O(1) operation
	printf("\nInserted %d at end successfully",value);
}
void display_array(int arr[]){
	printf("\nMy Array Elements [curr_size=%d]: ",curr_index);
	for(int i=0;i<curr_index ;i++){
		printf("%d ",arr[i]);
	}
}
