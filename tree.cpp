//Daniel Kobold
//CSCI362 PA2
//tree.cpp

#include "index.hpp"
using namespace std;

int leaf;
int treeLevs;
int leaves;
int leafInd;
struct node * root;
int leftOver;			//leftover empty nodes

//Complete transfer from LIST to TREE
void go()
{
	struct node * newRoot = new node;		//Make a new node
	int lv = 0;			//Number of levels in the tree
	int ind = 0;		//Index used during transfer of info
	int len = 0;		//Length of list
	int fv = 0;			//Final value number of how many leaves need assigned
	
	
	
	root = newRoot;				//Set root to that new node
	fv = assignIndexList(head);	//Assign indices to the list
	lv = getLevels(head);		//Determine number of tree levels needed
	treeLevs = lv;				//Set treeLevs to lv
	//printList();				//Used for reference
	//cout << lv;				//Used for reference
	leaves = 1;					//Start leaves at 1
	plant(root,lv);				//"Plant" (make) the tree, starting w/ root and having lv levels
	//cout << leaves;			//Used for reference
	assignIndexTree(root, treeLevs);		//Assign indices to the tree
	len = getLength(head);		//Set len to the length of the LIST
	leafInd = fv;				//Set leafInd to fv
	
	leftOver = leaf - fv;		//Set leftOver to leaf-fv
	
	while(ind < fv)			//Complete the transfer.
	{
		listToNode(head,root,ind);	//Convert list element to tree element
		ind++;						//Increment ind
	}
	//printLeafIndex(root);			//Used for reference
	
	//cout << "\n";					//Used for reference
	
	printLeaf(root,treeLevs,fv);	//Print the tree

	
}

//Set up a new root node
void getRoot(struct node * root)
{
	struct node * newRoot = new node;
	
	root = newRoot;	
	
	/*int mid = 0;		//Mid-point of the length of linked list
	int iter = 0;		//Iterate back through linked list
	struct list * ptr = top;	//Iterate through linked list
	
	mid = getLength(top) / 2;		//Get mid-point
	
	while(iter < mid)
	{
		iter++;
		ptr = ptr->next;
	}*/
}

//Make the tree based on root node and number of levels
void plant(struct node * bot, int levels)
{
	struct node * left = new node;		//New left node
	struct node * right = new node;		//New right node
	//cout << "Try planting.\n";		//Used for reference
	
	if(levels >1 && bot != NULL)		//If more of the tree needs set up
	{
		bot->left = left;				//Link left to left
		bot->right = right;				//Link right to right
		plant(bot->left, levels-1);		//Use plant again for the left node
		plant(bot->right, levels-1);	//Use plant again for the right node
		leaves += 2;
	}
}

//Return number of levels needed in binary search tree.
int getLevels(struct list * top)
{
	int length = getLength(top);		//Set vars equal to length of linked list
	int a = length;						//Set a to length (used for determining number of levels needed)
	int lvs = 0;						//Levels variable to be returned
	
	while(a>0)			//Keep dividing by two to find number of levels
	{
		a = a/2;		//Divide a by 2
		lvs++;			//Increment lvs
	}
	
	return lvs;			//Return lvs
}

//Assign index values to the list elements
int assignIndexList(struct list * top)
{
	int ind = 0;				//Set ind to 0
	struct list * ptr = top;	//Set ptr to top of the list
	
	while(ptr!=NULL)			//While ptr doesn't point to NULL
	{
		ptr->index=ind;			//Assign an index to that element
		ptr=ptr->next;			//Point to the next element
		//cout<<ind;			//Used for reference
		ind++;					//Increment ind
		
	}
	
	return ind;					//Return ind
}

//Assign index values to the (empty) tree
void assignIndexTree(struct node * bot, int lev)
{
	//cout<<"Try index.\n";			//Used for reference
	
	if(bot == NULL || lev == 0)						//If no node here, return
		return;
	
	//cout << "|";					//Used for reference
	
	//if(bot->left != NULL)
		assignIndexTree(bot->left, lev-1);	//Check left for more levels
	
	assignIndexLeaf(bot);				//Assign this index
	
	//if(bot->right != NULL)
		assignIndexTree(bot->right, lev-1);	//Check right for more levels
	
	
}

