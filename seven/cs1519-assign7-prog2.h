/*------------------------------------------------------------------
Name:  Ranjan Mishra
Roll Number: 1519
Date of Submission: 15th oct 2015
Deadline date:  16th Oct 2015
Program description: 2dimensional tree and range search on it.
Acknowledgements: 
--------------------------------------------------------------------*/

/* Struct to contain a single two dimensional point
 * it has x and y components
 */
typedef struct point{
	double x;
	double y;
}Point;


/* struscture of a node for 2D tree
 * it has two pointers for its right and left children
 * and a point struct as defined above
 */

typedef struct node{
	Point p;
	struct node *left;
	struct node *right;
}Node;


/* Desc: This function allocates the memory for given number(n) of points
   Arguments: It takes number of points to be allocted spaces as input of integer type
   Return: It returns the pointer to the alloctaed space
*/
Point* alloacate(int n);


/* Desc: This function sorts the points in the given array of points
   Arguments: It takes the pointer to the array of points, start index and end index of array positions tobe sorted and 
              dimension information based on which sorting is to be done, in this case 0 for X and 1 for Y dimensions.
   Return: None.
*/
void sortPoints(Point *points, int start, int end, int dim);

/* Desc: This function inserts the given points in the tree
   Arguments: It takes array of points to be inserted and start and end of the array, and the dimnsion info as above
   Return: It returns the root of the tree created
*/
Node* insert(Point *points, int start, int end, int dim);

/* Desc: This function searches the points which lie in given rectangular range
   Argumnets: The tree root node, range of the rectangle as x, x1 and y, y1 and dim info as above
   Return: None, it prints the points within the range.
*/
void searchRange(double x, double x1, double y, double y1, Node *root, int dim);


