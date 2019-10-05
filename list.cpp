//Daniel Kobold
//CSCI362 PA2
//list.cpp

#include "index.hpp"
using namespace std;

struct list *head;
struct list *prev;
int index = 0;

//Add Node
void addList(string w, int l)
{
	//cout<<"\n["<<index<<"]" <<w;
	index++;
	
	//If head doesn't exist, make a new first node
	//Otherwise, insert the node afterwards
	if(head == NULL)
		insertFirst(w,l);
	else
		insertElse(w,l);
}

//Print the list of nodes, from the beginning
void printList()
{
	//Set pointer to head
	struct list *ptr = head;
	struct lines *look;
	
	//Message
	//cout<<"Words:\n";
	
	//While ptr has not reached the end of the list
	while(ptr != NULL)
	{
		int pL = 0;
		//Display the coordinates of the initial position being pointed at by ptr
		
		//Print the first 10 characters if longer than 10 characters
		while(pL<10 && pL < ptr->word.length())
		{
			cout<<ptr->word[pL];	//Print a character of the word
			pL++;					//Increment pL
		}
		while(pL<10)	//If less than 10 characters, print spaces up until 10 chars
		{
			cout<<" ";	//Print a space
			pL++;		//Increment pL
		}
		
		look = ptr->headl;	//Set look equal to head of the list for the ptr
		
		while(look!=NULL)	//While look is not pointing to a NULL list item
		{
			cout<<"\t"<< look->line;	//Print a tab and the line number
			look = look->next;			//Point look to the next list element
		}	
		cout<<"\n";			//Print a newline (for formatting)
		
		//Set ptr to the next node
		ptr = ptr->next;
	}
}

//Insert the first node (when there are NO nodes)
void insertFirst(string w, int l)
{
	//Make new head list node
	struct list *first = new list;
	//New lines list element
	struct lines *newLines = new lines;
	
	//Assign word and line number to new list node
	first->word = w;
	//first->headl->line = l;
	first->line=l;
	
	newLines->line = l;			//Set the line number to the parameter l
	newLines->next = NULL;		//Set next to NULL
	first->headl = newLines;	//Set head of the list to this new element
	
	
	//Point head to NULL
	first->next=NULL;
	
	//Set head to the new head list node
	head = first;
	
	//Set this node as the new prev node
	prev = first;
}

//Insert somewhere else (there ARE nodes)
void insertElse(string w, int l)
{
	struct list * ptr = head->next;
	int answer;						//Answer to string comparison
	
	prev = head;					//Set prev to head
	
	if(strComp(w,head->word)==1)	//Use string compare (my version) to compare strings
	{
		//cout<<"\n<NEW HEAD>";		//Used for reference
		insertNewHead(w,l);			//Insert a new head node
	}
	else
	{
		while(ptr != NULL)					//While ptr hasn't reached end of linked list
		{
			answer = strComp(w,ptr->word);	//String compare
			if(answer==1)					//This string comes before ptr's string
			{
				//cout<<"\n<BEFORE>";		//Used for reference
				insertBefore(w,l,ptr,prev); //Insert before
				break;						//Break, b/c the node has been inserted
			}	
			else if(answer==0)				//The strings are equal
			{
				//cout<<"\n<SAME>";			//Used for reference
				insertSame(w,l,ptr);		//Add another line number
				break;						//Break, b/c the node has been inserted
			}
			else							//This string comes after ptr's string
			{
				//cout<<"\n<NOT YET>";		//Used for reference
				prev = ptr;					//Set prev to this ptr
				ptr = ptr->next;			//Move on to next string		
			}	
		}
		
		if(ptr == NULL)						//If this string comes after all strings
			insertAfter(w,l,prev);			//Insert at end of list
		
	}
}

