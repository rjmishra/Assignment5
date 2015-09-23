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


typedef struct node{
	int element;
	struct node *next;
	} Node;


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
		printf("\nHeader seems to be null!");
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
	header=header->next;
	temp->next=NULL;
	free(temp);
	return header;
}

void deleteFromEnd(Node *header){
	Node *temp, *parent;
	parent=temp=header;
	
	while(temp->next!=NULL){
		parent=temp;		
		temp=temp->next;
	}

	parent->next=NULL;
	free(temp);

}

void deleteFromPosition(int position, Node* header){
	Node *temp, *parent;
	int i=1;
	parent=temp=header;
	
	while(i<position){
		parent=temp;		
		temp=temp->next;
		i++;
	}
	if(temp==NULL){
		printf("\nPlease check, this is not correct position in the list");
		return;
	}
	parent->next=temp->next;
	free(temp);
	

}	


void displayList(Node *header){
	Node *temp;
	temp=header;
	if(temp==NULL){
		printf("\nList is empty");
		return;
	}
	
	printf("\nDisplaying the elements of the list: \n");
	while(temp!=NULL){
		printf("%d	", temp->element);
		temp=temp->next;
	}
	printf("\n");
}


int main(){
	
	int i,ch, numNode, position;
	int element;
	Node *header;
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
		printf("\n7: Display the content of the list");		
		printf("\n\n########################################################"); 
		printf("\n\nPlease enter your choice(-1 to exit):");
		scanf("%d", &ch);
	
		switch(ch){
			case 1:
				printf("\nPlease enter the element for the node");
				scanf("%d", &element);
				header=addAtBeginning(element, header);
				break;
			case 2:
				printf("\nPlease enter the element for the node");
				scanf("%d", &element);
				addAtEnd(element, header);
				break;
			case 3:
				printf("\nPlease enter the position for the new node");
				scanf("%d", &position);
				printf("\nPlease enter the element for the node");
				scanf("%d", &element);
				addAtPosition(position, element, header);
				break;
			case 4:
				header=deleteFromBeginning(header);
				break;
			case 5:
				deleteFromEnd(header);
				break;
	
			case 6:
				printf("\nPlease enter the position for the deletion");
				scanf("%d", &position);
				deleteFromPosition(position, header);
				break;
			
			case 7:
				displayList(header);
				break;	
			default: break;
		
		}
	}while(ch!=-1);

	return 0;
}



	
	

