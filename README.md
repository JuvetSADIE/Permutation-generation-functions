# Permutation-generation-functions
There are two permutation generation functions: Rank and Unrank. The first gives the rank associated with a permutation of n different elements. While unrank gives the permutation of n elements associated with a given rank.

These two functions are implemented in C language under the name permutation.c in the Linux environment.

The compile command and the generation of the executable are as follows : gcc -o permutation permutation.c -lgmp -lm

We make use of the gmp library to handle large numbers at high precision.

The execution of the executable is done as follows : ./permutation

The two example cases are:
case 1 : Function Rank

1-----> RANK : 

2-----> UNRANK : 1

Number of elements = 5

permutation[0]= 2
permutation[1]= 4
permutation[2]= 3
permutation[3]= 1
permutation[4]= 0

Rank Result = 25

case 2 : Function Unrank

1-----> RANK : 

2-----> UNRANK : 2

Number of elements = 5

rang = 25

Permutation Results : 2  4  3  1  0 

These two scenarios can be used to hide a secret (Unrank) and to extract a secret (Rank) using the usual colors.
‭For a binary secret = "00011001"‬ = 25 in decimal. The permutation associated with rank 25 is: 2  4  3  1  0 

Using 5 colors:
0 - green
1- red
2- yellow
3- purple
4- black

The coloring of the first 5 letters of the text will be done in the following order: yellow, black, purple, red and green.
