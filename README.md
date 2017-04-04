# Assignments
College Assignments

Problem 1: 
Write a C program that takes as input a positive integer 'n' and generates 
a matrix of size 2^n x 2^n using pointer to pointer. Fill the matrix 
with integers in the range [1,2^(2n)]. Write a recursive function to print 
the matrix in a spiral fashion.  

Problem 2: 
Write a C program that takes as input a positive integer 'n' and generates 
a matrix of size 2^n x 2^n using pointer to pointer. Fill the matrix 
with integers in the range [1,2^(2n)]. Write a recursive function to print 
the matrix in a Hilbert curve fashion.  

Problem 3: 
Write a C program to dynamically allocate an array A of size n x m. n and 
m are inputs to be taken from the user. The array A is treated as a maze
in which a mouse is trying to find its way. A[i][j]=0 indicates 
that the mouse can step onto the location (i,j) and A[i][j]=1 indicates 
that the mouse can't step onto the location (i,j). A mouse starts from 
A[0][0] and has to reach A[n-1][m-1], by passing only through positions 
that are set to 0. A mouse can move in any of the 8 directions -- N, S, 
E, W, NE, NW, SE, SW provided that those locations have a 0 and they are 
valid array entries. 

You have to write a recursive program that finds the path of the mouse 
if such a path exists. The array entries of A are to be generated randomly. 

Problem 4: 
Write a recursive C function to compute the maximum and minimum in an 
array A of size n. The matrix A should be generated dynamically. 
Any instance of the recursion looks at two "almost" equal partitions 
of the array -- let them be A1 and A2; compute max1 and min1, the maximum 
and minimum of A1, respectively; similarly, compute max2 and min2, the 
maximum and minimum of A2, respectively. Now to compute the maximum 
of the elements of A1 and A2, one needs to compare only between max1 
and max2; similarly to compute the minimum of the elements of A1 and A2, 
one needs to compare only between min1 and min2. Implement the above 
idea to get the maximum and minimum of A. 

Compute the total number of comparisons (#C) in finding the maximum and 
minimum in the above stated way. Analytically figure out the relation 
between #C and n. 
