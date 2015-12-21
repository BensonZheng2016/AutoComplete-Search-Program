#Assignment-3-Tries/Array-Implementation
Essentially a case-sensitive autocomplete/search program. This assignment was to make a C program that reads through an entire wordlist file and inserts each word into a Trie. The user can then enter any string from stdin and the program will search through the Trie and print out every word with the matching prefix.

I have implemented the Trie/program in 2 different ways. This way uses arrays.

For example, the wordlist could be:

       Alvin
       alvin
       computer
       Computer
       computation
       computational
       colour
       candy
       communists
       Corey's
       
Then if the user inputs "comp" into stdin, the output would be:

       computer
       computation
       computational
#complete.c
Contains the main function. It creates an empty Trie, reads from a wordlist file, inserts each word into the Trie, and calls the function to AutoComplete the inputted string.
#trie.c & trie.h
The Trie ADT. Contains functions like Insert, Search, and printWords.
#american-english-no-accents
This is the wordlist/dictionary file.
