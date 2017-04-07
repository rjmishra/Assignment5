/*------------------------------------------------------------------
Name: Ranjan Mishra
Roll Number: 1519
Date of Submission: 15th Oct 2015
Deadline date:  16th Oct 2015
Program description: Threaded binary tree implementation and traversal of the tree.
Acknowledgements:  http://comjnl.oxfordjournals.org/content/24/2/148.full.pdf for postorder traversal.
--------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
/* Structre of the binary tree
* it contains a data field and two pointers for left and right children
*/


#define MAX_SIZE 100

/* structure of the node for the threade tree
 * it has two pointers for left and right subtrees
 * data is the data to be stored in the tree.
 * and it has thread which represents whether links are original or threaded
 * 0 for original links, 1 for left link threaded, 2 for right link threaded and 3 for both the links threaded.
 */

typedef struct node{
int data;
struct node* left;
struct node* right;
int thread;
} Node;


/* Purpose of function: To initialize the tree
 * Argumnets: It will take int(data) as argument for data corresponding to root
 * Return type: It will return the tree node(namely the root node of the tree).
 */
Node* init(int data);



/* Purpose of function: To insert new node in the binary search tree
 * Argumnets: It will take int(data) and root of the tree as arguments
 * Return type: It returns nothing.
*/
void insertNode(int data, Node* root);


/* Purpose of function: This function traverse the BST and stores it in array named stack, that can be used for creating thread.
 * Argumnets: It will root of the tree as input
 * Return type: none
*/
void inorder(Node *root);


/* Purpose of function: This function creates the threaded links whenever it finds the links are null for BST.
 * Arguments: It takes root of node as argument
 * Return Type: None
*/
void createThread(Node *root);


/* Puropse of Function: This function returns the leftmost node of the current node which is not threaded link
 * Argument: It takes current node as argument
 * Return: It returns the leftmost node of the current node.
*/
Node* leftOfNode(Node *root);


/* Purpose of Function: This function prints the threaded BST in inorder.
 * Argumnt: It takes root of the tree as argumnet.
 * Return: None.
 */
void inorderOfThread(Node *root);



/* Purpose of Function: This function finds the successor of the node in preorder traversal 
 * Argumnt: It takes current node of the tree as argumnet.
 * Return: it returns the preorder successor of the current node.
 */

Node* preSuccessor(Node *root);



/* Purpose of Function: To find the first node in postorder traversal. 
 * Argumnt: It takes root node of the tree as argumnet.
 * Return: it returns the first node in postorder traversal.
 */

Node* postFirst(Node *root);


/* Purpose of Function: This function finds the successor of the node in postorder traversal 
 * Argumnt: It takes current node of the tree as argumnet.
 * Return: it returns the postorder successor of the current node.
 */


Node* postSuccessor(Node *root);



/* Purpose of Function: This function prints the threaded BST in preorder.
 * Argumnt: It takes root of the tree as argumnet.
 * Return: None.
 */
void preorder(Node *root);



/* Purpose of Function: This function prints the threaded BST in postorder.
 * Argumnt: It takes root of the tree as argumnet.
 * Return: None.
 */

void postorder(Node *root);