//Assign index to a single leaf
void assignIndexLeaf(struct node * thisLeaf)
{
	//If this leaf doesn't equal NULL
	if(thisLeaf == NULL)
		return;
	
	thisLeaf->index = leaf;		//Set index to the index
	//cout << leaf;				//Used for reference
	leaf++;						//Increment leaf
	
}

//Convert list element to tree node element
void listToNode(struct list * top, struct node * bot, int ind)
{
	struct list * ptr = top;			//Set list ptr to top
	struct node * dis = bot;			//Set node dis to bot
	struct lines * bNew = new lines;	//Make new lines node
	struct lines * lPtr = ptr->headl;	//Make lines pointer to headl
	struct lines * bPtr;				//Make another lines pointer
	
	while(ptr!=NULL && ptr->index != ind)			//Get proper list element
		ptr = ptr->next;							//Increment pointer
	
	while(dis!=NULL && dis->index != ind)			//Get proper tree node
	{
		//cout<<"dis:"<<dis->index<<"\tind:"<<ind<<"\n";	//Used for reference
		if(dis->index > ind)			//If this node's index is less than the desired index
			dis = dis->left;			//Set dis to the node to the left of dis
		else							//Otherwise, the index must be greater than desired index
			dis = dis->right;			//Set dis to the node to the right of dis
	}
	if(ptr==NULL || dis == NULL)			//Used for reference
	{
		cout << "-"<<ind;					//Used for reference
	}
	else
	{
		dis->word = ptr->word;				//Transfer word to node		
		dis->headl = ptr->headl;			//Set this headl to ptr's headl
	}
}

//Add a new node to the list of line numbers
void addLook(struct lines * me, int lineIn)
{
	struct lines * newLines = new lines;	//Add new lines node
	
	newLines->line=lineIn;					//Set line to line input
	newLines->next = NULL;					//Set next to NULL
	me->next = newLines;					//Set input node next to this node
}

//Print the indices of each node in the tree
//Used for reference to make sure indices were assigned in order
void printLeafIndex(struct node * bot)
{
	if(bot!=NULL)					//If node sent was not NULL
	{
		printLeafIndex(bot->left);	//Print the index of the node to the left
		
		cout << bot->index;			//Print the index of this node
			
		printLeafIndex(bot->right);	//Print the index of the node to the right
	}	
}

//Print the contents of each leaf
void printLeaf(struct node * bot, int levl, int fv)
{
	int pL = 0;						//Make sure 10 chars are printed
	struct lines *look;				//Used for printing the line numbers
	int lev = levl;					//Set lev to levl
	
	
	//cout<<lev<<" - Try printing.\n";		//Used for reference
	
	if(bot != NULL && fv > 0)		//If the node is not NULL and fv > 0
	{
		look = bot->headl;			//Start look at headl of this node
		
		if(lev > 1 && fv > 0)							//If level is greater than 1 and fv is greater than 0
		{
			printLeaf(bot->left, lev-1, fv-1);			//Check left for more levels and print that node's info
		}	
		while(pL<10 && pL < bot->word.length())			//Print characters of the word up until the 10th character
		{
			cout<<bot->word[pL];						//Print out a character
			pL++;										//Increment pL to keep printing letters
		}
		while(pL<10)									//If word was shorter than 10 letters, print spaces
		{
			cout<<" ";									//Print a space
			pL++;										//Increment pL to keep printing spaces
		}

		while(look!=NULL && bot->index < leafInd)		//While look doesn't point to NULL and index is less than total index
		{
			cout<<"\t"<< look->line;					//Print a tab and a line number
			look = look->next;							//Point to next line element
		}	
		if(bot->index < leafInd)						//If index is less than total leaf index
		{
			cout<<"\n";									//Print a new line for formatting
		}
		//cout << "[leafInd" <<leafInd<<"][bot->index"<<bot->index<<"][treeLevs"<<treeLevs<<"]\n";		//Used for reference
		
		if(lev > 1 && fv > 0)
		{
			printLeaf(bot->right, lev-1, fv-1);		//Check right for more levels and print that node's info
		}
	}
	
}

