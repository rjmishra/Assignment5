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



Node* detectLoop(Node *header){
	int result = 0, count, i;
	Node *slow, *fast;
	slow=fast=header;
	while(slow!=NULL&&fast!=NULL&&fast->next!=NULL){		
		slow=slow->next;
		fast=fast->next->next;
		if((slow==fast)){
			result=1;		
			break;
		}
		
	}
	
	if(result==1){
		fast=header;
		while(fast!=slow){
			fast=fast->next;
			slow=slow->next;
					
		}
		return fast;
	}
		
	else
		return NULL;
}	


void displayList(Node *header){
	Node *temp, *loopNode;
	temp=header;
	if(temp==NULL){
		printf("\nThe list is empty, no elements to display.");
		return;
	}
	loopNode=detectLoop(header);
	if(loopNode==NULL){	
		while(temp!=NULL){
			printf("%d	", temp->element);
			temp=temp->next;
		}
	}
	else if(loopNode->next==header){	
		while(temp!=loopNode){
			printf("%d	", temp->element);
			temp=temp->next;
		}
	}
		
	else {
		
		while(temp!=loopNode){
			printf("%d	", temp->element);
			temp=temp->next;
		}
		printf("%d	", temp->element);
		temp=loopNode->next;
		while(temp!=loopNode){
			printf("%d	", temp->element);
			temp=temp->next;
		}
	}
}



void addAtEndLoop(int element, Node *header, int numNodes){
	Node *newNode, *temp, *nextToTemp, *loop;
	Node *previous;
	int random;
	loop=detectLoop(header);
	if(loop!=NULL){
		printf("\nLoop is already present, can not be added");
		return;
	}
	newNode=createNode(element);
	nextToTemp=header;
	temp=header;
	random=(rand() % (numNodes));
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newNode;
	while(random>0){
		previous=nextToTemp;		
		nextToTemp=nextToTemp->next;
		random--;
	}

	newNode->next=previous;
	
}

void addAtEnd(int element, Node *header){
	Node *newNode, *temp, *loop, *loopPrevious;
	newNode=createNode(element);
	temp=header;
	
	loop=detectLoop(header);
	if(loop==NULL){	
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode;
	}

	else{
		printf("\nLoop element is:%d", loop->element);
		loopPrevious=loop;
		while(loopPrevious->next!=loop){
			loopPrevious=loopPrevious->next;
		}
		loopPrevious->next=newNode;
	}
}

