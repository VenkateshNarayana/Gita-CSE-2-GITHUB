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
void display_matrix(int mat[][3],int ,int ); 
void convert_sparse_to_triplet(int[][3],int[][3]);      //param1=original matrix;param2=triplet matrix
int main(){
	int mat_A[3][3]={ {5,0,0 },
				  {0,0,3 },
				  {0,4,0 }
				};
				
	int mat1_rows = sizeof(mat_A)/sizeof(mat_A[0]); //size of entire matrix / size of 1 row
	int mat1_cols = sizeof(mat_A[0])/sizeof(int); //size of 1 row / size of each element
	
	display_matrix(mat_A,mat1_rows,mat1_cols);
	//step 1: find the count of non zero elements
	int non_zeros_countA=0;
	for (int i=0;i<mat1_rows;i++){
		for(int j=0;j<mat1_cols;j++){
			if(mat_A[i][j]!=0){
				non_zeros_countA++;	
			}
		}
	}
	printf("\n\nTriplet count-%d",non_zeros_countA);
	
	//Step2 : Create the triple with rows = (non zero count + 1 header row)
	//          col = 3 (r,c,v)
	int triplet_matA[non_zeros_countA+1][3];

	//Step3 ; Store the header row - dimension of the matrix ie row,col and the no of non zero element
	triplet_matA[0][0]=mat1_rows;
	triplet_matA[0][1]=mat1_cols;
	triplet_matA[0][2]=non_zeros_countA;

	int k = 1; //row counter for the triplet matrix
	//Step4 : store the r,c,v of every non zero elements from original matrix
	convert_sparse_to_triplet(mat_A,triplet_matA);
	

	int mat_B[3][3]={{2,0,0 },
				  	 {0,0,6 },
				  	 {1,0,0 }
					};
				
	int mat2_rows = sizeof(mat_B)/sizeof(mat_B[0]); //size of entire matrix / size of 1 row
	int mat2_cols = sizeof(mat_B[0])/sizeof(int); //size of 1 row / size of each element
	display_matrix(mat_B,mat2_rows,mat2_cols);
	
	//step 1: find the count of non zero elements
	int non_zeros_countB=0;
	for (int i=0;i<mat2_rows;i++){
		for(int j=0;j<mat2_cols;j++){
			if(mat_B[i][j]!=0){
				non_zeros_countB++;	
			}
		}
	}
	printf("\n\nTriplet count-%d",non_zeros_countB);
	
	//Step2 : Create the triple with rows = (non zero count + 1 header row)
	//          col = 3 (r,c,v)
	int triplet_matB[non_zeros_countB+1][3];

	//Step3 ; Store the header row - dimension of the matrix ie row,col and the no of non zero element
	triplet_matB[0][0]=mat2_rows;
	triplet_matB[0][1]=mat2_cols;
	triplet_matB[0][2]=non_zeros_countB;

	k = 1; //row counter for the triplet matrix
	//Step4 : store the r,c,v of every non zero elements from original matrix
	convert_sparse_to_triplet(mat_B,triplet_matB);
	
	//now perform matrix addition using the triplet forms of matA and matB
	//step1: check the condtion of rows and cols should be same
	if(mat1_rows!=mat2_rows || mat1_cols!=mat2_cols){
		printf("Matrix addition cannot be performed");
		return 0; //exit program
	}
	//Step2 : create the result triplet matrix [row=?][col=?]
	int row = triplet_matA[0][2] + triplet_matB[0][2] + 1; // (header) -> non zero count of mat1 & mat2 plus 1 for the header row
//	col = 3 ->(r,c,v)
	int result_mat[row][3]={0}; //declaration
	
	//step3 : store the header information in 1st row
	//      r = triplet_mat1[0][0] ->Original matrix (row dimension)
	//      c = triplet_mat1[0][1] ->Original matrix (col dimension)
	//      v = triplet_mat1[0][2] + triplet_mat2[0][2](no of non zero elements in mat1 and mat2)
	result_mat[0][0]= triplet_matA[0][0];
	result_mat[0][1]= triplet_matA[0][1];
	result_mat[0][2]= triplet_matA[0][2] + triplet_matB[0][2];//(no of non zero elements in mat1 and mat2)
	
	//step4: perform the addition on the triplet and store r,c,v into triplet
	//       iterate all the rows of mat1 and mat2 and check for below 3 conditions	
	int  i = 1, j = 1; //i is for matA j is for matB and k is for result_mat
	k = 1;
	while(i<(mat1_rows+1) && j<(mat2_rows+1)){

		if (triplet_matA[i][0]==triplet_matB[j][0] && triplet_matA[i][1]==triplet_matB[i][1]) {
			//case 1: if row & col indexes are same for both mat1 & mat2.
			//        then, we add a single entry as below
			//		r = triplet_mat1[i][0] ->row index
			//      c = triplet_mat1[i][1] ->col index
			//      v = triplet_mat1[i][2] + triplet_mat2[0][2](add the values of mat1 and mat2)
			result_mat[k][0]= triplet_matA[i][0];
			result_mat[k][1]= triplet_matA[i][1];
			result_mat[k][2]= triplet_matA[i][2] + triplet_matB[j][2]; //add the values of matA and matB
			i++;
			j++;
			k++;	
		}else if (triplet_matA[i][0]==triplet_matB[j][0] && triplet_matA[i][1]!=triplet_matB[i][1]) {
			//case 2: if row indexes are same but col indexes are different for mat1 & mat2.
			//        then, we add 2 entries as below,
			//	   	  if mat 1 col index < mat 2 col index then
			//		    	r = triplet_mat1[i][0] ->row index
			//		      	c = triplet_mat1[i][1] ->col index
			//		      	v = triplet_mat1[i][2] (add the values of mat1)
			//		  else
			//				r = triplet_mat2[j][0] ->row index
			//		       	c = triplet_mat2[j][1] ->col index
			//		       	v = triplet_mat2[j][2] (add the values of mat2)
			if (triplet_matA[i][1]<triplet_matB[i][1]){
				//add 2 entries
				result_mat[k][0]= triplet_matA[i][0];
				result_mat[k][1]= triplet_matA[i][1];
				result_mat[k][2]= triplet_matA[i][2];
				i++;
				k++;
				//next entry for matB
				result_mat[k][0]= triplet_matB[j][0];
				result_mat[k][1]= triplet_matB[j][1];
				result_mat[k][2]= triplet_matB[j][2];
				j++;
				k++;
				
			}else{
				//Add first entry for matB
				result_mat[k][0]= triplet_matB[j][0];
				result_mat[k][1]= triplet_matB[j][1];
				result_mat[k][2]= triplet_matB[j][2];
				j++;
				k++;
				//next entry for matA
				result_mat[k][0]= triplet_matA[i][0];
				result_mat[k][1]= triplet_matA[i][1];
				result_mat[k][2]= triplet_matA[i][2];
				i++;
				k++;
			}
		}else if (triplet_matA[i][0]!=triplet_matB[j][0] && triplet_matA[i][1]!=triplet_matB[i][1]) {
			// case 3: if row indexes are col indexes are different for mat1 & mat2.
			//   		then, we add 2 entries as below,
			//	     	if mat 1 col index < mat 2 col index then
			//			   		r = triplet_mat1[i][0] ->row index
			//		        	c = triplet_mat1[i][1] ->col index
			//		        	v = triplet_mat1[i][2] (add the values of mat1)
			//				else
			//					r = triplet_mat2[j][0] ->row index
			//		        	c = triplet_mat2[j][1] ->col index
			//		        	v = triplet_mat2[j][2] (add the values of mat2)
			if (triplet_matA[i][0]<triplet_matB[i][0]){
				//add 2 entries
				result_mat[k][0]= triplet_matA[i][0];
				result_mat[k][1]= triplet_matA[i][1];
				result_mat[k][2]= triplet_matA[i][2];
				i++;
				k++;
				//next entry for matB
				result_mat[k][0]= triplet_matB[j][0];
				result_mat[k][1]= triplet_matB[j][1];
				result_mat[k][2]= triplet_matB[j][2];
				j++;
				k++;
				
			}else{
				//Add first entry for matB
				result_mat[k][0]= triplet_matB[j][0];
				result_mat[k][1]= triplet_matB[j][1];
				result_mat[k][2]= triplet_matB[j][2];
				j++;
				k++;
				//next entry for matA
				result_mat[k][0]= triplet_matA[i][0];
				result_mat[k][1]= triplet_matA[i][1];
				result_mat[k][2]= triplet_matA[i][2];
				i++;
				k++;
			}
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
	//display the triplet
	printf("\nTriplet Result Matrix:\n");
	printf("Row \tCol \tValue");
	for(int row=0;row< (result_mat[0][2]+1);row++){
		printf("\n%d \t%d \t%d",result_mat[row][0],result_mat[row][1],result_mat[row][2]);
	}
	
	return 0;//exit main
}
void display_matrix(int mat[][3],int row,int col){
	printf("\nGiven Matrix:\n");
	for (int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%d ",mat[i][j]);	
		}
		printf("\n");
	}
}

void convert_sparse_to_triplet(int mat_sparse[][3],int triplet_rep[][3]){
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
	//display the triplet
	printf("Triplet Matrix:\n");
	printf("Row \tCol \tValue");
	for(int row=0;row< (triplet_rep[0][2]+1);row++){
		printf("\n%d \t%d \t%d",triplet_rep[row][0],triplet_rep[row][1],triplet_rep[row][2]);
	}
}
