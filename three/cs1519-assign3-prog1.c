/*-------------------------------------------------------------------------------------------
Name: Ranjan Mishra
Roll Number: 1519
Date of Submission: 24th Aug 2015
Deadline date: 24th Aug 2015
Program description: Matrix inverse calculation and its verifcation.
Acknowledgements: https://en.wikipedia.org/wiki/Invertible_matrix
*/


#include<stdio.h>
#include<stdlib.h>

/* The allocate2D function will allocate two dimensional array of doubles i.e. floating point numbers,
 * it takes one argument number or rows/cols as integer
 * it returns the address of allocated two dimensional array.
 */

float **allocate2D(int row){
	float **matrix;int k;
	matrix = (float **)calloc(row , sizeof(float *));
	if(matrix==NULL){
		printf("\nNo space available!");
		exit(0);
	}
	for(k=0;k<row;k++){
		matrix[k] = (float *)calloc(row,sizeof(float));
		if(matrix[k]==NULL)
			{
			printf("\nNo space available!");
			exit(0);
		}
	}
	
	return matrix;
}


/* The copy_matrix function will copy the original matrix to another matrix,
 * so that it can be preserved during row operations
 * it takes three argument,  original matrix, copy matrix and order of square matrix
 */


void copy_matrix(float **array , float **copy,int row){	
	int i,j;		
	for(i=0;i<row;i++)
		for(j=0;j<row;j++)
			copy[i][j] = array[i][j];		
}	

/* The partial_pivoting_row and partial_pivoting_column are routines, 
 * that do partial pivoting during the row operations so that
 * divide by zero error can be avoided, 
 */
int partial_pivoting_row(float **copy,int i,int row){
	int start = i, j;
	float temp; 
	for(;start>=1;start--)
		for(j=0;j<row;j++){
			temp = copy[start][j];
			copy[start][j] = copy[start-1][j];
			copy[start-1][j] = temp;  
		}				
	return start;						
}

int partial_pivoting_column(float **copy,int j,int row){
	int start = j;
	float temp;
	for(;start>=1;start--)
		for(j=0;j<row;j++){
			temp = copy[j][start-1];
			copy[j][start-1] = copy[j][start];
			copy[j][start] = temp;  
		}				
	return start;						
}

/* The get_determinant function will compute the determinant of given matrix  
 * it takes 3 argumnets and returns the determinat of the matrix
 * the function computes the determinant after the row operations has been done 
 * on the matrix and it has form of triangular matrix
 */
float get_determinant(float **matrix,int row,int k){
	int i=0,j,l=k;
	float q,det = 1.0;
	float **copy;
	float div;
	copy = allocate2D(row);
	copy_matrix(matrix,copy,row);
	if(i==row)
		return 0.0;
	else{
		while(k<row){
			div = copy[k][k]; 
			for(i=k+1;i<row;i++){
				q = copy[i][k]/div;
				for(j=k;j<row;j++){
					copy[i][j] = copy[i][j] - (copy[k][j])*q;		
				}
                        }
			k++;
		}
		for(i=l;i<row;i++){
        	det = det * copy[i][i];  
 		}
		return det;
	}
}

void compute_inverse(float **matrix, float **comp,float **inverse , int row){	
	int i,j,pow;
	float det;		
	for(i=0;i<row;i++){
		for(j=0;j<row;j++){
		partial_pivoting_row(comp,i,row);
		partial_pivoting_column(comp,j,row);
		det = get_determinant(comp,row,1);
		pow=i+j;
		if(pow%2==0)
			inverse[i][j] = det;
		else inverse[i][j] = -det;
				copy_matrix(matrix,comp,row);							
		}
	}

}

/* multiply_matrix function will multiply the matrix a, b and store the result in c,
 * it also takes order of matrix as argument
 */   

void multiply_matrix(float **a,float **b,float **c,int row){
	int i,j,k;	
	for (i=0;i<row;i++){
		for (k=0;k<row;k++){
			c[i][k]=0;
			for (j=0;j<row;j++){
				c[i][k]=c[i][k]+a[i][j]*b[j][k];
		          }
                }
        }
	
}


int main(){

		
		int row,col,zero=0;
		int i,j;
		float determinant;
		float **matrix,**inverse,**copy,**transpose,**identity;
		printf("\nPlease enter the number of rows and columns, seperated by space:");
		scanf("%d%d",&row,&col);
		
		if(row!=col){
			printf("\nInverse only possible for square matrix");
			exit(0);
		}
		matrix = allocate2D(row);
		inverse = allocate2D(row);
		

		copy = allocate2D(row);
		

		transpose = allocate2D(row);

		identity = allocate2D(row);		
	
		for(i=0;i<row;i++){
			for(j=0;j<row;j++){
				printf("Please enter the value of Matrix[%d][%d]: ",i+1,j+1);
				scanf("%f",&matrix[i][j]);
			}
		}
		for(i=0;i<row;i++){
			for(j=0;j<row;j++){
				if(matrix[i][j]!=0){
				zero=1;	
				break;
				}
			}
		}
					
		if(zero==0){
			printf("\nInverse does not exists for null matrix.\n\n");
			exit(0);
		}
		
		printf("\nOriginal Matrix is: \n");
		for(i=0;i<row;i++){
			printf("\n");
			for(j=0;j<row;j++){
				printf("%f\t", matrix[i][j]);
			}
		}
		copy_matrix(matrix,copy,row);		
		compute_inverse(matrix,copy,inverse,row);
											
		determinant = get_determinant(matrix,row,0);
		
		if(determinant != 0){
		for(i=0;i<row;i++){
			for(j=0;j<row;j++){
				transpose[i][j] = inverse[j][i];
			}
		} 
		
		for(i=0;i<row;i++){
			for(j=0;j<row;j++){
				transpose[i][j] = (transpose[i][j])/determinant;
			}
		}

		printf("\n\nInverse Matrix is:\n\n");
		for(i=0;i<row;i++){
			for(j=0;j<row;j++)
				printf("%f\t",transpose[i][j]);
				printf("\n");	
			}
		}

		else printf("\nInverse does not exist for the matrix.\n");

		printf("\nVerification of inverse by multiplying with itself, \nPrinting the result of multiplication:\n\n");
		multiply_matrix(matrix,transpose,identity,row);
		for(i=0;i<row;i++){
			for(j=0;j<row;j++)
				printf("%f\t",identity[i][j]);
			printf("\n");
		}	
		return 0;
	   }			


