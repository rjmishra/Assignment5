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


//Main function starts 

int main(){
	int i,data,length;		//i is used in loops, data is to get data for tree node, length to get number of nodes to be added to tree.
	Node *root;			// root of the tree
	int ch;				//variable for user choice for menu based system.
	printf("\n Please enter the size of tree: ");
	scanf("%d", &length);
	printf("\n Please enter the elements of the tree:\n");		//input for the data for the tree nodes
	for(i=0;i<length;i++){
		scanf("%d", &data);
	
		if(i==0)
			root=init(data);				//tree initialization
		else
			insertNode(data, root);				//tree insertion of nodes
	}

	createThread(root);							//function call to make tree threaded

	do{
		printf("\n################MENU######################");
		printf("\n 1: Inorder traversal\n 2: Preorder Traversal \n 3: Postorder Traversal");
		printf("\n################MENU######################");
		printf("\n\nPlease enter your choice(-1 to exit):");
			
		scanf("%d", &ch);
		
		switch(ch){
				
				
				case 1: printf("\n\nTraversing in inorder: ");	//inorder traversal				
					inorderOfThread(root);
					printf("\n\n");
					break;
				case 2: printf("\n\nTraversing in preorder: ");			//preorder traversal
					preorder(root);
					printf("\n\n");					
					break;
				case 3: printf("\n\nTraversing in postorder: ");	//postorder traversal
					postorder(root);
					printf("\n\n");
					break;
				
				default: break;
			}

		}while(ch!=-1);

return 0;
}
				
