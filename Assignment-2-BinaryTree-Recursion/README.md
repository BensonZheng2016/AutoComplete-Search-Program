# Assignment-2-BinaryTree-Recursion
"The assignment was to make a program in C which reads 2 lines from stdin. The first line read indicates how big the int array will be. The second line read is the int array itself (each entry seperated by a space). The program then looks at the array and follows all the possible paths governed by the following rule: 

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
#pathfinder.c
"The file with the main function along with the recursive algorithm that finds all the possible paths in the array."
#path.c & path.h
"The path ADT"
#vector.c & vector.h
"The vector ADT"
