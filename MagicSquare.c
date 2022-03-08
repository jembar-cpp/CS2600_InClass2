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

void printSquare(int square[3][3]) {
    for(int row = 0; row < 3; row++) {
        printf("[%d",square[row][0]);
        for(int col = 1; col < 3; col++) {
            printf(" %d",square[row][col]);
        }
        printf("]\n");
    }
}

int main() {
    int square[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printSquare(square);
    return 0;
}