/* perform matrix addition using triplet form
Algorithm
step1 : perform check if rows and cols of matrix1 are same as rows and cols of matrix2
		if not, cannot perform matrix addition
step2 : create the result triplet matrix [row=?][col=?]
		row = triplet_mat1[0][2] + triplet_mat2[0][2] + 1 (header) -> non zero count of mat1 & mat2 plus 1 for the header row
		col = 3 ->(r,c,v)
step3 : store the header information in 1st row
        r = triplet_mat1[0][0] ->Original matrix (row dimension)
        c = triplet_mat1[0][1] ->Original matrix (col dimension)
        v = triplet_mat1[0][2] + triplet_mat2[0][2](no of non zero elements in mat1 and mat2)
        
step4: perform the addition on the triplet and store r,c,v into triplet
       iterate all the rows of mat1 and mat2 and check for below 3 conditions
       	case 1: if row & col indexes are same for both mat1 & mat2.
	   			then, we add a single entry as below
			r = triplet_mat1[i][0] ->row index
        	c = triplet_mat1[i][1] ->col index
        	v = triplet_mat1[i][2] + triplet_mat2[0][2](add the values of mat1 and mat2) 
		case 2: if row indexes are same but col indexes are different for mat1 & mat2.
	   			then, we add 2 entries as below,
	   			if mat 1 col index < mat 2 col index then
			   		r = triplet_mat1[i][0] ->row index
		        	c = triplet_mat1[i][1] ->col index
		        	v = triplet_mat1[i][2] (add the values of mat1)
				else
					r = triplet_mat2[j][0] ->row index
		        	c = triplet_mat2[j][1] ->col index
		        	v = triplet_mat2[j][2] (add the values of mat2)
		case 3: if row indexes and col indexes are different for both mat1 & mat2.
	   			then, we add 2 entries as below,
	   			if mat1 row index < mat2 row index then
			   		r = triplet_mat1[i][0] ->row index
		        	c = triplet_mat1[i][1] ->col index
		        	v = triplet_mat1[i][2] (add the values of mat1)
				else
					r = triplet_mat2[j][0] ->row index
		        	c = triplet_mat2[j][1] ->col index
		        	v = triplet_mat2[j][2] (add the values of mat2)
	step5 : 1.Any leftovers from mat1 needs to added to result triplet matrix
			2.Any leftovers from mat2 needs to added to result triplet matrix
	   
    step5 : display the result triplet matrix and also display the matrix
*/
#include<stdio.h>
void perform_matrix_addition(int[][3],int[][3],int[][3]); //param1=original matrix;param2=triplet matrix
void display_sparse_using_triplet(int[][3]);              //param1=original matrix;param2=triplet matrix
int get_matrix_element(int[][3],int ,int );               //param1=original matrix;param2=row as in i;param3=col as in j

