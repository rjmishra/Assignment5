/*------------------------------------------------------------------
Name: Ranjan Mishra
Roll Number: 1519
Date of Submission: 31st Aug 2015
Deadline date: 31st Aug 2015
Program description: Recursive function to print the matrix in a spiral fashion.
Acknowledgements: 
--------------------------------------------------------------------*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int left, right, up, down;   //These variables represent four boundaries of the square matrix.

void initBoundaries(unsigned length){
	left=-1;
	right=length-1;
	up=0;
	down=length-1;
}

unsigned ** allocate2D(unsigned length){
	unsigned **matrix, i;
	matrix=(unsigned**)malloc(length*sizeof(unsigned*));
	if(matrix==NULL){
		perror("\nNot enough spaces");
		exit(0);
	}
	for(i=0;i<length;i++){
		matrix[i]=(unsigned*)malloc(length*sizeof(unsigned));		
		if(matrix[i]==NULL){
			perror("\nNot enough spaces");
			exit(0);
		}
	}
	return matrix;
	
}

void fillMatrix(unsigned **matrix, unsigned length){
	unsigned i,j, count=1;	
	for(i=0;i<length;i++){	
		for(j=0;j<length;j++){
			matrix[i][j]=count;
			count++;
		}	
	}
}


void printMatrix(unsigned **matrix, unsigned length){
	unsigned i,j;	
	for(i=0;i<length;i++){
		printf("\n");	
		for(j=0;j<length;j++){
			printf("%u\t", matrix[i][j]);
		}	
	}
}

void printSpiral(unsigned **array, int rowIndex, int colIndex){
		printf("%u\t",array[rowIndex][colIndex]);
		if(left==right-1 && up==down)
			return;
		else if(rowIndex==up && colIndex==right){
			left=left+1;			
			printSpiral(array, rowIndex+1, colIndex);
			
		}	
		else if(colIndex==right && rowIndex==down){
			up=up+1;
			printSpiral(array, rowIndex, colIndex-1);
		}			
		else if(colIndex==left && rowIndex==down){
			right=right-1;
			printSpiral(array, rowIndex-1, colIndex);
		}		
		else if(colIndex==left && rowIndex==up){
			down=down-1;			
			printSpiral(array, rowIndex, colIndex+1);
		}		
		else if(rowIndex==up)
			printSpiral(array, rowIndex, colIndex+1);
					
		else if(colIndex==right)
			printSpiral(array, rowIndex+1, colIndex);
		
		else if(rowIndex==down){
			printSpiral(array, rowIndex, colIndex-1);
		}
		else if(colIndex==left){
			printSpiral(array, rowIndex-1, colIndex);
		}
		
}
		



int main(){
	unsigned length, n, **matrix;
	printf("\nPlease enter the value of n");
	scanf("%u", &n);
	length=pow(2,n);
	matrix=allocate2D(length);
	initBoundaries(length);
		
	fillMatrix(matrix, length);
	printf("\nThe matrix is :");	
	printMatrix(matrix, length);
	printf("\nMatrix elements traversed in spiral fashions as follows :\n");	
	printSpiral(matrix, 0, 0);

	return 0;

}
