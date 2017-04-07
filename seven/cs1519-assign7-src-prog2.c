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



/* Desc: This function allocates the memory for given number(n) of points
   Arguments: It takes number of points to be allocted spaces as input of integer type
   Return: It returns the pointer to the alloctaed space
*/

Point* alloacate(int n){
	Point *p;
	p=(Point*) malloc(sizeof(Point)*n);
	if(!p){	//In case memory allocation not possible
		perror("\nInsufficient memory!");
		exit(0);
	}

	return p;
}



/* Desc: This function sorts the points in the given array of points
   Arguments: It takes the pointer to the array of points, start index and end index of array positions tobe sorted and 
              dimension information based on which sorting is to be done, in this case 0 for X and 1 for Y dimensions.
   Return: None.
*/
void sortPoints(Point *points, int start, int end, int dim){
	int i, j;
	Point temp;
	if(dim==0){ //sorting based on x dimension
		 for(i=start+1;i<=end;i++){	//insertion sort
			j=i;
			while(j>start && points[j-1].x>points[j].x){
				temp=points[j-1];
				points[j-1]=points[j];
				points[j]=temp;
				j--;
			}
		}
	}
	else{	//sorting based of y dimension
		for(i=start+1;i<=end;i++){	//insertion sort
			j=i;
			while(j>start && points[j-1].y>points[j].y){

		
				temp=points[j-1];
				points[j-1]=points[j];
				points[j]=temp;
				j--;
			}
		}
	}
}
	

/* Desc: This function inserts the given points in the tree, it is recursive function
   Arguments: It takes array of points to be inserted and start and end of the array, and the dimnsion info as above
   Return: It returns the root of the tree created
*/	
Node* insert(Point *points, int start, int end, int dim){
	Node *root;	
	int median, i;
	if(end<start){		//in case we reached a condition where we dont have any point to add to tree
		return NULL;
	}
	sortPoints(points, start, end, dim);			//sort the points based on current dimnsion

	median=(start+end)/2;	//insert the mid point in the tree
	root=(Node*) malloc(sizeof(Node));
	root->p=points[median];
	root->left=insert(points, start, median-1, 1-dim);		//left side of sorted array to be inserted in left subtree
	root->right=insert(points, median+1, end, 1-dim);		//right side of the sorted array to be inserted in right subtree
	
	return root;
}
	

/* Desc: This function searches the points which lie in given rectangular range
   Argumnets: The tree root node, range of the rectangle as x, x1 and y, y1 and dim info as above
   Return: None, it prints the points within the range.
*/
void searchRange(double x, double x1, double y, double y1, Node *root, int dim){
	 if(root==NULL)			//function reached to end of tree
		return;
	 else{
		if(dim==0){		//based on x dimension
			if(x<=root->p.x && x1>=root->p.x){		//if range contains the current point, it must go both left and right
				printf("(%lf , %lf)\t", root->p.x, root->p.y);
				searchRange(x, x1, y, y1, root->left, 1-dim);
				searchRange(x, x1, y, y1, root->right, 1-dim);
			 }
			else if(x<root->p.x && x1<root->p.x){		//points lie on left side of the current node
				searchRange(x, x1, y, y1, root->left, 1-dim);
			}
			else if(x>root->p.x && x1>root->p.x){		//points lie on the right side of the current node
				searchRange(x, x1, y, y1, root->left, 1-dim);
			}
		}
		else if(dim==1){	//based on y dimension
			if(y<=root->p.y && y1>=root->p.y){		//if range contains the current point, it must go both left and right
				printf("(%lf , %lf)\t", root->p.x, root->p.y);
				searchRange(x, x1, y, y1, root->left, 1-dim);
				searchRange(x, x1, y, y1, root->right, 1-dim);
			 }
			else if(y<root->p.y && y1<root->p.y){		//points lie on left side of the current node
				searchRange(x, x1, y, y1, root->left, 1-dim);
			}
			else if(y>root->p.y && y1>root->p.y){		//points lie on right side of the current node
				searchRange(x, x1, y, y1, root->left, 1-dim);
			}
	}	}
}

