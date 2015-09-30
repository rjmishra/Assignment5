/* 
 * Name : Ranjan Mishra
 * Roll : CS1519(MTech)
 * Program: Non recursive inorder travesral of Binary Search Tree
 */
#define MAX_SIZE 100

typdef struct Stack{
	Node st[MAX_SIZE];
	int top=-1;
}STACK;

void push(Node *node, STACK *stack){
	stack->top=stack->top+1;
	stack->st[stack->top]=node;
}

void pop(STACK *stack){
	Node *node;	
	if(top==-1){
		return NULL:
	}
	node=stack->st[top];
	stack->top=stack->top-1;
	return node;
 }

void inorder(Node *node){
	STACK stack;	
	while(1){
		for(;node;node=node->left)
			push(node, stack);
		node=pop(stack);
		
		if(!node)
			break;
		printf("%d\t", node->data);
		node=node->right;
	}
}
		
