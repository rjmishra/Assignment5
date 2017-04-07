/*------------------------------------------------------------------
Name: Ranjan Mishra
Roll Number: 1519
Date of Submission: 15th Oct 2015
Deadline date:  16th Oct 2015
Program description: Threaded binary tree implementation and traversal of the tree.
Acknowledgements:  http://comjnl.oxfordjournals.org/content/24/2/148.full.pdf for postorder traversal.
--------------------------------------------------------------------*/

#include"cs1519-assign7-prog1.h"
#include<stdio.h>
#include<stdlib.h>

Node* stack[MAX_SIZE];			//temporary array to store the BST pointers in inorder
int top=0;				//for indexing of above array.


/* Purpose of function: To initialize the tree
 * Argumnets: It will take int(data) as argument for data corresponding to root
 * Return type: It will return the tree node(namely the root node of the tree).
 */
Node* init(int data){
	Node* root;
	root=(Node*)malloc(sizeof(Node));
	if(root==NULL){
		perror("\nNot enough spaces!");
		exit(0);
	}
	root->data=data;
	root->left=NULL;
	root->right=NULL;
	root->thread=0;

	return root;
}


/* Purpose of function: To insert new node in the binary search tree
 * Argumnets: It will take int(data) and root of the tree as arguments
 * Return type: It returns nothing.
*/
void insertNode(int data, Node* root){
	Node* newNode;
	Node *temp, *parent;
	int sideInd=0;parent=temp=root;
	
	while(temp!=NULL){
		parent=temp;
		if(data>temp->data){		//if data is greater, move to right
			temp=temp->right;
		}
		else if(data<temp->data){	//if data is greater, move to right
			temp=temp->left;
		}
		else{
			printf("\nNode with given element is already present!");
			return;
		}
	}
	newNode=(Node*)malloc(sizeof(Node));
	if(newNode==NULL){
		perror("\nNot enough spaces!");
		exit(0);
	}
	newNode->data=data;			//add new node to tree
	newNode->right=NULL;
	newNode->left=NULL;
	newNode->thread=0;			//initially thread is assigned 0, meaning no therad links present
	
	if(data<parent->data)
		parent->left=newNode;
	else
		parent->right=newNode;
}


/* Purpose of function: This function traverse the BST and stores it in array named stack, that can be used for creating thread.
 * Argumnets: It will root of the tree as input
 * Return type: none
 */

void inorder(Node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	stack[top++]=root;
	inorder(root->right);
	
}






/* Purpose of function: This function creates the threaded links whenever it finds the links are null for BST.
 * Arguments: It takes root of tree as argument.
 * Return Type: None
*/

void createThread(Node *root){
	int i=0;
	inorder(root);
	for(i=0;i<top;i++){
		if(stack[i]->left==NULL && i!=0){		//left link is null then assign it to inorder predecessor
			stack[i]->left=stack[i-1];
			stack[i]->thread=1;
		}
		if(stack[i]->right==NULL && i!=top-1){		//right link is null then assign it to inorder successor
			stack[i]->right=stack[i+1];
			if(stack[i]->thread==1)
				stack[i]->thread=3;
			else 
				stack[i]->thread=2;
		}
	}
}


/* Puropse of Function: This function returns the leftmost node of the current node, which is not threaded link
 * Argument: It takes current node as argument
 * Return: It returns the leftmost node of the current node.
*/

Node* leftOfNode(Node *root){
	if(root==NULL)
		return NULL;
	while(root->left!=NULL && (root->thread!=1 && root->thread!=3))
		root=root->left;
	return root;
}



/* Purpose of Function: This function prints the threaded BST in inorder.
 * Argumnt: It takes root of the tree as argumnet.
 * Return: None.
 */
void inorderOfThread(Node *root){
	Node *temp;
	temp=leftOfNode(root);			//first node in inorder is leftmost non threaded link of root.
	while(temp!=NULL){
		printf("\t%d", temp->data);
		
		if(temp->thread==2 || temp->thread==3){		//if there is any right threaded link its inorder successor of current node.
			temp=temp->right;
		}
		else 
			temp=leftOfNode(temp->right);		//if no right threaded link call function to find leftmost of right subtree
	}
}


/* Purpose of Function: This function finds the successor of the node in preorder traversal 
 * Argumnt: It takes current node of the tree as argumnet.
 * Return: it returns the preorder successor of the current node.
 */
Node* preSuccessor(Node *root){
	if(root->left!=NULL && (root->thread!=1 && root->thread!=3))	//if nodes left link is not threaded return the left child.
		return root->left;
	else{								// if not the above condition find the first right link not threaded
		while(root->right!=NULL && (root->thread==2 || root->thread==3))
			root=root->right;
		root=root->right;
	}
	
	return root;
}
	

/* Purpose of Function: To find the first node in postorder traversal. 
 * Argumnt: It takes root node of the tree as argumnet.
 * Return: it returns the first node in postorder traversal.
 */
Node* postFirst(Node *root){
	if(root->left==NULL && (root->thread==2 || root->thread==3)){	//if left child is not null and right link is threaded return the node itself
		return root;
	}
	else if(root->thread==3){		//if both the links are threaded then also the node itself is first postorder node
		return root;
	}
	else if(root->left==NULL && (root->thread!=2 && root->thread!=3)){	// if left child is null but right is not threaded call the 
										// function recursively with right child.
		return postFirst(root->right);
	}	
	return postFirst(root->left);				//if not all above cases call the function recursive with left child.
}



/* Purpose of Function: This function finds the successor of the node in postorder traversal 
 * Argumnt: It takes current node of the tree as argumnet.
 * Return: it returns the postorder successor of the current node.
 * Ackn: the algorithms used for this function is taken from the reaserch paper loacted at : 
 *       http://comjnl.oxfordjournals.org/content/24/2/148.full.pdf
 */
Node* postSuccessor(Node *root){
	Node *temp;
	temp=root;
	
	while(root->right!=NULL && (root->thread!=2 && root->thread!=3)){	//find the rightmost not threaded link.
		root=root->right;
	}
	if(root->right)	root=root->right;		// if right of node is not null, make node as right of itself.

	if(root->left==temp){				
			if(root->right==NULL){		
				root=root->left;
				while((root->thread!=1 && root->thread!=3)){ //find the rightmost of left child.
					root=root->left;
				}
				return root->left;
			}
			
			while(root->right!=NULL && (root->thread!=2 && root->thread!=3)){	//find the righmost of node.
				root=root->right;

			while(root->left!=NULL && (root->thread!=1 && root->thread!=3)){	//find the leftmost of node.
				root=root->left;
			}
		}
	}
	else {
		root=root->left;

		while(root->right!=temp){			//right child of the node is not the node we started, takethe right most
			root=root->right;
		}
	}

	return root;
}
	
	
		


/* Purpose of Function: This function prints the threaded BST in preorder.
 * Argumnt: It takes root of the tree as argumnet.
 * Return: None.
 */
void preorder(Node *root){
	while(root!=NULL){
		printf("%d\t", root->data);
		root=preSuccessor(root);
	}
}


/* Purpose of Function: This function prints the threaded BST in postorder.
 * Argumnt: It takes root of the tree as argumnet.
 * Return: None.
 */


void postorder(Node *root){
	Node *temp=root;
	root=postFirst(root);	
	while(root!=temp){
		printf("%d\t", root->data);
		root=postSuccessor(root);
	}
	printf("%d\t", root->data);
}


