#include<stdio.h>
void display_matrix(int mat[][5],int ,int );
void display_triplet(int mat[][3],int ,int );
void display_matrix_using_triplet(int mat[][3],int ,int );
void convert_triplet_transpose(int[][3],int ,int,int[][3]);
int get_matrix_element(int mat[][3],int row,int col,int i,int j);
int main(){
	int mat_sparse[][5]={ {1,0,0,9,0 },
				          {0,3,0,0,3 },
					      {0,0,2,0,0 },
					      {2,0,0,6,0 },
						  {0,1,0,0,7 }
					};
	int rows = 5, cols =5;
	display_matrix(mat_sparse,5,5);
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
	
	//store the triplets - rows = (non zero count + 1 header row)
	int triplet_transpose[non_zeros_count+1][3];
	int tran_row = sizeof(triplet_transpose)/sizeof(triplet_transpose[0]);
	convert_triplet_transpose(triplet_transpose,tran_row,3,triplet_rep);
	
	//now display the transpose matrix using transposed tripletform
	display_matrix_using_triplet(triplet_transpose,tran_row,3);
	
	return 0;
}
void convert_triplet_transpose(int triplet_transpose[][3],int tran_rows,int tran_cols,int triplet_rep[][3]){
	for(int i=0;i<tran_rows;i++){
		triplet_transpose[i][0] = triplet_rep[i][1]; //interchange row to col
		triplet_transpose[i][1] = triplet_rep[i][0]; //interchange col to row			
		triplet_transpose[i][2] = triplet_rep[i][2];	//store the same value	
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
