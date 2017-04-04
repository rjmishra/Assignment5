/*------------------------------------------------------------------
Name: Ranjan Mishra 
Roll Number: 1519
Date of Submission: 31st Aug 2015
Deadline date: 31st Aug 2015
Program description: Recursive program to find maximum and minimum from an array.
Acknowledgements: 
--------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
int comparisons;


typedef struct maxmin{
	long min;
	long max;
	}MinMax;


MinMax find_minmax(long *array, long start, long end, MinMax minmax, MinMax temp){
	int mid;
	if(end==start){
		minmax.max=array[end];
		minmax.min=array[end];
		return minmax;
	}
	else{
		
		temp=find_minmax(array, start, (start+end)/2, minmax, temp);
		minmax=find_minmax(array, (start+end)/2+1, end, minmax, temp);
		if(minmax.max<=temp.max){
			comparisons++;
			minmax.max=temp.max;
		
		}
		if(minmax.min>=temp.min){
			comparisons++;
			minmax.min=temp.min;
		}
	 return minmax;
	}
}

int main(){
	long *array, length, i;
	char ch;	
	MinMax result, temp_arg1, temp_arg2; 
	printf("Please enter the size of array: ");
	scanf("%ld", &length);
	array=(long*)malloc(length*sizeof(long));	
	printf("\nEnter 1 to add numbers from keyboard or \n2 to get numbers generated randomly (1/2):");
	scanf("%c", &ch);
	ch=getchar();
	switch(ch){
		case '1': for(i=0;i<length;i++){
				printf("\nPlease enter number[%ld] :", i+1);
				scanf("%ld", &array[i]);
			  }
			  break;
		
		case '2': printf("\nGenerating %ld random numbers to get maximum and minimum from them", length);
			  srand(time(NULL));
			  for(i=0;i<length;i++){
				array[i]=rand()%1000000;
			  }
			  
			 break;
		default: 
			printf("\nWrong choice, exiting the program");
			exit(0);
			break;
	}
		
	result=find_minmax(array, 0, length-1 , temp_arg1, temp_arg2);	
	printf("\nMax is : %ld", result.max);
	printf("\nMin is : %ld", result.min);
	printf("\nNumber of comparisons :%d", comparisons);
	printf("\n");
	return 0;
}
		
