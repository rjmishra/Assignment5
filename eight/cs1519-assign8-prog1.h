/*------------------------------------------------------------------
Name: Ranjan Mishra
Roll Number: CS1519
Date of Submission: 3rd Nov 2015
Deadline date: 3rd Nov 2015
Program description: Trie implementation, along with word suggestions
Acknowledgements: 
--------------------------------------------------------------------*/


#define ASCII_START 33
#define ALPHA_SIZE 60

/* Defining the node structure for the trie,
   it has two indicator variables, isLeaf which has value 1 if the current node is leaf, 0 otherwise
   and isWord with value 1 in case there is word ending on this node, 0 otherwise
   along with children which points the same node structure
 */

typedef struct trieNode{
	int isLeaf;
	struct trieNode* children[ALPHA_SIZE];
	int isWord;
}node;


/* Puropse : To craeate a new trie node
   Arguments: None
   Return Value: pointer to new trie node created.
*/

node* createNode();


/* Puropse : Insertion corresponding to the new word in TRIE
   Arguments: root of the TRIE and the new word to be inserted.
   Return Value: None.
*/

void insert(node *root, char *word);


/* Puropse : To load the dictionary file from system and store the words in TRIE
   Arguments: name of the file as string and root of the TRIE.
   Return Value: none
*/
void loadFromFile(char *fileName, node *root);


/* Puropse : To search the word in TRIE
   Arguments: The word to be searched in TRIE and root of the TRIE
   Return Value: returns 1 in case word is in TRIE and 0 otherwise.
*/
int search(node *root, char *word);


/* Puropse : To generate the suggestions based on the word searched, in case the word is not in TRIE.
   Arguments: root of the TRIE and the word which was searched.
   Return Value: none
*/
void generateSuggestions(node *root, char *word);


/* Puropse : Subfunction of generateSuggestions, this geerates the suggestions by deleting one letter from given word.
   Arguments: root of the TRIE and the word which was searched.
   Return Value: none
*/
void suggestOnDelete(node *root, char *word);



/* Puropse : Subfunction of generateSuggestions, this geerates the suggestions by inserting one letter in the given word.
   Arguments: root of the TRIE and the word which was searched.
   Return Value: none
*/
void suggestOnInsert(node *root, char *word);



/* Puropse : Subfunction of generateSuggestions, this geerates the suggestions by changing one letter in the given word.
   Arguments: root of the TRIE and the word which was searched.
   Return Value: none
*/
void suggestOnChange(node *root, char *word);



/* Puropse : To swap two given characters.
   Arguments: Pointers to the characters to be swapped.
   Return Value: None.
*/
void swap(char *x, char *y);


/* Puropse : Subfunction of generateSuggestions, this geerates the suggestions by swapping two letters in the given word.
   Arguments: root of the TRIE and the word which was searched.
   Return Value: none
*/
	
void suggestOnSwap(node *root, char *word);
	
