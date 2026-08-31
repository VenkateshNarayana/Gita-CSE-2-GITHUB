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
void display_matrix(int mat[][5],int ,int );
void display_triplet(int mat[][3],int ,int );
void display_matrix_using_triplet(int mat[][3],int ,int );
void convert_sparse_to_triplet(int[][5],int[][3]);
int get_matrix_element(int mat[][3],int i,int j);
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
	display_matrix_using_triplet(triplet_rep,non_zeros_count+1,3);
	
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
int get_matrix_element(int triplet_form[][3],int i_row,int j_col){
	int element=0;
	int row = triplet_form[0][2] + 1; //From the header get the value which is the non zero count add 1 for the header
	for (int i=1;i<row;i++){
		if(triplet_form[i][0]==i_row && triplet_form[i][1]==j_col){
			element = triplet_form[i][2];
			return element;
		}
	}
	return element;
}
void display_matrix_using_triplet(int triplet[][3],int trip_row,int trip_col){
	
	printf("\nMatrix Using Triplet form:\n");
	int mat_rows = triplet[0][0],mat_cols=triplet[0][1];
	for (int i=0;i<mat_rows;i++){
		for(int j=0;j<mat_cols;j++){
			printf("%d ",get_matrix_element(triplet,i,j));
		}
		printf("\n");
	}
}
