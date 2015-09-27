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
#include"cs1519-assign5-prog2.h"

int main(){
	
	int i,ch, numNode, choice;
	int element;
	Node *header, *loopNode;
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
		printf("\n\n1: Add a new Node \n2: Detect existence of loop");
		printf("\n3: Display the content of the list");		
		printf("\n\n########################################################"); 
		printf("\n\nPlease enter your choice(-1 to exit):");
		scanf("%d", &ch);
	
		switch(ch){
			case 1:
				printf("\n1: For adding at end \n2: Adding back as loop");
				printf("\nPlease enter your choice: ");	
				scanf("%d", &choice);			
				printf("\nPlease enter the element for the new node:");
				scanf("%d", &element);
				if(choice==1)
				addAtEnd(element, header);
				else if(choice==2){
				addAtEndLoop(element, header, numNode);
				}
				numNode++;
				break;

			case 2: 
				loopNode=detectLoop(header);
				if(loopNode!=NULL){
					printf("\nLoop detected at node with element: %d", loopNode->element);
				}
				else
					printf("\nNo Loop detected ");
				break;
			case 3:
				displayList(header);
				break;

	
					
			default: break;
		
		}
	}while(ch!=-1);

	return 0;
}
