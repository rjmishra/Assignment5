/*------------------------------------------------------------------
Name: Ranjan Mishra
Roll Number: CS1519
Date of Submission: 3rd Nov 2015
Deadline date: 3rd Nov 2015
Program description: Trie implementation, along with word suggestions
Acknowledgements: 
--------------------------------------------------------------------*/

#include "cs1519-assign8-prog1.h"
#include<stdio.h>
#include<string.h>


/* main function begins 
 */

int main(void){
	
	int ch,searchResult, length;	
	int i;			
	char word[50];
	node *root;					//root node of the trie.
	
	root=createNode();				//root node initialization
	
	loadFromFile("/usr/share/dict/words", root);			//loading the dictionary file.
	

	do{						//for serach operation
	
		printf("\n\nTo search a word, please enter 1(-1 to exit) : ");
		scanf("%d", &ch);
		
		
		if(ch == 1){
			printf("\nPlease enter the word to search : ");
			scanf("%s", word);
			
			length=strlen(word);			

			for(i=0;i<length;i++){				//converting the word to uppercase
				if(word[i]<123 && word[i]>96)
					word[i]=word[i]-('a'-'A');
			}
			
			searchResult = search(root, word);		//searching the trie

			if(searchResult)					//in case word is in TRIE
				printf("\nWord '%s' is found in dictionary!", word);
			else{							//in case its not, printing suggestions
				printf("\nNo such word '%s' in dictionary, here are few suggestion for the word!", word);
				generateSuggestions(root, word);
			}
	
		}
	}while(ch!=-1);
	
	return 0;
}
