/*------------------------------------------------------------------
Name: Ranjan Mishra
Roll Number: CS1519
Date of Submission:
Deadline date: 
Program description:
Acknowledgements:
--------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include"cs1519-assign5-prog1.h"

int main(){
	
	int i,ch, numNode, position;
	int element, direction, move;
	Node *header, *currentNode, **previousNode;
	header=NULL;
	
	printf("\nPlease enter the initial number of nodes in the list: ");
	scanf("%d", &numNode);
	
	for(i=0;i<numNode;i++){
		printf("\nPlease enter the element for the node%d :", i+1);
		scanf("%d", &element);
		if(i==0)
			header=init(element);
		else
			addAtEnd(element, header);
	}

	
	
	do{
		printf("\n\n##########################MENU##########################");
		printf("\n\n1: Add Node at Beginning\n2: Add node at end\n3: Add node at particular position");
		printf("\n4: Delete Node from Beginning\n5: Delete node from End\n6: Delete node from particular position");
		printf("\n7: Display the content of the list\n8: To and Fro Motion");		
		printf("\n\n########################################################"); 
		printf("\n\nPlease enter your choice(-1 to exit):");
		scanf("%d", &ch);
	
		switch(ch){
			case 1:
				printf("\nPlease enter the element for the new node:");
				scanf("%d", &element);
				header=addAtBeginning(element, header);
				break;
			case 2:
				printf("\nPlease enter the element for the new node:");
				scanf("%d", &element);
				addAtEnd(element, header);
				break;
			case 3:
				printf("\nPlease enter the position for the new node:");
				scanf("%d", &position);
				if(position<=0){
					printf("\nPosition must be greater than 1");
					printf("\nPlease enter the position again:");
					scanf("%d", &position);
				}
				printf("\nPlease enter the element for the new node:");
				scanf("%d", &element);
				addAtPosition(position, element, header);
				break;
			case 4:
				header=deleteFromBeginning(header);
				break;
			case 5:
				header=deleteFromEnd(header);
				break;
	
			case 6:
				printf("\nPlease enter the position for the deletion");
				scanf("%d", &position);
				if(position<=0){
					printf("\nPosition must be greater than 1");
					printf("\nPlease enter the position again:");
					scanf("%d", &position);
				}
				header=deleteFromPosition(position, header);
				break;
			
			case 7:
				displayList(header);
				break;

			case 8: 
				//backAndForth(header);	
				break;
					
			default: break;
		
		}
	}while(ch!=-1);

	return 0;
}
