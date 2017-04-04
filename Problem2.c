/*------------------------------------------------------------------
Name: Ranjan Mishra
Roll Number: 1519
Date of Submission: 31st Aug 2015
Deadline date:  31st Aug 2015
Program description: To recursively print the matrix in a Hilbert curve fashion. 
Acknowledgements: https://en.wikipedia.org/wiki/Hilbert_curve
		  There is one research paper published on the recursive Hilbert space filling, which is available at
		  http://ieeexplore.ieee.org/stamp/stamp.jsp?arnumber=7089683 url.
--------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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


void Hilbert(unsigned x, unsigned y, unsigned lg, unsigned i1, unsigned i2, unsigned **array) {
	if (lg == 1) { /* Unit shape reached. */
		printf("%u\t",array[x][y]); /* Output coordinates. */
		return; /* Exit recursion. */
	}
	lg >>= 1; /* Divide by 2. */
	Hilbert(x+i1*lg, y+i1*lg, lg, i1, 1-i2, array);
	Hilbert(x+i2*lg, y+(1-i2)*lg, lg, i1, i2, array);
	Hilbert(x+(1-i1)*lg, y+(1-i1)*lg, lg, i1, i2, array);
	Hilbert(x+(1-i2)*lg, y+i2*lg, lg, 1-i1, i2, array);
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

int main(){
	unsigned length, n, **matrix;
	printf("\nPlease enter the value of n");
	scanf("%u", &n);
	length=pow(2,n);
	matrix=allocate2D(length);
		
	fillMatrix(matrix, length);
	printf("\nThe matrix is :");	
	printMatrix(matrix, length);
	printf("\nMatrix elements traversed in spiral fashions as follows :\n");	
	Hilbert(0,0,length, 0, 0, matrix);

	return 0;

}
