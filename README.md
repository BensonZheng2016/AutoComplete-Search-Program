# Assignment-3-Tries
Essentially a case-sensitive autocomplete/search program. This assignment was to make a C program that reads through an entire wordlist file and inserts each word into a Trie. The user can then enter any string from stdin and the program will search through the Trie and print out every word with the matching prefix.

I have implemented the Trie/program in 2 different ways. The first way uses linked lists. The second way uses arrays and converts each character into ascii code. Both ways use recursion to go through the Trie and prints out every matching word.

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
