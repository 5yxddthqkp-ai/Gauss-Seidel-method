# Gauss-Seidel-method
Gauss Seidel Iterative method
Introduction
............
This is a C++ (high level language) program that uses Gause-Siedel method, an iterative method used to approximate solutions to a system 
of n linear equations in n variables (an n*n matrix) .
This method requires as inputs; an augmented matrix, a constant matrix  and an initial guess to work; so the user is 
required to enter such data and perform iterations.

With this iterative approach, convergence is guaranteed given that either the augmented matrix is strictly diagonally dominant or
symmetric and positive definite. However some matrices can be rearranged such that they are diagonally dominant
or positive definite and symmetric. It is worth noting that the converse is not true, that is, if the augmented matrix is neither strictly 
diagonally dominant nor  symmetric and positive definite, the approximated solutions may or may not converge to a unique solution.
Requirements
............
This programme requires a C++ ide to run. For the smooth running of the program the user is required to read instructions and enter valid 
data whenever inputs are required.

Functioning of the program
..........................
The programme offers the following functions of a user
1. The user firstly enters the size of a matrix.
2. The user then enters the elements of the matrix where aij denotes the component in the i-th row and j-th column of the matrix where 0<i,j<n+1.
3. The user inputs the constants matrix.
4. The user inputs an initial guess (o-th iteration) matrix.
5. The user is then asked to choose between two options; perform the first iteration and approximate the solutions to matrix or firstly check for diagonal
   dominance.
   a) if the user decides to check for diagonal dominance. The programme does just that and if the matrix is not diagonally dominant the user chooses to 
   either proceed with iterations either way or check if the matrix can be rearranged such that it is diagonally dominant.
   b) if such a matrix exists the user can procced to iterations using the rearranged matrix as interchanging rows  has no impact on the solutions.

N.B With increase in the size of matrix, the number of possible rearrangements of rows increases exponentially (in fact, factorially). Hence the user has to
consider the computaional energy.
6. The program then perfoms iterations and computes the error between successive iterations.
7. The user chooses whether they want to continue iterating or terminate the programme.
