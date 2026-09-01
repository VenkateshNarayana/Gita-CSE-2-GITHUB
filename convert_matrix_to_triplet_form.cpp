/*Display a matrix in triplet form
Algorithm
step1 : row = no. of non zero elements 
	    col = 3 ( r= row,c = col,v = value of non zero element ) 
step2 : create the 2d triplet matrix array[row][col]
step3 : store the header information in 1st row
        r = Original matrix (row dimension)
        c = Original matrix (col dimension)
        v = Original matrix (no of non zero elements)
        
step4: store the r,c,v of every non zero elements from original matrix
        r = non zero elemnent's row = i
        c = non zero elemnent's col = j
        v = non zero elemnent's value = matrix[i][j]

*/
#include<stdio.h>
void display_matrix(int mat[][5],int ,int );            //param1 = orignal matrix, param2= orig mat row,param3 = orig mat col
void display_triplet(int mat[][3],int ,int );           //param1 = triplet matrix, param2= triplet row, param3= triplet col
void convert_sparse_to_triplet(int[][5],int[][3]);      //param1=original matrix;param2=triplet matrix

void display_matrix_using_triplet(int mat[][3]);        //param1 = triplet matrix
int get_element_from_triplet(int mat[][3],int i,int j); //param1 = triplet matrix;param2 = i(row val of non zero element);param3= j(col val of non zero element)
int main(){
	int mat_sparse[4][5]={ {0,0,3,0,4 },
				          {0,0,5,7,0 },
					      {0,0,0,0,0 },
					      {6,0,0,0,0 }
					};
	int rows = sizeof(mat_sparse)/sizeof(mat_sparse[0]); //size of entire matrix / size of 1 row
	int cols = sizeof(mat_sparse[0])/sizeof(int); //size of 1 row / size of each element
	display_matrix(mat_sparse,rows,cols);

	//step 1: find the count of non zero elements
	int non_zeros_count=0;
	for (int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(mat_sparse[i][j]!=0){
				non_zeros_count++;	
			}
		}
	}
	printf("\n\nTriplet count-%d",non_zeros_count);
	
	//Step2 : Create the triple with rows = (non zero count + 1 header row)
	//          col = 3 (r,c,v)
	int triplet_rep[non_zeros_count+1][3];
	
	//Step3 ; Store the header row - dimension of the matrix ie row,col and the no of non zero element
	triplet_rep[0][0]=rows;
	triplet_rep[0][1]=cols;
	triplet_rep[0][2]=non_zeros_count;
	
	int k = 1; //row counter for the triplet matrix
	//Step4 : store the r,c,v of every non zero elements from original matrix
	convert_sparse_to_triplet(mat_sparse,triplet_rep);
	//display the triplet matrix
	display_triplet(triplet_rep,non_zeros_count+1,3);
	
	//now display the matrix using triplet form
	display_matrix_using_triplet(triplet_rep);
	
	//transpose triplet
	int trip_trans_rows = triplet_rep[0][2]+1;//header row ->non zero count + 1 (for header)
	int triplet_trans[trip_trans_rows][3];
	for(int row = 0;row<trip_trans_rows;row++){
		//insert the r,c,v ; r = triplet c, c = triplet r, v = triplet v
		triplet_trans[row][0]= triplet_rep[row][1];//r = triplet col values
		triplet_trans[row][1]= triplet_rep[row][0];//c = triplet row values
		triplet_trans[row][2]= triplet_rep[row][2];//v = triplet values(actual elements)
	}
	
	//display the transposed triplet matrix
	display_triplet(triplet_trans,trip_trans_rows,3);
	
	//now display the matrix using triplet form
	display_matrix_using_triplet(triplet_trans);
		
	return 0;
}
void convert_sparse_to_triplet(int mat_sparse[][5],int triplet_rep[][3]){
	int rows = triplet_rep[0][0];
	int cols = triplet_rep[0][1]; 
	int k = 1;
	for (int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(mat_sparse[i][j]!=0){
				//store the r,c,v in the triplet rep matrix
				triplet_rep[k][0]=i;  // store the row information
				triplet_rep[k][1]=j;  // store the col information
				triplet_rep[k][2]=mat_sparse[i][j]; //store the actual value of the non zero element
				k++; //increment the row
			}
		}
	}
}
void display_matrix(int mat[][5],int row,int col){
	printf("\nGiven Matrix:\n");
	for (int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%d ",mat[i][j]);	
		}
		printf("\n");
	}
}
void display_triplet(int mat[][3],int row,int col){
	printf("Triplet form:\n");
	printf("\nRow\t Col \t Value\n");
	for (int i=0;i<row;i++){
		printf("%d\t %d\t %d",mat[i][0],mat[i][1],mat[i][2]);	
		printf("\n");
	}
}
int get_element_from_triplet(int triplet_mat[][3],int i,int j){
	//fetch the rows of triplet matrix from header row (no of non zero elements stored in 3 col)
	int trip_rows = triplet_mat[0][2] +1 ;//non zero count + 1 (header row)
	for(int row=1;row<trip_rows;row++){
		if(triplet_mat[row][0]==i && triplet_mat[row][1]==j){ //if row and col values are same then return the value
			return triplet_mat[row][2];//return the value
		}
	}
	return 0;//if no match found 
}
void display_matrix_using_triplet(int triplet_mat[][3]){
	//fetch the original dimension from header row
	int rows = triplet_mat[0][0]; //rows
	int cols = triplet_mat[0][1]; //cols
	printf("\n Matrix:\n");
	//print the matrix using nested loops for i and j
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			printf("%d ",get_element_from_triplet(triplet_mat,i,j));
		}
		printf("\n"); //print a new line for each row
	}
	
}



