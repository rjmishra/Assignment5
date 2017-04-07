/*------------------------------------------------------------------
Name:  Ranjan Mishra
Roll Number: 1519
Date of Submission: 15th oct 2015
Deadline date:  16th Oct 2015
Program description: 2dimensional tree and range search on it.
Acknowledgements: 
--------------------------------------------------------------------*/
#include"cs1519-assign7-prog2.h"
#include<stdio.h>
#include<stdlib.h>

//Main function starts 

int main(){
	
	int n, i;		//n is number of points and i is used as loop variable
	Point *points;		// points are stored initially in this array
	double x, x1, y, y1;	// varibales to hold rectangular range
	Node *root2D;
	printf("\nPlease enter number of points:");
	scanf("%d", &n);
	
	points=alloacate(n);	//memory allocation for points
	printf("\nPlease enter points: ");
	for(i=1;i<=n;i++){
		scanf("%lf%lf", &points[i].x, &points[i].y);
	}

	root2D=insert(points, 1, n, 0);	//inserting points in 2D tree, initil dimnsion considered is X

	printf("\nPlease enter the x and x1: ");
	scanf("%lf%lf", &x, &x1);

	printf("\nPlease enter the y and y1: ");
	scanf("%lf%lf", &y, &y1);

	printf("\nPoint(s) within asked range is(are)\n"); 
	searchRange(x, x1, y, y1,root2D, 0);		//range search based on given input, initial dimnsion considered is X.
	return 0;
}
