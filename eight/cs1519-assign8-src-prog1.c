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
#include<stdlib.h>



/* Puropse : To craeate a new trie node
   Arguments: None
   Return Value: pointer to new trie node created.
*/
node* createNode(){
	int i;
	node *newNode;
	newNode = (node*) malloc(sizeof(node));

	if(!newNode){
		perror("\nInsufficient memory!!");	//in case memory allocation fails, terminate the program
		exit(0);
	}


	newNode->isLeaf=1;		//new node created is by default set as leaf node.
	newNode->isWord=0;		//new node craeted is set not to be representing a word.
	return newNode;

}
	


/* Puropse : Insertion corresponding to the new word in TRIE
   Arguments: root of the TRIE and the new word to be inserted.
   Return Value: None.
*/

void insert(node *root, char *word){
	int length, i;
	length=strlen(word);
	node *temp;
	for(i=0;i<length;i++){		//loops through all the characters in the word to reach final child node
		
				
		if(root->isLeaf || root->children[word[i]-ASCII_START]==NULL){	//if this is leaf node or this node is not child correspondin
										// to the letter we are considering
			temp=createNode();
			root->children[word[i]-ASCII_START]=temp;		//create a new child with the corresponding letter
			root->isLeaf=0;
			root=root->children[word[i]-ASCII_START];
		}
		else{							//in case it is laready having child with letter considered
			root=root->children[word[i]-ASCII_START];
		}
	}

	if(root->isWord==1){					//if its already a word in TRIE simply return from function
		return;	
	}
	else if(temp!=NULL){					//after looping through all letters if it was new node added 
		temp->isWord=1;
	}
	else							//if that node was already existing, but not represeniting a word.		
		root->isWord=1;	
}
	
	

/* Puropse : To search the word in TRIE
   Arguments: The word to be searched in TRIE and root of the TRIE
   Return Value: returns 1 in case word is in TRIE and 0 otherwise.
*/
int search(node *root, char *word){
	int length, i=0;
	length=strlen(word);					//length of word
	
	
	while(i<length && root){				//loop through all letters of word
		root=root->children[word[i]-ASCII_START];
		i++;
	}

	if(root!=NULL && root->isWord){			//if isWord is 1, that means we found the word
		return 1;				
	}
	else 						//in case the either we rached a null node or isWord is not 1, that word is not present.
		return 0;			
}


	

/* Puropse : To load the dictionary file from system and store the words in TRIE
   Arguments: name of the file as string and root of the TRIE.
   Return Value: none
*/

void loadFromFile(char *fileName, node *root){
	FILE *fp;				//file pointer
	char word[50];
	char c;
	int length, i;
	
	fp=fopen(fileName, "r");		//open the file in read mode
	
	do{
		c = fscanf(fp, "%s", word);	//scan the file and call the insert function for each word.
		
		length=strlen(word);

		for(i=0;i<length;i++){		//converting the alphabets to uppercase.
			if(word[i]<123 && word[i]>96)
				word[i]=word[i]-('a'-'A');
		}
		
		insert(root, word);
	 }while(c != EOF);

	fclose(fp);				//closing the file.

}
	



/* Puropse : To generate the suggestions based on the word searched, in case the word is not in TRIE.
   Arguments: root of the TRIE and the word which was searched.
   Return Value: none
*/

void suggestOnDelete(node *root, char *word){

	int length, result;
	int i=0,k,j=0;
	char *newWord;
	length=strlen(word);	
	newWord=(char*) malloc(sizeof(char)*length);
	
	if(!newWord){					// a new string is created to temporary store words by deleting one letter from
		perror("\nInsufficient Memory!");	// the original searched word.
		exit(0);
	}
	
	for(k=0;k<length;k++){				//looping through the length of words to delete one caharcter at a time.		
		while(word[i]){				
			if(i!=k){			//for each outer loop one letter will be skipped, and other will be stored in 		
				newWord[j]=word[i];	// the newWord named string.	
				i++;
				j++;
			}
			else				//skipping one letter
				i++;
		}
		newWord[j]='\0';			//storing null at the end for the safer side.
		i=0;
		j=0;
		result=search(root, newWord);		//search the newWord in the TRIE.
		if(result)
			printf("\n%s", newWord);	//if the newWord is in TRIE, print it as suggestion

	}
}


