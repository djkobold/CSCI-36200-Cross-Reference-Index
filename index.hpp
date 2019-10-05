//Daniel Kobold
//CSCI362 PA2
//index.hpp

#ifndef INDEX_H
#define INDEX_H

#include <iostream>
#include <fstream>

struct list{
	int index;				//List element index
	std::string word;		//Word
	struct list * prev;		//Prev list node
	struct list * next;		//Next list node
	struct lines * headl;	//Head of linked list of line numbers
	int line;				//Line of this instance of the word
};

//Node struct for organizing words with their line numbers
struct node{
	int index;				//Index (matches list index)
	int level;				//Level of this node of binary search tree
	std::string word;		//The word
	struct lines * headl;	//Head of linked list of line numbers
	struct node * left;		//Left binary search tree element (left child)
	struct node * right;	//Right binary search tree element (right child)
	
};

struct lines{
	int line;				//Line number
	struct lines * next;	//Next line number
};


int main(int argc, char *argv[]);

void addList(std::string w, int l);							//Add Node
void printList();											//Print the list of nodes, from the beginning
void insertFirst(std::string w, int l);						//Insert a node as the first node
void insertElse(std::string w, int l);						//Insert somewhere other than as the first node
void insertNewHead(std::string w, int l);					//Insert a new head node
void insertBefore(std::string w, int l, struct list *ptr, struct list *pre);
															//Insert a node before a node as indicated
															//(This is the most used of the insert ones)
void insertSame(std::string w, int l, struct list *ptr);	//Insert another line number to an existing node
void insertAfter(std::string w, int l, struct list *ptr);	//Insert a node at the end of the list
int strComp(std::string s1, std::string s2);				//Compare two strings
int abcComp(char c1, char c2);								//Compare two characters
int getLength(struct list * top);							//Get length of list


void go();														//Oversee transition from list->tree
void getRoot(struct node * root);								//Find mid-point
void plant(struct node * bot, int levels);						//Make the tree
int getLevels(struct list * top);								//Find number of levels needed
int assignIndexList(struct list * top);							//Assign indices to list
void assignIndexTree(struct node * bot, int lev);				//Assign indices to tree
void assignIndexLeaf(struct node * thisLeaf);					//Assign indices to one leaf
void listToNode(struct list * top, struct node * bot, int ind);	//Transfer info
void printLeaf(struct node * bot, int lev, int fv);				//Print the final table answer
void printLeafIndex(struct node * bot);
void addLook(struct lines * me, int lineIn);

extern int treeLevs;			//Levels of the tree
extern int leafInd;				//Levels of the tree
extern int index;				//Index of node
extern int leaf;				//Index of loop
extern int leaves;				//Number of nodes made
extern int leftOver;			//Nodes left to be assigned
extern struct list *head;		//Head node of the list
extern struct list *prev;		//Previous node accessed
extern struct node *root;		//Used in entry and deletion, keeps track of head node


#endif