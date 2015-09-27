/*------------------------------------------------------------------
Name: Ranjan Mishra
Roll Number: CS1519
Date of Submission:
Deadline date: 
Program description:
Acknowledgements:
--------------------------------------------------------------------*/


typedef struct node{
	int element;
	struct node *next;
	} Node;

Node* createNode(int element);
Node* init(int element);
void addAtEnd(int element, Node *header);
void displayList(Node *header);
Node* detectLoop(Node *header);
void addAtEndLoop(int element, Node *header, int numNodes);