/* Puropse : Subfunction of generateSuggestions, this geerates the suggestions by changing one letter in the given word.
   Arguments: root of the TRIE and the word which was searched.
   Return Value: none
*/

void suggestOnChange(node *root, char *word){
	
	int length, result;
	int i=0,k,j=0, alpha;
	char *newWord;
	length=strlen(word);	
	newWord=(char*) malloc(sizeof(char)*(length+1));
	
	if(!newWord){					// a new string is created to temporary store words by changing one letter from
		perror("\nInsufficient Memory!");	// the original searched word.
		exit(0);
	}
	
	for(alpha=0;alpha<26;alpha++){			//looping through all the english alphabet, so that each position gets changed with
		for(k=0;k<length;k++){			// all letters in English alphabet
			while(word[i]){
				if(i!=k){		//changing the letter in the newWord
					newWord[j]=word[i];
				
				}
				else{				//retaining all other letters as it is from word(original search word)
					newWord[j]='A'+alpha;
				}
				i++;
				j++;
			}

			newWord[j]='\0';			//storing null at the end for the safer side.
			i=0;
			j=0;
	
			result=search(root, newWord);		//search the newWord in the TRIE.

			if(result)
				printf("\n%s", newWord);	//if the newWord is in TRIE, print it as suggestion
		}
	}
}



/* Puropse : Subfunction of generateSuggestions, this geerates the suggestions by inserting one letter in the given word.
   Arguments: root of the TRIE and the word which was searched.
   Return Value: none
*/

void suggestOnInsert(node *root, char *word){
	
	int length, result;
	int i=0,k,j=0, alpha;
	char *newWord;
	length=strlen(word);	
	newWord=(char*) malloc(sizeof(char)*(length+2));
	
	if(!newWord){					// a new string is created to temporary store words by changing one letter from
		perror("\nInsufficient Memory!");	// the original searched word.
		exit(0);
	}
	
	for(alpha=0;alpha<26;alpha++){			//looping through all the english alphabet, so that each position gets inserted with
		for(k=0;k<=length;k++){			// all letters in English alphabet
			while(word[i]){
				if(j==k){			//inserting a new letter
					newWord[j]='A'+alpha;
					j++;
				
				}
				else{				//retaining all other letters
					newWord[j]=word[i];
					i++;
					j++;
				}
									
			}
			if(k==length){				//in case of adding at the end of the string
				newWord[j]='A'+alpha;
				j++;
			}
				
			newWord[j]='\0';			//storing null at the end for the safer side.
			i=0;
			j=0;
	
			result=search(root, newWord);		//search the newWord in the TRIE.
			if(result)
				printf("\n%s",newWord);		//if the newWord is in TRIE, print it as suggestion
		}
	}
}



/* Puropse : To swap two given characters.
   Arguments: Pointers to the characters to be swapped.
   Return Value: None.
*/
void swap(char *x, char *y){
	char temp;		
	temp = *y;		//swapping the two characters
	*y=*x;
	*x=temp;	
}



/* Puropse : Subfunction of generateSuggestions, this geerates the suggestions by swapping two letters in the given word.
   Arguments: root of the TRIE and the word which was searched.
   Return Value: none
*/


void suggestOnSwap(node *root, char *word){
	int i, j;
	int length, result;
	length=strlen(word);
	for(i=0;i<length;i++){
		for(j=i+1;j<length;j++){
			swap(word+i, word+j);			//swapping to create new word by swapping
			
			result=search(root, word);		//searching with new word
			if(result)
				printf("\n%s", word);		//printing the suggestions if new word found

			swap(word+i, word+j);			//swaooing back the two letters, swapped earlier
		}
	}
}



/* Puropse : To generate the suggestions based on the word searched, in case the word is not in TRIE.
   Arguments: root of the TRIE and the word which was searched.
   Return Value: none
*/

void generateSuggestions(node *root, char *word){
	
	suggestOnDelete(root, word);	//calling function for suggestions on deletion
	
	
	suggestOnChange(root, word);	//calling function for suggestions on changing letters
	suggestOnInsert(root, word);	//calling function for suggestions on inserting new letters

	suggestOnSwap(root, word);	//calling function for suggestions on swapping two letters
}


