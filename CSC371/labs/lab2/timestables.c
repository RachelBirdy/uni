#include <stdio.h>
#include <stdlib.h>
#include "timestables.h"
#include "arrays.h"

void generateTable(int num, int *table) {
        int i;
	for (i = 0; i < MAX_TABLE_SIZE; i++) {
                table[i] = i * num;
        }
}

void printTable(int num, int *table) {
	printf("%-2d times table\n--------------\n", num);
	int i;
	for (i = 0; i < MAX_TABLE_SIZE; i++) {
                printf("%-2d * %-2d = %d\n", num, i, *(table+i));
        }
	double meanValue = mean(MAX_TABLE_SIZE, table);
	printf("The mean for this table is %f\n\n", meanValue);
}

/*
 * This function takes a 2d array of tables (table for each number * the number of tables)
 * and calls the printTable function on each individual table within that array.
 */
void printTables(int **tables) {
	int i;
	for (i = 0; i <= MAX_TIMES_TABLE; i++) {
		printTable(i, tables[i]);
	}
}