int main(){
	
	int triplet_matA[4][3]={
							{3,3,3 },
							{0,0,5 },
							{1,2,3 },
							{2,1,4 }
							};
	int mat1_rows = triplet_matA[0][0];
	int mat1_cols = triplet_matA[0][1];
	
	int triplet_matB[4][3]={
							{3,3,3 },
							{0,0,2 },
							{1,2,6 },
							{ 2,0,1}
							};
	
	int mat2_rows = triplet_matB[0][0];
	int mat2_cols = triplet_matB[0][1];
	
	//perform matrix addition using the triplet forms of matA and matB
	//Step1: check the condtion of rows and cols should be same
	if(mat1_rows!=mat2_rows || mat1_cols!=mat2_cols){
		printf("Matrix addition cannot be performed");
		return 0; //exit program
	}
	//Step2 : create the result triplet matrix [row=?][col=?]
	int row = triplet_matA[0][2] + triplet_matB[0][2] + 1; // (header) -> non zero count of mat1 & mat2 plus 1 for the header row
	int result_mat[row][3]={0}; //declaration
	
	//perform matrix addition
	perform_matrix_addition(triplet_matA,triplet_matB,result_mat);
	
	//show the result triplet matrix into sparse matrix
	display_sparse_using_triplet(result_mat);
	
	return 0;//exit main
}
void perform_matrix_addition(int triplet_matA[][3],int triplet_matB[][3],int result_mat[][3]){
	int mat1_rows = triplet_matA[0][2];	
	int mat2_rows = triplet_matB[0][2];

	//Step3 : store the header information in 1st row
	//    r = triplet_mat1[0][0] ->Original matrix (row dimension)
	//    c = triplet_mat1[0][1] ->Original matrix (col dimension)
	//    v = triplet_mat1[0][2] + triplet_mat2[0][2](no of non zero elements in mat1 and mat2)
	result_mat[0][0]= triplet_matA[0][0];
	result_mat[0][1]= triplet_matA[0][1];
	result_mat[0][2]= triplet_matA[0][2] + triplet_matB[0][2];//(no of non zero elements in mat1 and mat2)
	
	//Step4: perform the addition on the triplet and store r,c,v into triplet
	//       iterate all the rows of mat1 and mat2 and check for below 3 conditions	
	int  i = 1, j = 1,k = 1; //i is for matA j is for matB and k is for result_mat
	
	while(i<(mat1_rows+1) && j<(mat2_rows+1)){

		if (triplet_matA[i][0]==triplet_matB[j][0] && triplet_matA[i][1]==triplet_matB[i][1]) {
			//case 1: if row & col indexes are same for both mat1 & mat2.
			//        then, we add a single entry where value is added from mat1 and mat2 and row and col remain same
			result_mat[k][0]= triplet_matA[i][0];
			result_mat[k][1]= triplet_matA[i][1];
			result_mat[k][2]= triplet_matA[i][2] + triplet_matB[j][2]; //add the values of matA and matB
			i++;
			j++;
			k++;	
		}else if (triplet_matA[i][0]==triplet_matB[j][0] && triplet_matA[i][1]<triplet_matB[i][1]) {
			//case 2: if row indexes are same but col indexes are different for mat1 & mat2.
			//        then, we add 2 entries as below,
			//	   	  if mat 1 col index < mat 2 col index then add row1 else add row2
				//add 2 entries
				result_mat[k][0]= triplet_matA[i][0];
				result_mat[k][1]= triplet_matA[i][1];
				result_mat[k][2]= triplet_matA[i][2];
				i++;
				k++;
		}else if (triplet_matA[i][0]==triplet_matB[j][0] && triplet_matA[i][1]>triplet_matB[i][1]) {
			//case 2: if row indexes are same but col indexes are different for mat1 & mat2.
			//        then, we add 2 entries as below,
			//	   	  if mat 1 col index < mat 2 col index then add row1 else add row2			
				//Add first entry for matB
				result_mat[k][0]= triplet_matB[j][0];
				result_mat[k][1]= triplet_matB[j][1];
				result_mat[k][2]= triplet_matB[j][2];
				j++;
				k++;
		}else if (triplet_matA[i][0]<triplet_matB[j][0] ) {
			// case 3: if row indexes are col indexes are different for mat1 & mat2.
			//   		then, we add 2 entries as below,
			//	     	if mat 1 col index < mat 2 col index then add row 1
			//				else add row2
				//add 2 entries
				result_mat[k][0]= triplet_matA[i][0];
				result_mat[k][1]= triplet_matA[i][1];
				result_mat[k][2]= triplet_matA[i][2];
				i++;
				k++;
		}else if (triplet_matA[i][0]>triplet_matB[j][0] ) {
			// case 3: if row indexes are col indexes are different for mat1 & mat2.
			//   		then, we add 2 entries as below,
			//	     	if mat 1 col index < mat 2 col index then add row 1
			//				else add row2
				//Add first entry for matB
				result_mat[k][0]= triplet_matB[j][0];
				result_mat[k][1]= triplet_matB[j][1];
				result_mat[k][2]= triplet_matB[j][2];
				j++;
				k++;
		}
	}
	//add any leftovers from matA
	while(i<(mat1_rows+1)){
		//Add first entry for matB
		result_mat[k][0]= triplet_matA[i][0];
		result_mat[k][1]= triplet_matA[i][1];
		result_mat[k][2]= triplet_matA[i][2];
		i++;
		k++;
	}
	
	//add any leftovers from matB
	while(j<(mat2_rows+1)){
		//Add first entry for matB
		result_mat[k][0]= triplet_matB[j][0];
		result_mat[k][1]= triplet_matB[j][1];
		result_mat[k][2]= triplet_matB[j][2];
		j++;
		k++;
	}
	//display the triplet matrix
	printf("\nTriplet Result Matrix:\n");
	printf("Row \tCol \tValue");
	for(int row=0;row< (result_mat[0][2]+1);row++){
		printf("\n%d \t%d \t%d",result_mat[row][0],result_mat[row][1],result_mat[row][2]);
	}
	
}
int get_matrix_element(int triplet_mat[][3],int i_row,int j_col){
	
	int trip_mat_row = triplet_mat[0][2]+1;
	//check in the triplet if the value exist return else return 0
	for (int row=0;row<trip_mat_row;row++){
		if(triplet_mat[row][0]==i_row && triplet_mat[row][1]==j_col){	
			return triplet_mat[row][2]; //pass the value of the matrix[i_row][j_col]
		}
	}	
	return 0;//if no matching rows and cols then return 0
}
void display_sparse_using_triplet(int triplet_mat[][3]){
	printf("\nMatrix from TRIPLET FORM:\n");
	int rows = triplet_mat[0][0]; //row dimension of original matrix 
	int cols = triplet_mat[0][1]; //col dimension of origianl matrix
	
	//print the matrix from triplet form(using get_matrix_element function)
	for (int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			printf("%d ",get_matrix_element(triplet_mat,i, j));	
		}
		printf("\n");
	}
}