//Insert a new head node
void insertNewHead(string w, int l)
{
	//Make new head node
	struct list *first = new list;
	
	//Make a new lines list element
	struct lines *newLines = new lines;
	
	//Assign x and y coordinates to new node
	first->word = w;
	
	//Set the line number to the parameter l
	first->line=l;
	
	newLines->line = l;		//Set the lines line number to the parameter l
	newLines->next=NULL;	//Set the lines next to NULL
	first->headl=newLines;	//Set the head node of first to this new lines element
	first->next=head;		//Point first to head since it is the new head node
	
	//Set head to the new head node
	head = first;
	
	//Set this node as the new prev node
	prev = first;
}

void insertBefore(string w, int l, struct list *ptr, struct list *pre)
{
	//Make a new node
	struct list *newList = new list;
	
	//Make a new lines element
	struct lines *newLines = new lines;
	
	newLines->line=l;		//Set the line number to parameter l
	newLines->next=NULL;	//Set next to NULL
	
	//Assign info to node
	newList->word = w;			//Assign word
	newList->headl = newLines;	//Assign head node of list elements
	newList->line=l;			//Assign line number
	
	//Make all necessary linked list connections
	pre->next = newList;		//Set previous next to this
	newList->prev = pre;		//Set this previous to prev
	ptr->prev = newList;		//Set ptr previous to newList
	newList->next = ptr;		//Set newList next to ptr
}

//Add another line number to an existing node
void insertSame(string w, int l, struct list *ptr)
{
	//Make new line node
	struct lines * newLine = new lines;
	
	//Lines pointer
	struct lines * lPtr = ptr->headl;
	
	newLine->line = l;					//Set newLine line to the line parameter (l)
	
	while(lPtr->next != NULL)			//Iterate through the list of line nodes
	{
		lPtr = lPtr->next;				//Move to next line struct
	}
	lPtr->next = newLine;				//Add newLine to the list
	newLine->next = NULL;				//Set its next element to NULL				
}

//Insert after a node, only used when adding to the end of the list
void insertAfter(string w, int l, struct list *ptr)
{
	//Make a new node
	struct list *newList = new list;
	
	//Make a new lines node
	struct lines *newLines = new lines;
	
	
	newLines->line = l;			//Set line to parameter l
	newLines->next = NULL;		//Set next to NULL
	
	//Assign w and l to new node and set next to null
	newList->word = w;			//Set word to w
	newList->line = l;			//Set line to l
	newList->headl=newLines;	//Add to lines linked list
	newList->next=NULL;			//Set next to NULL
	
	//Set previous node's next node to this new node
	prev->next=newList;
	
	//Set this node as the new prev node
	prev=newList;	
}


//Compare two strings
int strComp(string s1, string s2)
{
	int ans = 0;		//Answer of which string is earlier in alphabet
	int ind = 0;		//Index
	int lng1 = 0;		//Length 1
	int lng2 = 0;		//Length 2
	int lngth = 0;		//Longer of the lengths between the strings
	
	lng1 = s1.length();		//Length of first string		
	lng2 = s2.length();		//Length of second string
	if(lng1 < lng2)			//lng2 is larger
		lngth = lng2;
	else if(lng2 < lng1)	//lng1 is larger
		lngth = lng1;
	else					//lengths are equal
		lngth = lng1;
	
	//While index is less than 10 AND
	//Index is less than the longer of the two lengths AND
	//ans equals 0 (an answer hasn't been found yet)
	while(ind < 10 && ind<lngth && ans == 0)
	{
		//Compare the characters at the same index
		ans = abcComp(s1[ind],s2[ind]);
		
		//Increment ind
		ind++;
	}
	
	return ans;		//Return ans
}

//Compare two characters
int abcComp(char c1, char c2)
{
	if(c1 < c2)			//c1 comes before c2
		return 1;
	else if(c2 < c1)	//c2 comes before c1
		return 2;
	else if(c1 == c2)	//c1 and c2 are the same
		return 0;
	return 0;
}

//Get length of the list
int getLength(struct list * top)
{
	struct list * ptr = top;		//Set ptr to top of list
	int leng = 0;					//Set leng to 0
	
	while(ptr != NULL)				//While ptr doesn't equal NULL
	{
		leng++;						//Increment leng
		ptr = ptr->next;			//Move ptr to next element
	}
	
	return leng;					//Return leng
}
