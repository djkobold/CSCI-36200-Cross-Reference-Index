Daniel Kobold

CSCI362 PA2

readme.txt



Guidelines for using Cross-Reference Index





I used the following:


Host Name: tesla.cs.iupui.edu

 
Port 22
	




To compile, use: "make"


-> To run, use: "./index [file name]"

-> For test file, use "./index test2.txt"




(Other Makefile commands)


To clean, use: "make clean"


To debug, use: "make debug"


-> To use debugger, use "gdb ./index [file name]"


-> To run in debugger, use "run" when (gdb) appears




The program will analyze the file indicated by [file name] and will

make and print a table showing the words in the file and the line

number of each instance of the word.



The following assumptions were made:

(1) Only lowercase letters, numerical digits, punctuation marks,

blanks, and the newline character are present in the input text

file. The end of the file is signified by the '#' character.



(2) A word is considered any sequence of letters and digits starting

with a letter. The end of a word is marked by a blank, punctuation mark,

or a newline character.



(3) Punctuation marks are not part of any word.



(4) Line numbers should print in ascending order.



(5) Each word is at most ten characters long. All characters beyond that

in a word are ignored. Two words are the same if their first ten

characters match.



 



Thank you!
