/*-------------------------------------------------------------------------------------------
Name: Ranjan Mishra
Roll Number: 1519
Date of Submission: 24th Aug 2015
Deadline date: 24th Aug 2015
Program description: Dynamic memory allocations
Acknowledgements:
*/


#include <stdio.h>
#include <stdlib.h>
 
/* The node will be a data structure which will have starting position of memory allocation and 
 * number of bytes allocated and also it will have pointer to the next allocated memory space.
 */
struct node
{
  int pos;
  int size;
  struct node *next;
};
 

/* Below function will search for the free location and will allocate the memory based on the requirements recived
 * it takes the head node i,e. starting location of memory and size of the memory to allocte
 * will retrun -1 if the allocation is not possibles and location of memory if space is allocated succesfully
 */

int allocate_memory(struct node **head_ref , int size){
	struct node *last = *head_ref;
	struct node *prev;
	int r;
	prev = last;
	if(last -> size > size)				//if the first chunk has enough spaces, allocate the space in first chunk,
							// initially the whole memory can be considered as one chunk(first chunk)
	{
		r = last->pos;		
		last->pos = last->pos + size;
		last->size = last->size - size;
		return r;
	}
	
	else if(last->size == size)			// If first chunk has same size as needed, we can free it and allocate t
	{
		last = last->next;
		*head_ref = last;
		r = prev->pos;
		free(prev);
		return r;
	}

	last = last->next;
	
	while(last != NULL){				// Traverse through all nodes, for getting enough space to get allocated.

		if(last->size > size){
			r = last->pos;
			last->pos = last->pos + size;
			last->size = last->size - size;
			return r;
		}
		
		else if(last->size == size){
			r = last->pos;			
			prev->next = last->next;
			free(last);
			return r;
		}
		last = last->next;
		prev = prev->next;
	}

	return -1;

}

/* This function will add newly allocated space information to the allocated list.
*/

void append_allocated_list(struct node** head_ref,int position, int new_data)
{
    
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
 
    struct node *last = *head_ref; 
 
    new_node->pos = position;
    new_node->size  = new_data;
    new_node->next = NULL;
 
    
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
 
    while (last->next != NULL)
        last = last->next;
 

    last->next = new_node;
    return;
}

int update_free(struct node **head_ref , int p){
                                                                            
	struct node *last,*prev;int s;                                      
	last = *head_ref;                                                       
	prev = last;
	
	if(last->pos == p){
		s = last->size;
		last = last->next;
		*head_ref = last;
		free(prev);
		return s;
	}
	
	last = last->next;
		
	while(last != NULL){
		if(last->pos == p){
		s = last->size;
		prev->next = last->next;
		free(last);
		return s;
				  }

		last = last->next;
		prev = prev->next;
	}
	
	return -1;
		
}
/* Append_free_list function appends the new node to the free list maintained as the data structure
 */

void append_free_list(struct node** head1_ref,int position, int new_data){

	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->pos = position;
	new_node->size=new_data;
	new_node->next=NULL;
	
	struct node *p,*last,*n;
	p=*head1_ref;
	last = p->next;

	
	if(new_node->pos < p->pos){

					if((new_node->pos + new_node->size) == p->pos)
					{
						p->pos = new_node->pos;
						p->size = p->size + new_node->size ;
						free(new_node);
						return;
					}
					else{
						new_node->next = p;
						*head1_ref = new_node;return;
					}					
				 }

	while(last != NULL){
		if(new_node->pos < last->pos){
	
		if((new_node->pos + new_node->size) == last->pos && (p->pos + p->size) != new_node->pos) 
			{
				last->pos = new_node->pos;
				last->size = last->size + new_node->size ;
				free(new_node);
				return;
			}

		else if((new_node->pos + new_node->size) != last->pos && (p->pos + p->size) == new_node->pos) 
			{
				p->size = p->size + new_node->size ;
				free(new_node);
				return;
			}

		else if((new_node->pos + new_node->size) == last->pos && (p->pos + p->size) == new_node->pos)
                        {                                                                                     

				
                              p->size = p->size + new_node->size ;
			      
			      p->size = p->size + last->size;	

			      p->next = last->next;
				
			      free(last);

			      return;

			}
		  else  {
				new_node->next = last;				
				p->next = new_node;
					
		        }
        				      }

					last = last->next;
					p = p->next;
		           }
}

/* printlist function will print content of the list
 * which is essentially here is list containg memory locatins allocated or free 
 * it takes starting location of list as argument and prints its contens
 */
void printList(struct node *node)
{
  printf("\n Position\t Size\n");
  while (node != NULL)
  {
     printf("%d\t",node->pos);
     printf(" %d\t", node->size);
     node = node->next;
     printf("\n");
  }
}
 

int main()
{
  	
  	struct node* allocated = NULL;   	// The list which has the list of all allocation done, initally null as no allocation is done.
  	struct node* freed;         		// List of freed allocations, initially it has size as 100000 as all space is free.
	  char arr[100000];
	  char ch, type;				// ch for choice and type for data type as input from user
	  int size, total_size;			// size is the number of allocations for type data type, total_size=
	  freed= (struct node *)malloc(sizeof(struct node));
	
	  freed->pos =0;
	  freed->size = 100000;
	  freed->next = NULL;
	
	  printf("#################  MENU ###############\n");
		printf("\n 'A' to Allocate \n");
		printf("\n 'F' to Free\n");
		printf("\n 'Q' to Quit\n");	
		printf("#######################################\n");	
		ch = getchar();	
  
 	while(ch!='Q'){		
		if(ch=='a'||ch=='A'){
				printf("\nPlease select data type from below\n");
				printf("\n 'i' for integer");
				printf("\n 'c' for char");
				printf("\n 'f' for float\n");
				
				scanf("%c",&type);
				type=getchar();
				printf("\nYou have selected %c, \nHow much space do you need to allocate: ", type);
				scanf("%d",&size);
				if(type == 'i')
					total_size = size * sizeof(int);
				else if(type == 'c')
					total_size = size * sizeof(char);
				else if(type == 'f')
					total_size = size * sizeof(float);
				printf("\nTotal size will be allocated in bytes is: %d", total_size);
				int check = allocate_memory(&freed , total_size);
				if(check != -1){
						printf("\nSpace has been allocated\n");
						printf("\nStarting address is: %d\n",check);
						append_allocated_list(&allocated,check,total_size);
						printf("\nOccupied Memory addresses are:\n");
						printList(allocated);
						printf("\nFree memory chunks are:\n");
						printList(freed);
					      }
				else printf("Allocation not possible!!");
				}
		if(ch=='f'||ch=='F') {
				printf("Please enter address of that chunk of memory needs to be free!\n");
				int address;
				scanf("%d",&address);
				int check = update_free(&allocated,address);
				if(check != -1){
            printf("Memory has been freed\n");
						append_free_list(&freed,address,check);
						printf("Allocated  List\n");
						printList(allocated);
						printf("\nFree List \n");
						printList(freed);
				}

				else printf("\nNo such memory has been allocated \n");
			}
		printf("#################  MENU ###############\n");
		printf("\n 'A' to Allocate \n");
		printf("\n 'F' to Free\n");
		printf("\n 'Q' to Quit\n");	
		printf("#######################################\n");	
		ch=getchar();
		
	}
  return 0;
}

