# CPS305-Assignments
"Data Structures and Algorithms" course assignments with certain data structure implementations in C.
# Assignment-2-BinaryTree-Recursion
The assignment was to make a program in C which reads 2 lines from stdin. The first line read indicates how big the int array will be. The second line read is the int array itself (each entry seperated by a space). The program then looks at the array and follows all the possible paths governed by the following rule: 

       From position i, the next position in the path must be either i+x, 
       or i-x, where x is the non-negative integer stored in position i.
       There is no path possible from position i to position i+x if
       either of these 2 conditions hold:
       position i+x is beyond the end of V.
       position i+x is already on the path.
       There is no path possible from position i to position i-x if
       either of these 2 conditions hold:
       position i-x is beyond the start of V.
       position i-x is already on the path.
       
For example, the input could be:

       12
       2 8 3 2 7 2 2 3 2 1 3 0
       
Then the output would give the following paths:

       0 2 5 7 4 11 
       0 2 5 3 1 9 10 7 4 11 
       0 2 5 3 1 9 8 10 7 4 11 
       0 2 5 3 1 9 8 6 4 11 
       
This is done by using a binary tree and recursion.
# Assignment-3-Tries
Essentially an autocomplete/search program. This assignment was to make a C program that reads through an entire wordlist file and inserts each word into a Trie. The user can then enter any string from stdin and the program will search through the Trie and print out every word with the matching prefix.

I have implemented the Trie/program in 2 different ways. The first way uses linked lists. The second way uses arrays and converts each character into ascii code. Both ways use recursion to go through the Trie and prints out every matching word.
