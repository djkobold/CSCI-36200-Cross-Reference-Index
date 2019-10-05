//Daniel Kobold
//CSCI362 PA2
//index.cpp

#include "index.hpp"
using namespace std;

int main(int argc, char *argv[])
{
	ifstream in;		//File stream for input
	string line;		//Line collected from input stream
	size_t prevs;		//Used in tokenization
	size_t pos;			//Used in tokenization
	int lineNo;			//Line number, used for assigning line number
	string sub;			//Substring during tokenization
	
	int i = 0;			//Counter for incrementing set iterator
	
	int mid = 0;		//Middle of the set
	
	
	if(argc == 1)		//If one argument: "./index"
		cout << "No filename indicated.\n";
	else if(argc > 2)	//If more than two arguments "./index [arg1] [arg2]"
		cout << "Too many arguments.\n";
	else				//Otherwise, the correct number of arguments were used
	{
		in.open(argv[1]);	//Open the file for input
		if(!in)				//If opening failed
		{
			cout << "Unable to open " << argv[1] << "\n";	//Display corresponding message
		}
		else				//Otherwise, opening worked
		{
			lineNo = 1;		//Line number starts at 1
			while(getline(in,line))		//While valid lines are still being collected by getline
			{
				prevs = 0;				//Used in tokenization
					//This while loop tokenizes each string by finding the first instance of one
					//of the delimiters in the parentheses. The position is then recorded
					//and used to identify a string that qualifies as a word
					while((pos = line.find_first_of(" .!?,#", prevs))!=string::npos)
					{
						//If the position is greater than (later than) the previous index
						if(pos > prevs)
						{
							//cout << "2";				//Used for reference
							sub = line.substr(prevs,pos-prevs);		//Set sub as the substring
							//cout << sub << "| Line=" << lineNo << "\n";		//Used for reference
							
							if(isalpha(sub[0]))			//Make sure first character is a letter
								addList(sub,lineNo);	//If so, add this entry to the linked list
							
						}
						prevs = pos+1;					//Set prev to the character after the delimiter
					}
				lineNo++;								//Increment line number
			}
			//cout<< "?\n";								//Used for reference
		}
		in.close();										//Finally, close the file
		
		//printList();									//Used for reference
		
		go();			//Make transition from list -> binary search tree
		cout << "\n";	//Print one more newline for formatting purposes
	}
}
