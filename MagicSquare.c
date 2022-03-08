/**
 * MagicSquare.c
 * @author Jeremy Embar
 * 
 * Checks an 2 array and finds out if it is a magic square or not.
 * A 3x3 Lo Shu magic square contains the numbers 1 through 9 (non-repeating).
 * All columns, rows, and diagonals add up to the same number.
 * 
 * TODO:
 * function isMagicSquare:
 *  - checks if 2d array is a magic square or not, returns bool
 *  - check each column first
 *    - while checking each column, add values to 1d array and make sure they're all from 1 - 9 with no duplicates
 *  - check each row
 *  - check both diagonals
 *  - if at any point there's a repeating value, not in range 1 - 9, or rows/columns/diagonal don't add up to same number, return false
 *  - if everything is good, return true
 * 
 * main:
 *  - creates the 2d array, calls the function to test it
 * 
 * part 2:
 * function createSquare:
 *  - creates random square, prints it, and returns 2d array
 * 
 * main:
 *  - create square, check if it's magic, loop if not
 *  - count how many squares until it's magic
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/**
 * isMagicSquare: checks whether a square is a magic square or not.
 * A 3x3 magic square contains the numbers 1 - 9 (non-repeating).
 * Each row, column, and diagonal adds up to the same number.
 * Uses an integer pointer as an argument rather than a 2d array so that it can scale to nxn.
 * 
 * @param square (*int): the 1st index of the 2d array of the square
 * @param n: size of a side of the array
 * @return bool, whether the square is magic or not.
 */
bool isMagicSquare(int *square, int n) {
    const int N_SQUARED = n*n;
    int *numbers; // array to keep track of numbers
    numbers = (int*)calloc((N_SQUARED+1), sizeof(int)); // allocate memory for array

    int sum = 0; // the sum for which all rows, columns, and diagonals should add up to
    
    // Check each row and verify all numbers are within range and non-duplicate
    for(int row = 0; row < n; row++) {
        int currentSum = 0;
        for(int col = 0; col < n; col++) {
            int num = square[row*n+col];
            if(num < 1 || num > N_SQUARED || numbers+num != 0) { // number is out of range or duplicate
                numbers[num] = 1; // populate index in array
            }
            else { // not valid for a magic square
                return 0;
            }
            currentSum += num;
        }
        if (sum == 0) { // initialize sum if it hasn't been set yet
            sum = currentSum;
        }
        else if (currentSum != sum) { // sum of row isn't the same
            return 0; // not a magic square
        }
    }

    // Check sums of columns of the square
    for(int col = 0; col < n; col++) {
        int currentSum = 0;
        for(int row = 0; row < n; row++) {
            int num = square[row*n+col];
            currentSum += num;
        }
        if (currentSum != sum) { // sum of column isn't the same
            return 0; // not a magic square
        }
    }

    // Check diagonals of the square
    int diagSum1 = 0; // check both diagonals at the same time
    int diagSum2 = 0;
    for(int k = 0; k < n; k++) {
        diagSum1 += square[k*n+k];
        diagSum2 += square[k*n+(n-k-1)];
    }
    if (diagSum1 != sum || diagSum2 != sum) { // diagonals aren't the same as the sum
        return 0; // not a magic square
    }
    free(numbers);
    return 1; // square is a magic square
}

/**
 * printSquare: prints a square in the form:
 * [a b c]
 * [d e f]
 * [g h i]
 * 
 * @param square (int*) the 1st index of the 2d array to print
 * @param n: size of a side of the array
 */
void printSquare(int *square, int n) {
    for(int row = 0; row < 3; row++) {
        printf("[%d",square[row*n]);
        for(int col = 1; col < 3; col++) {
            printf(" %d",square[row*n+col]);
        }
        printf("]\n");
    }
}

/**
 * generateRandomSquare: generates a random square of size nxn
 * Contains the numbers from 1 to n^2, non-duplicate
 * 
 * @param n: the size of the square 
 * @return pointer to the first element of the square, a 1d array
 */
int *generateRandomSquare(int n) {
    const int N_SQUARED = n*n;

    // Allocate and create array of two parts:
    // Part 1 (0 - n^2): keeps track of duplicate numbers
    // Part 2 (n^2 + 1 - 2*n^2): the square of numbers
    int *numbers; // array to keep track of numbers
    numbers = (int*)calloc(2*(N_SQUARED+1), sizeof(int)); // allocate memory for array

    for(int i = 0; i < N_SQUARED; i++) { // loop until array is filled
        for(int j = 0; j < 1000; j++) { // generate a random number until it's unique
            int random = rand() % 9 + 1; // generate random number from 1 to 9
            if(numbers[random] == 0) { // number is unique
                numbers[random] = 1;
                numbers[i+N_SQUARED+1] = random;
                break;
            }
        }
    }

    return numbers+N_SQUARED+1; // return a pointer to the index of where the square starts
}

int main() {
    const int n = 3; // Hardcoded for 3x3 square

    srand(time(0)); // set random seed
    int *square = generateRandomSquare(n);
    printSquare(square, 3);
    if(isMagicSquare(square, 3)) {
        puts("The square is a magic square.");
    }
    else {
        puts("The square is not a magic square.");
    }
    free(square);
    return 0;
}