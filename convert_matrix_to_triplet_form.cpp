#include<stdio.h>
void display_matrix(int mat[][5],int ,int );
void display_triplet(int mat[][3],int ,int );
void display_matrix_using_triplet(int mat[][3],int ,int );
int get_matrix_element(int mat[][3],int row,int col,int i,int j);
int main(){
	int mat_sparse[][5]={ {1,0,0,4,0 },
				          {0,1,0,0,5 },
					      {0,0,1,0,0 },
					      {4,0,0,1,0 },
						  {0,5,0,0,1 }	
					};
	int rows = sizeof(mat_sparse)/sizeof(mat_sparse[0]); //size of entire matrix / size of 1 row
	int cols = sizeof(mat_sparse[0])/sizeof(int); //size of 1 row / size of each element
	display_matrix(mat_sparse,rows,cols);
	//get the count of non zero elements
	int non_zeros_count=0;
	for (int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(mat_sparse[i][j]!=0){
//				printf("\n%d\t %d\t %d",i,j,mat_sparse[i][j]);	
				non_zeros_count++;	
			}
		}
	}
	printf("\n\nTriplet count-%d",non_zeros_count);
	//store the triplets - rows = (non zero count + 1 header row)
	int triplet_rep[non_zeros_count+1][3];
	//store the header row - dimension of the matrix ie row,col and the no of non zero element
	int k=0; //row counter for the triplet matrix
	triplet_rep[k][0]=rows;
	triplet_rep[k][1]=cols;
	triplet_rep[k][2]=non_zeros_count;
	k++;
	for (int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(mat_sparse[i][j]!=0){
				triplet_rep[k][0]=i;  // store the row information
				triplet_rep[k][1]=j;  // store the col information
				triplet_rep[k][2]=mat_sparse[i][j]; //store the value
				k++;
			}
		}
	}
	display_triplet(triplet_rep,non_zeros_count+1,3);
	
	//now display the matrix using tripletform
	display_matrix_using_triplet(triplet_rep,non_zeros_count+1,3);
	
	return 0;
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
int get_matrix_element(int triplet_form[][3],int row,int col,int i_row,int j_col){
	int element=0;
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
			printf("%d ",get_matrix_element(triplet,trip_row,trip_col,i,j));
		}
		printf("\n");
	}
}
