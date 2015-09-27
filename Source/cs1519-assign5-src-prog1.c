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

Node* createNode(int element){
	Node *temp;
	temp=(Node*) malloc(sizeof(Node));
	
	if(temp==NULL){
		perror("\nNot enough space, terminating the program!");
		exit(0);
	}
			
	temp->element=element;
	temp->next=NULL;
	
	return temp;
	
}


Node* init(int element){
	Node *header;
	header=createNode(element);
	return header;
}


Node* addAtBeginning(int element, Node *header){
	Node *newNode;

	if(header==NULL){
		header=init(element);
		return header;
	}
	
	newNode=createNode(element);
	newNode->next=header;
	header=newNode; 
	return header;
	

}
	
void addAtEnd(int element, Node *header){
	Node *newNode, *temp;
	newNode=createNode(element);
	temp=header;
	
	while(temp->next!=NULL){
		temp=temp->next;
	}

	temp->next=newNode;
	
}


void addAtPosition(int position, int element, Node *header){
	Node *newNode, *temp;
	int i=1;
	newNode=createNode(element);
	
	temp=header;
	while(i<position-1){
		temp=temp->next;
		i++;
	}
	newNode->next=temp->next;
	temp->next=newNode;
	

	
}


Node* deleteFromBeginning(Node *header){
	
	Node *temp;
	temp=header;

	if(header==NULL){
		printf("\nList is empty, no elements to delete.");
		return NULL;
	} 
	header=header->next;
	temp->next=NULL;
	free(temp);
	return header;
}



Node* deleteFromEnd(Node *header){
	Node *temp, *parent;
	if(header==NULL){
		printf("\nList is empty, no elements to delete.");
		return NULL;
	} 	
	parent=temp=header;
	
	if(temp->next==NULL){
		free(temp);
		return NULL;
	}
	
	while(temp->next!=NULL){
		parent=temp;		
		temp=temp->next;
	}

	parent->next=NULL;
	free(temp);
	
	return header;

}



Node* deleteFromPosition(int position, Node* header){
	Node *temp, *parent;
	int i=1;
	if(header==NULL){
		printf("\nList is empty, no elements to delete");
		return NULL;
	} 
	parent=temp=header;
	
	if(position==1){
		header=header->next;
		free(temp);
		return header;
	}
	
	while(i<position){
		parent=temp;		
		temp=temp->next;
		i++;
	}
	if(temp==NULL){
		printf("\nPlease check, this is not correct position in the list");
		return	header;
	}
	parent->next=temp->next;
	free(temp);
	return header;
	

}	


void displayList(Node *header){
	Node *temp;
	temp=header;
	if(temp==NULL){
		printf("\nThe list is empty, no elements to display.");
		return;
	}
	
	while(temp!=NULL){
		printf("%d	", temp->element);
		temp=temp->next;
	}
	printf("\n\n");
}



int moveBackandForth(Node *header){
	Node *left, *right;
	Node *temp;
	float random;
	int choice;
	left=right=header;	
	do{
		printf("\n1:Random Walk \n2:Print the list"); 
		printf("\nPlease enter your choice(-1 to exit):");	
		scanf("%d", &choice);	
		switch(choice){
				
			case 1: random = (float) (rand() / (float)RAND_MAX);
				
					if(random<0.5 && right->next==NULL){
						printf("\nReached to end no further forward movement possible!");
						}
					else if(random<0.5 && right->next!=NULL){
						printf("\nMovement Direction: Forward");
						temp=left;
						left=right;
						right=right->next;
						if(left==header)
							left->next=NULL;
						else
							left->next=temp;
						
					}
					else if(random>=0.5 && (left->next==NULL || left==header)){
						printf("\nReached to end no further bacward movement possible!");
					}
					else if(random>=0.5 && left->next!=NULL){
						printf("\nMovement Direction: Backward");						
						temp=right;
						right=left;
						left=left->next;
						right->next=temp;
					}				
					
				break;
			case 2:
				printf("\nForward:");
				displayList(right);
				printf("Backward:");
				displayList(left);
				break;
			default: break;
		}
		
	}while(choice!=-1);
				
	return -1;
				
}

