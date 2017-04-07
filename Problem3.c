/*------------------------------------------------------------------
Name: Ranjan Mishra
Roll Number: 1519
Date of Submission: 31st Aug 2015
Deadline date:  31st Aug 2015
Program description: To find the path of the mouse in maze if it exists
Acknowledgements: 
--------------------------------------------------------------------*/


#include<stdio.h>
#include<stdlib.h>


typedef struct node{
	int rowIndex;
	int colIndex;
	struct node* next;
	}STACK;
STACK *stack;

STACK* init(){
	STACK *newElement;
	newElement=(STACK*)malloc(sizeof(STACK));
	newElement->next=NULL;
	return newElement;
}

void push(int rowIndex, int colIndex, STACK *stack){
	STACK *newElement;
	newElement=(STACK*)malloc(sizeof(STACK));
	newElement->rowIndex=rowIndex;
	newElement->colIndex=colIndex;
	newElement->next=stack->next;
	stack->next=newElement;
}


STACK pop(STACK *stack){
	STACK temp, *p;
	p=stack->next;
	temp.colIndex=p->colIndex;
	temp.rowIndex=p->rowIndex;
	stack->next=p->next;
	free(p);
	return temp;
}


int isEmpty(STACK *stack){
	if(stack->next==NULL)
		return 1;
	else 
		return 0;
}

void displayStackReverse(STACK *stack){
	STACK temp;	
	if(stack->next==NULL){
		return;
	}
	temp=pop(stack);
	displayStackReverse(stack);
	printf("\n(Row Index, Col Index): (%d, %d)", temp.rowIndex, temp.colIndex);
}



int **allocate2D(int row, int col){
	int **matrix;
	int i;
	matrix=(int**) malloc(row*sizeof(int*));
	if(matrix==NULL){
		perror("\nNo space available");
		exit(0);
	}
	for(i=0;i<row;i++){
		matrix[i]=(int*)malloc(col*sizeof(int));
		if(matrix[i]==NULL){
		perror("\nNo space available");
		exit(0);
		}
	}
	return matrix;
}


int isSafe(int rowIndex, int colIndex, int row, int col, int **matrix, int **marked){
	if(rowIndex<row && rowIndex>=0 && colIndex<col  && colIndex>=0 && matrix[rowIndex][colIndex]==0 && marked[rowIndex][colIndex]==0)
		return 1;
	else
		return 0;
}



int findPath(int **matrix, int **marked, int row, int col, int rowIndex, int colIndex){
		if(rowIndex==row-1 && colIndex==col-1 && isSafe(rowIndex, colIndex, row, col, matrix, marked)){
			marked[rowIndex][colIndex]=1;
			push(rowIndex, colIndex, stack);
			return 1;
		}
		// N=North S=South W=West E=East
		if(isSafe(rowIndex, colIndex, row, col, matrix, marked)){
			marked[rowIndex][colIndex]=1;
			push(rowIndex, colIndex, stack);
			if(findPath(matrix, marked, row, col, rowIndex+1, colIndex+1))			//SE
				return 1;
			if(findPath(matrix, marked, row, col, rowIndex, colIndex+1))			//E
				return 1;
			if(findPath(matrix, marked, row, col, rowIndex+1, colIndex))			//S
				return 1;
			if(findPath(matrix, marked, row, col, rowIndex-1, colIndex+1))			//NE
				return 1;
			if(findPath(matrix, marked, row, col, rowIndex+1, colIndex-1))			//SW
				return 1;
			if(findPath(matrix, marked, row, col, rowIndex, colIndex-1))			//N
				return 1;
			if(findPath(matrix, marked, row, col, rowIndex-1, colIndex))			//E
				return 1;
			if(findPath(matrix, marked, row, col, rowIndex-1, colIndex-1))			//NW
				return 1;
			marked[rowIndex][colIndex]=0;
			pop(stack);
			return 0;
		}
		
			
		return 0;
}



int main(){
	int col, row;
	int **matrix, **marked;
	int i,j; 
	stack=init();
	printf("\nPlease enter the row and column size of matrix:");
	scanf("%d%d", &row, &col);
	matrix=allocate2D(row,col);
	marked=allocate2D(row,col);
	srand(time(NULL));
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			matrix[i][j]=random()%2;
			marked[i][j]=0;
		}
	}	
	matrix[0][0]=0;
	matrix[row-1][col-1]=0;
	for(i=0;i<row;i++){
		printf("\n");
		for(j=0;j<col;j++){
			printf("%d", matrix[i][j]);
		}
	}
	if(findPath(matrix, marked, row, col, 0, 0)==0){
		printf("\nNo path from 0,0 to %d,%d possible",row-1,col-1);	
	}
	else {
	printf("\nFollowing is path mouse can take, in form of row and column index of matrix:");
        	/*for(i=0;i<row;i++){
			printf("\n");
			for(j=0;j<col;j++){
				if(marked[i][j]==1)
				printf("\n(Row Index, Col Index):(%d,%d)", i, j);
			}
		}*/
		displayStackReverse(stack);	
	}

	free(stack);
	free(matrix);
	free(marked);	
	return 0;
}
